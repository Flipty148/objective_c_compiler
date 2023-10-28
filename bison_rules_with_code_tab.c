
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



#define	YYFINAL		290
#define	YYFLAG		-32768
#define	YYNTBASE	56

#define YYTRANSLATE(x) ((unsigned)(x) <= 293 ? yytranslate[x] : 105)

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
    71,    73,    77,    79,    84,    87,    90,    93,    97,   101,
   105,   109,   113,   117,   121,   125,   129,   133,   137,   138,
   140,   142,   144,   146,   148,   150,   152,   155,   159,   162,
   168,   176,   182,   190,   200,   208,   217,   219,   222,   226,
   228,   230,   232,   234,   236,   238,   240,   244,   246,   249,
   250,   252,   254,   256,   258,   261,   268,   273,   280,   283,
   285,   288,   290,   295,   302,   307,   314,   321,   328,   332,
   334,   338,   342,   344,   346,   348,   351,   354,   357,   359,
   361,   366,   373,   377,   382,   389,   393,   395,   397,   399,
   402,   405,   408,   410,   412,   418,   426,   431,   437,   445,
   450,   452,   454,   458,   460,   463,   467,   470,   475,   479,
   483,   491,   493
};

static const short yyrhs[] = {    80,
     0,    83,     0,    80,    83,     0,    83,    80,     0,    21,
     0,    22,     0,    23,     0,    40,     0,    49,    12,     0,
    46,     0,    43,     0,    44,     0,    45,     0,    47,     0,
    57,    63,    50,     0,    60,     0,    61,    60,     0,     0,
    61,     0,     0,    64,     0,    65,     0,    64,    51,    65,
     0,    48,     0,    48,     3,    68,     0,    67,     0,    66,
    51,    67,     0,    57,    48,     0,    48,     0,    59,     0,
    58,     0,    17,    68,    18,     0,    38,     0,    19,    70,
    71,    20,     0,    11,    68,     0,    10,    68,     0,    52,
    68,     0,    68,    10,    68,     0,    68,    11,    68,     0,
    68,    12,    68,     0,    68,    13,    68,     0,    68,     4,
    68,     0,    68,     5,    68,     0,    68,     7,    68,     0,
    68,     6,    68,     0,    68,     8,    68,     0,    68,     9,
    68,     0,    68,     3,    68,     0,     0,    68,     0,    39,
     0,    38,     0,    49,     0,    48,     0,    72,     0,    73,
     0,    72,    73,     0,    48,    53,    68,     0,    53,    68,
     0,    26,    17,    68,    18,    78,     0,    26,    17,    68,
    18,    78,    27,    78,     0,    28,    17,    68,    18,    78,
     0,    29,    78,    28,    17,    68,    18,    50,     0,    30,
    17,    69,    50,    69,    50,    69,    18,    78,     0,    30,
    17,    48,    31,    68,    18,    78,     0,    30,    17,    57,
    48,    31,    68,    18,    78,     0,    50,     0,    68,    50,
     0,    42,    69,    50,     0,    74,     0,    75,     0,    76,
     0,    77,     0,    79,     0,    60,     0,    88,     0,    54,
    81,    55,     0,    78,     0,    80,    78,     0,     0,    80,
     0,    84,     0,    87,     0,    82,     0,    83,    82,     0,
    32,    48,    53,    48,    85,    34,     0,    32,    48,    85,
    34,     0,    32,    48,    53,    49,    85,    34,     0,    90,
    91,     0,    91,     0,    90,    95,     0,    95,     0,    33,
    48,    86,    34,     0,    33,    48,    53,    48,    86,    34,
     0,    33,    49,    86,    34,     0,    33,    49,    53,    48,
    86,    34,     0,    33,    48,    53,    49,    86,    34,     0,
    33,    49,    53,    49,    86,    34,     0,    41,    89,    50,
     0,    48,     0,    89,    51,    48,     0,    54,    61,    55,
     0,    60,     0,   103,     0,    92,     0,    91,    60,     0,
    91,    92,     0,    91,   103,     0,    93,     0,    94,     0,
    10,   102,    99,    50,     0,    10,    17,    24,    18,    99,
    50,     0,    10,    99,    50,     0,    11,   102,    99,    50,
     0,    11,    17,    24,    18,    99,    50,     0,    11,    99,
    50,     0,    60,     0,   103,     0,    96,     0,    95,    60,
     0,    95,    96,     0,    95,   103,     0,    97,     0,    98,
     0,    10,   102,    99,    62,    79,     0,    10,    17,    24,
    18,    99,    62,    79,     0,    10,    99,    62,    79,     0,
    11,   102,    99,    62,    79,     0,    11,    17,    24,    18,
    99,    62,    79,     0,    11,    99,    62,    79,     0,    48,
     0,   100,     0,   100,    51,    66,     0,   101,     0,   100,
   101,     0,    53,   102,    48,     0,    53,    48,     0,    48,
    53,   102,    48,     0,    48,    53,    48,     0,    17,    57,
    18,     0,    35,    17,   104,    18,    57,    48,    50,     0,
    36,     0,    37,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   134,   135,   136,   137,   141,   142,   143,   144,   145,   149,
   150,   153,   154,   155,   159,   162,   163,   166,   167,   170,
   171,   174,   175,   178,   179,   182,   183,   186,   191,   192,
   193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
   203,   204,   205,   206,   207,   208,   209,   210,   213,   214,
   217,   218,   219,   222,   223,   226,   227,   230,   231,   235,
   236,   240,   243,   246,   247,   248,   253,   254,   255,   256,
   257,   258,   259,   260,   261,   262,   265,   268,   269,   272,
   273,   276,   277,   280,   281,   285,   286,   287,   290,   291,
   294,   295,   298,   299,   300,   301,   302,   303,   306,   309,
   310,   313,   316,   317,   318,   319,   320,   321,   324,   325,
   328,   329,   330,   333,   334,   335,   338,   339,   340,   341,
   342,   343,   346,   347,   350,   351,   352,   355,   356,   357,
   360,   361,   362,   365,   366,   369,   370,   371,   372,   375,
   378,   381,   382
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
"expression","expression_e","receiver","message_selector","keyword_argument_list",
"keyword_argument","if_statement","while_statement","do_while_statement","for_statement",
"statement","compound_statement","statement_list","statement_list_e","class_statement",
"class_statement_list","class_interface","interface_statement","implementation_statement",
"class_implementation","class_declaration_list","class_list","instance_variables",
"interface_declaration_list","method_declaration","class_method_declaration",
"instance_method_declaration","implementation_definition_list","method_definition",
"class_method_definition","instance_method_definition","method_selector","keyword_selector",
"keyword_declaration","method_type","property","attribute",""
};
#endif

