#include "classes_nodes.h"
#include <string>
using namespace std;
long maxId = 0; // Глобальный id узла
set<string> ClassNames; //Множество имен объявленных классов

//---------- program ----------

Program_node* Program_node::createProgramNode(Function_and_class_list_node* list)
{
	Program_node *res = new Program_node;
    res->id = maxId++;
    res->list = list;
    return res;
}

// ---------- function_and_class_list ----------

Function_and_class_list_node* Function_and_class_list_node::createFunctionAndClassListNodeFromFunction(Function_node *functionList)
{
    Function_and_class_list_node *res = new Function_and_class_list_node;
    res->id = maxId++;
    res->FunctionsAndClasses = new vector<function_and_class>;
    struct function_and_class functionAndClass;
    functionAndClass.function = functionList;
    functionAndClass.class_block = NULL;
    functionAndClass.class_declaration_list = NULL;
    res->FunctionsAndClasses->push_back(functionAndClass);
    return res;
}

Function_and_class_list_node* Function_and_class_list_node::createFunctionAndClassListNodeFromClassDeclarationList(Class_declaration_list_node *classDeclarationList)
{
    Function_and_class_list_node *res = new Function_and_class_list_node;
    res->id = maxId++;
    res->FunctionsAndClasses = new vector<function_and_class>;
    struct function_and_class functionAndClass;
    functionAndClass.class_declaration_list = classDeclarationList;
    functionAndClass.class_block = NULL;
    functionAndClass.function = NULL;
    res->FunctionsAndClasses->push_back(functionAndClass);

    return res;
}

Function_and_class_list_node* Function_and_class_list_node::createFunctionAndClassListNodeFromClassBlock(Class_block_node *classBlock)
{
    Function_and_class_list_node *res = new Function_and_class_list_node;
    res->id = maxId++;
    res->FunctionsAndClasses = new vector<function_and_class>;
    struct function_and_class functionAndClass;
    functionAndClass.class_block = classBlock;
    functionAndClass.class_declaration_list = NULL;
    functionAndClass.function = NULL;
    res->FunctionsAndClasses->push_back(functionAndClass);
    return res;
}

Function_and_class_list_node* Function_and_class_list_node::addToFunctionAndClassListNodeFromFunction(Function_and_class_list_node *list, Function_node *function)
{
    struct function_and_class functionAndClass;
    functionAndClass.function = function;
    functionAndClass.class_block = NULL;
    functionAndClass.class_declaration_list = NULL;
    list->FunctionsAndClasses->push_back(functionAndClass);
    return list;
}

Function_and_class_list_node* Function_and_class_list_node::addToFunctionAndClassListNodeFromClassDeclarationList(Function_and_class_list_node *list, Class_declaration_list_node *classDeclarationList)
{
    struct function_and_class functionAndClass;
    functionAndClass.class_declaration_list = classDeclarationList;
    functionAndClass.class_block = NULL;
    functionAndClass.function = NULL;
    list->FunctionsAndClasses->push_back(functionAndClass);
    return list;
}

Function_and_class_list_node* Function_and_class_list_node::addToFunctionAndClassListNodeFromClassBlock(Function_and_class_list_node *list, Class_block_node *classStatement)
{
    struct function_and_class functionAndClass;
    functionAndClass.class_block = classStatement;
    functionAndClass.class_declaration_list = NULL;
    functionAndClass.function = NULL;
    list->FunctionsAndClasses->push_back(functionAndClass);
    return list;
}

// ---------- function ----------

Function_node* Function_node::createFunctionNode(Type_node *type, char *name, Statement_list_node *statement)
{
    Function_node *res = new Function_node;
    res->id = maxId++;
    res->Type = type;
    res->Name = name;
    res->statement = statement;
    return res;
}

// -------------------- Типы --------------------

// ---------- type ----------

Type_node* Type_node::createTypeNode(type_type type)
{
    Type_node *res = new Type_node;
    res->id = maxId++;
    res->type = type;
    res->ClassName = NULL;
    return res;
}

Type_node* Type_node::createTypeNodeFromClassName(type_type type, char *name)
{
    Type_node *res = new Type_node;
    res->id = maxId++;
    res->type = type;
    res->ClassName = name;
    return res;
}

//-------------------- Константы --------------------

// ---------- numeric_constant ----------

Numeric_constant_node* Numeric_constant_node::createNumericConstantNodeFromInteger(int number)
{
    Numeric_constant_node *res = new Numeric_constant_node;
    res->id = maxId++;
    res->type = INTEGER_CONSTANT_TYPE;
    res->number.Int = number;
    return res;
}

Numeric_constant_node* Numeric_constant_node::createNumericConstantNodeFromFloat(float number)
{
    Numeric_constant_node *res = new Numeric_constant_node;
    res->id = maxId++;
    res->type = FLOAT_CONSTANT_TYPE;
    res->number.Float = number;
    return res;
}

// ---------- literal ----------

Literal_node* Literal_node::createLiteralNode(literal_type type, char *value)
{
    Literal_node *res = new Literal_node;
    res->id = maxId++;
    res->type = type;
    res->value = value;
    return res;
}

// --------------------- Объявления --------------------

// ---------- declaration ----------

Declaration_node* Declaration_node::createDeclarationNode(Type_node *type, Init_declarator_list_node *initDeclarators)
{
    Declaration_node *res = new Declaration_node;
    res->id = maxId++;
    res->type = type;
    res->init_declarator_list = initDeclarators;
    res->Next = NULL;
    return res;
}

// ---------- declaration_list ----------

Declaration_list_node* Declaration_list_node::createDeclarationListNode(Declaration_node *declaration)
{
    Declaration_list_node *res = new Declaration_list_node;
    res->id = maxId++;
    res->First = declaration;
    res->Last = declaration;
    return res;
}

Declaration_list_node* Declaration_list_node::addToDeclarationListNode(Declaration_list_node *list, Declaration_node *declaration)
{
    list->Last->Next = declaration;
    list->Last = declaration;
    return list;
}

// ---------- init_declarator_list ----------

Init_declarator_list_node* Init_declarator_list_node::createInitDeclaratorListNode(Init_declarator_node *initDeclarator)
{
    Init_declarator_list_node *res = new Init_declarator_list_node;
    res->id = maxId++;
    res->First = initDeclarator;
    res->Last = initDeclarator;
    return res;
}

Init_declarator_list_node* Init_declarator_list_node::addToInitDeclaratorListNode(Init_declarator_list_node *list, Init_declarator_node *initDeclarator)
{
    list->Last->Next = initDeclarator;
    list->Last = initDeclarator;
    return list;
}

// ---------- init_declarator ----------

Init_declarator_node* Init_declarator_node::createInitDeclaratorNode(init_declarator_type type, char *declarator, Expression_node *expression)
{
    Init_declarator_node *res = new Init_declarator_node;
    res->id = maxId++;
    res->type = type;
    res->Declarator = declarator;
    res->expression = expression;
    res->ArraySize = NULL;
    res->InitializerList = NULL;
    res->Next = NULL;
    return res;
}

Init_declarator_node* Init_declarator_node::createInitDeclaratorNodeFromArray(init_declarator_type type, char *declarator, Expression_node *arraySize, Expression_node *expression, Expression_list_node *initializerList)
{
    Init_declarator_node *res = new Init_declarator_node;
    res->id = maxId++;
    res->type = type;
    res->Declarator = declarator;
    res->expression = expression;
    res->ArraySize = arraySize;
    res->InitializerList = initializerList;
    res->Next = NULL;
    return res;
}

// ---------- declarator ----------

