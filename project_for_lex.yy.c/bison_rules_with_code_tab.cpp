
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



#define	YYFINAL		381
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
   262,   270,   276,   284,   294,   305,   313,   323,   325,   328,
   332,   334,   336,   338,   340,   342,   344,   348,   350,   353,
   354,   356,   358,   360,   367,   372,   379,   386,   391,   398,
   399,   401,   404,   406,   407,   409,   412,   414,   419,   426,
   431,   438,   445,   452,   456,   458,   462,   466,   467,   469,
   473,   477,   479,   482,   484,   486,   488,   491,   494,   497,
   502,   509,   513,   518,   525,   529,   531,   533,   535,   538,
   541,   544,   550,   558,   563,   569,   577,   582,   584,   589,
   596,   597,   599,   601,   604,   607,   609,   613,   616,   621,
   625,   629,   634,   640,   647,   648,   651,   655,   659
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
    81,    20,    93,     0,    30,    19,    49,    31,    80,    20,
    93,     0,    30,    19,    50,    12,    49,    31,    80,    20,
    93,     0,    51,     0,    80,    51,     0,    43,    81,    51,
     0,    89,     0,    90,     0,    91,     0,    92,     0,    94,
     0,    65,     0,    57,    96,    58,     0,    93,     0,    95,
    93,     0,     0,    95,     0,    98,     0,   103,     0,    32,
    49,    56,    49,    99,    34,     0,    32,    49,    99,    34,
     0,    32,    49,    56,    50,    99,    34,     0,    32,    50,
    56,    49,    99,    34,     0,    32,    50,    99,    34,     0,
    32,    50,    56,    50,    99,    34,     0,     0,   100,     0,
   106,   110,     0,   110,     0,     0,   102,     0,   106,   112,
     0,   112,     0,    33,    49,   101,    34,     0,    33,    49,
    56,    49,   101,    34,     0,    33,    50,   101,    34,     0,
    33,    50,    56,    49,   101,    34,     0,    33,    49,    56,
    50,   101,    34,     0,    33,    50,    56,    50,   101,    34,
     0,    42,   105,    51,     0,    49,     0,   105,    52,    49,
     0,    57,   107,    58,     0,     0,   109,     0,    62,    74,
    51,     0,    50,    73,    51,     0,   108,     0,   109,   108,
     0,    65,     0,   120,     0,   111,     0,   110,    65,     0,
   110,   111,     0,   110,   120,     0,    10,   119,   114,    51,
     0,    10,    19,    24,    20,   114,    51,     0,    10,   114,
    51,     0,    11,   119,   114,    51,     0,    11,    19,    24,
    20,   114,    51,     0,    11,   114,    51,     0,    65,     0,
   122,     0,   113,     0,   112,    65,     0,   112,   122,     0,
   112,   113,     0,    10,   119,   114,    67,    94,     0,    10,
    19,    24,    20,   114,    67,    94,     0,    10,   114,    67,
    94,     0,    11,   119,   114,    67,    94,     0,    11,    19,
    24,    20,   114,    67,    94,     0,    11,   114,    67,    94,
     0,    49,     0,    49,    56,   117,   115,     0,    49,    56,
   117,   115,    52,    78,     0,     0,   116,     0,   118,     0,
   116,   118,     0,   119,    49,     0,    49,     0,    56,   119,
    49,     0,    56,    49,     0,    49,    56,   119,    49,     0,
    49,    56,    49,     0,    19,    62,    20,     0,    19,    50,
    12,    20,     0,    35,   121,    62,    49,    51,     0,    35,
   121,    50,    12,    49,    51,     0,     0,    19,    20,     0,
    19,    36,    20,     0,    19,    37,    20,     0,    38,    49,
    51,     0
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
   309,   313,   316,   319,   320,   321,   322,   327,   328,   329,
   330,   331,   332,   333,   334,   335,   338,   341,   342,   345,
   346,   349,   350,   354,   355,   356,   357,   358,   359,   362,
   363,   366,   367,   370,   371,   374,   375,   378,   379,   380,
   381,   382,   383,   386,   389,   390,   393,   396,   397,   400,
   401,   404,   405,   408,   409,   410,   411,   412,   413,   416,
   417,   418,   419,   420,   421,   424,   425,   426,   427,   428,
   429,   432,   433,   434,   435,   436,   437,   440,   441,   442,
   445,   446,   449,   450,   453,   454,   457,   458,   459,   460,
   463,   464,   467,   468,   471,   472,   473,   474,   477
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
    89,    90,    91,    92,    92,    92,    92,    93,    93,    93,
    93,    93,    93,    93,    93,    93,    94,    95,    95,    96,
    96,    97,    97,    98,    98,    98,    98,    98,    98,    99,
    99,   100,   100,   101,   101,   102,   102,   103,   103,   103,
   103,   103,   103,   104,   105,   105,   106,   107,   107,   108,
   108,   109,   109,   110,   110,   110,   110,   110,   110,   111,
   111,   111,   111,   111,   111,   112,   112,   112,   112,   112,
   112,   113,   113,   113,   113,   113,   113,   114,   114,   114,
   115,   115,   116,   116,   117,   117,   118,   118,   118,   118,
   119,   119,   120,   120,   121,   121,   121,   121,   122
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
     7,     5,     7,     9,    10,     7,     9,     1,     2,     3,
     1,     1,     1,     1,     1,     1,     3,     1,     2,     0,
     1,     1,     1,     6,     4,     6,     6,     4,     6,     0,
     1,     2,     1,     0,     1,     2,     1,     4,     6,     4,
     6,     6,     6,     3,     1,     3,     3,     0,     1,     3,
     3,     1,     2,     1,     1,     1,     2,     2,     2,     4,
     6,     3,     4,     6,     3,     1,     1,     1,     2,     2,
     2,     5,     7,     4,     5,     7,     4,     1,     4,     6,
     0,     1,     1,     2,     2,     1,     3,     2,     4,     3,
     3,     4,     5,     6,     0,     2,     3,     3,     3
};

