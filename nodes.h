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
