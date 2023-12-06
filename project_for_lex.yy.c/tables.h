#include <iostream>
#include <map>
#include "classes_nodes.h"
using namespace std;

class LocalVariablesTable;
class FieldsTable;
class MethodsTable;
class PropertiesTable;
class Type;

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
    constantType Type; // Тип константы
    string* Utf8String = NULL; // Строка для значения UTF-8 констант
    int Number = NULL; // Число для значения Integer констант
    int FirstRef = NULL; // Ссылка на 1-ую константу 
    int SecondRef = NULL; // Ссылка на 2-ую константу

    ConstantsTableElement(int id, constantType type, string utf8string);
    ConstantsTableElement(int id, constantType type, int number = NULL, int firstRef = NULL, int secondRef = NULL);

    string toCsvString(char separator = ';'); //Преобразование в строку формата CSV
};

class ConstantsTable
{
public:
    int maxId = 1; // Наибольший номер константы
    map<int, ConstantsTableElement*> items; // Таблица констант

    int findOrAddConstant(constantType type, string utf8string);
    int findOrAddConstant(constantType type, int number = NULL, int firstRef = NULL, int secondRef = NULL);
    ConstantsTableElement* getConstant(int id); //Получение константы
    string getConstantString(int id); //Получение значения UTF8 константы

    ConstantsTable();

    void toCsvFile(string filename, string filepath, char separator = ';'); //Преобразование в CSV-файл
private:
    int findConstant(constantType type, string* utf8string, int number = NULL, int firstRef = NULL, int secondRef = NULL);
};

// ---------- Таблица функций ----------

class FunctionsTableElement
{
public:
    int Name = NULL; // Ссылка на константу с именем функции
    int Descriptor = NULL; // Ссылка на константу с дескриптором функции
    Statement_node* BodyStart = NULL; // Ссылка на узел начала тела функции
    LocalVariablesTable* LocalVariables = NULL; // Ссылка на соответствующую таблицу локальных переменных
    string NameStr; // Имя функции
    string DescriptorStr; // Дескриптор функции

    FunctionsTableElement(int name, int descriptor, Statement_node* bodyStart, string nameStr, string descriptorStr);

    string toCsvString(string funcName, char separator = ';'); //Преобразование в строку формата CSV
    void refTablesToCsvFile(string filename, string filepath, char separator = ';');
};

class FunctionsTable
{
public:
    map<string, FunctionsTableElement*> items; // Таблица функций, в качестве ключа - Имя функции

    void addFunction(ConstantsTable* constantTable, string name, string descriptor, Statement_node* bodyStart);

    void toCsvFile(string filename, string filepath, char separator = ';'); //Преобразование в CSV-файл
};

// ---------- Таблица классов ----------

class ClassesTableElement
{
public:
    int Name; // Ссылка на константу с именем класса
    int SuperclassName; // Ссылка на константу с именем родительского класса
    bool IsImplementation; //Флаг, который показывает является ли класс реализацией (ВОЗМОЖНО, СТОИТ ДОБАВИТЬ ИМЕННО НАЛИЧИЕ РЕАЛИЗАЦИИ КЛАССА)
    bool IsHaveInterface = false; // Флаг, который показывает имеет ли реализация интерфейс
    int ThisClass; // Ссылка на константу текущего класса
    int Superclass; // Ссылка на константу родительского класса
    FieldsTable* Fields; // Ссылка на соответствующую таблицу полей класса
    MethodsTable* Methods; // Ссылка на соответстующую таблицу методов класса
    PropertiesTable* Properties; // Ссылка на соответствующую таблицу свойств класса
    ConstantsTable* ConstantTable; // Таблица констант

    ClassesTableElement(string name, string *superclassName, bool isImplementation);

    string toCsvString(char separator = ';'); //Преобразование в строку формата CSV
    void refTablesToCsvFile(string filepath, char separator = ';'); //Запись вложенных таблиц в файлы
};

class ClassesTable
{
public:
    static map<string, ClassesTableElement*> items; // Таблица классов, в качестве ключа - Имя класса

    static ClassesTableElement* addClass(string name, string *superclassName, bool isImplementation);

    static void toCsvFile(string filepath, char separator = ';'); //Преобразование в CSV-файл
};

// ---------- Таблица полей класса ----------

