
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

#line 1 "bison_rules_with_code.y"

	#include "classes_nodes.h"
	Program_node *root;

#line 7 "bison_rules_with_code.y"
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



#define	YYFINAL		291
#define	YYFLAG		-32768
#define	YYNTBASE	56

#define YYTRANSLATE(x) ((unsigned)(x) <= 293 ? yytranslate[x] : 106)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    52,     2,    17,
    18,    12,    10,    51,    11,     2,    13,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    53,    50,     6,
     3,     7,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    19,     2,    20,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    54,     2,    55,     2,     2,     2,     2,     2,
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
    47,    48,    49
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,    10,    12,    14,    16,    18,    21,
    23,    25,    27,    29,    31,    35,    37,    40,    41,    43,
    44,    46,    48,    52,    54,    58,    60,    64,    67,    69,
    71,    73,    77,    79,    81,    84,    87,    90,    94,    98,
   102,   106,   110,   114,   118,   122,   126,   130,   134,   135,
   137,   142,   144,   146,   148,   150,   152,   154,   157,   161,
   164,   170,   178,   184,   192,   202,   210,   219,   221,   224,
   228,   230,   232,   234,   236,   238,   240,   242,   246,   248,
   251,   252,   254,   256,   258,   260,   263,   270,   275,   282,
   285,   287,   290,   292,   297,   304,   309,   316,   323,   330,
   334,   336,   340,   344,   346,   348,   350,   353,   356,   359,
   361,   363,   368,   375,   379,   384,   391,   395,   397,   399,
   401,   404,   407,   410,   412,   414,   420,   428,   433,   439,
   447,   452,   454,   456,   460,   462,   465,   469,   472,   477,
   481,   485,   493,   495
};

static const short yyrhs[] = {    81,
     0,    84,     0,    81,    84,     0,    84,    81,     0,    21,
     0,    22,     0,    23,     0,    40,     0,    49,    12,     0,
    46,     0,    43,     0,    44,     0,    45,     0,    47,     0,
    57,    63,    50,     0,    60,     0,    61,    60,     0,     0,
    61,     0,     0,    64,     0,    65,     0,    64,    51,    65,
     0,    48,     0,    48,     3,    68,     0,    67,     0,    66,
    51,    67,     0,    57,    48,     0,    48,     0,    59,     0,
    58,     0,    17,    68,    18,     0,    38,     0,    70,     0,
    11,    68,     0,    10,    68,     0,    52,    68,     0,    68,
    10,    68,     0,    68,    11,    68,     0,    68,    12,    68,
     0,    68,    13,    68,     0,    68,     4,    68,     0,    68,
     5,    68,     0,    68,     7,    68,     0,    68,     6,    68,
     0,    68,     8,    68,     0,    68,     9,    68,     0,    68,
     3,    68,     0,     0,    68,     0,    19,    71,    72,    20,
     0,    39,     0,    38,     0,    49,     0,    48,     0,    73,
     0,    74,     0,    73,    74,     0,    48,    53,    68,     0,
    53,    68,     0,    26,    17,    68,    18,    79,     0,    26,
    17,    68,    18,    79,    27,    79,     0,    28,    17,    68,
    18,    79,     0,    29,    79,    28,    17,    68,    18,    50,
     0,    30,    17,    69,    50,    69,    50,    69,    18,    79,
     0,    30,    17,    48,    31,    68,    18,    79,     0,    30,
    17,    57,    48,    31,    68,    18,    79,     0,    50,     0,
    68,    50,     0,    42,    69,    50,     0,    75,     0,    76,
     0,    77,     0,    78,     0,    80,     0,    60,     0,    89,
     0,    54,    82,    55,     0,    79,     0,    81,    79,     0,
     0,    81,     0,    85,     0,    88,     0,    83,     0,    84,
    83,     0,    32,    48,    53,    48,    86,    34,     0,    32,
    48,    86,    34,     0,    32,    48,    53,    49,    86,    34,
     0,    91,    92,     0,    92,     0,    91,    96,     0,    96,
     0,    33,    48,    87,    34,     0,    33,    48,    53,    48,
    87,    34,     0,    33,    49,    87,    34,     0,    33,    49,
    53,    48,    87,    34,     0,    33,    48,    53,    49,    87,
    34,     0,    33,    49,    53,    49,    87,    34,     0,    41,
    90,    50,     0,    48,     0,    90,    51,    48,     0,    54,
    61,    55,     0,    60,     0,   104,     0,    93,     0,    92,
    60,     0,    92,    93,     0,    92,   104,     0,    94,     0,
    95,     0,    10,   103,   100,    50,     0,    10,    17,    24,
    18,   100,    50,     0,    10,   100,    50,     0,    11,   103,
   100,    50,     0,    11,    17,    24,    18,   100,    50,     0,
    11,   100,    50,     0,    60,     0,   104,     0,    97,     0,
    96,    60,     0,    96,    97,     0,    96,   104,     0,    98,
     0,    99,     0,    10,   103,   100,    62,    80,     0,    10,
    17,    24,    18,   100,    62,    80,     0,    10,   100,    62,
    80,     0,    11,   103,   100,    62,    80,     0,    11,    17,
    24,    18,   100,    62,    80,     0,    11,   100,    62,    80,
     0,    48,     0,   101,     0,   101,    51,    66,     0,   102,
     0,   101,   102,     0,    53,   103,    48,     0,    53,    48,
     0,    48,    53,   103,    48,     0,    48,    53,    48,     0,
    17,    57,    18,     0,    35,    17,   105,    18,    57,    48,
    50,     0,    36,     0,    37,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   136,   137,   138,   139,   143,   144,   145,   146,   147,   151,
   152,   155,   156,   157,   161,   164,   165,   168,   169,   172,
   173,   176,   177,   180,   181,   184,   185,   188,   193,   194,
   195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
   205,   206,   207,   208,   209,   210,   211,   212,   215,   216,
   219,   222,   223,   224,   227,   228,   231,   232,   235,   236,
   240,   241,   245,   248,   251,   252,   253,   258,   259,   260,
   261,   262,   263,   264,   265,   266,   267,   270,   273,   274,
   277,   278,   281,   282,   285,   286,   290,   291,   292,   295,
   296,   299,   300,   303,   304,   305,   306,   307,   308,   311,
   314,   315,   318,   321,   322,   323,   324,   325,   326,   329,
   330,   333,   334,   335,   338,   339,   340,   343,   344,   345,
   346,   347,   348,   351,   352,   355,   356,   357,   360,   361,
   362,   365,   366,   367,   370,   371,   374,   375,   376,   377,
   380,   383,   386,   387
};

