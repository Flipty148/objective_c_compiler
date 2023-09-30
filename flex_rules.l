/*Опции*/
%option noyywrap
%option never-interactive

/*Именованные шаблоны*/
DIGIT [0-9]
UNDERLINE_LITERAL [A-Za-z_]

/*Стартовые состояния*/
%x LINE_COMMENT
%x MULTILINE_COMMENT
%x STRING
%x CHAR

/*Подключение библиотек*/
%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    int isContainsSymbol(char *string, char symbol);
    void removeSymbol(char *string, char symbol);
    void removeFloatSuffix(char *string);
%}

%%
%{
    char tmp[10000];
    int rowCount = 1;
%}



"int" {printf("Found keyword INT: %s\n", yytext);}
"NSInteger" {printf("Found keyword NSINTEGER: %s\n", yytext);}
"char" {printf("Found keyword CHAR: %s\n", yytext);}
"NSString" {printf("Found keyword NSSTRING: %s\n", yytext);}
"NSArray" {printf("Found keyword NSARRAY: %s\n", yytext);}
"NSSet" {printf("Found keyword NSSET: %s\n", yytext);}
"NSDictionary" {printf("Found keyword NSDICTIONARY: %s\n", yytext);}
"if" {printf("Found keyword IF: %s\n", yytext);}
"else" {printf("Found keyword ELSE: %s\n", yytext);}
"while" {printf("Found keyword WHILE: %s\n", yytext);}
"do" {printf("Found keyword DO: %s\n", yytext);}
"for" {printf("Found keyword FOR: %s\n", yytext);}
"in" {printf("Found keyword IN: %s\n", yytext);}
"@interface" {printf("Found keyword INTERFACE: %s\n", yytext);}
"@end" {printf("Found keyword END: %s\n", yytext);}
"@implementation" {printf("Found keyword IMPLEMENTATION: %s\n", yytext);}
"@property" {printf("Found keyword PROPERTY: %s\n", yytext);}
"float" {printf("Found keyword FLOAT: %s\n", yytext);}
"readonly" {printf("Found keyword READONLY: %s\n", yytext);}
"readwrite" {printf("Found keyword READWRITE: %s\n", yytext);}
"enum" {printf("Found keyword ENUM: %s\n", yytext);}
"NSLog" {printf("Found keyword NSLOG: %s\n", yytext);}
"unsigned" {printf("Found keyword UNSIGNED: %s\n", yytext);}
"u" {printf("Found suffix U: %s\n", yytext);}
"long" {printf("Found keyword LONG: %s\n", yytext);}
"l" {printf("Found suffix L: %s\n", yytext);}
"return" {printf("Found keyword RETURN: %s\n", yytext);}
"self" {printf("Found keyword SELF: %s\n", yytext);}


"+" {printf("Found arithmetic operation +: %s\n", yytext);}
"-" {printf("Found arithmetic operation -: %s\n", yytext);}
"*" {printf("Found arithmetic operation *: %s\n", yytext);}
"/" {printf("Found arithmetic operation /: %s\n", yytext);}


"==" {printf("Found comparison operation ==: %s\n", yytext);}
"!=" {printf("Found comparison operation !=: %s\n", yytext);}
">" {printf("Found comparison operation >: %s\n", yytext);}
"<" {printf("Found comparison operation <: %s\n", yytext);}
">=" {printf("Found comparison operation >=: %s\n", yytext);}
"<=" {printf("Found comparison operation <=: %s\n", yytext);}


"=" {printf("Found assignment operation =: %s\n", yytext);}


"(" {printf("Found bracket (: %s\n", yytext);}
")" {printf("Found bracket ): %s\n", yytext);}
"{" {printf("Found bracket {: %s\n", yytext);}
"}" {printf("Found bracket }: %s\n", yytext);}
"[" {printf("Found bracket [: %s\n", yytext);}
"]" {printf("Found bracket ]: %s\n", yytext);}


";" {printf("Found delimiter ;: %s\n", yytext);}
":" {printf("Found delimiter :: %s\n", yytext);}
"," {printf("Found delimiter ,: %s\n", yytext);}


0|[1-9]{DIGIT}* {printf("Found integer: %d\n", atoi(yytext));}
(0x|0X)[0-9a-fA-F]+ {
    char* a;
    long number = strtol(yytext+2, &a,16);
    printf("Found hexadecimal number: %d\n", number);
    }
0[0-7]+ {
    char *a;
    long number = strtol(yytext+2, &a,8);
    printf("Found octal number: %d\n", number);
    }
0[0-9]+ {
    printf("ERROR! Incorrect octal number: %s in row: %d\n", yytext, rowCount);
}

