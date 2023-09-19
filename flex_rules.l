/*Опции*/
%option noyywrap
%option never-interactive

/*Именованные шаблоны*/
DIGIT [0-9]

/*Подключение библиотек*/
%{
    #include <stdio.h>
%}

%%

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