static const char * const yytname[] = {   "$","error","$undefined.","'='","EQUAL",
"NOT_EQUAL","'<'","'>'","LESS_EQUAL","GREATER_EQUAL","'+'","'-'","'*'","'/'",
"UMINUS","UPLUS","UAMPERSAND","'('","')'","'['","']'","INT","CHAR","FLOAT","VOID",
"ENUM","IF","ELSE","WHILE","DO","FOR","IN","INTERFACE","IMPLEMENTATION","END",
"PROPERTY","READONLY","READWRITE","SELF","SUPER","ID","CLASS","RETURN","INTEGER_CONSTANT",
"STRING_CONSTANT","CHAR_CONSTANT","FLOAT_CONSTANT","NSSTRING_CONSTANT","IDENTIFIER",
"CLASS_NAME","';'","','","'&'","':'","'{'","'}'","program","type","numeric_constant",
"literal","declaration","declaration_list","declaration_list_e","init_declarator_list_e",
"init_declarator_list","init_declarator","parameter_list","parameter_declaration",
"expression","expression_e","message_expression","receiver","message_selector",
"keyword_argument_list","keyword_argument","if_statement","while_statement",
"do_while_statement","for_statement","statement","compound_statement","statement_list",
"statement_list_e","class_statement","class_statement_list","class_interface",
"interface_statement","implementation_statement","class_implementation","class_declaration_list",
"class_list","instance_variables","interface_declaration_list","method_declaration",
"class_method_declaration","instance_method_declaration","implementation_definition_list",
"method_definition","class_method_definition","instance_method_definition","method_selector",
"keyword_selector","keyword_declaration","method_type","property","attribute",
""
};
#endif

