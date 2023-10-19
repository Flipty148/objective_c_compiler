%{
	#include "classes_nodes.h"
	#include "user_functions.h"
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
	Int_node *Int;
	Char_node *Char;
	Float_node *Float;
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
%token <Int> INT 
%token <Char> CHAR 
%token <Float> FLOAT
%token VOID
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
%token ELIPSIS

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

program: statement_list							{$$ = root = createProgramNode($1, NULL);}
	   | class_statement_list					{$$ = root = createProgramNode(NULL, $1);}
	   | statement_list class_statement_list	{$$ = root = createProgramNode($1, $2);}
	   | class_statement_list statement_list	{$$ = root = createProgramNode($2, $1);}
	   ;

// ---------- Типы ----------
type: INT				{$$ = createTypeNode(INT);}
    | CHAR				{$$ = createTypeNode(CHAR);}
    | FLOAT				{$$ = createTypeNode(FLOAT);}
    | ID				{$$ = createTypeNode(ID);}
	| CLASS_NAME '*'	{$$ = createClassTypeNode(CLASS_NAME, $1);}
    ;

// ---------- Константы ----------
numeric_constant: FLOAT_CONSTANT	{$$ = createFloatConstantNode($1);}
                | INTEGER_CONSTANT	{$$ = createIntegerConstantNode($1);}
                ;

literal: STRING_CONSTANT	{$$ = createLiteralNode(STRING_CONSTANT, $1);}
       | CHAR_CONSTANT		{$$ = createLiteralNode(CHAR_CONSTANT, $1);}
	   | NSSTRING_CONSTANT	{$$ = createLiteralNode(NSSTRING_CONSTANT, $1);}
       ;

// ---------- Объявления ----------
declaration: type init_declarator_list_e ';'	{$$ = createDeclarationNode($1, $2);}
           ;

declaration_list: declaration 					{$$ = createDeclarationListNode($1);}
				| declaration_list declaration	{$$ = addDeclarationListNode($1, $2);}
				;

declaration_list_e: /*empty*/			{$$ = NULL;}
				  | declaration_list	{$$ = $1;}
				  ;

init_declarator_list_e: /* empty */			{$$ = NULL;}
					| init_declarator_list	{$$ = $1;}
					;

init_declarator_list: init_declarator							{$$ = createInitDeclaratorListNode($1);}
					| init_declarator_list ',' init_declarator	{$$ = addInitDeclaratorListNode($1, $3);}
					;

init_declarator: IDENTIFIER					{$$ = createInitDeclaratorNode(SIMPLE_DECLARATOR, $1, NULL);}
			   | IDENTIFIER '=' expression	{$$ = createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING, $1, $3);}
			   ;

parameter_type_list: parameter_list /* Не знаю, нужно ли делать класс для узла */
				   | parameter_list ',' ELIPSIS
				   ;

parameter_list: parameter_declaration						{$$ = createParameterListNode($1);}
			  | parameter_list ',' parameter_declaration	{$$ = addParameterListNode($1, $3);}
			  ;

parameter_declaration: type IDENTIFIER			{$$ = createParameterDeclarationNode($1, $2);}
					 | CLASS_NAME IDENTIFIER	{$$ = createParameterDeclarationNode($1, $2);}
					 ;

// ---------- Выражения ----------

