#include <fstream>
#include "tables.h"
#include "code_generation_helpers.h"

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
	int fieldCount = Fields->items.size(); //Количество полей TODO: Сделать
	vector<char> fieldCountBytes = CodeGenerationHelpers::intToByteArray(0, 2); //Конвертация количества полей в байты
	CodeGenerationHelpers::appendArrayToByteVector(data, fieldCountBytes.data(), fieldCountBytes.size()); //Добавление количества полей в байты
	
	//Методы класса
	int methodCount = Methods->items.size(); //Количество методов TODO: Сделать
	vector<char> methodCountBytes = CodeGenerationHelpers::intToByteArray(0, 2); //Конвертация количества методов в байты
	CodeGenerationHelpers::appendArrayToByteVector(data, methodCountBytes.data(), methodCountBytes.size()); //Добавление количества методов в байты
	
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
