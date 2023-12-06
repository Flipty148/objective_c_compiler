#include "tables.h"
// ------------------------------ ����� ������ -------------------------------

// ---------- Function_and_class_list_node ----------

void Function_and_class_list_node::fillTables()
{
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
                ClassesTable::addClass(className, superclassName, true); // ���������� ������ � �������
            }
            else if (cur->type == INTERFACE_CLASS_BLOCK_TYPE)
            { // ���������
                Class_interface_node* curInterface = (Class_interface_node*)cur;
                string className = curInterface->ClassName; // ��� ������
                string superclassName = curInterface->SuperclassName; // ��� �����������
                ClassesTableElement* element = ClassesTable::addClass(className, &superclassName, false); // ���������� ������ � �������

				// ���������� instance variables
				map<string, Type*> instanceVariables = curInterface->Body->getInstanceVariables();
				for (auto it = instanceVariables.begin(); it != instanceVariables.end(); it++)
				{
                    element->Fields->addField(element->ConstantTable, it->first, it->second->getDescriptor(), true, it->second);
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
    vector<string> names; //������ ���� �����
    vector<Declarator_node*> variablesDeclarators = *DeclaratorList->Declarators; //������ ������������
    for (auto it = variablesDeclarators.begin(); it != variablesDeclarators.end(); it++)
    {
        names.push_back((*it)->Identifier); //���������� ����� ����������
        type_type type = this->type->type; //��������� datatype
        Expression_node* arrSize = (*it)->Expression; //������ �������
        if (type == CLASS_NAME_TYPE)
        {
			string className = string(this->type->ClassName); //��� ������
			if (arrSize != NULL)
			{ // ��� ������ � ������
				Type* curType = new Type(type, className, arrSize->constant.num->number.Int);
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
				Type* curType = new Type(type, arrSize->constant.num->number.Int);
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
