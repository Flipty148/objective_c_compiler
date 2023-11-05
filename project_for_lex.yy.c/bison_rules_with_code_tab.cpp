
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
#define	ARROW	265
#define	INT	266
#define	CHAR	267
#define	FLOAT	268
#define	VOID	269
#define	ENUM	270
#define	IF	271
#define	ELSE	272
#define	WHILE	273
#define	DO	274
#define	FOR	275
#define	IN	276
#define	INTERFACE	277
#define	IMPLEMENTATION	278
#define	END	279
#define	PROPERTY	280
#define	READONLY	281
#define	READWRITE	282
#define	SYNTHESIZE	283
#define	SELF	284
#define	SUPER	285
#define	ID	286
#define	CLASS	287
#define	RETURN	288
#define	INTEGER_CONSTANT	289
#define	STRING_CONSTANT	290
#define	CHAR_CONSTANT	291
#define	FLOAT_CONSTANT	292
#define	NSSTRING_CONSTANT	293
#define	IDENTIFIER	294
#define	CLASS_NAME	295

#line 1 "bison_rules_with_code.y"

	#include "classes_nodes.h"
	void yyerror(char const *s);
	extern int yylex(void);
	Program_node *root;

#line 9 "bison_rules_with_code.y"
typedef union {
	int Integer_constant;
	char *String_constant;
	char *Char_constant;
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
	Expression_list_node *Expression_list;
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
	Class_block_node *Class_block;
	Class_interface_node *Class_interface;
	Interface_body_node *Interface_body;
	Implementation_body_node *Implementation_body;
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
	Class_list_node *Class_list;
	Function_and_class_list_node *Function_and_class_list;
	Function_node *Function;
	Declarator_node *Declarator;
	Declarator_list_node *Declarator_list;
	Instance_variables_declaration_node *Instance_variables_declaration;
	Instance_variables_declaration_list_node *Instance_variables_declaration_list;
	Synthesize_node *Synthesize;
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



#define	YYFINAL		388
#define	YYFLAG		-32768
#define	YYNTBASE	59

#define YYTRANSLATE(x) ((unsigned)(x) <= 295 ? yytranslate[x] : 123)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    55,     2,    19,
    20,    12,    10,    52,    11,    17,    13,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    56,    51,     6,
     3,     7,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    53,     2,    54,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    57,     2,    58,     2,     2,     2,     2,     2,
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
     9,    14,    15,    16,    18,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     6,     8,    11,    14,    17,    23,    25,
    27,    29,    31,    33,    35,    37,    39,    41,    45,    49,
    51,    54,    55,    57,    58,    60,    62,    66,    68,    72,
    74,    77,    79,    83,    85,    89,    91,    95,    97,   101,
   102,   104,   106,   110,   113,   117,   119,   121,   123,   127,
   129,   131,   136,   141,   144,   147,   150,   154,   158,   162,
   166,   170,   174,   178,   182,   186,   190,   194,   198,   202,
   203,   205,   206,   208,   210,   214,   216,   218,   220,   222,
   227,   229,   234,   241,   242,   244,   246,   249,   253,   256,
   262,   270,   276,   284,   294,   305,   317,   325,   335,   337,
   340,   344,   346,   348,   350,   352,   354,   356,   360,   362,
   365,   366,   368,   370,   372,   379,   384,   391,   398,   403,
   410,   411,   413,   416,   418,   419,   421,   424,   426,   431,
   438,   443,   450,   457,   464,   468,   470,   474,   478,   479,
   481,   485,   489,   491,   494,   496,   498,   500,   503,   506,
   509,   514,   521,   525,   530,   537,   541,   543,   545,   547,
   550,   553,   556,   562,   570,   575,   581,   589,   594,   596,
   601,   608,   609,   611,   613,   616,   619,   621,   625,   628,
   633,   637,   641,   646,   652,   659,   660,   663,   667,   671
};

