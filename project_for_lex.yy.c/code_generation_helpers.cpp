#include "code_generation_helpers.h"

//Инициализация констант
unsigned char CodeGenerationHelpers::magicConstant[4] = { 0xCA, 0xFE, 0xBA, 0xBE };
unsigned char CodeGenerationHelpers::smallVersion[2] = { 0x00, 0x00 };
unsigned char CodeGenerationHelpers::bigVersion[2] = { 0x00, 0x3E };

void CodeGenerationHelpers::appendArrayToByteVector(vector<char>* data, unsigned char array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		data->push_back(array[i]);
	}
}
 