#include <vector>

// -------------------- Типы --------------------

// ---------- type ----------

enum type_type {
    INT,
    CHAR,
    FLOAT,
    ID,
    CLASS_NAME,
    VOID
};

class Type_node
{
    public:
        int id;
        enum type_type type;
        char *ClassName;
};

// -------------------- Константы --------------------

// ---------- numeric_constant ----------

enum numeric_constant_type {
    FLOAT_CONSTANT,
    INTEGER_CONSTANT
};

class Numeric_constant_node
{
    public:
        int id;
        enum numeric_constant_type type;
        union number
        {
            int Int;
            float Float;
        } *number;
        
};

// ---------- literal ----------

enum literal_type {
    STRING_CONSTANT,
    CHAR_CONSTANT,
    NSSTRING_CONSTANT
};

class Literal_node
{
    public:
        int id;
        enum literal_type type;
        char *value;
};

// -------------------- Объявления --------------------

// ---------- declaration ----------

class Declaration_node 
{
    public:
        int id;
        Type_node *type;
        Init_declarator_list_node *init_declarator_list;
        Declaration_node *Next;
};


// ---------- declaration_list ----------

class Declaration_list_node
{
    public:
        int id;
        Declaration_node *First;
        Declaration_node *Last;        
};

// ---------- init_declarator_list ----------

class Init_declarator_list_node
{
    public:
        int id;
        Init_declarator_node *First;
        Init_declarator_node *Last;
};

// ---------- init_declarator ----------

enum init_declarator_type {
    SIMPLE_DECLARATOR,
    DECLARATOR_WITH_INITIALIZING
};

class Init_declarator_node
{
    public:
        int id;
        enum init_declarator_type type;
        char *name;
        Expression_node *expression;
        Init_declarator_node *Next;
};

// ---------- parameter_type_list ----------

class Parameter_type_list_node
{
    public:
        int id;
        Parameter_list_node *ParameterList;
        bool includeElipsis = false;
};

// ---------- parameter_list ----------

class Parameter_list_node
{
    public:
        int id;
        Parameter_declaration_node *First;
        Parameter_declaration_node *Last;
};

// ---------- parameter_declaration ----------

class Parameter_declaration_node
{
    public:
        int id;
        Type_node *type;
        char *name;
        Parameter_declaration_node *Next;
};

// -------------------- Выражения --------------------

// ---------- expression ----------

enum expression_type
{
    IDENTIFIER,
    LITERAL,
    NUMERIIC_CONSTANT,
    PRIORITY,
    SELF,
    MESSAGE_EXPRESSION,
    UMINUS,
    UPLUS,
    UAMPERSAND,
    PLUS,
    MINUS,
    MUL,
    DIV,
    EQUAL,
    NOT_EQUAL,
    GREATER,
    LESS,
    LESS_EQUAL,
    GREATER_EQUAL,
    ASSIGNMENT
};

class Expression_node
{
    public:
        int id;
        enum expression_type type;
        char *name;
        union constant
        {
            Numeric_constant_node *num;
            Literal_node *literal;
        } *constant;
        Expression_node *Left;
        Expression_node *Right;
};

// ---------- message_expression ----------

class Message_expression_node : public Expression_node
{
    public:
        int id;
        Receiver_node *Receiver;
        Message_selector_node *Arguments;
};

// ---------- receiver ----------
enum receiver_type {
    SUPER,
    SELF,
    CLASS_NAME
};


class Receiver_node
{
    public:
        int id;
        char *name;
};

// ---------- message_selector -----------

class Message_selector_node
{
    public:
        int id;
        char *MethodName;
        Keyword_argument_list_node *Arguments;
};

// ---------- keyword_argument_list ----------

class Keyword_argument_list_node
{
    public:
        int id;
        Keyword_argument_node *First;
        Keyword_argument_node *Last;
};

// ---------- keyword_argument ----------

enum keyword_argument_type {
    WITH_IDENTIFIER,
    WITHOUT_IDENTIFIER
};

class Keyword_argument_node
{
    public:
        int id;
        enum keyword_argument_type type;
        char *name;
        Expression_node *expression;
        Keyword_argument_node *Next;
};

// -------------------- Управляющие структуры: развилки --------------------

// ------------ if_statement ----------

enum if_type {
    WITH_ALTERNATIVE,
    WITHOUT_ALTERNATIVE
};

class If_statement_node : public Statement_node
{
    public:
        int id;
        enum if_type type;
        Expression_node *Condition;
        Statement_node *TrueBranch;
        Statement_node *FalseBranch;
};

// -------------------- Управляющие структуры: циклы --------------------

// ----------- while_stasement ----------

class While_statement_node : public Statement_node
{
    public:
        int id;
        Expression_node *LoopCondition;
        Statement_node *LoopBody;
};

// ---------- do_while_statement ----------

class Do_while_statement_node : public Statement_node
{
    public:
        int id;
        Expression_node *LoopCondition;
        Statement_node *LoopBody;
};

// ---------- for_statement ----------

enum for_type {
    FOR,
    FOREACH,
    FOREACH_WITH_DECLARATION
};

class For_statement_node : public Statement_node
{
    public:
        int id;
        enum for_type type;
        Expression_node *InitExpression;
        Expression_node *ConditionExpression;
        Expression_node *LoopExpression;
        Statement_node *LoopBody;
        char *name;
        Type_node *NameType;
};

