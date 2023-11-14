#include <vector>
#include <set>
#include <iostream>
using namespace std;

//---------- Прототипы классов ----------
class Init_declarator_list_node;
class Init_declarator_node;
class Expression_node;
class Parameter_declaration_node;
class Receiver_node;
class Message_selector_node;
class Keyword_argument_list_node;
class Keyword_argument_node;
class Class_declaration_list_node;
class Statement_list_node;
class Class_interface_node;
class Class_implementation_node;
class Interface_body_node;
class Interface_declaration_list_node;
class Implementation_definition_list_node;
class Class_list_node;
class Property_node;
class Method_declaration_node;
class Method_selector_node;
class Method_definition_node;
class Keyword_selector_node;
class Keyword_declaration_node;
class Attribute_node;
class Function_and_class_list_node;
class Function_node;
class Instance_variables_declaration_list_node;
class Expression_list_node;


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

        string toDot(string labelConection="");
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
        } number;

        static Numeric_constant_node* createNumericConstantNodeFromInteger(int number);
        static Numeric_constant_node* createNumericConstantNodeFromFloat(float number);

        string toDot();
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

        string toDot();
};

// -------------------- Объявления --------------------

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
    DECLARATION_STATEMENT_TYPE
};

class Statement_node
{
    public:
        int id;
        enum statement_type type;
        Expression_node *Expression;
        Statement_node *Next;

        static Statement_node* createStatementNodeFromSimpleStatement(statement_type type, Expression_node *expression);

        virtual string toDot(string labelConection="");
};

// ---------- declaration ----------

class Declaration_node : public Statement_node
{
    public:
        int id;
        Type_node *type;
        Init_declarator_list_node *init_declarator_list;
        Declaration_node *Next;

        static Declaration_node* createDeclarationNode(Type_node *type, Init_declarator_list_node *initDeclarators);

        string toDot(string labelConection="");
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

        string toDot(string labelConection="");
        vector<Declaration_node*>* getElements();        
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

        string toDot(string labelConection="");
        vector<Init_declarator_node*>* getElements();
};

// ---------- init_declarator ----------

enum init_declarator_type {
    SIMPLE_DECLARATOR_TYPE,
    DECLARATOR_WITH_INITIALIZING_TYPE,
    ARRAY_DECLARATOR_TYPE,
    ARRAY_WITH_INITIALIZING_DECLARATOR_TYPE
};

class Init_declarator_node
{
    public:
        int id;
        enum init_declarator_type type;
        Expression_node *expression;
        Expression_node *ArraySize;
        Init_declarator_node *Next;
        char *Declarator;
        Expression_list_node *InitializerList;

        static Init_declarator_node* createInitDeclaratorNode(init_declarator_type type, char *declarator, Expression_node *expression);
        static Init_declarator_node* createInitDeclaratorNodeFromArray(init_declarator_type type, char *declarator, Expression_node *arraySize, Expression_node *expression, Expression_list_node *initializerList);
        
        string toDot(string labelConection="");
};

// ---------- declarator ----------
class Declarator_node
{
    public:
        int id;
        char *Identifier;
        Expression_node *Expression;

        static Declarator_node* createDeclaratorNode(char *identifier, Expression_node *expression);

        string toDot(string labelConection="");
};

// ---------- declarator_list ----------

class Declarator_list_node
{
    public:
        int id;
        std::vector<Declarator_node*> *Declarators;

        static Declarator_list_node* createDeclaratorListNode(Declarator_node *declarator);
        static Declarator_list_node* addToDeclaratorListNode(Declarator_list_node *list, Declarator_node *declarator);

        string toDot(string labelConection="");
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

        vector<Parameter_declaration_node*>* getElements();
        string toDot(string labelConection="");
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

        string toDot(string labelConection="");
};

// -------------------- Выражения --------------------

// ---------- expression ----------