Declarator_node* Declarator_node::createDeclaratorNode(char *identifier, Expression_node *expression)
{
    Declarator_node *res = new Declarator_node;
    res->id = maxId++;
    res->Identifier = identifier;
    res->Expression = expression;
    return res;
}

// ---------- declarator_list ----------

Declarator_list_node* Declarator_list_node::createDeclaratorListNode(Declarator_node *declarator)
{
    Declarator_list_node *res = new Declarator_list_node;
    res->id = maxId++;
    res->Declarators = new vector<Declarator_node*>;
    res->Declarators->push_back(declarator);
    return res;
}

Declarator_list_node* Declarator_list_node::addToDeclaratorListNode(Declarator_list_node *list, Declarator_node *declarator)
{
    list->Declarators->push_back(declarator);
    return list;
}

// ---------- parameter_list ----------

Parameter_list_node* Parameter_list_node::createParameterListNode(Parameter_declaration_node *parameter)
{
    Parameter_list_node *res = new Parameter_list_node;
    res->id = maxId++;
    res->First = parameter;
    res->Last = parameter;
    return res;
}

Parameter_list_node* Parameter_list_node::addToParameterListNode(Parameter_list_node *list, Parameter_declaration_node *parameter)
{
    list->Last->Next = parameter;
    list->Last = parameter;
    return list;
}

// ---------- parameter_declaration ----------

Parameter_declaration_node* Parameter_declaration_node::createParameterDeclarationNode(Type_node *type, char *name)
{
    Parameter_declaration_node *res = new Parameter_declaration_node;
    res->id = maxId++;
    res->type = type;
    res->name = name;
    res->Next = NULL;
    return res;
}

// -------------------- Выражения --------------------

// ---------- expression ----------

Expression_node* Expression_node::createExpressionNodeFromIdentifier(char *name)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = IDENTIFIER_EXPRESSION_TYPE;
    res->name = name;
    res->Left = NULL;
    res->Right = NULL;
    res->Next = NULL;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromLiteral(Literal_node *value)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = LITERAL_EXPRESSION_TYPE;
    res->name = NULL;
    res->constant.literal = value;
    res->Left = NULL;
    res->Right = NULL;
    res->Next = NULL;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromNumericConstant(Numeric_constant_node *value)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = NUMERIIC_CONSTANT_EXPRESSION_TYPE;
    res->name = NULL;
    res->constant.num = value;
    res->Left = NULL;
    res->Right = NULL;
    res->Next = NULL;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromSimpleExpression(expression_type type, Expression_node *expression)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = type;
    res->name = NULL;
    res->Left = NULL;
    res->Right = expression;
    res->Next = NULL;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromSelf()
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = SELF_EXPRESSION_TYPE;
    res->name = NULL;
    res->Left = NULL;
    res->Right = NULL;
    res->Next = NULL;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromSuper()
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = SUPER_EXPRESSION_TYPE;
    res->name = NULL;
    res->Left = NULL;
    res->Right = NULL;
    res->Next = NULL;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromOperator(expression_type type, Expression_node *leftExpression, Expression_node *rightExpression)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = type;
    res->name = NULL;
    res->Left = leftExpression;
    res->Right = rightExpression;
    res->Next = NULL;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromMessageExpression(Receiver_node *receiver, Message_selector_node *arguments)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = MESSAGE_EXPRESSION_EXPRESSION_TYPE;
    res->Receiver = receiver;
    res->Arguments = arguments;
    res->Next = NULL;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromFunctionCall(char *name, Expression_list_node *argumentsList)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = FUNCTION_CALL_EXPRESSION_TYPE;
    res->name = name;
    res->ArgumentsList = argumentsList;
    res->Next = NULL;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromMemberAccessOperator(expression_type type, Expression_node *expression, char *memberName)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = type;
    res->name = memberName;
    res->Left = expression;
    res->Right = NULL;
    res->Next = NULL;
    return res;
}

Expression_node* Expression_node::setPriority(Expression_node *expression, bool priority)
{
    expression->isPriority = priority;
    return expression;
}

// ---------- expression_list ----------

Expression_list_node* Expression_list_node::createExpressionListNode(Expression_node *expression)
{
    Expression_list_node *res = new Expression_list_node;
    res->id = maxId++;
    res->First = expression;
    res->Last = expression;
    return res;
}

Expression_list_node* Expression_list_node::addToExpressionListNode(Expression_list_node *list, Expression_node *expression)
{
    list->Last->Next = expression;
    list->Last = expression;
    return list;
}

// ---------- receiver ----------

Receiver_node* Receiver_node::createReceiverNode(receiver_type type, char *name)
{
    Receiver_node *res = new Receiver_node;
    res->id = maxId++;
    res->Type = type;
    res->name = name;
    return res;
}

Receiver_node* Receiver_node::createReceiverNodeFromMessageExpression(Receiver_node *receiver, Message_selector_node *arguments)
{
    Receiver_node *res = new Receiver_node;
    res->id = maxId++;
    res->Type = MESSAGE_EXPRESSION_RECEIVER_TYPE;
    res->Receiver = receiver;
    res->Arguments = arguments;
    return res;
}

// ---------- message_selector ----------

Message_selector_node* Message_selector_node::createMessageSelectorNode(char *methodName,Expression_node *expression, Keyword_argument_list_node *arguments, Expression_list_node *exprArguments)
{
    Message_selector_node *res = new Message_selector_node;
    res->id = maxId++;
    res->MethodName = methodName;
    res->Arguments = arguments;
    res->Expression = expression;
    res->ExprArguments = exprArguments;
    return res;
}

// ---------- keyword_argument_list ----------

Keyword_argument_list_node* Keyword_argument_list_node::createKeywordArgumentListNode(Keyword_argument_node *argument)
{
    Keyword_argument_list_node *res = new Keyword_argument_list_node;
    res->id = maxId++;
    res->First = argument;
    res->Last = argument;
    return res;
}

Keyword_argument_list_node* Keyword_argument_list_node::addToKeywordArgumentListNode(Keyword_argument_list_node *list, Keyword_argument_node *argument)
{
    list->Last->Next = argument;
    list->Last = argument;
    return list;
}

// ---------- keyword_argument ----------

Keyword_argument_node* Keyword_argument_node::createKeywordArgumentNode(keyword_argument_type type, char *identifier, Expression_node *expression)
{
    Keyword_argument_node *res = new Keyword_argument_node;
    res->id = maxId++;
    res->type = type;
    res->name = identifier;
    res->expression = expression;
    res->Next = NULL;
    return res;
}

// -------------------- Управляющие структуры: развилки --------------------

// ---------- if_statement ----------

If_statement_node* If_statement_node::createIfStatementNode(if_type type, Expression_node *condition, Statement_node *trueBranch, Statement_node *falseBranch)
{
    If_statement_node *res = new If_statement_node;
    res->id = maxId++;
    res->IfType = type;
    res->type = IF_STATEMENT_TYPE;
    res->Condition = condition;
    res->TrueBranch = trueBranch;
    res->FalseBranch = falseBranch;
    return res;
}

// -------------------- Управляющие структуры: циклы --------------------

// ---------- while_statement ----------

While_statement_node* While_statement_node::createWhileStatementNode(Expression_node *condition, Statement_node *body)
{
    While_statement_node *res = new While_statement_node;
    res->id = maxId++;
    res->type = WHILE_STATEMENT_TYPE;
    res->LoopCondition = condition;
    res->LoopBody = body;
    return res;
}

// ---------- do_while_statement ----------

