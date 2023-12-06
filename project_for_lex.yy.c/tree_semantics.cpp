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
							element->Fields->addField(element->ConstantTable, it->first, it->second->getDescriptor(), true, it->second);
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
					// Добавление instance variables
					map<string, Type*> instanceVariables = curInterface->Body->getInstanceVariables();
					for (auto it = instanceVariables.begin(); it != instanceVariables.end(); it++)
					{
						element->Fields->addField(element->ConstantTable, it->first, it->second->getDescriptor(), true, it->second);
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
