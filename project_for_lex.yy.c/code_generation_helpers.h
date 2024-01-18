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
	static vector<char> defaultConstructorCodeAttribute(int parrentInitConstant); //Генерация атрибута Code для конструктора по умолчанию

};

class CodeGenerationCommands
{
public:
	// ---------- КОМАНДЫ РАБОТЫ СО СТЕКОМ ----------

	/*!
	* Генерирует команды iconst, bipush, sipush, ldc.
	* Команды семейства iconst_<i> загружают небольшую целочисленную константу i на стек. Это однобайтная команда без операндов.
	* Команда bipush (0x10) загружает на стек однобайтовую целую константу, sipush (0x11) — двухбатовую
	* @param[in] num - загружаемое число
	* @return вектор байт
	*/
	static vector<char> iconstBipushSipush(int num);
	/*!
	* Генерирует команды ldc и ldc_w.
	* Команды ldc (0x12) и ldc_w (0x13) загружают на стек целую или дробную константу из таблицы констант класса.
	* @param[in] num - номер константы типа CONSTANT_Integer, CONSTANT_String
	* @return вектор байт
	*/
	static vector<char> ldc(int num);
	/*!
	* Генерирует команду iaload.
	* Команда iaload (0x15) загружает на стек целое число из локальной переменной.
	* @param[in] num - номер локальной переменной в таблице локальных переменных
	* @return вектор байт
	*/
	static vector<char> iload(int num);
	/*!
		* Генерирует команду aload.
		* Команда aload (0x19) загружает на стек ссылку на объект из локальной переменной.
		* @param[in] num - номер локальной переменной в таблице локальных переменных
		* @return вектор байт
		*/
	static vector<char> aload(int num);
	/*!
			* Генерирует команду istore .
			* Команда istore (0x36)сохраняет целое число с вершины стека в локальную переменной.
			* @param[in] num - номер локальной переменной в таблице локальных переменных
			* @return вектор байт
			*/
	static vector<char> istore(int num);
	/*!
	* Генерирует команду astore .
	* Команда astore (0x3a) сохраняет ссылку на объект с вершины стека в локальную переменную.
	* @param[in] num - номер локальной переменной в таблице локальных переменных
	* @return вектор байт
	*/
	static vector<char> astore(int num);
	/*!
	* Генерирует команду pop .
	* Команда pop (0x57) удаляет(снимает) верхний элемент стека.
	* @return вектор байт
	*/
	static vector<char> pop();
	/*!
	* Генерирует команду dup .
	* Команда dup (0x59) дублирует верхний элемент стека.
	* @return вектор байт
	*/
	static vector<char> dup();
	/*!
	* Генерирует команду dup2 .
	* Команда dup2 (0x5с) дублирует два верхних элемента стека.
	* @return вектор байт
	*/
	static vector<char> dup2();

	// ---------- КОМАНДЫ, ВЫПОЛНЯЮЩИЕ АРИФМЕТИЧЕСКИЕ ОПЕРАЦИИ ----------

	/*!
	* Генерирует команду iadd.
	* Команда iadd (0x60) выполняет сложение двух целых чисел, лежащих на вершине стека (с их удалением оттуда) и помещает сумму на вершину стека.
	* @return вектор байт
	*/
	static vector<char> iadd();
	/*!
	* Генерирует команду imul.
	* Команда imul (0x68) выполняет умножение двух целых чисел, лежащих на вершине стека (с их удалением оттуда) и помещает произведение на вершину стека.
	* @return вектор байт
	*/
	static vector<char> imul();
	/*!
	* Генерирует команду isub.
	* Команда isub (0x64) выполняет вычитание двух целых чисел, лежащих на вершине стека (с их удалением оттуда) и помещает разность на вершину стека.
	* @return вектор байт
	*/
	static vector<char> isub();
	/*!
	* Генерирует команду idiv.
	* Команда iвшм (0x6с) выполняет деление двух целых чисел, лежащих на вершине стека (с их удалением оттуда) и помещает частное на вершину стека.
	* @return вектор байт
	*/
	static vector<char> idiv();
	/*!
		* Генерирует команду iinc.
		* Команда iinc (0x84) прибавляет знаковое число размером 1 байт непосредственно к значению локальной переменной.
		* @param[in] index - индекс локальной переменной в таблице локальных переменных
		* @param[in] num - число, которое нужно прибавить
		* @return вектор байт
		*/
	static vector<char> iinc(int index, int num);
	/*!
	* Генерирует команду ineg.
	* Команда ineg (0x74) выполняет изменение знака числа, лежащего на вершине стека и помещает его на вершину стека.
	* @return вектор байт
	*/
	static vector<char> ineg();

	// ---------- КОМАНДЫ ПЕРЕДАЧИ УПРАВЛЕНИЯ ----------