Do_while_statement_node* Do_while_statement_node::createDoWhileStatementNode(Expression_node *condition, Statement_node *body)
{
    Do_while_statement_node *res = new Do_while_statement_node;
    res->id = maxId++;
    res->type = DO_WHILE_STATEMENT_TYPE;
    res->LoopCondition = condition;
    res->LoopBody = body;
    return res;
}

// ---------- for_statement ----------

For_statement_node* For_statement_node::createForStatementNode(Expression_list_node *initExpression, Expression_node *condition, Expression_list_node *loopExpression, Statement_node *body)
{
    For_statement_node *res = new For_statement_node;
    res->id = maxId++;
    res->ForType = FOR_FOR_TYPE;
    res->type = FOR_STATEMENT_TYPE;
    res->InitExpression = initExpression;
    res->ConditionExpression = condition;
    res->LoopExpression = loopExpression;
    res->LoopBody = body;
    res->name = NULL;
    res->NameType = NULL;
    return res;
}

For_statement_node* For_statement_node::createForStatementNodeFromForWithDeclaration(Type_node *type, Init_declarator_list_node *initList, Expression_node *condition, Expression_list_node *loopExpression, Statement_node *body)
{
    For_statement_node *res = new For_statement_node;
    res->id = maxId++;
    res->ForType = FOR_WITH_DECLARATION_FOR_TYPE;
    res->type = FOR_STATEMENT_TYPE;
    res->InitExpression = NULL;
    res->ConditionExpression = condition;
    res->LoopExpression = loopExpression;
    res->LoopBody = body;
    res->NameType = type;
    res->InitList = initList;
    return res;
}

For_statement_node* For_statement_node::createForStatementNodeFromForeach(for_type type, Type_node *varType, char *loopVar, Expression_node *expression, Statement_node *body)
{
    For_statement_node *res = new For_statement_node;
    res->id = maxId++;
    res->ForType = type;
    res->type = FOR_STATEMENT_TYPE;
    res->InitExpression = NULL;
    res->LoopExpression = NULL;
    res->ConditionExpression = expression;
    res->LoopBody = body;
    res->name = loopVar;
    res->NameType = varType;
    return res;
}

// -------------------- Операторы --------------------

// ---------- statement ----------

Statement_node* Statement_node::createStatementNodeFromSimpleStatement(statement_type type, Expression_node *expression)
{
    Statement_node *res = new Statement_node;
    res->id = maxId++;
    res->type = type;
    res->Expression = expression;
    res->Next = NULL;
    return res;
}

// ---------- statement_list ----------

Statement_list_node* Statement_list_node::createStatementListNode(Statement_node *statement)
{
    Statement_list_node *res = new Statement_list_node;
    res->id = maxId++;
    res->type = COMPOUND_STATEMENT_TYPE;
    res->First = statement;
    res->Last = statement;
    return res;
}

Statement_list_node* Statement_list_node::addToStatementListNode(Statement_list_node *list, Statement_node *statement)
{
    list->Last->Next = statement;
    list->Last = statement;
    return list;
}


// -------------------- Классы --------------------

// ---------- class_interface ----------

Class_interface_node* Class_interface_node::createClassInterfaceNode(char *className, char *superclassName, Interface_body_node *body)
{
    Class_interface_node *res = new Class_interface_node;
    res->id = maxId++;
    res->type = INTERFACE_CLASS_BLOCK_TYPE;
    res->ClassName = className;
    res->SuperclassName = superclassName;
    res->Body = body;

    string classStr = className;
    ClassNames.insert(classStr);
    if (superclassName!= NULL)
    {
        string superClassStr = superclassName;
        ClassNames.insert(superClassStr);
    }
    return res;
}

// ---------- interface_body ----------

Interface_body_node* Interface_body_node::createInterfaceBodyNode(Instance_variables_declaration_list_node *variables, Interface_declaration_list_node *declarationList)
{
    Interface_body_node *res= new Interface_body_node;
    res->id = maxId++;
    res->Variables = variables;
    res->Declaration_list = declarationList;
    return res;
}

// ---------- implementation_body ----------

Implementation_body_node* Implementation_body_node::createImplementationBodyNode(Instance_variables_declaration_list_node *variables, Implementation_definition_list_node *definitionList)
{
    Implementation_body_node *res= new Implementation_body_node;
    res->id = maxId++;
    res->Variables = variables;
    res->Declaration_list = definitionList;
    return res;
}

// ---------- class_implementation ----------

Class_implementation_node* Class_implementation_node::createClassImplementationNode(char *className, char *superclassName, Implementation_body_node *body)
{
    Class_implementation_node *res = new Class_implementation_node;
    res->id = maxId++;
    res->type = IMPLEMENTATION_CLASS_BLOCK_TYPE;
    res->ClassName = className;
    res->SuperclassName = superclassName;
    res->Body = body;

    string classStr = className;
    ClassNames.insert(classStr);
    if (superclassName!= NULL)
    {
        string superClassStr = superclassName;
        ClassNames.insert(superClassStr);
    }
    return res;
}

// ---------- class_declaration_list, class_list ----------

Class_list_node* Class_list_node::createClassListNode(char *className)
{
    Class_list_node *res = new Class_list_node;
    res->id = maxId++;
    res->Class_names = new vector<char*>;
    res->Class_names->push_back(className);

    string classStr = className;
    ClassNames.insert(classStr);
    return res;
}

Class_list_node* Class_list_node::addToClassListNode(Class_list_node *list, char *className)
{
    list->Class_names->push_back(className);
    string classStr = className;
    ClassNames.insert(classStr);
    return list;
}

Class_declaration_list_node* Class_declaration_list_node::createClassDeclarationListNode(Class_list_node *list)
{
    Class_declaration_list_node *res = new Class_declaration_list_node;
    res->id = maxId++;
    res->List = list;
    for(char * className : *list->Class_names)
    {
        string classStr = className;
        ClassNames.insert(classStr);
    }
    return res;
}

// ---------- instance_variables_declaration ----------

Instance_variables_declaration_node* Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(Type_node *type, Declarator_list_node *declaratorList)
{
    Instance_variables_declaration_node *res= new Instance_variables_declaration_node;
    res->id = maxId++;
    res->Type = type;
    res->DeclaratorList = declaratorList;
    res->Next = NULL;
    return res;
}

// ---------- instance_variables_declaration_list ----------

Instance_variables_declaration_list_node* Instance_variables_declaration_list_node::createInstanceVariablesDeclarationListNode(Instance_variables_declaration_node *declaration)
{
    Instance_variables_declaration_list_node *res= new Instance_variables_declaration_list_node;
    res->id = maxId++;
    res->First = declaration;
    res->Last = declaration;
    return res;
}

Instance_variables_declaration_list_node* Instance_variables_declaration_list_node::addToInstanceVariablesDeclarationListNode(Instance_variables_declaration_list_node *list, Instance_variables_declaration_node *declaration)
{
    list->Last->Next = declaration;
    list->Last = declaration;
    return list;
}

// ---------- interface_declaration_list ----------

Interface_declaration_list_node* Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(Declaration_node *interfaceDeclaration)
{
    Interface_declaration_list_node *res = new Interface_declaration_list_node;
    res->id = maxId++;
    res->Declarations = new vector<interface_declaration>;
    struct interface_declaration Declaration;
    Declaration.declaration = interfaceDeclaration;
    Declaration.method_declaration = NULL;
    Declaration.property = NULL;
    res->Declarations->push_back(Declaration);
    return res;
}

