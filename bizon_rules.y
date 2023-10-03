//Операции с их приоритетом
%right '='
%left EQUAL NOT_EQUAL
%left '<' '>' LESS_EQUAL GREATER_EQUAL
%left '+' '-'
%left '*' '/'
%left UMINUS UPLUS UASTERISK UAMPERSAND
%nonassoc '(' ')' '[' ']'
