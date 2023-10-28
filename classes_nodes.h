#include <vector>
#include <set>
#include <iostream>
using namespace std;
int maxId = 0; // Глобальный id узла
set<string> ClassNames; //Множество имен объявленных классов


// -------------------- Типы --------------------

// ---------- type ----------

enum type_type {
    INT_TYPE,
    CHAR_TYPE,
    FLOAT_TYPE,
    ID_TYPE,
    CLASS_NAME_TYPE,
    VOID_TYPE
};

class Type_node
{
    public:
        int id;
        enum type_type type;
        char *ClassName;

        static Type_node* createTypeNode(type_type type);
        static Type_node* createTypeNodeFromClassName(type_type type, char *name);
};

// -------------------- Константы --------------------

// ---------- numeric_constant ----------

enum numeric_constant_type {
    FLOAT_CONSTANT_TYPE,
    INTEGER_CONSTANT_TYPE
};

class Numeric_constant_node
{
    public:
        int id;
        enum numeric_constant_type type;
        union number
        {
            int Int;
            float Float;
        } *number;

        static Numeric_constant_node* createNumericConstantNodeFromInteger(int number);
        static Numeric_constant_node* createNumericConstantNodeFromFloat(float number);
};

// ---------- literal ----------

enum literal_type {
    STRING_CONSTANT_TYPE,
    CHAR_CONSTANT_TYPE,
    NSSTRING_CONSTANT_TYPE
};

class Literal_node
{
    public:
        int id;
        enum literal_type type;
        char *value;

        static Literal_node* createLiteralNode(literal_type type, char *value);
};

// -------------------- Объявления --------------------

// ---------- declaration ----------

class Declaration_node 
{
    public:
        int id;
        Type_node *type;
        Init_declarator_list_node *init_declarator_list;
        Declaration_node *Next;

        static Declaration_node* createDeclarationNode(Type_node *type, Init_declarator_list_node *initDeclarators);
};


// ---------- declaration_list ----------

class Declaration_list_node
{
    public:
        int id;
        Declaration_node *First;
        Declaration_node *Last;

        static Declaration_list_node* createDeclarationListNode(Declaration_node *declaration);
        static Declaration_list_node* addToDeclarationListNode(Declaration_list_node *list, Declaration_node *declaration);        
};

// ---------- init_declarator_list ----------

class Init_declarator_list_node
{
    public:
        int id;
        Init_declarator_node *First;
        Init_declarator_node *Last;

        static Init_declarator_list_node* createInitDeclaratorListNode(Init_declarator_node *initDeclarator);
        static Init_declarator_list_node* addToInitDeclaratorListNode(Init_declarator_list_node *list, Init_declarator_node *initDeclarator);
};

// ---------- init_declarator ----------

enum init_declarator_type {
    SIMPLE_DECLARATOR_TYPE,
    DECLARATOR_WITH_INITIALIZING_TYPE
};

class Init_declarator_node
{
    public:
        int id;
        enum init_declarator_type type;
        char *name;
        Expression_node *expression;
        Init_declarator_node *Next;

        static Init_declarator_node* createInitDeclaratorNode(init_declarator_type type, char *name, Expression_node *expression);
};

// ---------- parameter_list ----------

class Parameter_list_node
{
    public:
        int id;
        Parameter_declaration_node *First;
        Parameter_declaration_node *Last;

        static Parameter_list_node* createParameterListNode(Parameter_declaration_node *parameter);
        static Parameter_list_node* addToParameterListNode(Parameter_list_node *list, Parameter_declaration_node *parameter);
};

// ---------- parameter_declaration ----------

class Parameter_declaration_node
{
    public:
        int id;
        Type_node *type;
        char *name;
        Parameter_declaration_node *Next;

        static Parameter_declaration_node* createParameterDeclarationNode(Type_node *type, char *name);
};

// -------------------- Выражения --------------------

// ---------- expression ----------