static const short yydefact[] = {     0,
     9,    10,    11,     0,     0,    12,     0,     1,     3,     0,
     2,   112,   113,     4,   120,   120,   124,   124,   135,     0,
     6,     5,     7,     0,     0,     0,   185,    40,     0,   138,
    24,   144,     0,   121,     0,   123,   146,   145,     0,     0,
     0,     0,     0,     0,   156,     0,   125,     0,   127,   158,
   157,     0,     0,   134,     0,     0,     0,   168,     0,     0,
     0,     0,     0,     0,     0,     0,    36,    38,    41,     0,
   120,   120,     0,     0,     0,   142,   139,    30,     0,    25,
    26,    28,   115,   122,   147,   148,   149,   120,   120,   118,
     0,    22,     0,     0,    22,     0,     0,   124,   124,   128,
   126,   159,   161,   160,   124,   124,   130,   136,     0,     0,
     0,     0,     0,   152,     0,     0,   155,     0,   186,     0,
     0,     0,     0,    31,     0,     0,    19,     0,     0,    32,
     0,    34,     0,   137,   143,    18,     0,     0,     0,     0,
     0,    20,    23,     0,    22,     0,     0,    22,   189,     0,
     0,     0,     0,   110,     8,     0,     0,   181,     0,   176,
   171,     0,   150,     0,   153,   187,   188,     0,     0,     0,
     0,     0,    50,    51,    14,    15,    16,    13,    17,    46,
     0,     0,    48,    47,    37,    39,   114,   116,   141,     0,
   140,     0,    27,    29,   117,   119,     0,    21,   164,     0,
     0,   167,     0,   129,   132,   131,   133,     0,     0,     0,
     0,    70,    98,   106,     0,   101,   102,   103,   104,   108,
   105,   111,     0,     0,   182,     0,     0,   169,   172,   173,
   175,     0,     0,   183,    55,    54,     0,    72,    77,    76,
    78,    79,     0,     0,    56,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    33,    35,
    22,   162,    22,   165,     0,     0,     0,    70,    71,     0,
    99,   109,   107,   151,     0,   178,     0,     0,   174,   154,
   184,    49,    74,     0,    73,     0,    81,     0,    67,    61,
    62,    64,    63,    65,    66,    57,    58,    59,    60,    68,
    69,     0,     0,     0,     0,     0,    46,     0,    24,     0,
   100,   180,     0,   177,     0,     0,   170,    42,    53,     0,
     0,     0,    52,   163,   166,     0,     0,     0,     0,     0,
     0,    70,   179,     0,    44,     0,    75,    80,    84,    90,
    92,     0,     0,     0,    70,     0,    45,    43,     0,     0,
    82,    85,    86,     0,     0,     0,     0,     0,    70,     0,
    89,     0,    87,    91,    93,    96,     0,    70,     0,    88,
    83,     0,     0,     0,    97,     0,    94,    95,     0,     0,
     0
};

