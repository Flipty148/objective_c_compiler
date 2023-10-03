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

%%

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
constant: numeric_constant
        | literal
        ;

numeric_constant: FLOAT_CONSTANT
                | INTEGER_CONSTANT
                ;

literal: STRING_CONSTANT
       | CHAR_CONSTANT
       ;

// ---------- Объявления ----------
declaration: declaration_specifiers init_declarator_list
           | declaration_specifiers
           ;

declaration_specifiers: type
					  | type declaration_specifiers
					  ;

init_declarator_list: init_declarator
					| init_declarator_list ',' init_declarator
					;

init_declarator: declarator
			   | declarator '=' initializer
			   ;

declarator: direct_declarator
		  | '*' direct_declarator %prec UASTERISK
		  ;

direct_declarator: identifier
				 | '(' declarator ')'
				 ;

initializer: assignment_expression
		   ;

// ---------- Выражения ----------
arithmetic_expression: numeric_constant
					 | arithmetic_expression '+' arithmetic_expression
					 | arithmetic_expression '-' arithmetic_expression
					 | arithmetic_expression '*' arithmetic_expression
					 | arithmetic_expression '/' arithmetic_expression
					 | '(' arithmetic_expression ')'
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
				  | constant
				  | '(' expression ')'
				  | SELF
				  | message_expression
				  ;

expression: arithmetic_expression
		  | comparation_expression
		  | assignment_expression
		  ;

assignment_expression: unary_expression
					 | unary_expression '=' assignment_expression
					 ;

unary_expression: primary_expression
				| '*' identifier
				| '-' identifier
				| '+' identifier
				| '&' identifier
				| '-' numeric_constant
				| '+' numeric_constant
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
		 ;

compound_statement: '{' statement '}'
				  ;

statement_list: statement
			  | statement_list statement
			  ;

%%