Interface_declaration_list_node* Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(Property_node *interfaceDeclaration)
{
    Interface_declaration_list_node *res = new Interface_declaration_list_node;
    res->id = maxId++;
    res->Declarations = new vector<interface_declaration>;
    struct interface_declaration Declaration;
    Declaration.property = interfaceDeclaration;
    Declaration.method_declaration = NULL;
    Declaration.declaration = NULL;
    res->Declarations->push_back(Declaration);
    return res;
}

Interface_declaration_list_node* Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(Method_declaration_node *interfaceDeclaration)
{
    Interface_declaration_list_node *res = new Interface_declaration_list_node;
    res->id = maxId++;
    res->Declarations = new vector<interface_declaration>;
    struct interface_declaration Declaration;
    Declaration.method_declaration = interfaceDeclaration;
    Declaration.declaration = NULL;
    Declaration.property = NULL;
    res->Declarations->push_back(Declaration);
    return res;
}

Interface_declaration_list_node* Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(Interface_declaration_list_node *list, Declaration_node *interfaceDeclaration)
{
    struct interface_declaration Declaration;
    Declaration.declaration = interfaceDeclaration;
    Declaration.method_declaration = NULL;
    Declaration.property = NULL;
    list->Declarations->push_back(Declaration);
    return list;
}

Interface_declaration_list_node* Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(Interface_declaration_list_node *list, Property_node *interfaceDeclaration)
{
    interface_declaration Declaration;
    Declaration.property = interfaceDeclaration;
    Declaration.method_declaration = NULL;
    Declaration.declaration = NULL;
    list->Declarations->push_back(Declaration);
    return list;
}

Interface_declaration_list_node* Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(Interface_declaration_list_node *list, Method_declaration_node *interfaceDeclaration)
{
    interface_declaration Declaration;
    Declaration.method_declaration = interfaceDeclaration;
    Declaration.declaration = NULL;
    Declaration.property = NULL;
    list->Declarations->push_back(Declaration);
    return list;
}

// ---------- method_declaration, class_method_declaration, instance_method_declaration ----------

Method_declaration_node* Method_declaration_node::createMethodDeclarationNode(method_declaration_type type, Type_node *methodType, Method_selector_node *selector)
{
    Method_declaration_node *res = new Method_declaration_node;
    res->id = maxId++;
    res->type = type;
    res->MethodType = methodType;
    res->MethodSelector = selector;
    return res;
}

// ---------- implementation_definition_list ----------

Implementation_definition_list_node* Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(Declaration_node *implementationDefinition)
{
    Implementation_definition_list_node *res = new Implementation_definition_list_node;
    res->id = maxId++;
    res->Definitions = new vector<implementation_definition>;
    struct implementation_definition Definition;
    Definition.declaration = implementationDefinition;
    Definition.method_definition = NULL;
    Definition.synthesize = NULL;
    res->Definitions->push_back(Definition);
    return res;
}

Implementation_definition_list_node* Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(Method_definition_node *implementationDefinition)
{
    Implementation_definition_list_node *res = new Implementation_definition_list_node;
    res->id = maxId++;
    res->Definitions = new vector<implementation_definition>;
    struct implementation_definition Definition;
    Definition.method_definition = implementationDefinition;
    Definition.declaration = NULL;
    Definition.synthesize = NULL;
    res->Definitions->push_back(Definition);
    return res;
}

Implementation_definition_list_node* Implementation_definition_list_node::createImplementationDefinitionListNodeFromSynthesize(char *implementationDefinition)
{
    Implementation_definition_list_node *res = new Implementation_definition_list_node;
    res->id = maxId++;
    res->Definitions = new vector<implementation_definition>;
    struct implementation_definition Definition;
    Definition.synthesize = implementationDefinition;
    Definition.declaration = NULL;
    Definition.method_definition = NULL;
    res->Definitions->push_back(Definition);
    return res;
}

Implementation_definition_list_node* Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(Implementation_definition_list_node *list, Declaration_node *implementationDefinition)
{
    struct implementation_definition Definition;
    Definition.declaration = implementationDefinition;
    Definition.method_definition = NULL;
    Definition.synthesize = NULL;
    list->Definitions->push_back(Definition);
    return list;
}

Implementation_definition_list_node* Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(Implementation_definition_list_node *list, Method_definition_node *implementationDefinition)
{
    struct implementation_definition Definition;
    Definition.method_definition = implementationDefinition;
    Definition.declaration = NULL;
    Definition.synthesize = NULL;
    list->Definitions->push_back(Definition);
    return list;
}

Implementation_definition_list_node* Implementation_definition_list_node::addSynthesizeToImplementationDefinitionListNode(Implementation_definition_list_node *list, char *implementationDefinition)
{
    implementation_definition Definition;
    Definition.synthesize = implementationDefinition;
    Definition.declaration = NULL;
    Definition.method_definition = NULL;
    list->Definitions->push_back(Definition);
    return list;
}

// ---------- method_definition, class_method_definition, instance_method_definition ----------

Method_definition_node* Method_definition_node::createMethodDefinitionNode(method_definition_type type, Type_node *methodType, Method_selector_node *selector, Declaration_list_node *declarationList, Statement_list_node *methodBody)
{
    Method_definition_node *res = new Method_definition_node;
    res->id = maxId++;
    res->type = type;
    res->MethodType = methodType;
    res->MethodSelector = selector;
    res->DeclarationList = declarationList;
    res->MethodBody = methodBody;
    res->Next = NULL;
    return res;
}

// ---------- method_selector ----------

Method_selector_node* Method_selector_node::createMethodSelectorNode(char *methodName,Keyword_declaration_node *keywordDeclaration, Keyword_selector_node *selector, Parameter_list_node *parameters)
{
    Method_selector_node *res = new Method_selector_node;
    res->id = maxId++;
    res->MethodName = methodName;
    res->KeywordSelector = selector;
    res->ParameterListNode = parameters;
    res->KeywordDeclaration = keywordDeclaration;
    return res;
}

// ---------- keyword_selector ----------

Keyword_selector_node* Keyword_selector_node::createKeywordSelectorNode(Keyword_declaration_node *declaration)
{
    Keyword_selector_node *res = new Keyword_selector_node;
    res->id = maxId++;
    res->First = declaration;
    res->Last = declaration;
    return res;
}

Keyword_selector_node* Keyword_selector_node::addToKeywordSelectorNode(Keyword_selector_node *list, Keyword_declaration_node *declaration)
{
    list->Last->Next = declaration;
    list->Last = declaration;
    return list;
}

// ---------- keyword_declaration ----------

Keyword_declaration_node* Keyword_declaration_node::createKeywordDeclarationNode(Type_node *type, char *identifier, char *keywordName)
{
    Keyword_declaration_node *res = new Keyword_declaration_node;
    res->id = maxId++;
    res->KeywordType = type;
    res->Identifier = identifier;
    res->KeywordName = keywordName;
    res->Next = NULL;
    return res;
}

// ---------- property ----------

Property_node* Property_node::createPropertyNode(Attribute_node *attribute, Type_node *type, char *name)
{
    Property_node *res = new Property_node;
    res->id = maxId++;
    res->Attribute = attribute;
    res->type = type;
    res->Name = name;
    res->Next = NULL;
    return res;
}

// ---------- attribute ----------

Attribute_node* Attribute_node::createAttributeNode(attrribute_type type)
{
    Attribute_node *res = new Attribute_node;
    res->id = maxId++;
    res->type = type;
    return res;
}


// ------------------------------ ФУНКЦИИ ПОСТРОЕНИЯ ДЕРЕВА ------------------------------

// -------------------- Типы --------------------

// ---------- Type_node ----------

