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
