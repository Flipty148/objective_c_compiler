%{
	#include "classes_nodes.h"
	Program_node *root;
%}

// ---------- Объединение ----------
%union {
	int Integer_constant;
	char *String_constant;
	char Char_constant;
	float Float_constant;
	char *NSString_constant;
	char *Identifier;
	Type_node *Type;
	Numeric_constant_node *Numeric_constant;
	Literal_node *Literal;
	Declaration_node *Declaration;
	Declaration_list_node *Declaration_list;
	Init_declarator_list_node *Init_declarator_list;
	Init_declarator_node *Init_declarator;
	Parameter_list_node *Parameter_list;
	Parameter_declaration_node *Parameter_declaration;
	Expression_node *Expression;
	Message_expression_node *Message_expression;
	Receiver_node *Receiver;
	Message_selector_node *Message_selector;
	Keyword_argument_list_node *Keyword_argument_list;
	Keyword_argument_node *Keyword_argument;
	If_statement_node *If;
	While_statement_node *While;
	Do_while_statement_node *Do_while;
	For_statement_node *For;
	Statement_node *Statement;
	Compound_statement_node *Compound_statement;
	Statement_list_node *Statement_list;
	Class_statement_node *Class_statement;
	Class_statement_list_node *Class_statement_list;
	Class_interface_node *Class_interface;
	Interface_statement_node *Interface_statement;
	Implementation_statement_node *Implementation_statement;
	Class_implementation_node *Class_implementation;
	Class_declaration_list_node *Class_declaration_list;
	Instance_variables_node *Instance_variables;
	Interface_declaration_list_node *Interface_declaration_list;
	Method_declaration_node *Method_declaration;
	Implementation_definition_list_node *Implementation_definition_list;
	Method_definition_node *Method_definition;
	Method_selector_node *Method_selector;
	Keyword_selector_node *Keyword_selector;
	Keyword_declaration_node *Keyword_declaration;
	Property_node *Property;
	Attribute_node *Attribute;
	Program_node *Program;
	Class_list *Class_list;
}

// ---------- Операции с их приоритетом ----------
%right '='
%left EQUAL NOT_EQUAL
%left '<' '>' LESS_EQUAL GREATER_EQUAL
%left '+' '-'
%left '*' '/'
%right UMINUS UPLUS UAMPERSAND
%nonassoc '(' ')' '[' ']'

//---------- Терминальные символы ----------
%token <Type> INT 
%token <Type> CHAR 
%token <Type> FLOAT
%token <Type> VOID
%token ENUM
%token IF ELSE WHILE DO FOR
%token IN
%token INTERFACE IMPLEMENTATION 
%token END
%token PROPERTY
%token READONLY READWRITE
%token SELF SUPER ID /* НУЖНО ЛИ SUPER добавлять в expression */
%token CLASS
%token RETURN
%token <Integer_constant> INTEGER_CONSTANT
%token <String_constant> STRING_CONSTANT
%token <Char_constant> CHAR_CONSTANT
%token <Float_constant> FLOAT_CONSTANT
%token <NSString_constant> NSSTRING_CONSTANT
%token <Identifier> IDENTIFIER
%token <Identifier> CLASS_NAME

%type <Type> type method_type
%type <Numeric_constant> numeric_constant
%type <Literal> literal
%type <Declaration> declaration
%type <Declaration_list> declaration_list_e declaration_list
%type <Init_declarator_list> init_declarator_list_e init_declarator_list
%type <Init_declarator> init_declarator
%type <Parameter_list> parameter_list
%type <Parameter_declaration> parameter_declaration
%type <Expression> expression expression_e
%type <Message_expression> message_expression
%type <Receiver> receiver
%type <Message_selector> message_selector
%type <Keyword_argument_list> keyword_argument_list
%type <Keyword_argument> keyword_argument
%type <If> if_statement
%type <While> while_statement
%type <Do_while> do_while_statement
%type <For> for_statement
%type <Statement> statement
%type <Compound_statement> compound_statement
%type <Statement_list> statement_list_e statement_list
%type <Class_statement> class_statement
%type <Class_statement_list> class_statement_list
%type <Class_interface> class_interface
%type <Interface_statement> interface_statement
%type <Implementation_statement> implementation_statement
%type <Class_implementation> class_implementation
%type <Class_declaration_list> class_declaration_list 
%type <Class_list> class_list
%type <Instance_variables> instance_variables
%type <Interface_declaration_list> interface_declaration_list
%type <Method_declaration> method_declaration class_method_declaration instance_method_declaration
%type <Implementation_definition_list> implementation_definition_list
%type <Method_definition> method_definition class_method_definition instance_method_definition
%type <Method_selector> method_selector
%type <Keyword_selector> keyword_selector
%type <Keyword_declaration> keyword_declaration
%type <Property> property
%type <Attribute> attribute
%type <Program> program