static const short yydefgoto[] = {   379,
     8,     9,    31,   183,   184,   214,   143,   144,    79,    80,
    81,    82,    67,   131,   133,    68,    69,    70,   317,   318,
   215,   270,   284,   285,   244,   288,   351,   352,   353,   216,
   217,   218,   219,   220,   221,   222,   223,    11,    12,    33,
    34,    46,    47,    13,    14,    20,    35,    75,    76,    77,
    36,    37,    49,    50,    59,   228,   229,   161,   230,    60,
    38,    65,    51
};

static const short yypact[] = {   483,
-32768,-32768,-32768,    75,   101,-32768,   -46,   483,-32768,   -42,
-32768,-32768,-32768,-32768,   142,   342,   214,   346,-32768,   123,
-32768,-32768,-32768,     3,     1,    41,     8,    19,   131,   166,
    15,-32768,    39,-32768,   467,   467,-32768,-32768,   147,    63,
    57,    59,    58,   155,-32768,    88,-32768,   473,   473,-32768,
-32768,   162,   124,-32768,    77,   156,   145,   122,   134,   133,
   198,   140,   133,   -11,   305,   151,   191,-32768,   154,   157,
   350,   350,    19,    15,   165,-32768,   166,-32768,   183,   190,
-32768,   241,-32768,   467,-32768,-32768,-32768,   350,   350,-32768,
   251,   309,   133,   389,   309,   133,   195,   383,   383,-32768,
   473,-32768,-32768,-32768,   383,   383,-32768,-32768,   194,   234,
   244,   237,    92,-32768,   208,   242,-32768,   218,-32768,   246,
   256,   265,   230,-32768,   427,    19,-32768,   259,   263,-32768,
   176,-32768,   178,-32768,-32768,-32768,    15,   427,   266,   268,
   260,-32768,   309,   194,   309,   279,   194,   309,-32768,   269,
   272,   273,   274,   294,-32768,   133,   289,-32768,   367,-32768,
    -2,   261,-32768,   133,-32768,-32768,-32768,   262,   267,   427,
   427,   427,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   293,
   379,   427,-32768,-32768,   633,-32768,-32768,-32768,-32768,    19,
-32768,    15,-32768,   633,-32768,-32768,   133,-32768,-32768,   194,
   133,-32768,   194,-32768,-32768,-32768,-32768,   295,   300,   294,
   302,   427,-32768,-32768,   278,-32768,-32768,-32768,-32768,-32768,
-32768,   294,   290,   303,-32768,   306,    95,   314,    -2,-32768,
-32768,   307,   319,-32768,   215,   215,   525,   427,-32768,-32768,
-32768,-32768,   379,   276,   215,   427,   427,   427,   427,   427,
   427,   427,   427,   427,   427,   427,   325,   326,-32768,-32768,
   309,-32768,   309,-32768,   427,   427,   348,   404,   633,   327,
-32768,-32768,-32768,-32768,    99,-32768,   330,   477,-32768,-32768,
-32768,-32768,   633,   360,   329,   276,   339,   328,   633,   646,
   646,   451,   451,   451,   451,    87,    87,   215,   215,-32768,
-32768,   194,   194,   543,   561,   378,   153,   374,    15,   358,
-32768,-32768,   352,-32768,   408,   373,   364,-32768,-32768,   427,
   377,   427,-32768,-32768,-32768,   294,   294,   427,   427,   385,
   384,   427,-32768,   387,-32768,   477,   633,-32768,    31,   414,
-32768,   579,   597,   411,   427,   396,-32768,-32768,   399,   427,
   406,    26,-32768,   294,   405,   294,   427,   409,   427,   427,
   633,   427,-32768,-32768,-32768,-32768,   615,   427,   445,   633,
   329,   294,   450,   294,-32768,   294,-32768,-32768,   479,   481,
-32768
};

