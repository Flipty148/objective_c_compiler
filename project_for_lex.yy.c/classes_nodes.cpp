#include "classes_nodes.h"
int maxId = 0; // Глобальный id узла
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
    res->First->function = functionList;
    res->Last->function = functionList;
    return res;
}

Function_and_class_list_node* Function_and_class_list_node::createFunctionAndClassListNodeFromClassDeclarationList(Class_declaration_list_node *classDeclarationList)
{
    Function_and_class_list_node *res = new Function_and_class_list_node;
    res->id = maxId++;
    res->First->class_declaration_list = classDeclarationList;
    res->Last->class_declaration_list = classDeclarationList;
    return res;
}

Function_and_class_list_node* Function_and_class_list_node::createFunctionAndClassListNodeFromClassBlock(Class_block_node *classBlock)
{
    Function_and_class_list_node *res = new Function_and_class_list_node;
    res->id = maxId++;
    res->First->class_block = classBlock;
    res->Last->class_block = classBlock;
    return res;
}

Function_and_class_list_node* Function_and_class_list_node::addToFunctionAndClassListNodeFromFunction(Function_and_class_list_node *list, Function_node *function)
{
    list->Last->function->Next = function;
    list->Last->function = function;
    return list;
}

Function_and_class_list_node* Function_and_class_list_node::addToFunctionAndClassListNodeFromClassDeclarationList(Function_and_class_list_node *list, Class_declaration_list_node *classDeclarationList)
{
    list->Last->class_declaration_list->Next = classDeclarationList;
    list->Last->class_declaration_list = classDeclarationList;
    return list;
}

Function_and_class_list_node* Function_and_class_list_node::addToFunctionAndClassListNodeFromClassBlock(Function_and_class_list_node *list, Class_block_node *classStatement)
{
    list->Last->class_block->Next = classStatement;
    list->Last->class_block = classStatement;
    return list;
}

// ---------- function ----------

Function_node* Function_node::createFunctionNode(Type_node *type, char *name, Compound_statement_node *statement)
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
    res->number->Int = number;
    return res;
}