static const short yyr1[] = {     0,
    56,    56,    56,    56,    57,    57,    57,    57,    57,    58,
    58,    59,    59,    59,    60,    61,    61,    62,    62,    63,
    63,    64,    64,    65,    65,    66,    66,    67,    68,    68,
    68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
    68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
    70,    70,    70,    71,    71,    72,    72,    73,    73,    74,
    74,    75,    76,    77,    77,    77,    78,    78,    78,    78,
    78,    78,    78,    78,    78,    78,    79,    80,    80,    81,
    81,    82,    82,    83,    83,    84,    84,    84,    85,    85,
    86,    86,    87,    87,    87,    87,    87,    87,    88,    89,
    89,    90,    91,    91,    91,    91,    91,    91,    92,    92,
    93,    93,    93,    94,    94,    94,    95,    95,    95,    95,
    95,    95,    96,    96,    97,    97,    97,    98,    98,    98,
    99,    99,    99,   100,   100,   101,   101,   101,   101,   102,
   103,   104,   104
};

static const short yyr2[] = {     0,
     1,     1,     2,     2,     1,     1,     1,     1,     2,     1,
     1,     1,     1,     1,     3,     1,     2,     0,     1,     0,
     1,     1,     3,     1,     3,     1,     3,     2,     1,     1,
     1,     3,     1,     4,     2,     2,     2,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     0,     1,
     1,     1,     1,     1,     1,     1,     2,     3,     2,     5,
     7,     5,     7,     9,     7,     8,     1,     2,     3,     1,
     1,     1,     1,     1,     1,     1,     3,     1,     2,     0,
     1,     1,     1,     1,     2,     6,     4,     6,     2,     1,
     2,     1,     4,     6,     4,     6,     6,     6,     3,     1,
     3,     3,     1,     1,     1,     2,     2,     2,     1,     1,
     4,     6,     3,     4,     6,     3,     1,     1,     1,     2,
     2,     2,     1,     1,     5,     7,     4,     5,     7,     4,
     1,     1,     3,     1,     2,     3,     2,     4,     3,     3,
     7,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     5,     6,     7,     0,     0,     0,
     0,     0,     0,    33,     8,     0,    49,    11,    12,    13,
    10,    14,    29,     0,    67,     0,    80,    20,    31,    30,
    75,     0,    70,    71,    72,    73,    78,    74,     1,    84,
     2,    82,    83,    76,    36,    35,     0,    52,    51,    53,
     0,     0,     0,     0,    49,     0,     0,     0,   100,     0,
    50,     0,     9,    37,    81,     0,    24,     0,    21,    22,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    68,    79,     3,     4,    85,    32,    54,     0,     0,
    55,    56,     0,     0,     0,    29,     0,     0,     0,     0,
     0,     0,     0,   103,     0,     0,    90,   105,   109,   110,
   104,     0,     0,     0,   117,     0,     0,    92,   119,   123,
   124,   118,     0,     0,    99,     0,    69,    77,     0,    15,
     0,    48,    42,    43,    45,    44,    46,    47,    38,    39,
    40,    41,     0,    59,    34,     0,    57,     0,     0,     0,
     0,     0,    49,     0,   131,     0,     0,   132,   134,     0,
     0,     0,     0,     0,     0,     0,    16,     0,    87,    89,
   106,   107,   108,     0,    18,     0,     0,    18,     0,     0,
     0,    93,    91,   120,   121,   122,     0,     0,    95,   101,
    25,    23,    58,    60,    62,     0,     0,     0,     0,     0,
     0,     0,     0,   137,     0,   113,     0,     0,   135,     0,
     0,   116,     0,   142,   143,     0,     0,     0,   102,    17,
     0,    19,     0,    18,     0,     0,    18,     0,     0,     0,
     0,     0,     0,     0,     0,    49,     0,   140,   139,     0,
   136,     0,   133,    26,   111,     0,   114,     0,    86,    88,
     0,   127,     0,     0,   130,     0,    94,    97,    96,    98,
    61,    63,    65,     0,     0,     0,   138,    28,     0,     0,
     0,    18,   125,    18,   128,    66,     0,   112,    27,   115,
     0,     0,     0,    64,   141,   126,   129,     0,     0,     0
};