static const short yypgoto[] = {-32768,
-32768,   478,     0,-32768,-32768,    -3,-32768,   -90,   182,-32768,
   355,   -72,   -69,-32768,-32768,   359,-32768,-32768,-32768,   161,
  -119,  -189,-32768,   125,   250,   217,-32768,-32768,   149,-32768,
-32768,-32768,-32768,  -109,   -88,-32768,-32768,   499,-32768,    -5,
-32768,    56,-32768,-32768,   501,-32768,    11,-32768,   433,-32768,
   484,   -13,   464,   -39,    97,-32768,-32768,-32768,   284,   -25,
   -12,-32768,   -31
};


#define	YYLAST		664


static const short yytable[] = {    10,
    63,   132,    19,   130,   147,   185,    24,    10,   119,   103,
    40,    32,    32,    45,    45,    93,    96,   104,   194,    57,
   155,    56,    86,    87,   120,   121,    64,    48,    48,    74,
    66,    32,    85,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,    45,   102,   226,   257,   258,    58,
   235,   236,   237,   227,   200,   199,   112,   203,   202,    61,
   112,   103,   245,    78,   123,   128,   129,    32,    32,   104,
    86,    87,    83,    53,   349,    91,    74,    94,   310,   349,
    85,   350,   139,   140,    32,    32,   350,   162,   142,    58,
   112,   142,   269,   112,    45,    45,    90,   102,   255,   256,
   267,    45,    45,   257,   258,    58,    97,    58,    48,    48,
   159,   262,   272,   159,   264,    48,    48,   159,   283,   260,
   259,   100,    62,    15,    16,   108,   289,   290,   291,   292,
   293,   294,   295,   296,   297,   298,   299,    92,    95,   198,
   160,   142,   346,   276,   142,   304,   305,   312,   269,    17,
    18,    25,    26,   150,   151,   358,   115,   107,   112,   118,
   152,   153,     1,     2,     3,     1,     2,     3,   110,   369,
   302,   238,   303,    54,    55,   109,    27,   113,   373,    71,
    72,    58,     6,   329,   114,     6,     1,     2,     3,   145,
   117,    28,   148,   125,   111,    88,    89,    29,    30,   124,
   337,   277,   339,    98,    99,   126,     6,   127,   342,   343,
   105,   106,   269,   324,   325,    73,   340,   341,     1,     2,
     3,   116,   134,    41,    42,   269,   189,   190,   191,   192,
   361,   257,   258,   136,     1,     2,     3,   367,     6,   269,
   370,   137,   283,   138,   364,   149,   366,   111,   269,   313,
   154,    43,   224,   156,     6,   157,   158,   142,   163,   142,
   232,   164,   375,    28,   377,   166,   378,   309,   165,    44,
    30,     1,     2,     3,   141,   167,   168,   316,   169,   197,
   246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
   256,     6,   187,   261,   257,   258,   188,   263,   201,   195,
   111,   196,   204,   170,   171,   205,   206,   207,   225,   231,
   233,   238,   172,   265,     1,     2,     3,   234,   266,   208,
   268,   209,   210,   211,   287,     1,     2,     3,   271,     1,
     2,     3,   173,   174,     6,   316,   212,   175,   176,   177,
   178,   179,   180,    28,   213,     6,   181,   273,   182,     6,
   154,    25,    26,   274,   122,    41,    42,   280,    28,    25,
    26,   275,     1,     2,     3,   278,     1,     2,     3,   281,
     1,     2,     3,   300,   301,   306,    27,   311,   314,   319,
   320,   323,     6,    43,    27,   330,     6,     1,     2,     3,
     6,    28,    41,    42,   322,    28,   328,    39,    30,    28,
   333,    52,    30,     1,     2,     3,    30,     6,   332,     1,
     2,     3,   146,   170,   171,   336,   111,   239,   240,   334,
    43,   335,   172,     6,     1,     2,     3,   241,   242,     6,
   338,   243,    28,   344,   345,   347,   170,   171,   111,    30,
   354,   357,   173,   174,     6,   172,   359,   175,   176,   177,
   178,   179,   307,   308,   360,   365,   181,   362,   182,   368,
   253,   254,   255,   256,   374,   173,   174,   257,   258,   376,
   175,   176,   177,   178,   179,   180,    25,    26,   380,   181,
   381,   182,    41,    42,   186,    21,   371,     1,     2,     3,
   331,   193,   286,     1,     2,     3,   348,     1,     2,     3,
   363,    27,   321,     1,     2,     3,    22,     6,    23,   135,
    43,   101,   279,     6,     4,     5,    28,     6,    84,     0,
     0,     0,    28,     6,     7,     0,   315,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,     0,     0,
     0,   257,   258,     0,   282,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,     0,     0,     0,   257,
   258,     0,   326,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,     0,     0,     0,   257,   258,     0,
   327,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,     0,     0,     0,   257,   258,     0,   355,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     0,     0,     0,   257,   258,     0,   356,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,     0,     0,
     0,   257,   258,     0,   372,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,     0,     0,     0,   257,
   258,   249,   250,   251,   252,   253,   254,   255,   256,     0,
     0,     0,   257,   258
};

