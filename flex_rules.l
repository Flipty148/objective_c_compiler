/*Опции*/
%option noyywrap
%option never-interactive

/*Именованные шаблоны*/
DIGIT [0-9]
UNDERLINE_LETTER [A-Za-z_]

/*Стартовые состояния*/
%x MULTILINE_COMMENT
%x STRING
%x CHAR
%x NSSTRING

/*Подключение библиотек*/
%{
    #include "classes_nodes.h"
    #include "bison_rules_with_code_tab.h"
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <iostream>
    extern int yyparse(void);
    extern set<string> ClassNames;
    int isContainsSymbol(char *string, char symbol);
    void removeSymbol(char *string, char symbol);
    void removeFloatSuffix(char *string);
    int countChar(const char *str, char character);
%}

%%
%{
    char tmp[10000];
    int lineCount = 1;
    std::string str = "";
%}



"int" {printf("Found keyword INT: %s\n", yytext);   return INT;}
"char" {printf("Found keyword CHAR: %s\n", yytext);     return CHAR;}
"if" {printf("Found keyword IF: %s\n", yytext);     return IF;}
"else" {printf("Found keyword ELSE: %s\n", yytext);     return ELSE;}
"while" {printf("Found keyword WHILE: %s\n", yytext);   return WHILE;}
"do" {printf("Found keyword DO: %s\n", yytext);     return DO;}
"for" {printf("Found keyword FOR: %s\n", yytext);   return FOR;}
"in" {printf("Found keyword IN: %s\n", yytext);     return IN;}
"@interface" {printf("Found keyword INTERFACE: %s\n", yytext);      return INTERFACE;}
"@end" {printf("Found keyword END: %s\n", yytext);      return END;}
"@implementation" {printf("Found keyword IMPLEMENTATION: %s\n", yytext);    return IMPLEMENTATION;}
"@property" {printf("Found keyword PROPERTY: %s\n", yytext);    return PROPERTY;}
"@synthesize" {printf("Found keyword SYNTHESIZE: %s\n", yytext);    return SYNTHESIZE;}
"float" {printf("Found keyword FLOAT: %s\n", yytext);       return FLOAT;}
"readonly" {printf("Found keyword READONLY: %s\n", yytext);     return READONLY;}
"readwrite" {printf("Found keyword READWRITE: %s\n", yytext);   return READWRITE;}
"enum" {printf("Found keyword ENUM: %s\n", yytext);     return ENUM;}
"unsigned" {printf("Found keyword UNSIGNED: %s\n", yytext);}
"u" {printf("Found suffix U: %s\n", yytext);}
"long" {printf("Found keyword LONG: %s\n", yytext);}
"l" {printf("Found suffix L: %s\n", yytext);}
"return" {printf("Found keyword RETURN: %s\n", yytext);     return RETURN;}
"self" {printf("Found keyword SELF: %s\n", yytext);     return SELF;}
"super" {printf("Found keyword SUPER: %s\n", yytext);   return SUPER;}
"id" {printf("Found keyword ID: %s\n", yytext);     return ID;}
"@class" {printf("Found keyword CLASS: %s\n", yytext);  return CLASS;}
"void" {printf("Found keyword VOID: %s\n", yytext);     return VOID;}



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

"." {printf("Found member access operator '.' %s\n", yytext);}
"->" {printf("Found member access operator '->' %s\n", yytext);}


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
(0x|0X)[0-9a-zA-Z]+ {
    printf("ERROR! Incorrect hex number: %s in row: %d\n", yytext, lineCount);
}
0[0-7]+ {
    char *a;
    long number = strtol(yytext+2, &a,8);
    printf("Found octal number: %d\n", number);
    }
0[0-9]+ {
    printf("ERROR! Incorrect octal number: %s in row: %d\n", yytext, lineCount);
}