static const short yydefgoto[] = {   288,
    28,    29,    30,    31,   222,   223,    68,    69,    70,   243,
   244,    32,    62,    51,    90,    91,    92,    33,    34,    35,
    36,    37,    38,    39,    66,    40,    41,    42,   105,   116,
    43,    44,    60,   117,   107,   108,   109,   110,   118,   119,
   120,   121,   157,   158,   159,   160,   122,   216
};

static const short yypact[] = {   236,
   430,   430,   430,    59,-32768,-32768,-32768,     3,     6,   281,
    25,     8,    -2,-32768,-32768,    57,   430,-32768,-32768,-32768,
-32768,-32768,-32768,    77,-32768,   430,   281,    64,-32768,-32768,
-32768,   189,-32768,-32768,-32768,-32768,-32768,-32768,   236,-32768,
   236,-32768,-32768,-32768,-32768,-32768,   520,-32768,-32768,-32768,
   -27,   430,   430,    79,   415,   326,   329,   332,-32768,    41,
   616,    66,-32768,-32768,   281,    72,   128,   107,     2,-32768,
   430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
   430,-32768,-32768,    89,   281,-32768,-32768,    94,   430,   145,
    40,-32768,   536,   552,   151,   149,   136,   140,    -3,    11,
   187,    81,   165,-32768,   172,   469,   469,-32768,-32768,-32768,
-32768,    13,    19,    97,-32768,   173,   473,   473,-32768,-32768,
-32768,-32768,   111,   176,-32768,   170,-32768,-32768,   430,-32768,
    64,   616,   624,   624,   164,   164,   164,   164,   150,   150,
-32768,-32768,   430,   616,-32768,    94,-32768,   281,   281,   430,
   430,   181,   430,   130,   167,    21,   171,   -16,-32768,    56,
   212,   175,    56,   146,   366,   366,-32768,    -6,-32768,   469,
-32768,-32768,-32768,   292,   165,    56,   373,   165,    56,   381,
   381,-32768,   473,-32768,-32768,-32768,   381,   381,-32768,-32768,
   616,-32768,   616,   196,-32768,   568,   584,   430,   177,   210,
   211,    48,   165,-32768,   182,-32768,   167,   165,-32768,   188,
   213,-32768,   190,-32768,-32768,   219,   208,   209,-32768,-32768,
   226,   165,   191,   165,   230,   191,   165,   215,   216,   217,
   222,   281,   220,   281,   600,   430,    56,-32768,-32768,   223,
-32768,   224,   238,-32768,-32768,    56,-32768,   165,-32768,-32768,
    56,-32768,   191,    56,-32768,   191,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   281,   242,   225,-32768,-32768,   165,   237,
   245,   165,-32768,   165,-32768,-32768,   281,-32768,-32768,-32768,
   244,   191,   191,-32768,-32768,-32768,-32768,   263,   273,-32768
};

