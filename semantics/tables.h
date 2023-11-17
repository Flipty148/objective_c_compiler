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
    int Id; // Номер константы
    constantType Type; // Тип константы
    string Utf8String; // Строка для значения UTF-8 констант
    int Number; // Число для значения Integer констант
    int FirstRef; // Ссылка на 1-ую константу 
	int SecondRef; // Ссылка на 2-ую константу
};

class ConstantsTable
{
public:
    int maxId; // Наибольший номер константы
private:
    vector<ConstantsTableElement> items; // Таблица констант
};

// ---------- Таблица функций ----------

class FunctionsTableElement
{
public:
    int Name; // Ссылка на константу с именем функции
    int Descriptor; // Ссылка на константу с дескриптором функции
    Statement_node* BodyRoot; // Ссылка на узел начала тела функции
	LocalVariablesTable* LocalVariables; // Ссылка на соответствующую таблицу локальных переменных
};

class FunctionsTable
{
private:
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
private:
    map<string, ClassesTableElement*> items; // Таблица классов, в качестве ключа - Имя класса
};

// ---------- Таблица полей класса ----------

class FieldsTableElement
{
public:
    int Name; // Ссылка на константу с именем поля
	int Descriptor; // Ссылка на константу с дескриптором поля
    bool IsInstance; // Флаг, показывающий является ли поле частью экземпляра класса
    Type Type;
};

class FieldsTable
{
    map < string, FieldTableElement*> items; //Таблица полей класса, в качестве ключа - Имя поля класса
};

// ---------- Таблица методов ----------

class MethodsTableElement
{
public:
    int Name; // Ссылка на константу с именем метода
	int Descriptor; // Ссылка на константу с дескриптором метода (НУЖНО ЛИ НА KEYWORD ИЛИ ИХ НУЖНО ПРЕОБРАЗОВЫВАТЬ К СТАНДАРТНОМУ ДЕСКРИПТОРУ ФУНКЦИИ?)
    bool IsClassMethod; // Флаг, который показывает принадлежность метода к классу, а не объекту
	Statement_node* BodyStart; // Ссылка на узел начала тела метода
	LocalVariablesTable* LocalVariables; // Ссылка на соотвветсвующую таблицу локальных переменных
    Type ReturnType; //Тип возвращаемого значепаарния
    vector<Type> ParamsTypes; //Тип параметров
    vector<Type> KeywordsTypes; //Тип параметров keyword
};

class MethodsTable
{
private:
	map< string, MethodsTableElement* > items; //Таблица методов класса, в качестве ключа - Имя метода класса
};

// ----------- Таблица свойств ----------

class PropertiesTableElement
{
public:
    int Name; // Ссылка на константу с именем свойства
	int Descriptor; // Ссылка на константу с дескриптором типа константы
    bool isReadonly; // Флаг, который показывает, что свойство доступно только для чтения
    Type Type; // Тип свойства
};

class PropertiesTable
{
private:
	map<string, PropertiesTableElement*> items; // Таблица  свойств класса, в качестве ключа - Имя свойства класса
};

// ---------- Таблица локальных переменных ----------

class LocalVariablesTableElement
{
public:
	int Id; // Номер локальной переменной
	string Name; // Имя локальной переменной
    Type Type; //Тип переменной
};

class LocalVariablesTable
{
public:
    int maxId; // Наибольший номер локальной переменной
private:
    
	map<string, LocalVariablesTableElement*> items; // Таблица локальных переменных, в качестве ключа - Имя локальной переменной
};

// ---------- Типы ----------
class Type {
    type_type DataType; // Тип данных
    string ClassName; //Имя класса
    int ArrSize; // Размер массива
};