static const short yyr1[] = {     0,
    56,    56,    56,    56,    57,    57,    57,    57,    57,    58,
    58,    59,    59,    59,    60,    61,    61,    62,    62,    63,
    63,    64,    64,    65,    65,    66,    66,    67,    68,    68,
    68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
    68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
    70,    71,    71,    71,    72,    72,    73,    73,    74,    74,
    75,    75,    76,    77,    78,    78,    78,    79,    79,    79,
    79,    79,    79,    79,    79,    79,    79,    80,    81,    81,
    82,    82,    83,    83,    84,    84,    85,    85,    85,    86,
    86,    87,    87,    88,    88,    88,    88,    88,    88,    89,
    90,    90,    91,    92,    92,    92,    92,    92,    92,    93,
    93,    94,    94,    94,    95,    95,    95,    96,    96,    96,
    96,    96,    96,    97,    97,    98,    98,    98,    99,    99,
    99,   100,   100,   100,   101,   101,   102,   102,   102,   102,
   103,   104,   105,   105
};

static const short yyr2[] = {     0,
     1,     1,     2,     2,     1,     1,     1,     1,     2,     1,
     1,     1,     1,     1,     3,     1,     2,     0,     1,     0,
     1,     1,     3,     1,     3,     1,     3,     2,     1,     1,
     1,     3,     1,     1,     2,     2,     2,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     0,     1,
     4,     1,     1,     1,     1,     1,     1,     2,     3,     2,
     5,     7,     5,     7,     9,     7,     8,     1,     2,     3,
     1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
     0,     1,     1,     1,     1,     2,     6,     4,     6,     2,
     1,     2,     1,     4,     6,     4,     6,     6,     6,     3,
     1,     3,     3,     1,     1,     1,     2,     2,     2,     1,
     1,     4,     6,     3,     4,     6,     3,     1,     1,     1,
     2,     2,     2,     1,     1,     5,     7,     4,     5,     7,
     4,     1,     1,     3,     1,     2,     3,     2,     4,     3,
     3,     7,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     5,     6,     7,     0,     0,     0,
     0,     0,     0,    33,     8,     0,    49,    11,    12,    13,
    10,    14,    29,     0,    68,     0,    81,    20,    31,    30,
    76,     0,    34,    71,    72,    73,    74,    79,    75,     1,
    85,     2,    83,    84,    77,    36,    35,     0,    53,    52,
    54,     0,     0,     0,     0,    49,     0,     0,     0,   101,
     0,    50,     0,     9,    37,    82,     0,    24,     0,    21,
    22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    69,    80,     3,     4,    86,    32,    55,     0,
     0,    56,    57,     0,     0,     0,    29,     0,     0,     0,
     0,     0,     0,     0,   104,     0,     0,    91,   106,   110,
   111,   105,     0,     0,     0,   118,     0,     0,    93,   120,
   124,   125,   119,     0,     0,   100,     0,    70,    78,     0,
    15,     0,    48,    42,    43,    45,    44,    46,    47,    38,
    39,    40,    41,     0,    60,    51,     0,    58,     0,     0,
     0,     0,     0,    49,     0,   132,     0,     0,   133,   135,
     0,     0,     0,     0,     0,     0,     0,    16,     0,    88,
    90,   107,   108,   109,     0,    18,     0,     0,    18,     0,
     0,     0,    94,    92,   121,   122,   123,     0,     0,    96,
   102,    25,    23,    59,    61,    63,     0,     0,     0,     0,
     0,     0,     0,     0,   138,     0,   114,     0,     0,   136,
     0,     0,   117,     0,   143,   144,     0,     0,     0,   103,
    17,     0,    19,     0,    18,     0,     0,    18,     0,     0,
     0,     0,     0,     0,     0,     0,    49,     0,   141,   140,
     0,   137,     0,   134,    26,   112,     0,   115,     0,    87,
    89,     0,   128,     0,     0,   131,     0,    95,    98,    97,
    99,    62,    64,    66,     0,     0,     0,   139,    28,     0,
     0,     0,    18,   126,    18,   129,    67,     0,   113,    27,
   116,     0,     0,     0,    65,   142,   127,   130,     0,     0,
     0
};

static const short yydefgoto[] = {   289,
    28,    29,    30,    31,   223,   224,    69,    70,    71,   244,
   245,    32,    63,    33,    52,    91,    92,    93,    34,    35,
    36,    37,    38,    39,    40,    67,    41,    42,    43,   106,
   117,    44,    45,    61,   118,   108,   109,   110,   111,   119,
   120,   121,   122,   158,   159,   160,   161,   123,   217
};