string Type_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection != "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"";
    switch (type)
    {
        case INT_TYPE:
            res += "int";
            break;
        case CHAR_TYPE:
            res += "char";
            break;
        case FLOAT_TYPE:
            res += "float";
            break;
        case ID_TYPE:
            res += "id";
            break;
        case CLASS_NAME_TYPE:
            res += "class_name: ";
            res += ClassName;
            break;
        case VOID_TYPE:
            res += "void";
            break;
        default:
            break;
    }
    res += "\"];\n";
    return res;
}

// -------------------- Константы --------------------

// ---------- Numeric_constant_node ----------

string Numeric_constant_node::toDot()
{
    string res = "->" + to_string(id) + ";\n";
    if (type == INTEGER_CONSTANT_TYPE)
    {
        res += to_string(id) + "[label=\"" + to_string(number.Int) + "\"];\n";
    }
    else if (type == FLOAT_CONSTANT_TYPE)
    {
        res += to_string(id) + "[label=\"" + to_string(number.Float) + "\"];\n";
    }
    
    return res;
}

// ---------- Literal_node ----------

string Literal_node::toDot()
{
    string res = "->" + to_string(id) + ";\n";
    res += to_string(id) + "[label=<";
    if (type == STRING_CONSTANT_TYPE)
    {
        res += "\"";
        res += value;
        res += "\"";
    }
    else if (type == CHAR_CONSTANT_TYPE)
    {
        res += "'";
        res += value;
        res += "'";
    }
    else if (type == NSSTRING_CONSTANT_TYPE)
    {
        res += "@\"";
        res += value;
        res += "\"";
    }
    res += ">];\n";
    return res;
}

// -------------------- Объявления --------------------

// ---------- Declaration_node ----------

string Declaration_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
        
    res += ";\n";
    res += to_string(id) + "[label=\"declaration\"];\n";
    res += to_string(id);
    res += type->toDot();
    if (init_declarator_list != NULL)
    {
        res += to_string(id);
        res += init_declarator_list->toDot();
    }
    return res;
}

// ---------- Declaration_list_node ----------

vector<Declaration_node*>* Declaration_list_node::getElements()
{
    vector<Declaration_node*>* res = new vector<Declaration_node*>;
    Declaration_node *current = First;
    res->push_back(current);
    while (current->Next!= NULL)
    {
        current = current->Next;
        res->push_back(current);
    }
    return res;
}

string Declaration_list_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"declaration_list\"];\n";
    vector<Declaration_node*>* elements = getElements();
    for (int i = 0; i < elements->size(); i++)
    {
        res += to_string(id);
        res += elements->at(i)->toDot();
    }
    delete elements;
    return res;
}

// ---------- Init_declarator_list_node ----------

vector<Init_declarator_node*>* Init_declarator_list_node::getElements()
{
    vector<Init_declarator_node*>* res = new vector<Init_declarator_node*>;
    Init_declarator_node *current = First;
    res->push_back(current);
    while (current->Next!= NULL)
    {
        current = current->Next;
        res->push_back(current);
    }
    return res;
}

string Init_declarator_list_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"init_declarator_list\"];\n";
    vector<Init_declarator_node*>* elements = getElements();
    for (int i = 0; i < elements->size(); i++)
    {
        res += to_string(id);
        res += elements->at(i)->toDot(to_string(i));
    }
    delete elements;
    return res;
}

// ---------- Init_declarator_node ----------

string Init_declarator_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection != "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"init_declarator\"];\n";
    res += to_string(id) + ".1 [label=\"" + Declarator + "\"];\n";
    res += to_string(id) + "->" + to_string(id) + ".1[label=\"declarator\"];\n";
    if (type == DECLARATOR_WITH_INITIALIZING_TYPE)
    {
        res += to_string(id);
        res += expression->toDot("expression"); 
    }
    if (type == ARRAY_DECLARATOR_TYPE)
    {
        if (ArraySize!= NULL)
        {
            res += to_string(id);
            res += ArraySize->toDot("array_size");
        }
    }
    if (type == ARRAY_WITH_INITIALIZING_DECLARATOR_TYPE)
    {
        if (ArraySize!= NULL)
        {
            res += to_string(id);
            res += ArraySize->toDot("array_size");
        }
        if (expression!= NULL)
        {
            res += to_string(id);
            res += expression->toDot("expression");
        }
        if (InitializerList != NULL)
        {
            res += to_string(id);
            res += InitializerList->toDot("initializer_list");
        }
    }
    return res;
}

// ---------- Declarator_node ----------

string Declarator_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"declarator\"];\n";
    res += to_string(id) + ".1 [label=\"" + Identifier + "\"];\n";
    res += to_string(id) + "->" + to_string(id) + ".1[label=\"identifier\"];\n";
    if (Expression!= NULL)
    {
        res += to_string(id);
        res += Expression->toDot("array_size");
    }
    return res;
}

// ---------- Declarator_list_node ----------

string Declarator_list_node::toDot(string labelConection)
{
    string res = "->" + to_string(id); 
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]"; 
    res+= ";\n";
    res += to_string(id) + "[label=\"declarator_list\"];\n";
    for (int i = 0; i < Declarators->size(); i++)
    {
        res += to_string(id);
        res += Declarators->at(i)->toDot(to_string(i));
    }
    return res;
}

// ---------- Parameter_list ----------

vector<Parameter_declaration_node*>* Parameter_list_node::getElements()
{
    vector<Parameter_declaration_node*>* res = new vector<Parameter_declaration_node*>;
    Parameter_declaration_node *current = First;
    res->push_back(current);
    while (current->Next!= NULL)
    {
        current = current->Next;
        res->push_back(current);
    }
    return res;
}

string Parameter_list_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]"; 
    res += ";\n";
    res += to_string(id) + "[label=\"parameter_list\"];\n";
    vector<Parameter_declaration_node*>* elements = getElements();
    for (int i = 0; i < elements->size(); i++)
    {
        res += to_string(id);
        res += elements->at(i)->toDot(to_string(i));
    }
    delete elements;
    return res;
}

// ---------- Parameter_declaration_node ----------

string Parameter_declaration_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"parameter_declaration :"; 
    res += name;
    res += "\"];\n";
    res += to_string(id);
    res += type->toDot("type");
    return res;
}

// -------------------- Выражения --------------------

// ---------- Expression_node ----------