static const short yyrhs[] = {    60,
     0,    97,     0,    61,     0,   104,     0,    60,    97,     0,
    60,    61,     0,    60,   104,     0,    62,    49,    19,    20,
    94,     0,    21,     0,    22,     0,    23,     0,    41,     0,
    47,     0,    44,     0,    45,     0,    46,     0,    48,     0,
    62,    68,    51,     0,    50,    77,    51,     0,    65,     0,
    66,    65,     0,     0,    66,     0,     0,    69,     0,    70,
     0,    69,    52,    70,     0,    71,     0,    71,     3,    80,
     0,    49,     0,    12,    49,     0,    72,     0,    73,    52,
    72,     0,    71,     0,    74,    52,    71,     0,    72,     0,
    72,     3,    80,     0,    75,     0,    76,    52,    75,     0,
     0,    76,     0,    79,     0,    78,    52,    79,     0,    62,
    49,     0,    50,    12,    49,     0,    49,     0,    64,     0,
    63,     0,    19,    80,    20,     0,    39,     0,    40,     0,
    53,    84,    85,    54,     0,    49,    19,    82,    20,     0,
    11,    80,     0,    10,    80,     0,    55,    80,     0,    80,
    10,    80,     0,    80,    11,    80,     0,    80,    12,    80,
     0,    80,    13,    80,     0,    80,     4,    80,     0,    80,
     5,    80,     0,    80,     7,    80,     0,    80,     6,    80,
     0,    80,     8,    80,     0,    80,     9,    80,     0,    80,
     3,    80,     0,    80,    17,    49,     0,    80,    18,    49,
     0,     0,    80,     0,     0,    83,     0,    80,     0,    83,
    52,    80,     0,    40,     0,    39,     0,    49,     0,    50,
     0,    53,    84,    85,    54,     0,    49,     0,    49,    56,
    80,    86,     0,    49,    56,    80,    86,    52,    83,     0,
     0,    87,     0,    88,     0,    87,    88,     0,    49,    56,
    80,     0,    56,    80,     0,    26,    19,    80,    20,    93,
     0,    26,    19,    80,    20,    93,    27,    93,     0,    28,
    19,    80,    20,    93,     0,    29,    93,    28,    19,    80,
    20,    51,     0,    30,    19,    81,    51,    81,    51,    81,
    20,    93,     0,    30,    19,    62,    68,    51,    81,    51,
    81,    20,    93,     0,    30,    19,    50,    12,    68,    51,
    81,    51,    81,    20,    93,     0,    30,    19,    49,    31,
    80,    20,    93,     0,    30,    19,    50,    12,    49,    31,
    80,    20,    93,     0,    51,     0,    80,    51,     0,    43,
    81,    51,     0,    89,     0,    90,     0,    91,     0,    92,
     0,    94,     0,    65,     0,    57,    96,    58,     0,    93,
     0,    95,    93,     0,     0,    95,     0,    98,     0,   103,
     0,    32,    49,    56,    49,    99,    34,     0,    32,    49,
    99,    34,     0,    32,    49,    56,    50,    99,    34,     0,
    32,    50,    56,    49,    99,    34,     0,    32,    50,    99,
    34,     0,    32,    50,    56,    50,    99,    34,     0,     0,
   100,     0,   106,   110,     0,   110,     0,     0,   102,     0,
   106,   112,     0,   112,     0,    33,    49,   101,    34,     0,
    33,    49,    56,    49,   101,    34,     0,    33,    50,   101,
    34,     0,    33,    50,    56,    49,   101,    34,     0,    33,
    49,    56,    50,   101,    34,     0,    33,    50,    56,    50,
   101,    34,     0,    42,   105,    51,     0,    49,     0,   105,
    52,    49,     0,    57,   107,    58,     0,     0,   109,     0,
    62,    74,    51,     0,    50,    73,    51,     0,   108,     0,
   109,   108,     0,    65,     0,   120,     0,   111,     0,   110,
    65,     0,   110,   111,     0,   110,   120,     0,    10,   119,
   114,    51,     0,    10,    19,    24,    20,   114,    51,     0,
    10,   114,    51,     0,    11,   119,   114,    51,     0,    11,
    19,    24,    20,   114,    51,     0,    11,   114,    51,     0,
    65,     0,   122,     0,   113,     0,   112,    65,     0,   112,
   122,     0,   112,   113,     0,    10,   119,   114,    67,    94,
     0,    10,    19,    24,    20,   114,    67,    94,     0,    10,
   114,    67,    94,     0,    11,   119,   114,    67,    94,     0,
    11,    19,    24,    20,   114,    67,    94,     0,    11,   114,
    67,    94,     0,    49,     0,    49,    56,   117,   115,     0,
    49,    56,   117,   115,    52,    78,     0,     0,   116,     0,
   118,     0,   116,   118,     0,   119,    49,     0,    49,     0,
    56,   119,    49,     0,    56,    49,     0,    49,    56,   119,
    49,     0,    49,    56,    49,     0,    19,    62,    20,     0,
    19,    50,    12,    20,     0,    35,   121,    62,    49,    51,
     0,    35,   121,    50,    12,    49,    51,     0,     0,    19,
    20,     0,    19,    36,    20,     0,    19,    37,    20,     0,
    38,    49,    51,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   152,   155,   156,   157,   158,   159,   160,   165,   169,   170,
   171,   172,   176,   177,   180,   181,   182,   186,   187,   190,
   191,   194,   195,   198,   199,   202,   203,   206,   207,   210,
   213,   216,   217,   219,   220,   223,   224,   227,   228,   231,
   232,   235,   236,   239,   240,   245,   246,   247,   248,   249,
   250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
   260,   261,   262,   263,   264,   265,   266,   267,   268,   271,
   272,   275,   276,   279,   280,   283,   284,   285,   286,   287,
   290,   291,   292,   295,   296,   299,   300,   303,   304,   308,
   309,   313,   316,   319,   320,   321,   322,   323,   328,   329,
   330,   331,   332,   333,   334,   335,   336,   339,   342,   343,
   346,   347,   350,   351,   355,   356,   357,   358,   359,   360,
   363,   364,   367,   368,   371,   372,   375,   376,   379,   380,
   381,   382,   383,   384,   387,   390,   391,   394,   397,   398,
   401,   402,   405,   406,   409,   410,   411,   412,   413,   414,
   417,   418,   419,   420,   421,   422,   425,   426,   427,   428,
   429,   430,   433,   434,   435,   436,   437,   438,   441,   442,
   443,   446,   447,   450,   451,   454,   455,   458,   459,   460,
   461,   464,   465,   468,   469,   472,   473,   474,   475,   478
};

