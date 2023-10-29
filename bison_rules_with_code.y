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
	Class_block_node *Class_block;
	Class_interface_node *Class_interface;
	Interface_body_node *Interface_body;
	Implementation_body_node *Implementation_body;
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
	Function_and_class_list_node *Function_and_class_list;
	Function_node *Function;
	Declarator_node *Declarator;
	Declarator_list_node *Declarator_list;
	Instance_variables_declaration_node *Instance_variables_declaration;
	Instance_variables_declaration_list_node *Instance_variables_declaration_list;
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
%type <Init_declarator_list> init_declarator_list_e init_declarator_list init_declarator_with_asterisk_list init_declarator_with_asterisk_list_e
%type <Init_declarator> init_declarator init_declarator_with_asterisk
%type <Parameter_list> parameter_list
%type <Parameter_declaration> parameter_declaration
%type <Expression> expression expression_e
%type <Receiver> receiver
%type <Message_selector> message_selector
%type <Keyword_argument_list> keyword_argument_list keyword_argument_list_e
%type <Keyword_argument> keyword_argument
%type <If> if_statement
%type <While> while_statement
%type <Do_while> do_while_statement
%type <For> for_statement
%type <Statement> statement
%type <Compound_statement> compound_statement
%type <Statement_list> statement_list_e statement_list
%type <Class_block> class_block
%type <Class_interface> class_interface
%type <Interface_body> interface_body
%type <Implementation_body> implementation_body
%type <Class_implementation> class_implementation
%type <Class_declaration_list> class_declaration_list 
%type <Class_list> class_list
%type <Instance_variables> instance_variables
%type <Interface_declaration_list> interface_declaration_list
%type <Method_declaration> method_declaration class_method_declaration instance_method_declaration
%type <Implementation_definition_list> implementation_definition_list
%type <Method_definition> method_definition class_method_definition instance_method_definition
%type <Method_selector> method_selector
%type <Keyword_selector> keyword_selector keyword_selector_e
%type <Keyword_declaration> keyword_declaration keyword_declaration_without_identifier
%type <Property> property
%type <Attribute> attribute
%type <Program> program 
%type <Function_and_class_list> function_and_class_list
%type <Function> function
%type <Declarator> declarator declarator_with_asterisk
%type <Declarator_list> declarator_list declarator_with_asterisk_list
%type <Instance_variables_declaration> instance_variables_declaration
%type <Instance_variables_declaration_list> instance_variables_declaration_list


%start program

%%

program: function_and_class_list	{$$ = Program_node::createProgramNode($1);}
	   ;

function_and_class_list: class_block									{$$ = Function_and_class_list_node::createFunctionAndClassListNodeFromClassBlock($1);}
					   | function										{$$ = Function_and_class_list_node::createFunctionAndClassListNodeFromFunction($1);}
					   | class_declaration_list							{$$ = Function_and_class_list_node::createFunctionAndClassListNodeFromClassDeclarationList($1);}
					   | function_and_class_list class_block			{$$ = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassBlock($1, $2);}
					   | function_and_class_list function				{$$ = Function_and_class_list_node::addToFunctionAndClassListNodeFromFunction($1, $2);}
					   | function_and_class_list class_declaration_list	{$$ = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassDeclarationList($1, $2);}
					   ;

// ---------- Заглушки для списка функций ----------

function: type IDENTIFIER '(' ')' compound_statement /*Заглушка, тут должно быть определение функции*/ {$$ = Function_node::createFunctionNode($1, $2, $5);}
		;
// ---------- Типы ----------
type: INT				{$$ = Type_node::createTypeNode(INT_TYPE);}
    | CHAR				{$$ = Type_node::createTypeNode(CHAR_TYPE);}
    | FLOAT				{$$ = Type_node::createTypeNode(FLOAT_TYPE);}
    | ID				{$$ = Type_node::createTypeNode(ID_TYPE);}
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
		   | CLASS_NAME init_declarator_with_asterisk_list_e ';' {$$ = Declaration_node::createDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, $1), $2)}
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

init_declarator: declarator						{$$ = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, $1, NULL);}
			   | declarator '=' expression		{$$ = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, $1, $3);}
			   ;

declarator: IDENTIFIER	{$$ = Declarator_node::createDeclaratorNode($1);}
		  ;

declarator_with_asterisk: '*' IDENTIFIER	{$$ = Declarator_node::createDeclaratorNode($2);}
						;

declarator_with_asterisk_list: declarator_with_asterisk										{$$ = Declarator_list_node::createDeclaratorListNode($1);}
							 | declarator_with_asterisk_list ',' declarator_with_asterisk	{$$ = Declarator_list_node::addToDeclaratorListNode($1);}

declarator_list: declarator							{$$ = Declarator_list_node::createDeclaratorListNode($1);}
			   | declarator_list ',' declarator		{$$ = Declarator_list_node::addToDeclaratorListNode($1);}
			   ;