string Expression_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    if (isPriority)
        res += to_string(id) + "[label=\"(expression)\"];\n";
    else
        res += to_string(id) + "[label=\"expression\"];\n";
    if (type == IDENTIFIER_EXPRESSION_TYPE)
    {
        res += to_string(id);
        res += "->";
        res += to_string(id) + ".1 [label=\"identifier\"];";
        res += to_string(id) + ".1";
        res += "[label=\"";
        res += name;
        res += "\"];\n";
    }
    else if (type == LITERAL_EXPRESSION_TYPE)
    {
        res += to_string(id);
        res += constant.literal->toDot();
    }
    else if (type == NUMERIIC_CONSTANT_EXPRESSION_TYPE)
    {
        res += to_string(id);
        res += constant.num->toDot();
    }
    else if (type == SELF_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(self_expression)\"];\n";
        else
            res += "[label=\"self_expression\"];\n"; 
    }
    else if (type == SUPER_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(super_expression)\"];\n";
        else 
            res += "[label=\"super_expression\"];\n";
    }
    else if (type == MESSAGE_EXPRESSION_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(message_expression)\"];\n";
        else
            res += "[label=\"message_expression\"];\n";
        res += to_string(id);
        res += Receiver->toDot("receiver");
        res += to_string(id);
        res += Arguments->toDot("arguments");
    }
    else if (type == FUNCTION_CALL_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(function_call_expression)\"];\n";
        else
            res += "[label=\"function_call_expression\"];\n";
        res += to_string(id) + ".1 [label=\""+ name +"\"];\n";
        res += to_string(id) + "->" + to_string(id) + ".1 [label=\"name\"];\n";
        res += to_string(id);
        res += ArgumentsList->toDot("arguments_list");
    }
    else if (type == UMINUS_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(-)\"];\n";
        else
            res += "[label=\"-\"];\n";
        res += to_string(id);
        res += Right->toDot();
    }
    else if (type == UPLUS_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(+)\"];\n";
        else
            res += "[label=\"+\"];\n";
        res += to_string(id);
        res += Right->toDot();
    }
    else if (type == UAMPERSAND_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(&)\"];\n";
        else
            res += "[label=\"&\"];\n";
        res += to_string(id);
        res += Right->toDot();
    }
    else if (type == PLUS_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(+)\"];\n";
        else
            res += "[label=\"+\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id);
        res += Right->toDot("right");
    }
    else if (type == MINUS_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(-)\"];\n";
        else
            res += "[label=\"-\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id);
        res += Right->toDot("right");
    }
    else if (type == MUL_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(*)\"];\n";
        else
            res += "[label=\"*\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id);
        res += Right->toDot("right");
    }
    else if (type == DIV_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(/)\"];\n";
        else
            res += "[label=\"/\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id);
        res += Right->toDot("right");
    }
    else if (type == EQUAL_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(==)\"];\n";
        else
            res += "[label=\"==\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id);
        res += Right->toDot("right");
    }
    else if (type == NOT_EQUAL_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(!=)\"];\n";
        else
            res += "[label=\"!=\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id);
        res += Right->toDot("right");
    }
    else if (type == GREATER_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(>)\"];\n";
        else
            res += "[label=\">\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id);
        res += Right->toDot("right");
    }
    else if (type == LESS_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(<)\"];\n";
        else
            res += "[label=\"<\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id);
        res += Right->toDot("right");
    }
    else if (type == GREATER_EQUAL_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(>=)\"];\n";
        else
            res += "[label=\">=\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id);
        res += Right->toDot("right");
    }
    else if (type == LESS_EQUAL_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(<=)\"];\n";
        else
            res += "[label=\"<=\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id);
        res += Right->toDot("right");
    }
    else if (type == ASSIGNMENT_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(=)\"];\n";
        else
            res += "[label=\"=\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id);
        res += Right->toDot("right");
    }
    else if (type == DOT_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(.)\"];\n";
        else
            res += "[label=\".\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id) + ".1 [label=\"" + name + "\"];\n";
        res += to_string(id) + "->" + to_string(id) + ".1 [label=\"name\"];\n";
    }
    else if (type == ARROW_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"(->)\"];\n";
        else
            res += "[label=\"->\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id) + ".1 [label=\"" + name + "\"];\n";
        res += to_string(id) + "->" + to_string(id) + ".1 [label=\"name\"];\n";
    }
    else if (type == ARRAY_ELEMENT_ACCESS_EXPRESSION_TYPE)
    {
        res += to_string(id);
        if (isPriority)
            res += "[label=\"([])\"];\n";
        else
            res += "[label=\"[]\"];\n";
        res += to_string(id);
        res += Left->toDot("left");
        res += to_string(id);
        res += Right->toDot("right");
    }

    return res;
}

// ---------- Expression_list_node ----------

vector<Expression_node*>* Expression_list_node::getElements()
{
    vector<Expression_node*> *res = new vector<Expression_node*>;
    Expression_node *current = First;
    res->push_back(current);
    while (current->Next!= NULL)
    {
        current = current->Next;
        res->push_back(current);
    }
    return res;
}

string Expression_list_node::toDot(string labelConection)
{
    string res = "->" + to_string(id); 
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res+= ";\n";
    res += to_string(id) + "[label=\"expression_list\"];\n";
    vector<Expression_node*>* elements = getElements();
    for (int i = 0; i < elements->size(); i++)
    {
        res += to_string(id);
        res += elements->at(i)->toDot(to_string(i));
    }
    delete elements;
    return res;
}

// ---------- Receiver_node ----------

string Receiver_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    if (Type == SUPER_RECEIVER_TYPE)
        res += to_string(id) + "[label=\"receiver: super\"];\n";
    else if (Type == SELF_RECEIVER_TYPE)
        res += to_string(id) + "[label=\"receiver: self\"];\n";
    else if (Type == OBJECT_NAME_RECEIVER_TYPE)
    {
        res += to_string(id) + "[label=\"receiver: object_name\"];\n";
        res += to_string(id) + ".1 [label=\"" + name + "\"];\n";
        res += to_string(id) + "->" + to_string(id) + ".1 [label=\"name\"];\n";
    }
    else if (Type == CLASS_NAME_RECEIVER_TYPE)
    {
        res += to_string(id) + "[label=\"receiver: class_name\"];\n";
        res += to_string(id) + ".1 [label=\"" + name + "\"];\n";
        res += to_string(id) + "->" + to_string(id) + ".1 [label=\"name\"];\n";
    }
    else if (Type == MESSAGE_EXPRESSION_RECEIVER_TYPE)
    {
        res += to_string(id) + "[label=\"receiver: message_expression\"];\n";
        res += to_string(id);
        res += Receiver->toDot("receiver");
        res += to_string(id);
        res += Arguments->toDot("arguments");
    }
    
    return res;
}

// ---------- Message_selector_node ----------

string Message_selector_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"message_selector\"];\n";
    res += to_string(id) + ".1 [label=\"" + MethodName + "\"];\n";
    res += to_string(id) + "->" + to_string(id) + ".1 [label=\"method name\"]; \n";
    if (Arguments!= NULL)
    {
        res += to_string(id);
        res += Arguments->toDot("arguments");
    }
    if (Expression != NULL)
    {
        res += to_string(id);
        res += Expression->toDot("expression");
    }
    if (ExprArguments!= NULL)
    {
        res += to_string(id);
        res += ExprArguments->toDot("expr_arguments");
    }

    return res;
}

// ---------- Keyword_argument_list_node ----------

vector<Keyword_argument_node*>* Keyword_argument_list_node::getElements()
{
    vector<Keyword_argument_node*> *res = new vector<Keyword_argument_node*>;
    Keyword_argument_node *current = First;
    res->push_back(current);
    while (current->Next!= NULL)
    {
        current = current->Next;
        res->push_back(current);
    }
    return res;
}

string Keyword_argument_list_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"keyword_argument_list\"];\n";
    vector<Keyword_argument_node*>* elements = getElements();
    for (int i = 0; i < elements->size(); i++)
    {
        res += to_string(id);
        res += elements->at(i)->toDot(to_string(i));
    }
    delete elements;
    return res;
}

// ---------- Keyword_argument_node ----------

string Keyword_argument_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"keyword_argument\"];\n";

    if (type == WITH_IDENTIFIER_KW_ARGUMENT_TYPE)
    {
        res += to_string(id) + ".1 [label=\"" + name + "\"];\n";
        res += to_string(id) + "->" + to_string(id) + ".1 [label=\"identifier\"]; \n";
    }

    res += to_string(id);
    res += expression->toDot("expression");
    return res;
}

// -------------------- Операторы --------------------

// ---------- Statement_node ----------

string Statement_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    if (type == EMPTY_STATEMENT_TYPE)
    {
        res += to_string(id) + "[label=\"empty_statement\"];\n";
    }
    else if (type == SIMPLE_STATEMENT_TYPE)
    {
        res += to_string(id) + "[label=\"simple_statement\"];\n";
        res += to_string(id);
        res += Expression->toDot("expression");
    }
    else if (type == RETURN_STATEMENT_TYPE)
    {
        res += to_string(id) + "[label=\"return_statement\"];\n";
        if (Expression!= NULL)
        {
            res += to_string(id);
            res += Expression->toDot("expression");
        }
    }
    return res;
}

