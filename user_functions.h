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

Expression_node* createIdentifierExpressionNode(char *name);

Expression_node* createLiteralExpressionNode(Literal_node *value);

Expression_node* createNumericConstantExpressionNode(Numeric_constant_node *value);

Expression_node* createSimpleExpressionNode(expression_type type, Expression_node *expression);

Expression_node* createSelfExpressionNode();

Expression_node* createOperationExpressionNode(expression_type type, Expression_node *leftExpression, Expression_node *rightExpression);

Message_expression_node* createMessageExpressionNode(Receiver_node *receiver, Message_selector_node *arguments);

Receiver_node* createReceiverNode(receiver_type type, char *name);

Message_selector_node* createMethodSelectorNode(char *methodName, Keyword_argument_list_node *arguments);

Keyword_argument_list_node* createKeywordArgumentListNode(Keyword_argument_node *argument);

Keyword_argument_list_node* addKeywordArgumentListNode(Keyword_argument_list_node *list, Keyword_argument_node *argument);

Keyword_argument_node* createKeywordArgumentNode(keyword_argument_type type, char *identifier, Expression_node *expression);

If_statement_node* createIfStatementNode(if_type type, Expression_node *condition, Statement_node *trueBranch, Statement_node *falseBranch);

While_statement_node* createWhileStatementNode(Expression_node *condition, Statement_node *body);

Do_while_statement_node* createDoWhileStatementNode(Expression_node *condition, Statement_node *body);

For_statement_node* createForStatementNode(Expression_node *initExpression, Expression_node *condition, Expression_node *loopExpression, Statement_node *body);

For_statement_node* createForeachStatementNode(for_type type, Type_node *varType, char *loopVar, Expression_node *expression, Statement_node *body);
