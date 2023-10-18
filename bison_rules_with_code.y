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
%type <Class_declaration_list> class_declaration_list class_list
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
if_statement: IF '(' expression ')' statement
			| IF '(' expression ')' statement ELSE statement
			;

// ---------- Управляющие структуры: циклы ----------
while_statement: WHILE '(' expression ')' statement
			   ;

do_while_statement: DO statement WHILE '(' expression ')' ';'
				  ;

for_statement: FOR '(' expression_e ';' expression_e ';' expression_e ')' statement
			 | FOR '(' IDENTIFIER IN expression ')' statement
			 | FOR '(' type IDENTIFIER IN expression ')' statement
			 ;

// ---------- Операторы ----------

statement: ';'
		 | expression ';'
		 | RETURN expression_e ';'
		 | if_statement
		 | while_statement
		 | do_while_statement
		 | for_statement
		 | compound_statement
		 | declaration
		 | class_declaration_list
		 ;

compound_statement: '{' statement_list_e '}'
				  ;

statement_list: statement
			  | statement_list statement
			  ;

statement_list_e: /*empty*/
				| statement_list
				;

class_statement: class_interface
			   | class_implementation
			   ;

class_statement_list: class_statement
					| class_statement_list class_statement
					;

// ---------- Классы ----------
class_interface: INTERFACE IDENTIFIER ':' IDENTIFIER interface_statement END
			   | INTERFACE IDENTIFIER interface_statement END
			   ;

interface_statement: instance_variables interface_declaration_list
				   | interface_declaration_list
				   ;

implementation_statement: instance_variables implementation_definition_list
						| implementation_definition_list
						;

class_implementation: IMPLEMENTATION IDENTIFIER implementation_statement END
					| IMPLEMENTATION IDENTIFIER ':' IDENTIFIER implementation_statement END
					;

class_declaration_list: CLASS class_list ';'
					  ;

class_list: IDENTIFIER
		  | class_list ',' IDENTIFIER
		  ;

instance_variables: '{' declaration_list '}'
				   | '{' declaration_list instance_variables '}'
				   ;

interface_declaration_list: declaration
						  | property
						  | method_declaration
						  | interface_declaration_list declaration
						  | interface_declaration_list method_declaration
						  | interface_declaration_list property
						  ;

method_declaration: class_method_declaration
				  | instance_method_declaration
				  ;

class_method_declaration: '+' method_type method_selector ';'
						| '+' '(' VOID ')' method_selector ';'
						| '+' method_selector ';'
						;

instance_method_declaration: '-' method_type method_selector ';'
						   | '-' '(' VOID ')' method_selector ';'
						   | '-' method_selector ';'
						   ;

implementation_definition_list: declaration
							  | property
							  | method_definition
							  | implementation_definition_list declaration
							  | implementation_definition_list method_definition
							  | implementation_definition_list property
							  ;

method_definition: class_method_definition
				 | instance_method_definition
				 ;

class_method_definition: '+' method_type method_selector declaration_list_e compound_statement
					   | '+' '(' VOID ')' method_selector declaration_list_e compound_statement
					   | '+' method_selector declaration_list_e compound_statement
					   ;

instance_method_definition: '-' method_type method_selector declaration_list_e compound_statement
					   	  | '-' '(' VOID ')' method_selector declaration_list_e compound_statement
						  | '-' method_selector declaration_list_e compound_statement
					   	  ;

method_selector: IDENTIFIER
			   | keyword_selector
			   | keyword_selector ',' parameter_type_list
			   ;

keyword_selector: keyword_declaration
				| keyword_selector keyword_declaration
				;

keyword_declaration: ':' method_type IDENTIFIER
				   | ':' IDENTIFIER
				   | IDENTIFIER ':' method_type IDENTIFIER
				   | IDENTIFIER ':' IDENTIFIER
				   ;

method_type: '(' type ')'
		   ;

property: PROPERTY '(' attribute ')' type IDENTIFIER ';'
		;

attribute: READONLY
		 | READWRITE
		 ;

%%