static const short yycheck[] = {     0,
    26,    74,    49,    73,    95,   125,    49,     8,    20,    49,
    16,    15,    16,    17,    18,    41,    42,    49,   138,    19,
   109,    19,    36,    36,    36,    37,    19,    17,    18,    30,
    12,    35,    36,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    48,    49,    49,    17,    18,    49,
   170,   171,   172,    56,   145,   144,    57,   148,   147,    19,
    61,   101,   182,    49,    65,    71,    72,    71,    72,   101,
    84,    84,    34,    18,    49,    19,    77,    19,   268,    49,
    84,    56,    88,    89,    88,    89,    56,   113,    92,    49,
    91,    95,   212,    94,    98,    99,    34,   101,    12,    13,
   210,   105,   106,    17,    18,    49,    49,    49,    98,    99,
    19,   200,   222,    19,   203,   105,   106,    19,   238,   192,
   190,    34,    26,    49,    50,    49,   246,   247,   248,   249,
   250,   251,   252,   253,   254,   255,   256,    41,    42,   143,
    49,   145,   332,    49,   148,   265,   266,    49,   268,    49,
    50,    10,    11,    98,    99,   345,    60,    34,   159,    63,
   105,   106,    21,    22,    23,    21,    22,    23,    24,   359,
   261,    19,   263,    51,    52,    20,    35,    56,   368,    49,
    50,    49,    41,    31,    51,    41,    21,    22,    23,    93,
    51,    50,    96,     3,    50,    49,    50,    56,    57,    49,
   320,   227,   322,    49,    50,    52,    41,    51,   328,   329,
    49,    50,   332,   302,   303,    50,   326,   327,    21,    22,
    23,    24,    58,    10,    11,   345,    51,    52,    51,    52,
   350,    17,    18,    51,    21,    22,    23,   357,    41,   359,
   360,    52,   362,     3,   354,    51,   356,    50,   368,   275,
    57,    38,   156,    20,    41,    12,    20,   261,    51,   263,
   164,    20,   372,    50,   374,    20,   376,   268,    51,    56,
    57,    21,    22,    23,    24,    20,    12,   278,    49,    20,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    41,    34,   197,    17,    18,    34,   201,    20,    34,
    50,    34,    34,    10,    11,    34,    34,    34,    20,    49,
    49,    19,    19,    19,    21,    22,    23,    51,    19,    26,
    19,    28,    29,    30,    49,    21,    22,    23,    51,    21,
    22,    23,    39,    40,    41,   336,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    41,    53,    58,    55,    41,
    57,    10,    11,    51,    50,    10,    11,    51,    50,    10,
    11,    56,    21,    22,    23,    52,    21,    22,    23,    51,
    21,    22,    23,    49,    49,    28,    35,    51,    49,    20,
    52,    54,    41,    38,    35,    12,    41,    21,    22,    23,
    41,    50,    10,    11,    56,    50,    19,    56,    57,    50,
    49,    56,    57,    21,    22,    23,    57,    41,    51,    21,
    22,    23,    24,    10,    11,    52,    50,    39,    40,    12,
    38,    49,    19,    41,    21,    22,    23,    49,    50,    41,
    54,    53,    50,    49,    51,    49,    10,    11,    50,    57,
    27,    31,    39,    40,    41,    19,    51,    44,    45,    46,
    47,    48,    49,    50,    56,    51,    53,    52,    55,    51,
    10,    11,    12,    13,    20,    39,    40,    17,    18,    20,
    44,    45,    46,    47,    48,    49,    10,    11,     0,    53,
     0,    55,    10,    11,   126,     8,   362,    21,    22,    23,
   309,   137,   243,    21,    22,    23,   336,    21,    22,    23,
   352,    35,   286,    21,    22,    23,     8,    41,     8,    77,
    38,    48,   229,    41,    32,    33,    50,    41,    35,    -1,
    -1,    -1,    50,    41,    42,    -1,    50,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
    -1,    17,    18,    -1,    20,     3,     4,     5,     6,     7,
     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    17,
    18,    -1,    20,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
    20,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
    -1,    -1,    -1,    17,    18,    -1,    20,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
    -1,    17,    18,    -1,    20,     3,     4,     5,     6,     7,
     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    17,
    18,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
    -1,    -1,    17,    18
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
{yyval.For =For_statement_node::createForStatementNodeFromForWithDeclaration(yyvsp[-7].Type, yyvsp[-6].Init_declarator_list, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);
    break;}
case 96:
#line 321 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 97:
#line 322 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-6].Identifier), yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 98:
#line 327 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);;
    break;}
