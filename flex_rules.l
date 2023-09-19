/*Опции*/
%option noyywrap
%option never-interactive

/*Именованные шаблоны*/
DIGIT [0-9]
NONDIGIT [A-Za-z_]

/*Стартовые состояния*/
%x LINE_COMMENT
%x MULTILINE_COMMENT

/*Подключение библиотек*/
%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
%}

%%
%{
    int isContainsSymbol(char *string, char symbol);
    void removeSymbol(char *string, char symbol);
    void removeFloatSuffix(char *string);
    char tmp[10000];
%}



"int" {printf("Found keyword: %s\n", yytext);}
"NSInteger" {printf("Found keyword: %s\n", yytext);}
"char" {printf("Found keyword: %s\n", yytext);}
"NSString" {printf("Found keyword: %s\n", yytext);}
"if" {printf("Found keyword: %s\n", yytext);}
"else" {printf("Found keyword: %s\n", yytext);}
"while" {printf("Found keyword: %s\n", yytext);}
"do" {printf("Found keyword: %s\n", yytext);}
"for" {printf("Found keyword: %s\n", yytext);}
"in" {printf("Found keyword: %s\n", yytext);}
"@interface" {printf("Found keyword: %s\n", yytext);}
"@end" {printf("Found keyword: %s\n", yytext);}
"@implementation" {printf("Found keyword: %s\n", yytext);}
"@property" {printf("Found keyword: %s\n", yytext);}
"float" {printf("Found keyword: %s\n", yytext);}
"readonly" {printf("Found keyword: %s\n", yytext);}
"readwrite" {printf("Found keyword: %s\n", yytext);}


"+" {printf("Found arithmetic operation: %s\n", yytext);}
"-" {printf("Found arithmetic operation: %s\n", yytext);}
"*" {printf("Found arithmetic operation: %s\n", yytext);}
"/" {printf("Found arithmetic operation: %s\n", yytext);}


"==" {printf("Found comparison operation: %s\n", yytext);}
"!=" {printf("Found comparison operation: %s\n", yytext);}
">" {printf("Found comparison operation: %s\n", yytext);}
"<" {printf("Found comparison operation: %s\n", yytext);}
">=" {printf("Found comparison operation: %s\n", yytext);}
"<=" {printf("Found comparison operation: %s\n", yytext);}


"=" {printf("Found assignment operation: %s\n", yytext);}
"+=" {printf("Found assignment operation: %s\n", yytext);}
"-=" {printf("Found assignment operation: %s\n", yytext);}
"*=" {printf("Found assignment operation: %s\n", yytext);}
"/=" {printf("Found assignment operation: %s\n", yytext);}


"(" {printf("Found bracket: %s\n", yytext);}
")" {printf("Found bracket: %s\n", yytext);}
"{" {printf("Found bracket: %s\n", yytext);}
"}" {printf("Found bracket: %s\n", yytext);}


";" {printf("Found delimiter: %s\n", yytext);}
":" {printf("Found delimiter: %s\n", yytext);}
"," {printf("Found delimiter: %s\n", yytext);}


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

{NONDIGIT}({NONDIGIT}|{DIGIT})* {printf("Found identifier: %s\n", yytext);}
{DIGIT}({NONDIGIT}|{DIGIT})+ {printf("ERROR! Incorrect identifier name: %s\n", yytext);}




"//" {tmp[0] = '\0'; BEGIN(LINE_COMMENT);}
<LINE_COMMENT>[^\n*]+ {strcat(tmp, yytext);}
<LINE_COMMENT>\\*\n[^\n]* {strcat(tmp, yytext);}
<LINE_COMMENT>[^\\]\n {printf("Found comment: %s\n", tmp); BEGIN(INITIAL);}

"/*" {tmp[0] = '\0'; BEGIN(MULTILINE_COMMENT);}
<MULTILINE_COMMENT>[^*]+ {strcat(tmp, yytext);}
<MULTILINE_COMMENT>"*"+[^*/] {strcat(tmp, yytext);}
<MULTILINE_COMMENT>"*"+"/" {printf("Found comment: %s\n", tmp);BEGIN(INITIAL);}

<MULTILINE_COMMENT><<EOF>> {BEGIN(INITIAL); printf("ERROR! Multiline comment \"%s\" isn't close\n", tmp);}


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
