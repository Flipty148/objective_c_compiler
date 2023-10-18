#include "user_functions.h"
#include <iostream>
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
    res->ClassName = NULL;
    return res;
}

Type_node* createClassTypeNode(type_type type, char *name)
{
    Type_node *res = new Type_node;
    res->id = id++;
    res->type = type;
    res->ClassName = name;
    return res;
}

//-------------------- Константы --------------------

// ---------- numeric_constant ----------

Numeric_constant_node* createIntegerConstantNode(int number)
{
    Numeric_constant_node *res = new Numeric_constant_node;
    res->id = id++;
    res->type = INTEGER_CONSTANT;
    res->number.Int = number;
    return res;
}

Numeric_constant_node* createFloatConstantNode(float number)
{
    Numeric_constant_node *res = new Numeric_constant_node;
    res->id = id++;
    res->type = FLOAT_CONSTANT;
    res->number.Float = number;
    return res;
}

// ---------- literal ----------

Literal_node* createLiteralNode(literal_type type, char *value)
{
    Literal_node *res = new Literal_node;
    res->id = id++;
    res->type = type;
    res->value = value;
    return res;
}

// --------------------- Объявления --------------------

// ---------- declaration ----------

Declaration_node* createDeclarationNode(Type_node *type, Init_declarator_list_node *initDeclarators)
{
    Declaration_node *res = new Declaration_node;
    res->id = id++;
    res->type = type;
    res->init_declarator_list = initDeclarators;
    res->Next = NULL;
    return res;
}

// ---------- declaration_list ----------

Declaration_list_node* createDeclarationListNode(Declaration_node *declaration)
{
    Declaration_list_node *res = new Declaration_list_node;
    res->id = id++;
    res->First = declaration;
    res->Last = declaration;
    return res;
}

Declaration_list_node* addDeclarationListNode(Declaration_list_node *list, Declaration_node *declaration)
{
    list->Last->Next = declaration;
    list->Last = declaration;
    return list;
}

// ---------- init_declarator_list ----------

Init_declarator_list_node* createInitDeclaratorListNode(Init_declarator_node *initDeclarator)
{
    Init_declarator_list_node *res = new Init_declarator_list_node;
    res->id = id++;
    res->First = initDeclarator;
    res->Last = initDeclarator;
    return res;
}

Init_declarator_list_node* addInitDeclaratorListNode(Init_declarator_list_node *list, Init_declarator_node *initDeclarator)
{
    list->Last->Next = initDeclarator;
    list->Last = initDeclarator;
    return list;
}

// ---------- init_declarator ----------

Init_declarator_node* createInitDeclaratorNode(init_declarator_type type, char *name, Expression_node *expression)
{
    Init_declarator_node *res = new Init_declarator_node;
    res->id = id++;
    res->type = type;
    res->name = name;
    res->expression = expression;
    res->Next = NULL;
    return res;
}

// ---------- parameter_list ----------

Parameter_list_node* createParameterListNode(Parameter_declaration_node *parameter)
{
    Parameter_list_node *res = new Parameter_list_node;
    res->id = id++;
    res->First = parameter;
    res->Last = parameter;
    return res;
}

Parameter_list_node* addParameterListNode(Parameter_list_node *list, Parameter_declaration_node *parameter)
{
    list->Last->Next = parameter;
    list->Last = parameter;
    return list;
}

// ---------- parameter_declaration ----------

Parameter_declaration_node* createParameterDeclarationNode(Type_node *type, char *name)
{
    Parameter_declaration_node *res = new Parameter_declaration_node;
    res->id = id++;
    res->type = type;
    res->name = name;
    res->Next = NULL;
    return res;
}