%start program

%%

program: statement_list							{$$ = root = Program_node::createProgramNode($1, NULL);}
	   | class_statement_list					{$$ = root = Program_node::createProgramNode(NULL, $1);}
	   | statement_list class_statement_list	{$$ = root = Program_node::createProgramNode($1, $2);}
	   | class_statement_list statement_list	{$$ = root = Program_node::createProgramNode($2, $1);}
	   ;

// ---------- Типы ----------
type: INT				{$$ = Type_node::createTypeNode(INT_TYPE);}
    | CHAR				{$$ = Type_node::createTypeNode(CHAR_TYPE);}
    | FLOAT				{$$ = Type_node::createTypeNode(FLOAT_TYPE);}
    | ID				{$$ = Type_node::createTypeNode(ID_TYPE);}
	| CLASS_NAME '*'	{$$ = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, $1);}
    ;

// ---------- Константы ----------
numeric_constant: FLOAT_CONSTANT	{$$ = Numeric_constant_node::createNumericConstantNodeFromFloat($1);}
                | INTEGER_CONSTANT	{$$ = Numeric_constant_node::createNumericConstantNodeFromInteger($1);}
                ;

literal: STRING_CONSTANT	{$$ = Literal_node::createLiteralNode(STRING_CONSTANT_TYPE, $1);}
       | CHAR_CONSTANT		{$$ = Literal_node::createLiteralNode(CHAR_CONSTANT_TYPE, $1);}
	   | NSSTRING_CONSTANT	{$$ = Literal_node::createLiteralNode(NSSTRING_CONSTANT_TYPE, $1);}
       ;

// ---------- Объявления ----------
declaration: type init_declarator_list_e ';'	{$$ = Declaration_node::createDeclarationNode($1, $2);}
           ;

declaration_list: declaration 					{$$ = Declaration_list_node::createDeclarationListNode($1);}
				| declaration_list declaration	{$$ = Declaration_list_node::addToDeclarationListNode($1, $2);}
				;

declaration_list_e: /*empty*/			{$$ = NULL;}
				  | declaration_list	{$$ = $1;}
				  ;

init_declarator_list_e: /* empty */			{$$ = NULL;}
					| init_declarator_list	{$$ = $1;}
					;

init_declarator_list: init_declarator							{$$ = Init_declarator_list_node::createInitDeclaratorListNode($1);}
					| init_declarator_list ',' init_declarator	{$$ = Init_declarator_list_node::addToInitDeclaratorListNode($1, $3);}
					;

init_declarator: IDENTIFIER					{$$ = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, $1, NULL);}
			   | IDENTIFIER '=' expression	{$$ = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, $1, $3);}
			   ;

parameter_list: parameter_declaration						{$$ = Parameter_list_node::createParameterListNode($1);}
			  | parameter_list ',' parameter_declaration	{$$ = Parameter_list_node::addToParameterListNode($1, $3);}
			  ;

parameter_declaration: type IDENTIFIER			{$$ = Parameter_declaration_node::createParameterDeclarationNode($1, $2);}
					 ;

// ---------- Выражения ----------

