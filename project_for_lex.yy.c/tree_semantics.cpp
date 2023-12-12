#include "tables.h"
#include <algorithm>
// ------------------------------ Обход дерева -------------------------------

void getTypesFromInitDeclaratorType(vector<Init_declarator_node*>* declarators, Type_node* typeNode, vector<string>* varsNames, vector<Type*>* varsTypes);

// ---------- Function_and_class_list_node ----------

void Function_and_class_list_node::fillTables()
{
    for (int i = 0; i < FunctionsAndClasses->size(); i++)
    { //Для каждого элемента в списке
        if (FunctionsAndClasses->at(i).class_block != NULL)
        { //Если элемент - класс
            Class_block_node* cur = FunctionsAndClasses->at(i).class_block;
            if (cur->type == IMPLEMENTATION_CLASS_BLOCK_TYPE)
            { // Реализация
                Class_implementation_node* curImplementation = (Class_implementation_node*)cur;
                string className = curImplementation->ClassName; // Имя сласса
                string *superclassName = curImplementation->SuperclassName == NULL ? NULL : new string(curImplementation->SuperclassName); // Имя суперкласса
				ClassesTableElement *element = ClassesTable::addClass(className, superclassName, true); // Добавление класса в таблицу

				if (curImplementation->Body != NULL)
				{
					// Добавление переменных
					map<string, Expression_node*> initializers;
					map<string, Type*> vars = curImplementation->Body->getVariables(&initializers);
					for (auto it = vars.begin(); it != vars.end(); it++) {
						if (element->Fields->items.count(it->first) && element->Fields->items[it->first]->InitialValue != NULL && initializers[it->first] != NULL) {
							string msg = "Variable '" + it->first + "' redifinition in class '" + className + "'\n";
							throw std::exception(msg.c_str());
						}
						if (element->Fields->items.count(it->first) && (element->Fields->items[it->first]->DescriptorStr != it->second->getDescriptor() || element->Fields->items[it->first]->type->ArrSize != it->second->ArrSize)) {
							string msg = "Variable '" + it->first + "' in class '" + className + "' has conflict types.\n";
							throw std::exception(msg.c_str());
						}
						if (!element->Fields->items.count(it->first))
							element->Fields->addField(element->ConstantTable, it->first, it->second->getDescriptor(), false, it->second, initializers[it->first]);
					}

					vector<Type*> varTypes;
					vector<string> instanceVariables = curImplementation->Body->getInstanceVariables(&varTypes);

					if (element->IsHaveInterface) { // У класса был интерфейс
						// Проверить instance variables
						if (instanceVariables.size() > 0) {
							map<string, FieldsTableElement*> instVar;
							for (auto item : element->Fields->items)
							{
								if (item.second->IsInstance)
									instVar[item.first] = item.second;
							}

							if (instanceVariables.size() != instVar.size())
							{
								string msg = "Instance variables have different size in interface and implementation in class'" + className + "'\n";
								throw std::exception(msg.c_str());
							}
							// Сверить instance variables
							for (int i = 0; i < instanceVariables.size(); i++)
							{
								if (!instVar.count(instanceVariables[i])) {
									string msg = "Instance variable '" + instanceVariables[i] + "' not found in interface '" + className + "'\n";
									throw std::exception(msg.c_str());
								}

								if (instVar[instanceVariables[i]]->InstanceIndex != i+1)
								{
									string msg = "Instance variable '" + instanceVariables[i] + "' in class '" + className + "' has different position from the position specified in the interface'\n";
									throw std::exception(msg.c_str());
								}
								if (varTypes[i]->getDescriptor() != instVar[instanceVariables[i]]->DescriptorStr)
								{
									string msg = "Instance variable '" + instanceVariables[i] + "' in class '" + className + "' has different type from the type specified in the interface'\n";
									throw std::exception(msg.c_str());
								}
							}
						}

						// Добавление методов
						map<string, vector<string>*> keywordsNames; //Словарь для имен keywords
						map<string, vector<Type*>*> keywordsTypes; //Словарь для типов keywords
						map<string, vector<string>*> parametersNames; //Словарь для имен параметров
						map<string, vector<Type*>*> parametersTypes; //Словарь для типов параметров
						map<string, bool> isClassMethod; //Словарь, содержащий принадлежность метода к классу
						map<string, Statement_node*> startNodes; //Словарь, содержащий стартовые узлы тел методов
						map<string, Type*> methods = curImplementation->Body->getMethods(&keywordsNames, &keywordsTypes, &parametersNames, &parametersTypes, &isClassMethod, &startNodes); //Получение методов
						for (auto it = methods.begin(); it != methods.end(); it++)
						{
							// Формирование дескриптора
							string descriptor = "(";
							for (int i = 0; i < keywordsTypes[it->first]->size(); i++) {
								descriptor += keywordsTypes[it->first]->at(i)->getDescriptor();
							}
							descriptor += ")";
							descriptor += it->second->getDescriptor();
							if (element->Methods->items.count(it->first))
							{ //Метод есть. Проверка.
								MethodsTableElement *curMethod = element->Methods->items[it->first];
								if (descriptor != curMethod->DescriptorStr) {
									string msg = "Method '" + it->first + "' in class '" + className + "' has different type from the type specified in the interface\n";
									throw std::exception(msg.c_str());
								}
								curMethod->BodyStart = startNodes[it->first]; //Добавление тела

								//Получение и добавление локальных переменных внутри метода
								vector<string> varsNames;
								vector<Type*> varsTypes;
								curMethod->BodyStart->findLocalVariables(&varsNames, &varsTypes);
								for (int i = 0; i < varsNames.size(); i++)
								{
									curMethod->LocalVariables->findOrAddLocalVariable(varsNames[i], varsTypes[i]);
								}
							}
							else
							{ //Метода нет. Добавление.
								bool isClass = isClassMethod[it->first];// Признак принадлежности к классу
								vector<Type*>* curParametersTypes = parametersTypes[it->first]; // Типы параметров
								vector<Type*>* curKeywordsTypes = keywordsTypes[it->first]; // Типы keywords
								Statement_node* curStart = startNodes[it->first]; // Узел начала тела метода

								MethodsTableElement *method = element->Methods->addMethod(element->ConstantTable, it->first, descriptor, isClass, curStart, it->second, curParametersTypes, curKeywordsTypes); //Добавление метода
								
								//Формирование таблицы локальных переменных
								LocalVariablesTable* locals = method->LocalVariables; //Таблица локальных переменных данного метода
								Type* type = new Type(CLASS_NAME_TYPE, element->getClassName()); // Тип для self переменной
								locals->findOrAddLocalVariable("self", type); //Добавление self в таблицу локальных переменных
								//Добавление keywords в таблицу локальных переменных
								for (int i = 0; i < keywordsNames[it->first]->size(); i++) {
									locals->findOrAddLocalVariable(keywordsNames[it->first]->at(i), keywordsTypes[it->first]->at(i));
								}
								//Добавление parameters в таблицу локальных переменных
								for (int i = 0; i < parametersNames[it->first]->size(); i++) {
									locals->findOrAddLocalVariable(parametersNames[it->first]->at(i), parametersTypes[it->first]->at(i));
								}
								//Получение и добавление локальных переменных внутри метода
								vector<string> varsNames;
								vector<Type*> varsTypes;
								method->BodyStart->findLocalVariables(&varsNames, &varsTypes);
								for (int i = 0; i < varsNames.size(); i++)
								{
									locals->findOrAddLocalVariable(varsNames[i], varsTypes[i]);
								}
							}
						}
					}
					else { // У класса не было интерфейса
						// Добавить instance variables
						for (int i = 0; i < instanceVariables.size(); i++)
						{
							element->Fields->addField(element->ConstantTable, instanceVariables[i], varTypes[i]->getDescriptor(), true, varTypes[i], NULL);
						}

						// Добавление методов
						map<string, vector<string>*> keywordsNames; //Словарь для имен keywords
						map<string, vector<Type*>*> keywordsTypes; //Словарь для типов keywords
						map<string, vector<string>*> parametersNames; //Словарь для имен параметров
						map<string, vector<Type*>*> parametersTypes; //Словарь для типов параметров
						map<string, bool> isClassMethod; //Словарь, содержащий принадлежность метода к классу
						map<string, Statement_node*> startNodes; //Словарь, содержащий стартовые узлы тел методов
						map<string, Type*> methods = curImplementation->Body->getMethods(&keywordsNames, &keywordsTypes, &parametersNames, &parametersTypes, &isClassMethod, &startNodes); //Получение методов
						for (auto it = methods.begin(); it != methods.end(); it++)
						{
							// Формирование дескриптора
							string descriptor = "(";
							for (int i = 0; i < keywordsTypes[it->first]->size(); i++) {
								descriptor += keywordsTypes[it->first]->at(i)->getDescriptor();
							}
							descriptor += ")";
							descriptor += it->second->getDescriptor();

							bool isClass = isClassMethod[it->first];// Признак принадлежности к классу
							vector<Type*>* curParametersTypes = parametersTypes[it->first]; // Типы параметров
							vector<Type*>* curKeywordsTypes = keywordsTypes[it->first]; // Типы keywords
							Statement_node* curStart = startNodes[it->first]; // Узел начала тела метода

							MethodsTableElement *method = element->Methods->addMethod(element->ConstantTable, it->first, descriptor, isClass, curStart, it->second, curParametersTypes, curKeywordsTypes); //Добавление метода
							
							
							//Формирование таблицы локальных переменных
							LocalVariablesTable* locals = method->LocalVariables; //Таблица локальных переменных данного метода
							Type* type = new Type(CLASS_NAME_TYPE, element->getClassName()); // Тип для self переменной
							locals->findOrAddLocalVariable("self", type); //Добавление self в таблицу локальных переменных
							//Добавление keywords в таблицу локальных переменных
							for (int i = 0; i < keywordsNames[it->first]->size(); i++) {
								locals->findOrAddLocalVariable(keywordsNames[it->first]->at(i), keywordsTypes[it->first]->at(i));
							}
							//Добавление parameters в таблицу локальных переменных
							for (int i = 0; i < parametersNames[it->first]->size(); i++) {
								locals->findOrAddLocalVariable(parametersNames[it->first]->at(i), parametersTypes[it->first]->at(i));
							}
							//Получение и добавление локальных переменных внутри метода
							vector<string> varsNames;
							vector<Type*> varsTypes;
							method->BodyStart->findLocalVariables(&varsNames, &varsTypes);
							for (int i = 0; i < varsNames.size(); i++)
							{
								locals->findOrAddLocalVariable(varsNames[i], varsTypes[i]);
							}
						}
					}
				}
            }
            else if (cur->type == INTERFACE_CLASS_BLOCK_TYPE)
            { // Интерфейс
                Class_interface_node* curInterface = (Class_interface_node*)cur;
                string className = curInterface->ClassName; // Имя класса
                string superclassName = curInterface->SuperclassName; // Имя суперкласса
                ClassesTableElement* element = ClassesTable::addClass(className, &superclassName, false); // Добавление класса в таблицу

				if (curInterface->Body != NULL) {
					// Добавление переменных
					map<string, Expression_node*> initializers;
					map<string, Type*> vars = curInterface->Body->getVariables(&initializers);
					for (auto it = vars.begin(); it != vars.end(); it++) {
						if (element->Fields->items.count(it->first) && element->Fields->items[it->first]->InitialValue != NULL && initializers[it->first] != NULL) {
							string msg = "Variable '" + it->first + "' redifinition in class '" + className + "'\n";
							throw std::exception(msg.c_str());
						}
						if (element->Fields->items.count(it->first) && (element->Fields->items[it->first]->DescriptorStr != it->second->getDescriptor() || element->Fields->items[it->first]->type->ArrSize != it->second->ArrSize)) {
							string msg = "Variable '" + it->first + "' in class '" + className + "' has conflict types.\n";
							throw std::exception(msg.c_str());
						}
						element->Fields->addField(element->ConstantTable, it->first, it->second->getDescriptor(), false, it->second, initializers[it->first]);
					}

					// Добавление instance variables
					vector<Type*> varTypes;
					vector<string> instanceVariables = curInterface->Body->getInstanceVariables(&varTypes);
					for (int i = 0; i < instanceVariables.size(); i++)
					{
						element->Fields->addField(element->ConstantTable, instanceVariables[i], varTypes[i]->getDescriptor(), true, varTypes[i], NULL);
					}

					// Добавление методов
					map<string, vector<string>*> keywordsNames; //Словарь для имен keywords
					map<string, vector<Type*>*> keywordsTypes; //Словарь для типов keywords
					map<string, vector<string>*> parametersNames; //Словарь для имен параметров
					map<string, vector<Type*>*> parametersTypes; //Словарь для типов параметров
					map<string, bool> isClassMethod; //Словарь, содержащий принадлежность метода к классу
					map<string, Type*> methods = curInterface->Body->getMethods(&keywordsNames, &keywordsTypes, &parametersNames, &parametersTypes, &isClassMethod); //Получение методов
					for (auto it = methods.begin(); it != methods.end(); it++)
					{
						// Формирование дескриптора
						string descriptor = "(";
						for (int i = 0; i < keywordsTypes[it->first]->size(); i++) {
							descriptor += keywordsTypes[it->first]->at(i)->getDescriptor();
						}
						descriptor += ")";
						descriptor += it->second->getDescriptor();

						bool isClass = isClassMethod[it->first];// Признак принадлежности к классу
						vector<Type*>* curParametersTypes = parametersTypes[it->first]; // Типы параметров
						vector<Type*>* curKeywordsTypes = keywordsTypes[it->first]; // Типы keywords

						MethodsTableElement *method = element->Methods->addMethod(element->ConstantTable, it->first, descriptor, isClass, NULL, it->second, curParametersTypes, curKeywordsTypes); //Добавление метода
					

						//Формирование таблицы локальных переменных
						LocalVariablesTable* locals = method->LocalVariables; //Таблица локальных переменных данного метода
						Type* type = new Type(CLASS_NAME_TYPE, element->getClassName()); // Тип для self переменной
						locals->findOrAddLocalVariable("self", type); //Добавление self в таблицу локальных переменных
						//Добавление keywords в таблицу локальных переменных
						for (int i = 0; i < keywordsNames[it->first]->size(); i++) {
							locals->findOrAddLocalVariable(keywordsNames[it->first]->at(i), keywordsTypes[it->first]->at(i));
						}
						//Добавление parameters в таблицу локальных переменных
						for (int i = 0; i < parametersNames[it->first]->size(); i++) {
							locals->findOrAddLocalVariable(parametersNames[it->first]->at(i), parametersTypes[it->first]->at(i));
						}
					}

					// Добавление свойств
					map<string, bool> isReadonly; //Значение аттрибута readonly для property
					map<string, Type*> propertiesTypes = curInterface->Body->getProperties(&isReadonly);
					for (auto it = propertiesTypes.cbegin(); it != propertiesTypes.cend(); it++)
					{
						element->Properties->addProperty(element->ConstantTable, it->first, it->second->getDescriptor(), isReadonly[it->first], it->second);
					}
				}
            }
        }
    }
}