static const short yypact[] = {   241,
   435,   435,   435,    51,-32768,-32768,-32768,     7,    19,   286,
    40,    21,    45,-32768,-32768,    23,   435,-32768,-32768,-32768,
-32768,-32768,-32768,    63,-32768,   435,   286,    48,-32768,-32768,
-32768,   227,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   241,
-32768,   241,-32768,-32768,-32768,-32768,-32768,   521,-32768,-32768,
-32768,   -36,   435,   435,    70,   420,   331,   334,   337,-32768,
    55,   617,    53,-32768,-32768,   286,    46,   109,    69,    71,
-32768,   435,   435,   435,   435,   435,   435,   435,   435,   435,
   435,   435,-32768,-32768,    76,   286,-32768,-32768,    74,   435,
   104,   -28,-32768,   537,   553,   119,   107,   110,   105,    -6,
     1,   145,    82,   175,-32768,   130,   178,   178,-32768,-32768,
-32768,-32768,     2,    12,    98,-32768,   132,   474,   474,-32768,
-32768,-32768,-32768,   112,   136,-32768,   125,-32768,-32768,   435,
-32768,    48,   617,   509,   509,   199,   199,   199,   199,    32,
    32,-32768,-32768,   435,   617,-32768,    74,-32768,   286,   286,
   435,   435,   144,   435,   226,   134,    16,   128,   -14,-32768,
    44,   297,   142,    44,   147,   371,   371,-32768,   131,-32768,
   178,-32768,-32768,-32768,   378,   175,    44,   453,   175,    44,
   386,   386,-32768,   474,-32768,-32768,-32768,   386,   386,-32768,
-32768,   617,-32768,   617,   176,-32768,   569,   585,   435,   152,
   187,   188,    18,   175,-32768,   159,-32768,   134,   175,-32768,
   164,   198,-32768,   170,-32768,-32768,   203,   192,   194,-32768,
-32768,   204,   175,   189,   175,   223,   189,   175,   210,   211,
   212,   219,   286,   206,   286,   601,   435,    44,-32768,-32768,
   209,-32768,   213,   208,-32768,-32768,    44,-32768,   175,-32768,
-32768,    44,-32768,   189,    44,-32768,   189,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   286,   236,   215,-32768,-32768,   175,
   222,   228,   175,-32768,   175,-32768,-32768,   286,-32768,-32768,
-32768,   230,   189,   189,-32768,-32768,-32768,-32768,   278,   292,
-32768
};

static const short yypgoto[] = {-32768,
   -41,-32768,-32768,   -56,   190,   -80,-32768,-32768,   166,-32768,
    29,     5,   -52,-32768,-32768,-32768,-32768,   214,-32768,-32768,
-32768,-32768,   -10,  -211,    -4,-32768,   -32,   260,-32768,    24,
   -38,-32768,-32768,-32768,   -25,   195,  -103,-32768,-32768,   183,
  -110,-32768,-32768,   -73,-32768,   151,   -87,    10,-32768
};


#define	YYLAST		630


