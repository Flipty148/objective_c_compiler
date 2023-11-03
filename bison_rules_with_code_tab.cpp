
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



#define	YYFINAL		394
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
   625,   629,   634,   642,   651,   656,   662,   669,   677,   679,
   681
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
    12,    20,     0,    35,    19,   121,    20,    62,    49,    51,
     0,    35,    19,   121,    20,    50,    12,    49,    51,     0,
    35,    62,    49,    51,     0,    35,    50,    12,    49,    51,
     0,    35,    19,    20,    62,    49,    51,     0,    35,    19,
    20,    50,    12,    49,    51,     0,    36,     0,    37,     0,
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
   309,   313,   316,   319,   320,   321,   322,   327,   328,   329,
   330,   331,   332,   333,   334,   335,   338,   341,   342,   345,
   346,   349,   350,   354,   355,   356,   357,   358,   359,   362,
   363,   366,   367,   370,   371,   374,   375,   378,   379,   380,
   381,   382,   383,   386,   389,   390,   393,   396,   397,   400,
   401,   404,   405,   408,   409,   410,   411,   412,   413,   416,
   417,   418,   419,   420,   421,   424,   425,   426,   427,   428,
   429,   432,   433,   434,   435,   436,   437,   440,   441,   442,
   445,   446,   449,   450,   453,   454,   457,   458,   459,   460,
   463,   464,   467,   468,   469,   470,   471,   472,   475,   476,
   479
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
   119,   119,   120,   120,   120,   120,   120,   120,   121,   121,
   122
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
     3,     4,     7,     8,     4,     5,     6,     7,     1,     1,
     3
};

static const short yydefact[] = {     0,
     9,    10,    11,     0,     0,    12,     0,     1,     3,     0,
     2,   112,   113,     4,   120,   120,   124,   124,   135,     0,
     6,     5,     7,     0,     0,     0,     0,    40,     0,   138,
    24,   144,     0,   121,     0,   123,   146,   145,     0,     0,
     0,     0,     0,     0,   156,     0,   125,     0,   127,   158,
   157,     0,     0,   134,     0,     0,     0,   168,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    36,    38,    41,
     0,   120,   120,     0,     0,     0,   142,   139,    30,     0,
    25,    26,    28,   115,   122,   147,   148,   149,   120,   120,
   118,     0,    22,     0,     0,    22,     0,     0,   124,   124,
   128,   126,   159,   161,   160,   124,   124,   130,   136,     0,
     0,     0,     0,     0,   152,     0,     0,   155,     0,     0,
   189,   190,     0,     0,     0,    31,     0,     0,    19,     0,
     0,    32,     0,    34,     0,   137,   143,    18,     0,     0,
     0,     0,     0,    20,    23,     0,    22,     0,     0,    22,
   191,     0,     0,     0,     0,   110,     8,     0,     0,   181,
     0,   176,   171,     0,   150,     0,   153,     0,     0,     0,
     0,   185,     0,     0,     0,    50,    51,    14,    15,    16,
    13,    17,    46,     0,     0,    48,    47,    37,    39,   114,
   116,   141,     0,   140,     0,    27,    29,   117,   119,     0,
    21,   164,     0,     0,   167,     0,   129,   132,   131,   133,
     0,     0,     0,     0,    70,    98,   106,     0,   101,   102,
   103,   104,   108,   105,   111,     0,     0,   182,     0,     0,
   169,   172,   173,   175,     0,     0,     0,     0,     0,   186,
    55,    54,     0,    72,    77,    76,    78,    79,     0,     0,
    56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    33,    35,    22,   162,    22,   165,
     0,     0,     0,    70,    71,     0,    99,   109,   107,   151,
     0,   178,     0,     0,   174,   154,     0,   187,     0,     0,
    49,    74,     0,    73,     0,    81,     0,    67,    61,    62,
    64,    63,    65,    66,    57,    58,    59,    60,    68,    69,
     0,     0,     0,     0,     0,    46,     0,    24,     0,   100,
   180,     0,   177,     0,     0,   170,    42,   188,     0,   183,
    53,     0,     0,     0,    52,   163,   166,     0,     0,     0,
     0,     0,     0,    70,   179,     0,    44,     0,   184,    75,
    80,    84,    90,    92,     0,     0,     0,    70,     0,    45,
    43,     0,     0,    82,    85,    86,     0,     0,     0,     0,
     0,    70,     0,    89,     0,    87,    91,    93,    96,     0,
    70,     0,    88,    83,     0,     0,     0,    97,     0,    94,
    95,     0,     0,     0
};