//---------- Program_node ----------

void Program_node::fillClassesTable()
{
    list->fillTables();
}

//---------- Interface_body_node ---------- 

vector<string> Interface_body_node::getInstanceVariables(vector<Type*>* varTypes)
{
	Instance_variables_declaration_node* first = Variables->First;
	vector<string> res;
	while (first != NULL)
	{
		vector<Type*> *types = new vector<Type*>;
		vector <string> names = first->getInstanceVariables(types);
		for (int i = 0; i < names.size(); i++)
		{
			if (std::find(res.begin(), res.end(), names[i]) != res.end())
			{
				string msg = "Variable '" + names[i] + "' redeclaration";
				throw new std::exception(msg.c_str());
			}
			res.push_back(names[i]);
			varTypes->push_back(types->at(i));
		}
		first = first->Next;
	}
	return res;
}

map<string, Type*> Interface_body_node::getVariables(map<string, Expression_node*>* initializers)
{
	vector<Interface_declaration_list_node::interface_declaration>* declarations = Declaration_list->Declarations; //Список объявлений
	map<string, Type*> res;
	for (auto it = declarations->cbegin(); it < declarations->cend(); it++)
	{
		Declaration_node* declaration = it->declaration;
		if (declaration != NULL)
		{
			 map<string,Type*> cur = declaration->getDeclaration(initializers);
			 for (auto iterator = cur.begin(); iterator != cur.end(); iterator++)
			 {
				 res[iterator->first] = iterator->second;
			 }
		}
	}
	return res;
}