enum expression_type
{
    IDENTIFIER_EXPRESSION_TYPE,
    LITERAL_EXPRESSION_TYPE,
    NUMERIIC_CONSTANT_EXPRESSION_TYPE,
    PRIORITY_EXPRESSION_TYPE,
    SELF_EXPRESSION_TYPE,
    MESSAGE_EXPRESSION_EXPRESSION_TYPE,
    UMINUS_EXPRESSION_TYPE,
    UPLUS_EXPRESSION_TYPE,
    UAMPERSAND_EXPRESSION_TYPE,
    PLUS_EXPRESSION_TYPE,
    MINUS_EXPRESSION_TYPE,
    MUL_EXPRESSION_TYPE,
    DIV_EXPRESSION_TYPE,
    EQUAL_EXPRESSION_TYPE,
    NOT_EQUAL_EXPRESSION_TYPE,
    GREATER_EXPRESSION_TYPE,
    LESS_EXPRESSION_TYPE,
    LESS_EQUAL_EXPRESSION_TYPE,
    GREATER_EQUAL_EXPRESSION_TYPE,
    ASSIGNMENT_EXPRESSION_TYPE
};

class Expression_node
{
    public:
        int id;
        enum expression_type type;
        char *name;
        union constant
        {
            Numeric_constant_node *num;
            Literal_node *literal;
        } *constant;
        Expression_node *Left;
        Expression_node *Right;

        static Expression_node* createExpressionNodeFromIdentifier(char *name);
        static Expression_node* createExpressionNodeFromLiteral(Literal_node *value);
        static Expression_node* createExpressionNodeFromNumericConstant(Numeric_constant_node *value);
        static Expression_node* createExpressionNodeFromSimpleExpression(expression_type type, Expression_node *expression);
        static Expression_node* createExpressionNodeFromSelf();
        static Expression_node* createExpressionNodeFromOperator(expression_type type, Expression_node *leftExpression, Expression_node *rightExpression);
};

// ---------- message_expression ----------

class Message_expression_node : public Expression_node
{
    public:
        int id;
        Receiver_node *Receiver;
        Message_selector_node *Arguments;

        static Message_expression_node* createMessageExpressionNode(Receiver_node *receiver, Message_selector_node *arguments);
};

// ---------- receiver ----------
enum receiver_type {
    SUPER_RECEIVER_TYPE,
    SELF_RECEIVER_TYPE,
    CLASS_NAME_RECEIVER_TYPE
};


class Receiver_node
{
    public:
        int id;
        char *name;

        static Receiver_node* createReceiverNode(receiver_type type, char *name);
};

// ---------- message_selector -----------

class Message_selector_node
{
    public:
        int id;
        char *MethodName;
        Keyword_argument_list_node *Arguments;

        static Message_selector_node* createMessageSelectorNode(char *methodName, Keyword_argument_list_node *arguments);
};

// ---------- keyword_argument_list ----------

class Keyword_argument_list_node
{
    public:
        int id;
        Keyword_argument_node *First;
        Keyword_argument_node *Last;

        static Keyword_argument_list_node* createKeywordArgumentListNode(Keyword_argument_node *argument);
        static Keyword_argument_list_node* addToKeywordArgumentListNode(Keyword_argument_list_node *list, Keyword_argument_node *argument);
};

// ---------- keyword_argument ----------

enum keyword_argument_type {
    WITH_IDENTIFIER_KW_ARGUMENT_TYPE,
    WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE
};

class Keyword_argument_node
{
    public:
        int id;
        enum keyword_argument_type type;
        char *name;
        Expression_node *expression;
        Keyword_argument_node *Next;

        static Keyword_argument_node* createKeywordArgumentNode(keyword_argument_type type, char *identifier, Expression_node *expression);
};

// -------------------- Управляющие структуры: развилки --------------------

// ------------ if_statement ----------

enum if_type {
    WITH_ALTERNATIVE_IF_TYPE,
    WITHOUT_ALTERNATIVE_IF_TYPE
};

class If_statement_node : public Statement_node
{
    public:
        int id;
        enum if_type type;
        Expression_node *Condition;
        Statement_node *TrueBranch;
        Statement_node *FalseBranch;

