#include <iostream>
#include <map>
#include <hash_set>
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
    static int maxId; // Наибольший номер константы

    int Id; // Номер константы
    constantType Type; // Тип константы
    string Utf8String; // Строка для значения UTF-8 констант
    int Number; // Число для значения Integer констант
    ConstantsTableElement* FirstRef; // Ссылка на 1-ую константу 
	ConstantsTableElement* SecondRef; // Ссылка на 2-ую константу
};

class ConstantsTable
{
private:
    hash_set<ConstantsTableElement*> items; // Таблица констант
};

// ---------- Таблица функций ----------

class FunctionsTableElement
{
public:
	static int maxId; // Наибольший номер функции

    int Id; // Номер функции
    ConstantsTableElement* Name; // Ссылка на константу с именем функции
    ConstantsTableElement* Descriptor; // Ссылка на константу с дескриптором функции
    Statement_node* BodyStart; // Ссылка на узел начала тела функции
    //TODO ссылка на таблицу локальных переменных
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
	static int maxId; // Наибольший номер класса

	int Id; // Номер класса
	ConstantsTableElement* Name; // Ссылка на константу с именем класса
    ConstantsTableElement* SuperclassName; // Ссылка на константу с именем родительского класса
    bool IsImplementation; //Флаг, который показывает является ли класс реализацией (ВОЗМОЖНО, СТОИТ ДОБАВИТЬ ИМЕННО НАЛИЧИЕ РЕАЛИЗАЦИИ КЛАССА)
    //TODO ссылка на таблицу полей класса
    //TODO ссылка на таблицу методов
    //TODO ссылка на таблицу свойств
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
    static int maxId; // Наибольший номер поля класса

	int Id; // Номер поля класса
    ConstantsTableElement* Name; // Ссылка на константу с именем поля
	ConstantsTableElement* Descriptor; // Ссылка на константу с дескриптором поля
    bool IsInstance; // Флаг, показывающий является ли поле частью экземпляра класса
    //TODO значение
};

class FieldsTable
{
    map < string, FieldTableElement*> items; //Таблица полей класса, в качестве ключа - Имя поля класса
};

// ---------- Таблица методов ----------

class MethodsTableElement
{
public:
	static int maxId; // Наибольший номер метода класса

	int Id; // Номер метода класса
    ConstantsTableElement* Name; // Ссылка на константу с именем метода
	ConstantsTableElement* Descriptor; // Ссылка на константу с дескриптором метода (НУЖНО ЛИ НА KEYWORD ИЛИ ИХ НУЖНО ПРЕОБРАЗОВЫВАТЬ К СТАНДАРТНОМУ ДЕСКРИПТОРУ ФУНКЦИИ?)
    bool IsClassMethod; // Флаг, который показывает принадлежность метода к классу, а не объекту
	Statement_node* BodyStart; // Ссылка на узел начала тела метода
    //TODO ссылка на таблицу локальных переменных
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
    static int maxId; // Наибольший номер свойства класса

    int Id; // Номер свойства класса
    ConstantsTableElement* Name; // Ссылка на константу с именем свойства
	ConstantsTableElement* Descriptor; // Ссылка на константу с дескриптором типа константы
    bool isReadonly; // Флаг, который показывает, что свойство доступно только для чтения
    //TODO значение
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
	static int maxId; // Наибольший номер локальной переменной

	int Id; // Номер локальной переменной
	string Name; // Имя локальной переменной
    //TODO значение
};

class LocalVariablesTable
{
private:
	map<string, LocalVariablesTableElement*> items; // Таблица локальных переменных, в качестве ключа - Имя локальной переменной
};