map<string, Type*> Interface_body_node::getMethods(map<string, vector<string>*>* keywordsNames, map<string, vector<Type*>*> *keywordsTypes, map<string, vector<string>*>* parametersNames, map<string, vector<Type*>*> *parametersTypes, map<string, bool>* isClassMethod)
{
	map<string, Type*> res;
	if (Declaration_list != NULL)
	{
		vector<Interface_declaration_list_node::interface_declaration>* declarations = Declaration_list->Declarations; //Список объявлений
		
		for (auto it = declarations->cbegin(); it < declarations->cend(); it++)
		{
			Method_declaration_node* declaration = it->method_declaration;
			if (declaration != NULL)
			{
				vector<string>* curKeywordsNames = new vector<string>;
				vector<Type*>* curKeywordsTypes = new vector<Type*>;
				vector<string>* curParametersNames = new vector<string>;
				vector<Type*>* curParametersTypes = new vector<Type*>;
				bool isClass;
				Type* returnType = new Type(VOID_TYPE);
				string methodName = declaration->getMethod(&returnType, curKeywordsNames, curKeywordsTypes, curParametersNames, curParametersTypes, &isClass);
				if (isClass)
					methodName += string("Static");
				else
					methodName += string("Dynamic");
				if (res.count(methodName))
				{
					string msg = "Method '" + methodName + "' redeclaration.\n";
					throw std::exception(msg.c_str());
				}
				(*keywordsNames)[methodName] = curKeywordsNames;
				(*keywordsTypes)[methodName] = curKeywordsTypes;
				(*parametersNames)[methodName] = curParametersNames;
				(*parametersTypes)[methodName] = curParametersTypes;
				(*isClassMethod)[methodName] = isClass;
				res[methodName] = returnType;
			}
		}
	}
	return res;
}