// -------------------- Операторы --------------------

// ---------- statement ----------

enum statement_type {
    EMPTY,
    SIMPLE,
    RETURN,
    IF,
    WHILE,
    DO_WHILE,
    FOR,
    COMPOUND,
    DECLARATION,
    CLASS_DECLARATION_LIST
};

class Statement_node
{
    public:
        int id;
        enum statement_type type;
        Expression_node *Expression;
        Statement_node *Statement;
        Declaration_node *Declaration;
        Class_declaration_list_node *Class_declaration;
        Statement_node *Next;
};

// ---------- compound_statement ----------

class Compound_statement_node : public Statement_node
{
    public:
        int id;
        Statement_list_node *Statements;
};

// ---------- statement_list ----------

class Statement_list_node
{
    public:
        int id;
        Statement_node *First;
        Statement_node *Last;
};

// ---------- class_statement ----------

enum class_statement_type {
    INTERFACE,
    IMPLEMENTATION
};

class Class_statement_node {
    public:
        int id;
        enum class_statement_type type;
        union statement
        {
            Class_interface_node *Interface;
            Class_implementation_node *Implementation;
        } *statement; 
        Class_statement_node *Next;     
};

// ---------- class_statement_list ----------

class Class_statement_list_node
{
    public:
        int id;
        Class_statement_node *First;
        Class_statement_node *Last;
};


// -------------------- Классы --------------------

// ---------- class_interface ----------

enum class_interface_type {
    WITH_INHERITANCE,
    WITHOUT_INHERITANCE
};

class Class_interface_node : public Class_statement_node
{
    public:
        int id;
        enum class_interface_type type;
        char *ClassName;
        char *SuperclassName;
        Interface_statement_node *Statement;
};

// ---------- interface_statement ----------

class Interface_statement_node
{
    public:
        int id;
        Instance_variables_node *Variables;
        Interface_declaration_list_node *Declaration_list;
};

// ---------- implementation_statement ----------

class Implementation_statement_node
{
    public:
        int id;
        Instance_variables_node *Variables;
        Implementation_definition_list_node *Declaration_list;
};

// ---------- class_implementation ----------

enum class_implementation_type {
    WITH_INHERITANCE,
    WITHOUT_INHERITANCE
};

class Class_implementation_node : public Class_statement_node
{
    public:
        int id;
        enum class_implementation_type type;
        char *ClassName;
        char *SuperclassName;
        Implementation_statement_node *Staetment;
};

// ---------- class_declaration_list и class_list ----------

class Class_declaration_list_node
{
    public:
        int id;
        Class_list_node *List;
};

class Class_list_node
{
    public:
        int id;
    std::vector<char*> *Class_names;
};

// ---------- instance_variables ----------

class Instance_variables_node
{
    public:
        int id;
        Declaration_list_node *DeclarationList;
};

// ---------- interface_declaration_list ----------

class Interface_declaration_list_node
{
    public:
        int id;
        union interface_declaration {
            Declaration_node *declaration;
            Property_node *property;
            Method_declaration_node *method_declaration;
        } *First, *Last;
};

// ---------- method_declaration, class_method_declaration, instance_method_declaration ----------

enum method_declaration_type {
    CLASS,
    INSTANCE
};

class Method_declaration_node
{
    public:
        int id;
        enum method_declaration_type type;
        Type_node *MethodType;
        Method_selector_node *MethodSelector;
        Method_declaration_node *Next;
};


// ---------- implementation_definition_list ----------

class Implementation_definition_list_node
{
    public:
        int id;
        union interface_declaration {
            Declaration_node *declaration;
            Property_node *property;
            Method_definition_node *method_definition;
        } *First, *Last;
};

// ---------- method_definition, class_method_definition, instance_method_definition ----------

enum method_definition_type {
    CLASS,
    INSTANCE
};

class Method_definition_node
{
    public:
        int id;
        enum method_definition_type type;
        Type_node *MethodType;
        Method_selector_node *MethodSelector;
        Declaration_list_node *DeclarationList;
        Compound_statement_node *MethodBody;
        Method_definition_node *Next;
};

// ---------- method_selector ----------

class Method_selector_node
{
    public:
        int id;
        char *MethodName;
        Keyword_selector_node *KeywordSelector;
        Parameter_list_node *Parameter_list_node;
};

// ---------- keyword_selector ----------

class Keyword_selector_node
{
    public:
        int id;
        Keyword_declaration_node *First;
        Keyword_declaration_node *Last;
};

// ---------- keyword_declaration ----------

class Keyword_declaration_node
{
    public:
        int id;
        Type_node *KeywordType;
        char *Identifier;
        char *KeywordName;
        Keyword_declaration_node *Next;
};

// ---------- property ----------

class Property_node
{
    public:
        int id;
        Attribute_node *Attribute;
        Type_node *type;
        char *Name;
        Property_node *Next;
};

// ----------- attribute ----------

enum attrribute_type {
    READONLY,
    READWRITE
};

class Attribute_node
{
    public:
        int id;
        enum attrribute_type type;
};


// ---------- program ----------

class Program_node
{
    public:
        int id;
        Statement_list_node *Statements;
        Class_statement_list_node *ClassStatements;
};
