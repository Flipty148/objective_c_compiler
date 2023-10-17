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
        char * value;
};