static const short yytable[] = {    55,
   105,   116,   116,    99,   173,    46,    47,    48,   186,    87,
   155,    89,   253,   164,    98,   256,    90,   162,   175,   147,
   125,    62,    66,    53,    90,   177,   180,   163,   178,    84,
    65,   107,   204,   208,   204,    54,   209,    86,   157,   176,
   179,   156,   274,    81,    82,   276,   157,   168,   156,   156,
   105,   172,    87,   157,   157,    84,    56,    94,    95,   156,
    62,   116,   185,   205,   157,   240,   112,   173,    57,   206,
    60,   287,   288,   186,    64,    84,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   211,    49,    50,
   214,   156,    58,    59,   145,    68,   157,    96,   227,    51,
   129,   200,   128,   225,   126,   127,   228,    12,    13,   105,
   105,   130,   221,   202,   172,   241,   112,   174,   131,   168,
   202,   132,   168,   146,   116,   116,   144,   185,   187,   166,
   167,   116,   116,   202,   192,   151,   202,   152,   195,   196,
   107,   107,   229,   230,   254,   181,   182,   257,   194,   231,
   232,     5,     6,     7,   154,   197,   198,   153,    62,   188,
   189,   165,   202,   170,   267,   183,   221,   243,   168,   190,
    15,   168,   191,   271,   199,   112,   112,   207,   273,    24,
   174,   275,   215,   216,   266,   220,   203,   100,   101,   218,
   219,   213,   283,   187,   284,     5,     6,     7,     5,     6,
     7,   237,   233,   236,   238,   239,   242,   272,    79,    80,
    81,    82,   102,   246,    15,   247,   168,    15,   168,   248,
   249,   252,   262,    24,   264,   250,    24,   251,   243,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
   255,    62,    27,   258,   259,   260,     5,     6,     7,   201,
     1,     2,   261,   278,   277,   263,   268,     3,   270,     4,
   269,     5,     6,     7,   279,    15,     8,   285,     9,    10,
    11,   281,    12,    13,    24,   282,    83,   290,    14,   286,
    15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
    25,   291,    26,   169,    27,     1,     2,   193,   280,    85,
   184,   171,     3,     0,     4,   148,     5,     6,     7,   210,
     0,     8,     0,     9,    10,    11,     0,     5,     6,     7,
   212,     0,     0,    14,     0,    15,    16,    17,    18,    19,
    20,    21,    22,    23,    24,    25,    15,    26,     0,    27,
   100,   101,     0,   113,   114,    24,   113,   114,     0,     0,
     0,     5,     6,     7,     5,     6,     7,     5,     6,     7,
     0,     0,     0,     0,     0,   102,     0,     0,   102,     0,
    15,   102,     0,    15,     0,     0,    15,     0,     0,    24,
   100,   101,    24,   103,   104,    24,   115,   104,     0,   124,
   104,     5,     6,     7,     0,   113,   114,     0,     5,     6,
     7,   222,     0,     0,     0,   102,     5,     6,     7,     0,
    15,     0,     0,     0,     0,     0,     0,    15,     0,    24,
   102,     0,     0,     0,   104,    15,    24,     0,     0,     1,
     2,     0,     0,     0,    24,     0,     3,     0,     4,   104,
     5,     6,     7,     0,     1,     2,     0,     0,     0,     0,
     0,     3,     0,     4,     0,     0,     0,    14,     0,    15,
     0,     0,    18,    19,    20,    21,    22,    97,    24,     0,
     0,    26,    14,     5,     6,     7,   226,    18,    19,    20,
    21,    22,    23,   113,   114,     0,    26,     0,     0,     0,
     0,     0,    15,     0,     5,     6,     7,     0,     0,     0,
     0,    24,     0,     0,     0,     0,     0,     0,   102,     0,
     0,     0,     0,    15,    75,    76,    77,    78,    79,    80,
    81,    82,    24,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,     0,     0,     0,     0,    88,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     0,     0,     0,     0,   149,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,     0,     0,     0,     0,
   150,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,     0,     0,     0,     0,   234,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
     0,     0,   235,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,     0,     0,     0,     0,   265,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82
};

