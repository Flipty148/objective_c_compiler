/*Опции*/
%option noyywrap
%option never-interactive

/*Именованные шаблоны*/
DIGIT [0-9]
NONDIGIT [A-Za-z_]

/*Подключение библиотек*/
%{
    #include <stdio.h>
    #include <string.h>
%}

%%
%{
    char tmp[10000];
%}

/*Ключевые слова*/

"int" {printf("Found keyword: %s", yytext);}
"NSInteger" {printf("Found keyword: %s", yytext);}
"char" {printf("Found keyword: %s", yytext);}
"NSString" {printf("Found keyword: %s", yytext);}
"if" {printf("Found keyword: %s", yytext);}
"else" {printf("Found keyword: %s", yytext);}
"while" {printf("Found keyword: %s", yytext);}
"do" {printf("Found keyword: %s", yytext);}
"for" {printf("Found keyword: %s", yytext);}
"in" {printf("Found keyword: %s", yytext);}
"@interface" {printf("Found keyword: %s", yytext);}
"@end" {printf("Found keyword: %s", yytext);}
"@implementation" {printf("Found keyword: %s", yytext);}
"@property" {printf("Found keyword: %s", yytext);}
"float" {printf("Found keyword: %s", yytext);}
"readonly" {printf("Found keyword: %s", yytext);}
"readwrite" {printf("Found keyword: %s", yytext);}

/*Арифметические опрерации*/
"+" {printf("Found arithmetic operation: %s", yytext);}
"-" {printf("Found arithmetic operation: %s", yytext);}
"*" {printf("Found arithmetic operation: %s", yytext);}
"/" {printf("Found arithmetic operation: %s", yytext);}

/*Операции сравнения*/
"==" {printf("Found comparison operation: %s", yytext);}
"!=" {printf("Found comparison operation: %s", yytext);}
">" {printf("Found comparison operation: %s", yytext);}
"<" {printf("Found comparison operation: %s", yytext);}
">=" {printf("Found comparison operation: %s", yytext);}
"<=" {printf("Found comparison operation: %s", yytext);}

/*Операции присваивания*/
"=" {printf("Found assignment operation: %s", yytext);}
"+=" {printf("Found assignment operation: %s", yytext);}
"-=" {printf("Found assignment operation: %s", yytext);}
"*=" {printf("Found assignment operation: %s", yytext);}
"/=" {printf("Found assignment operation: %s", yytext);}

/*Скобки*/
"(" {printf("Found bracket: %s", yytext);}
")" {printf("Found bracket: %s", yytext);}
"{" {printf("Found bracket: %s", yytext);}
"}" {printf("Found bracket: %s", yytext);}

/*Разделители*/
";" {printf("Found delimiter: %s", yytext);}
":" {printf("Found delimiter: %s", yytext);}
"," {printf("Found delimiter: %s", yytext);}

/*Идентификатор*/
{NONDIGIT}({NONDIGIT}|{DIGIT})* {printf("Found identifier: %s", yytext);}

/*Константы*/
({DIGIT}+\.{DIGIT}*|\.{DIGIT}+)(f|F)? {
    strcpy(tmp, yytext);
    removeFloatSuffix(tmp)
    printf("Found float constant: %s", tmp);
}

({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)(e|E)-?{DIGIT}+[fF]? {
    strcpy(tmp, yytext);
    removeFloatSuffix(tmp)
    printf("Found float constant: %s", tmp);
}

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
        for (i=symbolPos; i < len; i++)
        {
            string[i] = string[i+1];
        }
        string[len-2] = '\0';
    }
}

//Удаление суффикса float
void removeFloatSuffix(char *string)
{
    if (isContainsSymbol(string, 'f') || isContainsSymbol(tmp, 'F'))
    {
        removeSymbol(tmp, 'f');
        removeSymbol(tmp, 'F');
    }
}