// ----------- If_statement_node ----------

string If_statement_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"if\"];\n";
    
    res += to_string(id);
    res += Condition->toDot("condition");

    res += to_string(id);
    res += TrueBranch->toDot("true");

    if (FalseBranch!= NULL)
    {
        res += to_string(id);
        res += FalseBranch->toDot("false");
    }
    return res;
}

// ----------- While_statement_node ----------

string While_statement_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"while\"];\n";
    
    res += to_string(id);
    res += LoopCondition->toDot("condition");
    
    res += to_string(id);
    res += LoopBody->toDot("body");
    
    return res;
}

// ---------- Do_while_statement_node ----------

string Do_while_statement_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"do_while\"];\n";
    
    res += to_string(id);
    res += LoopCondition->toDot("condition");

    res += to_string(id);
    res += LoopBody->toDot("body");
    
    return res;
}

// ---------- For_statement_node ----------

string For_statement_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"for\"];\n";
    
    if (ForType == FOR_FOR_TYPE)
    {
        if (InitExpression!= NULL)
        {
            res += to_string(id);
            res += InitExpression->toDot("init_expression");
        }
        if (ConditionExpression!= NULL)
        {
            res += to_string(id);
            res += ConditionExpression->toDot("condition_expression");
        }
        if (LoopExpression!= NULL)
        {
            res += to_string(id);
            res += LoopExpression->toDot("loop_expression");
        }

        res += to_string(id);
        res += LoopBody->toDot("body");
    }
    else if (ForType == FOR_WITH_DECLARATION_FOR_TYPE)
    {
        res += to_string(id);
        res += NameType->toDot("type");

        res += to_string(id);
        res += InitList->toDot("init_list");

        if (ConditionExpression!= NULL)
        {
            res += to_string(id);
            res += ConditionExpression->toDot("condition_expression");
        }
        if (LoopExpression!= NULL)
        {
            res += to_string(id);
            res += LoopExpression->toDot("loop_expression");
        }
        res += to_string(id);
        res += LoopBody->toDot("body");
    }
    else if (ForType == FOREACH_FOR_TYPE)
    {
        res += to_string(id) + ".1 [label=\"" + name + "\"];\n";
        res += to_string(id) + "->" + to_string(id) + ".1 [label=\"identifier\"];\n";

        res += to_string(id);
        res += ConditionExpression->toDot("expression");

        res += to_string(id);
        res += LoopBody->toDot("body");
    }
    else if (ForType == FOREACH_WITH_DECLARATION_FOR_TYPE)
    {
        res += to_string(id);
        res += NameType->toDot("type");

        res += to_string(id) + ".1 [label=\"" + name + "\"];\n";
        res += to_string(id) + "->" + to_string(id) + ".1 [label=\"identifier\"];\n";

        res += to_string(id);
        res += ConditionExpression->toDot("expression");

        res += to_string(id);
        res += LoopBody->toDot("body");
    }
    return res;
}


// ---------- Statement_list_node ----------

vector<Statement_node*>* Statement_list_node::getElements()
{
    vector<Statement_node*>* res = new vector<Statement_node*>;
    Statement_node *current = First;
    res->push_back(current);
    while (current->Next!= NULL)
    {
        current = current->Next;
        res->push_back(current);
    }
    return res;
}

string Statement_list_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"statement_list\"];\n";

    vector<Statement_node*>* elements = getElements();
    for (int i = 0; i < elements->size(); i++)
    {
        res += to_string(id);
        res += elements->at(i)->toDot(to_string(i));
    }
    delete elements;
    return res;
}

// -------------------- Классы --------------------


string Class_block_node::toDot(string labelConection)
{
    return string();
}

// ---------- Class_interface_node ----------

string Class_interface_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"class_interface\"];\n";

    res += to_string(id) + ".1 [label=\"" + ClassName + "\"];\n";
    res += to_string(id) + "->" + to_string(id) + ".1 [label=\"class name\"];\n";

    if (SuperclassName!= NULL)
    {
        res += to_string(id) + ".2 [label=\"" + SuperclassName + "\"];\n";
        res += to_string(id) + "->" + to_string(id) + ".2 [label=\"superclass name\"];\n";
    }

    if (Body != NULL)
    {
        res += to_string(id);
        res += Body->toDot("body");
    }

    return res;
}

// ---------- Interface_body_node ----------

string Interface_body_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"interface_body\"];\n";

    if (Variables!= NULL)
    {
        res += to_string(id);
        res += Variables->toDot("variables");
    }

    if (Declaration_list != NULL)
    {
        res += to_string(id);
        res += Declaration_list->toDot("declaration_list");
    }

    return res;
}

// ---------- Implementation_body_node ----------

string Implementation_body_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"implementation_body\"];\n";

    if (Variables!= NULL)
    {
        res += to_string(id);
        res += Variables->toDot("variables");
    }

    if (Declaration_list != NULL)
    {
        res += to_string(id);
        res += Declaration_list->toDot("definition_list");
    }

    return res;
}

// ---------- Class_implementation_node ----------

string Class_implementation_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"class_implementation\"];\n";

    res += to_string(id) + ".1 [label=\"" + ClassName + "\"];\n";
    res += to_string(id) + "->" + to_string(id) + ".1 [label=\"class name\"];\n";

    if (SuperclassName!= NULL)
    {
        res += to_string(id) + ".2 [label=\"" + SuperclassName + "\"];\n";
        res += to_string(id) + "->" + to_string(id) + ".2 [label=\"superclass name\"];\n";
    }

    if (Body!= NULL)
    {
        res += to_string(id);
        res += Body->toDot("body");
    }
    return res;
}

// ---------- Class_declaration_list_node ----------

string Class_declaration_list_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"class_declaration_list\"];\n";

    res += to_string(id);
    res += List->toDot();

    return res;
}

// ---------- Class_list_node ----------

string Class_list_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"class_list\"];\n";

    for (int i = 0; i < Class_names->size(); i++)
    {
        res += to_string(id) + "." + to_string(i) + " [label=\"" + Class_names->at(i) + "\"];\n";
        res += to_string(id) + "->" + to_string(id) + "." + to_string(i) + " [label=\"" + to_string(i) + "\"];\n";
    }

    return res;
}

// ---------- Instance_variables_declaration_node ----------

string Instance_variables_declaration_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"instance_variables_declaration\"];\n";

    res += to_string(id);
    res += Type->toDot("type");

    res += to_string(id);
    res += DeclaratorList->toDot("declarator_list");

    return res;
}

// ---------- Instance_variables_declaration_list_node ----------

vector<Instance_variables_declaration_node*>* Instance_variables_declaration_list_node::getElements()
{
    vector<Instance_variables_declaration_node*>* res = new vector<Instance_variables_declaration_node*>;
    Instance_variables_declaration_node *current = First;
    res->push_back(current);
    while (current->Next!= NULL)
    {
        current = current->Next;
        res->push_back(current);
    }
    return res;
}

string Instance_variables_declaration_list_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"instance_variables_declaration_list\"];\n";

    vector<Instance_variables_declaration_node*>* elements = getElements();
    for (int i = 0; i < elements->size(); i++)
    {
        res += to_string(id);
        res += elements->at(i)->toDot(to_string(i));
    }

    return res;
}

// ---------- Interface_declaration_list_node ----------