static const short yycheck[] = {    10,
    57,    58,    59,    56,   108,     1,     2,     3,   119,    42,
    17,    48,   224,   101,    56,   227,    53,    17,    17,    48,
    59,    17,    27,    17,    53,   113,   114,   101,    17,    40,
    26,    57,    17,    48,    17,    17,    51,    42,    53,   113,
   114,    48,   254,    12,    13,   257,    53,   104,    48,    48,
   107,   108,    85,    53,    53,    66,    17,    53,    54,    48,
    56,   118,   119,    48,    53,    48,    57,   171,    48,   157,
    48,   283,   284,   184,    12,    86,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,   161,    38,    39,
   164,    48,    48,    49,    90,    48,    53,    28,   179,    49,
    55,   154,    50,   177,    50,    51,   180,    32,    33,   166,
   167,     3,   169,   155,   171,   203,   107,   108,    50,   176,
   162,    51,   179,    20,   181,   182,    53,   184,   119,    48,
    49,   188,   189,   175,   130,    17,   178,    31,   149,   150,
   166,   167,   181,   182,   225,    48,    49,   228,   144,   188,
   189,    21,    22,    23,    50,   151,   152,    48,   154,    48,
    49,    17,   204,    34,   238,    34,   223,   209,   225,    34,
    40,   228,    48,   247,    31,   166,   167,    50,   252,    49,
   171,   255,    36,    37,   237,    55,    53,    10,    11,   166,
   167,    50,   273,   184,   275,    21,    22,    23,    21,    22,
    23,    50,    27,   199,    18,    18,    48,   249,    10,    11,
    12,    13,    35,    50,    40,    18,   273,    40,   275,    50,
    18,    18,   233,    49,   235,    34,    49,    34,   270,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
    18,   237,    54,    34,    34,    34,    21,    22,    23,    24,
    10,    11,    34,    18,   265,    50,    48,    17,    51,    19,
    48,    21,    22,    23,    50,    40,    26,   278,    28,    29,
    30,    50,    32,    33,    49,    48,    50,     0,    38,    50,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,     0,    52,   104,    54,    10,    11,   132,   270,    40,
   118,   107,    17,    -1,    19,    92,    21,    22,    23,   159,
    -1,    26,    -1,    28,    29,    30,    -1,    21,    22,    23,
    24,    -1,    -1,    38,    -1,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    40,    52,    -1,    54,
    10,    11,    -1,    10,    11,    49,    10,    11,    -1,    -1,
    -1,    21,    22,    23,    21,    22,    23,    21,    22,    23,
    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    35,    -1,
    40,    35,    -1,    40,    -1,    -1,    40,    -1,    -1,    49,
    10,    11,    49,    53,    54,    49,    53,    54,    -1,    53,
    54,    21,    22,    23,    -1,    10,    11,    -1,    21,    22,
    23,    24,    -1,    -1,    -1,    35,    21,    22,    23,    -1,
    40,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    49,
    35,    -1,    -1,    -1,    54,    40,    49,    -1,    -1,    10,
    11,    -1,    -1,    -1,    49,    -1,    17,    -1,    19,    54,
    21,    22,    23,    -1,    10,    11,    -1,    -1,    -1,    -1,
    -1,    17,    -1,    19,    -1,    -1,    -1,    38,    -1,    40,
    -1,    -1,    43,    44,    45,    46,    47,    48,    49,    -1,
    -1,    52,    38,    21,    22,    23,    24,    43,    44,    45,
    46,    47,    48,    10,    11,    -1,    52,    -1,    -1,    -1,
    -1,    -1,    40,    -1,    21,    22,    23,    -1,    -1,    -1,
    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
    -1,    -1,    -1,    40,     6,     7,     8,     9,    10,    11,
    12,    13,    49,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
    -1,    -1,    -1,    -1,    18,     3,     4,     5,     6,     7,
     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
    18,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    13,    -1,    -1,    -1,    -1,    18,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
    -1,    -1,    18,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    13
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
#line 136 "bison_rules_with_code.y"
{yyval.Program = root = Program_node::createProgramNode(yyvsp[0].Statement_list, NULL);;
    break;}
case 2:
#line 137 "bison_rules_with_code.y"
{yyval.Program = root = Program_node::createProgramNode(NULL, yyvsp[0].Class_statement_list);;
    break;}
case 3:
#line 138 "bison_rules_with_code.y"
{yyval.Program = root = Program_node::createProgramNode(yyvsp[-1].Statement_list, yyvsp[0].Class_statement_list);;
    break;}
case 4:
#line 139 "bison_rules_with_code.y"
{yyval.Program = root = Program_node::createProgramNode(yyvsp[0].Statement_list, yyvsp[-1].Class_statement_list);;
    break;}
case 5:
#line 143 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(INT_TYPE);;
    break;}
case 6:
#line 144 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(CHAR_TYPE);;
    break;}
case 7:
#line 145 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(FLOAT_TYPE);;
    break;}
case 8:
#line 146 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(ID_TYPE);;
    break;}
case 9:
#line 147 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-1].Identifier);;
    break;}
case 10:
#line 151 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromFloat(yyvsp[0].Float_constant);;
    break;}
case 11:
#line 152 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromInteger(yyvsp[0].Integer_constant);;
    break;}
case 12:
#line 155 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(STRING_CONSTANT_TYPE, yyvsp[0].String_constant);;
    break;}
case 13:
#line 156 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(CHAR_CONSTANT_TYPE, yyvsp[0].Char_constant);;
    break;}
case 14:
#line 157 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(NSSTRING_CONSTANT_TYPE, yyvsp[0].NSString_constant);;
    break;}
case 15:
#line 161 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Init_declarator_list);;
    break;}
case 16:
#line 164 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::createDeclarationListNode(yyvsp[0].Declaration);;
    break;}
case 17:
#line 165 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::addToDeclarationListNode(yyvsp[-1].Declaration_list, yyvsp[0].Declaration);;
    break;}
case 18:
#line 168 "bison_rules_with_code.y"
{yyval.Declaration_list = NULL;;
    break;}
case 19:
#line 169 "bison_rules_with_code.y"
{yyval.Declaration_list = yyvsp[0].Declaration_list;;
    break;}