static const char * const yytname[] = {   "$","error","$undefined.","'='","EQUAL",
"NOT_EQUAL","'<'","'>'","LESS_EQUAL","GREATER_EQUAL","'+'","'-'","'*'","'/'",
"UMINUS","UPLUS","UAMPERSAND","'.'","ARROW","'('","')'","INT","CHAR","FLOAT",
"VOID","ENUM","IF","ELSE","WHILE","DO","FOR","IN","INTERFACE","IMPLEMENTATION",
"END","PROPERTY","READONLY","READWRITE","SYNTHESIZE","SELF","SUPER","ID","CLASS",
"RETURN","INTEGER_CONSTANT","STRING_CONSTANT","CHAR_CONSTANT","FLOAT_CONSTANT",
"NSSTRING_CONSTANT","IDENTIFIER","CLASS_NAME","';'","','","'['","']'","'&'",
"':'","'{'","'}'","program","function_and_class_list","function","type","numeric_constant",
"literal","declaration","declaration_list","declaration_list_e","init_declarator_list_e",
"init_declarator_list","init_declarator","declarator","declarator_with_asterisk",
"declarator_with_asterisk_list","declarator_list","init_declarator_with_asterisk",
"init_declarator_with_asterisk_list","init_declarator_with_asterisk_list_e",
"parameter_list","parameter_declaration","expression","expression_e","expression_list_e",
"expression_list","receiver","message_selector","keyword_argument_list_e","keyword_argument_list",
"keyword_argument","if_statement","while_statement","do_while_statement","for_statement",
"statement","compound_statement","statement_list","statement_list_e","class_block",
"class_interface","interface_body_e","interface_body","implementation_body_e",
"implementation_body","class_implementation","class_declaration_list","class_list",
"instance_variables","instance_variables_declaration_list_e","instance_variables_declaration",
"instance_variables_declaration_list","interface_declaration_list","method_declaration",
"implementation_definition_list","method_definition","method_selector","keyword_selector_e",
"keyword_selector","keyword_declaration_without_identifier","keyword_declaration",
"method_type","property","attribute","synthesize",""
};
#endif

static const short yyr1[] = {     0,
    59,    60,    60,    60,    60,    60,    60,    61,    62,    62,
    62,    62,    63,    63,    64,    64,    64,    65,    65,    66,
    66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
    72,    73,    73,    74,    74,    75,    75,    76,    76,    77,
    77,    78,    78,    79,    79,    80,    80,    80,    80,    80,
    80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
    80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
    81,    82,    82,    83,    83,    84,    84,    84,    84,    84,
    85,    85,    85,    86,    86,    87,    87,    88,    88,    89,
    89,    90,    91,    92,    92,    92,    92,    92,    93,    93,
    93,    93,    93,    93,    93,    93,    93,    94,    95,    95,
    96,    96,    97,    97,    98,    98,    98,    98,    98,    98,
    99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
   103,   103,   103,   103,   104,   105,   105,   106,   107,   107,
   108,   108,   109,   109,   110,   110,   110,   110,   110,   110,
   111,   111,   111,   111,   111,   111,   112,   112,   112,   112,
   112,   112,   113,   113,   113,   113,   113,   113,   114,   114,
   114,   115,   115,   116,   116,   117,   117,   118,   118,   118,
   118,   119,   119,   120,   120,   121,   121,   121,   121,   122
};

static const short yyr2[] = {     0,
     1,     1,     1,     1,     2,     2,     2,     5,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
     2,     0,     1,     0,     1,     1,     3,     1,     3,     1,
     2,     1,     3,     1,     3,     1,     3,     1,     3,     0,
     1,     1,     3,     2,     3,     1,     1,     1,     3,     1,
     1,     4,     4,     2,     2,     2,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     0,
     1,     0,     1,     1,     3,     1,     1,     1,     1,     4,
     1,     4,     6,     0,     1,     1,     2,     3,     2,     5,
     7,     5,     7,     9,    10,    11,     7,     9,     1,     2,
     3,     1,     1,     1,     1,     1,     1,     3,     1,     2,
     0,     1,     1,     1,     6,     4,     6,     6,     4,     6,
     0,     1,     2,     1,     0,     1,     2,     1,     4,     6,
     4,     6,     6,     6,     3,     1,     3,     3,     0,     1,
     3,     3,     1,     2,     1,     1,     1,     2,     2,     2,
     4,     6,     3,     4,     6,     3,     1,     1,     1,     2,
     2,     2,     5,     7,     4,     5,     7,     4,     1,     4,
     6,     0,     1,     1,     2,     2,     1,     3,     2,     4,
     3,     3,     4,     5,     6,     0,     2,     3,     3,     3
};

static const short yydefact[] = {     0,
     9,    10,    11,     0,     0,    12,     0,     1,     3,     0,
     2,   113,   114,     4,   121,   121,   125,   125,   136,     0,
     6,     5,     7,     0,     0,     0,   186,    40,     0,   139,
    24,   145,     0,   122,     0,   124,   147,   146,     0,     0,
     0,     0,     0,     0,   157,     0,   126,     0,   128,   159,
   158,     0,     0,   135,     0,     0,     0,   169,     0,     0,
     0,     0,     0,     0,     0,     0,    36,    38,    41,     0,
   121,   121,     0,     0,     0,   143,   140,    30,     0,    25,
    26,    28,   116,   123,   148,   149,   150,   121,   121,   119,
     0,    22,     0,     0,    22,     0,     0,   125,   125,   129,
   127,   160,   162,   161,   125,   125,   131,   137,     0,     0,
     0,     0,     0,   153,     0,     0,   156,     0,   187,     0,
     0,     0,     0,    31,     0,     0,    19,     0,     0,    32,
     0,    34,     0,   138,   144,    18,     0,     0,     0,     0,
     0,    20,    23,     0,    22,     0,     0,    22,   190,     0,
     0,     0,     0,   111,     8,     0,     0,   182,     0,   177,
   172,     0,   151,     0,   154,   188,   189,     0,     0,     0,
     0,     0,    50,    51,    14,    15,    16,    13,    17,    46,
     0,     0,    48,    47,    37,    39,   115,   117,   142,     0,
   141,     0,    27,    29,   118,   120,     0,    21,   165,     0,
     0,   168,     0,   130,   133,   132,   134,     0,     0,     0,
     0,    70,    99,   107,     0,   102,   103,   104,   105,   109,
   106,   112,     0,     0,   183,     0,     0,   170,   173,   174,
   176,     0,     0,   184,    55,    54,     0,    72,    77,    76,
    78,    79,     0,     0,    56,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    33,    35,
    22,   163,    22,   166,     0,     0,     0,    70,    71,     0,
   100,   110,   108,   152,     0,   179,     0,     0,   175,   155,
   185,    49,    74,     0,    73,     0,    81,     0,    67,    61,
    62,    64,    63,    65,    66,    57,    58,    59,    60,    68,
    69,     0,     0,     0,     0,     0,    46,     0,    24,     0,
   101,   181,     0,   178,     0,     0,   171,    42,    53,     0,
     0,     0,    52,   164,   167,     0,     0,     0,     0,    24,
     0,    70,   180,     0,    44,     0,    75,    80,    84,    90,
    92,     0,     0,    30,     0,    70,     0,    45,    43,     0,
     0,    82,    85,    86,     0,     0,     0,     0,    70,     0,
    70,     0,    89,     0,    87,    91,    93,    97,     0,     0,
    70,     0,    88,    83,     0,    70,     0,     0,    98,     0,
     0,    94,     0,    95,    96,     0,     0,     0
};

