﻿#include <fstream>
#include "tables.h"
#include "code_generation_helpers.h"
#include <iostream>
#include <string>

using namespace std;

void ClassesTable::generateClassFiles(string filepath)
{
	auto iter = items.cbegin();
	while (iter != items.cend())
	{
		if (iter->second->isNeedToGenerateClassFile())
			iter->second->generateClassFile(filepath);
		++iter;
	}
}

void ClassesTableElement::generateClassFile(string filepath)
{
	string className = getClassName(); //Получить имя текущего класса
	string classFile = filepath + className + ".class"; //Путь к файлу
	
	//Генерация .class файла
	vector<char> *data = new vector<char>;

	//Указание магических констант
	int magicConstantSize = sizeof(CodeGenerationHelpers::magicConstant)/sizeof(CodeGenerationHelpers::magicConstant[0]); //Количество элементов в магической константе
	int smallVersionSize = sizeof(CodeGenerationHelpers::smallVersion)/sizeof(CodeGenerationHelpers::smallVersion[0]); //Количество элементов в малой версии формата файла
	int bigVersionSize = sizeof(CodeGenerationHelpers::bigVersion)/sizeof(CodeGenerationHelpers::bigVersion[0]); //Количество элементов в большой версии формата файла
	CodeGenerationHelpers::appendArrayToByteVector(data, CodeGenerationHelpers::magicConstant, magicConstantSize); //Добавление магической константы
	CodeGenerationHelpers::appendArrayToByteVector(data, CodeGenerationHelpers::smallVersion, smallVersionSize); //Добавление малой версии формата файла
	CodeGenerationHelpers::appendArrayToByteVector(data, CodeGenerationHelpers::bigVersion, bigVersionSize); //Добавление большой версии формата файла

	// Таблица констант
	int constantSize = ConstantTable->items.size() + 1; //Количество констант + 1
	vector<char> constantSizeBytes = CodeGenerationHelpers::intToByteArray(constantSize, 2); //Конвертация размера таблицы констант в байты
	CodeGenerationHelpers::appendArrayToByteVector(data, constantSizeBytes.data(), constantSizeBytes.size()); //Добавление размера таблицы констант в байты
	vector<char> constantTableBytes = ConstantTable->generateBytes(); //Генерация таблицы констант
	CodeGenerationHelpers::appendArrayToByteVector(data, constantTableBytes.data(), constantTableBytes.size()); //Добавление таблицы констант

	//Флаги доступа
	data->push_back(0x00); //Отсутствие ACC_ABSTRACT ????
	data->push_back(0x21); //ACC_SUPER + ACC_PUBLIC

	//Текущий класс
	vector<char> classNameBytes = CodeGenerationHelpers::intToByteArray(ThisClass, 2); //Конвертация имени текущего класса в байты
	CodeGenerationHelpers::appendArrayToByteVector(data, classNameBytes.data(), classNameBytes.size()); //Добавление имени текущего класса в байты

	//Класс-родитель
	vector<char> superClassBytes = CodeGenerationHelpers::intToByteArray(Superclass, 2); //Конвертация имени родительского класса в байты
	CodeGenerationHelpers::appendArrayToByteVector(data, superClassBytes.data(), superClassBytes.size()); //Добавление имени родительского класса в байты

	//Количество интерфейсов
	vector<char> interfaceCountBytes = CodeGenerationHelpers::intToByteArray(0, 2); //Конвертация количества интерфейсов в байты
	CodeGenerationHelpers::appendArrayToByteVector(data, interfaceCountBytes.data(), interfaceCountBytes.size()); //Добавление количества интерфейсов в байты

	//Поля класса
	int fieldCount = Fields->items.size(); //Количество полей
	vector<char> fieldCountBytes = CodeGenerationHelpers::intToByteArray(fieldCount, 2); //Конвертация количества полей в байты
	CodeGenerationHelpers::appendArrayToByteVector(data, fieldCountBytes.data(), fieldCountBytes.size()); //Добавление количества полей в байты
	vector<char> fieldTableBytes = Fields->generateBytes(); //Генерация таблицы полей
	CodeGenerationHelpers::appendArrayToByteVector(data, fieldTableBytes.data(), fieldTableBytes.size()); //Добавление таблицы полей
	
	//Методы класса
	int methodCount = Methods->items.size(); //Количество методов
	vector<char> methodCountBytes = CodeGenerationHelpers::intToByteArray(methodCount, 2); //Конвертация количества методов в байты
	CodeGenerationHelpers::appendArrayToByteVector(data, methodCountBytes.data(), methodCountBytes.size()); //Добавление количества методов в байты
	vector<char> methodTableBytes = Methods->generateBytes(ConstantTable); //Генерация таблицы методов
	CodeGenerationHelpers::appendArrayToByteVector(data, methodTableBytes.data(), methodTableBytes.size()); //Добавление таблицы методов
	
	//Атрибуты класса
	vector<char> attributeCountBytes = CodeGenerationHelpers::intToByteArray(0, 2); //Конвертация количества атрибутов в байты
	CodeGenerationHelpers::appendArrayToByteVector(data, attributeCountBytes.data(), attributeCountBytes.size()); //Добавление количества атрибутов в байты

	ofstream out(classFile, ios::out | ios::binary); //Создание и открытие потока на запись в файл
	out.write(data->data(), data->size()); //Запись в файл
	out.close(); //Закрытие потока
}

