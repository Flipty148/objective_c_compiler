#include "tables.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// -------------------- ConstantsTableElement --------------------

ConstantsTableElement::ConstantsTableElement(int id, constantType type, string utf8string)
{
	Id = id;
	Type = type;
	Utf8String = new string(utf8string);
}


ConstantsTableElement::ConstantsTableElement(int id, constantType type, int number, int firstRef, int secondRef)
{
	Id = id;
	Type = type;
	Number = number;
	FirstRef = firstRef;
	SecondRef = secondRef;
}

string ConstantsTableElement::toCsvString(char separator)
{
	string res = "";
	res += to_string(Id) + separator; //Добавление ID

	// Добавление типа и значения
	switch (Type)
	{
	case constantType::UTF8:
		res += string("UTF8") + separator;
		res += *Utf8String;
		break;
	case constantType::Integer:
		res += string("Integer") + separator;
		res += to_string(Number);
		break;
	case constantType::String:
		res += string("String") + separator;
		res += to_string(FirstRef);
		break;
	case constantType::Class:
		res += string("Class") + separator;
		res += to_string(FirstRef);
		break;
	case constantType::NameAndType:
		res += string("NameAndType") + separator;
		res += to_string(FirstRef) + ", ";
		res += to_string(SecondRef);
		break;
	case constantType::FieldRef:
		res += string("FieldRef") + separator;
		res += to_string(FirstRef) + ", ";
		res += to_string(SecondRef);
		break;
	case constantType::MethodRef:
		res += string("MethodRef") + separator;
		res += to_string(FirstRef) + ", ";
		res += to_string(SecondRef);
		break;
	default:
		break;
	}

	return res;
}

// -------------------- ConstantsTable --------------------

ConstantsTable::ConstantsTable()
{
	items[maxId] = new ConstantsTableElement(maxId, UTF8, "Code");
	maxId++;
}