static const short yypgoto[] = {-32768,
   -37,-32768,-32768,   -55,   192,   -83,-32768,-32768,   166,-32768,
    27,     5,   -51,-32768,-32768,-32768,   214,-32768,-32768,-32768,
-32768,   -10,  -182,    -8,-32768,   -30,   260,-32768,    50,   -45,
-32768,-32768,-32768,   -47,   195,   -97,-32768,-32768,   200,  -113,
-32768,-32768,   -73,-32768,   148,   -88,    43,-32768
};


#define	YYLAST		637


static const short yytable[] = {    54,
   104,   115,   115,    98,   185,    45,    46,    47,   106,   172,
    86,   163,   124,   154,     5,     6,     7,    97,    65,    52,
    88,    61,    53,   176,   179,    89,   162,   161,    83,   174,
    64,   207,    85,    15,   208,   177,   156,   203,   175,   178,
   252,    55,    24,   255,   155,    57,    58,   167,   219,   156,
   104,   171,   131,    86,    83,    56,    93,    94,   155,    61,
   155,   115,   184,   156,   203,   156,   155,   205,   204,   185,
   273,   156,   172,   275,    83,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   210,   146,    63,   213,
   125,   126,    89,   144,   226,   239,    48,    49,   111,   286,
   287,   199,   224,   155,    59,   227,    95,    50,   156,   104,
   104,    67,   220,   240,   171,   127,   201,   106,   106,   167,
    12,    13,   167,   201,   115,   115,   128,   184,   165,   166,
   129,   115,   115,   191,   228,   229,   201,   194,   195,   201,
   253,   230,   231,   256,   180,   181,   143,   193,   111,   173,
     5,     6,     7,   200,   196,   197,   130,    61,   187,   188,
   186,    80,    81,   266,   145,   201,   220,   150,   167,    15,
   242,   167,   270,    78,    79,    80,    81,   272,    24,   151,
   274,   214,   215,   152,   265,     5,     6,     7,   282,   153,
   283,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,   235,   164,    15,   169,   182,   111,   111,   189,
   271,   198,   173,    24,   217,   218,   167,   190,   167,   202,
   206,   261,   232,   263,   212,   186,   236,   237,   238,   241,
   246,   242,     5,     6,     7,   211,   248,   245,    82,   247,
    61,   249,   250,   251,    27,     1,     2,   254,   257,   258,
   259,    15,     3,   276,     4,   260,     5,     6,     7,   277,
    24,     8,   289,     9,    10,    11,   284,    12,    13,   262,
   267,   268,   290,    14,   278,    15,    16,    17,    18,    19,
    20,    21,    22,    23,    24,    25,   280,    26,   269,    27,
     1,     2,   281,   285,   168,   279,   192,     3,    84,     4,
   170,     5,     6,     7,   147,   209,     8,     0,     9,    10,
    11,     0,     5,     6,     7,   221,   183,     0,    14,     0,
    15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
    25,    15,    26,     0,    27,    99,   100,     0,   112,   113,
    24,   112,   113,     0,     0,     0,     5,     6,     7,     5,
     6,     7,     5,     6,     7,     0,     0,     0,     0,     0,
   101,     0,     0,   101,     0,    15,   101,     0,    15,     0,
     0,    15,     0,     0,    24,    99,   100,    24,   102,   103,
    24,   114,   103,     0,   123,   103,     5,     6,     7,     0,
   112,   113,     0,     5,     6,     7,   225,     0,     0,     0,
   101,     5,     6,     7,     0,    15,     0,     0,     0,     0,
     0,     0,    15,     0,    24,   101,     0,     0,     0,   103,
    15,    24,     0,     0,     1,     2,     0,     0,     0,    24,
     0,     3,     0,     4,   103,     5,     6,     7,     0,     1,
     2,     0,     0,     0,     0,     0,     3,     0,     4,     0,
     0,     0,    14,     0,    15,     0,     0,    18,    19,    20,
    21,    22,    96,    24,     0,     0,    26,    14,     0,     0,
     0,     0,    18,    19,    20,    21,    22,    23,    99,   100,
     0,    26,   112,   113,     0,     0,     0,     0,     0,     5,
     6,     7,     0,     5,     6,     7,     0,     0,     0,     0,
     0,     0,     0,   101,     0,     0,     0,   101,    15,     0,
     0,     0,    15,     0,     0,     0,     0,    24,     0,     0,
     0,    24,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,     0,     0,     0,     0,    87,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
     0,     0,     0,   148,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,     0,     0,     0,     0,   149,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,     0,     0,     0,     0,   233,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
     0,   234,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,     0,     0,     0,     0,   264,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    74,
    75,    76,    77,    78,    79,    80,    81
};

