#include "tables.h"
#include <iostream>
using namespace std;

// -------------------- ConstantsTableElement --------------------

ConstantsTableElement::ConstantsTableElement(int id, constantType type, string utf8string)
{
	Id = id;
	Type = type;
	Utf8String = utf8string;
}


ConstantsTableElement::ConstantsTableElement(int id, constantType type, int number, int firstRef, int secondRef)
{
	Id = id;
	Type = type;
	Number = number;
	FirstRef = firstRef;
	SecondRef = secondRef;
}

// -------------------- ConstantsTable --------------------

ConstantsTable::ConstantsTable()
{
	items[maxId] = new ConstantsTableElement(maxId, UTF8, "Code");
	maxId++;
}

int ConstantsTable::findOrAddConstant(constantType type, string utf8string)
{
	int res = findConstant(type, utf8string);
	if (res == -1)
	{
		res = maxId++;
		items[res] = new ConstantsTableElement(res, type, utf8string);
	}
	return res;
}

int ConstantsTable::findOrAddConstant(constantType type, int number, int firstRef, int secondRef)
{
	int res = findConstant(type, NULL, number, firstRef, secondRef);
	if (res == -1)
	{
		res = maxId++;
		items[res] = new ConstantsTableElement(res, type, number, firstRef, secondRef);
	}
	return res;
}

int ConstantsTable::findConstant(constantType type, string utf8string, int number, int firstRef, int secondRef)
{
	auto iter = items.cbegin();
	while (iter != items.cend())
	{
		if (iter->second->Type == type && iter->second->Utf8String == utf8string && iter->second->Number == number && iter->second->FirstRef == firstRef && iter->second->SecondRef == secondRef)
		{
			return iter->first;
		}
		++iter;
	}
	return -1;
}

// -------------------- ClassesTableElement --------------------

ClassesTableElement::ClassesTableElement(string name, string superclassName, bool isImplementation)
{
	ConstantTable = new ConstantsTable();
	Fields = new FieldsTable();
	Methods = new MethodsTable();
	Properties = new PropertiesTable();
	Name = ConstantTable->findOrAddConstant(UTF8, name);
	SuperclassName = ConstantTable->findOrAddConstant(UTF8, superclassName);
	IsImplementation = isImplementation;
}

// -------------------- ClassesTable --------------------
void ClassesTable::addClass(string name, string superclassName, bool isImplementation)
{
	ClassesTableElement *element = new ClassesTableElement(name, superclassName, isImplementation);
	items[name] = element;
}

// ------------------- FieldsTableElement --------------------

FieldsTableElement::FieldsTableElement(int name, int descriptor, bool isInstance, Type *type)
{
	Name = name;
	Descriptor = descriptor;
	IsInstance = isInstance;
	this->type = type;
}

// -------------------- FieldsTable --------------------

void FieldsTable::addField(ConstantsTable *constantTable, string name, string descriptor, bool isInstance, Type *type)
{
	int NameId = constantTable->findOrAddConstant(UTF8, name);
	int DescriptorId = constantTable->findOrAddConstant(UTF8, descriptor);
	FieldsTableElement *field = new FieldsTableElement(NameId, DescriptorId, isInstance, type);
	items[name] = field;
}

// -------------------- MethodsTableElement --------------------

MethodsTableElement::MethodsTableElement(int name, int descriptor, bool isClassMethod, Statement_node* bodyStart, Type *returnType, vector<Type>* paramsTypes, vector<Type>* keywordsTypes)
{
	Name = name;
	Descriptor = descriptor;
	IsClassMethod = isClassMethod;
	BodyStart = bodyStart;
	ReturnType = returnType;
	ParamsTypes = paramsTypes;
	KeywordsTypes = keywordsTypes;
	LocalVariables = new LocalVariablesTable();
}

// -------------------- MethodsTable --------------------

void MethodsTable::addMethod(ConstantsTable *constantTable, string name, string descriptor, bool isClassMethod, Statement_node* bodyStart, Type *returnType, vector<Type>* paramsTypes, vector<Type>* keywordsTypes)
{
	if (items.count(name) != 0)
	{
		string msg = "Method '" + name + "' already exists";
		throw new exception(msg.c_str());
	}
	int NameId = constantTable->findOrAddConstant(UTF8, name);
	int DescriptorId = constantTable->findOrAddConstant(UTF8, descriptor);
	MethodsTableElement *method = new MethodsTableElement(NameId, DescriptorId, isClassMethod, bodyStart, returnType, paramsTypes, keywordsTypes);
	items[name] = method;
}

// -------------------- PropertiesTableElement --------------------

PropertiesTableElement::PropertiesTableElement(int name, int descriptor, bool isReadonly, Type *type)
{
	Name = name;
	Descriptor = descriptor;
	IsReadonly = isReadonly;
	this->type = type;
}

// -------------------- PropertiesTable --------------------

 void PropertiesTable::addProperty(ConstantsTable *constantTable, string name, string descriptor, bool isReadonly, Type *type)
 {
	 if (items.count(name) != 0)
	 {
		 string msg = "Property '" + name + "' already exists";
		 throw new exception(msg.c_str());
	 }
	 int NameId = constantTable->findOrAddConstant(UTF8, name);
	 int DescriptorId = constantTable->findOrAddConstant(UTF8, descriptor);
	 PropertiesTableElement *property = new PropertiesTableElement(NameId, DescriptorId, isReadonly, type);
	 items[name] = property;
 }

 // ------------------- LocalVariablesTableElement --------------------

 LocalVariablesTableElement::LocalVariablesTableElement(int id, string name, Type *type)
 {
	 Id = id;
	 Name = name;
	 this->type = type;
 }

// -------------------- LocalVariablesTable --------------------

int LocalVariablesTable::findOrAddLocalVariable(string name, Type *type)
{
	if (items.count(name) == 0)
	{
		items[name] = new LocalVariablesTableElement(maxId++, name, type);
	}
	else {
		string msg = "Variable '" + name + "' already exists";
		throw new exception(msg.c_str());
	}
	return items[name]->Id;
}

// -------------------- Type --------------------

Type::Type(type_type dataType, string className, int arrSize)
{
	DataType = dataType;
	ClassName = className;
	ArrSize = arrSize;
}

Type::Type(type_type dataType, string className)
{
	DataType = dataType;
	ClassName = className;
}

Type::Type(type_type dataType)
{
	DataType = dataType;
}

Type::Type(type_type dataType, int arrSize)
{
	DataType = dataType;
	ArrSize = arrSize;
}

// -------------------- FunctionsTableElement --------------------

FunctionsTableElement::FunctionsTableElement(int name, int descriptor, Statement_node* bodyRoot)
{
	Name = name;
	Descriptor = descriptor;
	BodyRoot = bodyRoot;
	LocalVariables = new LocalVariablesTable();
}

// -------------------- FunctionsTable --------------------

void FunctionsTable::addFunction(ConstantsTable *constantTable, string name, string descriptor, Statement_node* bodyRoot)
{
	if (items.count(name) != 0)
	{
		string msg = "Function '" + name + "' already exists";
		throw new exception(msg.c_str());
	}
	int NameId = constantTable->findOrAddConstant(UTF8, name);
	int DescriptorId = constantTable->findOrAddConstant(UTF8, descriptor);
	FunctionsTableElement *function = new FunctionsTableElement(NameId, DescriptorId, bodyRoot);
	items[name] = function;
}