	enum IfCommandType {
		EQ,
		NE,
		LT,
		LE,
		GT,
		GE
	};
	/*!
	* Генерирует команду if_icmp
	* Команда if_icmp<cond> выполняет условный переход, если сравнение целых чисел дает истину.
	* Значение1 и Значение2 должны лежать на вершине стека и быть целыми переменными типа int.
	* Если результат сравнения ложен, то выполнение команд продолжится,
	* иначе произойдет переход к выполнению команды, расположенной через смещение от текущей команды
	* (положительное смещение для перехода вперед, отрицательное - назад).
	* @param[in] type - тип команды <cond>
	* @param[in] offset - смещение
	* @return вектор байт
	*/
	static vector<char> if_icmp(IfCommandType type, int offset);
	/*!
	* Генерирует команду if
	* Команда if<cond> выполняет условный переход, если сравнение целого числа с 0 дает истину.
	* Значение должно лежать на вершине стека и быть целыми переменными типа int.
	* Если результат сравнения ложен, то выполнение команд продолжится,
	* иначе произойдет переход к выполнению команды, расположенной через смещение от текущей команды
	* (положительное смещение для перехода вперед, отрицательное - назад).
	* @param[in] type - тип команды <cond>
	* @param[in] offset - смещение
	* @return вектор байт
	*/
	static vector<char> if_ (IfCommandType type, int offset);
	/*!
		* Генерирует команду if_acmp
		* Команда if_acmp<cond> выполняет условный переход, если сравнение ссылок на объекты дает истину. 
		* Ссылки считаются равными только если они указывают на один и тот же объект
		* Значение1 и Значение2 должны лежать на вершине стека и иметь тип ref.
		* Если результат сравнения ложен, то выполнение команд продолжится,
		* иначе произойдет переход к выполнению команды, расположенной через смещение от текущей команды
		* (положительное смещение для перехода вперед, отрицательное - назад).
		* @param[in] type - тип команды <cond>
		* @param[in] offset - смещение
		* @return вектор байт
	*/
	static vector<char> if_acmp(IfCommandType type, int offset);
	/*!
	* Генерирует команду goto
	* Команда goto (0xa7) выполняет безусловный переход на указанное смещение от текущей команды
	* (положительное смещение для перехода вперед, отрицательное - назад).
	* @param[in] offset - смещение
	*/
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
	/*!
	* Генерирует команду newarray
	* Команда newarray (0xbc) создает массив заданного типа и размера в области динамически выделяемой памяти ("куче") и помещает ссылку на него на вершину стека.
	* Тип - операнд.
	* Размер массива - на вершине стека.
	* @param[in] type - тип массива
	* @return вектор байт
	*/
	static vector<char> newarray(ArrayCommandType type);
	/*!
	* Генерирует команду anewarray.
	* Команда anewarray (0xbd) создает массив заданного типа (класса) и размера в области динамически выделяемой памяти ("куче").
	* Тип - операнд. Указывается номером константы CONSTANT_Class.
	* Размер массива - на вершине стека.
	* @param[in] constant - константа CONSTANT_Class
	* @return вектор байт
	*/
	static vector<char> anewarray(int constant);
	/*!
	* Генерирует команду arraylength
	* Команда arraylength (0xbe) возвращает длину массива, ссылка на который на вершине стека.
	* @return вектор байт
	*/
	static vector<char> arraylength();
	/*!
	* Генерирует команду iaload
	* Команда iaload (0x2e) загружает на стек целое число из массива по индексу.
	* Ссылка на массив и индекс расположены на вершине стека.
	* @return вектор байт
	*/
	static vector<char> iaload();
	/*!
		* Генерирует команду caload
		* Команда caload (0x34) загружает на стек символ из массива по индексу.
		* Ссылка на массив и индекс расположены на вершине стека.
		* @return вектор байт
		*/
	static vector<char> caload();
	/*!
		* Генерирует команду aaload
		* Команда aaload (0x32) загружает на стек ссылку на объект из массива по индексу.
		* Ссылка на массив и индекс расположены на вершине стека.
		* @return вектор байт
		*/
	static vector<char> aaload();
	/*!
	* Генерирует команду iastore
	* Команда iastore (0x4f) сохраняет целое число на вершине стека в массив по индексу.
	* Ссылка на массив, индекс и сохраняемое значение  расположены на вершине стека.
	* @return вектор байт
	*/
	static vector<char> iastore();
	/*!
		* Генерирует команду castore
		* Команда castore (0x55) сохраняет символ на вершине стека в массив по индексу.
		* Ссылка на массив, индекс и сохраняемое значение  расположены на вершине стека.
		* @return вектор байт
		*/
	static vector<char> castore();
	/*!
	* Генерирует команду aastore
	* Команда aastore (0x53) сохраняет ссылку на объект на вершине стека в массив по индексу.
	* Ссылка на массив, индекс и сохраняемое значение  расположены на вершине стека.
	* @return вектор байт
	*/
	static vector<char> aastore();