static const short yydefgoto[] = {   386,
     8,     9,    31,   183,   184,   214,   143,   144,    79,    80,
    81,    82,    67,   131,   133,    68,    69,    70,   317,   318,
   215,   270,   284,   285,   244,   288,   352,   353,   354,   216,
   217,   218,   219,   220,   221,   222,   223,    11,    12,    33,
    34,    46,    47,    13,    14,    20,    35,    75,    76,    77,
    36,    37,    49,    50,    59,   228,   229,   161,   230,    60,
    38,    65,    51
};

static const short yypact[] = {   232,
-32768,-32768,-32768,   -22,    24,-32768,   -20,   232,-32768,   -17,
-32768,-32768,-32768,-32768,   364,   367,   168,   372,-32768,    44,
-32768,-32768,-32768,    16,    -9,    -6,    35,    59,    52,   171,
    27,-32768,    53,-32768,   160,   160,-32768,-32768,   112,    73,
    -4,     4,    29,   115,-32768,    75,-32768,   421,   421,-32768,
-32768,   135,    77,-32768,    43,    98,   299,    78,    87,   100,
   329,   107,   100,    14,   207,   119,   169,-32768,   134,   146,
    58,    58,    59,    27,   144,-32768,   171,-32768,   156,   174,
-32768,   220,-32768,   160,-32768,-32768,-32768,    58,    58,-32768,
   482,   476,   100,   486,   476,   100,   185,   415,   415,-32768,
   421,-32768,-32768,-32768,   415,   415,-32768,-32768,   182,   221,
   230,   229,    17,-32768,   199,   238,-32768,   208,-32768,   240,
   242,   255,   223,-32768,   447,    59,-32768,   236,   241,-32768,
   136,-32768,   181,-32768,-32768,-32768,    27,   447,   243,   256,
   271,-32768,   476,   182,   476,   272,   182,   476,-32768,   273,
   274,   281,   282,   316,-32768,   100,   286,-32768,   490,-32768,
   -30,   227,-32768,   100,-32768,-32768,-32768,   268,   277,   447,
   447,   447,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   305,
   480,   447,-32768,-32768,   649,-32768,-32768,-32768,-32768,    59,
-32768,    27,-32768,   649,-32768,-32768,   100,-32768,-32768,   182,
   100,-32768,   182,-32768,-32768,-32768,-32768,   311,   314,   316,
   315,   447,-32768,-32768,   292,-32768,-32768,-32768,-32768,-32768,
-32768,   316,   283,   296,-32768,   298,    33,   306,   -30,-32768,
-32768,   297,   317,-32768,   202,   202,   541,   447,-32768,-32768,
-32768,-32768,   480,   323,   202,   447,   447,   447,   447,   447,
   447,   447,   447,   447,   447,   447,   327,   331,-32768,-32768,
   476,-32768,   476,-32768,   447,   447,   353,   429,   649,   333,
-32768,-32768,-32768,-32768,    41,-32768,   342,   493,-32768,-32768,
-32768,-32768,   649,   376,   340,   323,   341,   344,   649,   662,
   662,   301,   301,   301,   301,   133,   133,   202,   202,-32768,
-32768,   182,   182,   559,   577,   381,    18,   389,    27,   352,
-32768,-32768,   355,-32768,   394,   358,   357,-32768,-32768,   447,
   361,   447,-32768,-32768,-32768,   316,   316,   447,   447,   362,
   365,   447,-32768,   363,-32768,   493,   649,-32768,   276,   391,
-32768,   595,   613,   388,   379,   447,   382,-32768,-32768,   371,
   447,   383,   -18,-32768,   316,   390,   316,   447,   447,   395,
   447,   447,   649,   447,-32768,-32768,-32768,-32768,   631,   396,
   447,   414,   649,   340,   316,   447,   425,   316,-32768,   434,
   316,-32768,   316,-32768,-32768,   449,   455,-32768
};

static const short yypgoto[] = {-32768,
-32768,   452,     0,-32768,-32768,    68,-32768,   -86,  -297,-32768,
   324,   -71,   -57,-32768,-32768,   337,-32768,-32768,-32768,   128,
  -124,  -115,-32768,   103,   237,   195,-32768,-32768,   130,-32768,
-32768,-32768,-32768,  -112,  -103,-32768,-32768,   477,-32768,    48,
-32768,    49,-32768,-32768,   481,-32768,     7,-32768,   411,-32768,
   466,   -29,   442,   -45,   -21,-32768,-32768,-32768,   289,   -24,
   -14,-32768,   -38
};


#define	YYLAST		680


