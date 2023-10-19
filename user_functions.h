#include "classes_nodes.h"
#include <set>
#include <iostream>
using namespace std;
int id = 0; // Глобальный id узла
set<string> ClassNames; //Множество имен объявленных классов

//---------- program ----------
Program_node* createProgramNode(Statement_list_node *Statements, Class_statement_list_node *ClassStatements);

// -------------------- Типы --------------------
// ---------- type ----------
Type_node* createTypeNode(type_type type);
Type_node* createClassTypeNode(type_type type, char *name);

// -------------------- Константы --------------------
// ---------- numeric_constant ----------
Numeric_constant_node* createIntegerConstantNode(int number);
Numeric_constant_node* createFloatConstantNode(float number);

// ---------- literal ----------
Literal_node* createLiteralNode(literal_type type, char *value);

// --------------------- Объявления --------------------
// ---------- declaration ----------
Declaration_node* createDeclarationNode(Type_node *type, Init_declarator_list_node *initDeclarators);

// ---------- declaration_list ----------
Declaration_list_node* createDeclarationListNode(Declaration_node *declaration);
Declaration_list_node* addDeclarationListNode(Declaration_list_node *list, Declaration_node *declaration);

// ---------- init_declarator_list ----------
Init_declarator_list_node* createInitDeclaratorListNode(Init_declarator_node *initDeclarator);
Init_declarator_list_node* addInitDeclaratorListNode(Init_declarator_list_node *list, Init_declarator_node *initDeclarator);

// ---------- init_declarator ----------
Init_declarator_node* createInitDeclaratorNode(init_declarator_type type, char *name, Expression_node *expression);

// ---------- parameter_type_list ----------
Parameter_type_list_node* createParameterTypeListNode(Parameter_list_node *list, bool includeElipsis);

// ---------- parameter_list ----------
Parameter_list_node* createParameterListNode(Parameter_declaration_node *parameter);
Parameter_list_node* addParameterListNode(Parameter_list_node *list, Parameter_declaration_node *parameter);

// ---------- parameter_declaration ----------
Parameter_declaration_node* createParameterDeclarationNode(Type_node *type, char *name);

// -------------------- Выражения --------------------
// ---------- expression ----------
Expression_node* createIdentifierExpressionNode(char *name);
Expression_node* createLiteralExpressionNode(Literal_node *value);
Expression_node* createNumericConstantExpressionNode(Numeric_constant_node *value);
Expression_node* createSimpleExpressionNode(expression_type type, Expression_node *expression);
Expression_node* createSelfExpressionNode();
Expression_node* createOperationExpressionNode(expression_type type, Expression_node *leftExpression, Expression_node *rightExpression);

// ---------- message_expression ----------
Message_expression_node* createMessageExpressionNode(Receiver_node *receiver, Message_selector_node *arguments);

// ---------- receiver ----------
Receiver_node* createReceiverNode(receiver_type type, char *name);

// ---------- message_selector ----------
Message_selector_node* createMethodSelectorNode(char *methodName, Keyword_argument_list_node *arguments);

// ---------- keyword_argument_list ----------
Keyword_argument_list_node* createKeywordArgumentListNode(Keyword_argument_node *argument);
Keyword_argument_list_node* addKeywordArgumentListNode(Keyword_argument_list_node *list, Keyword_argument_node *argument);

// ---------- keyword_argument ----------
Keyword_argument_node* createKeywordArgumentNode(keyword_argument_type type, char *identifier, Expression_node *expression);

// -------------------- Управляющие структуры: развилки --------------------
// ---------- if_statement ----------
If_statement_node* createIfStatementNode(if_type type, Expression_node *condition, Statement_node *trueBranch, Statement_node *falseBranch);

// -------------------- Управляющие структуры: циклы --------------------
// ---------- while_statement ----------
While_statement_node* createWhileStatementNode(Expression_node *condition, Statement_node *body);

// ---------- do_while_statement ----------
Do_while_statement_node* createDoWhileStatementNode(Expression_node *condition, Statement_node *body);

// ---------- for_statement ----------
For_statement_node* createForStatementNode(Expression_node *initExpression, Expression_node *condition, Expression_node *loopExpression, Statement_node *body);
For_statement_node* createForeachStatementNode(for_type type, Type_node *varType, char *loopVar, Expression_node *expression, Statement_node *body);

// -------------------- Операторы --------------------
// ---------- statement ----------
Statement_node* createSimpleStatementNode(statement_type type, Expression_node *expression);
Statement_node* createComplexStatementNode(statement_type type, Statement_node *statement);
Statement_node* createDeclarationStatementNode(Declaration_node *declaration);
Statement_node* createClassDeclarationStatementNode(Class_declaration_list_node *classDeclarationList);

// ---------- compound_statement ----------
Compound_statement_node* createCompoundStatementNode(Statement_list_node *statements);