expression: IDENTIFIER							{$$ = createIdentifierExpressionNode($1);}
		  | literal								{$$ = createLiteralExpressionNode($1);}
		  | numeric_constant					{$$ = createNumericConstantExpressionNode($1);}
		  | '(' expression ')'					{$$ = createSimpleExpressionNode(PRIORITY, $2);}
		  | SELF								{$$ = createSelfExpressionNode();}
		  | message_expression					{$$ = createSimpleExpressionNode(MESSAGE_EXPRESSION, $1);}
		  | '-' expression %prec UMINUS			{$$ = createOperationExpressionNode(UMINUS, NULL, $2);}
		  | '+' expression %prec UPLUS			{$$ = createOperationExpressionNode(UPLUS, NULL, $2);}
		  | '&' expression %prec UAMPERSAND		{$$ = createOperationExpressionNode(UAMPERSAND, NULL, $2);}
		  | expression '+' expression			{$$ = createOperationExpressionNode(PLUS, $1, $3);}
		  | expression '-' expression			{$$ = createOperationExpressionNode(MINUS, $1, $3);}
		  | expression '*' expression			{$$ = createOperationExpressionNode(MUL, $1, $3);}
		  | expression '/' expression			{$$ = createOperationExpressionNode(DIV, $1, $3);}
		  | expression EQUAL expression			{$$ = createOperationExpressionNode(EQUAL, $1, $3);}
		  | expression NOT_EQUAL expression		{$$ = createOperationExpressionNode(NOT_EQUAL, $1, $3);}
		  | expression '>' expression			{$$ = createOperationExpressionNode(GREATER, $1, $3);}
		  | expression '<' expression			{$$ = createOperationExpressionNode(LESS, $1, $3);}
		  | expression LESS_EQUAL expression	{$$ = createOperationExpressionNode(LESS_EQUAL, $1, $3);}
		  | expression GREATER_EQUAL expression	{$$ = createOperationExpressionNode(GREATER_EQUAL, $1, $3);}
		  | expression '=' expression			{$$ = createOperationExpressionNode(ASSIGNMENT, $1, $3);}
		  ;

expression_e: /*empty*/		{$$ = NULL;}
			| expression	{$$ = $1;}
			;

message_expression: '[' receiver message_selector ']'	{$$ = createMessageExpressionNode($2, $3);}
				  ;

receiver: SUPER			{$$ = createReceiverNode(SUPER, NULL);}
		| SELF			{$$ = createReceiverNode(SELF, NULL);}
		| CLASS_NAME	{$$ = createReceiverNode(CLASS_NAME, $1);}
		;

message_selector: IDENTIFIER				{$$ = createMethodSelectorNode($1, NULL);}
				| keyword_argument_list		{$$ = createMethodSelectorNode(NULL, $1);}
				;

keyword_argument_list: keyword_argument							{$$ = createKeywordArgumentListNode($1);}
					 | keyword_argument_list keyword_argument	{$$ = addKeywordArgumentListNode($1, $2);}
					 ;

keyword_argument: IDENTIFIER ':' expression		{$$ = createKeywordArgumentNode(WITH_IDENTIFIER, $1, $3);}
				| ':' expression				{$$ = createKeywordArgumentNode(WITHOUT_IDENTIFIER, NULL, $2);}
				;

// ---------- Управляющие структуры: развилки ----------
if_statement: IF '(' expression ')' statement					{$$ = createIfStatementNode(WITHOUT_ALTERNATIVE, $3, $5, NULL);}
			| IF '(' expression ')' statement ELSE statement	{$$ = createIfStatementNode(WITHOUT_ALTERNATIVE, $3, $5, $7);}
			;

// ---------- Управляющие структуры: циклы ----------
while_statement: WHILE '(' expression ')' statement		{$$  = createWhileStatementNode($3, $5);}
			   ;

do_while_statement: DO statement WHILE '(' expression ')' ';'	{$$ = createDoWhileStatementNode($5, $2);}
				  ;

for_statement: FOR '(' expression_e ';' expression_e ';' expression_e ')' statement		{$$ = createForStatementNode($3, $5, $7, $9);}
			 | FOR '(' IDENTIFIER IN expression ')' statement							{$$ = createForeachStatementNode(FOREACH, NULL, $3, $5, $7);}
			 | FOR '(' type IDENTIFIER IN expression ')' statement						{$$ = createForeachStatementNode(FOREACH_WITH_DECLARATION, $3, $4, $6, $8);}
			 ;

// ---------- Операторы ----------

statement: ';'							{$$ = createSimpleStatementNode(EMPTY, NULL);}
		 | expression ';'				{$$ = createSimpleStatementNode(SIMPLE, $1);}
		 | RETURN expression_e ';'		{$$ = createSimpleStatementNode(RETURN, $2);}
		 | if_statement					{$$ = createComplexStatementNode(statement_type::IF, $1);}
		 | while_statement				{$$ = createComplexStatementNode(statement_type::WHILE, $1);}
		 | do_while_statement			{$$ = createComplexStatementNode(statement_type::DO_WHILE, $1);}
		 | for_statement				{$$ = createComplexStatementNode(statement_type::FOR, $1);}
		 | compound_statement			{$$ = createComplexStatementNode(statement_type::COMPOUND, $1);}
		 | declaration					{$$ = createDeclarationStatementNode($1);}
		 | class_declaration_list		{$$ = createClassDeclarationStatementNode($1);}
		 ;

