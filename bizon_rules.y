// ---------- Операции с их приоритетом ----------
%right '='
%left EQUAL NOT_EQUAL
%left '<' '>' LESS_EQUAL GREATER_EQUAL
%left '+' '-'
%left '*' '/'
%right UMINUS UPLUS UASTERISK UAMPERSAND
%nonassoc '(' ')' '[' ']'

//---------- Терминальные символы ----------
%token INT NSINTEGER CHAR NSSTRING FLOAT NSARRAY NSSET NSDICTIONARY ENUM NSLOG
%token IF ELSE WHILE DO FOR
%token IN
%token INTERFACE IMPLEMENTATION 
%token END
%token PROPERTY
%token READONLY READWRITE
%token SELF SUPER ID
%token CLASS
%token RETURN
%token INTEGER_CONSTANT STRING_CONSTANT CHAR_CONSTANT FLOAT_CONSTANT
%token IDENTIFIER
%token ELIPSIS

%start program

%%

program: statement_list
	   ;

// ---------- Типы ----------
type: INT
    | NSINTEGER
    | CHAR
    | NSSTRING
    | FLOAT
    | ID
    ;

// ----------  Идентификаторы ----------
identifier: IDENTIFIER
          ;

pointer: '*' identifier %prec UASTERISK
       | '*' pointer %prec UASTERISK
       ;

// ---------- Константы ----------
numeric_constant: FLOAT_CONSTANT
                | INTEGER_CONSTANT
                ;

literal: STRING_CONSTANT
       | CHAR_CONSTANT
       ;

// ---------- Объявления ----------
declaration: declaration_specifiers init_declarator_list ';'
           ;

declaration_list: declaration
				| declaration_list declaration
				| class_declaration_list
				;

declaration_specifiers: type
					  | method_type
					  ;

init_declarator_list:
					| init_declarator_listE
					;

init_declarator_listE: init_declarator
					| init_declarator_listE ',' init_declarator
					;

init_declarator: declarator
			   | declarator '=' initializer
			   ;

declarator: direct_declarator
		  ;

direct_declarator: identifier
				 | '(' declarator ')'
				 | '*' direct_declarator %prec UASTERISK
				 ;

initializer: assignment_expression
		   ;

parameter_type_list: parameter_list
				   | parameter_list ',' ELIPSIS
				   ;

parameter_list: parameter_declaration
			  | parameter_list ',' parameter_declaration
			  ;

parameter_declaration: declaration_specifiers declarator
					 ;

// ---------- Выражения ----------
arithmetic_expression: numeric_constant
					 | arithmetic_expression '+' arithmetic_expression
					 | arithmetic_expression '-' arithmetic_expression
					 | arithmetic_expression '*' arithmetic_expression
					 | arithmetic_expression '/' arithmetic_expression
					 ;

comparation_expression: arithmetic_expression
					  | comparation_expression EQUAL comparation_expression
					  | comparation_expression NOT_EQUAL comparation_expression
					  | comparation_expression '>' comparation_expression
					  | comparation_expression '<' comparation_expression
					  | comparation_expression LESS_EQUAL comparation_expression
					  | comparation_expression GREATER_EQUAL comparation_expression
					  ;

primary_expression: identifier
				  | pointer
				  | literal
				  | '(' expression ')'
				  | SELF
				  | message_expression
				  ;

expression: comparation_expression
		  | assignment_expression
		  ;

assignment_expression: unary_expression
					 | unary_expression '=' assignment_expression
					 ;

unary_expression: primary_expression
				| '-' identifier %prec UMINUS
				| '+' identifier %prec UPLUS
				| '&' identifier %prec UAMPERSAND
				| '-' numeric_constant %prec UMINUS
				| '+' numeric_constant %prec UPLUS
				;

message_expression: '[' receiver message_selector ']'
				  ;

receiver: SUPER
		| SELF
		| identifier
		;

message_selector: identifier
				| keyword_argument_list
				;

keyword_argument_list: keyword_argument
					 | keyword_argument_list keyword_argument
					 ;

keyword_argument: identifier ':' expression
				| ':' expression
				;

