
/*  A Bison parser, made from bison_rules_with_code.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	EQUAL	258
#define	NOT_EQUAL	259
#define	LESS_EQUAL	260
#define	GREATER_EQUAL	261
#define	UMINUS	262
#define	UPLUS	263
#define	UAMPERSAND	264
#define	INT	265
#define	CHAR	266
#define	FLOAT	267
#define	VOID	268
#define	ENUM	269
#define	IF	270
#define	ELSE	271
#define	WHILE	272
#define	DO	273
#define	FOR	274
#define	IN	275
#define	INTERFACE	276
#define	IMPLEMENTATION	277
#define	END	278
#define	PROPERTY	279
#define	READONLY	280
#define	READWRITE	281
#define	SELF	282
#define	SUPER	283
#define	ID	284
#define	CLASS	285
#define	RETURN	286
#define	INTEGER_CONSTANT	287
#define	STRING_CONSTANT	288
#define	CHAR_CONSTANT	289
#define	FLOAT_CONSTANT	290
#define	NSSTRING_CONSTANT	291
#define	IDENTIFIER	292
#define	CLASS_NAME	293
#define	ELIPSIS	294

#line 1 "bison_rules_with_code.y"

	#include "classes_nodes.h"
	#include "user_functions.h"
	Program_node *root;

#line 8 "bison_rules_with_code.y"
typedef union {
	int Integer_constant;
	char *String_constant;
	char Char_constant;
	float Float_constant;
	char *NSString_constant;
	char *Identifier;
	Type_node *Type;
	Numeric_constant_node *Numeric_constant;
	Literal_node *Literal;
	Declaration_node *Declaration;
	Declaration_list_node *Declaration_list;
	Init_declarator_list_node *Init_declarator_list;
	Init_declarator_node *Init_declarator;
	Parameter_type_list_node *Parameter_type_list;
	Parameter_list_node *Parameter_list;
	Parameter_declaration_node *Parameter_declaration;
	Expression_node *Expression;
	Message_expression_node *Message_expression;
	Receiver_node *Receiver;
	Message_selector_node *Message_selector;
	Keyword_argument_list_node *Keyword_argument_list;
	Keyword_argument_node *Keyword_argument;
	If_statement_node *If;
	While_statement_node *While;
	Do_while_statement_node *Do_while;
	For_statement_node *For;
	Statement_node *Statement;
	Compound_statement_node *Compound_statement;
	Statement_list_node *Statement_list;
	Class_statement_node *Class_statement;
	Class_statement_list_node *Class_statement_list;
	Class_interface_node *Class_interface;
	Interface_statement_node *Interface_statement;
	Implementation_statement_node *Implementation_statement;
	Class_implementation_node *Class_implementation;
	Class_declaration_list_node *Class_declaration_list;
	Instance_variables_node *Instance_variables;
	Interface_declaration_list_node *Interface_declaration_list;
	Method_declaration_node *Method_declaration;
	Implementation_definition_list_node *Implementation_definition_list;
	Method_definition_node *Method_definition;
	Method_selector_node *Method_selector;
	Keyword_selector_node *Keyword_selector;
	Keyword_declaration_node *Keyword_declaration;
	Property_node *Property;
	Attribute_node *Attribute;
	Program_node *Program;
	Class_list *Class_list;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		295
#define	YYFLAG		-32768
#define	YYNTBASE	57

#define YYTRANSLATE(x) ((unsigned)(x) <= 294 ? yytranslate[x] : 108)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    53,     2,    17,
    18,    12,    10,    52,    11,     2,    13,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    54,    51,     6,
     3,     7,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    19,     2,    20,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    55,     2,    56,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     4,     5,     8,
     9,    14,    15,    16,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,    10,    12,    14,    16,    18,    21,
    23,    25,    27,    29,    31,    35,    37,    40,    41,    43,
    44,    46,    48,    52,    54,    58,    60,    64,    66,    70,
    73,    76,    78,    80,    82,    86,    88,    90,    93,    96,
    99,   103,   107,   111,   115,   119,   123,   127,   131,   135,
   139,   143,   144,   146,   151,   153,   155,   157,   159,   161,
   163,   166,   170,   173,   179,   187,   193,   201,   211,   219,
   228,   230,   233,   237,   239,   241,   243,   245,   247,   249,
   251,   255,   257,   260,   261,   263,   265,   267,   269,   272,
   279,   284,   291,   294,   296,   299,   301,   306,   313,   318,
   325,   332,   339,   343,   345,   349,   353,   355,   357,   359,
   362,   365,   368,   370,   372,   377,   384,   388,   393,   400,
   404,   406,   408,   410,   413,   416,   419,   421,   423,   429,
   437,   442,   448,   456,   461,   463,   465,   469,   471,   474,
   478,   481,   486,   490,   494,   502,   504
};

static const short yyrhs[] = {    83,
     0,    86,     0,    83,    86,     0,    86,    83,     0,    21,
     0,    22,     0,    23,     0,    40,     0,    49,    12,     0,
    46,     0,    43,     0,    44,     0,    45,     0,    47,     0,
    58,    64,    51,     0,    61,     0,    62,    61,     0,     0,
    62,     0,     0,    65,     0,    66,     0,    65,    52,    66,
     0,    48,     0,    48,     3,    70,     0,    68,     0,    68,
    52,    50,     0,    69,     0,    68,    52,    69,     0,    58,
    48,     0,    49,    48,     0,    48,     0,    60,     0,    59,
     0,    17,    70,    18,     0,    38,     0,    72,     0,    11,
    70,     0,    10,    70,     0,    53,    70,     0,    70,    10,
    70,     0,    70,    11,    70,     0,    70,    12,    70,     0,
    70,    13,    70,     0,    70,     4,    70,     0,    70,     5,
    70,     0,    70,     7,    70,     0,    70,     6,    70,     0,
    70,     8,    70,     0,    70,     9,    70,     0,    70,     3,
    70,     0,     0,    70,     0,    19,    73,    74,    20,     0,
    39,     0,    38,     0,    49,     0,    48,     0,    75,     0,
    76,     0,    75,    76,     0,    48,    54,    70,     0,    54,
    70,     0,    26,    17,    70,    18,    81,     0,    26,    17,
    70,    18,    81,    27,    81,     0,    28,    17,    70,    18,
    81,     0,    29,    81,    28,    17,    70,    18,    51,     0,
    30,    17,    71,    51,    71,    51,    71,    18,    81,     0,
    30,    17,    48,    31,    70,    18,    81,     0,    30,    17,
    58,    48,    31,    70,    18,    81,     0,    51,     0,    70,
    51,     0,    42,    71,    51,     0,    77,     0,    78,     0,
    79,     0,    80,     0,    82,     0,    61,     0,    91,     0,
    55,    84,    56,     0,    81,     0,    83,    81,     0,     0,
    83,     0,    87,     0,    90,     0,    85,     0,    86,    85,
     0,    32,    48,    54,    48,    88,    34,     0,    32,    48,
    88,    34,     0,    32,    48,    54,    49,    88,    34,     0,
    93,    94,     0,    94,     0,    93,    98,     0,    98,     0,
    33,    48,    89,    34,     0,    33,    48,    54,    48,    89,
    34,     0,    33,    49,    89,    34,     0,    33,    49,    54,
    48,    89,    34,     0,    33,    48,    54,    49,    89,    34,
     0,    33,    49,    54,    49,    89,    34,     0,    41,    92,
    51,     0,    48,     0,    92,    52,    48,     0,    55,    62,
    56,     0,    61,     0,   106,     0,    95,     0,    94,    61,
     0,    94,    95,     0,    94,   106,     0,    96,     0,    97,
     0,    10,   105,   102,    51,     0,    10,    17,    24,    18,
   102,    51,     0,    10,   102,    51,     0,    11,   105,   102,
    51,     0,    11,    17,    24,    18,   102,    51,     0,    11,
   102,    51,     0,    61,     0,   106,     0,    99,     0,    98,
    61,     0,    98,    99,     0,    98,   106,     0,   100,     0,
   101,     0,    10,   105,   102,    63,    82,     0,    10,    17,
    24,    18,   102,    63,    82,     0,    10,   102,    63,    82,
     0,    11,   105,   102,    63,    82,     0,    11,    17,    24,
    18,   102,    63,    82,     0,    11,   102,    63,    82,     0,
    48,     0,   103,     0,   103,    52,    67,     0,   104,     0,
   103,   104,     0,    54,   105,    48,     0,    54,    48,     0,
    48,    54,   105,    48,     0,    48,    54,    48,     0,    17,
    58,    18,     0,    35,    17,   107,    18,    58,    48,    51,
     0,    36,     0,    37,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   140,   141,   142,   143,   147,   148,   149,   150,   151,   155,
   156,   159,   160,   161,   165,   168,   169,   172,   173,   176,
   177,   180,   181,   184,   185,   188,   189,   192,   193,   196,
   197,   202,   203,   204,   205,   206,   207,   208,   209,   210,
   211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   224,   225,   228,   231,   232,   233,   236,   237,   240,
   241,   244,   245,   249,   250,   254,   257,   260,   261,   262,
   267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
   279,   282,   283,   286,   287,   290,   291,   294,   295,   299,
   300,   301,   304,   305,   308,   309,   312,   313,   314,   315,
   316,   317,   320,   323,   324,   327,   330,   331,   332,   333,
   334,   335,   338,   339,   342,   343,   344,   347,   348,   349,
   352,   353,   354,   355,   356,   357,   360,   361,   364,   365,
   366,   369,   370,   371,   374,   375,   376,   379,   380,   383,
   384,   385,   386,   389,   392,   395,   396
};

static const char * const yytname[] = {   "$","error","$undefined.","'='","EQUAL",
"NOT_EQUAL","'<'","'>'","LESS_EQUAL","GREATER_EQUAL","'+'","'-'","'*'","'/'",
"UMINUS","UPLUS","UAMPERSAND","'('","')'","'['","']'","INT","CHAR","FLOAT","VOID",
"ENUM","IF","ELSE","WHILE","DO","FOR","IN","INTERFACE","IMPLEMENTATION","END",
"PROPERTY","READONLY","READWRITE","SELF","SUPER","ID","CLASS","RETURN","INTEGER_CONSTANT",
"STRING_CONSTANT","CHAR_CONSTANT","FLOAT_CONSTANT","NSSTRING_CONSTANT","IDENTIFIER",
"CLASS_NAME","ELIPSIS","';'","','","'&'","':'","'{'","'}'","program","type",
"numeric_constant","literal","declaration","declaration_list","declaration_list_e",
"init_declarator_list_e","init_declarator_list","init_declarator","parameter_type_list",
"parameter_list","parameter_declaration","expression","expression_e","message_expression",
"receiver","message_selector","keyword_argument_list","keyword_argument","if_statement",
"while_statement","do_while_statement","for_statement","statement","compound_statement",
"statement_list","statement_list_e","class_statement","class_statement_list",
"class_interface","interface_statement","implementation_statement","class_implementation",
"class_declaration_list","class_list","instance_variables","interface_declaration_list",
"method_declaration","class_method_declaration","instance_method_declaration",
"implementation_definition_list","method_definition","class_method_definition",
"instance_method_definition","method_selector","keyword_selector","keyword_declaration",
"method_type","property","attribute",""
};
#endif

static const short yyr1[] = {     0,
    57,    57,    57,    57,    58,    58,    58,    58,    58,    59,
    59,    60,    60,    60,    61,    62,    62,    63,    63,    64,
    64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
    69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
    70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
    70,    71,    71,    72,    73,    73,    73,    74,    74,    75,
    75,    76,    76,    77,    77,    78,    79,    80,    80,    80,
    81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
    82,    83,    83,    84,    84,    85,    85,    86,    86,    87,
    87,    87,    88,    88,    89,    89,    90,    90,    90,    90,
    90,    90,    91,    92,    92,    93,    94,    94,    94,    94,
    94,    94,    95,    95,    96,    96,    96,    97,    97,    97,
    98,    98,    98,    98,    98,    98,    99,    99,   100,   100,
   100,   101,   101,   101,   102,   102,   102,   103,   103,   104,
   104,   104,   104,   105,   106,   107,   107
};

static const short yyr2[] = {     0,
     1,     1,     2,     2,     1,     1,     1,     1,     2,     1,
     1,     1,     1,     1,     3,     1,     2,     0,     1,     0,
     1,     1,     3,     1,     3,     1,     3,     1,     3,     2,
     2,     1,     1,     1,     3,     1,     1,     2,     2,     2,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     0,     1,     4,     1,     1,     1,     1,     1,     1,
     2,     3,     2,     5,     7,     5,     7,     9,     7,     8,
     1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
     3,     1,     2,     0,     1,     1,     1,     1,     2,     6,
     4,     6,     2,     1,     2,     1,     4,     6,     4,     6,
     6,     6,     3,     1,     3,     3,     1,     1,     1,     2,
     2,     2,     1,     1,     4,     6,     3,     4,     6,     3,
     1,     1,     1,     2,     2,     2,     1,     1,     5,     7,
     4,     5,     7,     4,     1,     1,     3,     1,     2,     3,
     2,     4,     3,     3,     7,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     5,     6,     7,     0,     0,     0,
     0,     0,     0,    36,     8,     0,    52,    11,    12,    13,
    10,    14,    32,     0,    71,     0,    84,    20,    34,    33,
    79,     0,    37,    74,    75,    76,    77,    82,    78,     1,
    88,     2,    86,    87,    80,    39,    38,     0,    56,    55,
    57,     0,     0,     0,     0,    52,     0,     0,     0,   104,
     0,    53,     0,     9,    40,    85,     0,    24,     0,    21,
    22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    72,    83,     3,     4,    89,    35,    58,     0,
     0,    59,    60,     0,     0,     0,    32,     0,     0,     0,
     0,     0,     0,     0,   107,     0,     0,    94,   109,   113,
   114,   108,     0,     0,     0,   121,     0,     0,    96,   123,
   127,   128,   122,     0,     0,   103,     0,    73,    81,     0,
    15,     0,    51,    45,    46,    48,    47,    49,    50,    41,
    42,    43,    44,     0,    63,    54,     0,    61,     0,     0,
     0,     0,     0,    52,     0,   135,     0,     0,   136,   138,
     0,     0,     0,     0,     0,     0,     0,    16,     0,    91,
    93,   110,   111,   112,     0,    18,     0,     0,    18,     0,
     0,     0,    97,    95,   124,   125,   126,     0,     0,    99,
   105,    25,    23,    62,    64,    66,     0,     0,     0,     0,
     0,     0,     0,     0,   141,     0,   117,     0,     0,   139,
     0,     0,   120,     0,   146,   147,     0,     0,     0,   106,
    17,     0,    19,     0,    18,     0,     0,    18,     0,     0,
     0,     0,     0,     0,     0,     0,    52,     0,   144,   143,
     0,   140,     0,     0,   137,    26,    28,   115,     0,   118,
     0,    90,    92,     0,   131,     0,     0,   134,     0,    98,
   101,   100,   102,    65,    67,    69,     0,     0,     0,   142,
    31,    30,     0,     0,     0,    18,   129,    18,   132,    70,
     0,   116,    27,    29,   119,     0,     0,     0,    68,   145,
   130,   133,     0,     0,     0
};

static const short yydefgoto[] = {   293,
    28,    29,    30,    31,   223,   224,    69,    70,    71,   245,
   246,   247,    32,    63,    33,    52,    91,    92,    93,    34,
    35,    36,    37,    38,    39,    40,    67,    41,    42,    43,
   106,   117,    44,    45,    61,   118,   108,   109,   110,   111,
   119,   120,   121,   122,   158,   159,   160,   161,   123,   217
};

static const short yypact[] = {   255,
   410,   410,   410,    51,-32768,-32768,-32768,     0,     6,   301,
    21,    -2,    44,-32768,-32768,     9,   410,-32768,-32768,-32768,
-32768,-32768,-32768,    53,-32768,   410,   301,    46,-32768,-32768,
-32768,   240,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   255,
-32768,   255,-32768,-32768,-32768,-32768,-32768,   537,-32768,-32768,
-32768,   -30,   410,   410,    68,   396,   179,   186,   347,-32768,
    54,   633,    48,-32768,-32768,   301,    47,    98,    61,    65,
-32768,   410,   410,   410,   410,   410,   410,   410,   410,   410,
   410,   410,-32768,-32768,    76,   301,-32768,-32768,    73,   410,
   109,    -9,-32768,   553,   569,   114,   105,    90,   102,   -12,
    -5,   141,   122,   139,-32768,   121,   449,   449,-32768,-32768,
-32768,-32768,    -4,    -1,   126,-32768,   132,   455,   455,-32768,
-32768,-32768,-32768,   138,   149,-32768,   155,-32768,-32768,   410,
-32768,    46,   633,   515,   515,   181,   181,   181,   181,   193,
   193,-32768,-32768,   410,   633,-32768,    73,-32768,   301,   301,
   410,   410,   182,   410,   215,   161,    12,   165,   100,-32768,
    19,   459,   166,    19,   162,   350,   350,-32768,   124,-32768,
   449,-32768,-32768,-32768,   470,   139,    19,   490,   139,    19,
   354,   354,-32768,   455,-32768,-32768,-32768,   354,   354,-32768,
-32768,   633,-32768,   633,   191,-32768,   585,   601,   410,   173,
   209,   211,    16,   139,-32768,   183,-32768,   161,   480,-32768,
   203,   212,-32768,   205,-32768,-32768,   241,   224,   226,-32768,
-32768,   243,   139,   207,   139,   245,   207,   139,   233,   234,
   235,   236,   301,   222,   301,   617,   410,    19,-32768,-32768,
   227,-32768,     7,   231,-32768,   228,-32768,-32768,    19,-32768,
   139,-32768,-32768,    19,-32768,   207,    19,-32768,   207,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   301,   264,   238,-32768,
-32768,-32768,   313,   239,   244,   139,-32768,   139,-32768,-32768,
   301,-32768,-32768,-32768,-32768,   254,   207,   207,-32768,-32768,
-32768,-32768,   286,   294,-32768
};

static const short yypgoto[] = {-32768,
   -41,-32768,-32768,   -56,   210,  -154,-32768,-32768,   175,-32768,
-32768,    36,     5,   -52,-32768,-32768,-32768,-32768,   221,-32768,
-32768,-32768,-32768,   -10,  -190,    -7,-32768,   -31,   275,-32768,
    45,   -38,-32768,-32768,-32768,   -25,   214,   -99,-32768,-32768,
   198,  -109,-32768,-32768,   -73,-32768,   158,   -87,    11,-32768
};


#define	YYLAST		646


static const short yytable[] = {    55,
   105,   116,   116,    99,   155,    46,    47,    48,   173,   186,
    87,   162,   175,   164,    98,   178,    53,    89,    64,    66,
   125,    62,    54,    90,   227,   177,   180,   163,   204,    84,
    65,   107,   204,   255,    86,   156,   258,    56,   147,   176,
   179,   157,   156,   156,    90,    57,   156,   168,   157,   157,
   105,   172,   157,    87,   271,    84,    60,    94,    95,   205,
    62,   116,   185,   240,    64,   277,   156,   112,   279,   206,
   256,   173,   157,   259,   186,    84,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   211,    49,    50,
   214,    58,    59,    68,   145,    96,   291,   292,   128,    51,
   130,   200,   129,   225,   126,   127,   228,    12,    13,   105,
   105,   131,   221,   202,   172,   241,   132,   112,   174,   168,
   202,   287,   168,   288,   116,   116,   144,   185,   146,   187,
   151,   116,   116,   202,   192,   152,   202,   153,   195,   196,
   107,   107,   229,   230,     5,     6,     7,   208,   194,   231,
   232,   209,   154,   157,   170,   197,   198,   165,    62,     5,
     6,     7,   202,    15,   269,   183,   221,   244,   168,   166,
   167,   168,    24,   181,   182,   274,   112,   112,    15,   220,
   276,   174,   190,   278,   268,   188,   189,    24,   100,   101,
    79,    80,    81,    82,   187,   113,   114,   215,   216,     5,
     6,     7,   191,   236,    81,    82,     5,     6,     7,   275,
   218,   219,   199,   102,   203,   207,   213,   233,    15,   168,
   102,   168,   264,   237,   266,    15,   238,    24,   239,   249,
   242,   244,   103,   104,    24,     5,     6,     7,   201,   115,
   104,    62,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,   248,    15,   250,   280,   252,   251,   253,
   254,    27,   257,    24,     1,     2,   260,   261,   262,   263,
   289,     3,   265,     4,   270,     5,     6,     7,   272,   273,
     8,   281,     9,    10,    11,   294,    12,    13,   282,   285,
    83,   286,    14,   295,    15,    16,    17,    18,    19,    20,
    21,    22,    23,    24,   290,    25,   193,    26,   284,    27,
     1,     2,   148,   169,    85,   184,   210,     3,     0,     4,
   171,     5,     6,     7,     0,     0,     8,     0,     9,    10,
    11,     0,     0,     5,     6,     7,     0,     0,    14,     0,
    15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     0,    25,    15,    26,     0,    27,   113,   114,     0,   100,
   101,   243,   283,   113,   114,     0,     0,     5,     6,     7,
     5,     6,     7,     0,     5,     6,     7,     0,     0,     0,
     0,   102,     0,     0,   102,     0,    15,     0,   102,    15,
     0,     0,     0,    15,     0,    24,     0,     0,    24,     0,
   124,   104,    24,     0,   104,     1,     2,     0,   104,     0,
     0,     0,     3,     0,     4,     0,     5,     6,     7,     1,
     2,     0,     0,     0,     0,     0,     3,     0,     4,     0,
     0,     0,     0,    14,     0,    15,     0,     0,    18,    19,
    20,    21,    22,    97,    24,     0,     0,    14,    26,     0,
     0,     0,    18,    19,    20,    21,    22,    23,   100,   101,
     0,     0,    26,     0,   113,   114,     0,     0,     0,     5,
     6,     7,     0,     0,     0,     5,     6,     7,     0,     5,
     6,     7,   212,   102,     0,     0,     0,     0,    15,   102,
     5,     6,     7,   222,    15,     0,     0,    24,    15,     0,
     5,     6,     7,    24,     0,     0,     0,    24,     0,    15,
     5,     6,     7,   226,     0,     0,     0,     0,    24,    15,
    75,    76,    77,    78,    79,    80,    81,    82,   243,    15,
     0,     0,     0,     0,     0,     0,     0,     0,    24,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     0,     0,     0,     0,    88,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,     0,     0,     0,     0,
   149,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,     0,     0,     0,     0,   150,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
     0,     0,   234,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,     0,     0,     0,     0,   235,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     0,     0,     0,     0,   267,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82
};

static const short yycheck[] = {    10,
    57,    58,    59,    56,    17,     1,     2,     3,   108,   119,
    42,    17,    17,   101,    56,    17,    17,    48,    12,    27,
    59,    17,    17,    54,   179,   113,   114,   101,    17,    40,
    26,    57,    17,   224,    42,    48,   227,    17,    48,   113,
   114,    54,    48,    48,    54,    48,    48,   104,    54,    54,
   107,   108,    54,    85,    48,    66,    48,    53,    54,    48,
    56,   118,   119,    48,    12,   256,    48,    57,   259,   157,
   225,   171,    54,   228,   184,    86,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,   161,    38,    39,
   164,    48,    49,    48,    90,    28,   287,   288,    51,    49,
     3,   154,    56,   177,    51,    52,   180,    32,    33,   166,
   167,    51,   169,   155,   171,   203,    52,   107,   108,   176,
   162,   276,   179,   278,   181,   182,    54,   184,    20,   119,
    17,   188,   189,   175,   130,    31,   178,    48,   149,   150,
   166,   167,   181,   182,    21,    22,    23,    48,   144,   188,
   189,    52,    51,    54,    34,   151,   152,    17,   154,    21,
    22,    23,   204,    40,   238,    34,   223,   209,   225,    48,
    49,   228,    49,    48,    49,   249,   166,   167,    40,    56,
   254,   171,    34,   257,   237,    48,    49,    49,    10,    11,
    10,    11,    12,    13,   184,    10,    11,    36,    37,    21,
    22,    23,    48,   199,    12,    13,    21,    22,    23,   251,
   166,   167,    31,    35,    54,    51,    51,    27,    40,   276,
    35,   278,   233,    51,   235,    40,    18,    49,    18,    18,
    48,   273,    54,    55,    49,    21,    22,    23,    24,    54,
    55,   237,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    51,    40,    51,   267,    34,    18,    34,
    18,    55,    18,    49,    10,    11,    34,    34,    34,    34,
   281,    17,    51,    19,    48,    21,    22,    23,    48,    52,
    26,    18,    28,    29,    30,     0,    32,    33,    51,    51,
    51,    48,    38,     0,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    51,    51,   132,    53,   273,    55,
    10,    11,    92,   104,    40,   118,   159,    17,    -1,    19,
   107,    21,    22,    23,    -1,    -1,    26,    -1,    28,    29,
    30,    -1,    -1,    21,    22,    23,    -1,    -1,    38,    -1,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    -1,    51,    40,    53,    -1,    55,    10,    11,    -1,    10,
    11,    49,    50,    10,    11,    -1,    -1,    21,    22,    23,
    21,    22,    23,    -1,    21,    22,    23,    -1,    -1,    -1,
    -1,    35,    -1,    -1,    35,    -1,    40,    -1,    35,    40,
    -1,    -1,    -1,    40,    -1,    49,    -1,    -1,    49,    -1,
    54,    55,    49,    -1,    55,    10,    11,    -1,    55,    -1,
    -1,    -1,    17,    -1,    19,    -1,    21,    22,    23,    10,
    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    -1,
    -1,    -1,    -1,    38,    -1,    40,    -1,    -1,    43,    44,
    45,    46,    47,    48,    49,    -1,    -1,    38,    53,    -1,
    -1,    -1,    43,    44,    45,    46,    47,    48,    10,    11,
    -1,    -1,    53,    -1,    10,    11,    -1,    -1,    -1,    21,
    22,    23,    -1,    -1,    -1,    21,    22,    23,    -1,    21,
    22,    23,    24,    35,    -1,    -1,    -1,    -1,    40,    35,
    21,    22,    23,    24,    40,    -1,    -1,    49,    40,    -1,
    21,    22,    23,    49,    -1,    -1,    -1,    49,    -1,    40,
    21,    22,    23,    24,    -1,    -1,    -1,    -1,    49,    40,
     6,     7,     8,     9,    10,    11,    12,    13,    49,    40,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
    -1,    -1,    -1,    -1,    18,     3,     4,     5,     6,     7,
     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
    18,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    13,    -1,    -1,    -1,    -1,    18,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
    -1,    -1,    18,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
    -1,    -1,    -1,    -1,    18,     3,     4,     5,     6,     7,
     8,     9,    10,    11,    12,    13
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 140 "bison_rules_with_code.y"
{yyval.Program = root = createProgramNode(yyvsp[0].Statement_list, NULL);;
    break;}
case 2:
#line 141 "bison_rules_with_code.y"
{yyval.Program = root = createProgramNode(NULL, yyvsp[0].Class_statement_list);;
    break;}
case 3:
#line 142 "bison_rules_with_code.y"
{yyval.Program = root = createProgramNode(yyvsp[-1].Statement_list, yyvsp[0].Class_statement_list);;
    break;}
case 4:
#line 143 "bison_rules_with_code.y"
{yyval.Program = root = createProgramNode(yyvsp[0].Statement_list, yyvsp[-1].Class_statement_list);;
    break;}
case 5:
#line 147 "bison_rules_with_code.y"
{yyval.Type = createTypeNode(INT);;
    break;}
case 6:
#line 148 "bison_rules_with_code.y"
{yyval.Type = createTypeNode(CHAR);;
    break;}
case 7:
#line 149 "bison_rules_with_code.y"
{yyval.Type = createTypeNode(FLOAT);;
    break;}
case 8:
#line 150 "bison_rules_with_code.y"
{yyval.Type = createTypeNode(ID);;
    break;}
case 9:
#line 151 "bison_rules_with_code.y"
{yyval.Type = createClassTypeNode(CLASS_NAME, yyvsp[-1].Identifier);;
    break;}
case 10:
#line 155 "bison_rules_with_code.y"
{yyval.Numeric_constant = createFloatConstantNode(yyvsp[0].Float_constant);;
    break;}
case 11:
#line 156 "bison_rules_with_code.y"
{yyval.Numeric_constant = createIntegerConstantNode(yyvsp[0].Integer_constant);;
    break;}
case 12:
#line 159 "bison_rules_with_code.y"
{yyval.Literal = createLiteralNode(STRING_CONSTANT, yyvsp[0].String_constant);;
    break;}
case 13:
#line 160 "bison_rules_with_code.y"
{yyval.Literal = createLiteralNode(CHAR_CONSTANT, yyvsp[0].Char_constant);;
    break;}
case 14:
#line 161 "bison_rules_with_code.y"
{yyval.Literal = createLiteralNode(NSSTRING_CONSTANT, yyvsp[0].NSString_constant);;
    break;}
case 15:
#line 165 "bison_rules_with_code.y"
{yyval.Declaration = createDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Init_declarator_list);;
    break;}
case 16:
#line 168 "bison_rules_with_code.y"
{yyval.Declaration_list = createDeclarationListNode(yyvsp[0].Declaration);;
    break;}
case 17:
#line 169 "bison_rules_with_code.y"
{yyval.Declaration_list = addDeclarationListNode(yyvsp[-1].Declaration_list, yyvsp[0].Declaration);;
    break;}
case 18:
#line 172 "bison_rules_with_code.y"
{yyval.Declaration_list = NULL;;
    break;}
case 19:
#line 173 "bison_rules_with_code.y"
{yyval.Declaration_list = yyvsp[0].Declaration_list;;
    break;}
case 20:
#line 176 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 21:
#line 177 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 22:
#line 180 "bison_rules_with_code.y"
{yyval.Init_declarator_list = createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 23:
#line 181 "bison_rules_with_code.y"
{yyval.Init_declarator_list = addInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 24:
#line 184 "bison_rules_with_code.y"
{yyval.Init_declarator = createInitDeclaratorNode(SIMPLE_DECLARATOR, yyvsp[0].Identifier, NULL);;
    break;}
case 25:
#line 185 "bison_rules_with_code.y"
{yyval.Init_declarator = createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 26:
#line 188 "bison_rules_with_code.y"
{yyval.Parameter_type_list = createParameterTypeListNode(yyvsp[0].Parameter_list, false);;
    break;}
case 27:
#line 189 "bison_rules_with_code.y"
{yyval.Parameter_type_list = createParameterTypeListNode(yyvsp[-2].Parameter_list, true);;
    break;}
case 28:
#line 192 "bison_rules_with_code.y"
{yyval.Parameter_list = createParameterListNode(yyvsp[0].Parameter_declaration);;
    break;}
case 29:
#line 193 "bison_rules_with_code.y"
{yyval.Parameter_list = addParameterListNode(yyvsp[-2].Parameter_list, yyvsp[0].Parameter_declaration);;
    break;}
case 30:
#line 196 "bison_rules_with_code.y"
{yyval.Parameter_declaration = createParameterDeclarationNode(yyvsp[-1].Type, yyvsp[0].Identifier);;
    break;}
case 31:
#line 197 "bison_rules_with_code.y"
{yyval.Parameter_declaration = createParameterDeclarationNode(yyvsp[-1].Identifier, yyvsp[0].Identifier);;
    break;}
case 32:
#line 202 "bison_rules_with_code.y"
{yyval.Expression = createIdentifierExpressionNode(yyvsp[0].Identifier);;
    break;}
case 33:
#line 203 "bison_rules_with_code.y"
{yyval.Expression = createLiteralExpressionNode(yyvsp[0].Literal);;
    break;}
case 34:
#line 204 "bison_rules_with_code.y"
{yyval.Expression = createNumericConstantExpressionNode(yyvsp[0].Numeric_constant);;
    break;}
case 35:
#line 205 "bison_rules_with_code.y"
{yyval.Expression = createSimpleExpressionNode(PRIORITY, yyvsp[-1].Expression);;
    break;}
case 36:
#line 206 "bison_rules_with_code.y"
{yyval.Expression = createSelfExpressionNode();;
    break;}
case 37:
#line 207 "bison_rules_with_code.y"
{yyval.Expression = createSimpleExpressionNode(MESSAGE_EXPRESSION, yyvsp[0].Message_expression);;
    break;}
case 38:
#line 208 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(UMINUS, NULL, yyvsp[0].Expression);;
    break;}
case 39:
#line 209 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(UPLUS, NULL, yyvsp[0].Expression);;
    break;}
case 40:
#line 210 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(UAMPERSAND, NULL, yyvsp[0].Expression);;
    break;}
case 41:
#line 211 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(PLUS, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 42:
#line 212 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(MINUS, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 43:
#line 213 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(MUL, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 44:
#line 214 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(DIV, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 45:
#line 215 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(EQUAL, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 46:
#line 216 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(NOT_EQUAL, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 47:
#line 217 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(GREATER, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 48:
#line 218 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(LESS, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 49:
#line 219 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(LESS_EQUAL, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 50:
#line 220 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(GREATER_EQUAL, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 51:
#line 221 "bison_rules_with_code.y"
{yyval.Expression = createOperationExpressionNode(ASSIGNMENT, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 52:
#line 224 "bison_rules_with_code.y"
{yyval.Expression = NULL;;
    break;}
case 53:
#line 225 "bison_rules_with_code.y"
{yyval.Expression = yyvsp[0].Expression;;
    break;}
case 54:
#line 228 "bison_rules_with_code.y"
{yyval.Message_expression = createMessageExpressionNode(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 55:
#line 231 "bison_rules_with_code.y"
{yyval.Receiver = createReceiverNode(SUPER, NULL);;
    break;}
case 56:
#line 232 "bison_rules_with_code.y"
{yyval.Receiver = createReceiverNode(SELF, NULL);;
    break;}
case 57:
#line 233 "bison_rules_with_code.y"
{yyval.Receiver = createReceiverNode(CLASS_NAME, yyvsp[0].Identifier);;
    break;}
case 58:
#line 236 "bison_rules_with_code.y"
{yyval.Message_selector = createMethodSelectorNode(yyvsp[0].Identifier, NULL);;
    break;}
case 59:
#line 237 "bison_rules_with_code.y"
{yyval.Message_selector = createMethodSelectorNode(NULL, yyvsp[0].Keyword_argument_list);;
    break;}
case 60:
#line 240 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = createKeywordArgumentListNode(yyvsp[0].Keyword_argument);;
    break;}
case 61:
#line 241 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = addKeywordArgumentListNode(yyvsp[-1].Keyword_argument_list, yyvsp[0].Keyword_argument);;
    break;}
case 62:
#line 244 "bison_rules_with_code.y"
{yyval.Keyword_argument = createKeywordArgumentNode(WITH_IDENTIFIER, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 63:
#line 245 "bison_rules_with_code.y"
{yyval.Keyword_argument = createKeywordArgumentNode(WITHOUT_IDENTIFIER, NULL, yyvsp[0].Expression);;
    break;}
case 64:
#line 249 "bison_rules_with_code.y"
{yyval.If = createIfStatementNode(WITHOUT_ALTERNATIVE, yyvsp[-2].Expression, yyvsp[0].Statement, NULL);;
    break;}
case 65:
#line 250 "bison_rules_with_code.y"
{yyval.If = createIfStatementNode(WITHOUT_ALTERNATIVE, yyvsp[-4].Expression, yyvsp[-2].Statement, yyvsp[0].Statement);;
    break;}
case 66:
#line 254 "bison_rules_with_code.y"
{yyval.While  = createWhileStatementNode(yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 67:
#line 257 "bison_rules_with_code.y"
{yyval.Do_while = createDoWhileStatementNode(yyvsp[-2].Expression, yyvsp[-5].Statement);;
    break;}
case 68:
#line 260 "bison_rules_with_code.y"
{yyval.For = createForStatementNode(yyvsp[-6].Expression, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 69:
#line 261 "bison_rules_with_code.y"
{yyval.For = createForeachStatementNode(FOREACH, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 70:
#line 262 "bison_rules_with_code.y"
{yyval.For = createForeachStatementNode(FOREACH_WITH_DECLARATION, yyvsp[-5].Type, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 71:
#line 267 "bison_rules_with_code.y"
{yyval.Statement = createSimpleStatementNode(EMPTY, NULL);;
    break;}
case 72:
#line 268 "bison_rules_with_code.y"
{yyval.Statement = createSimpleStatementNode(SIMPLE, yyvsp[-1].Expression);;
    break;}
case 73:
#line 269 "bison_rules_with_code.y"
{yyval.Statement = createSimpleStatementNode(RETURN, yyvsp[-1].Expression);;
    break;}
case 74:
#line 270 "bison_rules_with_code.y"
{yyval.Statement = createComplexStatementNode(statement_type::IF, yyvsp[0].If);;
    break;}
case 75:
#line 271 "bison_rules_with_code.y"
{yyval.Statement = createComplexStatementNode(statement_type::WHILE, yyvsp[0].While);;
    break;}
case 76:
#line 272 "bison_rules_with_code.y"
{yyval.Statement = createComplexStatementNode(statement_type::DO_WHILE, yyvsp[0].Do_while);;
    break;}
case 77:
#line 273 "bison_rules_with_code.y"
{yyval.Statement = createComplexStatementNode(statement_type::FOR, yyvsp[0].For);;
    break;}
case 78:
#line 274 "bison_rules_with_code.y"
{yyval.Statement = createComplexStatementNode(statement_type::COMPOUND, yyvsp[0].Compound_statement);;
    break;}
case 79:
#line 275 "bison_rules_with_code.y"
{yyval.Statement = createDeclarationStatementNode(yyvsp[0].Declaration);;
    break;}
case 80:
#line 276 "bison_rules_with_code.y"
{yyval.Statement = createClassDeclarationStatementNode(yyvsp[0].Class_declaration_list);;
    break;}
case 81:
#line 279 "bison_rules_with_code.y"
{yyval.Compound_statement = createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 82:
#line 282 "bison_rules_with_code.y"
{yyval.Statement_list = createStatementListNode(yyvsp[0].Statement);;
    break;}
case 83:
#line 283 "bison_rules_with_code.y"
{yyval.Statement_list = addStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 84:
#line 286 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 85:
#line 287 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 86:
#line 290 "bison_rules_with_code.y"
{yyval.Class_statement = createInterfaceClassStatementNode(yyvsp[0].Class_interface);;
    break;}
case 87:
#line 291 "bison_rules_with_code.y"
{yyval.Class_statement = createImplementationClassStatementNode(yyvsp[0].Class_implementation);;
    break;}
case 88:
#line 294 "bison_rules_with_code.y"
{yyval.Class_statement_list = createClassStatementListNode(yyvsp[0].Class_statement);;
    break;}
case 89:
#line 295 "bison_rules_with_code.y"
{yyval.Class_statement_list = addClassStatementListNode(yyvsp[-1].Class_statement_list, yyvsp[0].Class_statement);;
    break;}
case 90:
#line 299 "bison_rules_with_code.y"
{yyval.Class_interface = createClassInterfaceNode(class_interface_type::WITH_INHERITANCE, yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_statement);;
    break;}
case 91:
#line 300 "bison_rules_with_code.y"
{yyval.Class_interface = createClassInterfaceNode(class_interface_type::WITHOUT_INHERITANCE, yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_statement);;
    break;}
case 92:
#line 301 "bison_rules_with_code.y"
{yyval.Class_interface = createClassInterfaceNode(class_interface_type::WITH_INHERITANCE, yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_statement);;
    break;}
case 93:
#line 304 "bison_rules_with_code.y"
{yyval.Interface_statement = createInterfaceStatementNode(yyvsp[-1].Instance_variables, yyvsp[0].Interface_declaration_list);;
    break;}
case 94:
#line 305 "bison_rules_with_code.y"
{yyval.Interface_statement = createInterfaceStatementNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 95:
#line 308 "bison_rules_with_code.y"
{yyval.Implementation_statement = createImplementationStatementNode(yyvsp[-1].Instance_variables, yyvsp[0].Implementation_definition_list);;
    break;}
case 96:
#line 309 "bison_rules_with_code.y"
{yyval.Implementation_statement = createImplementationStatementNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 97:
#line 312 "bison_rules_with_code.y"
{yyval.Class_implementation = createClassImplementationNode(class_implementation_type::WITHOUT_INHERITANCE, yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_statement);;
    break;}
case 98:
#line 313 "bison_rules_with_code.y"
{yyval.Class_implementation = createClassImplementationNode(class_implementation_type::WITH_INHERITANCE, yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_statement);;
    break;}
case 99:
#line 314 "bison_rules_with_code.y"
{yyval.Class_implementation = createClassImplementationNode(class_implementation_type::WITHOUT_INHERITANCE, yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_statement);;
    break;}
case 100:
#line 315 "bison_rules_with_code.y"
{yyval.Class_implementation = createClassImplementationNode(class_implementation_type::WITH_INHERITANCE, yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_statement);;
    break;}
case 101:
#line 316 "bison_rules_with_code.y"
{yyval.Class_implementation = createClassImplementationNode(class_implementation_type::WITH_INHERITANCE, yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_statement);;
    break;}
case 102:
#line 317 "bison_rules_with_code.y"
{yyval.Class_implementation = createClassImplementationNode(class_implementation_type::WITH_INHERITANCE, yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_statement);;
    break;}
case 103:
#line 320 "bison_rules_with_code.y"
{yyval.Class_declaration_list = createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 104:
#line 323 "bison_rules_with_code.y"
{yyval.Class_list = createClassListNode(yyvsp[0].Identifier);;
    break;}
case 105:
#line 324 "bison_rules_with_code.y"
{yyval.Class_list = addClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 106:
#line 327 "bison_rules_with_code.y"
{yyval.Instance_variables = createInstanceVariablesNode(yyvsp[-1].Declaration_list);;
    break;}
case 107:
#line 330 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = createDeclarationInterfaceDeclarationListNode(yyvsp[0].Declaration);;
    break;}
case 108:
#line 331 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = createPropertyInterfaceDeclarationListNode(yyvsp[0].Property);;
    break;}
case 109:
#line 332 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = createMethodDeclarationInterfaceDeclarationListNode(yyvsp[0].Method_declaration);;
    break;}
case 110:
#line 333 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = addDeclarationInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 111:
#line 334 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = addMethodDeclarationInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 112:
#line 335 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = addPropertyInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 113:
#line 338 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 114:
#line 339 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 115:
#line 342 "bison_rules_with_code.y"
{yyval.Method_declaration = createMethodDeclarationNode(method_declaration_type::CLASS, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 116:
#line 343 "bison_rules_with_code.y"
{yyval.Method_declaration = createMethodDeclarationNode(method_declaration_type::CLASS, yyvsp[-3].Type, yyvsp[-1].Method_selector);;
    break;}
case 117:
#line 344 "bison_rules_with_code.y"
{yyval.Method_declaration = createMethodDeclarationNode(method_declaration_type::CLASS, NULL, yyvsp[-1].Method_selector);;
    break;}
case 118:
#line 347 "bison_rules_with_code.y"
{yyval.Method_declaration = createMethodDeclarationNode(method_declaration_type::INSTANCE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 119:
#line 348 "bison_rules_with_code.y"
{yyval.Method_declaration = createMethodDeclarationNode(method_declaration_type::INSTANCE, yyvsp[-3].Type, yyvsp[-1].Method_selector);;
    break;}
case 120:
#line 349 "bison_rules_with_code.y"
{yyval.Method_declaration = createMethodDeclarationNode(method_declaration_type::INSTANCE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 121:
#line 352 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = createDeclarationImplementationDefinitionListNode(yyvsp[0].Declaration);;
    break;}
case 122:
#line 353 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = createPropertyImplementationDefinitionListNode(yyvsp[0].Property);;
    break;}
case 123:
#line 354 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = createMethodDeclarationImplementationDefinitionListNode(yyvsp[0].Method_definition);;
    break;}
case 124:
#line 355 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = addDeclarationImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 125:
#line 356 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = addMethodDeclarationImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 126:
#line 357 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = addPropertyImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Property);;
    break;}
case 127:
#line 360 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 128:
#line 361 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 129:
#line 364 "bison_rules_with_code.y"
{yyval.Method_definition = createMethodDefinitionNode(method_definition_type::CLASS, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 130:
#line 365 "bison_rules_with_code.y"
{yyval.Method_definition = createMethodDefinitionNode(method_definition_type::CLASS, yyvsp[-4].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 131:
#line 366 "bison_rules_with_code.y"
{yyval.Method_definition = createMethodDefinitionNode(method_definition_type::CLASS, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 132:
#line 369 "bison_rules_with_code.y"
{yyval.Method_definition = createMethodDefinitionNode(method_definition_type::INSTANCE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 133:
#line 370 "bison_rules_with_code.y"
{yyval.Method_definition = createMethodDefinitionNode(method_definition_type::INSTANCE, yyvsp[-4].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 134:
#line 371 "bison_rules_with_code.y"
{yyval.Method_definition = createMethodDefinitionNode(method_definition_type::INSTANCE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 135:
#line 374 "bison_rules_with_code.y"
{yyval.Method_selector = createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL);;
    break;}
case 136:
#line 375 "bison_rules_with_code.y"
{yyval.Method_selector = createMethodSelectorNode(NULL, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 137:
#line 376 "bison_rules_with_code.y"
{yyval.Method_selector = createMethodSelectorNode(NULL, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_type_list);;
    break;}
case 138:
#line 379 "bison_rules_with_code.y"
{yyval.Keyword_selector = createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 139:
#line 380 "bison_rules_with_code.y"
{yyval.Keyword_selector = addKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 140:
#line 383 "bison_rules_with_code.y"
{yyval.Keyword_declaration = createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 141:
#line 384 "bison_rules_with_code.y"
{yyval.Keyword_declaration = createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 142:
#line 385 "bison_rules_with_code.y"
{yyval.Keyword_declaration = createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 143:
#line 386 "bison_rules_with_code.y"
{yyval.Keyword_declaration = createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 144:
#line 389 "bison_rules_with_code.y"
{yyval.Type = createTypeNode(yyvsp[-1].Type);;
    break;}
case 145:
#line 392 "bison_rules_with_code.y"
{yyval.Property = createPropertyNode(yyvsp[-4].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 146:
#line 395 "bison_rules_with_code.y"
{yyval.Attribute = createAttributeNode(READONLY);;
    break;}
case 147:
#line 396 "bison_rules_with_code.y"
{yyval.Attribute = createAttributeNode(READWRITE);;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 399 "bison_rules_with_code.y"