map<string, Type*> Interface_body_node::getProperties(map<string, bool>* isReadonly)
{
	map<string, Type*> res;
	if (Declaration_list != NULL)
	{
		vector<Interface_declaration_list_node::interface_declaration>* declarations = Declaration_list->Declarations; // Список объявлений
		for (auto it = declarations->cbegin(); it < declarations->cend(); it++)
		{
			Property_node* property = it -> property; //Свойство
			if (property != NULL)
			{
				Type* type = property->type->toDataType(); //Тип
				for (char* name : *property->Names->Identifier_names)
				{//Для каждого имени
					if (res.count(string(name)))
					{ // Переопределение свойства
						string msg = "Property '" + string(name) + "' redeclaration.";
						throw new std::exception(msg.c_str());
					}
					res[string(name)] = type; //Добавить тип
					(*isReadonly)[string(name)] = property->Attribute->type == READONLY_ATTRIBUTE_TYPE; //Добавить атрибут
				}
			}
		}
	}
	return res;
}

//---------- Instance_variables_declaration_node ----------

vector<string> Instance_variables_declaration_node::getInstanceVariables(vector<Type*>* types)
{
    vector<string> names; //Вектор имен полей
    vector<Declarator_node*> variablesDeclarators = *DeclaratorList->Declarators; //Вектор деклараторов
    for (auto it = variablesDeclarators.begin(); it != variablesDeclarators.end(); it++)
    {
        names.push_back((*it)->Identifier); //Добавление имени переменной
        type_type type = this->type->type; //Получение datatype
        Expression_node* arrSize = (*it)->Expression; //Размер массива
        if (type == CLASS_NAME_TYPE)
        {
			string className = string(this->type->ClassName); //Имя класса
			if (arrSize != NULL)
			{ // тип класса и массив
				Type* curType = new Type(type, className, arrSize->constant.num->number.Int);
				types->push_back(curType);
			}
			else
			{ // тип класса 
				Type* curType = new Type(type, className);
				types->push_back(curType);
			}
        }
        else
        {
            if (arrSize != NULL)
			{ // Примитивный тип и массив
				Type* curType = new Type(type, arrSize->constant.num->number.Int);
				types->push_back(curType);
            }
            else
			{ // Примитивный тип 
				Type* curType = new Type(type);
				types->push_back(curType);
            }
        }
    }
	return names;
}