static const short yydefgoto[] = {   392,
     8,     9,    31,   186,   187,   217,   145,   146,    80,    81,
    82,    83,    68,   133,   135,    69,    70,    71,   326,   327,
   218,   276,   293,   294,   250,   297,   364,   365,   366,   219,
   220,   221,   222,   223,   224,   225,   226,    11,    12,    33,
    34,    46,    47,    13,    14,    20,    35,    76,    77,    78,
    36,    37,    49,    50,    59,   231,   232,   163,   233,    60,
    38,   123,    51
};

static const short yypact[] = {   540,
-32768,-32768,-32768,   -18,    36,-32768,   -45,   540,-32768,   -37,
-32768,-32768,-32768,-32768,   354,   357,   362,   405,-32768,    49,
-32768,-32768,-32768,    16,    -9,    -5,    15,    34,    38,    75,
     5,-32768,    46,-32768,   494,   494,-32768,-32768,    94,    57,
    20,    22,    23,   125,-32768,    60,-32768,   500,   500,-32768,
-32768,   148,    69,-32768,    56,    95,   135,    27,    66,    70,
   256,    73,    70,   126,   109,   102,   111,   161,-32768,   117,
   120,   410,   410,    34,     5,   119,-32768,    75,-32768,   128,
   132,-32768,   185,-32768,   494,-32768,-32768,-32768,   410,   410,
-32768,   280,   290,    70,   416,   290,    70,   139,   192,   192,
-32768,   500,-32768,-32768,-32768,   192,   192,-32768,-32768,   144,
   184,   194,   208,    24,-32768,   174,   212,-32768,   175,   504,
-32768,-32768,   214,   186,   188,-32768,   454,    34,-32768,   203,
   213,-32768,   165,-32768,   169,-32768,-32768,-32768,     5,   454,
   218,   223,   226,-32768,   290,   144,   290,   240,   144,   290,
-32768,   238,   239,   247,   248,   306,-32768,    70,   263,-32768,
   510,-32768,   -34,   249,-32768,    70,-32768,   284,   259,   525,
   254,-32768,   454,   454,   454,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   291,   205,   454,-32768,-32768,   691,-32768,-32768,
-32768,-32768,    34,-32768,     5,-32768,   691,-32768,-32768,    70,
-32768,-32768,   144,    70,-32768,   144,-32768,-32768,-32768,-32768,
   296,   299,   306,   300,   454,-32768,-32768,   282,-32768,-32768,
-32768,-32768,-32768,-32768,   306,   251,   269,-32768,   266,    30,
   271,   -34,-32768,-32768,   273,   277,   286,   326,   292,-32768,
   206,   206,   583,   454,-32768,-32768,-32768,-32768,   205,   293,
   206,   454,   454,   454,   454,   454,   454,   454,   454,   454,
   454,   454,   294,   295,-32768,-32768,   290,-32768,   290,-32768,
   454,   454,   311,   431,   691,   307,-32768,-32768,-32768,-32768,
    63,-32768,   317,   535,-32768,-32768,   318,-32768,   321,   320,
-32768,   691,   361,   322,   293,   330,   328,   691,   704,   704,
   412,   412,   412,   412,   155,   155,   206,   206,-32768,-32768,
   144,   144,   601,   619,   368,    29,   376,     5,   339,-32768,
-32768,   342,-32768,   381,   345,   344,-32768,-32768,   346,-32768,
-32768,   454,   347,   454,-32768,-32768,-32768,   306,   306,   454,
   454,   350,   351,   454,-32768,   356,-32768,   535,-32768,   691,
-32768,   258,   379,-32768,   637,   655,   377,   454,   358,-32768,
-32768,   378,   454,   365,   -23,-32768,   306,   384,   306,   454,
   385,   454,   454,   691,   454,-32768,-32768,-32768,-32768,   673,
   454,   424,   691,   322,   306,   427,   306,-32768,   306,-32768,
-32768,   448,   449,-32768
};