        static If_statement_node* createIfStatementNode(if_type type, Expression_node *condition, Statement_node *trueBranch, Statement_node *falseBranch);
};

// -------------------- Управляющие структуры: циклы --------------------

// ----------- while_stasement ----------

class While_statement_node : public Statement_node
{
    public:
        int id;
        Expression_node *LoopCondition;
        Statement_node *LoopBody;

        static While_statement_node* createWhileStatementNode(Expression_node *condition, Statement_node *body);
};

// ---------- do_while_statement ----------

class Do_while_statement_node : public Statement_node
{
    public:
        int id;
        Expression_node *LoopCondition;
        Statement_node *LoopBody;

        static Do_while_statement_node* createDoWhileStatementNode(Expression_node *condition, Statement_node *body);
};

// ---------- for_statement ----------

enum for_type {
    FOR_FOR_TYPE,
    FOREACH_FOR_TYPE,
    FOREACH_WITH_DECLARATION_FOR_TYPE
};

class For_statement_node : public Statement_node
{
    public:
        int id;
        enum for_type type;
        Expression_node *InitExpression;
        Expression_node *ConditionExpression;
        Expression_node *LoopExpression;
        Statement_node *LoopBody;
        char *name;
        Type_node *NameType;

        static For_statement_node* createForStatementNode(Expression_node *initExpression, Expression_node *condition, Expression_node *loopExpression, Statement_node *body);
        static For_statement_node* createForStatementNodeFromForeach(for_type type, Type_node *varType, char *loopVar, Expression_node *expression, Statement_node *body);
};

// -------------------- Операторы --------------------

// ---------- statement ----------

enum statement_type {
    EMPTY_STATEMENT_TYPE,
    SIMPLE_STATEMENT_TYPE,
    RETURN_STATEMENT_TYPE,
    IF_STATEMENT_TYPE,
    WHILE_STATEMENT_TYPE,
    DO_WHILE_STATEMENT_TYPE,
    FOR_STATEMENT_TYPE,
    COMPOUND_STATEMENT_TYPE,
    DECLARATION_STATEMENT_TYPE,
    CLASS_DECLARATION_LIST_STATEMENT_TYPE
};

class Statement_node
{
    public:
        int id;
        enum statement_type type;
        Expression_node *Expression;
        Statement_node *Statement;
        Declaration_node *Declaration;
        Class_declaration_list_node *Class_declaration;
        Statement_node *Next;

        static Statement_node* createStatementNodeFromSimpleStatement(statement_type type, Expression_node *expression);
        static Statement_node* createStatementNodeFromComplexStatement(statement_type type, Statement_node *statement);
        static Statement_node* createStatementNodeFromDeclaration(Declaration_node *declaration);
        static Statement_node* createStatementNodeFromClassDeclaration(Class_declaration_list_node *classDeclarationList);
};

// ---------- compound_statement ----------

class Compound_statement_node : public Statement_node
{
    public:
        int id;
        Statement_list_node *Statements;

        static Compound_statement_node* createCompoundStatementNode(Statement_list_node *statements);
};

// ---------- statement_list ----------

class Statement_list_node
{
    public:
        int id;
        Statement_node *First;
        Statement_node *Last;

        static Statement_list_node* createStatementListNode(Statement_node *statement);
        static Statement_list_node* addToStatementListNode(Statement_list_node *list, Statement_node *statement);
};

// ---------- class_statement ----------

enum class_statement_type {
    INTERFACE_CLASS_STATEMENT_TYPE,
    IMPLEMENTATION_CLASS_STATEMENT_TYPE
};

class Class_statement_node {
    public:
        int id;
        enum class_statement_type type;
        union statement
        {
            Class_interface_node *Interface;
            Class_implementation_node *Implementation;
        } *statement; 
        Class_statement_node *Next;

        static Class_statement_node* createClassStatementNodeFromInterface(Class_interface_node *interface);
        static Class_statement_node* createClassStatementNodeFromImplementation(Class_implementation_node *implementation);     
};

