#include "tables.h"
// ------------------------------ Обход дерева -------------------------------

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

					map<string, int>* indexes = new map<string, int>;
					map<string, Type*> instanceVariables = curImplementation->Body->getInstanceVariables(indexes);

					if (element->IsHaveInterface) { // У класса был интерфейс
						// Проверить instance variables
						if (instanceVariables.size() > 0) {
							// Сверить instance variables
							for (auto it = instanceVariables.begin(); it != instanceVariables.end(); it++)
							{
								if (!element->Fields->items.count(it->first)) {
									string msg = "Instance variable '" + it->first + "' not found in interface '" + className + "'\n";
									throw std::exception(msg.c_str());
								}

								if (element->Fields->items[it->first]->InstanceIndex != (*indexes)[it->first])
								{
									string msg = "Instance variable '" + it->first + "' in class '" + className + "' has different position from the position specified in the interface'\n";
									throw std::exception(msg.c_str());
								}
								if (it->second->getDescriptor() != element->Fields->items[it->first]->DescriptorStr)
								{
									string msg = "Instance variable '" + it->first + "' in class '" + className + "' has different type from the type specified in the interface'\n";
									throw std::exception(msg.c_str());
								}
							}
						}
					}
					else { // У класса не было интерфейса
						// Добавить instance variables
						for (auto it = instanceVariables.begin(); it != instanceVariables.end(); it++)
						{
							element->Fields->addField(element->ConstantTable, it->first, it->second->getDescriptor(), true, it->second, NULL);
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
					map<string, Type*> instanceVariables = curInterface->Body->getInstanceVariables();
					for (auto it = instanceVariables.begin(); it != instanceVariables.end(); it++)
					{
						element->Fields->addField(element->ConstantTable, it->first, it->second->getDescriptor(), true, it->second, NULL);
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

map<string, Type*> Interface_body_node::getInstanceVariables()
{
	Instance_variables_declaration_node* first = Variables->First;
	map<string, Type*> res;
	while (first != NULL)
	{
		vector<Type*> *types = new vector<Type*>;
		vector <string> names = first->getInstanceVariables(types);
		for (int i = 0; i < names.size(); i++)
		{
			res[names[i]] = types->at(i);
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
map<string, Type*> Implementation_body_node::getInstanceVariables(map<string, int> *indexes)
{
	Instance_variables_declaration_node* first = Variables->First;
	map<string, Type*> res;
	while (first != NULL)
	{
		vector<Type*>* types = new vector<Type*>;
		vector <string> names = first->getInstanceVariables(types);
		for (int i = 0; i < names.size(); i++)
		{
			res[names[i]] = types->at(i);
			(*indexes)[names[i]] = i + 1;
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

// ---------- Declaration_node ----------

map<string, Type*> Declaration_node::getDeclaration(map<string, Expression_node*>* initializators)
{
	vector<Init_declarator_node*>* declarators = init_declarator_list->getElements(); //Деклараторы
	map<string, Type*> res;
	for (auto it = declarators->begin(); it < declarators->end(); it++)
	{
		string name = string((*it)->Declarator); //Имя
		type_type type = this->type->type; //Тип
		Expression_node* arrSize = (*it)->ArraySize; //Размер массива
		Expression_node* initializer = (*it)->expression; // Инициализатор
		Expression_list_node* initializerList = (*it)->InitializerList; // Инициализатор массива
		if (type == CLASS_NAME_TYPE)
		{
			string className = this->type->ClassName;
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