enum expression_type
{
    IDENTIFIER_EXPRESSION_TYPE,
    LITERAL_EXPRESSION_TYPE,
    NUMERIIC_CONSTANT_EXPRESSION_TYPE,
    SELF_EXPRESSION_TYPE,
    SUPER_EXPRESSION_TYPE,
    MESSAGE_EXPRESSION_EXPRESSION_TYPE,
    FUNCTION_CALL_EXPRESSION_TYPE,
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
    ASSIGNMENT_EXPRESSION_TYPE,
    DOT_EXPRESSION_TYPE,
    ARROW_EXPRESSION_TYPE,
    ARRAY_ELEMENT_ACCESS_EXPRESSION_TYPE
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
        } constant;
        Expression_node *Left;
        Expression_node *Right;
        Receiver_node *Receiver;
        Message_selector_node *Arguments;
        Expression_node *Next;
        Expression_list_node *ArgumentsList;
        bool isPriority = false;

        static Expression_node* createExpressionNodeFromIdentifier(char *name);
        static Expression_node* createExpressionNodeFromLiteral(Literal_node *value);
        static Expression_node* createExpressionNodeFromNumericConstant(Numeric_constant_node *value);
        static Expression_node* createExpressionNodeFromSimpleExpression(expression_type type, Expression_node *expression);
        static Expression_node* createExpressionNodeFromSelf();
        static Expression_node* createExpressionNodeFromSuper();
        static Expression_node* createExpressionNodeFromOperator(expression_type type, Expression_node *leftExpression, Expression_node *rightExpression);
        static Expression_node* createExpressionNodeFromMessageExpression(Receiver_node *receiver, Message_selector_node *arguments);
        static Expression_node* createExpressionNodeFromFunctionCall(char *name, Expression_list_node *argumentsList);
        static Expression_node* createExpressionNodeFromMemberAccessOperator(expression_type type, Expression_node *expression, char *memberName);
        static Expression_node* setPriority(Expression_node *expression, bool priority);

        string toDot(string labelConection="");
};

// ---------- expression_list ----------

class Expression_list_node
{
    public:
        int id;
        Expression_node *First;
        Expression_node *Last;

        static Expression_list_node* createExpressionListNode(Expression_node *expression);
        static Expression_list_node* addToExpressionListNode(Expression_list_node *list, Expression_node *expression);

        vector<Expression_node*>* getElements();
        string toDot(string labelConection="");
};

// ---------- receiver ----------
enum receiver_type {
    SUPER_RECEIVER_TYPE,
    SELF_RECEIVER_TYPE,
    OBJECT_NAME_RECEIVER_TYPE,
    CLASS_NAME_RECEIVER_TYPE,
    MESSAGE_EXPRESSION_RECEIVER_TYPE
};


class Receiver_node
{
    public:
        int id;
        char *name;
        receiver_type Type;
        Receiver_node *Receiver;
        Message_selector_node *Arguments;

        static Receiver_node* createReceiverNode(receiver_type type, char *name);
        static Receiver_node* createReceiverNodeFromMessageExpression(Receiver_node *receiver, Message_selector_node *arguments);

        string toDot(string labelConection="");

};

// ---------- message_selector -----------

class Message_selector_node
{
    public:
        int id;
        char *MethodName;
        Keyword_argument_list_node *Arguments;
        Expression_node *Expression;
        Expression_list_node *ExprArguments;

        static Message_selector_node* createMessageSelectorNode(char *methodName, Expression_node *expression, Keyword_argument_list_node *arguments, Expression_list_node *exprArguments);

        string toDot(string labelConection="");
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

        vector<Keyword_argument_node*>* getElements();
        string toDot(string labelConection="");
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

        string toDot(string labelConection="");
};

// -------------------- Операторы --------------------



// ---------- Управляющие структуры: развилки ----------

// ------------ if_statement ----------

enum if_type {
    WITH_ALTERNATIVE_IF_TYPE,
    WITHOUT_ALTERNATIVE_IF_TYPE
};