\' {str = ""; BEGIN(CHAR);}
\" {str = ""; BEGIN(STRING);}
@\" {str = ""; BEGIN(NSSTRING);}
<STRING,NSSTRING>[^\\\n\"]+ {str += yytext;}
<CHAR>[^\\\n\'] {str += yytext;}
<STRING,CHAR,NSSTRING>\\b {str += "\b";}
<STRING,CHAR,NSSTRING>\\f {str += "\f";}
<STRING,CHAR,NSSTRING>\\n {str += "\n";}
<STRING,CHAR,NSSTRING>\\r {str += "\r";}
<STRING,CHAR,NSSTRING>\\t {str += "\t";}
<STRING,CHAR,NSSTRING>\\v {str += "\v";}
<STRING,CHAR,NSSTRING>\\\' {str += "\'";}
<STRING,CHAR,NSSTRING>\\\" {str += "\"";}
<STRING,CHAR,NSSTRING>\\\\ {str += "\\";}
<STRING,CHAR,NSSTRING>\\0 {str += '\0';}
<STRING,CHAR,NSSTRING>\\x0 {str += '\0';}
<STRING,CHAR,NSSTRING>\\x00 {str += '\0';}
<STRING,CHAR,NSSTRING>\\x[0-9a-fA-F]{1,2} {
    char *a;
    char c =strtol(yytext+2, &a, 16);
    str += c;}
<STRING,CHAR,NSSTRING>\\x[^0-9a-fA-F]? {printf("ERROR! Incorrect hex digit in string.\n");}
<STRING,CHAR,NSSTRING>\\[0-7]{1,3} {
    char *a;
    char c =strtol(yytext+1, &a, 8);
    str += c;}
<STRING,CHAR,NSSTRING>\n {printf("ERROR! Multiline string\n", lineCount); lineCount++;}
<STRING,CHAR,NSSTRING><<EOF>> {printf("ERROR! haven't found closing quotes.\n"); BEGIN(INITIAL);}
<STRING,NSSTRING>\" {std::cout << "Found String literal: " << str.c_str() << std::endl;BEGIN(INITIAL);}
<CHAR>\' {
    if(str.size() != 1)
    {
        printf("ERROR! char length != 1 in row: %d. Char length: %d\n", lineCount, str.size());BEGIN(INITIAL);
    }
    else
    {
        std::cout << "Found char: " + str << std::endl;BEGIN(INITIAL);
    }
}



({DIGIT}+\.{DIGIT}*|\.{DIGIT}+)(f|F)? {
    strcpy(tmp, yytext);
    removeFloatSuffix(tmp);
    printf("Found float constant: %f\n", (float)atof(tmp));
}

({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)(e|E)[+-]?{DIGIT}+[fF]? {
    strcpy(tmp, yytext);
    removeFloatSuffix(tmp);
    printf("Found float constant: %f\n", (float)atof(tmp));
}

{UNDERLINE_LETTER}({UNDERLINE_LETTER}|{DIGIT})* {printf("Found identifier: %s\n", yytext);}
{DIGIT}({UNDERLINE_LETTER}|{DIGIT})* {printf("ERROR! Incorrect identifier: %s\n", yytext);}


"//"([^\n]|\\\n)* {printf("Found line comment: %s\n", yytext);
    strcpy(tmp, yytext);
    lineCount += countChar(tmp, '\n');
}


"/*" {tmp[0] = '\0'; BEGIN(MULTILINE_COMMENT);}
<MULTILINE_COMMENT>[^*\n]+ {strcat(tmp, yytext);}
<MULTILINE_COMMENT>[^*\n]+\n {lineCount++; strcat(tmp, yytext);}
<MULTILINE_COMMENT>"*"+[^*/\n] {strcat(tmp, yytext);}
<MULTILINE_COMMENT>"*"+\n {lineCount++; strcat(tmp, yytext);}
<MULTILINE_COMMENT>"*"+"/" {printf("Found multiline comment: %s\n", tmp);BEGIN(INITIAL);}

<MULTILINE_COMMENT><<EOF>> {printf("ERROR! Multiline comment \"%s\" isn't closed in row: %d\n", tmp, lineCount); BEGIN(INITIAL);}

" "+ {printf("", yytext);}

<*>\\\n {lineCount++;}
<*>\n {lineCount++;}

<*>. {printf("unrecognized element: %s\n", yytext);}

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

//Количество вхождения символа в строку
int countChar(const char *str, char character)
{
    int count = 0;
    int len = strlen(str);
    for (int i=0; i<len; i++)
    {
        if (str[i] == character)
            count++;
    }
    return count;
}

int main(int argc, char* argv[])
{
    if ( argc > 1 )
            yyin = fopen( argv[1], "r" );
    else
            yyin = stdin;

    yyparse();
}
