#pragma once

#include <iostream>
#include <vector>
using namespace std;

class CodeGenerationHelpers
{
public:
	static unsigned char magicConstant[4]; // Магическая константа
	static unsigned char smallVersion[2]; // Малая версия формата файла
	static unsigned char bigVersion[2]; // Большая версия формата файла

	static void appendArrayToByteVector(vector<char>* data, unsigned char array[], int arraySize); // Добавление массива байт в вектор
	static vector<unsigned char> intToByteArray(int num, int arraySize); // Генерация вектора байт

};