int ConstantsTable::findOrAddConstant(constantType type, string utf8string)
{
	int res = findConstant(type, &utf8string);
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

int ConstantsTable::findConstant(constantType type, string *utf8string, int number, int firstRef, int secondRef)
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

ConstantsTableElement* ConstantsTable::getConstant(int id)
{
	return items[id];
}

void ConstantsTable::toCsvFile(string filename, string filepath, char separator)
{
	ofstream out(filepath + filename); //Создание и открытие потока на запись в файл
	out << "ID" << separator << "Type" << separator << "Value" << endl; // Запись заголовков
	auto iter = items.cbegin();
	while (iter != items.cend()) 
	{

		string str = iter->second->toCsvString(separator); // Формирование строки
		out << str << endl; //Запись строки в файл
		++iter;
	}
	out.close(); // Закрытие потока
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
	ThisClass = ConstantTable->findOrAddConstant(Class, NULL, Name);
	Superclass = ConstantTable->findOrAddConstant(Class, NULL, SuperclassName);
	IsImplementation = isImplementation;
}

string ClassesTableElement::toCsvString(char separator)
{
	string res = "";
	res += to_string(Name) + '(' + *ConstantTable->getConstant(Name)->Utf8String + ')' + separator;
	res += to_string(SuperclassName) + '(' + *ConstantTable->getConstant(SuperclassName)->Utf8String + ')' + separator;
	res += string((IsImplementation ? "true" : "false")) + separator;
	res += to_string(ThisClass) + separator;
	res += to_string(Superclass) + separator;

	if (Fields->items.size() > 0)
		res += *ConstantTable->getConstant(Name)->Utf8String + "_FieldsTable.csv" + separator;
	else
		res += string("emptyTable") + separator;

	if (Methods->items.size() >0 )
		res += *ConstantTable->getConstant(Name)->Utf8String + "_MethodsTable.csv" + separator;
	else
		res += string("emptyTable") + separator;

	if (Properties->items.size() > 0)
		res += *ConstantTable->getConstant(Name)->Utf8String + "_PropertiesTable.csv" + separator;
	else
		res += string("emptyTable") + separator;
		
	res += *ConstantTable->getConstant(Name)->Utf8String + "_ConstantsTable.csv";
	return res;
}

void ClassesTableElement::refTablesToCsvFile(string filepath, char separator)
{
	string className = *ConstantTable->getConstant(Name)->Utf8String;
	replace(className.begin(), className.end(), '/', '_');
	if (Fields->items.size() > 0)
		Fields->toCsvFile(className, filepath, separator); //Записать таблицу полей в файл
	
	if (Methods->items.size() > 0)
		Methods->toCsvFile(className + "_MethodsTable.csv", filepath, separator); //Записать таблицу методов в файл

	if (Properties->items.size() > 0)
		Properties->toCsvFile(className + "_PropertiesTable.csv", filepath, separator); //Записать таблицу свойств в файл

	ConstantTable->toCsvFile(className + "_ConstantsTable.csv", filepath, separator); //Записать таблицу констант в файл
}

// -------------------- ClassesTable --------------------
map<string, ClassesTableElement*> ClassesTable::items;

void ClassesTable::addClass(string name, string superclassName, bool isImplementation)
{
	//TODO: check superclass name is RTL
	//TODO: Добавить проверку на наличие реализации метода при наличии интерфейса
	ClassesTableElement *element = new ClassesTableElement("global/" + name, "global/" + superclassName, isImplementation);
	if (!isImplementation && items.count("global/" + name) && items["global/" + name]->IsImplementation) {
		string msg = "Class interface'" + name + "' after implementation";
		throw std::exception(msg.c_str());
	}
	else if (items.count("global/" + name) && items["global/" + name]->IsImplementation == isImplementation) {
		string msg = "Rediifnition of class '" + name + "'";
		throw std::exception(msg.c_str());
	}
	else
		items["global/" + name] = element;
}

void ClassesTable::toCsvFile(string filepath, char separator)
{
	ofstream out(filepath + "ClassesTable.csv"); //Создание и открытие потока на запись в файл
	out << "Name" << separator << "SuperclassName" << separator << "IsImplementation" << separator << "ThisClass" << separator << "Superclass" << separator << "FieldsTableName" << separator << "MethodsTableName" << separator << "PropertiesTableName" << separator << "ConstantsTableName" << endl; // Запись заголовков
	auto iter = items.cbegin();
	while (iter != items.cend())
	{
		string str = iter->second->toCsvString(separator); // Формирование строки
		out << str << endl; //Запись строки в файл
		iter->second->refTablesToCsvFile(filepath, separator); // Запись вложенных таблиц класса
		++iter;
	}
	out.close(); // Закрытие потока
}

// ------------------- FieldsTableElement --------------------

FieldsTableElement::FieldsTableElement(int name, int descriptor, bool isInstance, Type *type, string nameStr, string descriptorStr)
{
	Name = name;
	Descriptor = descriptor;
	IsInstance = isInstance;
	this->type = type;
	NameStr = nameStr;
	DescriptorStr = descriptorStr;
}

string FieldsTableElement::toCsvString(char separator)
{
	string res = "";
	res += to_string(Name) + " (" + NameStr + ")" + separator; //Добавление имени
	res += to_string(Descriptor) + " (" + DescriptorStr + ")" + separator; //Добавление дескриптора
	res += string((IsInstance ? "true" : "false")) + separator; //Добавление флага, который показывает принадлежность поля к экземпляру
	res += type->toString() + separator; //Добавление типа
	return res;
}

// -------------------- FieldsTable --------------------

void FieldsTable::addField(ConstantsTable *constantTable, string name, string descriptor, bool isInstance, Type *type)
{
	int NameId = constantTable->findOrAddConstant(UTF8, name);
	int DescriptorId = constantTable->findOrAddConstant(UTF8, descriptor);
	FieldsTableElement *field = new FieldsTableElement(NameId, DescriptorId, isInstance, type, name, descriptor);
	items[name] = field;
}

void FieldsTable::toCsvFile(string filename, string filepath, char separator)
{
	ofstream out(filepath + filename); //Создание и открытие потока на запись в файл
	out << "Name" << separator << "Descriptor" << separator << "IsInstance" << separator << "Type" << endl; // Запись заголовков
	auto iter = items.cbegin();
	while (iter != items.cend())
	{
		string str = iter->second->toCsvString(separator); // Формирование строки
		out << str << endl; //Запись строки в файл
		++iter;
	}
	out.close(); // Закрытие потока
}

// -------------------- MethodsTableElement --------------------

MethodsTableElement::MethodsTableElement(int name, int descriptor, bool isClassMethod, Statement_node* bodyStart, Type *returnType, vector<Type*>* paramsTypes, vector<Type*>* keywordsTypes, string nameStr, string descriptorStr)
{
	Name = name;
	Descriptor = descriptor;
	IsClassMethod = isClassMethod;
	BodyStart = bodyStart;
	ReturnType = returnType;
	ParamsTypes = paramsTypes;
	KeywordsTypes = keywordsTypes;
	LocalVariables = new LocalVariablesTable();
	NameStr = nameStr;
	DescriptorStr = descriptorStr;
}

string MethodsTableElement::toCsvString(string methodName, char separator)
{
	string res = "";
	res += to_string(Name) + " (" + NameStr + ")" + separator; //Добавление имени
	res += to_string(Descriptor) + " (" + DescriptorStr + ")" + separator; //Добавление дескриптора
	res += string((IsClassMethod ? "true" : "false")) + separator; //Добавление флага, который показывает принадлежность метода к классу
	res += ReturnType->toString() + separator; //Добавление типа возвращаемого значения

	// Формирование строки с типами параметров
	string paramsTypesStr = "";
	for (int i = 0; i < ParamsTypes->size(); i++)
	{
		paramsTypesStr += ParamsTypes->at(i)->toString();
		if (i != ParamsTypes->size() - 1)
		{
			paramsTypesStr += ',';
		}
	}

	// Формирование строки с типами ключевых слов
	string keywordsTypesStr = "";
	for (int i = 0; i < KeywordsTypes->size(); i++)
	{
		keywordsTypesStr += KeywordsTypes->at(i)->toString();
		if (i != KeywordsTypes->size() - 1)
		{
			keywordsTypesStr += ',';
		}
	}

	res += paramsTypesStr + separator; //Добавление типов параметров
	res += keywordsTypesStr + separator; //Добавление типов ключевых слов
	res += to_string(BodyStart->id) + separator; //Добавление ID узла начала тела метода

	if (LocalVariables->items.size() > 0)
		res += methodName + "_LocalVariablesTable.csv"; //Добавление имени таблицы локальных переменных
	else
		res += string("emptyTable"); 
	return res;
}

void MethodsTableElement::refTablesToCsvFile(string methodName, string filepath, char separator)
{
	if (LocalVariables->items.size() > 0)
		LocalVariables->toCsvFile(methodName + "_LocalVariablesTable.csv", filepath, separator);
}

// -------------------- MethodsTable --------------------

void MethodsTable::addMethod(ConstantsTable *constantTable, string name, string descriptor, bool isClassMethod, Statement_node* bodyStart, Type *returnType, vector<Type*>* paramsTypes, vector<Type*>* keywordsTypes)
{
	if (items.count(name) != 0)
	{
		string msg = "Method '" + name + "' already exists";
		throw new exception(msg.c_str());
	}
	int NameId = constantTable->findOrAddConstant(UTF8, name);
	int DescriptorId = constantTable->findOrAddConstant(UTF8, descriptor);
	MethodsTableElement *method = new MethodsTableElement(NameId, DescriptorId, isClassMethod, bodyStart, returnType, paramsTypes, keywordsTypes, name, descriptor);
	items[name] = method;
}

void MethodsTable::toCsvFile(string filename, string filepath, char separator)
{
	ofstream out(filepath + filename); //Создание и открытие потока на запись в файл
	out << "Name" << separator << "Descriptor" << separator << "IsClassMethod" << separator << "ReturnType" << separator << "ParamsTypes" << separator << "KeywordsTypes" << separator << "BodyStartStatementId" << separator << "LocalVariablesTableName" << endl; // Запись заголовков
	auto iter = items.cbegin();
	while (iter != items.cend())
	{
		string methodName = filename.substr(0, filename.find(".")) + "_" + iter->first;
		string str = iter->second->toCsvString(methodName, separator); // Формирование строки
		out << str << endl; //Запись строки в файл
		iter->second->refTablesToCsvFile(methodName, filepath, separator); // Запись вложенных таблиц метода
		++iter;
	}
	out.close(); // Закрытие потока
}

// -------------------- PropertiesTableElement --------------------

PropertiesTableElement::PropertiesTableElement(int name, int descriptor, bool isReadonly, Type *type, string nameStr, string descriptorStr)
{
	Name = name;
	Descriptor = descriptor;
	IsReadonly = isReadonly;
	this->type = type;
	NameStr = nameStr;
	DescriptorStr = descriptorStr;
}

string PropertiesTableElement::toCsvString(char separator)
{
	string res = "";
	res += to_string(Name) + " (" + NameStr + ")" + separator; //Добавление имени
	res += to_string(Descriptor) + " (" + DescriptorStr + ")" + separator; //Добавление дескриптора
	res += string((IsReadonly ? "true" : "false")) + separator; //Добавление флага, который показывает принадлежность свойства к экземпляру
	res += type->toString() + separator; //Добавление типа
	return res;
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
	 PropertiesTableElement *property = new PropertiesTableElement(NameId, DescriptorId, isReadonly, type, name, descriptor);
	 items[name] = property;
 }

 void PropertiesTable::toCsvFile(string filename, string filepath, char separator)
 {
	 ofstream out(filepath + filename); //Создание и открытие потока на запись в файл
	 out << "Name" << separator << "Descriptor" << separator << "IsReadonly" << separator << "Type" << endl; // Запись заголовков
	 auto iter = items.cbegin();
	 while (iter != items.cend())
	 {
		 string str = iter->second->toCsvString(separator); // Формирование строки
		 out << str << endl; //Запись строки в файл
		 ++iter;
	 }
	 out.close(); // Закрытие потока
 }

 // ------------------- LocalVariablesTableElement --------------------

 LocalVariablesTableElement::LocalVariablesTableElement(int id, string name, Type *type)
 {
	 Id = id;
	 Name = name;
	 this->type = type;
 }

 string LocalVariablesTableElement::toCsvString(char separator)
 {
	 string res = "";
	 res += to_string(Id) + separator;
	 res += Name + separator;
	 res += type->toString();
	 return res;
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

void LocalVariablesTable::toCsvFile(string filename, string fileoath, char separator)
{
	ofstream out(fileoath + filename); //Создание и открытие потока на запись в файл
	out << "Id" << separator << "Name" << separator << "Type" << endl; // Запись заголовков
	auto iter = items.cbegin();
	while (iter != items.cend())
	{
		string str = iter->second->toCsvString(separator); // Формирование строки
		out << str << endl; //Запись строки в файл
		++iter;
	}
	out.close(); // Закрытие потока
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

string Type::toString()
{
	string res = "";

	// Формирование строки с типом
	switch (DataType)
	{
	case INT_TYPE:
		res += string("int");
		break;
	case CHAR_TYPE:
		res += string("char");
		break;
	case FLOAT_TYPE:
		res += string("float");
		break;
	case ID_TYPE:
		res += string("id");
		break;
	case CLASS_NAME_TYPE:
		res += ClassName;
		break;
	case VOID_TYPE:
		res += string("void");
		break;
	default:
		break;
	}

	// Формирование строки с учетом массива
	if (ArrSize != -1)
	{
		res += '[' + to_string(ArrSize) + ']';
	}
	return res;
}

// -------------------- FunctionsTableElement --------------------

FunctionsTableElement::FunctionsTableElement(int name, int descriptor, Statement_node* bodyStart, string nameStr, string descriptorStr)
{
	Name = name;
	Descriptor = descriptor;
	BodyStart = bodyStart;
	LocalVariables = new LocalVariablesTable();
	NameStr = nameStr;
	DescriptorStr = descriptorStr;
}

string FunctionsTableElement::toCsvString(string funcName, char separator)
{
	string res = "";
	res += to_string(Name) + " (" + NameStr + ")" + separator; //Добавление имени
	res += to_string(Descriptor) + " (" + DescriptorStr + ")" + separator; //Добавление дескриптора
	res += to_string(BodyStart->id) + separator; //Добавление id узла начала тела функции
	res += funcName + "_LocalVariablesTable.csv"; //имя таблицы с локальными переменными
	return res;
}

void FunctionsTableElement::refTablesToCsvFile(string filename, string filepath, char separator)
{
	if (LocalVariables->items.size() > 0)
		LocalVariables->toCsvFile(filename, filepath, separator);
}

// -------------------- FunctionsTable --------------------

void FunctionsTable::addFunction(ConstantsTable *constantTable, string name, string descriptor, Statement_node* bodyStart)
{
	if (items.count(name) != 0)
	{
		string msg = "Function '" + name + "' already exists";
		throw new exception(msg.c_str());
	}
	int NameId = constantTable->findOrAddConstant(UTF8, name);
	int DescriptorId = constantTable->findOrAddConstant(UTF8, descriptor);
	FunctionsTableElement *function = new FunctionsTableElement(NameId, DescriptorId, bodyStart, name, descriptor);
	items[name] = function;
}

void FunctionsTable::toCsvFile(string filename, string filepath, char separator)
{
	ofstream out(filepath + filename); //Создание и открытие потока на запись в файл
	out << "Name" << separator << "Descriptor" << "BodyStartStatementId" << "LocalVariablesTableName" << endl; // Запись заголовков
	auto iter = items.cbegin();
	while (iter != items.cend())
	{
		string funcName = filename.substr(0, filename.find(".")) + iter->first; // Имя функции
		string str = iter->second->toCsvString(funcName, separator); // Формирование строки
		out << str << endl; //Запись строки в файл
		iter->second->refTablesToCsvFile(funcName, filepath, separator); // Запись вложенных таблиц функции
		++iter;
	}
	out.close(); // Закрытие потока
}
