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
