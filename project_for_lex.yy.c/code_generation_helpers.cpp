#include "code_generation_helpers.h"

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
		res.push_back(0x2);
	}
	else if (num == 0) {
		res.push_back(0x3);
	}
	else if (num == 1) {
		res.push_back(0x4);
	}
	else if (num == 2) {
		res.push_back(0x5);
	}
	else if (num == 3) {
		res.push_back(0x6);
	}
	else if (num == 4) {
		res.push_back(0x7);
	}
	else if (num == 5) {
		res.push_back(0x8);
	}

	if (num <= 5 && num >= -1) {
		return res;
	}

	if (num >= -128 && num <= 127) {
		// bipush
		res.push_back(0x10);
		res.push_back(num);
		return res;
	}

	if (num >= -32768 && num <= 32767) {
		// sipush
		res.push_back(0x11);
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
		res.push_back(0x12);
		res.push_back(num);
	}
	else if (num >= 256 && num <= 65535) {
		//ldc_w
		res.push_back(0x13);
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
		res.push_back(0x15);
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
		res.push_back(0x19);
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
		res.push_back(0x36);
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
}