// ---------- Implementation_body_node ----------
vector<string> Implementation_body_node::getInstanceVariables(vector<Type*> *varTypes)
{
	Instance_variables_declaration_node* first = Variables->First;
	vector<string> res;
	while (first != NULL)
	{
		vector<Type*>* types = new vector<Type*>;
		vector <string> names = first->getInstanceVariables(types);
		for (int i = 0; i < names.size(); i++)
		{
			if (std::find(res.begin(), res.end(), names[i]) != res.end())
			{
				string msg = "Variable '" + names[i] + "' redeclaration";
				throw new std::exception(msg.c_str());
			}
			res.push_back(names[i]);
			varTypes->push_back(types->at(i));
		}
		first = first->Next;
	}
	return res;
}

map<string, Type*> Implementation_body_node::getVariables(map<string, Expression_node*>* initializers)
{
	map<string, Type*> res;
	if (Declaration_list != NULL)
	{
		vector<Implementation_definition_list_node::implementation_definition>* definitions = Declaration_list->Definitions; //Список определений
		for (auto it = definitions->cbegin(); it < definitions->cend(); it++)
		{
			Declaration_node* declaration = it->declaration;
			if (declaration != NULL)
			{
				map<string, Type*> cur = declaration->getDeclaration(initializers);
				for (auto iterator = cur.begin(); iterator != cur.end(); iterator++)
				{
					res[iterator->first] = iterator->second;
				}
			}
		}
	}
	return res;
}