\' strcpy(tmp,""); BEGIN(CHAR);
@\" strcpy(tmp,""); BEGIN(STRING);
<STRING>[^\\\n\"]+ strcat(tmp,yytext);
<CHAR>[^\\\n\'] strcat(tmp,yytext);
<STRING,CHAR>\\b strcat(tmp,"\b");
<STRING,CHAR>\\f strcat(tmp,"\f");
<STRING,CHAR>\\n strcat(tmp,"\n");
<STRING,CHAR>\\r strcat(tmp,"\r");
<STRING,CHAR>\\t strcat(tmp,"\t");
<STRING,CHAR>\\v strcat(tmp,"\v");
<STRING,CHAR>\\\' strcat(tmp,"\'");
<STRING,CHAR>\\\" strcat(tmp,"\"");
<STRING,CHAR>\\\\ strcat(tmp,"\\");
<STRING,CHAR>\\\? strcat(tmp,"\?");
<STRING,CHAR>\\x[0-9a-fA-F]{1,2} {
    char dig[2];
    char *a;
    dig[0]=strtol(yytext+2, &a, 16);
    dig[1]='\0';
    strcat(tmp, dig);}
<STRING,CHAR>\\[0-7]{1,3} {
    char dig[2];
    char *a;
    dig[0]=strtol(yytext+1, &a, 8);
    dig[1]='\0';
strcat(tmp, dig);}
<STRING,CHAR><<EOF>> {printf("ERROR! haven't found closing quotes in row: %d\n", rowCount); BEGIN(INITIAL);}
<STRING>\" {printf("Found String literal: %s\n",tmp);BEGIN(INITIAL);}
<CHAR>\' {
    if(strlen(tmp) != 1)
    {
        printf("ERROR! char length != 1 in row: %d\n", rowCount);BEGIN(INITIAL);
    }
    else
    {
        printf("Found Char literal: %s\n",tmp);BEGIN(INITIAL);
    }
}



({DIGIT}+\.{DIGIT}*|\.{DIGIT}+)(f|F)? {
    strcpy(tmp, yytext);
    removeFloatSuffix(tmp);
    printf("Found float constant: %f\n", (float)atof(tmp));
}

({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)(e|E)-?{DIGIT}+[fF]? {
    strcpy(tmp, yytext);
    removeFloatSuffix(tmp);
    printf("Found float constant: %f\n", (float)atof(tmp));
}

{UNDERLINE_LITERAL}({UNDERLINE_LITERAL}|{DIGIT})* {printf("Found identifier: %s\n", yytext);}
{DIGIT}({UNDERLINE_LITERAL}|{DIGIT})+ {printf("ERROR! Incorrect identifier name: %s in row: %d\n", yytext, rowCount);}


"//" {tmp[0] = '\0'; BEGIN(LINE_COMMENT);}
<LINE_COMMENT>[^\n\\]+ {strcat(tmp, yytext);}
<LINE_COMMENT>\\\n { rowCount++; }
<LINE_COMMENT>\n {printf("Found line comment: %s\n", tmp); BEGIN(INITIAL); rowCount++; }

"/*" {tmp[0] = '\0'; BEGIN(MULTILINE_COMMENT);}
<MULTILINE_COMMENT>[^*]+ {strcat(tmp, yytext);}
<MULTILINE_COMMENT>[^*]+\n {rowCount++; strcat(tmp, yytext);}
<MULTILINE_COMMENT>"*"+[^*/] {strcat(tmp, yytext);}
<MULTILINE_COMMENT>"*"+\n {rowCount++; strcat(tmp, yytext);}
<MULTILINE_COMMENT>"*"+"/" {printf("Found multiline comment: %s\n", tmp);BEGIN(INITIAL);}

<MULTILINE_COMMENT><<EOF>> {printf("ERROR! Multiline comment \"%s\" isn't closed in row: %d\n", tmp, rowCount); BEGIN(INITIAL);}

<*>\n {rowCount++;}

" " {printf("", yytext);}

<*>.|\\n {printf("unrecognized element: %s\n", yytext);}

%%

//Проверка на содержание символа в строке
int isContainsSymbol(char *string, char symbol)
{
    return strchr(string, symbol) != NULL;
}

//Удаление первого вхождения символа в строку
void removeSymbol(char *string, char symbol)
{
    if (isContainsSymbol(string, symbol))
    {
        char* pointer = strchr(string, symbol);
        int symbolPos = pointer - string;
        int len = strlen(string);
        for (int i=symbolPos; i < len; i++)
        {
            string[i] = string[i+1];
        }
        string[len-1] = '\0';
    }
}

//Удаление суффикса float
void removeFloatSuffix(char *string)
{
    if (isContainsSymbol(string, 'f') || isContainsSymbol(string, 'F'))
    {
        removeSymbol(string, 'f');
        removeSymbol(string, 'F');
    }
}

int main(int argc, char* argv[])
{
    if ( argc > 1 )
            yyin = fopen( argv[1], "r" );
    else
            yyin = stdin;

    yylex();
}
