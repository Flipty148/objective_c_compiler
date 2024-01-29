#include <fstream>
#include "tables.h"
#include "code_generation_helpers.h"
#include <iostream>
#include <string>

using namespace std;

void ClassesTable::generateClassFiles(string filepath)
{
	auto iter = items->cbegin();
	while (iter != items->cend())
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
	classFile.erase(std::remove(classFile.begin(), classFile.end(), '<'), classFile.end());
	classFile.erase(std::remove(classFile.begin(), classFile.end(), '>'), classFile.end());
	
	//Генерация .class файла
	vector<char> data;

	//Указание магических констант
	int magicConstantSize = sizeof(CodeGenerationHelpers::magicConstant)/sizeof(CodeGenerationHelpers::magicConstant[0]); //Количество элементов в магической константе
	int smallVersionSize = sizeof(CodeGenerationHelpers::smallVersion)/sizeof(CodeGenerationHelpers::smallVersion[0]); //Количество элементов в малой версии формата файла
	int bigVersionSize = sizeof(CodeGenerationHelpers::bigVersion)/sizeof(CodeGenerationHelpers::bigVersion[0]); //Количество элементов в большой версии формата файла
	CodeGenerationHelpers::appendArrayToByteVector(&data, CodeGenerationHelpers::magicConstant, magicConstantSize); //Добавление магической константы
	CodeGenerationHelpers::appendArrayToByteVector(&data, CodeGenerationHelpers::smallVersion, smallVersionSize); //Добавление малой версии формата файла
	CodeGenerationHelpers::appendArrayToByteVector(&data, CodeGenerationHelpers::bigVersion, bigVersionSize); //Добавление большой версии формата файла

	// Таблица констант
	int constantSize = ConstantTable->items.size() + 1; //Количество констант + 1
	vector<char> constantSizeBytes = CodeGenerationHelpers::intToByteArray(constantSize, 2); //Конвертация размера таблицы констант в байты
	CodeGenerationHelpers::appendArrayToByteVector(&data, constantSizeBytes.data(), constantSizeBytes.size()); //Добавление размера таблицы констант в байты
	vector<char> constantTableBytes = ConstantTable->generateBytes(); //Генерация таблицы констант
	CodeGenerationHelpers::appendArrayToByteVector(&data, constantTableBytes.data(), constantTableBytes.size()); //Добавление таблицы констант

	//Флаги доступа
	data.push_back(0x00); //Отсутствие ACC_ABSTRACT ????
	data.push_back(0x21); //ACC_SUPER + ACC_PUBLIC

	//Текущий класс
	vector<char> classNameBytes = CodeGenerationHelpers::intToByteArray(ThisClass, 2); //Конвертация имени текущего класса в байты
	CodeGenerationHelpers::appendArrayToByteVector(&data, classNameBytes.data(), classNameBytes.size()); //Добавление имени текущего класса в байты

	//Класс-родитель
	vector<char> superClassBytes = CodeGenerationHelpers::intToByteArray(Superclass, 2); //Конвертация имени родительского класса в байты
	CodeGenerationHelpers::appendArrayToByteVector(&data, superClassBytes.data(), superClassBytes.size()); //Добавление имени родительского класса в байты

	//Количество интерфейсов
	vector<char> interfaceCountBytes = CodeGenerationHelpers::intToByteArray(0, 2); //Конвертация количества интерфейсов в байты
	CodeGenerationHelpers::appendArrayToByteVector(&data, interfaceCountBytes.data(), interfaceCountBytes.size()); //Добавление количества интерфейсов в байты

	//Поля класса
	int fieldCount = Fields->items.size(); //Количество полей
	vector<char> fieldCountBytes = CodeGenerationHelpers::intToByteArray(fieldCount, 2); //Конвертация количества полей в байты
	CodeGenerationHelpers::appendArrayToByteVector(&data, fieldCountBytes.data(), fieldCountBytes.size()); //Добавление количества полей в байты
	vector<char> fieldTableBytes = Fields->generateBytes(); //Генерация таблицы полей
	CodeGenerationHelpers::appendArrayToByteVector(&data, fieldTableBytes.data(), fieldTableBytes.size()); //Добавление таблицы полей
	
	//Методы класса
	int methodCount = Methods->items.size(); //Количество методов
	vector<char> methodCountBytes = CodeGenerationHelpers::intToByteArray(methodCount, 2); //Конвертация количества методов в байты
	CodeGenerationHelpers::appendArrayToByteVector(&data, methodCountBytes.data(), methodCountBytes.size()); //Добавление количества методов в байты
	vector<char> methodTableBytes = Methods->generateBytes(ConstantTable, constructorNumber); //Генерация таблицы методов
	CodeGenerationHelpers::appendArrayToByteVector(&data, methodTableBytes.data(), methodTableBytes.size()); //Добавление таблицы методов
	
	//Атрибуты класса
	vector<char> attributeCountBytes = CodeGenerationHelpers::intToByteArray(0, 2); //Конвертация количества атрибутов в байты
	CodeGenerationHelpers::appendArrayToByteVector(&data, attributeCountBytes.data(), attributeCountBytes.size()); //Добавление количества атрибутов в байты

	ofstream out(classFile, ios::out | ios::binary); //Создание и открытие потока на запись в файл
	out.write(data.data(), data.size()); //Запись в файл
	out.close(); //Закрытие потока
}