Numeric_constant_node* Numeric_constant_node::createNumericConstantNodeFromFloat(float number)
{
    Numeric_constant_node *res = new Numeric_constant_node;
    res->id = maxId++;
    res->type = FLOAT_CONSTANT_TYPE;
    res->number->Float = number;
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

Init_declarator_node* Init_declarator_node::createInitDeclaratorNode(init_declarator_type type, Declarator_node *declarator, Expression_node *expression)
{
    Init_declarator_node *res = new Init_declarator_node;
    res->id = maxId++;
    res->type = type;
    res->Declarator = declarator;
    res->expression = expression;
    res->Next = NULL;
    return res;
}

// ---------- declarator ----------

Declarator_node* Declarator_node::createDeclaratorNode(char *name)
{
    Declarator_node *res = new Declarator_node;
    res->id = maxId++;
    res->name = name;
    res->Next = NULL;
    return res;
}

// ---------- declarator_list ----------

Declarator_list_node* Declarator_list_node::createDeclaratorListNode(Declarator_node *declarator)
{
    Declarator_list_node *res = new Declarator_list_node;
    res->id = maxId++;
    res->First = declarator;
    res->Last = declarator;
    return res;
}

Declarator_list_node* Declarator_list_node::addToDeclaratorListNode(Declarator_list_node *list, Declarator_node *declarator)
{
    list->Last->Next = declarator;
    list->Last = declarator;
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
    res->constant = NULL;
    res->Left = NULL;
    res->Right = NULL;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromLiteral(Literal_node *value)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = LITERAL_EXPRESSION_TYPE;
    res->name = NULL;
    res->constant->literal = value;
    res->Left = NULL;
    res->Right = NULL;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromNumericConstant(Numeric_constant_node *value)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = NUMERIIC_CONSTANT_EXPRESSION_TYPE;
    res->name = NULL;
    res->constant->num = value;
    res->Left = NULL;
    res->Right = NULL;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromSimpleExpression(expression_type type, Expression_node *expression)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = type;
    res->name = NULL;
    res->constant = NULL;
    res->Left = NULL;
    res->Right = expression;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromSelf()
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = SELF_EXPRESSION_TYPE;
    res->name = NULL;
    res->constant = NULL;
    res->Left = NULL;
    res->Right = NULL;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromOperator(expression_type type, Expression_node *leftExpression, Expression_node *rightExpression)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = type;
    res->name = NULL;
    res->constant = NULL;
    res->Left = leftExpression;
    res->Right = rightExpression;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromMessageExpression(Receiver_node *receiver, Message_selector_node *arguments)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = MESSAGE_EXPRESSION_EXPRESSION_TYPE;
    res->Receiver = receiver;
    res->Arguments = arguments;
    return res;
}

Expression_node* Expression_node::createExpressionNodeFromMemberAccessOperator(expression_type type, Expression_node *expression, char *memberName)
{
    Expression_node *res = new Expression_node;
    res->id = maxId++;
    res->type = type;
    res->name = memberName;
    res->constant = NULL;
    res->Left = expression;
    res->Right = NULL;
    return res;
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

Message_selector_node* Message_selector_node::createMessageSelectorNode(char *methodName,Expression_node *expression, Keyword_argument_list_node *arguments)
{
    Message_selector_node *res = new Message_selector_node;
    res->id = maxId++;
    res->MethodName = methodName;
    res->Arguments = arguments;
    res->Expression = expression;
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
    res->type = type;
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
    res->LoopCondition = condition;
    res->LoopBody = body;
    return res;
}

// ---------- do_while_statement ----------

Do_while_statement_node* Do_while_statement_node::createDoWhileStatementNode(Expression_node *condition, Statement_node *body)
{
    Do_while_statement_node *res = new Do_while_statement_node;
    res->id = maxId++;
    res->LoopCondition = condition;
    res->LoopBody = body;
    return res;
}

// ---------- for_statement ----------

For_statement_node* For_statement_node::createForStatementNode(Expression_node *initExpression, Expression_node *condition, Expression_node *loopExpression, Statement_node *body)
{
    For_statement_node *res = new For_statement_node;
    res->id = maxId++;
    res->type = FOR_FOR_TYPE;
    res->InitExpression = initExpression;
    res->ConditionExpression = condition;
    res->LoopExpression = loopExpression;
    res->LoopBody = body;
    res->name = NULL;
    res->NameType = NULL;
    return res;
}

For_statement_node* For_statement_node::createForStatementNodeFromForeach(for_type type, Type_node *varType, char *loopVar, Expression_node *expression, Statement_node *body)
{
    For_statement_node *res = new For_statement_node;
    res->id = maxId++;
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

Statement_node* Statement_node::createStatementNodeFromSimpleStatement(statement_type type, Expression_node *expression)
{
    Statement_node *res = new Statement_node;
    res->id = maxId++;
    res->type = type;
    res->Expression = expression;
    res->Statement = NULL;
    res->Declaration = NULL;
    res->Class_declaration = NULL;
    res->Next = NULL;
    return res;
}

Statement_node* Statement_node::createStatementNodeFromComplexStatement(statement_type type, Statement_node *statement)
{
    Statement_node *res = new Statement_node;
    res->id = maxId++;
    res->type = type;
    res->Expression = NULL;
    res->Statement = statement;
    res->Declaration = NULL;
    res->Class_declaration = NULL;
    res->Next = NULL;
    return res;
}

Statement_node* Statement_node::createStatementNodeFromDeclaration(Declaration_node *declaration)
{
    Statement_node *res = new Statement_node;
    res->id = maxId++;
    res->type = DECLARATION_STATEMENT_TYPE;
    res->Expression = NULL;
    res->Statement = NULL;
    res->Declaration = declaration;
    res->Class_declaration = NULL;
    res->Next = NULL;
    return res;
}

// ---------- compound_statement ----------

Compound_statement_node* Compound_statement_node::createCompoundStatementNode(Statement_list_node *statements)
{
    Compound_statement_node *res = new Compound_statement_node;
    res->id = maxId++;
    res->Statements = statements;
    return res;
}

// ---------- statement_list ----------

Statement_list_node* Statement_list_node::createStatementListNode(Statement_node *statement)
{
    Statement_list_node *res = new Statement_list_node;
    res->id = maxId++;
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

// ----------- class_statement ----------

Class_block_node* Class_block_node::createClassBlockNodeFromInterface(Class_interface_node *interface)
{
    Class_block_node *res = new Class_block_node;
    res->id = maxId++;
    res->type = INTERFACE_CLASS_BLOCK_TYPE;
    res->statement->Interface = interface;
    res->Next = NULL;
    return res;
}

Class_block_node* Class_block_node::createClassBlockNodeFromImplementation(Class_implementation_node *implementation)
{
    Class_block_node *res = new Class_block_node;
    res->id = maxId++;
    res->type = IMPLEMENTATION_CLASS_BLOCK_TYPE;
    res->statement->Implementation = implementation;
    res->Next = NULL;
    return res;
}

// -------------------- Классы --------------------

// ---------- class_interface ----------

Class_interface_node* Class_interface_node::createClassInterfaceNode(char *className, char *superclassName, Interface_body_node *body)
{
    Class_interface_node *res = new Class_interface_node;
    res->id = maxId++;
    res->ClassName = className;
    res->SuperclassName = superclassName;
    res->Body = body;

    ClassNames.insert(className);
    ClassNames.insert(superclassName);
    return res;
}

// ---------- interface_body ----------

Interface_body_node* Interface_body_node::createInterfaceBodyNode(Instance_variables_node *variables, Interface_declaration_list_node *declarationList)
{
    Interface_body_node *res= new Interface_body_node;
    res->id = maxId++;
    res->Variables = variables;
    res->Declaration_list = declarationList;
    return res;
}

// ---------- implementation_body ----------

Implementation_body_node* Implementation_body_node::createImplementationBodyNode(Instance_variables_node *variables, Implementation_definition_list_node *definitionList)
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
    res->ClassName = className;
    res->SuperclassName = superclassName;
    res->Body = body;

    ClassNames.insert(className);
    ClassNames.insert(superclassName);
    return res;
}

// ---------- class_declaration_list, class_list ----------

Class_list_node* Class_list_node::createClassListNode(char *className)
{
    Class_list_node *res = new Class_list_node;
    res->id = maxId++;
    res->Class_names->push_back(className);
    ClassNames.insert(className);
    return res;
}

Class_list_node* Class_list_node::addToClassListNode(Class_list_node *list, char *className)
{
    list->Class_names->push_back(className);
    ClassNames.insert(className);
    return list;
}

Class_declaration_list_node* Class_declaration_list_node::createClassDeclarationListNode(Class_list_node *list)
{
    Class_declaration_list_node *res = new Class_declaration_list_node;
    res->id = maxId++;
    res->List = list;
    for(char * className : *list->Class_names)
    {
        ClassNames.insert(className);
    }
    return res;
}

// ---------- instance_variables ----------

Instance_variables_node* Instance_variables_node::createInstanceVariablesNode(Instance_variables_declaration_list_node *declarationList)
{
    Instance_variables_node *res= new Instance_variables_node;
    res->id = maxId++;
    res->DeclarationList = declarationList;
    return res;
}

// ---------- instance_variables_declaration ----------

Instance_variables_declaration_node* Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(Type_node *type, Declarator_list_node *declaratorList)
{
    Instance_variables_declaration_node *res= new Instance_variables_declaration_node;
    res->id = maxId++;
    res->Type = type;
    res->DeclaratorList = declaratorList;
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
    res->First->declaration = interfaceDeclaration;
    res->Last->declaration = interfaceDeclaration;
    return res;
}

Interface_declaration_list_node* Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(Property_node *interfaceDeclaration)
{
    Interface_declaration_list_node *res = new Interface_declaration_list_node;
    res->id = maxId++;
    res->First->property = interfaceDeclaration;
    res->Last->property = interfaceDeclaration;
    return res;
}

Interface_declaration_list_node* Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(Method_declaration_node *interfaceDeclaration)
{
    Interface_declaration_list_node *res = new Interface_declaration_list_node;
    res->id = maxId++;
    res->First->method_declaration = interfaceDeclaration;
    res->Last->method_declaration = interfaceDeclaration;
    return res;
}

Interface_declaration_list_node* Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(Interface_declaration_list_node *list, Declaration_node *interfaceDeclaration)
{
    list->Last->declaration->Next = interfaceDeclaration;
    list->Last->declaration = interfaceDeclaration;
    return list;
}

Interface_declaration_list_node* Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(Interface_declaration_list_node *list, Property_node *interfaceDeclaration)
{
    list->Last->property->Next = interfaceDeclaration;
    list->Last->property = interfaceDeclaration;
    return list;
}

Interface_declaration_list_node* Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(Interface_declaration_list_node *list, Method_declaration_node *interfaceDeclaration)
{
    list->Last->method_declaration->Next = interfaceDeclaration;
    list->Last->method_declaration = interfaceDeclaration;
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
    res->First->declaration = implementationDefinition;
    res->Last->declaration = implementationDefinition;
    return res;
}

Implementation_definition_list_node* Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(Method_definition_node *implementationDefinition)
{
    Implementation_definition_list_node *res = new Implementation_definition_list_node;
    res->id = maxId++;
    res->First->method_definition = implementationDefinition;
    res->Last->method_definition = implementationDefinition;
    return res;
}

Implementation_definition_list_node* Implementation_definition_list_node::createImplementationDefinitionListNodeFromSynthesize(Synthesize_node *implementationDefinition)
{
    Implementation_definition_list_node *res = new Implementation_definition_list_node;
    res->id = maxId++;
    res->First->synthesize = implementationDefinition;
    res->Last->synthesize = implementationDefinition;
    return res;
}

Implementation_definition_list_node* Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(Implementation_definition_list_node *list, Declaration_node *implementationDefinition)
{
    list->Last->declaration->Next = implementationDefinition;
    list->Last->declaration = implementationDefinition;
    return list;
}

Implementation_definition_list_node* Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(Implementation_definition_list_node *list, Method_definition_node *implementationDefinition)
{
    list->Last->method_definition->Next = implementationDefinition;
    list->Last->method_definition = implementationDefinition;
    return list;
}

Implementation_definition_list_node* Implementation_definition_list_node::addSynthesizeToImplementationDefinitionListNode(Implementation_definition_list_node *list, Synthesize_node *implementationDefinition)
{
    list->Last->synthesize->Next = implementationDefinition;
    list->Last->synthesize = implementationDefinition;
    return list;
}

// ---------- method_definition, class_method_definition, instance_method_definition ----------

Method_definition_node* Method_definition_node::createMethodDefinitionNode(method_definition_type type, Type_node *methodType, Method_selector_node *selector, Declaration_list_node *declarationList, Compound_statement_node *methodBody)
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

// ---------- synthesize ----------

Synthesize_node* Synthesize_node::createSynthesizeNode(char *name)
{
    Synthesize_node *res = new Synthesize_node;
    res->id = maxId++;
    res->Name = name;
    res->Next = NULL;
    return res;
}
