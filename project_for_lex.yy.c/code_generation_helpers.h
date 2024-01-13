#pragma once

#include <iostream>
#include <vector>
using namespace std;

class CodeGenerationHelpers
{
public:
	static char magicConstant[4]; // Магическая константа
	static char smallVersion[2]; // Малая версия формата файла
	static char bigVersion[2]; // Большая версия формата файла
	static const int stackSize = 1000;

	static void appendArrayToByteVector(vector<char>* data, char array[], int arraySize); // Добавление массива байт в вектор
	static vector<char> intToByteArray(int num, int arraySize); // Генерация вектора байт

};

class CodeGenerationCommands
{
public:
	// ---------- КОМАНДЫ РАБОТЫ СО СТЕКОМ ----------

	static vector<char> iconstBipushSipush(int num);
	static vector<char> ldc(int num);
	static vector<char> iload(int num);
	static vector<char> aload(int num);
	static vector<char> istore(int num);
	static vector<char> astore(int num);
	static vector<char> pop();
	static vector<char> dup();
	static vector<char> dup2();

	// ---------- КОМАНДЫ, ВЫПОЛНЯЮЩИЕ АРИФМЕТИЧЕСКИЕ ОПЕРАЦИИ ----------

	static vector<char> iadd();
	static vector<char> imul();
	static vector<char> isub();
	static vector<char> idiv();
	static vector<char> iinc();

	// ---------- КОМАНДЫ ПЕРЕДАЧИ УПРАВЛЕНИЯ ----------

	enum IfCommandType {
		EQ,
		NE,
		LT,
		LE,
		GT,
		GE
	};
	static vector<char> if_icmp(IfCommandType type, int offset);
	static vector<char> if_ (IfCommandType type, int offset);
	static vector<char> if_acmp(IfCommandType type, int offset);
	static vector<char> goto_(int offset);

	// ---------- КОМАНДЫ РАБОТЫ С МАССИВАМИ ----------

	enum ArrayCommandType {
		T_BOOLEAN = 4,
		T_CHAR = 5,
		T_FLOAT = 6,
		T_DOUBLE = 7,
		T_BYTE = 8,
		T_SHORT = 9,
		T_INT = 10,
		T_LONG = 11
	};
	static vector<char> newarray(ArrayCommandType type);
	static vector<char> anewarray(int constant);
	static vector<char> arraylength();
	static vector<char> iaload();
	static vector<char> aaload();
	static vector<char> iastore();
	static vector<char> aastore();

	// ---------- КОМАНДЫ РАБОТЫ С ОБЪЕКТАМИ ----------

	static vector<char> new_(int constant);
	static vector<char> getfield(int constant);
	static vector<char> putfield(int constant);
	static vector<char> instanceof(int constant);
};
