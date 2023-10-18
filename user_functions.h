#include "classes_nodes.h"

Program_node* createProgramNode(Statement_list_node *Statements, Class_statement_list_node *ClassStatements);

Type_node* createTypeNode(type_type type);

Numeric_constant_node* createIntegerConstantNode(int number);

Numeric_constant_node* createFloatConstantNode(float number);

Literal_node* createLiteralNode(literal_type type, char *value);