static const short yypgoto[] = {-32768,
-32768,   450,     0,-32768,-32768,    93,-32768,   -73,   138,-32768,
   324,   -72,   -67,-32768,-32768,   331,-32768,-32768,-32768,   121,
  -122,  -254,-32768,    99,   219,   187,-32768,-32768,   118,-32768,
-32768,-32768,-32768,  -158,  -104,-32768,-32768,   477,-32768,   -14,
-32768,    48,-32768,-32768,   479,-32768,     7,-32768,   411,-32768,
   453,   -17,   442,   -40,   -13,-32768,-32768,-32768,   260,   -25,
   -15,-32768,   -38
};


#define	YYLAST		722


static const short yytable[] = {    10,
    63,    40,   134,    19,   188,   157,   132,    10,   104,    57,
   105,    24,    62,    61,   229,    94,    97,   197,    87,   319,
    88,   230,   149,    48,    48,   362,    66,    93,    96,    75,
    15,    16,   363,    64,    56,     1,     2,     3,    92,    58,
    95,   202,   161,    58,   205,    67,   116,   244,   161,   119,
   241,   242,   243,    79,   273,     6,   113,   130,   131,   341,
   113,   104,   251,   105,    65,    53,   278,    87,    58,    88,
    58,    98,   162,   203,   141,   142,   206,    75,   282,    84,
   147,   161,   114,   150,    17,    18,    72,    73,   164,   359,
    91,   113,   275,   101,   113,     1,     2,     3,   268,    54,
    55,   270,   108,   371,   109,    48,    48,    32,    32,    45,
    45,   321,    48,    48,   110,     6,   115,   382,    58,   169,
   124,   292,   266,   118,    74,   265,   386,    32,    86,   298,
   299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
    45,   103,    89,    90,   227,   120,   152,   153,   313,   314,
   125,   275,   235,   154,   155,     1,     2,     3,   111,   126,
   113,   121,   122,   127,    32,    32,   261,   262,   128,   239,
   129,   263,   264,    99,   100,     6,   136,    86,   138,   353,
   354,    32,    32,   139,   112,   144,   267,   140,   144,   151,
   269,    45,    45,   311,   103,   312,   106,   107,    45,    45,
   156,    41,    42,   158,   283,   159,   336,   337,   377,   350,
   379,   352,     1,     2,     3,   192,   193,   355,   356,   194,
   195,   275,   263,   264,   165,   167,   388,   160,   390,    43,
   391,   166,     6,   170,   171,   275,   190,   201,   172,   144,
   374,    28,   144,   245,   246,   200,   191,   380,    30,   275,
   383,   198,   292,   247,   248,   322,   199,   249,   275,   204,
   252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
   262,   207,   208,   318,   263,   264,     1,     2,     3,   117,
   209,   210,   228,   325,   252,   253,   254,   255,   256,   257,
   258,   259,   260,   261,   262,   236,     6,   234,   263,   264,
     1,     2,     3,   143,   240,   112,   362,   237,   279,   244,
     1,     2,     3,   363,   271,   173,   174,   272,   274,   280,
     6,   281,   284,   286,   175,   287,     1,     2,     3,   112,
     6,   211,   277,   212,   213,   214,   288,   289,   315,    28,
   290,   296,   309,   310,   176,   177,     6,   325,   215,   178,
   179,   180,   181,   182,   183,    28,   216,   320,   184,   144,
   185,   144,   156,    25,    26,   323,    25,    26,   328,   329,
   330,    41,    42,   332,     1,     2,     3,     1,     2,     3,
   331,   335,     1,     2,     3,   334,   340,   342,    27,   344,
   345,    27,   346,   347,     6,   348,   349,     6,   357,    43,
   351,   358,     6,    28,   360,   367,    28,   370,   372,    29,
    30,    28,    39,    30,    41,    42,   375,    44,    30,    25,
    26,   259,   260,   261,   262,     1,     2,     3,   263,   264,
     1,     2,     3,   373,   378,   381,     1,     2,     3,   148,
   173,   174,    43,   387,    27,     6,   389,   393,   394,   175,
     6,     1,     2,     3,    28,   343,     6,    21,   189,    28,
    52,    30,   196,   173,   174,   112,    30,   295,   361,   176,
   177,     6,   175,   384,   178,   179,   180,   181,   182,   316,
   317,   333,   376,   184,    22,   185,    23,    85,   137,   102,
     0,   285,   176,   177,     0,     0,     0,   178,   179,   180,
   181,   182,   183,    25,    26,     0,   184,     0,   185,    41,
    42,     0,     0,     0,     1,     2,     3,     0,     0,     0,
     1,     2,     3,     0,     1,     2,     3,     0,    27,     0,
     1,     2,     3,     0,     6,     0,     0,    43,     0,     0,
     6,     0,     0,    28,     6,     1,     2,     3,     0,    28,
     6,     0,     0,   168,     0,     1,     2,     3,     0,   112,
     1,     2,     3,     0,     0,     6,     0,     0,     0,     0,
     0,     4,     5,     0,   238,     6,     0,     0,     0,     0,
     6,     7,     0,     0,   324,   252,   253,   254,   255,   256,
   257,   258,   259,   260,   261,   262,     0,     0,     0,   263,
   264,     0,   291,   252,   253,   254,   255,   256,   257,   258,
   259,   260,   261,   262,     0,     0,     0,   263,   264,     0,
   338,   252,   253,   254,   255,   256,   257,   258,   259,   260,
   261,   262,     0,     0,     0,   263,   264,     0,   339,   252,
   253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     0,     0,     0,   263,   264,     0,   368,   252,   253,   254,
   255,   256,   257,   258,   259,   260,   261,   262,     0,     0,
     0,   263,   264,     0,   369,   252,   253,   254,   255,   256,
   257,   258,   259,   260,   261,   262,     0,     0,     0,   263,
   264,     0,   385,   252,   253,   254,   255,   256,   257,   258,
   259,   260,   261,   262,     0,     0,     0,   263,   264,   255,
   256,   257,   258,   259,   260,   261,   262,     0,     0,     0,
   263,   264
};

