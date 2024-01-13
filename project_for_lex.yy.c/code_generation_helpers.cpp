﻿#include "code_generation_helpers.h"

//Инициализация констант
char CodeGenerationHelpers::magicConstant[4] = { 0xCA, 0xFE, 0xBA, 0xBE };
char CodeGenerationHelpers::smallVersion[2] = { 0x00, 0x00 };
char CodeGenerationHelpers::bigVersion[2] = { 0x00, 0x3E };

void CodeGenerationHelpers::appendArrayToByteVector(vector<char>* data, char array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		data->push_back(array[i]);
	}
}

vector<char> CodeGenerationHelpers::intToByteArray(int num, int arraySize)
{
	vector<char> result(arraySize);
	for (int i = 0; i < arraySize; i++)
	{
		result[arraySize - i - 1] = (num >> ( i * 8));
	}
	return result;
}

// -------------------- ГЕНЕРАЦИИ КОМАНД JVM --------------------

// ---------- iconst, bipush, sipush ----------
vector<char> CodeGenerationCommands::iconstBipushSipush(int num)
{
	vector<char> res;

	// iconst
	if (num == -1) {
		res.push_back(0x2); //iconst_m1
	}
	else if (num == 0) {
		res.push_back(0x3); //iconst_0
	}
	else if (num == 1) {
		res.push_back(0x4); //iconst_1
	}
	else if (num == 2) {
		res.push_back(0x5); //iconst_2
	}
	else if (num == 3) {
		res.push_back(0x6); //iconst_3
	}
	else if (num == 4) {
		res.push_back(0x7); //iconst_4
	}
	else if (num == 5) {
		res.push_back(0x8); //iconst_5
	}

	if (num <= 5 && num >= -1) {
		return res;
	}

	if (num >= -128 && num <= 127) {
		// bipush
		res.push_back(0x10); //bipush
		res.push_back(num);
		return res;
	}

	if (num >= -32768 && num <= 32767) {
		// sipush
		res.push_back(0x11); //sipush
		vector <char> temp = CodeGenerationHelpers::intToByteArray(num, 2);
		CodeGenerationHelpers::appendArrayToByteVector(&res, temp.data(), temp.size());
		return res;
	}
	else {
		throw std::exception("Error in iconstBipushSipush: Invalid number");
	}
}


// ---------- ldc, ldc_w ----------
vector<char> CodeGenerationCommands::ldc(int num)
{
	vector<char> res;
	if (num >= 0 && num <= 255) {
		//ldc
		res.push_back(0x12); //ldc
		res.push_back(num);
	}
	else if (num >= 256 && num <= 65535) {
		//ldc_w
		res.push_back(0x13); //ldc_w
		vector <char> temp = CodeGenerationHelpers::intToByteArray(num, 2);
		CodeGenerationHelpers::appendArrayToByteVector(&res, temp.data(), temp.size());
	}
	else {
		throw std::exception("Error in ldc, ldc_w: Invalid number");
	}

	return res;
}

// ---------- iload ----------
vector<char> CodeGenerationCommands::iload(int num)
{
	vector<char> res;
	if (num >= 0 && num <= 255) {
		res.push_back(0x15); //iload
		res.push_back(num);
	}
	else if (num >= 256 && num <= 65535) {
		// wide iload
		res.push_back(0xC4); //wide
		res.push_back(0x15); //iload
		vector <char> temp = CodeGenerationHelpers::intToByteArray(num, 2);
		CodeGenerationHelpers::appendArrayToByteVector(&res, temp.data(), temp.size());
	}
	else {
		throw std::exception("Error in iload: Invalid number");
	}

	return res;
}

// ---------- aload ----------
vector<char> CodeGenerationCommands::aload(int num)
{
	vector<char> res;
	if (num >= 0 && num <= 255) {
		res.push_back(0x19); //aload
		res.push_back(num); 
	}
	else if (num >= 256 && num <= 65535) {
		// wide aload
		res.push_back(0xC4); //wide
		res.push_back(0x19); //aload
		vector <char> temp = CodeGenerationHelpers::intToByteArray(num, 2);
		CodeGenerationHelpers::appendArrayToByteVector(&res, temp.data(), temp.size());
	}
	else {
		throw std::exception("Error in aload: Invalid number");
	}

	return res;
}

// ---------- istore ----------
vector<char> CodeGenerationCommands::istore(int num)
{
	vector<char> res;
	if (num >= 0 && num <= 255) {
		res.push_back(0x36); //istore
		res.push_back(num);
	}
	else if (num >= 256 && num <= 65535) {
		// wide istore
		res.push_back(0xC4); //wide
		res.push_back(0x36); //istore
		vector <char> temp = CodeGenerationHelpers::intToByteArray(num, 2);
		CodeGenerationHelpers::appendArrayToByteVector(&res, temp.data(), temp.size());
	}
	else {
		throw std::exception("Error in istore: Invalid number");
	}

	return res;
}