bool ClassesTableElement::isNeedToGenerateClassFile()
{
	string className = getClassName(); //Получить имя текущего класса
	if (className == "rtl/Program" || className.find("rtl/") == string::npos)
		return true;
	return false;
}

// -------------------- Таблица констант --------------------
vector<char> ConstantsTable::generateBytes()
{
	vector <char> res;
	for (auto iter = items.cbegin(); iter != items.cend(); ++iter) {
		vector<char> bytes = iter->second->generateBytes();
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		
	return res;
}

vector<char> ConstantsTableElement::generateBytes()
{
	vector<char> res;
	
	// Добавление типа константы
	res.push_back(Type);

	switch (Type)
	{
	case UTF8: {
		vector<char> len = CodeGenerationHelpers::intToByteArray(Utf8String->length(), 2); //Размер строки в байтах
		char *str = new char[Utf8String->length() + 1]; //Строка
		strcpy(str, Utf8String->c_str());
		CodeGenerationHelpers::appendArrayToByteVector(&res, len.data(), len.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, str, Utf8String->length());
	}
		break;
	case Integer: {
		vector<char> num = CodeGenerationHelpers::intToByteArray(Number, 4); //Число в байтах
		CodeGenerationHelpers::appendArrayToByteVector(&res, num.data(), num.size());
	}
		break;
	case String:
	case Class: {
		vector<char> ref = CodeGenerationHelpers::intToByteArray(FirstRef, 2); //Номер константы UTF-8
		CodeGenerationHelpers::appendArrayToByteVector(&res, ref.data(), ref.size());
	}
		break;
	case NameAndType: {
		vector<char> firstRef = CodeGenerationHelpers::intToByteArray(FirstRef, 2); //Номер константы UTF-8 с именем
		vector<char> secondRef = CodeGenerationHelpers::intToByteArray(SecondRef, 2); //Номер константы UTF-8 с типом
		CodeGenerationHelpers::appendArrayToByteVector(&res, firstRef.data(), firstRef.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, secondRef.data(), secondRef.size());
	}
		break;
	case FieldRef:
	case MethodRef: {
		vector<char> firstRef = CodeGenerationHelpers::intToByteArray(SecondRef, 2); //Номер константы Class с классом
		vector<char> secondRef = CodeGenerationHelpers::intToByteArray(FirstRef, 2); //Номер константы NameAndType с типом и именем
		CodeGenerationHelpers::appendArrayToByteVector(&res, firstRef.data(), firstRef.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, secondRef.data(), secondRef.size());
	}
		break;
	default:
		break;
	}

	return res;
}

// -------------------- Таблица полей --------------------
vector<char> FieldsTable::generateBytes()
{
	vector<char> res;
	for (auto iter = items.cbegin(); iter != items.cend(); ++iter) {
		vector<char> bytes = iter->second->generateBytes();
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
	return res;
}

vector<char> FieldsTableElement::generateBytes()
{
	vector<char> res;

	//Добавление флага доступа
	char publicFlag[2] = { 0x00, 0x01 }; //Флаг ACC_PUBLIC
	char protectedFlag[2] = { 0x00, 0x04 }; //Флаг ACC_PROTECTED
	
	if (IsInstance) {
		CodeGenerationHelpers::appendArrayToByteVector(&res, publicFlag, 2);
	}
	else {
		CodeGenerationHelpers::appendArrayToByteVector(&res, protectedFlag, 2);
	}

	//Добавление имени поля
	vector<char> nameBytes = CodeGenerationHelpers::intToByteArray(Name, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, nameBytes.data(), nameBytes.size());

	//Добавление дескриптора поля
	vector<char> typeBytes = CodeGenerationHelpers::intToByteArray(Descriptor, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, typeBytes.data(), typeBytes.size());

	//Добавление атрибутов
	res.push_back(0x00);
	res.push_back(0x00);

	return res;
}

// -------------------- Таблица методов --------------------
vector<char> MethodsTable::generateBytes(ConstantsTable* constantsTable)
{
	vector<char> res;
	for (auto iter = items.cbegin(); iter != items.cend(); ++iter) {
		vector<char> bytes = iter->second->generateBytes(constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
	return res;
}

vector<char> MethodsTableElement::generateBytes(ConstantsTable* constantsTable)
{
	vector<char> res;

	// Добавление флага доступа
	char publicDynamicFlag[2] = { 0x00, 0x01 }; //ACC_PUBLIC
	char publicStaticFlag[2] = { 0x00, 0x09 }; //ACC_PUBLIC + ACC_STATIC

	if (IsClassMethod)
		CodeGenerationHelpers::appendArrayToByteVector(&res, publicStaticFlag, 2);
	else
		CodeGenerationHelpers::appendArrayToByteVector(&res, publicDynamicFlag, 2);

	//Добавление имени метода
	vector<char> nameBytes = CodeGenerationHelpers::intToByteArray(Name, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, nameBytes.data(), nameBytes.size());

	// Добавление дескриптора метода
	vector<char> typeBytes = CodeGenerationHelpers::intToByteArray(Descriptor, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, typeBytes.data(), typeBytes.size());

	//Добавление атрибутов TODO:Code
	vector<char> codeAttributeSizeBytes = CodeGenerationHelpers::intToByteArray(1, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, codeAttributeSizeBytes.data(), codeAttributeSizeBytes.size());
	vector<char> codeAttributeBytes = generateCodeAttribute(constantsTable);
	CodeGenerationHelpers::appendArrayToByteVector(&res, codeAttributeBytes.data(), codeAttributeBytes.size());

	return res;
}

vector<char> MethodsTableElement::generateCodeAttribute(ConstantsTable* constantsTable)
{
	vector<char> res;

	//Добавление имени атрибута
	vector<char> nameBytes = CodeGenerationHelpers::intToByteArray(1, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, nameBytes.data(), nameBytes.size());

	//Формирование байт-кода метода
	vector<char> codeBytes;
	if (BodyStart != NULL) {
		Statement_node* curStatement = BodyStart;
		while (curStatement != NULL) {
			vector<char> bytes = curStatement->generateCode(IsClassMethod, constantsTable);
			CodeGenerationHelpers::appendArrayToByteVector(&codeBytes, bytes.data(), bytes.size());
			curStatement = curStatement->Next;
		}
	}

	//Добавление длины атрибута
	vector<char> lengthBytes = CodeGenerationHelpers::intToByteArray(12 + codeBytes.size(), 4);
	CodeGenerationHelpers::appendArrayToByteVector(&res, lengthBytes.data(), lengthBytes.size());

	//Добавление размера стека операндов
	vector<char> stackSizeBytes = CodeGenerationHelpers::intToByteArray(CodeGenerationHelpers::stackSize, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, stackSizeBytes.data(), stackSizeBytes.size());

	//Добавление количества локальных переменных
	int localsSize = LocalVariables->items.size();
	if (IsClassMethod)
		localsSize -= 1;
	vector<char> localsSizeBytes = CodeGenerationHelpers::intToByteArray(localsSize, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, localsSizeBytes.data(), localsSizeBytes.size());


	//Добавление длины байт-кода TODO: сделать
	vector<char> codeSizeBytes = CodeGenerationHelpers::intToByteArray(codeBytes.size(), 4);
	CodeGenerationHelpers::appendArrayToByteVector(&res, codeSizeBytes.data(), codeSizeBytes.size());

	//Добавление байт-кода
	CodeGenerationHelpers::appendArrayToByteVector(&res, codeBytes.data(), codeBytes.size());

	//Добавление количества записей в таблице исключений
	vector<char> exceptionTableSizeBytes = CodeGenerationHelpers::intToByteArray(0, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, exceptionTableSizeBytes.data(), exceptionTableSizeBytes.size());

	//Добавление количества атрибутов
	vector<char> attributesCountBytes = CodeGenerationHelpers::intToByteArray(0, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, attributesCountBytes.data(), attributesCountBytes.size());

	return res;
}


// -------------------- Генерация байт-кода метода для атрибута Code --------------------

// ---------- Statement ----------
vector<char> Statement_node::generateCode(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	switch (type)
	{
	case EMPTY_STATEMENT_TYPE:
		break;
	case SIMPLE_STATEMENT_TYPE: {
		vector<char> bytes = generateCodeForSimpleStatement(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case RETURN_STATEMENT_TYPE: {
		vector<char> bytes = generateCodeForReturnStatement(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case IF_STATEMENT_TYPE: {

	}
		break;
	case WHILE_STATEMENT_TYPE: {

	}
		break;
	case DO_WHILE_STATEMENT_TYPE: {

	}
		break;
	case FOR_STATEMENT_TYPE: {

	}
		break;
	case COMPOUND_STATEMENT_TYPE: {

	}
		break;
	case DECLARATION_STATEMENT_TYPE: {

	}
		break;
	default:
		break;
	}

	return res;
}

vector<char> Statement_node::generateCodeForSimpleStatement(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> expr = Expression->generateCode(isInsideClassMethod, constantsTable);
	CodeGenerationHelpers::appendArrayToByteVector(&res, expr.data(), expr.size());

	return res;
}

vector<char> Statement_node::generateCodeForReturnStatement(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	if (Expression != NULL) {
		vector<char> expr = Expression->generateCode(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, expr.data(), expr.size()); //Загрузить expression (значение)

		if (Expression->DataType->DataType == CLASS_NAME_TYPE || Expression->DataType->DataType == ID_TYPE) { //Возвращается ссылка
			vector<char> returnBytes = CodeGenerationCommands::areturn();
			CodeGenerationHelpers::appendArrayToByteVector(&res, returnBytes.data(), returnBytes.size());
		}
		else { //Возвращается значение
			vector<char> returnBytes = CodeGenerationCommands::ireturn();
			CodeGenerationHelpers::appendArrayToByteVector(&res, returnBytes.data(), returnBytes.size());
		}
	}
	else { //void return
		vector<char> returnBytes = CodeGenerationCommands::return_();
		CodeGenerationHelpers::appendArrayToByteVector(&res, returnBytes.data(), returnBytes.size());
	}

	return res;
}


// ---------- Expression ----------

vector<char> Expression_node::generateCode(bool isInsideClassMethod, ConstantsTable *constantsTable)
{
	vector<char> res;

	switch (type)
	{
	case IDENTIFIER_EXPRESSION_TYPE: {

	}
		break;
	case LITERAL_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForLiteral();
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case NUMERIIC_CONSTANT_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForNumericConstant();
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case SELF_EXPRESSION_TYPE: {

	}
		break;
	case SUPER_EXPRESSION_TYPE: {

	}
		break;
	case MESSAGE_EXPRESSION_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForMessageExpression(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case UMINUS_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForUminus(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case UPLUS_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForUplus(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case UAMPERSAND_EXPRESSION_TYPE: {

	}
		break;
	case PLUS_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForPlus(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case MINUS_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForMinus(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case MUL_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForMul(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case DIV_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForDiv(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case EQUAL_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForEqual(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case NOT_EQUAL_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForNotEqual(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case GREATER_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForGreater(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case LESS_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForLess(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case LESS_EQUAL_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForLessEqual(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case GREATER_EQUAL_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForGreaterEqual(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case ASSIGNMENT_EXPRESSION_TYPE: {

	}
		break;
	case DOT_EXPRESSION_TYPE: {

	}
		break;
	case ARROW_EXPRESSION_TYPE: {

	}
		break;
	case ARRAY_ELEMENT_ACCESS_EXPRESSION_TYPE: {

	}
		break;
	case ARRAY_ASSIGNMENT_EXPRESSION_TYPE: {

	}
		break;
	case MEMBER_ACCESS_ASSIGNMENT_EXPRESSION_TYPE: {

	}
		break;
	case CHAR_CAST: {

	}
		break;
	case INT_CAST: {

	}
		break;
	case CLASS_CAST: {

	}
		break;
	default:
		break;
	}

	return res;
}

vector<char> Expression_node::generateCodeForNumericConstant()
{
	vector<char> res;
	
	int number = num->Int; // Число

	vector<char> bytes = CodeGenerationCommands::iconstBipushSipush(number); //Команда
	CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());

	return res;
}

vector<char> Expression_node::generateCodeForPlus(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> leftOperand = Left->generateCode(isInsideClassMethod, constantsTable); //1-ое слагаемое
	CodeGenerationHelpers::appendArrayToByteVector(&res, leftOperand.data(), leftOperand.size());

	vector<char> rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //2-ое слагаемое
	CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());

	vector<char> bytes = CodeGenerationCommands::iadd(); //Команда
	CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());

	return res;
}

vector<char> Expression_node::generateCodeForMinus(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> leftOperand = Left->generateCode(isInsideClassMethod, constantsTable); //Уменьшаемое
	CodeGenerationHelpers::appendArrayToByteVector(&res, leftOperand.data(), leftOperand.size());

	vector<char> rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //Вычитаемое
	CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());

	vector<char> bytes = CodeGenerationCommands::isub(); //Команда
	CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());

	return res;
}

vector<char> Expression_node::generateCodeForMul(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> leftOperand = Left->generateCode(isInsideClassMethod, constantsTable); //1-ый множитель
	CodeGenerationHelpers::appendArrayToByteVector(&res, leftOperand.data(), leftOperand.size());

	vector<char> rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //2-ой множитель
	CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());

	vector<char> bytes = CodeGenerationCommands::imul(); //Команда
	CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());

	return res;
}

vector<char> Expression_node::generateCodeForDiv(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> leftOperand = Left->generateCode(isInsideClassMethod, constantsTable); //Делимое
	CodeGenerationHelpers::appendArrayToByteVector(&res, leftOperand.data(), leftOperand.size());

	vector<char> rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //Делитель
	CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());

	vector<char> bytes = CodeGenerationCommands::idiv(); //Команда
	CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());

	return res;
}

vector<char> Expression_node::generateCodeForUminus(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //Число
	CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());

	vector<char> bytes = CodeGenerationCommands::ineg(); //Команда
	CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());

	return res;
}

vector<char> Expression_node::generateCodeForUplus(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res = Right->generateCode(isInsideClassMethod, constantsTable); //Число
	return res;
}

vector<char> Expression_node::generateCodeForLiteral()
{
	vector<char> res;

	if (literal->type == CHAR_CONSTANT_TYPE) {
		vector<char> bytes = CodeGenerationCommands::iconstBipushSipush(*literal->value); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
	else if (literal->type == STRING_CONSTANT_TYPE) {
		vector<char> size = CodeGenerationCommands::iconstBipushSipush(strlen(literal->value)); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, size.data(), size.size());
		vector<char> bytes = CodeGenerationCommands::newarray(CodeGenerationCommands::T_CHAR); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
		for (int i = 0; i < strlen(literal->value); i++) {
			vector<char> dup = CodeGenerationCommands::dup(); //Дублирование ссылки на массив
			CodeGenerationHelpers::appendArrayToByteVector(&res, dup.data(), dup.size());
			vector<char> index = CodeGenerationCommands::iconstBipushSipush(i); //Индекс
			CodeGenerationHelpers::appendArrayToByteVector(&res, index.data(), index.size());
			vector<char> charValue = CodeGenerationCommands::iconstBipushSipush(literal->value[i]); //Значение
			CodeGenerationHelpers::appendArrayToByteVector(&res, charValue.data(), charValue.size());
			vector<char> aastore = CodeGenerationCommands::castore(); //Команда
			CodeGenerationHelpers::appendArrayToByteVector(&res, aastore.data(), aastore.size());
		}
	}
	else {
		vector<char> bytes = CodeGenerationCommands::ldc(literal->constant->Id); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}

	return res;
}

vector<char> Expression_node::generateCodeForEqual(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> leftOperand = Left->generateCode(isInsideClassMethod, constantsTable); //левый операнд	
	CodeGenerationHelpers::appendArrayToByteVector(&res, leftOperand.data(), leftOperand.size());

	vector<char> rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //правый операнд
	CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());

	vector<char> trueBytes = CodeGenerationCommands::iconstBipushSipush(1); //Ветка, если равны
	vector<char> falseBytes = CodeGenerationCommands::iconstBipushSipush(0); //Ветка, если не равны
	vector<char> gotoBytes = CodeGenerationCommands::goto_(falseBytes.size()); //Безусловный переход в случае положительной ветки

	int offset = trueBytes.size() + gotoBytes.size(); //Смещение, с которого начинается альтернативная ветка
	vector<char> ifBytes; //Условный переход
	if (Left->DataType->isPrimitive() && Right->DataType->isPrimitive())
		ifBytes = CodeGenerationCommands::if_icmp(CodeGenerationCommands::NE, offset);
	else 
		ifBytes = CodeGenerationCommands::if_acmp(CodeGenerationCommands::NE, offset);

	// Формирование кода
	CodeGenerationHelpers::appendArrayToByteVector(&res, ifBytes.data(), ifBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, trueBytes.data(), trueBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, gotoBytes.data(), gotoBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, falseBytes.data(), falseBytes.size());

	return res;
}

vector<char> Expression_node::generateCodeForNotEqual(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> leftOperand = Left->generateCode(isInsideClassMethod, constantsTable); //левый операнд	
	CodeGenerationHelpers::appendArrayToByteVector(&res, leftOperand.data(), leftOperand.size());

	vector<char> rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //правый операнд
	CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());

	vector<char> trueBytes = CodeGenerationCommands::iconstBipushSipush(1); //Ветка, если не равны
	vector<char> falseBytes = CodeGenerationCommands::iconstBipushSipush(0); //Ветка, если равны
	vector<char> gotoBytes = CodeGenerationCommands::goto_(falseBytes.size()); //Безусловный переход в случае положительной ветки

	int offset = trueBytes.size() + gotoBytes.size(); //Смещение, с которого начинается альтернативная ветка
	vector<char> ifBytes; //Условный переход
	if (Left->DataType->isPrimitive() && Right->DataType->isPrimitive())
		ifBytes = CodeGenerationCommands::if_icmp(CodeGenerationCommands::EQ, offset);
	else
		ifBytes = CodeGenerationCommands::if_acmp(CodeGenerationCommands::EQ, offset);

	// Формирование кода
	CodeGenerationHelpers::appendArrayToByteVector(&res, ifBytes.data(), ifBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, trueBytes.data(), trueBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, gotoBytes.data(), gotoBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, falseBytes.data(), falseBytes.size());

	return res;
}

vector<char> Expression_node::generateCodeForGreater(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> leftOperand = Left->generateCode(isInsideClassMethod, constantsTable); //левый операнд	
	CodeGenerationHelpers::appendArrayToByteVector(&res, leftOperand.data(), leftOperand.size());

	vector<char> rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //правый операнд
	CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());

	vector<char> trueBytes = CodeGenerationCommands::iconstBipushSipush(1); //Ветка, если больше
	vector<char> falseBytes = CodeGenerationCommands::iconstBipushSipush(0); //Ветка, если меньше или равно
	vector<char> gotoBytes = CodeGenerationCommands::goto_(falseBytes.size()); //Безусловный переход в случае положительной ветки

	int offset = trueBytes.size() + gotoBytes.size(); //Смещение, с которого начинается альтернативная ветка
	vector<char> ifBytes = CodeGenerationCommands::if_icmp(CodeGenerationCommands::LE, offset); //Условный переход

	// Формирование кода
	CodeGenerationHelpers::appendArrayToByteVector(&res, ifBytes.data(), ifBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, trueBytes.data(), trueBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, gotoBytes.data(), gotoBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, falseBytes.data(), falseBytes.size());

	return res;
}

vector<char> Expression_node::generateCodeForLess(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> leftOperand = Left->generateCode(isInsideClassMethod, constantsTable); //левый операнд	
	CodeGenerationHelpers::appendArrayToByteVector(&res, leftOperand.data(), leftOperand.size());

	vector<char> rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //правый операнд
	CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());

	vector<char> trueBytes = CodeGenerationCommands::iconstBipushSipush(1); //Ветка, если меньше
	vector<char> falseBytes = CodeGenerationCommands::iconstBipushSipush(0); //Ветка, если больше или равно
	vector<char> gotoBytes = CodeGenerationCommands::goto_(falseBytes.size()); //Безусловный переход в случае положительной ветки

	int offset = trueBytes.size() + gotoBytes.size(); //Смещение, с которого начинается альтернативная ветка
	vector<char> ifBytes = CodeGenerationCommands::if_icmp(CodeGenerationCommands::GE, offset); //Условный переход

	// Формирование кода
	CodeGenerationHelpers::appendArrayToByteVector(&res, ifBytes.data(), ifBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, trueBytes.data(), trueBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, gotoBytes.data(), gotoBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, falseBytes.data(), falseBytes.size());

	return res;
}

vector<char> Expression_node::generateCodeForLessEqual(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> leftOperand = Left->generateCode(isInsideClassMethod, constantsTable); //левый операнд	
	CodeGenerationHelpers::appendArrayToByteVector(&res, leftOperand.data(), leftOperand.size());

	vector<char> rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //правый операнд
	CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());

	vector<char> trueBytes = CodeGenerationCommands::iconstBipushSipush(1); //Ветка, если меньше или равно
	vector<char> falseBytes = CodeGenerationCommands::iconstBipushSipush(0); //Ветка, если больше
	vector<char> gotoBytes = CodeGenerationCommands::goto_(falseBytes.size()); //Безусловный переход в случае положительной ветки

	int offset = trueBytes.size() + gotoBytes.size(); //Смещение, с которого начинается альтернативная ветка
	vector<char> ifBytes = CodeGenerationCommands::if_icmp(CodeGenerationCommands::GT, offset); //Условный переход

	// Формирование кода
	CodeGenerationHelpers::appendArrayToByteVector(&res, ifBytes.data(), ifBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, trueBytes.data(), trueBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, gotoBytes.data(), gotoBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, falseBytes.data(), falseBytes.size());

	return res;
}

vector<char> Expression_node::generateCodeForGreaterEqual(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> leftOperand = Left->generateCode(isInsideClassMethod, constantsTable); //левый операнд	
	CodeGenerationHelpers::appendArrayToByteVector(&res, leftOperand.data(), leftOperand.size());

	vector<char> rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //правый операнд
	CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());

	vector<char> trueBytes = CodeGenerationCommands::iconstBipushSipush(1); //Ветка, если больше или равно
	vector<char> falseBytes = CodeGenerationCommands::iconstBipushSipush(0); //Ветка, если меньше
	vector<char> gotoBytes = CodeGenerationCommands::goto_(falseBytes.size()); //Безусловный переход в случае положительной ветки

	int offset = trueBytes.size() + gotoBytes.size(); //Смещение, с которого начинается альтернативная ветка
	vector<char> ifBytes = CodeGenerationCommands::if_icmp(CodeGenerationCommands::LT, offset); //Условный переход

	// Формирование кода
	CodeGenerationHelpers::appendArrayToByteVector(&res, ifBytes.data(), ifBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, trueBytes.data(), trueBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, gotoBytes.data(), gotoBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, falseBytes.data(), falseBytes.size());

	return res;
}

vector<char> Expression_node::generateCodeForMessageExpression(bool isInsideClassMethod, ConstantsTable *constantsTable)
{
	vector<char> res;

	vector<char> receiver = Receiver->generateCode(isInsideClassMethod, constantsTable); //Объект

	vector<char> messageSelector = Arguments->generateCode(isInsideClassMethod, constantsTable); //Аргументы

	

	if (constantsTable->items.count(Constant) == 0) {
		string msg = "Class doesn't have constant " + to_string(Constant);
		throw std::exception(msg.c_str());
	}
	else if (constantsTable->items[Constant]->Type != MethodRef) {
		string msg = "Constant " + to_string(Constant) + " is not methodRef";
		throw std::exception(msg.c_str());
	}
	
	if (Method->IsClassMethod) {
		CodeGenerationHelpers::appendArrayToByteVector(&res, messageSelector.data(), messageSelector.size());
		vector<char> invoke = CodeGenerationCommands::invokestatic(Constant);
		CodeGenerationHelpers::appendArrayToByteVector(&res, invoke.data(), invoke.size());
	}
	else {
		CodeGenerationHelpers::appendArrayToByteVector(&res, messageSelector.data(), messageSelector.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, receiver.data(), receiver.size());
		vector<char> invoke;
		if (Receiver->type == SUPER_RECEIVER_TYPE)
			invoke = CodeGenerationCommands::invokespecial(Constant);
		else
			invoke = CodeGenerationCommands::invokevirtual(Constant);
		CodeGenerationHelpers::appendArrayToByteVector(&res, invoke.data(), invoke.size());
	}
	

	return res;
}

vector<char> Receiver_node::generateCode(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;
	
	switch (type)
	{
	case SUPER_RECEIVER_TYPE: {
		if (!isInsideClassMethod) {
			vector<char> obj = CodeGenerationCommands::aload(LocalVariable->Id); //Объект
			CodeGenerationHelpers::appendArrayToByteVector(&res, obj.data(), obj.size());
		}
	}
		break;
	case SELF_RECEIVER_TYPE: {
		if (!isInsideClassMethod) {
			vector<char> obj = CodeGenerationCommands::aload(LocalVariable->Id); //Объект
			CodeGenerationHelpers::appendArrayToByteVector(&res, obj.data(), obj.size());
		}
	}
		break;
	case OBJECT_NAME_RECEIVER_TYPE: {
		if (LocalVariable != NULL)
		{
			vector<char> obj = CodeGenerationCommands::aload(LocalVariable->Id - isInsideClassMethod); //Объект
			CodeGenerationHelpers::appendArrayToByteVector(&res, obj.data(), obj.size());
		}
		else if (Field != NULL) {
			vector<char> obj = CodeGenerationCommands::aload(0); //Объект
			CodeGenerationHelpers::appendArrayToByteVector(&res, obj.data(), obj.size());

			string className = Receiver->DataType->ClassName;
			ConstantsTable* constantsTable = ClassesTable::items[className]->ConstantTable;
			if (constantsTable->items.count(Constant) == 0) {
				string msg = "Class " + className + " doesn't have constant " + to_string(Constant);
				throw std::exception(msg.c_str());
			}
			else if (constantsTable->items[Constant]->Type != FieldRef) {
				string msg = "Constant " + to_string(Constant) + " is not fieldRef";
				throw std::exception(msg.c_str());
			}

			vector<char> field = CodeGenerationCommands::getfield(Constant); //Поле
			CodeGenerationHelpers::appendArrayToByteVector(&res, field.data(), field.size());
		}
	}
		break;
	case CLASS_NAME_RECEIVER_TYPE: {

	}
		break;
	case MESSAGE_EXPRESSION_RECEIVER_TYPE: {
		vector<char> receiver = Receiver->generateCode(isInsideClassMethod, constantsTable); //Объект

		vector<char> messageSelector = Arguments->generateCode(isInsideClassMethod, constantsTable); //Аргументы

		

		if (constantsTable->items.count(Constant) == 0) {
			string msg = "Class doesn't have constant " + to_string(Constant);
			throw std::exception(msg.c_str());
		}
		else if (constantsTable->items[Constant]->Type != MethodRef) {
			string msg = "Constant " + to_string(Constant) + " is not methodRef";
			throw std::exception(msg.c_str());
		}

		if (Method->IsClassMethod) {
			CodeGenerationHelpers::appendArrayToByteVector(&res, messageSelector.data(), messageSelector.size());
			vector<char> invoke = CodeGenerationCommands::invokestatic(Constant);
			CodeGenerationHelpers::appendArrayToByteVector(&res, invoke.data(), invoke.size());
		}
		else {
			CodeGenerationHelpers::appendArrayToByteVector(&res, messageSelector.data(), messageSelector.size());
			CodeGenerationHelpers::appendArrayToByteVector(&res, receiver.data(), receiver.size());
			vector<char> invoke;
			if (Receiver->type == SUPER_RECEIVER_TYPE)
				invoke = CodeGenerationCommands::invokespecial(Constant);
			else
				invoke = CodeGenerationCommands::invokevirtual(Constant);
			CodeGenerationHelpers::appendArrayToByteVector(&res, invoke.data(), invoke.size());
		}
	}
		break;
	default:
		break;
	}

	return res;
}

vector<char> Message_selector_node::generateCode(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	if (FirstArgument != NULL) {
		vector<char> firstArgument = FirstArgument->generateCode(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, firstArgument.data(), firstArgument.size());
	}
	if (Arguments != NULL) {
		Keyword_argument_node* cur = Arguments->First;
		while (cur != NULL) {
			vector<char> argument = cur->expression->generateCode(isInsideClassMethod, constantsTable);
			CodeGenerationHelpers::appendArrayToByteVector(&res, argument.data(), argument.size());
			cur = cur->Next;
		}
	}
	if (ExprArguments != NULL) {
		vector<char> exprArguments = ExprArguments->generateCode(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, exprArguments.data(), exprArguments.size());
	}

	return res;
}

vector<char> Expression_list_node::generateCode(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;
	Expression_node* cur = First;
	while (cur != NULL) {
		vector<char> expression = cur->generateCode(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, expression.data(), expression.size());
		cur = cur->Next;
	}
	return res;
}