// ---------- Управляющие структуры: развилки ----------
if_statement: IF '(' expression ')' statement
			| IF '(' expression ')' ELSE statement
			;

// ---------- Управляющие структуры: циклы ----------
while_statement: WHILE '(' expression ')' statement
			   ;

do_while_statement: DO statement WHILE '(' expression ')' ';'
				  ;

for_statement: FOR '(' expression ';' expression ';' expression ')' statement
			 | FOR '(' ';' ';' ')' statement
			 | FOR '(' ';' ';' expression ')' statement
			 | FOR '(' ';' expression ';' ')' statement
			 | FOR '(' expression ';' ';' ')' statement
			 | FOR '(' ';' expression ';' expression ')' statement
			 | FOR '(' expression ';' ';' expression ')' statement
			 | FOR '(' expression ';' expression ';' ')' statement
			 | FOR '(' identifier IN expression ')' statement
			 | FOR '(' type identifier IN expression ')' statement
			 ;

// ---------- Операторы ----------
cycle_statement: while_statement
			   | do_while_statement
			   | for_statement
			   ;

statement: expression ';'
		 | cycle_statement
		 | if_statement
		 | compound_statement
		 | class_statement
		 ;

compound_statement: '{' statement '}'
				  ;

statement_list: statement
			  | statement_list statement
			  ;

class_statement: class_interface
			   | class_implementation
			   ;

// ---------- Классы ----------
class_interface: INTERFACE class_name ':' superclass_name interface_statement END
			   | INTERFACE class_name interface_statement END
			   ;

interface_statement: instance_variables interface_declaration_list
				   | interface_declaration_list
				   ;

implementation_statement: instance_variables implementation_definition_list
						| implementation_definition_list
						;

class_implementation: IMPLEMENTATION class_name implementation_statement END
					| IMPLEMENTATION class_name ':' superclass_name implementation_statement END
					;

class_declaration_list: CLASS class_list
					  ;

class_list: class_name
		  | class_list ',' class_name
		  ;

class_name: identifier
		  ;

superclass_name: identifier
			   ;

instance_variables: '{' struct_declaration_list '}'
				   | '{' struct_declaration_list instance_variables '}'
				   ;

struct_declaration_list: struct_declaration
					   | struct_declaration_list struct_declaration
					   ;

struct_declaration: type struct_declarator_list
				  ;

struct_declarator_list: struct_declarator
					  | struct_declarator_list struct_declarator
					  ;

struct_declarator: declarator
				 ;


interface_declaration_list: declaration
						  | property
						  | method_declaration
						  | interface_declaration_list declaration
						  | interface_declaration_list method_declaration
						  ;

method_declaration: class_method_declaration
				  | instance_method_declaration
				  ;

class_method_declaration: '+' method_type method_selector
						| '+' method_selector ';'
						;

instance_method_declaration: '-' method_type method_selector
						   | '-' method_selector ';'
						   ;

implementation_definition_list: declaration
							  | property
							  | method_definition
							  | implementation_definition_list declaration
							  | implementation_definition_list method_definition
							  ;

method_definition: class_method_definition
				 | instance_method_definition
				 ;

class_method_definition: '+' method_type method_selector declaration_list compound_statement
					   | '+' method_selector compound_statement
					   | '+' method_selector declaration_list compound_statement
					   | '+' method_type method_selector compound_statement
					   ;

instance_method_definition: '-' method_type method_selector declaration_list compound_statement
					   	  | '-' method_selector compound_statement
					   	  | '-' method_selector declaration_list compound_statement
					   	  | '-' method_type method_selector compound_statement
					   	  ;

method_selector: identifier
			   | keyword_selector ',' parameter_type_list
			   | keyword_selector
			   ;

keyword_selector: keyword_declaration
				| keyword_selector keyword_declaration
				;

keyword_declaration: ':' method_type identifier
				   | ':' identifier
				   | identifier ':' method_type identifier
				   | identifier ':' identifier
				   ;

method_type: '(' type ')'
		   ;

property: PROPERTY '(' attribute ')' type identifier ';'
		;

attribute: READONLY
		 | READWRITE
		 ;

%%