// ---------- astore ----------
vector<char> CodeGenerationCommands::astore(int num)
{
	vector<char> res;
	if (num >= 0 && num <= 255) {
		res.push_back(0x3A); //astore
		res.push_back(num);
	}
	else if (num >= 256 && num <= 65535) {
		// wide astore
		res.push_back(0xC4); //wide
		res.push_back(0x3A); //astore
		vector <char> temp = CodeGenerationHelpers::intToByteArray(num, 2);
		CodeGenerationHelpers::appendArrayToByteVector(&res, temp.data(), temp.size());
	}
	else {
		throw std::exception("Error in astore: Invalid number");
	}

	return res;
}

// ---------- pop ----------
vector<char> CodeGenerationCommands::pop()
{
	vector <char> res;
	res.push_back(0x57); //pop
	return res;
}

// ---------- dup ----------
vector<char> CodeGenerationCommands::dup()
{
	vector <char> res;
	res.push_back(0x59); //dup
	return res;
}

// ---------- dup2 ----------
vector<char> CodeGenerationCommands::dup2()
{
	vector <char> res;
	res.push_back(0x5C); //dup2
	return res;
}

// ---------- iadd ----------
vector<char> CodeGenerationCommands::iadd()
{
	vector<char> res;
	res.push_back(0x60); //iadd
	return res;
}

// ---------- imul ----------
vector<char> CodeGenerationCommands::imul()
{
	vector<char> res;
	res.push_back(0x68); //imul
	return res;
}

// ---------- isub ----------
vector<char> CodeGenerationCommands::isub()
{
	vector<char> res;
	res.push_back(0x64); //isub
	return res;
}

// ---------- idiv ----------
vector<char> CodeGenerationCommands::idiv()
{
	vector<char> res;
	res.push_back(0x6C); //idiv
	return res;
}

// ---------- iinc ----------
vector<char> CodeGenerationCommands::iinc()
{
	vector<char> res;
	res.push_back(0x84); //iinc
	return res;
}

// ---------- if_icmp ----------
vector<char> CodeGenerationCommands::if_icmp(IfCommandType type, int offset)
{
	vector<char> res;
	switch (type)
	{
	case EQ:
		res.push_back(0x9F); //if_icmpeq
		break;
	case NE:
		res.push_back(0xA0); //if_icmpne
		break;
	case LT:
		res.push_back(0xA1); //if_icmplt
		break;
	case LE:
		res.push_back(0xA4); //if_icmple
		break;
	case GT:
		res.push_back(0xA3); //if_icmpgt
		break;
	case GE:
		res.push_back(0xA2); //if_icmpge
		break;
	default:
		break;
	}

	vector <char> temp = CodeGenerationHelpers::intToByteArray(offset, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, temp.data(), temp.size());

	return res;
}

// ---------- if ----------
vector<char> CodeGenerationCommands::if_(IfCommandType type, int offset)
{
	vector<char> res;

	switch (type)
	{
	case EQ:
		res.push_back(0x99); //ifeq
		break;
	case NE:
		res.push_back(0x9A); //ifne
		break;
	case LT:
		res.push_back(0x9B); //iflt
		break;
	case LE:
		res.push_back(0x9E); //ifle
		break;
	case GT:
		res.push_back(0x9D); //ifgt
		break;
	case GE:
		res.push_back(0x9C); //ifge
		break;
	default:
		break;
	}

	vector <char> temp = CodeGenerationHelpers::intToByteArray(offset, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, temp.data(), temp.size());

	return res;
}

// ---------- if_acmp ----------
vector<char> CodeGenerationCommands::if_acmp(IfCommandType type, int offset)
{
	vector<char> res;

	switch (type)
	{
	case EQ:
		res.push_back(0xA5); //if_acmpeq
		break;
	case NE:
		res.push_back(0xA6); //if_acmpne
		break;
	default:
	{
		throw std::exception("Error in if_acmp: Invalid type");
	}
		break;
	}

	vector <char> temp = CodeGenerationHelpers::intToByteArray(offset, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, temp.data(), temp.size());

	return res;
}

// ---------- goto ----------
vector<char> CodeGenerationCommands::goto_(int offset)
{
	vector<char> res;
	res.push_back(0xA7); //goto
	vector <char> temp = CodeGenerationHelpers::intToByteArray(offset, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, temp.data(), temp.size());
	return res;
}

// ---------- newarray ----------
vector<char> CodeGenerationCommands::newarray(ArrayCommandType type)
{
	vector<char> res;
	res.push_back(0xBC); //newarray
	res.push_back(type);
	return res;

}

// ---------- anewarray ----------
vector<char> CodeGenerationCommands::anewarray(int constant)
{
	vector<char> res;
	res.push_back(0xBD); //anewarray
	vector <char> temp = CodeGenerationHelpers::intToByteArray(constant, 2);
	CodeGenerationHelpers::appendArrayToByteVector(&res, temp.data(), temp.size());
	return res;
}

// ---------- arraylength ----------
vector<char> CodeGenerationCommands::arraylength()
{
	vector<char> res;
	res.push_back(0xBE); //arraylength
	return res;
}

// ---------- iaload ----------
vector<char> CodeGenerationCommands::iaload()
{
	vector<char> res;
	res.push_back(0x2E); //iaload
	return res;
}

// ---------- aaload ----------
vector<char> CodeGenerationCommands::aaload()
{
	vector<char> res;
	res.push_back(0x32); //aaload
	return res;
}