static const short yytable[] = {    10,
   185,    63,   132,   103,    62,   155,    86,    10,   147,    57,
   104,   331,    61,   194,    91,   130,    93,    96,   226,    92,
    95,    87,    94,    48,    48,   227,    15,    16,    19,    74,
   350,    24,   345,   119,    56,   159,   238,   351,   115,    58,
   199,   118,    58,   202,    58,   235,   236,   237,   329,   120,
   121,   159,    58,    64,    86,   103,   112,   245,   200,   159,
   112,   203,   104,    40,   123,   160,    53,    25,    26,    87,
    66,   145,    17,    18,   148,    78,    74,    97,     1,     2,
     3,   276,    32,    32,    45,    45,    83,   269,   162,   312,
   112,   108,    27,   112,    54,    55,   262,   267,     6,   264,
    71,    72,    32,    85,    48,    48,    90,    28,   100,   272,
   107,    48,    48,   283,    30,    45,   102,   109,   128,   129,
   260,   289,   290,   291,   292,   293,   294,   295,   296,   297,
   298,   299,   259,   113,   224,   139,   140,   114,    32,    32,
   304,   305,   232,   269,   255,   256,   150,   151,    58,   257,
   258,    85,   310,   152,   153,    32,    32,   117,   112,   142,
    88,    89,   142,    98,    99,    45,    45,   124,   102,    25,
    26,   125,    45,    45,   302,   261,   303,    41,    42,   263,
     1,     2,     3,   105,   106,   126,   189,   190,     1,     2,
     3,     1,     2,     3,    27,   337,   127,   339,   324,   325,
     6,   134,   277,   342,   343,    43,   136,   269,     6,    28,
   198,     6,   142,   340,   341,   142,   347,    28,   257,   258,
    73,   269,   138,    44,    30,   137,   363,     1,     2,     3,
   360,   191,   192,   369,   269,   149,   269,   373,   154,   283,
   156,   157,   366,   370,   368,   372,   269,     6,   158,   163,
   313,   269,     1,     2,     3,   377,   122,   164,   165,   166,
   380,   167,   379,     4,     5,   382,   168,   309,   384,   187,
   385,   169,     6,     7,   188,   231,   195,   316,   246,   247,
   248,   249,   250,   251,   252,   253,   254,   255,   256,   196,
   197,   201,   257,   258,   246,   247,   248,   249,   250,   251,
   252,   253,   254,   255,   256,   225,   204,   205,   257,   258,
   253,   254,   255,   256,   206,   207,   233,   257,   258,     1,
     2,     3,   110,   238,   350,   170,   171,   234,   142,   265,
   142,   351,   266,   268,   172,   316,     1,     2,     3,     6,
   273,   208,   271,   209,   210,   211,   274,   280,   111,     1,
     2,     3,   116,   275,   173,   174,     6,   278,   212,   175,
   176,   177,   178,   179,   180,    28,   213,   281,   181,     6,
   182,   287,   154,    25,    26,   300,    25,    26,   111,   301,
   306,    41,    42,   311,     1,     2,     3,     1,     2,     3,
   314,   320,     1,     2,     3,   319,   322,   323,    27,   328,
   330,    27,   332,   333,     6,   334,   335,     6,   336,    43,
   344,   348,     6,    28,   338,   346,    28,   355,   358,    29,
    30,    28,    39,    30,    41,    42,   362,    52,    30,   359,
    41,    42,   361,   378,   364,     1,     2,     3,   170,   171,
   367,     1,     2,     3,   381,   371,   376,   172,   387,     1,
     2,     3,    43,   383,   388,     6,   170,   171,    43,    21,
   193,     6,   186,   349,    28,   172,   374,   173,   174,     6,
    28,    30,   175,   176,   177,   178,   179,   307,   308,   286,
   321,   181,   365,   182,    22,   173,   174,   135,    23,   101,
   175,   176,   177,   178,   179,   180,     1,     2,     3,   181,
    84,   182,     1,     2,     3,   141,     1,     2,     3,   146,
     1,     2,     3,     1,     2,     3,     6,   279,   239,   240,
     0,     0,     6,     0,     0,    28,     6,     0,   241,   242,
     6,   111,   243,     6,     0,   111,     0,     0,     0,   111,
     0,     0,   315,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,     0,     0,     0,   257,   258,     0,
   282,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,     0,     0,     0,   257,   258,     0,   326,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     0,     0,     0,   257,   258,     0,   327,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,     0,     0,
     0,   257,   258,     0,   356,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,     0,     0,     0,   257,
   258,     0,   357,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,     0,     0,     0,   257,   258,     0,
   375,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,     0,     0,     0,   257,   258,   249,   250,   251,
   252,   253,   254,   255,   256,     0,     0,     0,   257,   258
};