compound_statement: '{' statement_list_e '}'	{$$ = createCompoundStatementNode($2);}
				  ;

statement_list: statement					{$$ = createStatementListNode($1);}
			  | statement_list statement	{$$ = addStatementListNode($1, $2);}
			  ;

statement_list_e: /*empty*/			{$$ = NULL;}
				| statement_list	{$$ = $1;}
				;

class_statement: class_interface		{$$ = createInterfaceClassStatementNode($1);}
			   | class_implementation	{$$ = createImplementationClassStatementNode($1);}
			   ;

class_statement_list: class_statement							{$$ = createClassStatementListNode($1);}
					| class_statement_list class_statement		{$$ = addClassStatementListNode($1, $2);}
					;

// ---------- Классы ----------
class_interface: INTERFACE IDENTIFIER ':' IDENTIFIER interface_statement END	{$$ = createClassInterfaceNode(class_interface_type::WITH_INHERITANCE, $2, $4, $5);}
			   | INTERFACE IDENTIFIER interface_statement END					{$$ = createClassInterfaceNode(class_interface_type::WITHOUT_INHERITANCE, $2, NULL, $3);}
			   | INTERFACE IDENTIFIER ':' CLASS_NAME interface_statement END	{$$ = createClassInterfaceNode(class_interface_type::WITH_INHERITANCE, $2, $4, $5);}
			   ;

interface_statement: instance_variables interface_declaration_list	{$$ = createInterfaceStatementNode($1, $2);}
				   | interface_declaration_list						{$$ = createInterfaceStatementNode(NULL, $1);}
				   ;

implementation_statement: instance_variables implementation_definition_list	{$$ = createImplementationStatementNode($1, $2);}
						| implementation_definition_list					{$$ = createImplementationStatementNode(NULL, $1);}
						;

class_implementation: IMPLEMENTATION IDENTIFIER implementation_statement END					{$$ = createClassImplementationNode(class_implementation_type::WITHOUT_INHERITANCE, $2, NULL, $3);}
					| IMPLEMENTATION IDENTIFIER ':' IDENTIFIER implementation_statement END		{$$ = createClassImplementationNode(class_implementation_type::WITH_INHERITANCE, $2, $4, $5);}
					| IMPLEMENTATION CLASS_NAME implementation_statement END					{$$ = createClassImplementationNode(class_implementation_type::WITHOUT_INHERITANCE, $2, NULL, $3);}
					| IMPLEMENTATION CLASS_NAME ':' IDENTIFIER implementation_statement END		{$$ = createClassImplementationNode(class_implementation_type::WITH_INHERITANCE, $2, $4, $5);}
					| IMPLEMENTATION IDENTIFIER ':' CLASS_NAME implementation_statement END		{$$ = createClassImplementationNode(class_implementation_type::WITH_INHERITANCE, $2, $4, $5);}
					| IMPLEMENTATION CLASS_NAME ':' CLASS_NAME implementation_statement END		{$$ = createClassImplementationNode(class_implementation_type::WITH_INHERITANCE, $2, $4, $5);}
					;

class_declaration_list: CLASS class_list ';'	{$$ = createClassDeclarationListNode($2);}
					  ;

class_list: IDENTIFIER					{$$ = createClassListNode($1);}
		  | class_list ',' IDENTIFIER	{$$ = addClassListNode($1, $3);}
		  ;

instance_variables: '{' declaration_list '}'	{$$ = createInstanceVariablesNode($2);}
				   ;

interface_declaration_list: declaration										{$$ = createDeclarationInterfaceDeclarationListNode($1);}
						  | property										{$$ = createPropertyInterfaceDeclarationListNode($1);}
						  | method_declaration								{$$ = createMethodDeclarationInterfaceDeclarationListNode($1);}
						  | interface_declaration_list declaration			{$$ = addDeclarationInterfaceDeclarationListNode($1, $2);}
						  | interface_declaration_list method_declaration	{$$ = addMethodDeclarationInterfaceDeclarationListNode($1, $2);}
						  | interface_declaration_list property				{$$ = addPropertyInterfaceDeclarationListNode($1, $2);}
						  ;

method_declaration: class_method_declaration		{$$ = $1;}
				  | instance_method_declaration		{$$ = $1;}
				  ;