static const short yycheck[] = {    10,
    56,    57,    58,    55,   118,     1,     2,     3,    56,   107,
    41,   100,    58,    17,    21,    22,    23,    55,    27,    17,
    48,    17,    17,   112,   113,    53,   100,    17,    39,    17,
    26,    48,    41,    40,    51,    17,    53,    17,   112,   113,
   223,    17,    49,   226,    48,    48,    49,   103,    55,    53,
   106,   107,    51,    84,    65,    48,    52,    53,    48,    55,
    48,   117,   118,    53,    17,    53,    48,   156,    48,   183,
   253,    53,   170,   256,    85,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,   160,    48,    12,   163,
    50,    51,    53,    89,   178,    48,    38,    39,    56,   282,
   283,   153,   176,    48,    48,   179,    28,    49,    53,   165,
   166,    48,   168,   202,   170,    50,   154,   165,   166,   175,
    32,    33,   178,   161,   180,   181,    55,   183,    48,    49,
     3,   187,   188,   129,   180,   181,   174,   148,   149,   177,
   224,   187,   188,   227,    48,    49,    53,   143,   106,   107,
    21,    22,    23,    24,   150,   151,    50,   153,    48,    49,
   118,    12,    13,   237,    20,   203,   222,    17,   224,    40,
   208,   227,   246,    10,    11,    12,    13,   251,    49,    31,
   254,    36,    37,    48,   236,    21,    22,    23,   272,    50,
   274,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    13,   198,    17,    40,    34,    34,   165,   166,    34,
   248,    31,   170,    49,   165,   166,   272,    48,   274,    53,
    50,   232,    27,   234,    50,   183,    50,    18,    18,    48,
    18,   269,    21,    22,    23,    24,    18,    50,    50,    50,
   236,    34,    34,    18,    54,    10,    11,    18,    34,    34,
    34,    40,    17,   264,    19,    34,    21,    22,    23,    18,
    49,    26,     0,    28,    29,    30,   277,    32,    33,    50,
    48,    48,     0,    38,    50,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    50,    52,    51,    54,
    10,    11,    48,    50,   103,   269,   131,    17,    39,    19,
   106,    21,    22,    23,    91,   158,    26,    -1,    28,    29,
    30,    -1,    21,    22,    23,    24,   117,    -1,    38,    -1,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    40,    52,    -1,    54,    10,    11,    -1,    10,    11,
    49,    10,    11,    -1,    -1,    -1,    21,    22,    23,    21,
    22,    23,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
    35,    -1,    -1,    35,    -1,    40,    35,    -1,    40,    -1,
    -1,    40,    -1,    -1,    49,    10,    11,    49,    53,    54,
    49,    53,    54,    -1,    53,    54,    21,    22,    23,    -1,
    10,    11,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
    35,    21,    22,    23,    -1,    40,    -1,    -1,    -1,    -1,
    -1,    -1,    40,    -1,    49,    35,    -1,    -1,    -1,    54,
    40,    49,    -1,    -1,    10,    11,    -1,    -1,    -1,    49,
    -1,    17,    -1,    19,    54,    21,    22,    23,    -1,    10,
    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    -1,
    -1,    -1,    38,    -1,    40,    -1,    -1,    43,    44,    45,
    46,    47,    48,    49,    -1,    -1,    52,    38,    -1,    -1,
    -1,    -1,    43,    44,    45,    46,    47,    48,    10,    11,
    -1,    52,    10,    11,    -1,    -1,    -1,    -1,    -1,    21,
    22,    23,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    35,    -1,    -1,    -1,    35,    40,    -1,
    -1,    -1,    40,    -1,    -1,    -1,    -1,    49,    -1,    -1,
    -1,    49,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    -1,    -1,    -1,    -1,    18,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
    -1,    -1,    -1,    18,     3,     4,     5,     6,     7,     8,
     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    -1,    -1,    -1,    -1,    18,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
    -1,    18,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    -1,    -1,    -1,    -1,    18,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,     6,
     7,     8,     9,    10,    11,    12,    13
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
#line 134 "bison_rules_with_code.y"
{yyval.Program = root = Program_node::createProgramNode(yyvsp[0].Statement_list, NULL);;
    break;}
case 2:
#line 135 "bison_rules_with_code.y"
{yyval.Program = root = Program_node::createProgramNode(NULL, yyvsp[0].Class_statement_list);;
    break;}
case 3:
#line 136 "bison_rules_with_code.y"
{yyval.Program = root = Program_node::createProgramNode(yyvsp[-1].Statement_list, yyvsp[0].Class_statement_list);;
    break;}
case 4:
#line 137 "bison_rules_with_code.y"
{yyval.Program = root = Program_node::createProgramNode(yyvsp[0].Statement_list, yyvsp[-1].Class_statement_list);;
    break;}
case 5:
#line 141 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(INT_TYPE);;
    break;}
