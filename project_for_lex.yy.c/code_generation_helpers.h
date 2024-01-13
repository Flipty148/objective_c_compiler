﻿#pragma once

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
	static vector<char> iconstBipushSipush(int num);
};