static const short yycheck[] = {     0,
   125,    26,    74,    49,    26,   109,    36,     8,    95,    19,
    49,   309,    19,   138,    19,    73,    41,    42,    49,    41,
    42,    36,    19,    17,    18,    56,    49,    50,    49,    30,
    49,    49,   330,    20,    19,    19,    19,    56,    60,    49,
   144,    63,    49,   147,    49,   170,   171,   172,    31,    36,
    37,    19,    49,    19,    84,   101,    57,   182,   145,    19,
    61,   148,   101,    16,    65,    49,    18,    10,    11,    84,
    12,    93,    49,    50,    96,    49,    77,    49,    21,    22,
    23,    49,    15,    16,    17,    18,    34,   212,   113,    49,
    91,    49,    35,    94,    51,    52,   200,   210,    41,   203,
    49,    50,    35,    36,    98,    99,    34,    50,    34,   222,
    34,   105,   106,   238,    57,    48,    49,    20,    71,    72,
   192,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   190,    56,   156,    88,    89,    51,    71,    72,
   265,   266,   164,   268,    12,    13,    98,    99,    49,    17,
    18,    84,   268,   105,   106,    88,    89,    51,   159,    92,
    49,    50,    95,    49,    50,    98,    99,    49,   101,    10,
    11,     3,   105,   106,   261,   197,   263,    10,    11,   201,
    21,    22,    23,    49,    50,    52,    51,    52,    21,    22,
    23,    21,    22,    23,    35,   320,    51,   322,   302,   303,
    41,    58,   227,   328,   329,    38,    51,   332,    41,    50,
   143,    41,   145,   326,   327,   148,   332,    50,    17,    18,
    50,   346,     3,    56,    57,    52,   351,    21,    22,    23,
   346,    51,    52,   358,   359,    51,   361,   362,    57,   364,
    20,    12,   355,   359,   357,   361,   371,    41,    20,    51,
   275,   376,    21,    22,    23,   371,    50,    20,    51,    20,
   376,    20,   375,    32,    33,   378,    12,   268,   381,    34,
   383,    49,    41,    42,    34,    49,    34,   278,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    34,
    20,    20,    17,    18,     3,     4,     5,     6,     7,     8,
     9,    10,    11,    12,    13,    20,    34,    34,    17,    18,
    10,    11,    12,    13,    34,    34,    49,    17,    18,    21,
    22,    23,    24,    19,    49,    10,    11,    51,   261,    19,
   263,    56,    19,    19,    19,   336,    21,    22,    23,    41,
    58,    26,    51,    28,    29,    30,    51,    51,    50,    21,
    22,    23,    24,    56,    39,    40,    41,    52,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    51,    53,    41,
    55,    49,    57,    10,    11,    49,    10,    11,    50,    49,
    28,    10,    11,    51,    21,    22,    23,    21,    22,    23,
    49,    52,    21,    22,    23,    20,    56,    54,    35,    19,
    12,    35,    51,    49,    41,    12,    49,    41,    52,    38,
    49,    49,    41,    50,    54,    51,    50,    27,    31,    56,
    57,    50,    56,    57,    10,    11,    56,    56,    57,    51,
    10,    11,    51,    20,    52,    21,    22,    23,    10,    11,
    51,    21,    22,    23,    20,    51,    51,    19,     0,    21,
    22,    23,    38,    20,     0,    41,    10,    11,    38,     8,
   137,    41,   126,   336,    50,    19,   364,    39,    40,    41,
    50,    57,    44,    45,    46,    47,    48,    49,    50,   243,
   286,    53,   353,    55,     8,    39,    40,    77,     8,    48,
    44,    45,    46,    47,    48,    49,    21,    22,    23,    53,
    35,    55,    21,    22,    23,    24,    21,    22,    23,    24,
    21,    22,    23,    21,    22,    23,    41,   229,    39,    40,
    -1,    -1,    41,    -1,    -1,    50,    41,    -1,    49,    50,
    41,    50,    53,    41,    -1,    50,    -1,    -1,    -1,    50,
    -1,    -1,    50,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
    20,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
    -1,    -1,    -1,    17,    18,    -1,    20,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
    -1,    17,    18,    -1,    20,     3,     4,     5,     6,     7,
     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    17,
    18,    -1,    20,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
    20,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    13,    -1,    -1,    -1,    17,    18,     6,     7,     8,
     9,    10,    11,    12,    13,    -1,    -1,    -1,    17,    18
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
#line 152 "bison_rules_with_code.y"
{yyval.Program = root = Program_node::createProgramNode(yyvsp[0].Function_and_class_list);;
    break;}
case 2:
#line 155 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassBlock(yyvsp[0].Class_block);;
    break;}
case 3:
#line 156 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromFunction(yyvsp[0].Function);;
    break;}
case 4:
#line 157 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassDeclarationList(yyvsp[0].Class_declaration_list);;
    break;}
case 5:
#line 158 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassBlock(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_block);;
    break;}
case 6:
#line 159 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromFunction(yyvsp[-1].Function_and_class_list, yyvsp[0].Function);;
    break;}
case 7:
#line 160 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassDeclarationList(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_declaration_list);;
    break;}
case 8:
#line 165 "bison_rules_with_code.y"
{yyval.Function = Function_node::createFunctionNode(yyvsp[-4].Type, yyvsp[-3].Identifier, yyvsp[0].Compound_statement);;
    break;}
case 9:
#line 169 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(INT_TYPE);;
    break;}
case 10:
#line 170 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(CHAR_TYPE);;
    break;}
case 11:
#line 171 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(FLOAT_TYPE);;
    break;}
case 12:
#line 172 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(ID_TYPE);;
    break;}
case 13:
#line 176 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromFloat(yyvsp[0].Float_constant);;
    break;}
case 14:
#line 177 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromInteger(yyvsp[0].Integer_constant);;
    break;}
case 15:
#line 180 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(STRING_CONSTANT_TYPE, yyvsp[0].String_constant);;
    break;}
case 16:
#line 181 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(CHAR_CONSTANT_TYPE, yyvsp[0].Char_constant);;
    break;}
case 17:
#line 182 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(NSSTRING_CONSTANT_TYPE, yyvsp[0].NSString_constant);;
    break;}
case 18:
#line 186 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Init_declarator_list);;
    break;}
case 19:
#line 187 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Init_declarator_list);
    break;}
case 20:
#line 190 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::createDeclarationListNode(yyvsp[0].Declaration);;
    break;}
case 21:
#line 191 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::addToDeclarationListNode(yyvsp[-1].Declaration_list, yyvsp[0].Declaration);;
    break;}
case 22:
#line 194 "bison_rules_with_code.y"
{yyval.Declaration_list = NULL;;
    break;}
case 23:
#line 195 "bison_rules_with_code.y"
{yyval.Declaration_list = yyvsp[0].Declaration_list;;
    break;}
case 24:
#line 198 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 25:
#line 199 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 26:
#line 202 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 27:
#line 203 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 28:
#line 206 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Declarator, NULL);;
    break;}
