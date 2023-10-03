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

%%