map<string, Type*> Implementation_body_node::getMethods(map<string, vector<string>*>* keywordsNames, map<string, vector<Type*>*>* keywordsTypes, map<string, vector<string>*>* parametersNames, map<string, vector<Type*>*>* parametersTypes, map<string, bool>* isClassMethod, map<string, Statement_node*> *bodyStartNode)
{
	map<string, Type*> res;
	if (Declaration_list != NULL)
	{
		vector<Implementation_definition_list_node::implementation_definition>* definitions = Declaration_list->Definitions; //Список объявлений
		for (auto it = definitions->cbegin(); it < definitions->cend(); it++)
		{
			Method_definition_node* definition = it->method_definition;
			if (definition != NULL)
			{
				vector<string>* curKeywordsNames = new vector<string>;
				vector<Type*>* curKeywordsTypes = new vector<Type*>;
				vector<string>* curParametersNames = new vector<string>;
				vector<Type*>* curParametersTypes = new vector<Type*>;
				bool isClass;
				Type* returnType = new Type(VOID_TYPE);
				Statement_node* bodyStart;
				string methodName = definition->getMethod(&returnType, curKeywordsNames, curKeywordsTypes, curParametersNames, curParametersTypes, &isClass, &bodyStart);
				if (isClass)
					methodName += string("Static");
				else
					methodName += string("Dynamic");
				if (res.count(methodName))
				{
					string msg = "Method '" + methodName + "' redifinition.\n";
					throw std::exception(msg.c_str());
				}
				(*keywordsNames)[methodName] = curKeywordsNames;
				(*keywordsTypes)[methodName] = curKeywordsTypes;
				(*parametersNames)[methodName] = curParametersNames;
				(*parametersTypes)[methodName] = curParametersTypes;
				(*isClassMethod)[methodName] = isClass;
				(*bodyStartNode)[methodName] = bodyStart;
				res[methodName] = returnType;
			}
		}
	}
	return res;
}

// ---------- Declaration_node ----------

map<string, Type*> Declaration_node::getDeclaration(map<string, Expression_node*>* initializators)
{
	vector<Init_declarator_node*>* declarators = init_declarator_list->getElements(); //Деклараторы
	map<string, Type*> res;
	for (auto it = declarators->begin(); it < declarators->end(); it++)
	{
		string name = string((*it)->Declarator); //Имя
		type_type type = this->typeNode->type; //Тип
		Expression_node* arrSize = (*it)->ArraySize; //Размер массива
		Expression_node* initializer = (*it)->expression; // Инициализатор
		Expression_list_node* initializerList = (*it)->InitializerList; // Инициализатор массива
		if (type == CLASS_NAME_TYPE)
		{
			string className = this->typeNode->ClassName;
			if (arrSize != NULL || initializerList != NULL)
			{ // Массив типа класса
				int arraySize;
				if (arrSize != NULL)
				{
					arraySize = arrSize->constant.num->number.Int;
				}
				else
				{
					arraySize = initializerList->getElements()->size();
				}
				Type* curType = new Type(type, className, arraySize);
				res[name] = curType;
				if (initializators->count(name) && (*initializators)[name] != NULL && initializerList != NULL) {
					string msg = "Variable '" + name + "' redifinition";
					throw new exception(msg.c_str());
				}
				(*initializators)[name] = initializerList;
			}
			else
			{ //Тип класса
				Type* curType = new Type(type, className);
				res[name] = curType;
				if (initializators->count(name) && (*initializators)[name] != NULL && initializer != NULL) {
					string msg = "Variable '" + name + "' redifinition";
					throw new exception(msg.c_str());
				}
				(*initializators)[name] = initializer;
			}
		}
		else
		{ 
			if (arrSize != NULL || initializerList != NULL)
			{ // Массив примитивного типа
				int arraySize;
				if (arrSize != NULL)
				{
					arraySize = arrSize->constant.num->number.Int;
				}
				else
				{
					arraySize = initializerList->getElements()->size();
				}
				Type* curType = new Type(type, arraySize);
				res[name] = curType;
				if (initializators->count(name) && (*initializators)[name] != NULL && initializerList != NULL) {
					string msg = "Variable '" + name + "' redifinition";
					throw new exception(msg.c_str());
				}
				(*initializators)[name] = initializerList;
			}
			else
			{ //Примитивный тип
				Type* curType = new Type(type);
				res[name] = curType;
				if (initializators->count(name) && (*initializators)[name] != NULL && initializer != NULL) {
					string msg = "Variable '" + name + "' redifinition";
					throw new exception(msg.c_str());
				}
				(*initializators)[name] = initializer;
			}
		}
	}
	return res;
}

