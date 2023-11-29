#include <iostream>
#include <map>
#include "classes_nodes.h"
using namespace std;
// ---------- Таблица констант ----------

enum constantType {
    UTF8,
    Integer,
    String,
    Class,
    NameAndType,
    FieldRef,
    MethodRef
};

class ConstantsTableElement
{
public:
    int Id = NULL; // Номер константы
    constantType Type = NULL; // Тип константы
    string Utf8String = NULL; // Строка для значения UTF-8 констант
    int Number = NULL; // Число для значения Integer констант
    int FirstRef = NULL; // Ссылка на 1-ую константу 
	int SecondRef = NULL; // Ссылка на 2-ую константу
};

class ConstantsTable
{
public:
    int maxId = 1; // Наибольший номер константы
    map<int, ConstantsTableElement*> items; // Таблица констант
};

// ---------- Таблица функций ----------

class FunctionsTableElement
{
public:
    int Name = NULL; // Ссылка на константу с именем функции
    int Descriptor = NULL; // Ссылка на константу с дескриптором функции
    Statement_node* BodyRoot = NULL; // Ссылка на узел начала тела функции
	LocalVariablesTable* LocalVariables = NULL; // Ссылка на соответствующую таблицу локальных переменных
};

class FunctionsTable
{
public:
    map<string, FunctionsTableElement*> items; // Таблица функций, в качестве ключа - Имя функции
};

// ---------- Таблица классов ----------

class ClassesTableElement
{
public:
	int Name; // Ссылка на константу с именем класса
    int SuperclassName; // Ссылка на константу с именем родительского класса
    bool IsImplementation; //Флаг, который показывает является ли класс реализацией (ВОЗМОЖНО, СТОИТ ДОБАВИТЬ ИМЕННО НАЛИЧИЕ РЕАЛИЗАЦИИ КЛАССА)
	FieldsTable* Fields; // Ссылка на соответствующую таблицу полей класса
	MethodsTable* Methods; // Ссылка на соответстующую таблицу методов класса
	PropertiesTable* Properties; // Ссылка на соответствующую таблицу свойств класса
    ConstantsTable* ConstantTable; // Таблица констант
};

class ClassesTable
{
public:
    map<string, ClassesTableElement*> items; // Таблица классов, в качестве ключа - Имя класса
};

// ---------- Таблица полей класса ----------

class FieldsTableElement
{
public:
    int Name = NULL; // Ссылка на константу с именем поля
	int Descriptor = NULL; // Ссылка на константу с дескриптором поля
    bool IsInstance = NULL; // Флаг, показывающий является ли поле частью экземпляра класса
    Type Type;
};

class FieldsTable
{
public:
    map < string, FieldsTableElement*> items; //Таблица полей класса, в качестве ключа - Имя поля класса
};

// ---------- Таблица методов ----------

class MethodsTableElement
{
public:
    int Name = NULL; // Ссылка на константу с именем метода
	int Descriptor = NULL; // Ссылка на константу с дескриптором метода (НУЖНО ЛИ НА KEYWORD ИЛИ ИХ НУЖНО ПРЕОБРАЗОВЫВАТЬ К СТАНДАРТНОМУ ДЕСКРИПТОРУ ФУНКЦИИ?)
    bool IsClassMethod = NULL; // Флаг, который показывает принадлежность метода к классу, а не объекту
	Statement_node* BodyStart = NULL; // Ссылка на узел начала тела метода
	LocalVariablesTable* LocalVariables = NULL; // Ссылка на соотвветсвующую таблицу локальных переменных
    Type ReturnType; //Тип возвращаемого значепаарния
    vector<Type> ParamsTypes = NULL; //Тип параметров
    vector<Type> KeywordsTypes = NULL; //Тип параметров keyword
};

class MethodsTable
{
public:
	map< string, MethodsTableElement* > items; //Таблица методов класса, в качестве ключа - Имя метода класса
};

// ----------- Таблица свойств ----------

class PropertiesTableElement
{
public:
    int Name = NULL; // Ссылка на константу с именем свойства
	int Descriptor = NULL; // Ссылка на константу с дескриптором типа константы
    bool isReadonly = NULL; // Флаг, который показывает, что свойство доступно только для чтения
    Type Type; // Тип свойства
};

class PropertiesTable
{
public:
	map<string, PropertiesTableElement*> items; // Таблица  свойств класса, в качестве ключа - Имя свойства класса
};

// ---------- Таблица локальных переменных ----------

class LocalVariablesTableElement
{
public:
	int Id = NULL; // Номер локальной переменной
	string Name = NULL; // Имя локальной переменной
    Type Type; //Тип переменной
};

class LocalVariablesTable
{
public:
    int maxId = 0; // Наибольший номер локальной переменной
	map<string, LocalVariablesTableElement*> items; // Таблица локальных переменных, в качестве ключа - Имя локальной переменной
};

// ---------- Типы ----------
class Type {
    type_type DataType; // Тип данных
    string ClassName; //Имя класса
    int ArrSize; // Размер массива
};