	// ---------- КОМАНДЫ РАБОТЫ С ОБЪЕКТАМИ ----------

	/*!
	* Генерирует команду new
	* Команда new (0xbb) создает новый объект заданного типа (класса)  в области динамически выделяемой памяти («куче») и
	* помещает ссылку на него на вершину стека.
	* Команда new не инициализирует объект, пока не будет вызван специальный метод. Перед дальнейшем
	* использованием созданного объекта необходимо вызвать для него конструктор
	* @param[in] constant - константа CONSTANT_Class
	* @return вектор байт
	*/
	static vector<char> new_(int constant);
	/*!
	* Генерирует команду getfield
	* Команда getfield (0xb4) возвращает значение поля объекта на вершине стека.
	* Ссылка на объект располагается на вершине стека.
	* @param[in] constant - константа CONSTANT_Fieldref
	* @return вектор байт
	*/
	static vector<char> getfield(int constant);
	/*!
		* Генерирует команду putfield
		* Команда putfield (0xb5) устанавливает значение на вершине стека в поле объекта.
		* Ссылка на объект и значение располагаются на вершине стека.
		* @param[in] constant - константа CONSTANT_Fieldref
		* @return вектор байт
		*/
	static vector<char> putfield(int constant);
	/*!
	* Генерирует команду instanceof
	* Команда instanceof (0xc1) проверяет является ли ссылка на объект экземпляром заданного класса.
	* Ссылка на объект располагается на вершине стека.
	* Если ссылка на объект не содержит null и объект является экземпляром указанного класса(массива), то
	* на вершину стека помещается int-значение 1, иначе 0
	* @param[in] constant - константа CONSTANT_Class
	* @return вектор байт
	*/
	static vector<char> instanceof(int constant);
	/*!
	* Генерирует команду checkcast
	* Команда checkcast (0xc0) проверяет является ли ссылка на объект экземпляром заданного класса.
	* Ссылка на объект располагается на вершине стека.
	* Если ссылка на объект содержит null, либо объект не является экземпляром указанного класса(массива), то выбрасывается исключение
	* ClassCastException, вместо помещения на вершину стека результата. Сама ссылка не убирается с вершины стека.
	* Использовать команду checkcast для случаев, когда не принадлежность объекта классу означает фатальную ошибку в выполняемой программе, в противном случае следует использовать instanceof
	* @param[in] constant - константа CONSTANT_Class
	* @return вектор байт
	*/
	static vector<char> checkcast(int constant);

	// ---------- КОМАНДЫ РАБОТЫ С МЕТОДАМИ ----------

	/*!
	* Генерирует команду invokevirtual
	* Команда invokevirtual (0xb6) вызывает метод экземпляра класса.
	* Ссылка на объект и аргументы располагаются на вершине стека.
	* Создается отдельная область выполненияметода, со своими локальными переменными, где 0-я локальная переменная — ссылка на объект,
	* 1-я локальная переменная — аргумент1 и так далее. По завершении выполнения метода на стек помещается возвращенное им значение, если оно есть.
	* @param[in] constant - константа CONSTANT_Methodref
	* @return вектор байт
	*/
	static vector<char> invokevirtual(int constant);
	/*!
	* Генерирует команду invokespecial
	* Команда invokespecial (0xb7) вызывает метод, определенный в классе, наследующемся от указанного класса, в частности используется для вызова конструктора текущего класса.
	* Ссылка на объект и аргументы располагаются на вершине стека.
	* @param[in] constant - константа CONSTANT_Methodref
	* @return вектор байт
	*/
	static vector<char> invokespecial(int constant);
	/*!
		* Генерирует команду invokestatic
		* Команда invokestatic (0xb8) вызывает статический метод класса.
		* Ссылка на объект и аргументы располагаются на вершине стека.
		* @param[in] constant - константа CONSTANT_Methodref
		* @return вектор байт
		*/
	static vector<char> invokestatic(int constant);
	/*!
	* Генерирует команду ireturn.
	* Команда ireturn (0xac) завершает выполнение текущего метода и возвращает int-значение из вершины стека.
	* @return вектор байт
	*/
	static vector<char> ireturn();
	/*!
	* Генерирует команду areturn
	* Команда areturn (0xb0) завершает выполнение текущего метода и возвращает ссылку на объект из вершины стека.
	* @return вектор байт
	*/
	static vector<char> areturn();
	/*!
	* Генерирует команду return
	* Команда return (0xb1) завершает выполнение текущего метода без возвращаемого значения (void).
	* @return вектор байт
	*/
	static vector<char> return_();
};
