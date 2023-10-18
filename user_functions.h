#include "classes_nodes.h"

Program_node* createProgramNode(Statement_list_node *Statements, Class_statement_list_node *ClassStatements);

Type_node* createTypeNode(type_type type);

Type_node* createClassTypeNode(type_type type, char *name);

Numeric_constant_node* createIntegerConstantNode(int number);

Numeric_constant_node* createFloatConstantNode(float number);

Literal_node* createLiteralNode(literal_type type, char *value);

Declaration_node* createDeclarationNode(Type_node *type, Init_declarator_list_node *initDeclarators);

Declaration_list_node* createDeclarationListNode(Declaration_node *declaration);

Declaration_list_node* addDeclarationListNode(Declaration_list_node *list, Declaration_node *declaration);

Init_declarator_list_node* createInitDeclaratorListNode(Init_declarator_node *initDeclarator);

Init_declarator_list_node* addInitDeclaratorListNode(Init_declarator_list_node *list, Init_declarator_node *initDeclarator);

Init_declarator_node* createInitDeclaratorNode(init_declarator_type type, char *name, Expression_node *expression);

Parameter_list_node* createParameterListNode(Parameter_declaration_node *parameter);

Parameter_list_node* addParameterListNode(Parameter_list_node *list, Parameter_declaration_node *parameter);

Parameter_declaration_node* createParameterDeclarationNode(Type_node *type, char *name);