// ---------- class_statement_list ----------

class Class_statement_list_node
{
    public:
        int id;
        Class_statement_node *First;
        Class_statement_node *Last;

        static Class_statement_list_node* createClassStatementListNode(Class_statement_node *ClassStatement);
        static Class_statement_list_node* addToClassStatementListNode(Class_statement_list_node *list, Class_statement_node *ClassStatement);
};


// -------------------- Классы --------------------

// ---------- class_interface ----------

class Class_interface_node : public Class_statement_node
{
    public:
        int id;
        char *ClassName;
        char *SuperclassName;
        Interface_statement_node *Statement;

        static Class_interface_node* createClassInterfaceNode(char *className, char *superclassName, Interface_statement_node *statement);
};

// ---------- interface_statement ----------

class Interface_statement_node
{
    public:
        int id;
        Instance_variables_node *Variables;
        Interface_declaration_list_node *Declaration_list;

        static Interface_statement_node* createInterfaceStatementNode(Instance_variables_node *variables, Interface_declaration_list_node *declarationList);
};

// ---------- implementation_statement ----------

class Implementation_statement_node
{
    public:
        int id;
        Instance_variables_node *Variables;
        Implementation_definition_list_node *Declaration_list;

        static Implementation_statement_node* createImplementationStatementNode(Instance_variables_node *variables, Implementation_definition_list_node *definitionList);
};

// ---------- class_implementation ----------

class Class_implementation_node : public Class_statement_node
{
    public:
        int id;
        char *ClassName;
        char *SuperclassName;
        Implementation_statement_node *Staetment;

        static Class_implementation_node* createClassImplementationNode(char *className, char *superclassName, Implementation_statement_node *statement);
};

// ---------- class_declaration_list и class_list ----------

class Class_declaration_list_node
{
    public:
        int id;
        Class_list_node *List;

        static Class_declaration_list_node* createClassDeclarationListNode(Class_list_node *list);
};

class Class_list_node
{
    public:
        int id;
    std::vector<char*> *Class_names;

    static Class_list_node* createClassListNode(char *className);
    static Class_list_node* addToClassListNode(Class_list_node *list, char *className);
};

// ---------- instance_variables ----------

class Instance_variables_node
{
    public:
        int id;
        Declaration_list_node *DeclarationList;

        static Instance_variables_node* createInstanceVariablesNode(Declaration_list_node *declarationList);
};

// ---------- interface_declaration_list ----------

class Interface_declaration_list_node
{
    public:
        int id;
        union interface_declaration {
            Declaration_node *declaration;
            Property_node *property;
            Method_declaration_node *method_declaration;
        } *First, *Last;

        static Interface_declaration_list_node* createInterfaceDeclarationListNodeFromDeclaration(Declaration_node *interfaceDeclaration);
        static Interface_declaration_list_node* createInterfaceDeclarationListNodeFromProperty(Property_node *interfaceDeclaration);
        static Interface_declaration_list_node* createInterfaceDeclarationListNodeFromMethodDeclaration(Method_declaration_node *interfaceDeclaration);
        static Interface_declaration_list_node* addDeclarationToInterfaceDeclarationListNode(Interface_declaration_list_node *list, Declaration_node *interfaceDeclaration);
        static Interface_declaration_list_node* addPropertyToInterfaceDeclarationListNode(Interface_declaration_list_node *list, Property_node *interfaceDeclaration);
        static Interface_declaration_list_node* addMethodDeclarationToInterfaceDeclarationListNode(Interface_declaration_list_node *list, Method_declaration_node *interfaceDeclaration);
};

// ---------- method_declaration, class_method_declaration, instance_method_declaration ----------

enum method_declaration_type {
    CLASS_METHOD_DECLARATION_TYPE,
    INSTANCE_METHOD_DECLARATION_TYPE
};

class Method_declaration_node
{
    public:
        int id;
        enum method_declaration_type type;
        Type_node *MethodType;
        Method_selector_node *MethodSelector;
        Method_declaration_node *Next;

