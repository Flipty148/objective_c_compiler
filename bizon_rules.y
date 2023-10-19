// ---------- Операции с их приоритетом ----------
%right '='
%left EQUAL NOT_EQUAL
%left '<' '>' LESS_EQUAL GREATER_EQUAL
%left '+' '-'
%left '*' '/'
%right UMINUS UPLUS UAMPERSAND
%nonassoc '(' ')' '[' ']'

//---------- Терминальные символы ----------
%token INT CHAR FLOAT ENUM CLASS_NAME
%token VOID
%token IF ELSE WHILE DO FOR
%token IN
%token INTERFACE IMPLEMENTATION 
%token END
%token PROPERTY
%token READONLY READWRITE
%token SELF SUPER ID  /* НУЖНО ЛИ SUPER добавлять в expression */
%token CLASS
%token RETURN
%token INTEGER_CONSTANT STRING_CONSTANT CHAR_CONSTANT FLOAT_CONSTANT NSSTRING_CONSTANT
%token IDENTIFIER
%token ELIPSIS

%start program

%%

program: statement_list
	   | class_statement_list
	   | statement_list class_statement_list
	   | class_statement_list statement_list
	   ;

// ---------- Типы ----------
type: INT
    | CHAR
    | FLOAT
    | ID
	| CLASS_NAME '*'
    ;

// ---------- Константы ----------
numeric_constant: FLOAT_CONSTANT
                | INTEGER_CONSTANT
                ;

literal: STRING_CONSTANT
       | CHAR_CONSTANT
	   | NSSTRING_CONSTANT
       ;

// ---------- Объявления ----------
declaration: type init_declarator_list_e ';'
           ;

declaration_list: declaration
				| declaration_list declaration
				;

declaration_list_e: /*empty*/
				  | declaration_list
				  ;

init_declarator_list_e: /* empty */
					| init_declarator_list
					;

init_declarator_list: init_declarator
					| init_declarator_list ',' init_declarator
					;

init_declarator: IDENTIFIER
			   | IDENTIFIER '=' expression
			   ;

parameter_type_list: parameter_list
				   | parameter_list ',' ELIPSIS
				   ;

parameter_list: parameter_declaration
			  | parameter_list ',' parameter_declaration
			  ;

parameter_declaration: type IDENTIFIER
					 | CLASS_NAME IDENTIFIER
					 ;

// ---------- Выражения ----------

expression: IDENTIFIER
		  | literal
		  | numeric_constant
		  | '(' expression ')'
		  | SELF
		  | message_expression
		  | '-' expression %prec UMINUS
		  | '+' expression %prec UPLUS
		  | '&' expression %prec UAMPERSAND
		  | expression '+' expression
		  | expression '-' expression
		  | expression '*' expression
		  | expression '/' expression
		  | expression EQUAL expression
		  | expression NOT_EQUAL expression
		  | expression '>' expression
		  | expression '<' expression
		  | expression LESS_EQUAL expression
		  | expression GREATER_EQUAL expression
		  | expression '=' expression
		  ;

expression_e: /*empty*/
			| expression;

message_expression: '[' receiver message_selector ']'
				  ;

receiver: SUPER
		| SELF
		| CLASS_NAME
		;

message_selector: IDENTIFIER
				| keyword_argument_list
				;

keyword_argument_list: keyword_argument
					 | keyword_argument_list keyword_argument
					 ;

keyword_argument: IDENTIFIER ':' expression
				| ':' expression
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
			   | INTERFACE IDENTIFIER ':' CLASS_NAME interface_statement END
			   ;

interface_statement: instance_variables interface_declaration_list
				   | interface_declaration_list
				   ;

implementation_statement: instance_variables implementation_definition_list
						| implementation_definition_list
						;

class_implementation: IMPLEMENTATION IDENTIFIER implementation_statement END
					| IMPLEMENTATION IDENTIFIER ':' IDENTIFIER implementation_statement END
					| IMPLEMENTATION CLASS_NAME implementation_statement END
					| IMPLEMENTATION CLASS_NAME ':' IDENTIFIER implementation_statement END
					| IMPLEMENTATION IDENTIFIER ':' CLASS_NAME implementation_statement END
					| IMPLEMENTATION CLASS_NAME ':' CLASS_NAME implementation_statement END
					;

class_declaration_list: CLASS class_list ';'
					  ;

class_list: IDENTIFIER
		  | class_list ',' IDENTIFIER
		  ;

instance_variables: '{' declaration_list '}'
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