static const short yycheck[] = {     0,
    26,    16,    75,    49,   127,   110,    74,     8,    49,    19,
    49,    49,    26,    19,    49,    41,    42,   140,    36,   274,
    36,    56,    96,    17,    18,    49,    27,    41,    42,    30,
    49,    50,    56,    19,    19,    21,    22,    23,    19,    49,
    19,   146,    19,    49,   149,    12,    60,    19,    19,    63,
   173,   174,   175,    49,   213,    41,    57,    72,    73,    31,
    61,   102,   185,   102,    50,    18,   225,    85,    49,    85,
    49,    49,    49,   147,    89,    90,   150,    78,    49,    34,
    94,    19,    56,    97,    49,    50,    49,    50,   114,   344,
    34,    92,   215,    34,    95,    21,    22,    23,   203,    51,
    52,   206,    34,   358,    49,    99,   100,    15,    16,    17,
    18,    49,   106,   107,    20,    41,    51,   372,    49,   120,
    12,   244,   195,    51,    50,   193,   381,    35,    36,   252,
   253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
    48,    49,    49,    50,   158,    20,    99,   100,   271,   272,
    49,   274,   166,   106,   107,    21,    22,    23,    24,    49,
   161,    36,    37,     3,    72,    73,    12,    13,    52,   170,
    51,    17,    18,    49,    50,    41,    58,    85,    51,   338,
   339,    89,    90,    52,    50,    93,   200,     3,    96,    51,
   204,    99,   100,   267,   102,   269,    49,    50,   106,   107,
    57,    10,    11,    20,   230,    12,   311,   312,   367,   332,
   369,   334,    21,    22,    23,    51,    52,   340,   341,    51,
    52,   344,    17,    18,    51,    51,   385,    20,   387,    38,
   389,    20,    41,    20,    49,   358,    34,   145,    51,   147,
   363,    50,   150,    39,    40,    20,    34,   370,    57,   372,
   373,    34,   375,    49,    50,   281,    34,    53,   381,    20,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    34,    34,   274,    17,    18,    21,    22,    23,    24,
    34,    34,    20,   284,     3,     4,     5,     6,     7,     8,
     9,    10,    11,    12,    13,    12,    41,    49,    17,    18,
    21,    22,    23,    24,    51,    50,    49,    49,    58,    19,
    21,    22,    23,    56,    19,    10,    11,    19,    19,    51,
    41,    56,    52,    51,    19,    49,    21,    22,    23,    50,
    41,    26,    51,    28,    29,    30,    51,    12,    28,    50,
    49,    49,    49,    49,    39,    40,    41,   348,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    51,    53,   267,
    55,   269,    57,    10,    11,    49,    10,    11,    51,    49,
    51,    10,    11,    52,    21,    22,    23,    21,    22,    23,
    20,    54,    21,    22,    23,    56,    19,    12,    35,    51,
    49,    35,    12,    49,    41,    52,    51,    41,    49,    38,
    54,    51,    41,    50,    49,    27,    50,    31,    51,    56,
    57,    50,    56,    57,    10,    11,    52,    56,    57,    10,
    11,    10,    11,    12,    13,    21,    22,    23,    17,    18,
    21,    22,    23,    56,    51,    51,    21,    22,    23,    24,
    10,    11,    38,    20,    35,    41,    20,     0,     0,    19,
    41,    21,    22,    23,    50,   318,    41,     8,   128,    50,
    56,    57,   139,    10,    11,    50,    57,   249,   348,    39,
    40,    41,    19,   375,    44,    45,    46,    47,    48,    49,
    50,   295,   365,    53,     8,    55,     8,    35,    78,    48,
    -1,   232,    39,    40,    -1,    -1,    -1,    44,    45,    46,
    47,    48,    49,    10,    11,    -1,    53,    -1,    55,    10,
    11,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,
    21,    22,    23,    -1,    21,    22,    23,    -1,    35,    -1,
    21,    22,    23,    -1,    41,    -1,    -1,    38,    -1,    -1,
    41,    -1,    -1,    50,    41,    21,    22,    23,    -1,    50,
    41,    -1,    -1,    50,    -1,    21,    22,    23,    -1,    50,
    21,    22,    23,    -1,    -1,    41,    -1,    -1,    -1,    -1,
    -1,    32,    33,    -1,    50,    41,    -1,    -1,    -1,    -1,
    41,    42,    -1,    -1,    50,     3,     4,     5,     6,     7,
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
    18,    -1,    20,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,     6,
     7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
    17,    18
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
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 184:
#line 468 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-5].Attribute, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 185:
#line 469 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 186:
#line 470 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 187:
#line 471 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 188:
#line 472 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 189:
#line 475 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 190:
#line 476 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READWRITE_ATTRIBUTE_TYPE);;
    break;}
case 191:
#line 479 "bison_rules_with_code.y"
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
#line 482 "bison_rules_with_code.y"


void yyerror(char const *s)
{
	printf("%s",s);
}
