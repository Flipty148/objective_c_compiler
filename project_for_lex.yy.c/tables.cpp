#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "tables.h"
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
	string compared = utf8string == NULL ? "" : *utf8string;
	auto iter = items.cbegin();
	while (iter != items.cend())
	{
		string curStr = iter->second->Utf8String == NULL ? "" : *iter->second->Utf8String;
		if (iter->second->Type == type && curStr == compared && iter->second->Number == number && iter->second->FirstRef == firstRef && iter->second->SecondRef == secondRef)
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

string ConstantsTable::getConstantString(int id)
{
	if (items[id]->Type != constantType::UTF8)
	{
		return "";
	}
	return *items[id]->Utf8String;
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

int ConstantsTable::findOrAddFieldRefConstant(string className, string fieldName, string descriptor)
{
	int classNameConst = this->findOrAddConstant(UTF8, className);
	int classConst = this->findOrAddConstant(Class, NULL, classNameConst);
	int nameConst = this->findOrAddConstant(UTF8, fieldName);
	int descriptorConst = this->findOrAddConstant(UTF8, descriptor);
	int nameAndTypeConst = this->findOrAddConstant(NameAndType, NULL, nameConst, descriptorConst);
	int fieldRefConst = this->findOrAddConstant(FieldRef, NULL, nameAndTypeConst, classConst);

	return fieldRefConst;
}

int ConstantsTable::findOrAddMethodRefConstant(string className, string methodName, string descriptor)
{
	int classNameConst = this->findOrAddConstant(UTF8, className);
	int classConst = this->findOrAddConstant(Class, NULL, classNameConst);
	int nameConst = this->findOrAddConstant(UTF8, methodName);
	int descriptorConst = this->findOrAddConstant(UTF8, descriptor);
	int nameAndTypeConst = this->findOrAddConstant(NameAndType, NULL, nameConst, descriptorConst);
	int methodRefConst = this->findOrAddConstant(MethodRef, NULL, nameAndTypeConst, classConst);
	
	return methodRefConst;
}

// -------------------- ClassesTableElement --------------------

ClassesTableElement::ClassesTableElement(string name, string *superclassName, bool isImplementation)
{
	ConstantTable = new ConstantsTable();
	Fields = new FieldsTable();
	Methods = new MethodsTable();
	Properties = new PropertiesTable();
	Name = ConstantTable->findOrAddConstant(UTF8, name);
	if (superclassName != NULL)
		SuperclassName = ConstantTable->findOrAddConstant(UTF8, *superclassName);
	ThisClass = ConstantTable->findOrAddConstant(Class, NULL, Name);
	if (superclassName != NULL)
		Superclass = ConstantTable->findOrAddConstant(Class, NULL, SuperclassName);
	IsImplementation = isImplementation;
}

string ClassesTableElement::toCsvString(char separator)
{
	string res = "";
	res += to_string(Name) + '(' + *ConstantTable->getConstant(Name)->Utf8String + ')' + separator;
	if (SuperclassName != NULL)
		res += to_string(SuperclassName) + '(' + *ConstantTable->getConstant(SuperclassName)->Utf8String + ')' + separator;
	else
		res += string("empty") + separator;
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
		Fields->toCsvFile(className + "_FieldsTable.csv", filepath, separator); //Записать таблицу полей в файл
	
	if (Methods->items.size() > 0)
		Methods->toCsvFile(className + "_MethodsTable.csv", filepath, separator); //Записать таблицу методов в файл

	if (Properties->items.size() > 0)
		Properties->toCsvFile(className + "_PropertiesTable.csv", filepath, separator); //Записать таблицу свойств в файл

	ConstantTable->toCsvFile(className + "_ConstantsTable.csv", filepath, separator); //Записать таблицу констант в файл
}

string ClassesTableElement::getClassName()
{
	return ConstantTable->getConstantString(Name);
}

string ClassesTableElement::getSuperClassName()
{
	return ConstantTable->getConstantString(SuperclassName);
}

void ClassesTableElement::fillFieldRefs()
{
	for (auto iter = Methods->items.cbegin(); iter != Methods->items.cend(); ++iter)
	{
		iter->second->fillFieldRefs(ConstantTable, this);
	}
}

void ClassesTableElement::fillMethodRefs()
{
	for (auto iter = Methods->items.cbegin(); iter != Methods->items.cend(); ++iter)
	{
		iter->second->fillMethodRefs(ConstantTable, this);
	}
}

bool ClassesTableElement::isContainsField(string fieldName)
{
	if (Fields->items.count(fieldName) != 0)
		return true;
	else {
		if (SuperclassName != NULL)
			return ClassesTable::items[getSuperClassName()]->isContainsField(fieldName); //TODO: check types
	}
	return false;
}

void ClassesTableElement::getFieldForRef(string name, string* descriptor, string* className)
{
	if (isContainsField(name)){ // Содержит поле
		if (Fields->items.count(name) != 0) { //Поле содержится в текущем классе
			*descriptor = Fields->items[name]->DescriptorStr;
			*className = getClassName();
		}
		else { //Поле содержится в одном из родительских классов
			if (SuperclassName != NULL)
				ClassesTable::items[getSuperClassName()]->getFieldForRef(name, descriptor, className);
		}
	}
}

bool ClassesTableElement::isHaveOneOfSuperclass(string name)
{
	if (SuperclassName == NULL) { //Родительский класс отсутствует
		return false;
	}
	else {
		if (getSuperClassName() == name) //Имя родительского класса совпадает с искомым
			return true;
		else return ClassesTable::items[getSuperClassName()]->isHaveOneOfSuperclass(name); //Проверить является искомый класс родительским для родительского
	}
}

bool ClassesTableElement::isContainsMethod(string methodName)
{
	if (Methods->items.count(methodName) != 0)
		return true;
	else {
		if (SuperclassName != NULL)
			return ClassesTable::items[getSuperClassName()]->isContainsMethod(methodName);
	}
	return false;
}

void ClassesTableElement::getMethodForRef(string name, string* descriptor, string* className)
{
	if (isContainsMethod(name)) { // Содержит метод
		if (Methods->items.count(name) != 0) { //Метод содержится в текущем классе
			*descriptor = Methods->items[name]->DescriptorStr;
			*className = getClassName();
		}
		else { //Метод содержится в одном из родительских классов
			if (SuperclassName != NULL)
				ClassesTable::items[getSuperClassName()]->getMethodForRef(name, descriptor, className);
		}
	}
}

// -------------------- ClassesTable --------------------
map<string, ClassesTableElement*> ClassesTable::items;

ClassesTableElement* ClassesTable::addClass(string name, string* superclassName, bool isImplementation)
{
	//TODO: check superclass name is RTL
	//TODO: Добавить проверку на наличие реализации метода при наличии интерфейса
	//TODO: Проверка на соответствие необходимых элементов в реализации и интерфейсе
	string fullName = "global/" + name;
	string* fullSuperclassName = NULL;
	if (superclassName != NULL)
		fullSuperclassName = new string("global/" +  * superclassName);
	ClassesTableElement *element = new ClassesTableElement("global/" + name, fullSuperclassName, isImplementation); // Новый добавляемый элемент


	if (!isImplementation && items.count(fullName) && items[fullName]->IsImplementation) { // Проверка, чтобы интерфейс класса при его наличии находился раньше реализации
		string msg = "Class interface'" + name + "' after implementation";
		throw std::exception(msg.c_str());
	}
	else if (items.count(fullName) && items[fullName]->IsImplementation == isImplementation) { // Проверка на повторное объявление класса
		string msg = "Rediifnition of class '" + name + "'";
		throw std::exception(msg.c_str());
	}
	else if (superclassName != NULL && items.count(fullName) && items[fullName]->ConstantTable->getConstantString(items[fullName]->SuperclassName) != *fullSuperclassName) { // Проверка на совпадение суперкласса в интерфейсе и реаизации
		string msg = "Class '" + name + "' with different superclass";
		throw std::exception(msg.c_str());
	}
	else if (items.count(fullName) && !items[fullName]->IsImplementation && isImplementation) { // Объявление реализации после интерфейса
		items[fullName]->IsImplementation = true;
		items[fullName]->IsHaveInterface = true;
		delete element;
	}
	else {
		items[fullName] = element; // Добавление (обновление элемента в таблице классов)
	}

	return items[fullName];
}

void ClassesTable::initRTL()
{
	initClassProgram();

	

	// Создание 

	//TODO: СДелать создание остальных классов RTL и заполнение всех классов RTL
}

void ClassesTable::initClassProgram()
{
	// Создание класса Program
	ClassesTableElement* program = new ClassesTableElement("rtl/Program", NULL, false);

	// Добавление метода printInt
	ConstantsTable* сonstantTable = program->ConstantTable;
	Type *printIntReturnType = new Type(VOID_TYPE);
	vector<Type*> *printIntKeywordsType = new vector<Type*>{ new Type(INT_TYPE) };
	vector<Type*> *printIntParamsType = new vector<Type*>;
	program->Methods->addMethod(сonstantTable, "printInt", "(I)V", true, NULL, printIntReturnType, printIntParamsType, printIntKeywordsType);

	//Добавление метода printChar
	Type* printCharReturnType = new Type(VOID_TYPE);
	vector<Type*> *printCharKeywordsType = new vector<Type*>{ new Type(CHAR_TYPE) };
	vector<Type*> *printCharParamsType = new vector<Type*>;
	program->Methods->addMethod(сonstantTable, "printChar", "(C)V", true, NULL, printCharReturnType, printCharParamsType, printCharKeywordsType);

	//Добавление метода printString
	Type* printStringReturnType = new Type(VOID_TYPE);
	vector<Type*> *printStringKeywordsType = new vector<Type*>{ new Type(CLASS_NAME_TYPE, "java/lang/String")};
	vector<Type*> *printStringParamsType = new vector<Type*>;
	program->Methods->addMethod(сonstantTable, "printString", "(Ljava/lang/String;)V", true, NULL, printStringReturnType, printStringParamsType, printStringKeywordsType);

	//Добавление метода printCharArray
	Type* printCharArrayReturnType = new Type(VOID_TYPE);
	vector<Type*> *printCharArrayKeywordsType = new vector<Type*>{ new Type(CHAR_TYPE, 1024) };
	vector<Type*> *printCharArrayParamsType = new vector<Type*>;
	program->Methods->addMethod(сonstantTable, "printCharArray", "([C)V", true, NULL, printCharArrayReturnType, printCharArrayParamsType, printCharArrayKeywordsType);

	//Добавление метода printObject
	Type* printObjectReturnType = new Type(VOID_TYPE);
	vector<Type*> *printObjectKeywordsType = new vector<Type*>{ new Type(CLASS_NAME_TYPE, "java/lang/Object") };
	vector<Type*> *printObjectParamsType = new vector<Type*>;
	program->Methods->addMethod(сonstantTable, "printObject", "(Ljava/lang/Object;)V", true, NULL, printObjectReturnType, printObjectParamsType, printObjectKeywordsType);

	//Добавление метода read
	Type* readReturnType = new Type(CLASS_NAME_TYPE, "java/lang/String");
	vector<Type*> *readKeywordsType = new vector<Type*>;
	vector<Type*> *readParamsType = new vector<Type*>;
	program->Methods->addMethod(сonstantTable, "read", "()Ljava/lang/String;", true, NULL, readReturnType, readParamsType, readKeywordsType);

	//Добавление метода readInt
	Type* readIntReturnType = new Type(INT_TYPE);
	vector<Type*> *readIntKeywordsType = new vector<Type*>;
	vector<Type*> *readIntParamsType = new vector<Type*>;
	program->Methods->addMethod(сonstantTable, "readInt", "()I", true, NULL, readIntReturnType, readIntParamsType, readIntKeywordsType);

	//Добавление метода readChar
	Type* readCharReturnType = new Type(CHAR_TYPE);
	vector<Type*> *readCharKeywordsType = new vector<Type*>;
	vector<Type*> *readCharParamsType = new vector<Type*>;
	program->Methods->addMethod(сonstantTable, "readChar", "()C", true, NULL, readCharReturnType, readCharParamsType, readCharKeywordsType);


	//Добавление FieldRef
	сonstantTable->findOrAddFieldRefConstant("java/lang/System", "out", "Ljava/io/PrintStream;");

	//Добавление MethodRef
	сonstantTable->findOrAddMethodRefConstant("java/lang/Object", "<init>", "()V");
	сonstantTable->findOrAddMethodRefConstant("java/io/PrintStream", "print", "(I)V");
	сonstantTable->findOrAddMethodRefConstant("java/io/PrintStream", "print", "(C)V");
	сonstantTable->findOrAddMethodRefConstant("java/io/PrintStream", "print", "(Ljava/lang/String;)V");
	сonstantTable->findOrAddMethodRefConstant("java/io/PrintStream", "print", "([C)V");
	сonstantTable->findOrAddMethodRefConstant("java/io/PrintStream", "print", "Ljava/lang/Object;");
	сonstantTable->findOrAddMethodRefConstant("java/lang/System", "console", "Ljava/io/Console;");
	сonstantTable->findOrAddMethodRefConstant("java/io/Console", "readLine", "()Ljava/lang/String;");
	сonstantTable->findOrAddMethodRefConstant("rtl/Program", "read", "()Ljava/lang/String;");
	сonstantTable->findOrAddMethodRefConstant("java/lang/Integer", "parseInt", "(Ljava/lang/String;)I");
	сonstantTable->findOrAddMethodRefConstant("java/lang/String", "charAt", "(I)C");

	//Добавление класса Program в таблицу классов
	items["rtl/Program"] = program;
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

void ClassesTable::fillFieldRefs()
{
	auto iter = items.cbegin();
	while (iter != items.cend())
	{
		iter->second->fillFieldRefs();
		++iter;
	}
}

void ClassesTable::fillMethodRefs()
{
	auto iter = items.cbegin();
	while (iter != items.cend())
	{
		iter->second->fillMethodRefs();
		++iter;
	}
}

string ClassesTable::getFullClassName(string name)
{
	// TODO: если имя класса из RTL, то вернуть имя RTL ("rtl/")
	if (name.find("global/") != string::npos)
		return name;
	if (name.find("rtl/") != string::npos)
		return name;
	string fullName = "global/" + name;
	if (items.count(fullName) == 0) {
		string msg = "Class '" + name + "' not found";
		throw std::exception(msg.c_str());
	}
	return fullName;
}

// ------------------- FieldsTableElement --------------------

FieldsTableElement::FieldsTableElement(int name, int descriptor, bool isInstance, int instanceIndex, Type *type, string nameStr, string descriptorStr, Expression_node* initialValue)
{
	Name = name;
	Descriptor = descriptor;
	IsInstance = isInstance;
	InstanceIndex = instanceIndex;
	this->type = type;
	NameStr = nameStr;
	DescriptorStr = descriptorStr;
	InitialValue = initialValue;
}

string FieldsTableElement::toCsvString(char separator)
{
	string res = "";
	res += to_string(Name) + " (" + NameStr + ")" + separator; //Добавление имени
	res += to_string(Descriptor) + " (" + DescriptorStr + ")" + separator; //Добавление дескриптора
	res += string((IsInstance ? "true" : "false")) + separator; //Добавление флага, который показывает принадлежность поля к экземпляру
	res += type->toString() + separator; //Добавление типа
	if (InitialValue == NULL)
		res += string("empty");
	else
		res += to_string(InitialValue->id); //Добавление id узла инициализации
	return res;
}

// -------------------- FieldsTable --------------------

void FieldsTable::addField(ConstantsTable* constantTable, string name, string descriptor, bool isInstance, Type* type, Expression_node* initValue)
{
	int NameId = constantTable->findOrAddConstant(UTF8, name);
	int DescriptorId = constantTable->findOrAddConstant(UTF8, descriptor);
	if (isInstance) {
		FieldsTableElement* field = new FieldsTableElement(NameId, DescriptorId, isInstance, maxInstanceIndex, type, name, descriptor, initValue);
		maxInstanceIndex++;
		items[name] = field;
	}
	else {
		FieldsTableElement* field = new FieldsTableElement(NameId, DescriptorId, isInstance, 0, type, name, descriptor, initValue);
		items[name] = field;
	}
	
}

void FieldsTable::toCsvFile(string filename, string filepath, char separator)
{
	ofstream out(filepath + filename); //Создание и открытие потока на запись в файл
	out << "Name" << separator << "Descriptor" << separator << "IsInstance" << separator << "Type" << separator << "InitValueIdNode" <<  endl; // Запись заголовков
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
	if (BodyStart != NULL)
		res += to_string(BodyStart->id) + separator; //Добавление ID узла начала тела метода
	else
		res += string("empty") + separator;

	if (LocalVariables->items.size() > 0)
		res += methodName + "_LocalVariablesTable.csv"; //Добавление имени таблицы локальных переменных
	else
		res += string("emptyTable"); 
	return res;
}

void MethodsTableElement::fillFieldRefs(ConstantsTable *constantTable, ClassesTableElement* classTableElement)
{
	Statement_node *cur = BodyStart;
	while (cur != NULL)
	{
		cur->fillFieldRefs(constantTable, LocalVariables, classTableElement); // Заполнить таблицу
		cur = cur->Next;
	}
}

void MethodsTableElement::fillMethodRefs(ConstantsTable* constantTable, ClassesTableElement* classTableElement)
{
	Statement_node* cur = BodyStart;
	while (cur != NULL)
	{
		cur->fillMethodRefs(constantTable, LocalVariables, classTableElement, !IsClassMethod); // Заполнить таблицу
		cur = cur->Next;
	}
}

void MethodsTableElement::refTablesToCsvFile(string methodName, string filepath, char separator)
{
	if (LocalVariables->items.size() > 0)
		LocalVariables->toCsvFile(methodName + "_LocalVariablesTable.csv", filepath, separator);
}

// -------------------- MethodsTable --------------------

MethodsTableElement* MethodsTable::addMethod(ConstantsTable *constantTable, string name, string descriptor, bool isClassMethod, Statement_node* bodyStart, Type *returnType, vector<Type*>* paramsTypes, vector<Type*>* keywordsTypes)
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

	return method;
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

bool LocalVariablesTable::isContains(string name)
{
	return items.count(name) != 0;
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

string Type::getDescriptor()
{
	string res = "";
	if (ArrSize != -1)
	{
		res += '[';
	}
	switch (DataType)
	{
	case INT_TYPE:
		res += string("I");
		break;
	case CHAR_TYPE:
		res += string("C");
		break;
	case FLOAT_TYPE:
		res += string("F");
		break;
	case ID_TYPE:
		res += string("Lrtl/NSObject;");
		break;
	case CLASS_NAME_TYPE:
		res += 'L' + ClassName + ';';
		break;
	case VOID_TYPE:
		res += string("V");
		break;
	default:
		break;
	}
	return res;
}

bool Type::equal(Type* other)
{
	return DataType == other->DataType && ClassName == other->ClassName && ArrSize == other->ArrSize;
}

// -------------------- FunctionsTableElement --------------------

FunctionsTableElement::FunctionsTableElement(Statement_node* bodyStart, string nameStr, string descriptorStr, vector<Type*>* params, Type* returnType)
{
	BodyStart = bodyStart;
	LocalVariables = new LocalVariablesTable();
	NameStr = nameStr;
	DescriptorStr = descriptorStr;
	ParametersTypes = params;
	ReturnType = returnType;
}

string FunctionsTableElement::toCsvString(string funcName, char separator)
{
	string res = "";
	res +=  NameStr + separator; //Добавление имени
	res += DescriptorStr + separator; //Добавление дескриптора
	res += to_string(BodyStart->id) + separator; //Добавление id узла начала тела функции
	if (LocalVariables->items.size() > 0)
		res += funcName + "_LocalVariablesTable.csv"; //имя таблицы с локальными переменными
	else
		res += string("empty");
	return res;
}

void FunctionsTableElement::refTablesToCsvFile(string filename, string filepath, char separator)
{
	if (LocalVariables->items.size() > 0)
		LocalVariables->toCsvFile(filename, filepath, separator);
}

void FunctionsTableElement::fillFieldRefs(ConstantsTable* constantTable, ClassesTableElement* classTableElement)
{
	Statement_node* cur = BodyStart;
	while (cur != NULL)
	{
		cur->fillFieldRefs(constantTable, LocalVariables, classTableElement); // Заполнить таблицу
		cur = cur->Next;
	}
}

void FunctionsTableElement::fillMethodRefs(ConstantsTable* constantTable, ClassesTableElement* classTableElement)
{
	Statement_node* cur = BodyStart;
	while (cur != NULL)
	{
		cur->fillMethodRefs(constantTable, LocalVariables, classTableElement, false); // Заполнить таблицу
		cur = cur->Next;
	}
}

// -------------------- FunctionsTable --------------------
map<string, FunctionsTableElement*> FunctionsTable::items;


FunctionsTableElement* FunctionsTable::addFunction(string name, string descriptor, Statement_node* bodyStart, vector<Type*>* params, Type* returnType)
{
	if (items.count(name) != 0)
	{
		string msg = "Function '" + name + "' already exists";
		throw new exception(msg.c_str());
	}
	FunctionsTableElement *function = new FunctionsTableElement(bodyStart, name, descriptor, params, returnType);
	items[name] = function;
	return function;
}

void FunctionsTable::toCsvFile(string filename, string filepath, char separator)
{
	ofstream out(filepath + filename); //Создание и открытие потока на запись в файл
	out << "Name" << separator << "Descriptor" << separator << "BodyStartStatementId" << separator << "LocalVariablesTableName" << endl; // Запись заголовков
	auto iter = items.cbegin();
	while (iter != items.cend())
	{
		string funcName = filename.substr(0, filename.find(".")) + string("_") + iter->first + "_LocalVariables.csv"; // Имя функции
		string str = iter->second->toCsvString(funcName, separator); // Формирование строки
		out << str << endl; //Запись строки в файл
		iter->second->refTablesToCsvFile(funcName, filepath, separator); // Запись вложенных таблиц функции
		++iter;
	}
	out.close(); // Закрытие потока
}

void FunctionsTable::fillFieldRefs()
{
	ClassesTableElement* classTableElement = ClassesTable::items["rtl/Program"];
	bool isDontContainsMain = true;
	auto iter = items.cbegin();
	while (iter != items.cend())
	{
		isDontContainsMain = isDontContainsMain && iter->first == "main";
		iter->second->fillFieldRefs(classTableElement->ConstantTable, classTableElement);
		++iter;
	}

	if (!isDontContainsMain) { //Функция main не найдена
		string msg = "Function 'main' not found";
		throw new exception(msg.c_str());
	}
}

void FunctionsTable::fillMethodRefs()
{
	ClassesTableElement* classTableElement = ClassesTable::items["rtl/Program"];
	auto iter = items.cbegin();
	while (iter != items.cend())
	{
		iter->second->fillMethodRefs(classTableElement->ConstantTable, classTableElement);
		++iter;
	}
}