class FieldsTableElement
{
public:
    int Name = NULL; // Ссылка на константу с именем поля
    int Descriptor = NULL; // Ссылка на константу с дескриптором поля
    bool IsInstance = NULL; // Флаг, показывающий является ли поле частью экземпляра класса
	int InstanceIndex = NULL; // Индекс instance variable в списке (нужно, так как важен их порядок)
    Type* type; // Тип поля
    string NameStr; // Имя поля
    string DescriptorStr; // Дескриптор поля
	Expression_node* InitialValue = NULL; // Инициализирующее выражение

    FieldsTableElement(int name, int descriptor, bool isInstance, int instanceIndex, Type* type, string nameStr, string descriptorStr, Expression_node* initialValue);

    string toCsvString(char separator = ';'); //Преобразование в строку формата CSV
};

class FieldsTable
{
public:
	int maxInstanceIndex = 1;
    map < string, FieldsTableElement*> items; //Таблица полей класса, в качестве ключа - Имя поля класса

    void addField(ConstantsTable* constantTable, string name, string descriptor, bool isInstance, Type* type, Expression_node* initValue);

    void toCsvFile(string filename, string filepath, char separator = ';'); //Преобразование в CSV-файл
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
    Type* ReturnType; //Тип возвращаемого значепаарния
    vector<Type*>* ParamsTypes = NULL; //Тип параметров
    vector<Type*>* KeywordsTypes = NULL; //Тип параметров keyword

    string NameStr; // Имя метода
    string DescriptorStr; // Дескриптор метода

    MethodsTableElement(int name, int descriptor, bool isClassMethod, Statement_node* bodyStart, Type* returnType, vector<Type*>* paramsTypes, vector<Type*>* keywordsTypes, string nameStr, string descriptorStr);

    string toCsvString(string methodName, char separator = ';'); //Преобразование в строку формата CSV
    void refTablesToCsvFile(string methodName, string filepath, char separator = ';');
};

class MethodsTable
{
public:
    map< string, MethodsTableElement* > items; //Таблица методов класса, в качестве ключа - Имя метода класса

    void addMethod(ConstantsTable* constantTable, string name, string descriptor, bool isClassMethod, Statement_node* bodyStart, Type* returnType, vector<Type*>* paramsTypes, vector<Type*>* keywordsTypes);

    void toCsvFile(string filename, string filepath, char separator = ';'); //Преобразование в CSV-файл
};

// ----------- Таблица свойств ----------

class PropertiesTableElement
{
public:
    int Name = NULL; // Ссылка на константу с именем свойства
    int Descriptor = NULL; // Ссылка на константу с дескриптором типа константы
    bool IsReadonly = NULL; // Флаг, который показывает, что свойство доступно только для чтения
    Type* type; // Тип свойства
    string NameStr; // Имя свойства
    string DescriptorStr; // Дескриптор свойства

    PropertiesTableElement(int name, int descriptor, bool isReadonly, Type* type, string nameStr, string descriptorStr);

    string toCsvString(char separator = ';'); //Преобразование в строку формата CSV
};

class PropertiesTable
{
public:
    map<string, PropertiesTableElement*> items; // Таблица  свойств класса, в качестве ключа - Имя свойства класса

    void addProperty(ConstantsTable* constantTable, string name, string descriptor, bool isReadonly, Type* type);

    void toCsvFile(string filename, string filepath, char separator = ';'); //Преобразование в CSV-файл
};

// ---------- Таблица локальных переменных ----------

class LocalVariablesTableElement
{
public:
    int Id = NULL; // Номер локальной переменной
    string Name = NULL; // Имя локальной переменной
    Type* type; //Тип переменной

    LocalVariablesTableElement(int id, string name, Type* type);

    string toCsvString(char separator = ';'); //Преобразование в строку формата CSV
};

class LocalVariablesTable
{
public:
    int maxId = 0; // Наибольший номер локальной переменной
    map<string, LocalVariablesTableElement*> items; // Таблица локальных переменных, в качестве ключа - Имя локальной переменной

    int findOrAddLocalVariable(string name, Type* type);

    void toCsvFile(string filename, string fileoath, char separator = ';'); //Преобразование в CSV-файл
};

// ---------- Типы ----------
class Type
{
public:
    type_type DataType; // Тип данных
    string ClassName; //Имя класса
    int ArrSize = -1; // Размер массива

    Type(type_type dataType, string className, int arrSize);
    Type(type_type dataType, string className);
    Type(type_type dataType);
    Type(type_type dataType, int arrSize);

    string toString();
    string getDescriptor();
};