class_method_declaration: '+' method_type method_selector ';'	{$$ = createMethodDeclarationNode(method_declaration_type::CLASS, $2, $3);}
						| '+' '(' VOID ')' method_selector ';'	{$$ = createMethodDeclarationNode(method_declaration_type::CLASS, $3, $5);}
						| '+' method_selector ';'				{$$ = createMethodDeclarationNode(method_declaration_type::CLASS, NULL, $2);}
						;

instance_method_declaration: '-' method_type method_selector ';' 	{$$ = createMethodDeclarationNode(method_declaration_type::INSTANCE, $2, $3);}
						   | '-' '(' VOID ')' method_selector ';'	{$$ = createMethodDeclarationNode(method_declaration_type::INSTANCE, $3, $5);}
						   | '-' method_selector ';'				{$$ = createMethodDeclarationNode(method_declaration_type::INSTANCE, NULL, $2);}
						   ;

implementation_definition_list: declaration											{$$ = createDeclarationImplementationDefinitionListNode($1);}
							  | property											{$$ = createPropertyImplementationDefinitionListNode($1);}
							  | method_definition									{$$ = createMethodDeclarationImplementationDefinitionListNode($1);}
							  | implementation_definition_list declaration			{$$ = addDeclarationImplementationDefinitionListNode($1, $2);}
							  | implementation_definition_list method_definition	{$$ = addMethodDeclarationImplementationDefinitionListNode($1, $2);}
							  | implementation_definition_list property				{$$ = addPropertyImplementationDefinitionListNode($1, $2);}
							  ;

method_definition: class_method_definition		{$$ = $1;}
				 | instance_method_definition	{$$ = $1;}
				 ;

class_method_definition: '+' method_type method_selector declaration_list_e compound_statement		{$$ = createMethodDefinitionNode(method_definition_type::CLASS, $2, $3, $4, $5);}
					   | '+' '(' VOID ')' method_selector declaration_list_e compound_statement		{$$ = createMethodDefinitionNode(method_definition_type::CLASS, $3, $5, $6, $7);}
					   | '+' method_selector declaration_list_e compound_statement					{$$ = createMethodDefinitionNode(method_definition_type::CLASS, NULL, $2, $3, $4);}
					   ;

instance_method_definition: '-' method_type method_selector declaration_list_e compound_statement	{$$ = createMethodDefinitionNode(method_definition_type::INSTANCE, $2, $3, $4, $5);}
					   	  | '-' '(' VOID ')' method_selector declaration_list_e compound_statement	{$$ = createMethodDefinitionNode(method_definition_type::INSTANCE, $3, $5, $6, $7);}
						  | '-' method_selector declaration_list_e compound_statement				{$$ = createMethodDefinitionNode(method_definition_type::INSTANCE, NULL, $2, $3, $4);}
					   	  ;

method_selector: IDENTIFIER									{$$ = createMethodSelectorNode($1, NULL, NULL);}
			   | keyword_selector							{$$ = createMethodSelectorNode(NULL, $1, NULL);}
			   | keyword_selector ',' parameter_type_list	{$$ = createMethodSelectorNode(NULL, $1, $3);}
			   ;

keyword_selector: keyword_declaration						{$$ = createKeywordSelectorNode($1);}
				| keyword_selector keyword_declaration		{$$ = addKeywordSelectorNode($1, $2);}
				;

keyword_declaration: ':' method_type IDENTIFIER					{$$ = createKeywordDeclarationNode($2, NULL, $3);}
				   | ':' IDENTIFIER								{$$ = createKeywordDeclarationNode(NULL, NULL, $2);}
				   | IDENTIFIER ':' method_type IDENTIFIER		{$$ = createKeywordDeclarationNode($3, $1, $4);}
				   | IDENTIFIER ':' IDENTIFIER					{$$ = createKeywordDeclarationNode(NULL, $1, $3);}
				   ;

method_type: '(' type ')'	{$$ = createTypeNode($2);}
		   ;

property: PROPERTY '(' attribute ')' type IDENTIFIER ';'	{$$ = createPropertyNode($3, $5, $6);}
		;

attribute: READONLY		{$$ = createAttributeNode(READONLY);}
		 | READWRITE	{$$ = createAttributeNode(READWRITE);}
		 ;

%%