case 6:
#line 142 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(CHAR_TYPE);;
    break;}
case 7:
#line 143 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(FLOAT_TYPE);;
    break;}
case 8:
#line 144 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(ID_TYPE);;
    break;}
case 9:
#line 145 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-1].Identifier);;
    break;}
case 10:
#line 149 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromFloat(yyvsp[0].Float_constant);;
    break;}
case 11:
#line 150 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromInteger(yyvsp[0].Integer_constant);;
    break;}
case 12:
#line 153 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(STRING_CONSTANT_TYPE, yyvsp[0].String_constant);;
    break;}
case 13:
#line 154 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(CHAR_CONSTANT_TYPE, yyvsp[0].Char_constant);;
    break;}
case 14:
#line 155 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(NSSTRING_CONSTANT_TYPE, yyvsp[0].NSString_constant);;
    break;}
case 15:
#line 159 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Init_declarator_list);;
    break;}
case 16:
#line 162 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::createDeclarationListNode(yyvsp[0].Declaration);;
    break;}
case 17:
#line 163 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::addToDeclarationListNode(yyvsp[-1].Declaration_list, yyvsp[0].Declaration);;
    break;}
case 18:
#line 166 "bison_rules_with_code.y"
{yyval.Declaration_list = NULL;;
    break;}
case 19:
#line 167 "bison_rules_with_code.y"
{yyval.Declaration_list = yyvsp[0].Declaration_list;;
    break;}
case 20:
#line 170 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 21:
#line 171 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 22:
#line 174 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 23:
#line 175 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 24:
#line 178 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Identifier, NULL);;
    break;}