case 99:
#line 328 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 100:
#line 329 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 101:
#line 330 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(IF_STATEMENT_TYPE, yyvsp[0].If);;
    break;}
case 102:
#line 331 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(WHILE_STATEMENT_TYPE, yyvsp[0].While);;
    break;}
case 103:
#line 332 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(DO_WHILE_STATEMENT_TYPE, yyvsp[0].Do_while);;
    break;}
case 104:
#line 333 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(FOR_STATEMENT_TYPE, yyvsp[0].For);;
    break;}
case 105:
#line 334 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(COMPOUND_STATEMENT_TYPE, yyvsp[0].Compound_statement);;
    break;}
case 106:
#line 335 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 107:
#line 338 "bison_rules_with_code.y"
{yyval.Compound_statement = Compound_statement_node::createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 108:
#line 341 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::createStatementListNode(yyvsp[0].Statement);;
    break;}
case 109:
#line 342 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::addToStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 110:
#line 345 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 111:
#line 346 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 112:
#line 349 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlockNodeFromInterface(yyvsp[0].Class_interface);;
    break;}
case 113:
#line 350 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlockNodeFromImplementation(yyvsp[0].Class_implementation);;
    break;}
case 114:
#line 354 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 115:
#line 355 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 116:
#line 356 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 117:
#line 357 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 118:
#line 358 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 119:
#line 359 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 120:
#line 362 "bison_rules_with_code.y"
{yyval.Interface_body = NULL;;
    break;}
