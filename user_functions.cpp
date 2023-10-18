#include "user_functions.h"
int id = 0;

//---------- program ----------

Program_node* createProgramNode(Statement_list_node *Statements, Class_statement_list_node *ClassStatements)
{
	Program_node *res = new Program_node;
    res->id = id++;
    res->Statements = Statements;
    res->ClassStatements = ClassStatements;
    return res;
}

// -------------------- Типы --------------------

// ---------- type ----------

Type_node* createTypeNode(type_type type)
{
    Type_node *res = new Type_node;
    res->id = id++;
    res->type = type;
}

//-------------------- Константы --------------------

// ---------- numeric_constant ----------

Numeric_constant_node* createIntegerConstantNode(int number)
{
    Numeric_constant_node *res = new Numeric_constant_node;
    res->id = id++;
    res->type = INTEGER_CONSTANT;
    res->number.Int = number;
}

Numeric_constant_node* createFloatConstantNode(float number)
{
    Numeric_constant_node *res = new Numeric_constant_node;
    res->id = id++;
    res->type = FLOAT_CONSTANT;
    res->number.Float = number;
}

// ---------- literal ----------

Literal_node* createLiteralNode(literal_type type, char *value)
{
    Literal_node *res = new Literal_node;
    res->id = id++;
    res->type = type;
    res->value = value;
}