expression: IDENTIFIER							{$$ = Expression_node::createExpressionNodeFromIdentifier($1);}
		  | literal								{$$ = Expression_node::createExpressionNodeFromLiteral($1);}
		  | numeric_constant					{$$ = Expression_node::createExpressionNodeFromNumericConstant($1);}
		  | '(' expression ')'					{$$ = Expression_node::createSimpleExpressionNode(PRIORITY_EXPRESSION_TYPE, $2);}
		  | SELF								{$$ = Expression_node::createExpressionNodeFromSelf();}
		  | message_expression					{$$ = Expression_node::createExpressionNodeFromSimpleExpression(MESSAGE_EXPRESSION_EXPRESSION_TYPE, $1);}
		  | '-' expression %prec UMINUS			{$$ = Expression_node::createExpressionNodeFromOperator(UMINUS_EXPRESSION_TYPE, NULL, $2);}
		  | '+' expression %prec UPLUS			{$$ = Expression_node::createExpressionNodeFromOperator(UPLUS_EXPRESSION_TYPE, NULL, $2);}
		  | '&' expression %prec UAMPERSAND		{$$ = Expression_node::createExpressionNodeFromOperator(UAMPERSAND_EXPRESSION_TYPE, NULL, $2);}
		  | expression '+' expression			{$$ = Expression_node::createExpressionNodeFromOperator(PLUS_EXPRESSION_TYPE, $1, $3);}
		  | expression '-' expression			{$$ = Expression_node::createExpressionNodeFromOperator(MINUS_EXPRESSION_TYPE, $1, $3);}
		  | expression '*' expression			{$$ = Expression_node::createExpressionNodeFromOperator(MUL_EXPRESSION_TYPE, $1, $3);}
		  | expression '/' expression			{$$ = Expression_node::createExpressionNodeFromOperator(DIV_EXPRESSION_TYPE, $1, $3);}
		  | expression EQUAL expression			{$$ = Expression_node::createExpressionNodeFromOperator(EQUAL_EXPRESSION_TYPE, $1, $3);}
		  | expression NOT_EQUAL expression		{$$ = Expression_node::createExpressionNodeFromOperator(NOT_EQUAL_EXPRESSION_TYPE, $1, $3);}
		  | expression '>' expression			{$$ = Expression_node::createExpressionNodeFromOperator(GREATER_EXPRESSION_TYPE, $1, $3);}
		  | expression '<' expression			{$$ = Expression_node::createExpressionNodeFromOperator(LESS_EXPRESSION_TYPE, $1, $3);}
		  | expression LESS_EQUAL expression	{$$ = Expression_node::createExpressionNodeFromOperator(LESS_EQUAL_EXPRESSION_TYPE, $1, $3);}
		  | expression GREATER_EQUAL expression	{$$ = Expression_node::createExpressionNodeFromOperator(GREATER_EQUAL_EXPRESSION_TYPE, $1, $3);}
		  | expression '=' expression			{$$ = Expression_node::createExpressionNodeFromOperator(ASSIGNMENT_EXPRESSION_TYPE, $1, $3);}
		  ;

expression_e: /*empty*/		{$$ = NULL;}
			| expression	{$$ = $1;}
			;

message_expression: '[' receiver message_selector ']'	{$$ = Message_expression_node::createMessageExpressionNode($2, $3);}
				  ;

receiver: SUPER			{$$ = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);}
		| SELF			{$$ = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);}
		| CLASS_NAME	{$$ = Receiver_node::createReceiverNode(CLASS_NAME_RECEIVER_TYPE, $1);}
		;

message_selector: IDENTIFIER				{$$ = Message_selector_node::createMessageSelectorNode($1, NULL);}
				| keyword_argument_list		{$$ = Message_selector_node::createMessageSelectorNode(NULL, $1);}
				;

keyword_argument_list: keyword_argument							{$$ = Keyword_argument_list_node::createKeywordArgumentListNode($1);}
					 | keyword_argument_list keyword_argument	{$$ = Keyword_argument_list_node::addToKeywordArgumentListNode($1, $2);}
					 ;

keyword_argument: IDENTIFIER ':' expression		{$$ = Keyword_argument_node::createKeywordArgumentNode(WITH_IDENTIFIER_KW_ARGUMENT_TYPE, $1, $3);}
				| ':' expression				{$$ = Keyword_argument_node::createKeywordArgumentNode(WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE, NULL, $2);}
				;

// ---------- Управляющие структуры: развилки ----------
if_statement: IF '(' expression ')' statement					{$$ = If_statement_node::createIfStatementNode(WITHOUT_ALTERNATIVE_IF_TYPE, $3, $5, NULL);}
			| IF '(' expression ')' statement ELSE statement	{$$ = If_statement_node::createIfStatementNode(WITH_ALTERNATIVE_IF_TYPE, $3, $5, $7);}
			;

// ---------- Управляющие структуры: циклы ----------
while_statement: WHILE '(' expression ')' statement		{$$  = While_statement_node::createWhileStatementNode($3, $5);}
			   ;

do_while_statement: DO statement WHILE '(' expression ')' ';'	{$$ = Do_while_statement_node::createDoWhileStatementNode($5, $2);}
				  ;

for_statement: FOR '(' expression_e ';' expression_e ';' expression_e ')' statement		{$$ = For_statement_node::createForStatementNode($3, $5, $7, $9);}
			 | FOR '(' IDENTIFIER IN expression ')' statement							{$$ = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, $3, $5, $7);}
			 | FOR '(' type IDENTIFIER IN expression ')' statement						{$$ = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, $3, $4, $6, $8);}
			 ;