case 25:
#line 179 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 26:
#line 182 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::createParameterListNode(yyvsp[0].Parameter_declaration);;
    break;}
case 27:
#line 183 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::addToParameterListNode(yyvsp[-2].Parameter_list, yyvsp[0].Parameter_declaration);;
    break;}
case 28:
#line 186 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(yyvsp[-1].Type, yyvsp[0].Identifier);;
    break;}
case 29:
#line 191 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromIdentifier(yyvsp[0].Identifier);;
    break;}
case 30:
#line 192 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromLiteral(yyvsp[0].Literal);;
    break;}
case 31:
#line 193 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromNumericConstant(yyvsp[0].Numeric_constant);;
    break;}
case 32:
#line 194 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createSimpleExpressionNode(PRIORITY_EXPRESSION_TYPE, yyvsp[-1].Expression);;
    break;}
case 33:
#line 195 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSelf();;
    break;}
case 34:
#line 196 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 35:
#line 197 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UMINUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 36:
#line 198 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UPLUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 37:
#line 199 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UAMPERSAND_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 38:
#line 200 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(PLUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 39:
#line 201 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MINUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 40:
#line 202 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MUL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 41:
#line 203 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(DIV_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 42:
#line 204 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 43:
#line 205 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(NOT_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 44:
#line 206 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 45:
#line 207 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 46:
#line 208 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 47:
#line 209 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 48:
#line 210 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(ASSIGNMENT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 49:
#line 213 "bison_rules_with_code.y"
{yyval.Expression = NULL;;
    break;}
case 50:
#line 214 "bison_rules_with_code.y"
{yyval.Expression = yyvsp[0].Expression;;
    break;}
case 51:
#line 217 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);;
    break;}
case 52:
#line 218 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);;
    break;}
case 53:
#line 219 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(CLASS_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 54:
#line 222 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[0].Identifier, NULL);;
    break;}
case 55:
#line 223 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(NULL, yyvsp[0].Keyword_argument_list);;
    break;}
case 56:
#line 226 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::createKeywordArgumentListNode(yyvsp[0].Keyword_argument);;
    break;}
case 57:
#line 227 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::addToKeywordArgumentListNode(yyvsp[-1].Keyword_argument_list, yyvsp[0].Keyword_argument);;
    break;}
case 58:
#line 230 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITH_IDENTIFIER_KW_ARGUMENT_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 59:
#line 231 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 60:
#line 235 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITHOUT_ALTERNATIVE_IF_TYPE, yyvsp[-2].Expression, yyvsp[0].Statement, NULL);;
    break;}
case 61:
#line 236 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITH_ALTERNATIVE_IF_TYPE, yyvsp[-4].Expression, yyvsp[-2].Statement, yyvsp[0].Statement);;
    break;}
case 62:
#line 240 "bison_rules_with_code.y"
{yyval.While  = While_statement_node::createWhileStatementNode(yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 63:
#line 243 "bison_rules_with_code.y"
{yyval.Do_while = Do_while_statement_node::createDoWhileStatementNode(yyvsp[-2].Expression, yyvsp[-5].Statement);;
    break;}
case 64:
#line 246 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNode(yyvsp[-6].Expression, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 65:
#line 247 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 66:
#line 248 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, yyvsp[-5].Type, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 67:
#line 253 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);;
    break;}
case 68:
#line 254 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 69:
#line 255 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 70:
#line 256 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(IF_STATEMENT_TYPE, yyvsp[0].If);;
    break;}
case 71:
#line 257 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(WHILE_STATEMENT_TYPE, yyvsp[0].While);;
    break;}
case 72:
#line 258 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(DO_WHILE_STATEMENT_TYPE, yyvsp[0].Do_while);;
    break;}
case 73:
#line 259 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(FOR_STATEMENT_TYPE, yyvsp[0].For);;
    break;}
case 74:
#line 260 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(COMPOUND_STATEMENT_TYPE, yyvsp[0].Compound_statement);;
    break;}
case 75:
#line 261 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 76:
#line 262 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromClassDeclaration(yyvsp[0].Class_declaration_list);;
    break;}
case 77:
#line 265 "bison_rules_with_code.y"
{yyval.Compound_statement = Compound_statement_node::createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 78:
#line 268 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::createStatementListNode(yyvsp[0].Statement);;
    break;}