string Interface_declaration_list_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"interface_declaration_list\"];\n";

    for (int i = 0; i < Declarations->size(); i++)
    {
        res += to_string(id);
        if (Declarations->at(i).declaration != NULL)
            res += Declarations->at(i).declaration->toDot(to_string(i));
        else if (Declarations->at(i).property != NULL)
            res += Declarations->at(i).property->toDot(to_string(i));
        else if (Declarations->at(i).method_declaration != NULL)
            res += Declarations->at(i).method_declaration->toDot(to_string(i));
    }

    return res;
}

// ---------- Method_declaration_node ----------

string Method_declaration_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    
    if (type == CLASS_METHOD_DECLARATION_TYPE)
        res += to_string(id) + "[label=\"class_method_declaration\"];\n";
    else if (type == INSTANCE_METHOD_DECLARATION_TYPE)
        res += to_string(id) + "[label=\"instance_method_declaration\"];\n";
    
    if (MethodType != NULL)
    {
        res += to_string(id);
        res += MethodType->toDot("method_type");
    }

    res += to_string(id);
    res += MethodSelector->toDot("selector");

    return res;
}

// ---------- Implementation_definition_list_node ----------

string Implementation_definition_list_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"implementation_definition_list\"];\n";

    for (int i = 0; i < Definitions->size(); i++)
    {
        if (Definitions->at(i).declaration!= NULL)
        {
            res += to_string(id);
            res += Definitions->at(i).declaration->toDot(to_string(i));
        }
        else if (Definitions->at(i).method_definition!= NULL)
        {
            res += to_string(id);
            res += Definitions->at(i).method_definition->toDot(to_string(i));
        }
        else if (Definitions->at(i).synthesize!= NULL)
        {
            res += to_string(id) + ".1 [label=\"synthesize: " + Definitions->at(i).synthesize + "\"];\n";
            res += to_string(id) + "->" + to_string(id) + ".1 [label=\"" + to_string(i) + "\"];\n";
        }
    }

    return res;
}

// ---------- Method_definition_node ----------

string Method_definition_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    
    if (type == CLASS_METHOD_DEFINITION_TYPE)
        res += to_string(id) + "[label=\"class_method_definition\"];\n";
    else if (type == INSTANCE_METHOD_DEFINITION_TYPE)
        res += to_string(id) + "[label=\"instance_method_definition\"];\n";

    if (MethodType!= NULL)
    {
        res += to_string(id);
        res += MethodType->toDot("method_type");
    }

    res += to_string(id);
    res += MethodSelector->toDot("selector");

    if (DeclarationList != NULL)
    {
        res += to_string(id);
        res += DeclarationList->toDot("declaration_list");
    }

    if (MethodBody != NULL)
    {
        res += to_string(id);
        res += MethodBody->toDot("body");
    }

    return res;
}

// ---------- Method_selector_node ----------

string Method_selector_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"method_selector\"];\n";

    res += to_string(id) + "->" + to_string(id) + ".1 [label=\"method_name\"];\n";
    res += to_string(id) + ".1 [label=\"" + MethodName + "\"];\n";

    if (KeywordSelector != NULL)
    {
        res += to_string(id);
        res += KeywordSelector->toDot("keyword_selector");
    }

    if (ParameterListNode != NULL)
    {
        res += to_string(id);
        res += ParameterListNode->toDot("parameter_list");
    }

    if (KeywordDeclaration != NULL)
    {
        res += to_string(id);
        res += KeywordDeclaration->toDot("keyword_parameters");
    }

    return res;
}

// ---------- Keyword_selector_node ----------

vector<Keyword_declaration_node*>* Keyword_selector_node::getElements()
{
    vector<Keyword_declaration_node*>* res = new vector<Keyword_declaration_node*>;
    Keyword_declaration_node *current = First;
    res->push_back(current);
    while (current->Next!= NULL)
    {
        current = current->Next;
        res->push_back(current);
    }
    return res;
}

string Keyword_selector_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"];\n";
    res += to_string(id) + "[label=\"keyword_selector\"];\n";
    
    vector<Keyword_declaration_node*>* elements = getElements();
    for (int i = 0; i < elements->size(); i++)
    {
        res += to_string(id);
        res += elements->at(i)->toDot(to_string(i));
    }
    
    return res;
}

// ---------- Keyword_declaration_node ----------

string Keyword_declaration_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"keyword_declaration\"];\n";

    if (KeywordType!= NULL)
    {
        res += to_string(id);
        res += KeywordType->toDot("keyword_type");
    }

    if (Identifier!= NULL)
    {
        res += to_string(id) + "->" + to_string(id) + ".1 [label=\"identifier\"];\n";
        res += to_string(id) + ".1 [label=\"" + Identifier + "\"];\n";
    }

    res += to_string(id) + "->" + to_string(id) + ".2 [label=\"keyword_name\"];\n";
    res += to_string(id) + ".2 [label=\"" + KeywordName + "\"];\n";

    return res;
}

// ---------- Property_node ----------

string Property_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"property\"];\n";

    if (Attribute != NULL)
    {
        res += to_string(id);
        res += Attribute->toDot("attribute_type");
    }

    res += to_string(id);
    res += type->toDot("type");

    res += to_string(id) + "->" + to_string(id) + ".1 [label=\"name\"];\n";
    res += to_string(id) + ".1 [label=\"" + Name + "\"];\n";

    return res;
}

// ---------- Attribute_node ----------

string Attribute_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id);
    
    if (type == READONLY_ATTRIBUTE_TYPE)
    {
        res += "[label=\"readonly\"];\n";
    }
    else if (type == READWRITE_ATTRIBUTE_TYPE)
    {
        res += "[label=\"readwrite\"];\n";
    }
    else if (type == EMPTY_ATTRIBUTE_TYPE)
    {
        res += "[label=\"empty\"];\n";
    }
    return res;
}

// -------------------- Program ----------------------

// ---------- Program_node ----------

string Program_node::toDot()
{
    string res = "digraph ObjectiveC { rankdir=\"LR\";\n";
    res += to_string(id) + "[label=\"program\"];\n";

    res += to_string(id);
    res += list->toDot();
    res += "}\n";
    return res;
}

// ---------- Function_and_class_list_node ----------

string Function_and_class_list_node::toDot()
{
    string res = "->" + to_string(id) + ";\n";
    res += to_string(id) + "[label=\"function_and_class_list\"];\n";

    for (int i = 0; i < FunctionsAndClasses->size(); i++)
    {
        res += to_string(id);
        if (FunctionsAndClasses->at(i).function!= NULL)
            res += FunctionsAndClasses->at(i).function->toDot(to_string(i));
        else if (FunctionsAndClasses->at(i).class_block!= NULL)
            res += FunctionsAndClasses->at(i).class_block->toDot(to_string(i));
        else if (FunctionsAndClasses->at(i).class_declaration_list!= NULL)
            res += FunctionsAndClasses->at(i).class_declaration_list->toDot(to_string(i));
    }

    return res;
}

// ---------- Function_node ----------

string Function_node::toDot(string labelConection)
{
    string res = "->" + to_string(id);
    if (labelConection!= "")
        res += "[label=\"" + labelConection + "\"]";
    res += ";\n";
    res += to_string(id) + "[label=\"function\"];\n";

    res += to_string(id);
    res += Type->toDot("type");

    res += to_string(id) + "->" + to_string(id) + ".1 [label=\"name\"];\n";
    res += to_string(id) + ".1 [label=\""; 
    res += Name;
    res += "\"];\n";

    if (statement != NULL)
    {
        res += to_string(id);
        res += statement->toDot("body");
    }
    return res;
}
