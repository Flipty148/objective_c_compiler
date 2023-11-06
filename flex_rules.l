/*Опции*/
%option noyywrap
%option never-interactive

/*Именованные шаблоны*/
DIGIT [0-9]
UNDERLINE_LETTER [A-Za-z_]

/*Стартовые состояния*/
%x MULTILINE_COMMENT
%x STRING_SC
%x CHAR_SC
%x NSSTRING_SC

/*Подключение библиотек*/
%{
    #include "classes_nodes.h"
    #include "bison_rules_with_code_tab.h"
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <iostream>
    #include <fstream>
    extern int yyparse(void);
    extern Program_node *root;
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



"+" {printf("Found arithmetic operation +: %s\n", yytext);  return (unsigned char)'+';}
"-" {printf("Found arithmetic operation -: %s\n", yytext);  return (unsigned char)'-';}
"*" {printf("Found arithmetic operation *: %s\n", yytext);  return (unsigned char)'*';}
"/" {printf("Found arithmetic operation /: %s\n", yytext);  return (unsigned char)'/';}


"==" {printf("Found comparison operation ==: %s\n", yytext);    return EQUAL;}
"!=" {printf("Found comparison operation !=: %s\n", yytext);    return NOT_EQUAL;}
">" {printf("Found comparison operation >: %s\n", yytext);      return (unsigned char)'>';}
"<" {printf("Found comparison operation <: %s\n", yytext);      return (unsigned char)'<';}
">=" {printf("Found comparison operation >=: %s\n", yytext);    return GREATER_EQUAL;}
"<=" {printf("Found comparison operation <=: %s\n", yytext);    return LESS_EQUAL;}


"=" {printf("Found assignment operation =: %s\n", yytext);      return (unsigned char)'=';}

"." {printf("Found member access operator '.' %s\n", yytext);   return (unsigned char)'.';}
"->" {printf("Found member access operator '->' %s\n", yytext);     return ARROW;}


"(" {printf("Found bracket (: %s\n", yytext);   return (unsigned char)'(';}
")" {printf("Found bracket ): %s\n", yytext);   return (unsigned char)')';}
"{" {printf("Found bracket {: %s\n", yytext);   return (unsigned char)'{';}
"}" {printf("Found bracket }: %s\n", yytext);   return (unsigned char)'}';}
"[" {printf("Found bracket [: %s\n", yytext);   return (unsigned char)'[';}
"]" {printf("Found bracket ]: %s\n", yytext);   return (unsigned char)']';}


";" {printf("Found delimiter ;: %s\n", yytext);     return (unsigned char)';';}
":" {printf("Found delimiter :: %s\n", yytext);     return (unsigned char)':';}
"," {printf("Found delimiter ,: %s\n", yytext);     return (unsigned char)',';}

0|[1-9]{DIGIT}* {printf("Found integer: %d\n", atoi(yytext));   yylval.Integer_constant=atoi(yytext); return INTEGER_CONSTANT;}
(0x|0X)[0-9a-fA-F]+ {
    char* a;
    long number = strtol(yytext+2, &a,16);
    printf("Found hexadecimal number: %d\n", number);
    yylval.Integer_constant=number;
    return INTEGER_CONSTANT;
    }
(0x|0X)[0-9a-zA-Z]+ {
    printf("ERROR! Incorrect hex number: %s in row: %d\n", yytext, lineCount);
}
0[0-7]+ {
    char *a;
    long number = strtol(yytext+2, &a,8);
    printf("Found octal number: %d\n", number);
    yylval.Integer_constant=number;
    return INTEGER_CONSTANT;
    }
0[0-9]+ {
    printf("ERROR! Incorrect octal number: %s in row: %d\n", yytext, lineCount);
}

\' {str = ""; BEGIN(CHAR_SC);}
\" {str = ""; BEGIN(STRING_SC);}
@\" {str = ""; BEGIN(NSSTRING_SC);}
<STRING_SC,NSSTRING_SC>[^\\\n\"]+ {str += yytext;}
<CHAR_SC>[^\\\n\'] {str += yytext;}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\b {str += "\b";}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\f {str += "\f";}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\n {str += "\n";}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\r {str += "\r";}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\t {str += "\t";}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\v {str += "\v";}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\\' {str += "\'";}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\\" {str += "\"";}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\\\ {str += "\\";}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\0 {str += '\0';}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\x0 {str += '\0';}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\x00 {str += '\0';}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\x[0-9a-fA-F]{1,2} {
    char *a;
    char c =strtol(yytext+2, &a, 16);
    str += c;}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\x[^0-9a-fA-F]? {printf("ERROR! Incorrect hex digit in string.\n");}
<STRING_SC,CHAR_SC,NSSTRING_SC>\\[0-7]{1,3} {
    char *a;
    char c =strtol(yytext+1, &a, 8);
    str += c;}
<STRING_SC,CHAR_SC,NSSTRING_SC>\n {printf("ERROR! Multiline string\n"); lineCount++;}
<STRING_SC,CHAR_SC,NSSTRING_SC><<EOF>> {printf("ERROR! haven't found closing quotes.\n"); BEGIN(INITIAL);}
<STRING_SC,NSSTRING_SC>\" {std::cout << "Found String literal: " << str.c_str() << std::endl;

      if (YY_START == STRING_SC)
      {
        yylval.String_constant = new char[str.length()];
        strcpy(yylval.String_constant, str.c_str()); 
        BEGIN(INITIAL);
        return STRING_CONSTANT;
      }
      else
      {
        yylval.NSString_constant = new char[str.length()];
        strcpy(yylval.NSString_constant, str.c_str()); 
        BEGIN(INITIAL);
        return NSSTRING_CONSTANT;
      }

}
<CHAR_SC>\' {
    if(str.size() != 1)
    {
        printf("ERROR! char length != 1 in row: %d. Char length: %d\n", lineCount, str.size());BEGIN(INITIAL);
    }
    else
    {
        std::cout << "Found char: " + str << std::endl;BEGIN(INITIAL);
        yylval.Char_constant = new char[str.length()];
        strcpy(yylval.Char_constant, str.c_str());
        BEGIN(INITIAL);
        return CHAR_CONSTANT;
    }
    
}



({DIGIT}+\.{DIGIT}*|\.{DIGIT}+)(f|F)? {
    strcpy(tmp, yytext);
    removeFloatSuffix(tmp);
    printf("Found float constant: %f\n", (float)atof(tmp));
    yylval.Float_constant = (float)atof(tmp);
    return FLOAT_CONSTANT;
}

({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)(e|E)[+-]?{DIGIT}+[fF]? {
    strcpy(tmp, yytext);
    removeFloatSuffix(tmp);
    printf("Found float constant: %f\n", (float)atof(tmp));
    yylval.Float_constant = (float)atof(tmp);
    return FLOAT_CONSTANT;
}

{UNDERLINE_LETTER}({UNDERLINE_LETTER}|{DIGIT})* {printf("Found identifier: %s\n", yytext);
    str = "";
    str += yytext;
    yylval.Identifier = new char[str.length()];
    strcpy(yylval.Identifier, str.c_str());
    if (ClassNames.count(str))
        return CLASS_NAME;
    else
        return IDENTIFIER;
}
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

" "+ {printf("");}

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

    string res = root->toDot();
    ofstream out("dot.dot");
    out << res;
    out.close();
}