// ------------ Method_declaration_node ------------
string Method_declaration_node::getMethod(Type** returnType, vector<string>* keywordsNames, vector<Type*> *keywordsTypes, vector<string>* parametersNames, vector<Type*> *parametersTypes, bool *isClassmethod)
{
	*returnType = MethodType->toDataType(); // Тип возвращаемого значения
	// Тип метода
	if (type == CLASS_METHOD_DECLARATION_TYPE)
		*isClassmethod = true;
	else if (type == INSTANCE_METHOD_DECLARATION_TYPE)
		*isClassmethod = false;
	string mathodName = string(MethodSelector->MethodName); // Имя метода
	MethodSelector->getParams(keywordsNames, keywordsTypes, parametersNames, parametersTypes); // Параметры
	return mathodName;
}

// ---------- Method_definition_node ----------
string Method_definition_node::getMethod(Type** returnType, vector<string>* keywordsNames, vector<Type*>* keywordsTypes, vector<string>* parametersNames, vector<Type*>* parametersTypes, bool* isClassmethod, Statement_node** bodyStart)
{
	*returnType = MethodType->toDataType(); // Тип возвращаемого значения
	// Тип метода
	if (type == CLASS_METHOD_DECLARATION_TYPE)
		*isClassmethod = true;
	else if (type == INSTANCE_METHOD_DECLARATION_TYPE)
		*isClassmethod = false;
	string methodName = string(MethodSelector->MethodName); // Имя метода
	MethodSelector->getParams(keywordsNames, keywordsTypes, parametersNames, parametersTypes); // Параметры
	*bodyStart = MethodBody->First; // Начало тела метода
	return methodName;
}


// ---------- Type_node ----------
Type* Type_node::toDataType()
{
	if (type == CLASS_NAME_TYPE)
	{
		string className = ClassName;
		Type* res = new Type(type, className);
		return res;
	}
	else
	{
		Type* res = new Type(type);
		return res;
	}
}

// ---------- Method_selector_node ----------
void Method_selector_node::getParams(vector<string>* keywordsNames, vector<Type*>* keywordsTypes, vector<string>* parametersNames, vector<Type*> *parametersTypes)
{
	if (KeywordDeclaration != NULL) { //Добавление первого параметра
		string firstKeywordName = string(KeywordDeclaration->KeywordName); // 
		Type* firstKeywordType = KeywordDeclaration->KeywordType->toDataType();
		keywordsNames->push_back(firstKeywordName);
		keywordsTypes->push_back(firstKeywordType);
	}

	if (KeywordSelector != NULL) { //Добавление остальных параметров
		vector<Keyword_declaration_node*>* keywordsList = KeywordSelector->getElements(); //Список keword
		for (auto it = keywordsList->cbegin(); it < keywordsList->cend(); it++)
		{
			Keyword_declaration_node* keyword = *it; //Ключевое слово
			string name = string(keyword->KeywordName); //Имя
			Type* type = keyword->KeywordType->toDataType(); //Тип
			if (std::find(keywordsNames->begin(), keywordsNames->end(), name) != keywordsNames->end()) { //Переопределение параметра
				string msg = "Parameter '" + name + "' redifinition";
				throw new exception(msg.c_str());
			}
			keywordsNames->push_back(name); //Добавление имени
			keywordsTypes->push_back(type); //Добавление типа
		}
	}

	if (ParameterListNode != NULL) { //Добавление параметров
		vector<Parameter_declaration_node*>* parametersList = ParameterListNode->getElements(); //Список параметров
		for (auto it = parametersList->cbegin(); it < parametersList->cend(); it++)
		{
			Parameter_declaration_node* parameter = *it; //Параметр
			string name = string(parameter->name); //Имя
			Type* type = parameter->type->toDataType(); //Тип
			if (std::find(parametersNames->begin(), parametersNames->end(), name) != parametersNames->end() || std::find(keywordsNames->begin(), keywordsNames->end(), name) != keywordsNames->end()) { //Переопределение параметра
				string msg = "Parameter '" + name + "' redifinition";
				throw new exception(msg.c_str());
			}
			parametersNames->push_back(name); //Добавление имени
			parametersTypes->push_back(type); //Добавление типа
		}
	}
}