bool ClassesTableElement::isNeedToGenerateClassFile()
{
	string className = getClassName(); //Получить имя текущего класса
	if (className == "rtl/!Program!" || className.find("rtl/") == string::npos)
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
		delete[] str;
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
vector<char> MethodsTable::generateBytes(ConstantsTable* constantsTable, int parrentInitNumber)
{
	vector<char> res;
	for (auto iter = items.cbegin(); iter != items.cend(); ++iter) {
		vector<char> bytes = iter->second->generateBytes(constantsTable, parrentInitNumber);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
	return res;
}

vector<char> MethodsTableElement::generateBytes(ConstantsTable* constantsTable, int parrentInitNumber)
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

	if (NameStr != "<init>") {
		vector<char> codeAttributeBytes = generateCodeAttribute(constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, codeAttributeBytes.data(), codeAttributeBytes.size());
	}
	else {
		vector<char> codeAttributeBytes = CodeGenerationHelpers::defaultConstructorCodeAttribute(parrentInitNumber);
		CodeGenerationHelpers::appendArrayToByteVector(&res, codeAttributeBytes.data(), codeAttributeBytes.size());
	}

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
			vector<char> bytes = curStatement->generateCode(IsClassMethod, constantsTable, LocalVariables);
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
vector<char> Statement_node::generateCode(bool isInsideClassMethod, ConstantsTable* constantsTable, LocalVariablesTable *locals)
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
		vector<char> bytes = generateCodeForIfStatement(isInsideClassMethod, constantsTable, locals);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case WHILE_STATEMENT_TYPE: {
		vector<char> bytes = generateCodeForWhileStatement(isInsideClassMethod, constantsTable, locals);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case DO_WHILE_STATEMENT_TYPE: {
		vector<char> bytes = generateCodeForDoWhileStatement(isInsideClassMethod, constantsTable, locals);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case FOR_STATEMENT_TYPE: {
		vector<char> bytes = generateCodeForForStatement(isInsideClassMethod, constantsTable, locals);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case COMPOUND_STATEMENT_TYPE: {
		vector<char> bytes = generateCodeForCompoundStatement(isInsideClassMethod, constantsTable, locals);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case DECLARATION_STATEMENT_TYPE: {
		vector<char> bytes = generateCodeForDeclarationStatement(isInsideClassMethod, constantsTable, locals);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
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

vector<char> Statement_node::generateCodeForDeclarationStatement(bool isInsideClassMethod, ConstantsTable* constantsTable, LocalVariablesTable *locals)
{
	vector<char> res;

	Declaration_node* declaration = (Declaration_node*)this;
	Init_declarator_node* initDeclarator = declaration->init_declarator_list->First;

	while (initDeclarator != NULL) {
		
		vector<char> bytes = initDeclarator->generateCodeForInitDeclarator(isInsideClassMethod, constantsTable, locals);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());

		initDeclarator = initDeclarator->Next;
	}

	return res;
}

vector<char> Init_declarator_node::generateCodeForInitDeclarator(bool isInsideClassMethod, ConstantsTable* constantsTable, LocalVariablesTable* locals)
{
	vector <char> res;

	LocalVariablesTableElement* local = locals->items[Declarator]; //Локальная переменная
	Type* dataType = local->type; //Тип локальной переменной
	if (dataType->DataType == INT_TYPE) { //Тип int
		if (dataType->ArrSize == NULL) { //Не является массивом
			vector<char> expr;
			if (expression != NULL) { //Указано начальное значение
				expr = expression->generateCode(isInsideClassMethod, constantsTable);
				CodeGenerationHelpers::appendArrayToByteVector(&res, expr.data(), expr.size()); //Загрузить expression (значение)
			}
			else { //Не указано начальное значение
				expr = CodeGenerationCommands::iconstBipushSipush(0);
				CodeGenerationHelpers::appendArrayToByteVector(&res, expr.data(), expr.size());
			}
			vector<char> istore = CodeGenerationCommands::istore(local->Id - isInsideClassMethod);
			CodeGenerationHelpers::appendArrayToByteVector(&res, istore.data(), istore.size());
		}
		else { //Является массивом
			vector<char> arrSize = dataType->ArrSize->generateCode(isInsideClassMethod, constantsTable);
			CodeGenerationHelpers::appendArrayToByteVector(&res, arrSize.data(), arrSize.size());
			vector<char> array = CodeGenerationCommands::newarray(CodeGenerationCommands::T_INT);
			CodeGenerationHelpers::appendArrayToByteVector(&res, array.data(), array.size());
			vector<char> astore = CodeGenerationCommands::astore(local->Id - isInsideClassMethod);
			CodeGenerationHelpers::appendArrayToByteVector(&res, astore.data(), astore.size());
			if (InitializerList != NULL) {
				vector<char> aload = CodeGenerationCommands::aload(local->Id - isInsideClassMethod);
				CodeGenerationHelpers::appendArrayToByteVector(&res, aload.data(), aload.size());

				Expression_node* cur = InitializerList->First;
				int i = 0;
				while (cur != NULL) {
					vector<char> dup = CodeGenerationCommands::dup(); //Дублирование ссылки на массив
					CodeGenerationHelpers::appendArrayToByteVector(&res, dup.data(), dup.size());
					vector<char> index = CodeGenerationCommands::iconstBipushSipush(i); //Индекс
					CodeGenerationHelpers::appendArrayToByteVector(&res, index.data(), index.size());
					vector<char> bytes = cur->generateCode(isInsideClassMethod, constantsTable); //Значение
					CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
					vector<char> iastore = CodeGenerationCommands::iastore(); //Команда
					CodeGenerationHelpers::appendArrayToByteVector(&res, iastore.data(), iastore.size());

					i++;
					cur = cur->Next;
				}
			}

		}
	}
	else if (dataType->DataType == CHAR_TYPE) { //Тип char
		if (dataType->ArrSize == NULL) { //Не является массивом
			vector<char> expr;
			if (expression != NULL) { //Указано начальное значение
				expr = expression->generateCode(isInsideClassMethod, constantsTable);
				CodeGenerationHelpers::appendArrayToByteVector(&res, expr.data(), expr.size()); //Загрузить expression (значение)
			}
			else { //Не указано начальное значение
				expr = CodeGenerationCommands::iconstBipushSipush(0);
				CodeGenerationHelpers::appendArrayToByteVector(&res, expr.data(), expr.size());
			}
			vector<char> istore = CodeGenerationCommands::istore(local->Id - isInsideClassMethod);
			CodeGenerationHelpers::appendArrayToByteVector(&res, istore.data(), istore.size());
		}
		else { //Является массивом
			vector<char> arrSize = dataType->ArrSize->generateCode(isInsideClassMethod, constantsTable);
			CodeGenerationHelpers::appendArrayToByteVector(&res, arrSize.data(), arrSize.size());
			vector<char> array = CodeGenerationCommands::newarray(CodeGenerationCommands::T_CHAR);
			CodeGenerationHelpers::appendArrayToByteVector(&res, array.data(), array.size());
			vector<char> astore = CodeGenerationCommands::astore(local->Id - isInsideClassMethod);
			CodeGenerationHelpers::appendArrayToByteVector(&res, astore.data(), astore.size());
			if (expression != NULL) {
				vector<char> aload = CodeGenerationCommands::aload(local->Id - isInsideClassMethod);
				CodeGenerationHelpers::appendArrayToByteVector(&res, aload.data(), aload.size());

				Literal_node* literal = expression->literal;
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
			else if (InitializerList != NULL) {
				vector<char> aload = CodeGenerationCommands::aload(local->Id - isInsideClassMethod);
				CodeGenerationHelpers::appendArrayToByteVector(&res, aload.data(), aload.size());

				Expression_node* cur = InitializerList->First;
				int i = 0;
				while (cur != NULL) {
					vector<char> dup = CodeGenerationCommands::dup(); //Дублирование ссылки на массив
					CodeGenerationHelpers::appendArrayToByteVector(&res, dup.data(), dup.size());
					vector<char> index = CodeGenerationCommands::iconstBipushSipush(i); //Индекс
					CodeGenerationHelpers::appendArrayToByteVector(&res, index.data(), index.size());
					vector<char> bytes = cur->generateCode(isInsideClassMethod, constantsTable); //Значение
					CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
					vector<char> castore = CodeGenerationCommands::castore(); //Команда
					CodeGenerationHelpers::appendArrayToByteVector(&res, castore.data(), castore.size());

					i++;
					cur = cur->Next;
				}

			}
		}
	}
	else if (dataType->DataType == CLASS_NAME_TYPE || dataType->DataType == ID_TYPE) { //Тип класса
		if (dataType->ArrSize == NULL) { //Не является массивом

			

			if (expression != NULL) { //Указано начальное значение
				vector<char> expr = expression->generateCode(isInsideClassMethod, constantsTable);
				CodeGenerationHelpers::appendArrayToByteVector(&res, expr.data(), expr.size()); //Загрузить expression (значение)
			}

			else { //Не указано начальное значение
				// Поиск константы с создаваемым классом
				int constUtf = constantsTable->findConstant(UTF8, &dataType->ClassName);
				int constClass = constantsTable->findConstant(Class, NULL, NULL, constUtf);

				vector<char> bytes = CodeGenerationCommands::new_(constClass); // Создание объекта
				CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
				vector<char> dup = CodeGenerationCommands::dup();
				CodeGenerationHelpers::appendArrayToByteVector(&res, dup.data(), dup.size());
				vector<char> aconstNull = CodeGenerationCommands::aconst_null();
				CodeGenerationHelpers::appendArrayToByteVector(&res, aconstNull.data(), aconstNull.size());
			}

			vector<char> astore = CodeGenerationCommands::astore(local->Id - isInsideClassMethod);
			CodeGenerationHelpers::appendArrayToByteVector(&res, astore.data(), astore.size());
		}
		else { //Является массивом
			// Поиск константы с создаваемым классом
			int constUtf = constantsTable->findConstant(UTF8, &dataType->ClassName);
			int constClass = constantsTable->findConstant(Class, NULL, NULL, constUtf);

			vector<char> arrSize = dataType->ArrSize->generateCode(isInsideClassMethod, constantsTable);
			CodeGenerationHelpers::appendArrayToByteVector(&res, arrSize.data(), arrSize.size());
			vector<char> array = CodeGenerationCommands::anewarray(constClass);
			CodeGenerationHelpers::appendArrayToByteVector(&res, array.data(), array.size());
			vector<char> astore = CodeGenerationCommands::astore(local->Id - isInsideClassMethod);
			CodeGenerationHelpers::appendArrayToByteVector(&res, astore.data(), astore.size());

			if (InitializerList != NULL) {
				vector<char> aload = CodeGenerationCommands::aload(local->Id - isInsideClassMethod);
				CodeGenerationHelpers::appendArrayToByteVector(&res, aload.data(), aload.size());

				Expression_node* cur = InitializerList->First;
				int i = 0;
				while (cur != NULL) {
					vector<char> dup = CodeGenerationCommands::dup(); //Дублирование ссылки на массив
					CodeGenerationHelpers::appendArrayToByteVector(&res, dup.data(), dup.size());
					vector<char> index = CodeGenerationCommands::iconstBipushSipush(i); //Индекс
					CodeGenerationHelpers::appendArrayToByteVector(&res, index.data(), index.size());
					vector<char> bytes = cur->generateCode(isInsideClassMethod, constantsTable); //Значение
					CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
					vector<char> aastore = CodeGenerationCommands::aastore(); //Команда
					CodeGenerationHelpers::appendArrayToByteVector(&res, aastore.data(), aastore.size());

					i++;
					cur = cur->Next;
				}

			}

		}
	}

	return res;
}

vector<char> Statement_node::generateCodeForIfStatement(bool isInsideClassMethod, ConstantsTable* constantsTable, LocalVariablesTable* locals)
{
	vector<char> res;
	
	If_statement_node* if_stmt = (If_statement_node*)this;

	vector<char> condition = if_stmt->Condition->generateCode(isInsideClassMethod, constantsTable); //Условие
	CodeGenerationHelpers::appendArrayToByteVector(&res, condition.data(), condition.size());

	vector<char> trueBytes;
	vector<char> falseBytes;
	vector<char> gotoBytes;

	if (if_stmt->TrueBranch != NULL)
		trueBytes = if_stmt->TrueBranch->generateCode(isInsideClassMethod, constantsTable, locals);

	if (if_stmt->FalseBranch != NULL) {
		falseBytes = if_stmt->FalseBranch->generateCode(isInsideClassMethod, constantsTable, locals);
		gotoBytes = CodeGenerationCommands::goto_(falseBytes.size());
	}

	int offset = trueBytes.size() + gotoBytes.size();
	vector<char> ifBytes;
	if (if_stmt->Condition->DataType->isPrimitive()) {
		ifBytes = CodeGenerationCommands::if_(CodeGenerationCommands::EQ, offset);
	}
	else {
		vector<char> aconst_null = CodeGenerationCommands::aconst_null(); //Загрузка null для сравнения объекта
		CodeGenerationHelpers::appendArrayToByteVector(&res, aconst_null.data(), aconst_null.size());
		ifBytes = CodeGenerationCommands::if_acmp(CodeGenerationCommands::EQ, offset);
	}


	// Формирование кода
	CodeGenerationHelpers::appendArrayToByteVector(&res, ifBytes.data(), ifBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, trueBytes.data(), trueBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, gotoBytes.data(), gotoBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, falseBytes.data(), falseBytes.size());

	return res;
}

vector<char> Statement_node::generateCodeForCompoundStatement(bool isInsideClassMethod, ConstantsTable* constantsTable, LocalVariablesTable* locals)
{
	vector<char> res;
	
	Statement_list_node* statements = (Statement_list_node*)this;
	
	Statement_node* cur = statements->First;
	while (cur != NULL) {
		vector<char> bytes = cur->generateCode(isInsideClassMethod, constantsTable, locals);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
		cur = cur->Next;
	}

	return res;
}

vector<char> Statement_node::generateCodeForWhileStatement(bool isInsideClassMethod, ConstantsTable* constantsTable, LocalVariablesTable* locals)
{
	vector<char> res;

	While_statement_node* while_stmt = (While_statement_node*)this;

	vector<char> bodyBytes = while_stmt->LoopBody->generateCode(isInsideClassMethod, constantsTable, locals);
	vector<char> gotoBytes = CodeGenerationCommands::goto_(bodyBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, gotoBytes.data(), gotoBytes.size());
	CodeGenerationHelpers::appendArrayToByteVector(&res, bodyBytes.data(), bodyBytes.size());

	vector<char> conditionBytes = while_stmt->LoopCondition->generateCode(isInsideClassMethod, constantsTable); //Условие
	CodeGenerationHelpers::appendArrayToByteVector(&res, conditionBytes.data(), conditionBytes.size());

	int offset = bodyBytes.size() + conditionBytes.size();
	offset = -offset;
	vector<char> ifBytes;
	if (while_stmt->LoopCondition->DataType->isPrimitive()) {
		ifBytes = CodeGenerationCommands::if_(CodeGenerationCommands::NE, offset);
	}
	else {
		vector<char> aconst_null = CodeGenerationCommands::aconst_null(); //Загрузка null для сравнения объекта
		CodeGenerationHelpers::appendArrayToByteVector(&res, aconst_null.data(), aconst_null.size());
		ifBytes = CodeGenerationCommands::if_acmp(CodeGenerationCommands::NE, offset);
	}

	CodeGenerationHelpers::appendArrayToByteVector(&res, ifBytes.data(), ifBytes.size());
	

	return res;
}

vector<char> Statement_node::generateCodeForDoWhileStatement(bool isInsideClassMethod, ConstantsTable* constantsTable, LocalVariablesTable* locals)
{
	vector<char> res;

	Do_while_statement_node* do_while_stmt = (Do_while_statement_node*)this;

	vector<char> bodyBytes = do_while_stmt->LoopBody->generateCode(isInsideClassMethod, constantsTable, locals);
	CodeGenerationHelpers::appendArrayToByteVector(&res, bodyBytes.data(), bodyBytes.size());

	vector<char> conditionBytes = do_while_stmt->LoopCondition->generateCode(isInsideClassMethod, constantsTable); //Условие
	CodeGenerationHelpers::appendArrayToByteVector(&res, conditionBytes.data(), conditionBytes.size());

	int offset = bodyBytes.size() + conditionBytes.size();
	offset = -offset;
	vector<char> ifBytes;
	if (do_while_stmt->LoopCondition->DataType->isPrimitive()) {
		ifBytes = CodeGenerationCommands::if_(CodeGenerationCommands::NE, offset);
	}
	else {
		vector<char> aconst_null = CodeGenerationCommands::aconst_null(); //Загрузка null для сравнения объекта
		CodeGenerationHelpers::appendArrayToByteVector(&res, aconst_null.data(), aconst_null.size());
		ifBytes = CodeGenerationCommands::if_acmp(CodeGenerationCommands::NE, offset);
	}

	CodeGenerationHelpers::appendArrayToByteVector(&res, ifBytes.data(), ifBytes.size());

	return res;
}

vector<char> Statement_node::generateCodeForForStatement(bool isInsideClassMethod, ConstantsTable* constantsTable, LocalVariablesTable* locals)
{
	vector<char> res;
	For_statement_node* for_stmt = (For_statement_node*)this;
	int num;
	int arrNum;

	// Инициализация
	if (for_stmt->ForType == FOR_FOR_TYPE) {
		vector<char> initBytes = for_stmt->InitExpression->generateCode(isInsideClassMethod, constantsTable); // Инициализация
		CodeGenerationHelpers::appendArrayToByteVector(&res, initBytes.data(), initBytes.size());
	}
	else if (for_stmt->ForType == FOR_WITH_DECLARATION_FOR_TYPE) {
		Init_declarator_node* initDeclarator = for_stmt->InitList->First;
		while (initDeclarator != NULL) {
			vector<char> bytes = initDeclarator->generateCodeForInitDeclarator(isInsideClassMethod, constantsTable, locals);
			CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
			initDeclarator = initDeclarator->Next;
		}
	}
	else if (for_stmt->ForType == FOREACH_FOR_TYPE) {
		num = locals->items["<iterator" + to_string(for_stmt->id) + ">"]->Id - isInsideClassMethod;
		arrNum = locals->items["<array" + to_string(for_stmt->id) + ">"]->Id - isInsideClassMethod;
		vector<char> initValue = CodeGenerationCommands::iconstBipushSipush(0); // Инициализация
		CodeGenerationHelpers::appendArrayToByteVector(&res, initValue.data(), initValue.size());
		vector<char> initBytes = CodeGenerationCommands::istore(num); // Инициализация
		CodeGenerationHelpers::appendArrayToByteVector(&res, initBytes.data(), initBytes.size());
	}
	else if (for_stmt->ForType == FOREACH_WITH_DECLARATION_FOR_TYPE) {
		LocalVariablesTableElement* local = locals->items[for_stmt->name];
		num = locals->items["<iterator" + to_string(for_stmt->id) + ">"]->Id - isInsideClassMethod;
		arrNum = locals->items["<array" + to_string(for_stmt->id) + ">"]->Id - isInsideClassMethod;
		vector<char> initValue = CodeGenerationCommands::iconstBipushSipush(0); // Инициализация
		CodeGenerationHelpers::appendArrayToByteVector(&res, initValue.data(), initValue.size());
		vector<char> initBytes = CodeGenerationCommands::istore(num); // Инициализация
		CodeGenerationHelpers::appendArrayToByteVector(&res, initBytes.data(), initBytes.size());
		
		// Поиск константы с создаваемым классом
		string className = for_stmt->NameType->ClassName;
		int constUtf = constantsTable->findConstant(UTF8, &className);
		int constClass = constantsTable->findConstant(Class, NULL, NULL, constUtf);

		vector<char> bytes = CodeGenerationCommands::new_(constClass); // Создание объекта
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
		vector<char> dup = CodeGenerationCommands::dup();
		CodeGenerationHelpers::appendArrayToByteVector(&res, dup.data(), dup.size());
		vector<char> aconstNull = CodeGenerationCommands::aconst_null();
		CodeGenerationHelpers::appendArrayToByteVector(&res, aconstNull.data(), aconstNull.size());

		vector<char> astore = CodeGenerationCommands::astore(local->Id - isInsideClassMethod);
		CodeGenerationHelpers::appendArrayToByteVector(&res, astore.data(), astore.size());
	}

	if (for_stmt->ForType == FOR_FOR_TYPE || for_stmt->ForType == FOR_WITH_DECLARATION_FOR_TYPE) {
		vector<char> bodyBytes = for_stmt->LoopBody->generateCode(isInsideClassMethod, constantsTable, locals); // Тело цикла
		vector<char> loopExpression = for_stmt->LoopExpression->generateCode(isInsideClassMethod, constantsTable); // Выражение цикла
		vector<char> gotoBytes = CodeGenerationCommands::goto_(bodyBytes.size() + loopExpression.size()); // Переход к условию цикла
		CodeGenerationHelpers::appendArrayToByteVector(&res, gotoBytes.data(), gotoBytes.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, bodyBytes.data(), bodyBytes.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, loopExpression.data(), loopExpression.size());

		vector<char> conditionBytes = for_stmt->ConditionExpression->generateCode(isInsideClassMethod, constantsTable); //Условие
		CodeGenerationHelpers::appendArrayToByteVector(&res, conditionBytes.data(), conditionBytes.size());

		int offset = bodyBytes.size() + conditionBytes.size() + loopExpression.size();
		offset = -offset;
		vector<char> ifBytes;
		if (for_stmt->ConditionExpression->DataType->isPrimitive()) {
			ifBytes = CodeGenerationCommands::if_(CodeGenerationCommands::NE, offset);
		}
		else {
			vector<char> aconst_null = CodeGenerationCommands::aconst_null(); //Загрузка null для сравнения объекта
			CodeGenerationHelpers::appendArrayToByteVector(&res, aconst_null.data(), aconst_null.size());
			ifBytes = CodeGenerationCommands::if_acmp(CodeGenerationCommands::NE, offset);
		}

		CodeGenerationHelpers::appendArrayToByteVector(&res, ifBytes.data(), ifBytes.size());
	}
	else {
		vector<char> arr = for_stmt->ConditionExpression->generateCode(isInsideClassMethod, constantsTable); //Объект
		int cloneConstant = constantsTable->findOrAddMethodRefConstant("rtl/NSArray", "arrayWithArrayStatic", "(Lrtl/NSArray;)Lrtl/NSArray;");
		vector<char> cloneInvoke = CodeGenerationCommands::invokestatic(cloneConstant); //Клонирование
		vector<char> cloneStore = CodeGenerationCommands::astore(arrNum); //Сохранение
		vector<char> cloneLoad = CodeGenerationCommands::aload(arrNum); //Загрузка
		
		vector<char> iload = CodeGenerationCommands::iload(num); //Индекс

		int constant = constantsTable->findOrAddMethodRefConstant("rtl/NSArray", "objectAtIndexDynamic", "(I)Lrtl/NSObject;");
		vector<char> value = CodeGenerationCommands::invokevirtual(constant); //Значение

		int valLocal = locals->items[for_stmt->name]->Id - isInsideClassMethod;
		vector<char> astore = CodeGenerationCommands::astore(valLocal); //Сохранение
		
		vector<char> bodyBytes;
		if (for_stmt->LoopBody != NULL)
			bodyBytes = for_stmt->LoopBody->generateCode(isInsideClassMethod, constantsTable, locals); // Тело цикла
		vector<char> incIter = CodeGenerationCommands::iinc(num, 1); // Инкремент
		int gotoOffset = cloneLoad.size() + iload.size() + value.size() + astore.size() + bodyBytes.size() + incIter.size();
		vector<char> gotoBytes = CodeGenerationCommands::goto_(gotoOffset); // Переход к условию цикла
		CodeGenerationHelpers::appendArrayToByteVector(&res, arr.data(), arr.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, cloneInvoke.data(), cloneInvoke.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, cloneStore.data(), cloneStore.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, gotoBytes.data(), gotoBytes.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, cloneLoad.data(), cloneLoad.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, iload.data(), iload.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, value.data(), value.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, astore.data(), astore.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, bodyBytes.data(), bodyBytes.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, incIter.data(), incIter.size());

		
		CodeGenerationHelpers::appendArrayToByteVector(&res, iload.data(), iload.size()); //Текущее значение итератора
		int sizeConst = constantsTable->findOrAddMethodRefConstant("rtl/NSArray", "countDynamic", "()I");
		vector<char> invokeVirtual = CodeGenerationCommands::invokevirtual(sizeConst); //Размер массива
		CodeGenerationHelpers::appendArrayToByteVector(&res, cloneLoad.data(), cloneLoad.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, invokeVirtual.data(), invokeVirtual.size());
		
		int offset = cloneLoad.size() + iload.size() + value.size() + astore.size() + bodyBytes.size() + incIter.size() + iload.size() + cloneLoad.size() + invokeVirtual.size();
		offset = -offset;
		vector<char> ifBytes;
		ifBytes = CodeGenerationCommands::if_icmp(CodeGenerationCommands::LT, offset);
		CodeGenerationHelpers::appendArrayToByteVector(&res, ifBytes.data(), ifBytes.size());
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
		vector<char> bytes = generateCodeForIdentifier(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
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
		if (!isInsideClassMethod) {
			vector<char> bytes = generateCodeForSelf();
			CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
		}
	}
		break;
	case SUPER_EXPRESSION_TYPE: {
		if (!isInsideClassMethod) {
			vector<char> bytes = generateCodeForSuper();
			CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
		}
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
		vector<char> bytes = generateCodeForAssignment(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case ARROW_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForArrow(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case ARRAY_ELEMENT_ACCESS_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForArrayElementAccess(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case ARRAY_ASSIGNMENT_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForArrayAssignment(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case MEMBER_ACCESS_ASSIGNMENT_EXPRESSION_TYPE: {
		vector<char> bytes = generateCodeForMemberAccessAssignment(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case CHAR_CAST: {
		vector<char> bytes = generateCodeForCharCast(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case INT_CAST: {
		vector<char> bytes = generateCodeForIntCast(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
		break;
	case CLASS_CAST: {
		vector<char> bytes = generateCodeForClassCast(isInsideClassMethod, constantsTable);
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
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

	if (number >= -32768 && number <= 32767) { //Число занимает до 2-х байт
		vector<char> bytes = CodeGenerationCommands::iconstBipushSipush(number); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
	else { //Число занимает более 2-х байт
		if (num->constant == -1) {
			string msg = string("Constant for number '") + to_string(num->Int) + "' doesn't exist";
			throw new std::exception(msg.c_str());
		}
		vector <char> bytes = CodeGenerationCommands::ldc(num->constant); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}

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

	if (Left->type != SUPER_EXPRESSION_TYPE && Left->type != SELF_EXPRESSION_TYPE && Right->type != SUPER_EXPRESSION_TYPE && Right->type != SELF_EXPRESSION_TYPE) {
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
	}
	else {
		if (Left->type == Right->type)
			res = CodeGenerationCommands::iconstBipushSipush(1);
		else
			res = CodeGenerationCommands::iconstBipushSipush(0);
	}

	return res;
}

vector<char> Expression_node::generateCodeForNotEqual(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	if (Left->type != SUPER_EXPRESSION_TYPE && Left->type != SELF_EXPRESSION_TYPE && Right->type != SUPER_EXPRESSION_TYPE && Right->type != SELF_EXPRESSION_TYPE) {
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
	}
	else {
		if (Left->type != Right->type)
			res = CodeGenerationCommands::iconstBipushSipush(1);
		else
			res = CodeGenerationCommands::iconstBipushSipush(0);
	}

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
	

	if (isInitMethod) {
		int utf = constantsTable->findConstant(UTF8, &Receiver->DataType->ClassName);
		int classConst = constantsTable->findConstant(Class, NULL, NULL, utf);
		vector<char> newBytes = CodeGenerationCommands::new_(classConst);
		CodeGenerationHelpers::appendArrayToByteVector(&res, newBytes.data(), newBytes.size());
		vector<char> dupBytes = CodeGenerationCommands::dup();
		CodeGenerationHelpers::appendArrayToByteVector(&res, dupBytes.data(), dupBytes.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, receiver.data(), receiver.size());
		CodeGenerationHelpers::appendArrayToByteVector(&res, messageSelector.data(), messageSelector.size());
		vector<char> invoke = CodeGenerationCommands::invokespecial(Constant);
		CodeGenerationHelpers::appendArrayToByteVector(&res, invoke.data(), invoke.size());
	}
	else {
		if (Method->IsClassMethod) {
			CodeGenerationHelpers::appendArrayToByteVector(&res, messageSelector.data(), messageSelector.size());
			vector<char> invoke = CodeGenerationCommands::invokestatic(Constant);
			CodeGenerationHelpers::appendArrayToByteVector(&res, invoke.data(), invoke.size());
		}
		else {
			CodeGenerationHelpers::appendArrayToByteVector(&res, receiver.data(), receiver.size());
			CodeGenerationHelpers::appendArrayToByteVector(&res, messageSelector.data(), messageSelector.size());
			vector<char> invoke;
			if (Receiver->type == SUPER_RECEIVER_TYPE)
				invoke = CodeGenerationCommands::invokespecial(Constant);
			else
				invoke = CodeGenerationCommands::invokevirtual(Constant);
			CodeGenerationHelpers::appendArrayToByteVector(&res, invoke.data(), invoke.size());
		}
	}
	

	return res;
}

vector<char> Expression_node::generateCodeForIdentifier(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;
	if (LocalVariable != NULL) { //Локальная переменная
		vector<char> bytes;
		if (DataType->ClassName != "" || DataType->ArrSize != NULL)
			bytes = CodeGenerationCommands::aload(LocalVariable->Id - isInsideClassMethod); //Команда
		else
			bytes = CodeGenerationCommands::iload(LocalVariable->Id - isInsideClassMethod); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
	else if (Field != NULL) {
		vector<char> obj = CodeGenerationCommands::aload(0); //Объект
		CodeGenerationHelpers::appendArrayToByteVector(&res, obj.data(), obj.size());

		if (constantsTable->items.count(Constant) == 0) {
			string msg = "Class doesn't have constant " + to_string(Constant);
			throw new std::exception(msg.c_str());
		}

		vector<char> field = CodeGenerationCommands::getfield(Constant); //Поле
		CodeGenerationHelpers::appendArrayToByteVector(&res, field.data(), field.size());
	}
	else {
		string msg = "Unknown identifier '" + string(name);
		throw new std::exception(msg.c_str());
	}
	return res;
}

vector<char> Expression_node::generateCodeForSelf()
{
	vector<char> res = CodeGenerationCommands::aload(LocalVariable->Id);
	return res;
}

vector<char> Expression_node::generateCodeForSuper()
{
	vector<char> res = CodeGenerationCommands::aload(LocalVariable->Id);
	return res;
}

vector<char> Expression_node::generateCodeForAssignment(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	if (Left->DataType->ClassName != "") { //Объект
		if (Left->LocalVariable != NULL) { //Запись в локальную переменную
			vector<char>rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //Левая часть выражения
			CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());
			vector<char> bytes = CodeGenerationCommands::astore(Left->LocalVariable->Id - isInsideClassMethod); //Команда
			CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
		}
		else if (Left->Field != NULL) { //Запись в поле
			vector<char> obj = CodeGenerationCommands::aload(0); //Объект
			CodeGenerationHelpers::appendArrayToByteVector(&res, obj.data(), obj.size());

			if (constantsTable->items.count(Left->Constant) == 0) {
				string msg = "Class doesn't have constant " + to_string(Constant);
				throw new std::exception(msg.c_str());
			}
			else if (constantsTable->items[Left->Constant]->Type != FieldRef) {
				string msg = "Constant " + to_string(Left->Constant) + " is not fieldRef";
				throw new std::exception(msg.c_str());
			}
			vector<char>rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //Левая часть выражения
			CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());

			vector<char> field = CodeGenerationCommands::putfield(Left->Constant); //Поле
			CodeGenerationHelpers::appendArrayToByteVector(&res, field.data(), field.size());
		}
		else {
			string msg = "Unknown identifier '" + string(name);
			throw new std::exception(msg.c_str());
		}
	}
	else { //Целое число
		if (Left->LocalVariable != NULL) {//Запись в локальную переменную
			vector<char>rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //Левая часть выражения
			CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());
			vector<char> bytes = CodeGenerationCommands::istore(Left->LocalVariable->Id - isInsideClassMethod); //Команда
			CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
		}
		else if (Left->Field != NULL) { //Запись в поле
			vector<char> obj = CodeGenerationCommands::aload(0); //Объект
			CodeGenerationHelpers::appendArrayToByteVector(&res, obj.data(), obj.size());

			if (constantsTable->items.count(Left->Constant) == 0) {
				string msg = "Class doesn't have constant " + to_string(Constant);
				throw new std::exception(msg.c_str());
			}
			else if (constantsTable->items[Left->Constant]->Type != FieldRef) {
				string msg = "Constant " + to_string(Left->Constant) + " is not fieldRef";
				throw new std::exception(msg.c_str());
			}
			vector<char>rightOperand = Right->generateCode(isInsideClassMethod, constantsTable); //Левая часть выражения
			CodeGenerationHelpers::appendArrayToByteVector(&res, rightOperand.data(), rightOperand.size());

			vector<char> field = CodeGenerationCommands::putfield(Left->Constant); //Поле
			CodeGenerationHelpers::appendArrayToByteVector(&res, field.data(), field.size());
		}
		else {
			string msg = "Unknown identifier '" + string(name);
			throw new std::exception(msg.c_str());
		}
	}

	return res;
}

vector<char> Expression_node::generateCodeForArrow(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	if (Field != NULL) {
		vector<char> obj = Left->generateCode(isInsideClassMethod, constantsTable); //Объект
		CodeGenerationHelpers::appendArrayToByteVector(&res, obj.data(), obj.size());

		if (constantsTable->items.count(Constant) == 0) {
			string msg = "Class doesn't have constant " + to_string(Constant);
			throw new std::exception(msg.c_str());
		}
		else if (constantsTable->items[Constant]->Type != FieldRef) {
			string msg = "Constant " + to_string(Constant) + " is not fieldRef";
			throw new std::exception(msg.c_str());
		}

		vector<char> field = CodeGenerationCommands::getfield(Constant); //Поле
		CodeGenerationHelpers::appendArrayToByteVector(&res, field.data(), field.size());
	}
	else {
		string msg = "Unknown identifier '" + string(name);
		throw new std::exception(msg.c_str());
	}

	return res;
}

vector<char> Expression_node::generateCodeForArrayElementAccess(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> arr = Left->generateCode(isInsideClassMethod, constantsTable); //ссылка на Массив
	CodeGenerationHelpers::appendArrayToByteVector(&res, arr.data(), arr.size());
	
	vector<char> index = Right->generateCode(isInsideClassMethod, constantsTable); //индекс
	CodeGenerationHelpers::appendArrayToByteVector(&res, index.data(), index.size());

	if (DataType->DataType == INT_TYPE) {
		vector<char> bytes = CodeGenerationCommands::iaload(); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
	else if (DataType->DataType == CHAR_TYPE) {
		vector<char> bytes = CodeGenerationCommands::caload(); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
	else if (DataType->DataType == CLASS_NAME_TYPE || DataType->DataType == ID_TYPE) {
		vector<char> bytes = CodeGenerationCommands::aaload(); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}


	return res;
}

vector<char> Expression_node::generateCodeForArrayAssignment(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	vector<char> arr = Left->generateCode(isInsideClassMethod, constantsTable); //ссылка на Массив
	CodeGenerationHelpers::appendArrayToByteVector(&res, arr.data(), arr.size());

	vector<char> index = Child->generateCode(isInsideClassMethod, constantsTable); //индекс
	CodeGenerationHelpers::appendArrayToByteVector(&res, index.data(), index.size());

	vector<char> value = Right->generateCode(isInsideClassMethod, constantsTable); //значение
	CodeGenerationHelpers::appendArrayToByteVector(&res, value.data(), value.size());

	if (DataType->DataType == INT_TYPE) {
		vector<char> bytes = CodeGenerationCommands::iastore(); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
	else if (DataType->DataType == CHAR_TYPE) {
		vector<char> bytes = CodeGenerationCommands::castore(); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}
	else if (DataType->DataType == CLASS_NAME_TYPE || DataType->DataType == ID_TYPE) {
		vector<char> bytes = CodeGenerationCommands::aastore(); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}

	return res;
}

vector<char> Expression_node::generateCodeForMemberAccessAssignment(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	if (Field != NULL) {
		vector<char> obj = Left->generateCode(isInsideClassMethod, constantsTable); //Ссылка на Объект
		CodeGenerationHelpers::appendArrayToByteVector(&res, obj.data(), obj.size());

		vector<char> value = Right->generateCode(isInsideClassMethod, constantsTable); //Значение
		CodeGenerationHelpers::appendArrayToByteVector(&res, value.data(), value.size());

		if (constantsTable->items.count(Constant) == 0) {
			string msg = "Class doesn't have constant " + to_string(Constant);
			throw new std::exception(msg.c_str());
		}
		else if (constantsTable->items[Constant]->Type != FieldRef) {
			string msg = "Constant " + to_string(Constant) + " is not fieldRef";
			throw new std::exception(msg.c_str());
		}

		vector<char> bytes = CodeGenerationCommands::putfield(Constant); //Команда
		CodeGenerationHelpers::appendArrayToByteVector(&res, bytes.data(), bytes.size());
	}

	return res;
}

vector<char> Expression_node::generateCodeForCharCast(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;


	if (Right->DataType->isCastableTo(DataType)) {
		vector<char> value = Right->generateCode(isInsideClassMethod, constantsTable); //Значение
		CodeGenerationHelpers::appendArrayToByteVector(&res, value.data(), value.size());
	}
	else {
		string msg = "Cannot cast " + Right->DataType->ClassName + " to " + DataType->ClassName;
		throw new std::exception(msg.c_str());
	}

	return res;
}

vector<char> Expression_node::generateCodeForIntCast(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	if (Right->DataType->isCastableTo(DataType)) {
		vector<char> value = Right->generateCode(isInsideClassMethod, constantsTable); //Значение
		CodeGenerationHelpers::appendArrayToByteVector(&res, value.data(), value.size());
	}
	else {
		string msg = "Cannot cast " + Right->DataType->ClassName + " to " + DataType->ClassName;
		throw new std::exception(msg.c_str());
	}

	return res;
}

vector<char> Expression_node::generateCodeForClassCast(bool isInsideClassMethod, ConstantsTable* constantsTable)
{
	vector<char> res;

	if (Right->DataType->isCastableTo(DataType)) {
		vector<char> value = Right->generateCode(isInsideClassMethod, constantsTable); //Значение
		CodeGenerationHelpers::appendArrayToByteVector(&res, value.data(), value.size());
	}
	else {
		string msg = "Cannot cast " + Right->DataType->ClassName + " to " + DataType->ClassName;
		throw new std::exception(msg.c_str());
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
			ConstantsTable* constantsTable = ClassesTable::items->at(className)->ConstantTable;
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
	case OBJECT_ARRAY_RECEIVER_TYPE:
	{
		if (LocalVariable != NULL)
		{
			vector<char> arr = CodeGenerationCommands::aload(LocalVariable->Id - isInsideClassMethod); //Массив
			CodeGenerationHelpers::appendArrayToByteVector(&res, arr.data(), arr.size());
		}
		else if (Field != NULL) {
			vector<char> obj = CodeGenerationCommands::aload(0); //Объект
			CodeGenerationHelpers::appendArrayToByteVector(&res, obj.data(), obj.size());

			string className = Receiver->DataType->ClassName;
			ConstantsTable* constantsTable = ClassesTable::items->at(className)->ConstantTable;
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
		vector<char> index = ObjectArrayIndex->generateCode(isInsideClassMethod, constantsTable); //Индекс
		CodeGenerationHelpers::appendArrayToByteVector(&res, index.data(), index.size());
		vector<char> array = CodeGenerationCommands::aaload(); //Объект
		CodeGenerationHelpers::appendArrayToByteVector(&res, array.data(), array.size());
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

		if (isInitMethod) {
			int utf = constantsTable->findConstant(UTF8, &Receiver->DataType->ClassName);
			int classConst = constantsTable->findConstant(Class, NULL, NULL, utf);
			vector<char> newBytes = CodeGenerationCommands::new_(classConst);
			CodeGenerationHelpers::appendArrayToByteVector(&res, newBytes.data(), newBytes.size());
			vector<char> dupBytes = CodeGenerationCommands::dup();
			CodeGenerationHelpers::appendArrayToByteVector(&res, dupBytes.data(), dupBytes.size());
			CodeGenerationHelpers::appendArrayToByteVector(&res, receiver.data(), receiver.size());
			CodeGenerationHelpers::appendArrayToByteVector(&res, messageSelector.data(), messageSelector.size());
			vector<char> invoke = CodeGenerationCommands::invokespecial(Constant);
			CodeGenerationHelpers::appendArrayToByteVector(&res, invoke.data(), invoke.size());
		}
		else if (Method->IsClassMethod) {
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