case 29:
#line 207 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Declarator, yyvsp[0].Expression);;
    break;}
case 30:
#line 210 "bison_rules_with_code.y"
{yyval.Declarator = Declarator_node::createDeclaratorNode(yyvsp[0].Identifier);;
    break;}
case 31:
#line 213 "bison_rules_with_code.y"
{yyval.Declarator = Declarator_node::createDeclaratorNode(yyvsp[0].Identifier);;
    break;}
case 32:
#line 216 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Declarator);;
    break;}
case 33:
#line 217 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-2].Declarator_list, yyvsp[0].Declarator);;
    break;}
case 34:
#line 219 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Declarator);;
    break;}
case 35:
#line 220 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-2].Declarator_list,yyvsp[0].Declarator);;
    break;}
case 36:
#line 223 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Declarator, NULL);;
    break;}
case 37:
#line 224 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Declarator, yyvsp[0].Expression);;
    break;}
case 38:
#line 227 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 39:
#line 228 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 40:
#line 231 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 41:
#line 232 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 42:
#line 235 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::createParameterListNode(yyvsp[0].Parameter_declaration);;
    break;}
case 43:
#line 236 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::addToParameterListNode(yyvsp[-2].Parameter_list, yyvsp[0].Parameter_declaration);;
    break;}
case 44:
#line 239 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(yyvsp[-1].Type, yyvsp[0].Identifier);;
    break;}
case 45:
#line 240 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier),yyvsp[0].Identifier);;
    break;}
case 46:
#line 245 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromIdentifier(yyvsp[0].Identifier);;
    break;}
case 47:
#line 246 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromLiteral(yyvsp[0].Literal);;
    break;}
case 48:
#line 247 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromNumericConstant(yyvsp[0].Numeric_constant);;
    break;}
case 49:
#line 248 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSimpleExpression(PRIORITY_EXPRESSION_TYPE, yyvsp[-1].Expression);;
    break;}
case 50:
#line 249 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSelf();;
    break;}
case 51:
#line 250 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSuper();;
    break;}
case 52:
#line 251 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 53:
#line 252 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromFunctionCall(yyvsp[-3].Identifier, yyvsp[-1].Expression_list);;
    break;}
case 54:
#line 253 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UMINUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 55:
#line 254 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UPLUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 56:
#line 255 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UAMPERSAND_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 57:
#line 256 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(PLUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 58:
#line 257 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MINUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 59:
#line 258 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MUL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 60:
#line 259 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(DIV_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 61:
#line 260 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 62:
#line 261 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(NOT_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 63:
#line 262 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 64:
#line 263 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 65:
#line 264 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 66:
#line 265 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 67:
#line 266 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(ASSIGNMENT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 68:
#line 267 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMemberAccessOperator(DOT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Identifier);;
    break;}
case 69:
#line 268 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMemberAccessOperator(ARROW_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Identifier);;
    break;}
case 70:
#line 271 "bison_rules_with_code.y"
{yyval.Expression = NULL;;
    break;}
case 71:
#line 272 "bison_rules_with_code.y"
{yyval.Expression = yyvsp[0].Expression;;
    break;}
case 72:
#line 275 "bison_rules_with_code.y"
{yyval.Expression_list = NULL;;
    break;}
case 73:
#line 276 "bison_rules_with_code.y"
{yyval.Expression_list = yyvsp[0].Expression_list;;
    break;}
case 74:
#line 279 "bison_rules_with_code.y"
{yyval.Expression_list = Expression_list_node::createExpressionListNode(yyvsp[0].Expression);;
    break;}
case 75:
#line 280 "bison_rules_with_code.y"
{yyval.Expression_list = Expression_list_node::addToExpressionListNode(yyvsp[-2].Expression_list, yyvsp[0].Expression);;
    break;}
case 76:
#line 283 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);;
    break;}
case 77:
#line 284 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);;
    break;}
case 78:
#line 285 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(OBJECT_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 79:
#line 286 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(CLASS_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 80:
#line 287 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 81:
#line 290 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 82:
#line 291 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Expression, yyvsp[0].Keyword_argument_list, NULL);;
    break;}
case 83:
#line 292 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Expression, yyvsp[-2].Keyword_argument_list, yyvsp[0].Expression_list);;
    break;}
case 84:
#line 295 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = NULL;;
    break;}
case 85:
#line 296 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = yyvsp[0].Keyword_argument_list;;
    break;}
case 86:
#line 299 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::createKeywordArgumentListNode(yyvsp[0].Keyword_argument);;
    break;}
case 87:
#line 300 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::addToKeywordArgumentListNode(yyvsp[-1].Keyword_argument_list, yyvsp[0].Keyword_argument);;
    break;}
case 88:
#line 303 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITH_IDENTIFIER_KW_ARGUMENT_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 89:
#line 304 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 90:
#line 308 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITHOUT_ALTERNATIVE_IF_TYPE, yyvsp[-2].Expression, yyvsp[0].Statement, NULL);;
    break;}
case 91:
#line 309 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITH_ALTERNATIVE_IF_TYPE, yyvsp[-4].Expression, yyvsp[-2].Statement, yyvsp[0].Statement);;
    break;}