case 79:
#line 269 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::addToStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 80:
#line 272 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 81:
#line 273 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 82:
#line 276 "bison_rules_with_code.y"
{yyval.Class_statement = Class_statement_node::createClassStatementNodeFromInterface(yyvsp[0].Class_interface);;
    break;}
case 83:
#line 277 "bison_rules_with_code.y"
{yyval.Class_statement = Class_statement_node::createClassStatementNodeFromImplementation(yyvsp[0].Class_implementation);;
    break;}
case 84:
#line 280 "bison_rules_with_code.y"
{yyval.Class_statement_list = Class_statement_list_node::createClassStatementListNode(yyvsp[0].Class_statement);;
    break;}
case 85:
#line 281 "bison_rules_with_code.y"
{yyval.Class_statement_list = Class_statement_list_node::addToClassStatementListNode(yyvsp[-1].Class_statement_list, yyvsp[0].Class_statement);;
    break;}
case 86:
#line 285 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_statement);;
    break;}
case 87:
#line 286 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_statement);;
    break;}
case 88:
#line 287 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_statement);;
    break;}
case 89:
#line 290 "bison_rules_with_code.y"
{yyval.Interface_statement = Interface_statement_node::createInterfaceStatementNode(yyvsp[-1].Instance_variables, yyvsp[0].Interface_declaration_list);;
    break;}
case 90:
#line 291 "bison_rules_with_code.y"
{yyval.Interface_statement = Interface_statement_node::createInterfaceStatementNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 91:
#line 294 "bison_rules_with_code.y"
{yyval.Implementation_statement = Implementation_statement_node::createImplementationStatementNode(yyvsp[-1].Instance_variables, yyvsp[0].Implementation_definition_list);;
    break;}
case 92:
#line 295 "bison_rules_with_code.y"
{yyval.Implementation_statement = Implementation_statement_node::createImplementationStatementNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 93:
#line 298 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_statement);;
    break;}
case 94:
#line 299 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_statement);;
    break;}
case 95:
#line 300 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_statement);;
    break;}
case 96:
#line 301 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_statement);;
    break;}
case 97:
#line 302 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_statement);;
    break;}
case 98:
#line 303 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_statement);;
    break;}
case 99:
#line 306 "bison_rules_with_code.y"
{yyval.Class_declaration_list = Class_declaration_list_node::createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 100:
#line 309 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::createClassListNode(yyvsp[0].Identifier);;
    break;}
case 101:
#line 310 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::addToClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 102:
#line 313 "bison_rules_with_code.y"
{yyval.Instance_variables = Instance_variables_node::createInstanceVariablesNode(yyvsp[-1].Declaration_list);;
    break;}
case 103:
#line 316 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 104:
#line 317 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 105:
#line 318 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(yyvsp[0].Method_declaration);;
    break;}
case 106:
#line 319 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 107:
#line 320 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 108:
#line 321 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 109:
#line 324 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 110:
#line 325 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 111:
#line 328 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 112:
#line 329 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 113:
#line 330 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 114:
#line 333 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 115:
#line 334 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 116:
#line 335 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 117:
#line 338 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 118:
#line 339 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 119:
#line 340 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(yyvsp[0].Method_definition);;
    break;}
case 120:
#line 341 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 121:
#line 342 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 122:
#line 343 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addPropertyToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Property);;
    break;}
case 123:
#line 346 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 124:
#line 347 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 125:
#line 350 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 126:
#line 351 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 127:
#line 352 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 128:
#line 355 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 129:
#line 356 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 130:
#line 357 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 131:
#line 360 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL);;
    break;}
case 132:
#line 361 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(NULL, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 133:
#line 362 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(NULL, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_list);;
    break;}
case 134:
#line 365 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 135:
#line 366 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::addToKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 136:
#line 369 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 137:
#line 370 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 138:
#line 371 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 139:
#line 372 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 140:
#line 375 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(yyvsp[-1].Type);;
    break;}
case 141:
#line 378 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 142:
#line 381 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 143:
#line 382 "bison_rules_with_code.y"
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
#line 385 "bison_rules_with_code.y"