init_declarator_with_asterisk: declarator_with_asterisk					{$$ = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, $1, NULL);}
			   				 | declarator_with_asterisk '=' expression	{$$ = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, $1, $3);}
							 ;

init_declarator_with_asterisk_list: init_declarator_with_asterisk											{$$ = Init_declarator_list_node::createInitDeclaratorListNode($1);}								
								  | init_declarator_with_asterisk_list ',' init_declarator_with_asterisk	{$$ = Init_declarator_list_node::addToInitDeclaratorListNode($1, $3);}
								  ;

init_declarator_with_asterisk_list_e: /*empty*/								{$$ = NULL;}
									| init_declarator_with_asterisk_list	{$$ = $1;}
									;

parameter_list: parameter_declaration						{$$ = Parameter_list_node::createParameterListNode($1);}
			  | parameter_list ',' parameter_declaration	{$$ = Parameter_list_node::addToParameterListNode($1, $3);}
			  ;

parameter_declaration: type IDENTIFIER			{$$ = Parameter_declaration_node::createParameterDeclarationNode($1, $2);}
					 | CLASS_NAME '*' IDENTIFIER	{$$ = Parameter_declaration_node::createParameterDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, $1),$3);}
					 ;

// ---------- Выражения ----------

expression: IDENTIFIER							{$$ = Expression_node::createExpressionNodeFromIdentifier($1);}
		  | literal								{$$ = Expression_node::createExpressionNodeFromLiteral($1);}
		  | numeric_constant					{$$ = Expression_node::createExpressionNodeFromNumericConstant($1);}
		  | '(' expression ')'					{$$ = Expression_node::createSimpleExpressionNode(PRIORITY_EXPRESSION_TYPE, $2);}
		  | SELF								{$$ = Expression_node::createExpressionNodeFromSelf();}
		  | '[' receiver message_selector ']'	{$$ = Expression_node::createExpressionNodeFromMessageExpression($2, $3);}
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

receiver: SUPER								{$$ = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);}
		| SELF								{$$ = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);}
		| IDENTIFIER						{$$ = Receiver_node::createReceiverNode(OBJECT_NAME_RECEIVER_TYPE, $1);}
		| '[' receiver message_selector ']'	{$$ = Receiver_node::createReceiverNodeFromMessageExpression($2, $3);}
		;

message_selector: IDENTIFIER										{$$ = Message_selector_node::createMessageSelectorNode($1, NULL, NULL);}
				| IDENTIFIER ':' expression keyword_argument_list_e	{$$ = Message_selector_node::createMessageSelectorNode($1, $3, $4);}
				;

keyword_argument_list_e: /*empty*/				{$$ = NULL;}
					   | keyword_argument_list	{$$ = $1;}
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
			 | FOR '(' CLASS_NAME '*' IDENTIFIER IN expression ')' statement			{$$ = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, $3), $5, $7, $9);}
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
		 ;

compound_statement: '{' statement_list_e '}'	{$$ = Compound_statement_node::createCompoundStatementNode($2);}
				  ;

statement_list: statement					{$$ = Statement_list_node::createStatementListNode($1);}
			  | statement_list statement	{$$ = Statement_list_node::addToStatementListNode($1, $2);}
			  ;

statement_list_e: /*empty*/			{$$ = NULL;}
				| statement_list	{$$ = $1;}
				;

class_block: class_interface		{$$ = Class_block_node::createClassBlockNodeFromInterface($1);}
	 	   | class_implementation	{$$ = Class_block_node::createClassBlcokNodeFromImplementation($1);}
		   ;

// ---------- Классы ----------
class_interface: INTERFACE IDENTIFIER ':' IDENTIFIER interface_body END	{$$ = Class_interface_node::createClassInterfaceNode($2, $4, $5);}
			   | INTERFACE IDENTIFIER interface_body END					{$$ = Class_interface_node::createClassInterfaceNode($2, NULL, $3);}
			   | INTERFACE IDENTIFIER ':' CLASS_NAME interface_body END	{$$ = Class_interface_node::createClassInterfaceNode($2, $4, $5);}
			   ;

interface_body: instance_variables interface_declaration_list	{$$ = Interface_body_node::createInterfaceBodyNode($1, $2);}
			  | interface_declaration_list						{$$ = Interface_body_node::createInterfaceBodyNode(NULL, $1);}
			  ;

implementation_body: instance_variables implementation_definition_list	{$$ = Implementation_body_node::createImplementationBodyNode($1, $2);}
			       | implementation_definition_list						{$$ = Implementation_body_node::createImplementationBodyNode(NULL, $1);}
				   ;