        static Method_declaration_node* createMethodDeclarationNode(method_declaration_type type, Type_node *methodType, Method_selector_node *selector);
};


// ---------- implementation_definition_list ----------

class Implementation_definition_list_node
{
    public:
        int id;
        union interface_declaration {
            Declaration_node *declaration;
            Property_node *property;
            Method_definition_node *method_definition;
        } *First, *Last;

        static Implementation_definition_list_node* createImplementationDefinitionListNodeFromDeclaration(Declaration_node *interfaceDeclaration);
        static Implementation_definition_list_node* createImplementationDefinitionListNodeFromProperty(Property_node *interfaceDeclaration);
        static Implementation_definition_list_node* createImplementationDefinitionListNodeFromMethodDeclaration(Method_definition_node *interfaceDeclaration);
        static Implementation_definition_list_node* addDeclarationToImplementationDefinitionListNode(Implementation_definition_list_node *list, Declaration_node *interfaceDeclaration);
        static Implementation_definition_list_node* addPropertyToImplementationDefinitionListNode(Implementation_definition_list_node *list, Property_node *interfaceDeclaration);
        static Implementation_definition_list_node* addMethodDeclarationToImplementationDefinitionListNode(Implementation_definition_list_node *list, Method_definition_node *interfaceDeclaration);
};

// ---------- method_definition, class_method_definition, instance_method_definition ----------

enum method_definition_type {
    CLASS_METHOD_DEFINITION_TYPE,
    INSTANCE_METHOD_DEFINITION_TYPE
};

class Method_definition_node
{
    public:
        int id;
        enum method_definition_type type;
        Type_node *MethodType;
        Method_selector_node *MethodSelector;
        Declaration_list_node *DeclarationList;
        Compound_statement_node *MethodBody;
        Method_definition_node *Next;

        static Method_definition_node* createMethodDefinitionNode(method_definition_type type, Type_node *methodType, Method_selector_node *selector, Declaration_list_node *declarationList, Compound_statement_node *methodBody);
};

// ---------- method_selector ----------

class Method_selector_node
{
    public:
        int id;
        char *MethodName;
        Keyword_selector_node *KeywordSelector;
        Parameter_list_node *ParameterListNode;

        static Method_selector_node* createMethodSelectorNode(char *methodName, Keyword_selector_node *selector, Parameter_list_node *parameters);
};

// ---------- keyword_selector ----------

class Keyword_selector_node
{
    public:
        int id;
        Keyword_declaration_node *First;
        Keyword_declaration_node *Last;

        static Keyword_selector_node* createKeywordSelectorNode(Keyword_declaration_node *declaration);
        static Keyword_selector_node* addToKeywordSelectorNode(Keyword_selector_node *list, Keyword_declaration_node *declaration);
};

// ---------- keyword_declaration ----------

class Keyword_declaration_node
{
    public:
        int id;
        Type_node *KeywordType;
        char *Identifier;
        char *KeywordName;
        Keyword_declaration_node *Next;

        static Keyword_declaration_node* createKeywordDeclarationNode(Type_node *type, char *identifier, char *keywordName);
};

// ---------- property ----------

class Property_node
{
    public:
        int id;
        Attribute_node *Attribute;
        Type_node *type;
        char *Name;
        Property_node *Next;

        static Property_node* createPropertyNode(Attribute_node *attribute, Type_node *type, char *name);
};

// ----------- attribute ----------

enum attrribute_type {
    READONLY_ATTRIBUTE_TYPE,
    READWRITE_ATTRIBUTE_TYPE
};

class Attribute_node
{
    public:
        int id;
        enum attrribute_type type;

        static Attribute_node* createAttributeNode(attrribute_type type);
};


// ---------- program ----------

class Program_node
{
    public:
        int id;
        Statement_list_node *Statements;
        Class_statement_list_node *ClassStatements;

        static Program_node* createProgramNode(Statement_list_node *Statements, Class_statement_list_node *ClassStatements);
};