class If_statement_node : public Statement_node
{
    public:
        int id;
        enum if_type IfType;
        Expression_node *Condition;
        Statement_node *TrueBranch;
        Statement_node *FalseBranch;

        static If_statement_node* createIfStatementNode(if_type type, Expression_node *condition, Statement_node *trueBranch, Statement_node *falseBranch);

        string toDot(string labelConection="");
};

// ---------- Управляющие структуры: циклы ----------

// ----------- while_stasement ----------

class While_statement_node : public Statement_node
{
    public:
        int id;
        Expression_node *LoopCondition;
        Statement_node *LoopBody;

        static While_statement_node* createWhileStatementNode(Expression_node *condition, Statement_node *body);

        string toDot(string labelConection="");
};

// ---------- do_while_statement ----------

class Do_while_statement_node : public Statement_node
{
    public:
        int id;
        Expression_node *LoopCondition;
        Statement_node *LoopBody;

        static Do_while_statement_node* createDoWhileStatementNode(Expression_node *condition, Statement_node *body);

        string toDot(string labelConection="");
};

// ---------- for_statement ----------

enum for_type {
    FOR_FOR_TYPE,
    FOR_WITH_DECLARATION_FOR_TYPE,
    FOREACH_FOR_TYPE,
    FOREACH_WITH_DECLARATION_FOR_TYPE
};

class For_statement_node : public Statement_node
{
    public:
        int id;
        enum for_type ForType;
        Expression_list_node *InitExpression;
        Expression_node *ConditionExpression;
        Expression_list_node *LoopExpression;
        Statement_node *LoopBody;
        char *name;
        Type_node *NameType;
        Init_declarator_list_node *InitList;

        static For_statement_node* createForStatementNode(Expression_list_node *initExpression, Expression_node *condition, Expression_list_node *loopExpression, Statement_node *body);
        static For_statement_node* createForStatementNodeFromForWithDeclaration(Type_node *type, Init_declarator_list_node *initList, Expression_node *condition, Expression_list_node *loopExpression, Statement_node *body);
        static For_statement_node* createForStatementNodeFromForeach(for_type type, Type_node *varType, char *loopVar, Expression_node *expression, Statement_node *body);

        string toDot(string labelConection="");
};

// ---------- statement_list ----------

class Statement_list_node : public Statement_node
{
    public:
        int id;
        Statement_node *First;
        Statement_node *Last;

        static Statement_list_node* createStatementListNode(Statement_node *statement);
        static Statement_list_node* addToStatementListNode(Statement_list_node *list, Statement_node *statement);

        vector<Statement_node*>* getElements();
        string toDot(string labelConection="");
};

// ---------- class_block ----------

enum class_block_type {
    INTERFACE_CLASS_BLOCK_TYPE,
    IMPLEMENTATION_CLASS_BLOCK_TYPE
};

class Class_block_node {
    public:
        int id;
        enum class_block_type type;
        Class_block_node *Next;

        virtual string toDot(string labelConection="");
};


// -------------------- Классы --------------------

// ---------- class_interface ----------

class Class_interface_node : public Class_block_node
{
    public:
        int id;
        char *ClassName;
        char *SuperclassName;
        Interface_body_node *Body;

        static Class_interface_node* createClassInterfaceNode(char *className, char *superclassName, Interface_body_node *body);

        string toDot(string labelConection="");
};

// ---------- interface_body ----------

class Interface_body_node
{
    public:
        int id;
        Instance_variables_declaration_list_node *Variables;
        Interface_declaration_list_node *Declaration_list;

        static Interface_body_node* createInterfaceBodyNode(Instance_variables_declaration_list_node *variables, Interface_declaration_list_node *declarationList);

        string toDot(string labelConection="");
};

// ---------- implementation_body ----------

