// ---------- Int keyword ----------

class Int_node
{
    public:
        int id;
};

// ---------- Char keyword ----------

class Char_node
{
    public:
        int id;
};

// ---------- Float keyword -----------

class Float_node
{
    public:
        int id;
};


// ---------- type ----------

enum type_type {
    INT,
    CHAR,
    FLOAT,
    ID,
    CLASS_NAME
};

class Type_node
{
    public:
        int id;
        enum type_type type;
};


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
            int numver;
            float number;
        } number;
        
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
        char *expression;
        Init_declarator_node *Next;
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
        enum expression_type *type;
        char *name;
        union constant
        {
            Numeric_constant_node *num;
            Literal_node *literal;
        } constant;
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
    SuPER,
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
};

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

// ---------- statement ----------

enum statement_type {
    EMPTY,
    SIMPLE,
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
        Statement_list_node *Block;
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
        } statement; 
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