case 121:
#line 363 "bison_rules_with_code.y"
{yyval.Interface_body = yyvsp[0].Interface_body;;
    break;}
case 122:
#line 366 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Interface_declaration_list);;
    break;}
case 123:
#line 367 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 124:
#line 370 "bison_rules_with_code.y"
{yyval.Implementation_body = NULL;;
    break;}
case 125:
#line 371 "bison_rules_with_code.y"
{yyval.Implementation_body = yyvsp[0].Implementation_body;;
    break;}
case 126:
#line 374 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Implementation_definition_list);;
    break;}
case 127:
#line 375 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 128:
#line 378 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 129:
#line 379 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 130:
#line 380 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 131:
#line 381 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
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
#line 386 "bison_rules_with_code.y"
{yyval.Class_declaration_list = Class_declaration_list_node::createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 135:
#line 389 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::createClassListNode(yyvsp[0].Identifier);;
    break;}
case 136:
#line 390 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::addToClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 137:
#line 393 "bison_rules_with_code.y"
{yyval.Instance_variables = Instance_variables_node::createInstanceVariablesNode(yyvsp[-1].Instance_variables_declaration_list);;
    break;}
case 138:
#line 396 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = NULL;;
    break;}
case 139:
#line 397 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = yyvsp[0].Instance_variables_declaration_list;;
    break;}
case 140:
#line 400 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Declarator_list);;
    break;}
case 141:
#line 401 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Declarator_list);;
    break;}
case 142:
#line 404 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::createInstanceVariablesDeclarationListNode(yyvsp[0].Instance_variables_declaration);;
    break;}
case 143:
#line 405 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::addToInstanceVariablesDeclarationListNode(yyvsp[-1].Instance_variables_declaration_list, yyvsp[0].Instance_variables_declaration);;
    break;}
case 144:
#line 408 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 145:
#line 409 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 146:
#line 410 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(yyvsp[0].Method_declaration);;
    break;}
case 147:
#line 411 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 148:
#line 412 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 149:
#line 413 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 150:
#line 416 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 151:
#line 417 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 152:
#line 418 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 153:
#line 419 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 154:
#line 420 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 155:
#line 421 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 156:
#line 424 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 157:
#line 425 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromSynthesize(yyvsp[0].Synthesize);;
    break;}
case 158:
#line 426 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(yyvsp[0].Method_definition);;
    break;}
case 159:
#line 427 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 160:
#line 428 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addSynthesizeToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Synthesize);;
    break;}
case 161:
#line 429 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 162:
#line 432 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 163:
#line 433 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 164:
#line 434 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 165:
#line 435 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 166:
#line 436 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 167:
#line 437 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 168:
#line 440 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 169:
#line 441 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Keyword_declaration, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 170:
#line 442 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Keyword_declaration, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_list);;
    break;}
case 171:
#line 445 "bison_rules_with_code.y"
{yyval.Keyword_selector = NULL;;
    break;}
case 172:
#line 446 "bison_rules_with_code.y"
{yyval.Keyword_selector = yyvsp[0].Keyword_selector;;
    break;}
case 173:
#line 449 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 174:
#line 450 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::addToKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 175:
#line 453 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 176:
#line 454 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 177:
#line 457 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 178:
#line 458 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 179:
#line 459 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 180:
#line 460 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 181:
#line 463 "bison_rules_with_code.y"
{yyval.Type = yyvsp[-1].Type;;
    break;}
case 182:
#line 464 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier);;
    break;}
case 183:
#line 467 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-3].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 184:
#line 468 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 185:
#line 471 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(EMPTY_ATTRIBUTE_TYPE);;
    break;}
case 186:
#line 472 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(EMPTY_ATTRIBUTE_TYPE);;
    break;}
case 187:
#line 473 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 188:
#line 474 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READWRITE_ATTRIBUTE_TYPE);;
    break;}
case 189:
#line 477 "bison_rules_with_code.y"
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
#line 480 "bison_rules_with_code.y"


void yyerror(char const *s)
{
	printf("%s",s);
}