class Implementation_body_node
{
    public:
        int id;
        Instance_variables_declaration_list_node *Variables;
        Implementation_definition_list_node *Declaration_list;

        static Implementation_body_node* createImplementationBodyNode(Instance_variables_declaration_list_node *variables, Implementation_definition_list_node *definitionList);

        string toDot(string labelConection="");
};

// ---------- class_implementation ----------

class Class_implementation_node : public Class_block_node
{
    public:
        int id;
        char *ClassName;
        char *SuperclassName;
        Implementation_body_node *Body;

        static Class_implementation_node* createClassImplementationNode(char *className, char *superclassName, Implementation_body_node *body);

        string toDot(string labelConection="");
};

// ---------- class_declaration_list и class_list ----------

class Class_declaration_list_node
{
    public:
        int id;
        Class_list_node *List;
        Class_declaration_list_node *Next;

        static Class_declaration_list_node* createClassDeclarationListNode(Class_list_node *list);

        string toDot(string labelConection="");
};

class Class_list_node
{
    public:
        int id;
        std::vector<char*> *Class_names;

    static Class_list_node* createClassListNode(char *className);
    static Class_list_node* addToClassListNode(Class_list_node *list, char *className);

    string toDot(string labelConection="");
};

// ---------- instance_variables_declaration --------

class Instance_variables_declaration_node
{
    public:
        int id;
        Type_node *Type;
        Declarator_list_node *DeclaratorList;
        Instance_variables_declaration_node *Next;

        static Instance_variables_declaration_node* createInstanceVariablesDeclarationNode(Type_node *type, Declarator_list_node *declaratorList);

        string toDot(string labelConection="");
};

// ---------- instance_variables_declaration_list ----------

class Instance_variables_declaration_list_node
{
    public:
        int id;
        Instance_variables_declaration_node *First;
        Instance_variables_declaration_node *Last;

        static Instance_variables_declaration_list_node* createInstanceVariablesDeclarationListNode(Instance_variables_declaration_node *declaration);
        static Instance_variables_declaration_list_node* addToInstanceVariablesDeclarationListNode(Instance_variables_declaration_list_node *list, Instance_variables_declaration_node *declaration);

        vector<Instance_variables_declaration_node*>* getElements();
        string toDot(string labelConection="");
};

// ---------- interface_declaration_list ----------

class Interface_declaration_list_node
{
    public:
        int id;
        struct interface_declaration {
            Declaration_node *declaration;
            Property_node *property;
            Method_declaration_node *method_declaration;
        };
        vector<interface_declaration> *Declarations;

        static Interface_declaration_list_node* createInterfaceDeclarationListNodeFromDeclaration(Declaration_node *interfaceDeclaration);
        static Interface_declaration_list_node* createInterfaceDeclarationListNodeFromProperty(Property_node *interfaceDeclaration);
        static Interface_declaration_list_node* createInterfaceDeclarationListNodeFromMethodDeclaration(Method_declaration_node *interfaceDeclaration);
        static Interface_declaration_list_node* addDeclarationToInterfaceDeclarationListNode(Interface_declaration_list_node *list, Declaration_node *interfaceDeclaration);
        static Interface_declaration_list_node* addPropertyToInterfaceDeclarationListNode(Interface_declaration_list_node *list, Property_node *interfaceDeclaration);
        static Interface_declaration_list_node* addMethodDeclarationToInterfaceDeclarationListNode(Interface_declaration_list_node *list, Method_declaration_node *interfaceDeclaration);

        string toDot(string labelConection="");
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

        string toDot(string labelConection="");
};


// ---------- implementation_definition_list ----------

class Implementation_definition_list_node
{
    public:
        int id;
        struct implementation_definition {
            Declaration_node *declaration;
            Method_definition_node *method_definition;
            char *synthesize;
        };
        vector<implementation_definition> *Definitions;

