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
    res->number->Int = number;
    return res;
}

Numeric_constant_node* createFloatConstantNode(float number)
{
    Numeric_constant_node *res = new Numeric_constant_node;
    res->id = id++;
    res->type = FLOAT_CONSTANT;
    res->number->Float = number;
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

// -------------------- Выражения --------------------

// ---------- expression ----------

Expression_node* createIdentifierExpressionNode(char *name)
{
    Expression_node *res = new Expression_node;
    res->id = id++;
    res->type = IDENTIFIER;
    res->name = name;
    res->constant = NULL;
    res->Left = NULL;
    res->Right = NULL;
    return res;
}

Expression_node* createLiteralExpressionNode(Literal_node *value)
{
    Expression_node *res = new Expression_node;
    res->id = id++;
    res->type = LITERAL;
    res->name = NULL;
    res->constant->literal = value;
    res->Left = NULL;
    res->Right = NULL;
    return res;
}

Expression_node* createNumericConstantExpressionNode(Numeric_constant_node *value)
{
    Expression_node *res = new Expression_node;
    res->id = id++;
    res->type = NUMERIIC_CONSTANT;
    res->name = NULL;
    res->constant->num = value;
    res->Left = NULL;
    res->Right = NULL;
    return res;
}

Expression_node* createSimpleExpressionNode(expression_type type, Expression_node *expression)
{
    Expression_node *res = new Expression_node;
    res->id = id++;
    res->type = type;
    res->name = NULL;
    res->constant = NULL;
    res->Left = NULL;
    res->Right = expression;
    return res;
}

Expression_node* createSelfExpressionNode()
{
    Expression_node *res = new Expression_node;
    res->id = id++;
    res->type = expression_type::SELF;
    res->name = NULL;
    res->constant = NULL;
    res->Left = NULL;
    res->Right = NULL;
    return res;
}

Expression_node* createOperationExpressionNode(expression_type type, Expression_node *leftExpression, Expression_node *rightExpression)
{
    Expression_node *res = new Expression_node;
    res->id = id++;
    res->type = type;
    res->name = NULL;
    res->constant = NULL;
    res->Left = leftExpression;
    res->Right = rightExpression;
    return res;
}

// ---------- message_expression ----------

Message_expression_node* createMessageExpressionNode(Receiver_node *receiver, Message_selector_node *arguments)
{
    Message_expression_node *res = new Message_expression_node;
    res->id = id++;
    res->Receiver = receiver;
    res->Arguments = arguments;
    return res;
}

// ---------- receiver ----------

Receiver_node* createReceiverNode(receiver_type type, char *name)
{
    Receiver_node *res = new Receiver_node;
    res->id = id++;
    res->name = name;
    return res;
}

// ---------- message_selector ----------

Message_selector_node* createMethodSelectorNode(char *methodName, Keyword_argument_list_node *arguments)
{
    Message_selector_node *res = new Message_selector_node;
    res->id = id++;
    res->MethodName = methodName;
    res->Arguments = arguments;
    return res;
}

// ---------- keyword_argument_list ----------

Keyword_argument_list_node* createKeywordArgumentListNode(Keyword_argument_node *argument)
{
    Keyword_argument_list_node *res = new Keyword_argument_list_node;
    res->id = id++;
    res->First = argument;
    res->Last = argument;
    return res;
}

Keyword_argument_list_node* addKeywordArgumentListNode(Keyword_argument_list_node *list, Keyword_argument_node *argument)
{
    list->Last->Next = argument;
    list->Last = argument;
    return list;
}

// ---------- keyword_argument ----------

Keyword_argument_node* createKeywordArgumentNode(keyword_argument_type type, char *identifier, Expression_node *expression)
{
    Keyword_argument_node *res = new Keyword_argument_node;
    res->id = id++;
    res->type = type;
    res->name = identifier;
    res->expression = expression;
    res->Next = NULL;
    return res;
}

// -------------------- Управляющие структуры: развилки --------------------

// ---------- if_statement ----------

If_statement_node* createIfStatementNode(if_type type, Expression_node *condition, Statement_node *trueBranch, Statement_node *falseBranch)
{
    If_statement_node *res = new If_statement_node;
    res->id = id++;
    res->type = type;
    res->Condition = condition;
    res->TrueBranch = trueBranch;
    res->FalseBranch = falseBranch;
    return res;
}

// -------------------- Управляющие структуры: циклы --------------------

// ---------- while_statement ----------

While_statement_node* createWhileStatementNode(Expression_node *condition, Statement_node *body)
{
    While_statement_node *res = new While_statement_node;
    res->id = id++;
    res->LoopCondition = condition;
    res->LoopBody = body;
    return res;
}

// ---------- do_while_statement ----------

Do_while_statement_node* createDoWhileStatementNode(Expression_node *condition, Statement_node *body)
{
    Do_while_statement_node *res = new Do_while_statement_node;
    res->id = id++;
    res->LoopCondition = condition;
    res->LoopBody = body;
    return res;
}

// ---------- for_statement ----------

For_statement_node* createForStatementNode(Expression_node *initExpression, Expression_node *condition, Expression_node *loopExpression, Statement_node *body)
{
    For_statement_node *res = new For_statement_node;
    res->id = id++;
    res->type = for_type::FOR;
    res->InitExpression = initExpression;
    res->ConditionExpression = condition;
    res->LoopExpression = loopExpression;
    res->LoopBody = body;
    res->name = NULL;
    res->NameType = NULL;
    return res;
}

For_statement_node* createForeachStatementNode(for_type type, Type_node *varType, char *loopVar, Expression_node *expression, Statement_node *body)
{
    For_statement_node *res = new For_statement_node;
    res->id = id++;
    res->type = type;
    res->InitExpression = NULL;
    res->ConditionExpression = NULL;
    res->LoopExpression = expression;
    res->LoopBody = body;
    res->name = loopVar;
    res->NameType = varType;
    return res;
}

// -------------------- Операторы --------------------

// ---------- statement ----------

Statement_node* createSimpleStatementNode(statement_type type, Expression_node *expression)
{
    Statement_node *res = new Statement_node;
    res->id = id++;
    res->type = type;
    res->Expression = expression;
    res->Statement = NULL;
    res->Declaration = NULL;
    res->Class_declaration = NULL;
    res->Next = NULL;
    return res;
}

Statement_node* createComplexStatementNode(statement_type type, Statement_node *statement)
{
    Statement_node *res = new Statement_node;
    res->id = id++;
    res->type = type;
    res->Expression = NULL;
    res->Statement = statement;
    res->Declaration = NULL;
    res->Class_declaration = NULL;
    res->Next = NULL;
    return res;
}

Statement_node* createDeclarationStatementNode(Declaration_node *declaration)
{
    Statement_node *res = new Statement_node;
    res->id = id++;
    res->type = DECLARATION;
    res->Expression = NULL;
    res->Statement = NULL;
    res->Declaration = declaration;
    res->Class_declaration = NULL;
    res->Next = NULL;
    return res;
}

Statement_node* createClassDeclarationStatementNode(Class_declaration_list_node *classDeclarationList)
{
    Statement_node *res = new Statement_node;
    res->id = id++;
    res->type = CLASS_DECLARATION_LIST;
    res->Expression = NULL;
    res->Statement = NULL;
    res->Declaration = NULL;
    res->Class_declaration = classDeclarationList;
    res->Next = NULL;
    return res;
}

// ---------- compound_statement ----------

Compound_statement_node* createCompoundStatementNode(Statement_list_node *statements)
{
    Compound_statement_node *res = new Compound_statement_node;
    res->id = id++;
    res->Statements = statements;
    return res;
}

// ---------- statement_list ----------

Statement_list_node* createStatementListNode(Statement_node *statement)
{
    Statement_list_node *res = new Statement_list_node;
    res->id = id++;
    res->First = statement;
    res->Last = statement;
    return res;
}

Statement_list_node* addStatementListNode(Statement_list_node *list, Statement_node *statement)
{
    list->Last->Next = statement;
    list->Last = statement;
    return list;
}

// ----------- class_statement ----------

Class_statement_node* createInterfaceClassStatementNode(Class_interface_node *interface)
{
    Class_statement_node *res = new Class_statement_node;
    res->id = id++;
    res->type = INTERFACE;
    res->statement.Interface = interface;
    res->Next = NULL;
    return res;
}

Class_statement_node* createImplementationClassStatementNode(Class_implementation_node *implementation)
{
    Class_statement_node *res = new Class_statement_node;
    res->id = id++;
    res->type = IMPLEMENTATION;
    res->statement.Implementation = implementation;
    res->Next = NULL;
    return res;
}

// ---------- Class_statement_list ----------

Class_statement_list_node* createClassStatementListNode(Class_statement_node *ClassStatement)
{
    Class_statement_list_node *res = new Class_statement_list_node;
    res->id = id++;
    res->First = ClassStatement;
    res->Last = ClassStatement;
    return res;
}

Class_statement_list_node* addClassStatementListNode(Class_statement_list_node *list, Class_statement_node *ClassStatement)
{
    list->Last->Next = ClassStatement;
    list->Last = ClassStatement;
    return list;
}
