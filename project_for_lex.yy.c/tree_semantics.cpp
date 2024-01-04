#include "tables.h"
#include <algorithm>
// ------------------------------ ����� ������ -------------------------------

void getTypesFromInitDeclaratorType(vector<Init_declarator_node*>* declarators, Type_node* typeNode, vector<string>* varsNames, vector<Type*>* varsTypes);

// ---------- Function_and_class_list_node ----------

void Function_and_class_list_node::fillTables()
{
	ClassesTable::initRTL(); //���������������� RTL

    for (int i = 0; i < FunctionsAndClasses->size(); i++)
    { //��� ������� �������� � ������
        if (FunctionsAndClasses->at(i).class_block != NULL)
        { //���� ������� - �����
            Class_block_node* cur = FunctionsAndClasses->at(i).class_block;
            if (cur->type == IMPLEMENTATION_CLASS_BLOCK_TYPE)
            { // ����������
                Class_implementation_node* curImplementation = (Class_implementation_node*)cur;
                string className = curImplementation->ClassName; // ��� ������
                string *superclassName = curImplementation->SuperclassName == NULL ? NULL : new string(curImplementation->SuperclassName); // ��� �����������
				ClassesTableElement *element = ClassesTable::addClass(className, superclassName, true); // ���������� ������ � �������

				if (curImplementation->Body != NULL)
				{
					// ���������� ����������
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

					if (element->IsHaveInterface) { // � ������ ��� ���������
						// ��������� instance variables
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
							// ������� instance variables
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

						// ���������� �������
						map<string, vector<string>*> keywordsNames; //������� ��� ���� keywords
						map<string, vector<Type*>*> keywordsTypes; //������� ��� ����� keywords
						map<string, vector<string>*> parametersNames; //������� ��� ���� ����������
						map<string, vector<Type*>*> parametersTypes; //������� ��� ����� ����������
						map<string, bool> isClassMethod; //�������, ���������� �������������� ������ � ������
						map<string, Statement_node*> startNodes; //�������, ���������� ��������� ���� ��� �������
						map<string, Type*> methods = curImplementation->Body->getMethods(&keywordsNames, &keywordsTypes, &parametersNames, &parametersTypes, &isClassMethod, &startNodes); //��������� �������
						for (auto it = methods.begin(); it != methods.end(); it++)
						{
							// ������������ �����������
							string descriptor = "(";
							for (int i = 0; i < keywordsTypes[it->first]->size(); i++) {
								descriptor += keywordsTypes[it->first]->at(i)->getDescriptor();
							}
							descriptor += ")";
							descriptor += it->second->getDescriptor();
							if (element->Methods->items.count(it->first))
							{ //����� ����. ��������.
								MethodsTableElement* curMethod = element->Methods->items[it->first];
								if (descriptor != curMethod->DescriptorStr) {
									string msg = "Method '" + it->first + "' in class '" + className + "' has different type from the type specified in the interface\n";
									throw std::exception(msg.c_str());
								}

								curMethod->BodyStart = startNodes[it->first]; //���������� ����
								if (curMethod->BodyStart != NULL) {
									//��������� � ���������� ��������� ���������� ������ ������
									vector<string> varsNames;
									vector<Type*> varsTypes;
									curMethod->BodyStart->findLocalVariables(&varsNames, &varsTypes);
									for (int i = 0; i < varsNames.size(); i++)
									{
										curMethod->LocalVariables->findOrAddLocalVariable(varsNames[i], varsTypes[i]);
									}
								}
							}
							else
							{ //������ ���. ����������.
								bool isClass = isClassMethod[it->first];// ������� �������������� � ������
								vector<Type*>* curParametersTypes = parametersTypes[it->first]; // ���� ����������
								vector<Type*>* curKeywordsTypes = keywordsTypes[it->first]; // ���� keywords
								Statement_node* curStart = startNodes[it->first]; // ���� ������ ���� ������

								MethodsTableElement *method = element->Methods->addMethod(element->ConstantTable, it->first, descriptor, isClass, curStart, it->second, curParametersTypes, curKeywordsTypes); //���������� ������
								
								//������������ ������� ��������� ����������
								LocalVariablesTable* locals = method->LocalVariables; //������� ��������� ���������� ������� ������
								Type* type = new Type(CLASS_NAME_TYPE, element->getClassName()); // ��� ��� self ����������
								locals->findOrAddLocalVariable("self", type); //���������� self � ������� ��������� ����������
								//���������� keywords � ������� ��������� ����������
								for (int i = 0; i < keywordsNames[it->first]->size(); i++) {
									locals->findOrAddLocalVariable(keywordsNames[it->first]->at(i), keywordsTypes[it->first]->at(i));
								}
								//���������� parameters � ������� ��������� ����������
								for (int i = 0; i < parametersNames[it->first]->size(); i++) {
									locals->findOrAddLocalVariable(parametersNames[it->first]->at(i), parametersTypes[it->first]->at(i));
								}
								//��������� � ���������� ��������� ���������� ������ ������
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
					else { // � ������ �� ���� ����������
						// �������� instance variables
						for (int i = 0; i < instanceVariables.size(); i++)
						{
							element->Fields->addField(element->ConstantTable, instanceVariables[i], varTypes[i]->getDescriptor(), true, varTypes[i], NULL);
						}

						// ���������� �������
						map<string, vector<string>*> keywordsNames; //������� ��� ���� keywords
						map<string, vector<Type*>*> keywordsTypes; //������� ��� ����� keywords
						map<string, vector<string>*> parametersNames; //������� ��� ���� ����������
						map<string, vector<Type*>*> parametersTypes; //������� ��� ����� ����������
						map<string, bool> isClassMethod; //�������, ���������� �������������� ������ � ������
						map<string, Statement_node*> startNodes; //�������, ���������� ��������� ���� ��� �������
						map<string, Type*> methods = curImplementation->Body->getMethods(&keywordsNames, &keywordsTypes, &parametersNames, &parametersTypes, &isClassMethod, &startNodes); //��������� �������
						for (auto it = methods.begin(); it != methods.end(); it++)
						{
							// ������������ �����������
							string descriptor = "(";
							for (int i = 0; i < keywordsTypes[it->first]->size(); i++) {
								descriptor += keywordsTypes[it->first]->at(i)->getDescriptor();
							}
							descriptor += ")";
							descriptor += it->second->getDescriptor();

							bool isClass = isClassMethod[it->first];// ������� �������������� � ������
							vector<Type*>* curParametersTypes = parametersTypes[it->first]; // ���� ����������
							vector<Type*>* curKeywordsTypes = keywordsTypes[it->first]; // ���� keywords
							Statement_node* curStart = startNodes[it->first]; // ���� ������ ���� ������

							MethodsTableElement *method = element->Methods->addMethod(element->ConstantTable, it->first, descriptor, isClass, curStart, it->second, curParametersTypes, curKeywordsTypes); //���������� ������
							
							
							//������������ ������� ��������� ����������
							LocalVariablesTable* locals = method->LocalVariables; //������� ��������� ���������� ������� ������
							Type* type = new Type(CLASS_NAME_TYPE, element->getClassName()); // ��� ��� self ����������
							locals->findOrAddLocalVariable("self", type); //���������� self � ������� ��������� ����������
							//���������� keywords � ������� ��������� ����������
							for (int i = 0; i < keywordsNames[it->first]->size(); i++) {
								locals->findOrAddLocalVariable(keywordsNames[it->first]->at(i), keywordsTypes[it->first]->at(i));
							}
							//���������� parameters � ������� ��������� ����������
							for (int i = 0; i < parametersNames[it->first]->size(); i++) {
								locals->findOrAddLocalVariable(parametersNames[it->first]->at(i), parametersTypes[it->first]->at(i));
							}
							//��������� � ���������� ��������� ���������� ������ ������
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
            { // ���������
                Class_interface_node* curInterface = (Class_interface_node*)cur;
                string className = curInterface->ClassName; // ��� ������
                string superclassName = curInterface->SuperclassName; // ��� �����������
                ClassesTableElement* element = ClassesTable::addClass(className, &superclassName, false); // ���������� ������ � �������

				if (curInterface->Body != NULL) {
					// ���������� ����������
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

					// ���������� instance variables
					vector<Type*> varTypes;
					vector<string> instanceVariables = curInterface->Body->getInstanceVariables(&varTypes);
					for (int i = 0; i < instanceVariables.size(); i++)
					{
						element->Fields->addField(element->ConstantTable, instanceVariables[i], varTypes[i]->getDescriptor(), true, varTypes[i], NULL);
					}

					// ���������� �������
					map<string, vector<string>*> keywordsNames; //������� ��� ���� keywords
					map<string, vector<Type*>*> keywordsTypes; //������� ��� ����� keywords
					map<string, vector<string>*> parametersNames; //������� ��� ���� ����������
					map<string, vector<Type*>*> parametersTypes; //������� ��� ����� ����������
					map<string, bool> isClassMethod; //�������, ���������� �������������� ������ � ������
					map<string, Type*> methods = curInterface->Body->getMethods(&keywordsNames, &keywordsTypes, &parametersNames, &parametersTypes, &isClassMethod); //��������� �������
					for (auto it = methods.begin(); it != methods.end(); it++)
					{
						// ������������ �����������
						string descriptor = "(";
						for (int i = 0; i < keywordsTypes[it->first]->size(); i++) {
							descriptor += keywordsTypes[it->first]->at(i)->getDescriptor();
						}
						descriptor += ")";
						descriptor += it->second->getDescriptor();

						bool isClass = isClassMethod[it->first];// ������� �������������� � ������
						vector<Type*>* curParametersTypes = parametersTypes[it->first]; // ���� ����������
						vector<Type*>* curKeywordsTypes = keywordsTypes[it->first]; // ���� keywords

						MethodsTableElement *method = element->Methods->addMethod(element->ConstantTable, it->first, descriptor, isClass, NULL, it->second, curParametersTypes, curKeywordsTypes); //���������� ������
					

						//������������ ������� ��������� ����������
						LocalVariablesTable* locals = method->LocalVariables; //������� ��������� ���������� ������� ������
						Type* type = new Type(CLASS_NAME_TYPE, element->getClassName()); // ��� ��� self ����������
						locals->findOrAddLocalVariable("self", type); //���������� self � ������� ��������� ����������
						//���������� keywords � ������� ��������� ����������
						for (int i = 0; i < keywordsNames[it->first]->size(); i++) {
							locals->findOrAddLocalVariable(keywordsNames[it->first]->at(i), keywordsTypes[it->first]->at(i));
						}
						//���������� parameters � ������� ��������� ����������
						for (int i = 0; i < parametersNames[it->first]->size(); i++) {
							locals->findOrAddLocalVariable(parametersNames[it->first]->at(i), parametersTypes[it->first]->at(i));
						}
					}

					// ���������� �������
					map<string, bool> isReadonly; //�������� ��������� readonly ��� property
					map<string, Type*> propertiesTypes = curInterface->Body->getProperties(&isReadonly);
					for (auto it = propertiesTypes.cbegin(); it != propertiesTypes.cend(); it++)
					{
						element->Properties->addProperty(element->ConstantTable, it->first, it->second->getDescriptor(), isReadonly[it->first], it->second);
					}
				}
            }
        }
		else if (FunctionsAndClasses->at(i).function != NULL)
		{
			Function_node* cur = FunctionsAndClasses->at(i).function; //���� �������
			Type* returnType; //������������ ���
			Statement_node* body; //���� ������ ���� �������
			string functionName = cur->getFunction(&returnType, &body); //��� �������

			// ������������ �����������
			string descriptor = "()";
			descriptor += returnType->getDescriptor();

			FunctionsTableElement* element = FunctionsTable::addFunction(functionName, descriptor, body, NULL, NULL); // ���������� ������� � �������

			// ������������ ������� ��������� ����������
			LocalVariablesTable* locals = element->LocalVariables; //������� ��������� ���������� ������ �������
			Type* type = new Type(CLASS_NAME_TYPE, "rtl/Program"); //��� ��� this
			locals->findOrAddLocalVariable("this", type); //���������� self � ������� ��������� ����������
			vector<string> varsNames;
			vector<Type*> varsTypes;
			element->BodyStart->findLocalVariables(&varsNames, &varsTypes);
			for (int i = 0; i < varsNames.size(); i++)
			{
				locals->findOrAddLocalVariable(varsNames[i], varsTypes[i]);
			}
		}
    }

	ClassesTable::fillFieldRefs(); // ����� � ��������� field refs ��� �������
	FunctionsTable::fillFieldRefs(); //����� � ��������� fields refs � �������

	ClassesTable::fillMethodRefs(); //����� � ��������� method refs ��� �������
	FunctionsTable::fillMethodRefs(); //����� � ��������� method refs � �������

	ClassesTable::fillLiterals(); // ����� � ��������� string � integer ���������
	FunctionsTable::fillLiterals(); // ����� � ��������� string � integer ���������
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
	vector<Interface_declaration_list_node::interface_declaration>* declarations = Declaration_list->Declarations; //������ ����������
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
		vector<Interface_declaration_list_node::interface_declaration>* declarations = Declaration_list->Declarations; //������ ����������
		
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
		vector<Interface_declaration_list_node::interface_declaration>* declarations = Declaration_list->Declarations; // ������ ����������
		for (auto it = declarations->cbegin(); it < declarations->cend(); it++)
		{
			Property_node* property = it -> property; //��������
			if (property != NULL)
			{
				Type* type = property->type->toDataType(); //���
				for (char* name : *property->Names->Identifier_names)
				{//��� ������� �����
					if (res.count(string(name)))
					{ // ��������������� ��������
						string msg = "Property '" + string(name) + "' redeclaration.";
						throw new std::exception(msg.c_str());
					}
					res[string(name)] = type; //�������� ���
					(*isReadonly)[string(name)] = property->Attribute->type == READONLY_ATTRIBUTE_TYPE; //�������� �������
				}
			}
		}
	}
	return res;
}

//---------- Instance_variables_declaration_node ----------

vector<string> Instance_variables_declaration_node::getInstanceVariables(vector<Type*>* types)
{
    vector<string> names; //������ ���� �����
    vector<Declarator_node*> variablesDeclarators = *DeclaratorList->Declarators; //������ ������������
    for (auto it = variablesDeclarators.begin(); it != variablesDeclarators.end(); it++)
    {
        names.push_back((*it)->Identifier); //���������� ����� ����������
        type_type type = this->type->type; //��������� datatype
        Expression_node* arrSize = (*it)->Expression; //������ �������
        if (type == CLASS_NAME_TYPE)
        {
			string className = ClassesTable::getFullClassName(string(this->type->ClassName)); //��� ������
			if (arrSize != NULL)
			{ // ��� ������ � ������
				Type* curType = new Type(type, className, arrSize->num->Int);
				types->push_back(curType);
			}
			else
			{ // ��� ������ 
				Type* curType = new Type(type, className);
				types->push_back(curType);
			}
        }
        else
        {
            if (arrSize != NULL)
			{ // ����������� ��� � ������
				Type* curType = new Type(type, arrSize->num->Int);
				types->push_back(curType);
            }
            else
			{ // ����������� ��� 
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
		vector<Implementation_definition_list_node::implementation_definition>* definitions = Declaration_list->Definitions; //������ �����������
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
		vector<Implementation_definition_list_node::implementation_definition>* definitions = Declaration_list->Definitions; //������ ����������
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
	vector<Init_declarator_node*>* declarators = init_declarator_list->getElements(); //�����������
	map<string, Type*> res;
	for (auto it = declarators->begin(); it < declarators->end(); it++)
	{
		string name = string((*it)->Declarator); //���
		type_type type = this->typeNode->type; //���
		Expression_node* arrSize = (*it)->ArraySize; //������ �������
		Expression_node* initializer = (*it)->expression; // �������������
		Expression_list_node* initializerList = (*it)->InitializerList; // ������������� �������
		if (type == CLASS_NAME_TYPE)
		{
			string className = ClassesTable::getFullClassName(string(this->typeNode->ClassName));
			if (arrSize != NULL || initializerList != NULL)
			{ // ������ ���� ������
				int arraySize;
				if (arrSize != NULL)
				{
					arraySize = arrSize->num->Int;
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
			{ //��� ������
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
			{ // ������ ������������ ����
				int arraySize;
				if (arrSize != NULL)
				{
					arraySize = arrSize->num->Int;
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
			{ //����������� ���
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
	*returnType = MethodType->toDataType(); // ��� ������������� ��������
	// ��� ������
	if (type == CLASS_METHOD_DECLARATION_TYPE)
		*isClassmethod = true;
	else if (type == INSTANCE_METHOD_DECLARATION_TYPE)
		*isClassmethod = false;
	string mathodName = string(MethodSelector->MethodName); // ��� ������
	MethodSelector->getParams(keywordsNames, keywordsTypes, parametersNames, parametersTypes); // ���������
	return mathodName;
}

// ---------- Method_definition_node ----------
string Method_definition_node::getMethod(Type** returnType, vector<string>* keywordsNames, vector<Type*>* keywordsTypes, vector<string>* parametersNames, vector<Type*>* parametersTypes, bool* isClassmethod, Statement_node** bodyStart)
{
	*returnType = MethodType->toDataType(); // ��� ������������� ��������
	// ��� ������
	if (type == CLASS_METHOD_DECLARATION_TYPE)
		*isClassmethod = true;
	else if (type == INSTANCE_METHOD_DECLARATION_TYPE)
		*isClassmethod = false;
	string methodName = string(MethodSelector->MethodName); // ��� ������
	MethodSelector->getParams(keywordsNames, keywordsTypes, parametersNames, parametersTypes); // ���������
	if (MethodBody != NULL)
		*bodyStart = MethodBody->First; // ������ ���� ������
	else
		*bodyStart = NULL;
	return methodName;
}


// ---------- Type_node ----------
Type* Type_node::toDataType()
{
	if (type == CLASS_NAME_TYPE)
	{
		string className = ClassesTable::getFullClassName(string(ClassName));
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
	if (KeywordDeclaration != NULL) { //���������� ������� ���������
		string firstKeywordName = string(KeywordDeclaration->KeywordName); // 
		Type* firstKeywordType = KeywordDeclaration->KeywordType->toDataType();
		keywordsNames->push_back(firstKeywordName);
		keywordsTypes->push_back(firstKeywordType);
	}

	if (KeywordSelector != NULL) { //���������� ��������� ����������
		vector<Keyword_declaration_node*>* keywordsList = KeywordSelector->getElements(); //������ keword
		for (auto it = keywordsList->cbegin(); it < keywordsList->cend(); it++)
		{
			Keyword_declaration_node* keyword = *it; //�������� �����
			string name = string(keyword->KeywordName); //���
			Type* type = keyword->KeywordType->toDataType(); //���
			if (std::find(keywordsNames->begin(), keywordsNames->end(), name) != keywordsNames->end()) { //��������������� ���������
				string msg = "Parameter '" + name + "' redifinition";
				throw new exception(msg.c_str());
			}
			keywordsNames->push_back(name); //���������� �����
			keywordsTypes->push_back(type); //���������� ����
		}
	}

	if (ParameterListNode != NULL) { //���������� ����������
		vector<Parameter_declaration_node*>* parametersList = ParameterListNode->getElements(); //������ ����������
		for (auto it = parametersList->cbegin(); it < parametersList->cend(); it++)
		{
			Parameter_declaration_node* parameter = *it; //��������
			string name = string(parameter->name); //���
			Type* type = parameter->type->toDataType(); //���
			if (std::find(parametersNames->begin(), parametersNames->end(), name) != parametersNames->end() || std::find(keywordsNames->begin(), keywordsNames->end(), name) != keywordsNames->end()) { //��������������� ���������
				string msg = "Parameter '" + name + "' redifinition";
				throw new exception(msg.c_str());
			}
			parametersNames->push_back(name); //���������� �����
			parametersTypes->push_back(type); //���������� ����
		}
	}
}

// ---------- Statement_node ----------
void Statement_node::findLocalVariables(vector<string>* localVariablesNames, vector<Type*>* localVariablesTypes)
{
	vector<Init_declarator_node*>* declarators = NULL; //�����������
	Type_node* typeNode = NULL;
	// ��������� ������������
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
		getTypesFromInitDeclaratorType(declarators, typeNode, localVariablesNames, localVariablesTypes); // ��������� ����������



	if (Next != NULL)
	{
		Next->findLocalVariables(localVariablesNames, localVariablesTypes);
	}
}

void getTypesFromInitDeclaratorType(vector<Init_declarator_node*>* declarators, Type_node* typeNode, vector<string>* varsNames, vector<Type*>* varsTypes)
{
	for (auto it = declarators->begin(); it < declarators->end(); it++)
	{
		string name = string((*it)->Declarator); //���
		type_type type = typeNode->type; //���
		Expression_node* arrSize = (*it)->ArraySize; //������ �������
		Expression_node* initializer = (*it)->expression; // �������������
		Expression_list_node* initializerList = (*it)->InitializerList; // ������������� �������
		if (type == CLASS_NAME_TYPE)
		{
			string className = ClassesTable::getFullClassName(string(typeNode->ClassName));
			if (arrSize != NULL || initializerList != NULL)
			{ // ������ ���� ������
				int arraySize;
				if (arrSize != NULL)
				{
					arraySize = arrSize->num->Int;
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
			{ //��� ������
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
			{ // ������ ������������ ����
				int arraySize;
				if (arrSize != NULL)
				{
					arraySize = arrSize->num->Int;
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
			{ //����������� ���
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

void Statement_node::fillFieldRefs(ConstantsTable *constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement)
{
	if (type == EMPTY_STATEMENT_TYPE) {

	}
	else if (type == SIMPLE_STATEMENT_TYPE) {
		Expression->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
	else if (type == RETURN_STATEMENT_TYPE) {
		Expression->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
	else if (type == IF_STATEMENT_TYPE) {
		If_statement_node *cur = (If_statement_node*)this;
		cur->Condition->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
		cur->TrueBranch->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
		if (cur->FalseBranch != NULL)
			cur->FalseBranch->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
	else if (type == WHILE_STATEMENT_TYPE) {
		While_statement_node *cur = (While_statement_node*)this;
		cur->LoopCondition->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
		if (cur->LoopBody != NULL)
			cur->LoopBody->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
	else if (type == DO_WHILE_STATEMENT_TYPE) {
		Do_while_statement_node *cur = (Do_while_statement_node*)this;
		cur->LoopCondition->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
		if (cur->LoopBody != NULL)
			cur->LoopBody->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
	else if (type == FOR_STATEMENT_TYPE) {
		For_statement_node *cur = (For_statement_node*)this;
		if (cur->InitExpression != NULL)
			cur->InitExpression->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
		if (cur->ConditionExpression != NULL)
			cur->ConditionExpression->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
		if (cur->LoopExpression != NULL)
			cur->LoopExpression->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
		if (cur->InitList != NULL)
			cur->InitList->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
		if (cur->LoopBody != NULL)
			cur->LoopBody->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
	else if (type == COMPOUND_STATEMENT_TYPE) {
		Statement_list_node *cur = (Statement_list_node*)this;
		if (cur->First != NULL) {
			Statement_node *elem = cur->First;
			while (elem != NULL) {
				elem->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
				elem = elem->Next;
			}
		}
	}
	else if (type == DECLARATION_STATEMENT_TYPE) {
		Declaration_node *cur = (Declaration_node*)this;
		if (cur->init_declarator_list != NULL)
			cur->init_declarator_list->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
}

void Statement_node::fillMethodRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement, bool isInInstanceMethod)
{
	if (type == EMPTY_STATEMENT_TYPE) {

	}
	else if (type == SIMPLE_STATEMENT_TYPE) {
		Expression->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	}
	else if (type == RETURN_STATEMENT_TYPE) {
		Expression->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	}
	else if (type == IF_STATEMENT_TYPE) {
		If_statement_node* cur = (If_statement_node*)this;
		cur->Condition->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
		cur->TrueBranch->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
		if (cur->FalseBranch != NULL)
			cur->FalseBranch->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	}
	else if (type == WHILE_STATEMENT_TYPE) {
		While_statement_node* cur = (While_statement_node*)this;
		cur->LoopCondition->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
		if (cur->LoopBody != NULL)
			cur->LoopBody->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	}
	else if (type == DO_WHILE_STATEMENT_TYPE) {
		Do_while_statement_node* cur = (Do_while_statement_node*)this;
		cur->LoopCondition->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
		if (cur->LoopBody != NULL)
			cur->LoopBody->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	}
	else if (type == FOR_STATEMENT_TYPE) {
		For_statement_node* cur = (For_statement_node*)this;
		if (cur->InitExpression != NULL)
			cur->InitExpression->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
		if (cur->ConditionExpression != NULL)
			cur->ConditionExpression->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
		if (cur->LoopExpression != NULL)
			cur->LoopExpression->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
		if (cur->InitList != NULL)
			cur->InitList->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
		if (cur->LoopBody != NULL)
			cur->LoopBody->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	}
	else if (type == COMPOUND_STATEMENT_TYPE) {
		Statement_list_node* cur = (Statement_list_node*)this;
		if (cur->First != NULL) {
			Statement_node* elem = cur->First;
			while (elem != NULL) {
				elem->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
				elem = elem->Next;
			}
		}
	}
	else if (type == DECLARATION_STATEMENT_TYPE) {
		Declaration_node* cur = (Declaration_node*)this;
		if (cur->init_declarator_list != NULL)
			cur->init_declarator_list->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	}
}

void Statement_node::fillLiterals(ConstantsTable* constantTable)
{
	if (type == EMPTY_STATEMENT_TYPE) {

	}
	else if (type == SIMPLE_STATEMENT_TYPE) {
		Expression->fillLiterals(constantTable);
	}
	else if (type == RETURN_STATEMENT_TYPE) {
		Expression->fillLiterals(constantTable);
	}
	else if (type == IF_STATEMENT_TYPE) {
		If_statement_node* cur = (If_statement_node*)this;
		cur->Condition->fillLiterals(constantTable);
		cur->TrueBranch->fillLiterals(constantTable);
		if (cur->FalseBranch != NULL) {
			cur->FalseBranch->fillLiterals(constantTable);
		}
	}
	else if (type == WHILE_STATEMENT_TYPE) {
		While_statement_node* cur = (While_statement_node*)this;
		cur->LoopCondition->fillLiterals(constantTable);
		if (cur->LoopBody != NULL) {
			cur->LoopBody->fillLiterals(constantTable);
		}
	}
	else if (type == DO_WHILE_STATEMENT_TYPE) {
		Do_while_statement_node* cur = (Do_while_statement_node*)this;
		cur->LoopCondition->fillLiterals(constantTable);
		if (cur->LoopBody != NULL) {
			cur->LoopBody->fillLiterals(constantTable);
		}
	}
	else if (type == FOR_STATEMENT_TYPE) {
		For_statement_node* cur = (For_statement_node*)this;
		if (cur->InitExpression != NULL)
			cur->InitExpression->fillLiterals(constantTable);
		if (cur->ConditionExpression != NULL)
			cur->ConditionExpression->fillLiterals(constantTable);
		if (cur->LoopExpression != NULL)
			cur->LoopExpression->fillLiterals(constantTable);
		if (cur->InitList != NULL)
			cur->InitList->fillLiterals(constantTable);
		if (cur->LoopBody != NULL)
			cur->LoopBody->fillLiterals(constantTable);
	}
	else if (type == COMPOUND_STATEMENT_TYPE) {
		Statement_list_node* cur = (Statement_list_node*)this;
		if (cur->First != NULL) {
			Statement_node* elem = cur->First;
			while (elem != NULL) {
				elem->fillLiterals(constantTable);
				elem = elem->Next;
			}
		}
	}
	else if (type == DECLARATION_STATEMENT_TYPE) {
		Declaration_node* cur = (Declaration_node*)this;
		if (cur->init_declarator_list != NULL)
			cur->init_declarator_list->fillLiterals(constantTable);
	}
}

// ---------- Function_declaration ----------
string Function_node::getFunction(Type** returnType, Statement_node** bodyStart)
{
	*returnType = ReturnType->toDataType(); //��� ������������� ��������
	string functionName = string(Name); //��� �������
	*bodyStart = statement->First; // ������ ���� �������
	return functionName;
}

// ---------- Expression_node ----------
void Expression_node::fillFieldRefs(ConstantsTable* constantTable, LocalVariablesTable *localVariablesTable, ClassesTableElement *classTableElement)
{
	if (type == IDENTIFIER_EXPRESSION_TYPE) {
		if (!localVariablesTable->isContains(name) && !classTableElement->isContainsField(name)) {
			string msg = "Variable '" + string(name) + "' not declarated";
			throw new exception(msg.c_str());
		}
		else if (!localVariablesTable->isContains(name) && classTableElement->isContainsField(name)) {
			string descriptor; //������ �����������
			string className; //��� ������
			classTableElement->getFieldForRef(name, &descriptor, &className); //��������� ����������� � ����� ������
			//������������ fieldRef
			constantTable->findOrAddFieldRefConstant(className, name, descriptor);
		}
	}
	else if (type == SELF_EXPRESSION_TYPE) {

	}
	else if (type == SUPER_EXPRESSION_TYPE) {
		string msg = "Can not call field from super object";
		throw new std::exception(msg.c_str());
	}
	if (type == ARROW_EXPRESSION_TYPE) {
		string objName;
		// ��������� ����� ������� � �������� ��� ������������
		if (Left->type == IDENTIFIER_EXPRESSION_TYPE)
			objName = Left->name; //��� �������
		else if (Left->type == SELF_EXPRESSION_TYPE)
			objName = "self";
		else if (Left->type == SUPER_EXPRESSION_TYPE) {
			string msg = "Can not call field from super object";
			throw new std::exception(msg.c_str());
		}
		else {
			string msg = "Invalid expression type in function call.";
			throw new std::exception(msg.c_str());
		}


		if (name == NULL) {
			string msg = "Field call not to field";
			throw new std::exception(msg.c_str());
		}


		string fieldName = name; //��� ����
		if (!localVariablesTable->isContains(objName) && !classTableElement->isContainsField(objName)) { //�� �������� ��������� ���������� ��� ����� ������
			string msg = "Variable '" + string(objName) + "' not declarated";
			throw new exception(msg.c_str());
		}
		else if (classTableElement->isContainsField(objName) && !localVariablesTable->isContains(objName)) {
			FieldsTableElement* field = classTableElement->Fields->items[objName]; //��������� ����������
			if (field->type->DataType != CLASS_NAME_TYPE) { // �� �������� ����������� ������
				string msg = "Variable '" + objName + "' is not instance of object.";
				throw new std::exception(msg.c_str());
			}
			string className = field->type->ClassName; //��� ������ ��������� ����������
			ClassesTableElement* classElem = ClassesTable::items[className];
			if (!classElem->isContainsField(fieldName) || classElem->Fields->items[fieldName]->IsInstance == false) { //���� �� ���������� � ������ �������
				string msg = "Class '" + className + "' don't contains field '" + fieldName;
				throw new std::exception(msg.c_str());
			}
			if (classElem != classTableElement && classTableElement->getClassName() != "rtl/Program" && !classTableElement->isHaveOneOfSuperclass(className)) {
				// ���� �������� protected � �� ��������� ������� ��� ����������� ������������� protected
				string msg = "Component '" + fieldName + "' only protected";
				throw new std::exception(msg.c_str());
			}


			string descriptor; // ����������
			string fieldClassName;  // ��� ������ ����
			classElem->getFieldForRef(fieldName, &descriptor, &fieldClassName); // ��������� ������ ��� field ref
			//������������ fieldRef
			constantTable->findOrAddFieldRefConstant(fieldClassName, fieldName, descriptor);
		}
		else { //�������� ��������� ����������
			LocalVariablesTableElement* local = localVariablesTable->items[objName]; //��������� ����������
			if (local->type->DataType != CLASS_NAME_TYPE) { // �� �������� ����������� ������
				string msg = "Variable '" + objName + "' is not instance of object.";
				throw new std::exception(msg.c_str());
			}
			string className = local->type->ClassName; //��� ������ ��������� ����������
			ClassesTableElement* classElem = ClassesTable::items[className];
			if (!classElem->isContainsField(fieldName) || classElem->Fields->items[fieldName]->IsInstance == false) { //���� �� ���������� � ������ �������
				string msg = "Class '" + className + "' don't contains field '" + fieldName;
				throw new std::exception(msg.c_str());
			}
			if (classElem != classTableElement && classTableElement->getClassName() != "rtl/Program" && !classTableElement->isHaveOneOfSuperclass(className)) {
				// ���� �������� protected � �� ��������� ������� ��� ����������� ������������� protected
				string msg = "Component '" + fieldName + "' only protected";
				throw new std::exception(msg.c_str());
			}


			string descriptor; // ����������
			string fieldClassName;  // ��� ������ ����
			classElem->getFieldForRef(fieldName, &descriptor, &fieldClassName); // ��������� ������ ��� field ref
			//������������ fieldRef
			constantTable->findOrAddFieldRefConstant(fieldClassName, fieldName, descriptor);
		}
		
	}
	if (Left != NULL) {
		Left->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
	if (Right != NULL) {
		Right->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
	if (Receiver != NULL) {
		Receiver->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
	if (Arguments != NULL) {
		Arguments->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
	if (ArgumentsList != NULL) {
		ArgumentsList->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
}

void Expression_node::fillMethodRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement, bool isInInstanceMethod)
{
	if (type == MESSAGE_EXPRESSION_EXPRESSION_TYPE) { //����� ������
		string receiverName;
		bool isObject;
		bool isReceiver = false;
		if (Receiver->type == MESSAGE_EXPRESSION_RECEIVER_TYPE) {// ���� ������� ����� ��� message_selector, �� �������� �� �������� ���������
			Type *returnType;
			Receiver->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod, &returnType);
			if (returnType->DataType != CLASS_NAME_TYPE) {
				string msg = "Receiver is not an object";
				throw new std::exception(msg.c_str());
			}
			isObject = true;
			isReceiver = true;
			receiverName = returnType->ClassName;
		}
		else {
			isObject = Receiver->getName(&receiverName); // �������� ��� �������/������ � ��� ���
			//�������������� ��� self � super
			if (receiverName == "self") {
				if (!isInInstanceMethod)
					receiverName = classTableElement->getClassName();
				isObject = isInInstanceMethod;
			}
			if (receiverName == "super") {
				if (!isInInstanceMethod)
					receiverName = classTableElement->getSuperClassName();
				isObject = isInInstanceMethod;
			}
		}


		// �� message_selector �������� ��� ������.
		string methodName = Arguments->MethodName; // ��� ������
		string methodNameWithType; //��� ������ � dynamic ��� static
		
		//TODO: �������� �������������� ���� ����� ������
		if (isObject)
			methodNameWithType = methodName + "Dynamic";
		else
			methodNameWithType = methodName + "Static";


		// ��������� ������� ������ � ������
		if (isReceiver) {
			bool isContainsMethod = ClassesTable::items[receiverName]->isContainsMethod(methodNameWithType);
			if (!isContainsMethod) {
				string msg = "Class '" + receiverName + "' don't contains method '-" + methodName + "'";
				throw new std::exception(msg.c_str());
			}
		}
		else {
			if (isObject) {
				if (!localVariablesTable->isContains(receiverName) && !classTableElement->isContainsField(receiverName) && receiverName != "super") {
					string msg = "Using undeclarated variable '" + receiverName + "'";
					throw new std::exception(msg.c_str());
				}
				else if (!localVariablesTable->isContains(receiverName) && classTableElement->isContainsField(receiverName) && receiverName != "super") { //�������� ����� ������
					FieldsTableElement* field = classTableElement->Fields->items[receiverName];
					if (field->type->DataType != CLASS_NAME_TYPE) {
						string msg = "Variable '" + receiverName + "' is not an object";
						throw new std::exception(msg.c_str());
					}
					string className = field->type->ClassName;
					bool isContainsMethod = ClassesTable::items[className]->isContainsMethod(methodNameWithType);
					if (!isContainsMethod) {
						string msg = "Class '" + className + "' don't contains method '-" + methodName + "'";
						throw new std::exception(msg.c_str());
					}
				}
				else if (receiverName != "super") { //�������� ��������� ����������
					LocalVariablesTableElement* local = localVariablesTable->items[receiverName];
					if (local->type->DataType != CLASS_NAME_TYPE) {
						string msg = "Variable '" + receiverName + "' is not an object";
						throw new std::exception(msg.c_str());
					}
					string className = local->type->ClassName;
					bool isContainsMethod = ClassesTable::items[className]->isContainsMethod(methodNameWithType);
					if (!isContainsMethod) {
						string msg = "Class '" + receiverName + "' don't contains method '-" + methodName + "'";
						throw new std::exception(msg.c_str());
					}
				}
				else { //Super
					string className = classTableElement->getSuperClassName();
					bool isContainsMethod = ClassesTable::items[className]->isContainsMethod(methodNameWithType);
					if (!isContainsMethod) {
						string msg = "Class '" + className + "' don't contains method '-" + methodName + "'";
						throw new std::exception(msg.c_str());
					}
				}
			}
			else {
				string fullClassName = ClassesTable::getFullClassName(receiverName); //�������� ������ ��� ������ //TODO: ��������, ����� ����� ������, ���� ��� �������������� ������ ����� ���������� ����� ��� ����� �������
				bool isContainsMethod = ClassesTable::items[fullClassName]->isContainsMethod(methodNameWithType); //��������� ������� ������
				if (!isContainsMethod) {
					string msg = "Class '" + receiverName + "' don't contains method '+" + methodName + "'";
					throw new std::exception(msg.c_str());
				}
			}
		}

		// �������� methodRef
		if (isReceiver) {
			ClassesTableElement* element = ClassesTable::items[receiverName];
			// �������� ���������� ��� �������� ��������� ���� method ref
			string descriptor;
			string className;
			element->getMethodForRef(methodNameWithType, &descriptor, &className);
			// �������� ��������� method ref
			constantTable->findOrAddMethodRefConstant(className, methodName, descriptor);
		}
		else {
			if (isObject) {
				string className;
				if (receiverName == "super") {//Super
					className = classTableElement->getClassName();
				}
				else if (!localVariablesTable->isContains(receiverName) && classTableElement->isContainsField(receiverName)) { //�������� ����� ������
					FieldsTableElement* field = classTableElement->Fields->items[receiverName];
					className = field->type->ClassName;
				}
				else { //�������� ��������� ����������
					LocalVariablesTableElement* local = localVariablesTable->items[receiverName];
					className = local->type->ClassName;
				}
				ClassesTableElement* element = ClassesTable::items[className];
				// �������� ���������� ��� �������� ��������� ���� method ref
				string descriptor;
				element->getMethodForRef(methodNameWithType, &descriptor, &className);
				// �������� ��������� method ref
				constantTable->findOrAddMethodRefConstant(className, methodName, descriptor);
			}
			else {
				string fullClassName = ClassesTable::getFullClassName(receiverName); //�������� ������ ��� ������ //TODO: ��������, ����� ����� ������, ���� ��� �������������� ������ ����� ���������� ����� ��� ����� �������
				ClassesTableElement* element = ClassesTable::items[fullClassName];
				// �������� ���������� ��� �������� ��������� ���� method ref
				string descriptor;
				string className;
				element->getMethodForRef(methodNameWithType, &descriptor, &className);
				// �������� ��������� method ref
				constantTable->findOrAddMethodRefConstant(className, methodName, descriptor);
			}
		}

		// �������� ������ �� �������� ��������� message selector
		Arguments->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	}
	// ������� �� �������� ���������
	if (Left != NULL) {
		Left->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	}
	if (Right != NULL) {
		Right->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	}
	if (ArgumentsList != NULL) {
		ArgumentsList->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	}
}

void Expression_node::fillLiterals(ConstantsTable* constantTable)
{
	if (type == LITERAL_EXPRESSION_TYPE) {
		literal->fillLiterals(constantTable);
	}
	else if (type == NUMERIIC_CONSTANT_EXPRESSION_TYPE) {
		num->fillLiterals(constantTable);
	}

	if (Left != NULL)
		Left->fillLiterals(constantTable);
	if (Right != NULL)
		Right->fillLiterals(constantTable);
	if (Receiver != NULL)
		Receiver->fillLiterals(constantTable);
	if (Arguments != NULL)
		Arguments->fillLiterals(constantTable);
	if (ArgumentsList != NULL)
		ArgumentsList->fillLiterals(constantTable);

}

// ---------- Receiver_node ----------
void Receiver_node::fillFieldRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement)
{
	if (type == SELF_RECEIVER_TYPE) {
		LocalVariablesTableElement* self = localVariablesTable->items["self"];
		string descriptor = self->type->getDescriptor(); //������ �����������
		string className = self->type->ClassName; //��� ������
		//������������ fieldRef
		constantTable->findOrAddFieldRefConstant(className, "self", descriptor);
	}
	else if (type == OBJECT_NAME_RECEIVER_TYPE) {
		if (classTableElement->isContainsField(name)) {
			string descriptor; //����������
			string className; //��� ������
			classTableElement->getFieldForRef(name, &descriptor, &className); //��������� ������ ���� ��� �������� fieldRef
			constantTable->findOrAddFieldRefConstant(className, name, descriptor); //������������ fieldRef
		}
	}
	else if (type == MESSAGE_EXPRESSION_RECEIVER_TYPE) {
		Receiver->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
		if  (Arguments != NULL)
			Arguments->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
}

bool Receiver_node::getName(string* Name)
{
	if (type == SUPER_RECEIVER_TYPE) {
		*Name = "super";
		return true;
	}
	else if (type == SELF_RECEIVER_TYPE) {
		*Name = "self";
		return true;
	}
	else if (type == OBJECT_NAME_RECEIVER_TYPE) {
		*Name = name;
		return true;
	}
	else if (type == CLASS_NAME_RECEIVER_TYPE) {
		*Name = name;
		return false;
	}
	else if (type == MESSAGE_EXPRESSION_RECEIVER_TYPE) {
		return true;
	}
}

void Receiver_node::fillMethodRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement, bool isInInstanceMethod, Type **returnType)
{
	if (type == MESSAGE_EXPRESSION_RECEIVER_TYPE) {
		string receiverName;
		bool isObject;
		bool isReceiver = false;
		if (Receiver->type == MESSAGE_EXPRESSION_RECEIVER_TYPE) {// ���� ������� ����� ��� message_selector, �� �������� �� �������� ���������
			Type* returnType;
			Receiver->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod, &returnType);
			if (returnType->DataType != CLASS_NAME_TYPE) {
				string msg = "Receiver is not an object";
				throw new std::exception(msg.c_str());
			}
			isObject = true;
			isReceiver = true;
			receiverName = returnType->ClassName;
		}
		else {
			isObject = Receiver->getName(&receiverName); // �������� ��� �������/������ � ��� ���
			//�������������� ��� self � super
			if (receiverName == "self") {
				if (!isInInstanceMethod)
					receiverName = classTableElement->getClassName();
				isObject = isInInstanceMethod;
			}
			if (receiverName == "super") {
				if (!isInInstanceMethod)
					receiverName = classTableElement->getSuperClassName();
				isObject = isInInstanceMethod;
			}
		}


		// �� message_selector �������� ��� ������.
		string methodName = Arguments->MethodName; // ��� ������
		string methodNameWithType; //��� ������ � dynamic ��� static

		//TODO: �������� �������������� ���� ����� ������
		if (isObject)
			methodNameWithType = methodName + "Dynamic";
		else
			methodNameWithType = methodName + "Static";


		// ��������� ������� ������ � ������
		if (isReceiver) {
			bool isContainsMethod = ClassesTable::items[receiverName]->isContainsMethod(methodNameWithType);
			if (!isContainsMethod) {
				string msg = "Class '" + receiverName + "' don't contains method '-" + methodName + "'";
				throw new std::exception(msg.c_str());
			}
		}
		else {
			if (isObject) {
				if (!localVariablesTable->isContains(receiverName) && !classTableElement->isContainsField(receiverName) && receiverName != "super") {
					string msg = "Using undeclarated variable '" + receiverName + "'";
					throw new std::exception(msg.c_str());
				}
				else if (!localVariablesTable->isContains(receiverName) && !classTableElement->isContainsField(receiverName) && receiverName != "super") { //�������� ����� ������
					FieldsTableElement* field = classTableElement->Fields->items[receiverName];
					if (field->type->DataType != CLASS_NAME_TYPE) {
						string msg = "Variable '" + receiverName + "' is not an object";
						throw new std::exception(msg.c_str());
					}
					string className = field->type->ClassName;
					bool isContainsMethod = ClassesTable::items[className]->isContainsMethod(methodNameWithType);
					if (!isContainsMethod) {
						string msg = "Class '" + receiverName + "' don't contains method '-" + methodName + "'";
						throw new std::exception(msg.c_str());
					}
				}
				else if (receiverName != "super") { //�������� ��������� ����������
					LocalVariablesTableElement* local = localVariablesTable->items[receiverName];
					if (local->type->DataType != CLASS_NAME_TYPE) {
						string msg = "Variable '" + receiverName + "' is not an object";
						throw new std::exception(msg.c_str());
					}
					string className = local->type->ClassName;
					bool isContainsMethod = ClassesTable::items[className]->isContainsMethod(methodNameWithType);
					if (!isContainsMethod) {
						string msg = "Class '" + receiverName + "' don't contains method '-" + methodName + "'";
						throw new std::exception(msg.c_str());
					}
				}
				else { //Super
					string className = classTableElement->getSuperClassName();
					bool isContainsMethod = ClassesTable::items[className]->isContainsMethod(methodNameWithType);
					if (!isContainsMethod) {
						string msg = "Class '" + className + "' don't contains method '-" + methodName + "'";
						throw new std::exception(msg.c_str());
					}
				}
			}
			else {
				string fullClassName = ClassesTable::getFullClassName(receiverName); //�������� ������ ��� ������ //TODO: ��������, ����� ����� ������, ���� ��� �������������� ������ ����� ���������� ����� ��� ����� �������
				bool isContainsMethod = ClassesTable::items[fullClassName]->isContainsMethod(methodNameWithType); //��������� ������� ������
				if (!isContainsMethod) {
					string msg = "Class '" + receiverName + "' don't contains method '+" + methodName + "'";
					throw new std::exception(msg.c_str());
				}
			}
		}

		// �������� methodRef
		if (isReceiver) {
			ClassesTableElement* element = ClassesTable::items[receiverName];
			// �������� ���������� ��� �������� ��������� ���� method ref
			string descriptor;
			string className;
			element->getMethodForRef(methodNameWithType, &descriptor, &className);
			// �������� ��������� method ref
			constantTable->findOrAddMethodRefConstant(className, methodName, descriptor);
			*returnType = ClassesTable::items[className]->Methods->items[methodNameWithType]->ReturnType;
		}
		else {
			if (isObject) {
				string className;
				if (receiverName == "super") {//Super
					className = classTableElement->getClassName();
				}
				else if (!localVariablesTable->isContains(receiverName) && classTableElement->isContainsField(receiverName)) { //�������� ����� ������
					FieldsTableElement* field = classTableElement->Fields->items[receiverName];
					className = field->type->ClassName;
				}
				else { //�������� ��������� ����������
					LocalVariablesTableElement* local = localVariablesTable->items[receiverName];
					className = local->type->ClassName;
				}
				ClassesTableElement* element = ClassesTable::items[className];
				// �������� ���������� ��� �������� ��������� ���� method ref
				string descriptor;
				element->getMethodForRef(methodNameWithType, &descriptor, &className);
				// �������� ��������� method ref
				constantTable->findOrAddMethodRefConstant(className, methodName, descriptor);

				*returnType = ClassesTable::items[className]->Methods->items[methodNameWithType]->ReturnType;
			}
			else {
				string fullClassName = ClassesTable::getFullClassName(receiverName); //�������� ������ ��� ������ //TODO: ��������, ����� ����� ������, ���� ��� �������������� ������ ����� ���������� ����� ��� ����� �������
				ClassesTableElement* element = ClassesTable::items[fullClassName];
				// �������� ���������� ��� �������� ��������� ���� method ref
				string descriptor;
				string className;
				element->getMethodForRef(methodNameWithType, &descriptor, &className);
				// �������� ��������� method ref
				constantTable->findOrAddMethodRefConstant(className, methodName, descriptor);

				*returnType = ClassesTable::items[className]->Methods->items[methodNameWithType]->ReturnType;
			}
		}

		// �������� ������ �� �������� ��������� message selector
		Arguments->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	}
}

void Receiver_node::fillLiterals(ConstantsTable* constantTable)
{
	if (Receiver != NULL)
		Receiver->fillLiterals(constantTable);
	if (Arguments != NULL)
		Arguments->fillLiterals(constantTable);
}

// ---------- Message_selector_node ----------
void Message_selector_node::fillFieldRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement)
{
	if (FirstArgument != NULL) {
		FirstArgument->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	}
	if (Arguments != NULL)
		Arguments->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	if (ExprArguments != NULL)
		ExprArguments->fillFieldRefs(constantTable, localVariablesTable, classTableElement);

}

void Message_selector_node::fillMethodRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement, bool isInInstanceMethod)
{
	if (FirstArgument != NULL)
		FirstArgument->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	if (Arguments != NULL)
		Arguments->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	if (ExprArguments != NULL)
		ExprArguments->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
}

void Message_selector_node::fillLiterals(ConstantsTable* constantTable)
{
	if (FirstArgument != NULL)
		FirstArgument->fillLiterals(constantTable);
	if (Arguments != NULL)
		Arguments->fillLiterals(constantTable);
	if (ExprArguments != NULL)
		ExprArguments->fillLiterals(constantTable);
}

// ---------- Keyword_argument_list_node ----------
void Keyword_argument_list_node::fillFieldRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement)
{
	Keyword_argument_node* arg = First;
	while (arg != NULL)
	{
		arg->expression->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
		arg = arg->Next;
	}
}

void Keyword_argument_list_node::fillMethodRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement, bool isInstanceMethod)
{
	Keyword_argument_node* arg = First;
	while (arg != NULL)
	{
		arg->expression->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInstanceMethod);
		arg = arg->Next;
	}
}

void Keyword_argument_list_node::fillLiterals(ConstantsTable* constantTable)
{
	Keyword_argument_node* arg = First;
	while (arg != NULL)
	{
		arg->expression->fillLiterals(constantTable);
		arg = arg->Next;
	}
}

// ---------- Expression_list_node ----------

void Expression_list_node::fillFieldRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement)
{
	Expression_node* cur = First;
	while (cur != NULL)
	{
		cur->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
		cur = cur->Next;
	}
}

void Expression_list_node::fillMethodRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement, bool isInInstanceMethod)
{
	Expression_node* cur = First;
	while (cur != NULL)
	{
		cur->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
		cur = cur->Next;
	}
}

void Expression_list_node::fillLiterals(ConstantsTable* constantTable)
{
	Expression_node* cur = First;
	while (cur != NULL)
	{
		cur->fillLiterals(constantTable);
		cur = cur->Next;
	}
}

// ---------- Init_declarator_list_node ----------
void Init_declarator_list_node::fillFieldRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement)
{
	Init_declarator_node* declarator = First;
	while (declarator != NULL)
	{
		declarator->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
		declarator = declarator->Next;
	}
}

void Init_declarator_list_node::fillMethodRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement, bool isInInstanceMethod)
{
	Init_declarator_node* declarator = First;
	while (declarator != NULL)
	{
		declarator->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
		declarator = declarator->Next;
	}
}

void Init_declarator_list_node::fillLiterals(ConstantsTable* constantTable)
{
	Init_declarator_node* declarator = First;
	while (declarator != NULL)
	{
		declarator->fillLiterals(constantTable);
		declarator = declarator->Next;
	}
}

// ---------- Init_declarator_node ---------- 
void Init_declarator_node::fillFieldRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement)
{
	if (expression != NULL)
		expression->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	if (ArraySize != NULL)
		ArraySize->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
	if (InitializerList != NULL)
		InitializerList->fillFieldRefs(constantTable, localVariablesTable, classTableElement);
}

void Init_declarator_node::fillMethodRefs(ConstantsTable* constantTable, LocalVariablesTable* localVariablesTable, ClassesTableElement* classTableElement, bool isInInstanceMethod)
{
	if (expression != NULL)
		expression->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	if (ArraySize != NULL)
		ArraySize->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);
	if (InitializerList != NULL)
		InitializerList->fillMethodRefs(constantTable, localVariablesTable, classTableElement, isInInstanceMethod);

}

void Init_declarator_node::fillLiterals(ConstantsTable* constantTable)
{
	if (expression != NULL)
		expression->fillLiterals(constantTable);
	if (ArraySize != NULL)
		ArraySize->fillLiterals(constantTable);
	if (InitializerList != NULL)
		InitializerList->fillLiterals(constantTable);
}



// ---------- Numeric_constant ----------
void Numeric_constant_node::fillLiterals(ConstantsTable* constantTable)
{
	if (Int > 32767 || Int < -32768) {
		constantTable->findOrAddConstant(Integer, Int);
	}
}

// ---------- literal ----------
void Literal_node::fillLiterals(ConstantsTable* constantTable)
{
	if (type == STRING_CONSTANT_TYPE || type == NSSTRING_CONSTANT_TYPE) {
		int utfIndex = constantTable->findOrAddConstant(UTF8, value);
		constantTable->findOrAddConstant(String, 0, utfIndex);
	}
}