case 20:
#line 172 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 21:
#line 173 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 22:
#line 176 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 23:
#line 177 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 24:
#line 180 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Identifier, NULL);;
    break;}
case 25:
#line 181 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 26:
#line 184 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::createParameterListNode(yyvsp[0].Parameter_declaration);;
    break;}
case 27:
#line 185 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::addToParameterListNode(yyvsp[-2].Parameter_list, yyvsp[0].Parameter_declaration);;
    break;}
case 28:
#line 188 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(yyvsp[-1].Type, yyvsp[0].Identifier);;
    break;}
case 29:
#line 193 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromIdentifier(yyvsp[0].Identifier);;
    break;}
case 30:
#line 194 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromLiteral(yyvsp[0].Literal);;
    break;}
case 31:
#line 195 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromNumericConstant(yyvsp[0].Numeric_constant);;
    break;}
case 32:
#line 196 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createSimpleExpressionNode(PRIORITY_EXPRESSION_TYPE, yyvsp[-1].Expression);;
    break;}
case 33:
#line 197 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSelf();;
    break;}
case 34:
#line 198 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSimpleExpression(MESSAGE_EXPRESSION_EXPRESSION_TYPE, yyvsp[0].Message_expression);;
    break;}
case 35:
#line 199 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UMINUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 36:
#line 200 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UPLUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 37:
#line 201 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UAMPERSAND_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 38:
#line 202 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(PLUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 39:
#line 203 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MINUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 40:
#line 204 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MUL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 41:
#line 205 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(DIV_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 42:
#line 206 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 43:
#line 207 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(NOT_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 44:
#line 208 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 45:
#line 209 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 46:
#line 210 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 47:
#line 211 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 48:
#line 212 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(ASSIGNMENT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 49:
#line 215 "bison_rules_with_code.y"
{yyval.Expression = NULL;;
    break;}
case 50:
#line 216 "bison_rules_with_code.y"
{yyval.Expression = yyvsp[0].Expression;;
    break;}
case 51:
#line 219 "bison_rules_with_code.y"
{yyval.Message_expression = Message_expression_node::createMessageExpressionNode(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 52:
#line 222 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);;
    break;}
case 53:
#line 223 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);;
    break;}
case 54:
#line 224 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(CLASS_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 55:
#line 227 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[0].Identifier, NULL);;
    break;}
case 56:
#line 228 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(NULL, yyvsp[0].Keyword_argument_list);;
    break;}
case 57:
#line 231 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::createKeywordArgumentListNode(yyvsp[0].Keyword_argument);;
    break;}
case 58:
#line 232 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::addToKeywordArgumentListNode(yyvsp[-1].Keyword_argument_list, yyvsp[0].Keyword_argument);;
    break;}
case 59:
#line 235 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITH_IDENTIFIER_KW_ARGUMENT_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 60:
#line 236 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 61:
#line 240 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITHOUT_ALTERNATIVE_IF_TYPE, yyvsp[-2].Expression, yyvsp[0].Statement, NULL);;
    break;}
case 62:
#line 241 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITH_ALTERNATIVE_IF_TYPE, yyvsp[-4].Expression, yyvsp[-2].Statement, yyvsp[0].Statement);;
    break;}
case 63:
#line 245 "bison_rules_with_code.y"
{yyval.While  = While_statement_node::createWhileStatementNode(yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 64:
#line 248 "bison_rules_with_code.y"
{yyval.Do_while = Do_while_statement_node::createDoWhileStatementNode(yyvsp[-2].Expression, yyvsp[-5].Statement);;
    break;}
case 65:
#line 251 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNode(yyvsp[-6].Expression, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 66:
#line 252 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 67:
#line 253 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, yyvsp[-5].Type, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 68:
#line 258 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);;
    break;}
case 69:
#line 259 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 70:
#line 260 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 71:
#line 261 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(IF_STATEMENT_TYPE, yyvsp[0].If);;
    break;}
case 72:
#line 262 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(WHILE_STATEMENT_TYPE, yyvsp[0].While);;
    break;}
case 73:
#line 263 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(DO_WHILE_STATEMENT_TYPE, yyvsp[0].Do_while);;
    break;}
case 74:
#line 264 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(FOR_STATEMENT_TYPE, yyvsp[0].For);;
    break;}
case 75:
#line 265 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(COMPOUND_STATEMENT_TYPE, yyvsp[0].Compound_statement);;
    break;}
case 76:
#line 266 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 77:
#line 267 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromClassDeclaration(yyvsp[0].Class_declaration_list);;
    break;}