// ---------- Statement_node ----------
void Statement_node::findLocalVariables(vector<string>* localVariablesNames, vector<Type*>* localVariablesTypes)
{
	vector<Init_declarator_node*>* declarators = NULL; //Деклараторы
	Type_node* typeNode = NULL;
	// Получение деклараторов
	if (type == DECLARATION_STATEMENT_TYPE)
	{
		Declaration_node* declaration = (Declaration_node*)this;
		declarators = declaration->init_declarator_list->getElements();
		typeNode = declaration->typeNode;
	}
	if (type == FOR_STATEMENT_TYPE)
	{
		For_statement_node* for_stmt = (For_statement_node*)this;
		declarators = for_stmt->InitList->getElements();
		typeNode = for_stmt->NameType;
	}
	if (declarators != NULL && typeNode != NULL)
		getTypesFromInitDeclaratorType(declarators, typeNode, localVariablesNames, localVariablesTypes); // Получение переменных



	if (Next != NULL)
	{
		Next->findLocalVariables(localVariablesNames, localVariablesTypes);
	}
}

void getTypesFromInitDeclaratorType(vector<Init_declarator_node*>* declarators, Type_node* typeNode, vector<string>* varsNames, vector<Type*>* varsTypes)
{
	for (auto it = declarators->begin(); it < declarators->end(); it++)
	{
		string name = string((*it)->Declarator); //Имя
		type_type type = typeNode->type; //Тип
		Expression_node* arrSize = (*it)->ArraySize; //Размер массива
		Expression_node* initializer = (*it)->expression; // Инициализатор
		Expression_list_node* initializerList = (*it)->InitializerList; // Инициализатор массива
		if (type == CLASS_NAME_TYPE)
		{
			string className = typeNode->ClassName;
			if (arrSize != NULL || initializerList != NULL)
			{ // Массив типа класса
				int arraySize;
				if (arrSize != NULL)
				{
					arraySize = arrSize->constant.num->number.Int;
				}
				else
				{
					arraySize = initializerList->getElements()->size();
				}
				Type* curType = new Type(type, className, arraySize);
				if (std::find(varsNames->begin(), varsNames->end(), name) != varsNames->end() && initializerList != NULL) {
					string msg = "Variable '" + name + "' redifinition";
					throw new exception(msg.c_str());
				}
				varsNames->push_back(name);
				varsTypes->push_back(curType);
				
			}
			else
			{ //Тип класса
				Type* curType = new Type(type, className);
				if (std::find(varsNames->begin(), varsNames->end(), name) != varsNames->end() && initializer != NULL) {
					string msg = "Variable '" + name + "' redifinition";
					throw new exception(msg.c_str());
				}
				varsNames->push_back(name);
				varsTypes->push_back(curType);
			}
		}
		else
		{
			if (arrSize != NULL || initializerList != NULL)
			{ // Массив примитивного типа
				int arraySize;
				if (arrSize != NULL)
				{
					arraySize = arrSize->constant.num->number.Int;
				}
				else
				{
					arraySize = initializerList->getElements()->size();
				}
				Type* curType = new Type(type, arraySize);
				if (std::find(varsNames->begin(), varsNames->end(), name) != varsNames->end() && initializerList != NULL) {
					string msg = "Variable '" + name + "' redifinition";
					throw new exception(msg.c_str());
				}
				varsNames->push_back(name);
				varsTypes->push_back(curType);
			}
			else
			{ //Примитивный тип
				Type* curType = new Type(type);
				if (std::find(varsNames->begin(), varsNames->end(), name) != varsNames->end() && initializer != NULL) {
					string msg = "Variable '" + name + "' redifinition";
					throw new exception(msg.c_str());
				}
				varsNames->push_back(name);
				varsTypes->push_back(curType);
			}
		}
	}
}