// ---------- statement_list ----------
Statement_list_node* createStatementListNode(Statement_node *statement);
Statement_list_node* addStatementListNode(Statement_list_node *list, Statement_node *statement);

// ----------- class_statement ----------
Class_statement_node* createInterfaceClassStatementNode(Class_interface_node *interface);
Class_statement_node* createImplementationClassStatementNode(Class_implementation_node *implementation);

// ---------- Class_statement_list ----------
Class_statement_list_node* createClassStatementListNode(Class_statement_node *ClassStatement);
Class_statement_list_node* addClassStatementListNode(Class_statement_list_node *list, Class_statement_node *ClassStatement);

// -------------------- Классы --------------------
// ---------- class_interface ----------
Class_interface_node* createClassInterfaceNode(class_interface_type type, char *className, char *superclassName, Interface_statement_node *statement);

// ---------- interface_statement ----------
Interface_statement_node* createInterfaceStatementNode(Instance_variables_node *variables, Interface_declaration_list_node *declarationList);

// ---------- implementation_statement ----------
Implementation_statement_node* createImplementationStatementNode(Instance_variables_node *variables, Implementation_definition_list_node *definitionList);

// ---------- class_implementation ----------
Class_implementation_node* createClassImplementationNode(class_implementation_type type, char *className, char *superclassName, Implementation_statement_node *statement);

// ---------- class_declaration_list, class_list ----------
Class_list_node* createClassListNode(char *className);
Class_list_node* addClassListNode(Class_list_node *list, char *className);
Class_declaration_list_node* createClassDeclarationListNode(Class_list_node *list);

// ---------- instance_variables ----------
Instance_variables_node* createInstanceVariablesNode(Declaration_list_node *declarationList);

// ---------- interface_declaration_list ----------
Interface_declaration_list_node* createDeclarationInterfaceDeclarationListNode(Declaration_node *interfaceDeclaration);
Interface_declaration_list_node* createPropertyInterfaceDeclarationListNode(Property_node *interfaceDeclaration);
Interface_declaration_list_node* createMethodDeclarationInterfaceDeclarationListNode(Method_declaration_node *interfaceDeclaration);
Interface_declaration_list_node* addDeclarationInterfaceDeclarationListNode(Interface_declaration_list_node *list, Declaration_node *interfaceDeclaration);
Interface_declaration_list_node* addPropertyInterfaceDeclarationListNode(Interface_declaration_list_node *list, Property_node *interfaceDeclaration);
Interface_declaration_list_node* addMethodDeclarationInterfaceDeclarationListNode(Interface_declaration_list_node *list, Method_declaration_node *interfaceDeclaration);

// ---------- method_declaration, class_method_declaration, instance_method_declaration ----------
Method_declaration_node* createMethodDeclarationNode(method_declaration_type type, Type_node *methodType, Method_selector_node *selector);

// ---------- implementation_definition_list ----------
Implementation_definition_list_node* createDeclarationImplementationDefinitionListNode(Declaration_node *interfaceDeclaration);
Implementation_definition_list_node* createPropertyImplementationDefinitionListNode(Property_node *interfaceDeclaration);
Implementation_definition_list_node* createMethodDeclarationImplementationDefinitionListNode(Method_definition_node *interfaceDeclaration);
Implementation_definition_list_node* addDeclarationImplementationDefinitionListNode(Implementation_definition_list_node *list, Declaration_node *interfaceDeclaration);
Implementation_definition_list_node* addPropertyImplementationDefinitionListNode(Implementation_definition_list_node *list, Property_node *interfaceDeclaration);
Implementation_definition_list_node* addMethodDeclarationImplementationDefinitionListNode(Implementation_definition_list_node *list, Method_definition_node *interfaceDeclaration);

// ---------- method_definition, class_method_definition, instance_method_definition ----------
Method_definition_node* createMethodDefinitionNode(method_definition_type type, Type_node *methodType, Method_selector_node *selector, Declaration_list_node *declarationList, Compound_statement_node *methodBody);

// ---------- method_selector ----------
Method_selector_node* createMethodSelectorNode(char *methodName, Keyword_selector_node *selector, Parameter_list_node *parameters);

// ---------- keyword_selector ----------
Keyword_selector_node* createKeywordSelectorNode(Keyword_declaration_node *declaration);
Keyword_selector_node* addKeywordSelectorNode(Keyword_selector_node *list, Keyword_declaration_node *declaration);

// ---------- keyword_declaration ----------
Keyword_declaration_node* createKeywordDeclarationNode(Type_node *type, char *identifier, char *keywordName);

// ---------- property ----------
Property_node* createPropertyNode(Attribute_node *attribute, Type_node *type, char *name);

// ---------- attribute ----------
Attribute_node* createAttributeNode(attrribute_type type);