class_implementation: IMPLEMENTATION IDENTIFIER implementation_body END						{$$ = Class_implementation_node::createClassImplementationNode($2, NULL, $3);}
					| IMPLEMENTATION IDENTIFIER ':' IDENTIFIER implementation_body END		{$$ = Class_implementation_node::createClassImplementationNode($2, $4, $5);}
					| IMPLEMENTATION CLASS_NAME implementation_body END						{$$ = Class_implementation_node::createClassImplementationNode($2, NULL, $3);}
					| IMPLEMENTATION CLASS_NAME ':' IDENTIFIER implementation_body END		{$$ = Class_implementation_node::createClassImplementationNode($2, $4, $5);}
					| IMPLEMENTATION IDENTIFIER ':' CLASS_NAME implementation_body END		{$$ = Class_implementation_node::createClassImplementationNode($2, $4, $5);}
					| IMPLEMENTATION CLASS_NAME ':' CLASS_NAME implementation_body END		{$$ = Class_implementation_node::createClassImplementationNode($2, $4, $5);}
					;

class_declaration_list: CLASS class_list ';'	{$$ = Class_declaration_list_node::createClassDeclarationListNode($2);}
					  ;

class_list: IDENTIFIER					{$$ = Class_list_node::createClassListNode($1);}
		  | class_list ',' IDENTIFIER	{$$ = Class_list_node::addToClassListNode($1, $3);}
		  ;

instance_variables: '{' instance_variables_declaration_list '}'	{$$ = Instance_variables_node::createInstanceVariablesNode($2);}
				   ;

instance_variables_declaration: type declarator_list ';'						{$$ = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode($1, $2);}
							  | CLASS_NAME declarator_with_asterisk_list ';'	{$$ = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, $1), $2);}
							  ;

instance_variables_declaration_list: instance_variables_declaration											{$$ = Instance_variables_declaration_list_node::createInstanceVariablesDeclarationListNode($1);}
								   | instance_variables_declaration_list instance_variables_declaration		{$$ = Instance_variables_declaration_list_node::addToInstanceVariablesDeclarationListNode($1, $2);}
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
							  | method_definition									{$$ = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration($1);}
							  | implementation_definition_list declaration			{$$ = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode($1, $2);}
							  | implementation_definition_list method_definition	{$$ = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode($1, $2);}
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

method_selector: IDENTIFIER																						{$$ = Method_selector_node::createMethodSelectorNode($1, NULL, NULL, NULL);}
			   | IDENTIFIER ':' keyword_declaration_without_identifier keyword_selector_e						{$$ = Method_selector_node::createMethodSelectorNode($1, $3, $4, NULL);}
			   | IDENTIFIER ':' keyword_declaration_without_identifier keyword_selector_e ',' parameter_list 	{$$ = Method_selector_node::createMethodSelectorNode($1, $3, $4, $6);}
			   ;

keyword_selector_e: /*empty*/			{$$ = NULL;}
				  | keyword_selector	{$$ = $1;}
				  ;

keyword_selector: keyword_declaration						{$$ = Keyword_selector_node::createKeywordSelectorNode($1);}
				| keyword_selector keyword_declaration		{$$ = Keyword_selector_node::addToKeywordSelectorNode($1, $2);}
				;

keyword_declaration_without_identifier: method_type IDENTIFIER	{$$ = Keyword_declaration_node::createKeywordDeclarationNode($1, NULL, $2);}
				   					  | IDENTIFIER				{$$ = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, $1);}
									  ;

keyword_declaration: ':' method_type IDENTIFIER					{$$ = Keyword_declaration_node::createKeywordDeclarationNode($2, NULL, $3);}
				   | ':' IDENTIFIER								{$$ = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, $2);}
				   | IDENTIFIER ':' method_type IDENTIFIER		{$$ = Keyword_declaration_node::createKeywordDeclarationNode($3, $1, $4);}
				   | IDENTIFIER ':' IDENTIFIER					{$$ = Keyword_declaration_node::createKeywordDeclarationNode(NULL, $1, $3);}
				   ;

method_type: '(' type ')'	{$$ = Type_node::createTypeNode($2);}
		   | '(' CLASS_NAME '*' ')' {$$ = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, $2);}
		   ;

property: PROPERTY '(' attribute ')' type IDENTIFIER ';'	{$$ = Property_node::createPropertyNode($3, $5, $6);}
		| PROPERTY '(' attribute ')' CLASS_NAME '*' IDENTIFIER ';'	{$$ = Property_node::createPropertyNode($3, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, $5), $7);}
		| PROPERTY type IDENTIFIER ';'	{$$ = Property_node::createPropertyNode(NULL, $2, $3);}
		| PROPERTY CLASS_NAME '*' IDENTIFIER ';'	{$$ = Property_node::createPropertyNode(NULL, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, $2), $4);}
		| PROPERTY '(' ')' type IDENTIFIER ';'	{$$ = Property_node::createPropertyNode(NULL, $4, $5);}
		| PROPERTY '(' ')' CLASS_NAME '*' IDENTIFIER ';'	{$$ = Property_node::createPropertyNode(NULL, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, $4), $6);}
		;

attribute: READONLY		{$$ = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);}
		 | READWRITE	{$$ = Attribute_node::createAttributeNode(READWRITE_ATTRIBUTE_TYPE);}
		 ;

%%