        static Implementation_definition_list_node* createImplementationDefinitionListNodeFromDeclaration(Declaration_node *implementationDefinition);
        static Implementation_definition_list_node* createImplementationDefinitionListNodeFromMethodDeclaration(Method_definition_node *implementationDefinition);
        static Implementation_definition_list_node* createImplementationDefinitionListNodeFromSynthesize(char *implementationDefinition);
        static Implementation_definition_list_node* addDeclarationToImplementationDefinitionListNode(Implementation_definition_list_node *list, Declaration_node *implementationDefinition);
        static Implementation_definition_list_node* addMethodDeclarationToImplementationDefinitionListNode(Implementation_definition_list_node *list, Method_definition_node *implementationDefinition);
        static Implementation_definition_list_node* addSynthesizeToImplementationDefinitionListNode(Implementation_definition_list_node *list, char *implementationDefinition);

        string toDot(string labelConection="");
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
        Statement_list_node *MethodBody;
        Method_definition_node *Next;

        static Method_definition_node* createMethodDefinitionNode(method_definition_type type, Type_node *methodType, Method_selector_node *selector, Declaration_list_node *declarationList, Statement_list_node *methodBody);

        string toDot(string labelConection="");
};

// ---------- method_selector ----------

class Method_selector_node
{
    public:
        int id;
        char *MethodName;
        Keyword_selector_node *KeywordSelector;
        Parameter_list_node *ParameterListNode;
        Keyword_declaration_node *KeywordDeclaration;

        static Method_selector_node* createMethodSelectorNode(char *methodName, Keyword_declaration_node *keywordDeclaration, Keyword_selector_node *selector, Parameter_list_node *parameters);

        string toDot(string labelConection="");
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

        vector<Keyword_declaration_node*>* getElements();
        string toDot(string labelConection="");
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

        string toDot(string labelConection="");
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

        string toDot(string labelConection="");
};

// ----------- attribute ----------

enum attrribute_type {
    READONLY_ATTRIBUTE_TYPE,
    READWRITE_ATTRIBUTE_TYPE,
    EMPTY_ATTRIBUTE_TYPE
};

class Attribute_node
{
    public:
        int id;
        enum attrribute_type type;

        static Attribute_node* createAttributeNode(attrribute_type type);

        string toDot(string labelConection="");
};


// ---------- program ----------

class Program_node
{
    public:
        int id;
        Function_and_class_list_node *list;

        static Program_node* createProgramNode(Function_and_class_list_node *list);
        
        string toDot();
};

// ---------- function_and_class_list ----------

class Function_and_class_list_node
{
    public:
        int id;
        struct function_and_class {
            Function_node *function;
            Class_block_node *class_block;
            Class_declaration_list_node *class_declaration_list;
        };

        vector<function_and_class> *FunctionsAndClasses;

        static Function_and_class_list_node* createFunctionAndClassListNodeFromClassBlock(Class_block_node *classBlock);
        static Function_and_class_list_node* createFunctionAndClassListNodeFromFunction(Function_node *function);
        static Function_and_class_list_node* createFunctionAndClassListNodeFromClassDeclarationList(Class_declaration_list_node *classDeclarationList);
        static Function_and_class_list_node* addToFunctionAndClassListNodeFromClassBlock(Function_and_class_list_node *list, Class_block_node *classBlock);
        static Function_and_class_list_node* addToFunctionAndClassListNodeFromFunction(Function_and_class_list_node *list, Function_node *functionList);
        static Function_and_class_list_node* addToFunctionAndClassListNodeFromClassDeclarationList(Function_and_class_list_node *list, Class_declaration_list_node *classDeclarationList);

        string toDot();
};

// ---------- function ----------

class Function_node
{ //ЗАГЛУШКА
    public:
        int id;
        Type_node *Type;
        char *Name;
        Statement_list_node *statement;
        Function_node *Next;

        static Function_node* createFunctionNode(Type_node *type, char *name, Statement_list_node *statement);
        
        string toDot(string labelConection="");
};