// ---------- Операторы ----------

statement: ';'							{$$ = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);}
		 | expression ';'				{$$ = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, $1);}
		 | RETURN expression_e ';'		{$$ = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, $2);}
		 | if_statement					{$$ = Statement_node::createStatementNodeFromComplexStatement(IF_STATEMENT_TYPE, $1);}
		 | while_statement				{$$ = Statement_node::createStatementNodeFromComplexStatement(WHILE_STATEMENT_TYPE, $1);}
		 | do_while_statement			{$$ = Statement_node::createStatementNodeFromComplexStatement(DO_WHILE_STATEMENT_TYPE, $1);}
		 | for_statement				{$$ = Statement_node::createStatementNodeFromComplexStatement(FOR_STATEMENT_TYPE, $1);}
		 | compound_statement			{$$ = Statement_node::createStatementNodeFromComplexStatement(COMPOUND_STATEMENT_TYPE, $1);}
		 | declaration					{$$ = Statement_node::createStatementNodeFromDeclaration($1);}
		 | class_declaration_list		{$$ = Statement_node::createStatementNodeFromClassDeclaration($1);}
		 ;

compound_statement: '{' statement_list_e '}'	{$$ = Compound_statement_node::createCompoundStatementNode($2);}
				  ;

statement_list: statement					{$$ = Statement_list_node::createStatementListNode($1);}
			  | statement_list statement	{$$ = Statement_list_node::addToStatementListNode($1, $2);}
			  ;

statement_list_e: /*empty*/			{$$ = NULL;}
				| statement_list	{$$ = $1;}
				;

class_statement: class_interface		{$$ = Class_statement_node::createClassStatementNodeFromInterface($1);}
			   | class_implementation	{$$ = Class_statement_node::createClassStatementNodeFromImplementation($1);}
			   ;

class_statement_list: class_statement							{$$ = Class_statement_list_node::createClassStatementListNode($1);}
					| class_statement_list class_statement		{$$ = Class_statement_list_node::addToClassStatementListNode($1, $2);}
					;

// ---------- Классы ----------
class_interface: INTERFACE IDENTIFIER ':' IDENTIFIER interface_statement END	{$$ = Class_interface_node::createClassInterfaceNode($2, $4, $5);}
			   | INTERFACE IDENTIFIER interface_statement END					{$$ = Class_interface_node::createClassInterfaceNode($2, NULL, $3);}
			   | INTERFACE IDENTIFIER ':' CLASS_NAME interface_statement END	{$$ = Class_interface_node::createClassInterfaceNode($2, $4, $5);}
			   ;

interface_statement: instance_variables interface_declaration_list	{$$ = Interface_statement_node::createInterfaceStatementNode($1, $2);}
				   | interface_declaration_list						{$$ = Interface_statement_node::createInterfaceStatementNode(NULL, $1);}
				   ;

implementation_statement: instance_variables implementation_definition_list	{$$ = Implementation_statement_node::createImplementationStatementNode($1, $2);}
						| implementation_definition_list					{$$ = Implementation_statement_node::createImplementationStatementNode(NULL, $1);}
						;

class_implementation: IMPLEMENTATION IDENTIFIER implementation_statement END					{$$ = Class_implementation_node::createClassImplementationNode($2, NULL, $3);}
					| IMPLEMENTATION IDENTIFIER ':' IDENTIFIER implementation_statement END		{$$ = Class_implementation_node::createClassImplementationNode($2, $4, $5);}
					| IMPLEMENTATION CLASS_NAME implementation_statement END					{$$ = Class_implementation_node::createClassImplementationNode($2, NULL, $3);}
					| IMPLEMENTATION CLASS_NAME ':' IDENTIFIER implementation_statement END		{$$ = Class_implementation_node::createClassImplementationNode($2, $4, $5);}
					| IMPLEMENTATION IDENTIFIER ':' CLASS_NAME implementation_statement END		{$$ = Class_implementation_node::createClassImplementationNode($2, $4, $5);}
					| IMPLEMENTATION CLASS_NAME ':' CLASS_NAME implementation_statement END		{$$ = Class_implementation_node::createClassImplementationNode($2, $4, $5);}
					;

class_declaration_list: CLASS class_list ';'	{$$ = Class_declaration_list_node::createClassDeclarationListNode($2);}
					  ;