case 78:
#line 270 "bison_rules_with_code.y"
{yyval.Compound_statement = Compound_statement_node::createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 79:
#line 273 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::createStatementListNode(yyvsp[0].Statement);;
    break;}
case 80:
#line 274 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::addToStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 81:
#line 277 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 82:
#line 278 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 83:
#line 281 "bison_rules_with_code.y"
{yyval.Class_statement = Class_statement_node::createClassStatementNodeFromInterface(yyvsp[0].Class_interface);;
    break;}
case 84:
#line 282 "bison_rules_with_code.y"
{yyval.Class_statement = Class_statement_node::createClassStatementNodeFromImplementation(yyvsp[0].Class_implementation);;
    break;}
case 85:
#line 285 "bison_rules_with_code.y"
{yyval.Class_statement_list = Class_statement_list_node::createClassStatementListNode(yyvsp[0].Class_statement);;
    break;}
case 86:
#line 286 "bison_rules_with_code.y"
{yyval.Class_statement_list = Class_statement_list_node::addToClassStatementListNode(yyvsp[-1].Class_statement_list, yyvsp[0].Class_statement);;
    break;}
case 87:
#line 290 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_statement);;
    break;}
case 88:
#line 291 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_statement);;
    break;}
case 89:
#line 292 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_statement);;
    break;}
case 90:
#line 295 "bison_rules_with_code.y"
{yyval.Interface_statement = Interface_statement_node::createInterfaceStatementNode(yyvsp[-1].Instance_variables, yyvsp[0].Interface_declaration_list);;
    break;}
case 91:
#line 296 "bison_rules_with_code.y"
{yyval.Interface_statement = Interface_statement_node::createInterfaceStatementNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 92:
#line 299 "bison_rules_with_code.y"
{yyval.Implementation_statement = Implementation_statement_node::createImplementationStatementNode(yyvsp[-1].Instance_variables, yyvsp[0].Implementation_definition_list);;
    break;}
case 93:
#line 300 "bison_rules_with_code.y"
{yyval.Implementation_statement = Implementation_statement_node::createImplementationStatementNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 94:
#line 303 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_statement);;
    break;}
case 95:
#line 304 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_statement);;
    break;}
case 96:
#line 305 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_statement);;
    break;}
case 97:
#line 306 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_statement);;
    break;}
case 98:
#line 307 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_statement);;
    break;}
case 99:
#line 308 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_statement);;
    break;}
case 100:
#line 311 "bison_rules_with_code.y"
{yyval.Class_declaration_list = Class_declaration_list_node::createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 101:
#line 314 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::createClassListNode(yyvsp[0].Identifier);;
    break;}
case 102:
#line 315 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::addToClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 103:
#line 318 "bison_rules_with_code.y"
{yyval.Instance_variables = Instance_variables_node::createInstanceVariablesNode(yyvsp[-1].Declaration_list);;
    break;}
case 104:
#line 321 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 105:
#line 322 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 106:
#line 323 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(yyvsp[0].Method_declaration);;
    break;}
case 107:
#line 324 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 108:
#line 325 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 109:
#line 326 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 110:
#line 329 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 111:
#line 330 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 112:
#line 333 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 113:
#line 334 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 114:
#line 335 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 115:
#line 338 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 116:
#line 339 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 117:
#line 340 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 118:
#line 343 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 119:
#line 344 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 120:
#line 345 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(yyvsp[0].Method_definition);;
    break;}
case 121:
#line 346 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 122:
#line 347 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 123:
#line 348 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addPropertyToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Property);;
    break;}
case 124:
#line 351 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 125:
#line 352 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 126:
#line 355 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 127:
#line 356 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 128:
#line 357 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 129:
#line 360 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 130:
#line 361 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 131:
#line 362 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 132:
#line 365 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL);;
    break;}
case 133:
#line 366 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(NULL, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 134:
#line 367 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(NULL, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_list);;
    break;}
case 135:
#line 370 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 136:
#line 371 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::addToKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 137:
#line 374 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 138:
#line 375 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 139:
#line 376 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 140:
#line 377 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 141:
#line 380 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(yyvsp[-1].Type);;
    break;}
case 142:
#line 383 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 143:
#line 386 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 144:
#line 387 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READWRITE_ATTRIBUTE_TYPE);;
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
#line 390 "bison_rules_with_code.y"