case 92:
#line 313 "bison_rules_with_code.y"
{yyval.While  = While_statement_node::createWhileStatementNode(yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 93:
#line 316 "bison_rules_with_code.y"
{yyval.Do_while = Do_while_statement_node::createDoWhileStatementNode(yyvsp[-2].Expression, yyvsp[-5].Statement);;
    break;}
case 94:
#line 319 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNode(yyvsp[-6].Expression, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 95:
#line 320 "bison_rules_with_code.y"
{yyval.For =For_statement_node::createForStatementNodeFromForWithDeclaration(yyvsp[-7].Type, yyvsp[-6].Init_declarator_list, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 96:
#line 321 "bison_rules_with_code.y"
{yyval.For =For_statement_node::createForStatementNodeFromForWithDeclaration(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-8].Identifier), yyvsp[-6].Init_declarator_list, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 97:
#line 322 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 98:
#line 323 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-6].Identifier), yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 99:
#line 328 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);;
    break;}
case 100:
#line 329 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 101:
#line 330 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 102:
#line 331 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].If;;
    break;}
case 103:
#line 332 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].While;;
    break;}
case 104:
#line 333 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].Do_while;;
    break;}
case 105:
#line 334 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].For;;
    break;}
case 106:
#line 335 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].Compound_statement;;
    break;}
case 107:
#line 336 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].Declaration;;
    break;}
case 108:
#line 339 "bison_rules_with_code.y"
{yyval.Compound_statement = Compound_statement_node::createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 109:
#line 342 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::createStatementListNode(yyvsp[0].Statement);;
    break;}
case 110:
#line 343 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::addToStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 111:
#line 346 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 112:
#line 347 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 113:
#line 350 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlockNodeFromInterface(yyvsp[0].Class_interface);;
    break;}
case 114:
#line 351 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlockNodeFromImplementation(yyvsp[0].Class_implementation);;
    break;}
case 115:
#line 355 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 116:
#line 356 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 117:
#line 357 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 118:
#line 358 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 119:
#line 359 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 120:
#line 360 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 121:
#line 363 "bison_rules_with_code.y"
{yyval.Interface_body = NULL;;
    break;}
case 122:
#line 364 "bison_rules_with_code.y"
{yyval.Interface_body = yyvsp[0].Interface_body;;
    break;}
case 123:
#line 367 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Interface_declaration_list);;
    break;}
case 124:
#line 368 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 125:
#line 371 "bison_rules_with_code.y"
{yyval.Implementation_body = NULL;;
    break;}
case 126:
#line 372 "bison_rules_with_code.y"
{yyval.Implementation_body = yyvsp[0].Implementation_body;;
    break;}
case 127:
#line 375 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Implementation_definition_list);;
    break;}
case 128:
#line 376 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 129:
#line 379 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 130:
#line 380 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 131:
#line 381 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 132:
#line 382 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 133:
#line 383 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 134:
#line 384 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 135:
#line 387 "bison_rules_with_code.y"
{yyval.Class_declaration_list = Class_declaration_list_node::createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 136:
#line 390 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::createClassListNode(yyvsp[0].Identifier);;
    break;}
case 137:
#line 391 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::addToClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 138:
#line 394 "bison_rules_with_code.y"
{yyval.Instance_variables = Instance_variables_node::createInstanceVariablesNode(yyvsp[-1].Instance_variables_declaration_list);;
    break;}
case 139:
#line 397 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = NULL;;
    break;}
case 140:
#line 398 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = yyvsp[0].Instance_variables_declaration_list;;
    break;}
case 141:
#line 401 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Declarator_list);;
    break;}
case 142:
#line 402 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Declarator_list);;
    break;}
case 143:
#line 405 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::createInstanceVariablesDeclarationListNode(yyvsp[0].Instance_variables_declaration);;
    break;}
case 144:
#line 406 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::addToInstanceVariablesDeclarationListNode(yyvsp[-1].Instance_variables_declaration_list, yyvsp[0].Instance_variables_declaration);;
    break;}
case 145:
#line 409 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 146:
#line 410 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 147:
#line 411 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(yyvsp[0].Method_declaration);;
    break;}
case 148:
#line 412 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 149:
#line 413 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 150:
#line 414 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 151:
#line 417 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 152:
#line 418 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 153:
#line 419 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 154:
#line 420 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 155:
#line 421 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 156:
#line 422 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 157:
#line 425 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 158:
#line 426 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromSynthesize(yyvsp[0].Synthesize);;
    break;}
case 159:
#line 427 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(yyvsp[0].Method_definition);;
    break;}
case 160:
#line 428 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 161:
#line 429 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addSynthesizeToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Synthesize);;
    break;}
case 162:
#line 430 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 163:
#line 433 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 164:
#line 434 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 165:
#line 435 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 166:
#line 436 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 167:
#line 437 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 168:
#line 438 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 169:
#line 441 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 170:
#line 442 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Keyword_declaration, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 171:
#line 443 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Keyword_declaration, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_list);;
    break;}
case 172:
#line 446 "bison_rules_with_code.y"
{yyval.Keyword_selector = NULL;;
    break;}
case 173:
#line 447 "bison_rules_with_code.y"
{yyval.Keyword_selector = yyvsp[0].Keyword_selector;;
    break;}
case 174:
#line 450 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 175:
#line 451 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::addToKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 176:
#line 454 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 177:
#line 455 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 178:
#line 458 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 179:
#line 459 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 180:
#line 460 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 181:
#line 461 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 182:
#line 464 "bison_rules_with_code.y"
{yyval.Type = yyvsp[-1].Type;;
    break;}
case 183:
#line 465 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier);;
    break;}
case 184:
#line 468 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-3].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 185:
#line 469 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 186:
#line 472 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(EMPTY_ATTRIBUTE_TYPE);;
    break;}
case 187:
#line 473 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(EMPTY_ATTRIBUTE_TYPE);;
    break;}
case 188:
#line 474 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 189:
#line 475 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READWRITE_ATTRIBUTE_TYPE);;
    break;}
case 190:
#line 478 "bison_rules_with_code.y"
{yyval.Synthesize = Synthesize_node::createSynthesizeNode(yyvsp[-1].Identifier);
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
#line 481 "bison_rules_with_code.y"


void yyerror(char const *s)
{
	printf("%s",s);
}