class_list: IDENTIFIER					{$$ = Class_list_node::createClassListNode($1);}
		  | class_list ',' IDENTIFIER	{$$ = Class_list_node::addToClassListNode($1, $3);}
		  ;

instance_variables: '{' declaration_list '}'	{$$ = Instance_variables_node::createInstanceVariablesNode($2);}
				   ;

interface_declaration_list: declaration										{$$ = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration($1);}
						  | property										{$$ = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty($1);}
						  | method_declaration								{$$ = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration($1);}
						  | interface_declaration_list declaration			{$$ = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode($1, $2);}
						  | interface_declaration_list method_declaration	{$$ = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode($1, $2);}
						  | interface_declaration_list property				{$$ = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode($1, $2);}
						  ;

method_declaration: class_method_declaration		{$$ = $1;}
				  | instance_method_declaration		{$$ = $1;}
				  ;

class_method_declaration: '+' method_type method_selector ';'	{$$ = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, $2, $3);}
						| '+' '(' VOID ')' method_selector ';'	{$$ = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), $5);}
						| '+' method_selector ';'				{$$ = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, $2);}
						;

instance_method_declaration: '-' method_type method_selector ';' 	{$$ = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, $2, $3);}
						   | '-' '(' VOID ')' method_selector ';'	{$$ = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), $5);}
						   | '-' method_selector ';'				{$$ = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, $2);}
						   ;

implementation_definition_list: declaration											{$$ = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration($1);}
							  | property											{$$ = Implementation_definition_list_node::createImplementationDefinitionListNodeFromProperty($1);}
							  | method_definition									{$$ = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration($1);}
							  | implementation_definition_list declaration			{$$ = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode($1, $2);}
							  | implementation_definition_list method_definition	{$$ = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode($1, $2);}
							  | implementation_definition_list property				{$$ = Implementation_definition_list_node::addPropertyToImplementationDefinitionListNode($1, $2);}
							  ;

method_definition: class_method_definition		{$$ = $1;}
				 | instance_method_definition	{$$ = $1;}
				 ;

class_method_definition: '+' method_type method_selector declaration_list_e compound_statement		{$$ = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, $2, $3, $4, $5);}
					   | '+' '(' VOID ')' method_selector declaration_list_e compound_statement		{$$ = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), $5, $6, $7);}
					   | '+' method_selector declaration_list_e compound_statement					{$$ = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, $2, $3, $4);}
					   ;

instance_method_definition: '-' method_type method_selector declaration_list_e compound_statement	{$$ = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, $2, $3, $4, $5);}
					   	  | '-' '(' VOID ')' method_selector declaration_list_e compound_statement	{$$ = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), $5, $6, $7);}
						  | '-' method_selector declaration_list_e compound_statement				{$$ = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, $2, $3, $4);}
					   	  ;

method_selector: IDENTIFIER									{$$ = Method_selector_node::createMethodSelectorNode($1, NULL, NULL);}
			   | keyword_selector							{$$ = Method_selector_node::createMethodSelectorNode(NULL, $1, NULL);}
			   | keyword_selector ',' parameter_list	{$$ = Method_selector_node::createMethodSelectorNode(NULL, $1, $3);}
			   ;

keyword_selector: keyword_declaration						{$$ = Keyword_selector_node::createKeywordSelectorNode($1);}
				| keyword_selector keyword_declaration		{$$ = Keyword_selector_node::addToKeywordSelectorNode($1, $2);}
				;

keyword_declaration: ':' method_type IDENTIFIER					{$$ = Keyword_declaration_node::createKeywordDeclarationNode($2, NULL, $3);}
				   | ':' IDENTIFIER								{$$ = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, $2);}
				   | IDENTIFIER ':' method_type IDENTIFIER		{$$ = Keyword_declaration_node::createKeywordDeclarationNode($3, $1, $4);}
				   | IDENTIFIER ':' IDENTIFIER					{$$ = Keyword_declaration_node::createKeywordDeclarationNode(NULL, $1, $3);}
				   ;

method_type: '(' type ')'	{$$ = Type_node::createTypeNode($2);}
		   ;

property: PROPERTY '(' attribute ')' type IDENTIFIER ';'	{$$ = Property_node::createPropertyNode($3, $5, $6);}
		;

attribute: READONLY		{$$ = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);}
		 | READWRITE	{$$ = Attribute_node::createAttributeNode(READWRITE_ATTRIBUTE_TYPE);}
		 ;

%%

