
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
	Class_list *Class_list;
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



#define	YYFINAL		372
#define	YYFLAG		-32768
#define	YYNTBASE	59

#define YYTRANSLATE(x) ((unsigned)(x) <= 295 ? yytranslate[x] : 122)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    55,     2,    19,
    20,    12,    10,    54,    11,    17,    13,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    56,    53,     6,
     3,     7,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    21,     2,    22,     2,     2,     2,     2,     2,     2,     2,
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
     9,    14,    15,    16,    18,    23,    24,    25,    26,    27,
    28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     6,     8,    11,    14,    17,    23,    25,
    27,    29,    31,    33,    35,    37,    39,    41,    45,    49,
    51,    54,    55,    57,    58,    60,    62,    66,    68,    72,
    74,    77,    79,    83,    85,    89,    91,    95,    97,   101,
   102,   104,   106,   110,   113,   117,   119,   121,   123,   127,
   129,   134,   137,   140,   143,   147,   151,   155,   159,   163,
   167,   171,   175,   179,   183,   187,   191,   195,   196,   198,
   200,   202,   204,   209,   211,   216,   217,   219,   221,   224,
   228,   231,   237,   245,   251,   259,   269,   277,   286,   296,
   298,   301,   305,   307,   309,   311,   313,   315,   317,   321,
   323,   326,   327,   329,   331,   333,   340,   345,   352,   355,
   357,   360,   362,   367,   374,   379,   386,   393,   400,   404,
   406,   410,   414,   418,   422,   424,   427,   429,   431,   433,
   436,   439,   442,   444,   446,   451,   458,   462,   467,   474,
   478,   480,   482,   484,   487,   490,   493,   495,   497,   503,
   511,   516,   522,   530,   535,   537,   542,   549,   550,   552,
   554,   557,   560,   562,   566,   569,   574,   578,   582,   587,
   595,   604,   609,   615,   622,   630,   632,   634
};

static const short yyrhs[] = {    60,
     0,    95,     0,    61,     0,   100,     0,    60,    95,     0,
    60,    61,     0,    60,   100,     0,    62,    51,    19,    20,
    92,     0,    23,     0,    24,     0,    25,     0,    43,     0,
    49,     0,    46,     0,    47,     0,    48,     0,    50,     0,
    62,    68,    53,     0,    52,    77,    53,     0,    65,     0,
    66,    65,     0,     0,    66,     0,     0,    69,     0,    70,
     0,    69,    54,    70,     0,    71,     0,    71,     3,    80,
     0,    51,     0,    12,    51,     0,    72,     0,    73,    54,
    72,     0,    71,     0,    74,    54,    71,     0,    72,     0,
    72,     3,    80,     0,    75,     0,    76,    54,    75,     0,
     0,    76,     0,    79,     0,    78,    54,    79,     0,    62,
    51,     0,    52,    12,    51,     0,    51,     0,    64,     0,
    63,     0,    19,    80,    20,     0,    41,     0,    21,    82,
    83,    22,     0,    11,    80,     0,    10,    80,     0,    55,
    80,     0,    80,    10,    80,     0,    80,    11,    80,     0,
    80,    12,    80,     0,    80,    13,    80,     0,    80,     4,
    80,     0,    80,     5,    80,     0,    80,     7,    80,     0,
    80,     6,    80,     0,    80,     8,    80,     0,    80,     9,
    80,     0,    80,     3,    80,     0,    80,    17,    51,     0,
    80,    18,    51,     0,     0,    80,     0,    42,     0,    41,
     0,    51,     0,    21,    82,    83,    22,     0,    51,     0,
    51,    56,    80,    84,     0,     0,    85,     0,    86,     0,
    85,    86,     0,    51,    56,    80,     0,    56,    80,     0,
    28,    19,    80,    20,    91,     0,    28,    19,    80,    20,
    91,    29,    91,     0,    30,    19,    80,    20,    91,     0,
    31,    91,    30,    19,    80,    20,    53,     0,    32,    19,
    81,    53,    81,    53,    81,    20,    91,     0,    32,    19,
    51,    33,    80,    20,    91,     0,    32,    19,    62,    51,
    33,    80,    20,    91,     0,    32,    19,    52,    12,    51,
    33,    80,    20,    91,     0,    53,     0,    80,    53,     0,
    45,    81,    53,     0,    87,     0,    88,     0,    89,     0,
    90,     0,    92,     0,    65,     0,    57,    94,    58,     0,
    91,     0,    93,    91,     0,     0,    93,     0,    96,     0,
    99,     0,    34,    51,    56,    51,    97,    36,     0,    34,
    51,    97,    36,     0,    34,    51,    56,    52,    97,    36,
     0,   102,   105,     0,   105,     0,   102,   109,     0,   109,
     0,    35,    51,    98,    36,     0,    35,    51,    56,    51,
    98,    36,     0,    35,    52,    98,    36,     0,    35,    52,
    56,    51,    98,    36,     0,    35,    51,    56,    52,    98,
    36,     0,    35,    52,    56,    52,    98,    36,     0,    44,
   101,    53,     0,    51,     0,   101,    54,    51,     0,    57,
   104,    58,     0,    62,    74,    53,     0,    52,    73,    53,
     0,   103,     0,   104,   103,     0,    65,     0,   119,     0,
   106,     0,   105,    65,     0,   105,   106,     0,   105,   119,
     0,   107,     0,   108,     0,    10,   118,   113,    53,     0,
    10,    19,    26,    20,   113,    53,     0,    10,   113,    53,
     0,    11,   118,   113,    53,     0,    11,    19,    26,    20,
   113,    53,     0,    11,   113,    53,     0,    65,     0,   121,
     0,   110,     0,   109,    65,     0,   109,   121,     0,   109,
   110,     0,   111,     0,   112,     0,    10,   118,   113,    67,
    92,     0,    10,    19,    26,    20,   113,    67,    92,     0,
    10,   113,    67,    92,     0,    11,   118,   113,    67,    92,
     0,    11,    19,    26,    20,   113,    67,    92,     0,    11,
   113,    67,    92,     0,    51,     0,    51,    56,   116,   114,
     0,    51,    56,   116,   114,    54,    78,     0,     0,   115,
     0,   117,     0,   115,   117,     0,   118,    51,     0,    51,
     0,    56,   118,    51,     0,    56,    51,     0,    51,    56,
   118,    51,     0,    51,    56,    51,     0,    19,    62,    20,
     0,    19,    52,    12,    20,     0,    37,    19,   120,    20,
    62,    51,    53,     0,    37,    19,   120,    20,    52,    12,
    51,    53,     0,    37,    62,    51,    53,     0,    37,    52,
    12,    51,    53,     0,    37,    19,    20,    62,    51,    53,
     0,    37,    19,    20,    52,    12,    51,    53,     0,    38,
     0,    39,     0,    40,    51,    53,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   148,   151,   152,   153,   154,   155,   156,   161,   164,   165,
   166,   167,   171,   172,   175,   176,   177,   181,   182,   185,
   186,   189,   190,   193,   194,   197,   198,   201,   202,   205,
   208,   211,   212,   214,   215,   218,   219,   222,   223,   226,
   227,   230,   231,   234,   235,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,   258,   259,   260,   261,   264,   265,   268,
   269,   270,   271,   274,   275,   278,   279,   282,   283,   286,
   287,   291,   292,   296,   299,   302,   303,   304,   305,   310,
   311,   312,   313,   314,   315,   316,   317,   318,   321,   324,
   325,   328,   329,   332,   333,   337,   338,   339,   342,   343,
   346,   347,   350,   351,   352,   353,   354,   355,   358,   361,
   362,   365,   368,   369,   372,   373,   376,   377,   378,   379,
   380,   381,   384,   385,   388,   389,   390,   393,   394,   395,
   398,   399,   400,   401,   402,   403,   406,   407,   410,   411,
   412,   415,   416,   417,   420,   421,   422,   425,   426,   429,
   430,   433,   434,   437,   438,   439,   440,   443,   444,   447,
   448,   449,   450,   451,   452,   455,   456,   459
};

static const char * const yytname[] = {   "$","error","$undefined.","'='","EQUAL",
"NOT_EQUAL","'<'","'>'","LESS_EQUAL","GREATER_EQUAL","'+'","'-'","'*'","'/'",
"UMINUS","UPLUS","UAMPERSAND","'.'","ARROW","'('","')'","'['","']'","INT","CHAR",
"FLOAT","VOID","ENUM","IF","ELSE","WHILE","DO","FOR","IN","INTERFACE","IMPLEMENTATION",
"END","PROPERTY","READONLY","READWRITE","SYNTHESIZE","SELF","SUPER","ID","CLASS",
"RETURN","INTEGER_CONSTANT","STRING_CONSTANT","CHAR_CONSTANT","FLOAT_CONSTANT",
"NSSTRING_CONSTANT","IDENTIFIER","CLASS_NAME","';'","','","'&'","':'","'{'",
"'}'","program","function_and_class_list","function","type","numeric_constant",
"literal","declaration","declaration_list","declaration_list_e","init_declarator_list_e",
"init_declarator_list","init_declarator","declarator","declarator_with_asterisk",
"declarator_with_asterisk_list","declarator_list","init_declarator_with_asterisk",
"init_declarator_with_asterisk_list","init_declarator_with_asterisk_list_e",
"parameter_list","parameter_declaration","expression","expression_e","receiver",
"message_selector","keyword_argument_list_e","keyword_argument_list","keyword_argument",
"if_statement","while_statement","do_while_statement","for_statement","statement",
"compound_statement","statement_list","statement_list_e","class_block","class_interface",
"interface_body","implementation_body","class_implementation","class_declaration_list",
"class_list","instance_variables","instance_variables_declaration","instance_variables_declaration_list",
"interface_declaration_list","method_declaration","class_method_declaration",
"instance_method_declaration","implementation_definition_list","method_definition",
"class_method_definition","instance_method_definition","method_selector","keyword_selector_e",
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
    80,    80,    80,    80,    80,    80,    80,    81,    81,    82,
    82,    82,    82,    83,    83,    84,    84,    85,    85,    86,
    86,    87,    87,    88,    89,    90,    90,    90,    90,    91,
    91,    91,    91,    91,    91,    91,    91,    91,    92,    93,
    93,    94,    94,    95,    95,    96,    96,    96,    97,    97,
    98,    98,    99,    99,    99,    99,    99,    99,   100,   101,
   101,   102,   103,   103,   104,   104,   105,   105,   105,   105,
   105,   105,   106,   106,   107,   107,   107,   108,   108,   108,
   109,   109,   109,   109,   109,   109,   110,   110,   111,   111,
   111,   112,   112,   112,   113,   113,   113,   114,   114,   115,
   115,   116,   116,   117,   117,   117,   117,   118,   118,   119,
   119,   119,   119,   119,   119,   120,   120,   121
};

static const short yyr2[] = {     0,
     1,     1,     1,     1,     2,     2,     2,     5,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
     2,     0,     1,     0,     1,     1,     3,     1,     3,     1,
     2,     1,     3,     1,     3,     1,     3,     1,     3,     0,
     1,     1,     3,     2,     3,     1,     1,     1,     3,     1,
     4,     2,     2,     2,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     0,     1,     1,
     1,     1,     4,     1,     4,     0,     1,     1,     2,     3,
     2,     5,     7,     5,     7,     9,     7,     8,     9,     1,
     2,     3,     1,     1,     1,     1,     1,     1,     3,     1,
     2,     0,     1,     1,     1,     6,     4,     6,     2,     1,
     2,     1,     4,     6,     4,     6,     6,     6,     3,     1,
     3,     3,     3,     3,     1,     2,     1,     1,     1,     2,
     2,     2,     1,     1,     4,     6,     3,     4,     6,     3,
     1,     1,     1,     2,     2,     2,     1,     1,     5,     7,
     4,     5,     7,     4,     1,     4,     6,     0,     1,     1,
     2,     2,     1,     3,     2,     4,     3,     3,     4,     7,
     8,     4,     5,     6,     7,     1,     1,     3
};

static const short yydefact[] = {     0,
     9,    10,    11,     0,     0,    12,     0,     1,     3,     0,
     2,   104,   105,     4,     0,     0,     0,   120,     0,     6,
     5,     7,     0,     0,     0,     0,    40,     0,     0,    24,
   127,     0,     0,   110,   129,   133,   134,   128,     0,     0,
     0,     0,   141,     0,     0,   112,   143,   147,   148,   142,
     0,     0,   119,     0,     0,     0,   155,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    36,    38,    41,     0,
     0,     0,     0,     0,   125,     0,    30,     0,    25,    26,
    28,   107,   109,   130,   131,   132,     0,    22,     0,     0,
    22,     0,     0,     0,     0,   113,   111,   144,   146,   145,
     0,     0,   115,   121,     0,     0,     0,     0,     0,   137,
     0,     0,   140,     0,     0,   176,   177,     0,     0,     0,
    31,     0,     0,    19,     0,     0,    32,     0,    34,     0,
   122,   126,    18,     0,     0,     0,    20,    23,     0,    22,
     0,     0,    22,   178,     0,     0,     0,     0,   102,     8,
     0,     0,   168,     0,   163,   158,     0,   135,     0,   138,
     0,     0,     0,     0,   172,     0,     0,     0,     0,    50,
    14,    15,    16,    13,    17,    46,     0,    48,    47,    37,
    39,   106,   108,   124,     0,   123,     0,    27,    29,     0,
    21,   151,     0,     0,   154,     0,   114,   117,   116,   118,
     0,     0,     0,     0,    68,    90,    98,     0,    93,    94,
    95,    96,   100,    97,   103,     0,     0,   169,     0,     0,
   156,   159,   160,   162,     0,     0,     0,     0,     0,   173,
    53,    52,     0,     0,    71,    70,    72,     0,    54,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    33,    35,    22,   149,    22,   152,     0,     0,
     0,    68,    69,     0,    91,   101,    99,   136,     0,   165,
     0,     0,   161,   139,     0,   174,     0,     0,    49,     0,
    74,     0,    65,    59,    60,    62,    61,    63,    64,    55,
    56,    57,    58,    66,    67,     0,     0,     0,     0,     0,
    46,     0,     0,     0,    92,   167,     0,   164,     0,     0,
   157,    42,   175,     0,   170,     0,     0,    51,   150,   153,
     0,     0,     0,     0,     0,     0,    68,   166,     0,    44,
     0,   171,    73,    76,    82,    84,     0,     0,     0,     0,
     0,    45,    43,     0,     0,    75,    77,    78,     0,     0,
     0,     0,     0,    68,     0,    81,    79,    83,    85,    87,
     0,     0,     0,    80,     0,    88,     0,    89,    86,     0,
     0,     0
};

static const short yydefgoto[] = {   370,
     8,     9,    30,   178,   179,   207,   138,   139,    78,    79,
    80,    81,    67,   128,   130,    68,    69,    70,   311,   312,
   208,   264,   238,   282,   346,   347,   348,   209,   210,   211,
   212,   213,   214,   215,   216,    11,    12,    32,    44,    13,
    14,    19,    45,    75,    76,    34,    35,    36,    37,    46,
    47,    48,    49,    58,   221,   222,   156,   223,    59,    38,
   118,    50
};

static const short yypact[] = {   511,
-32768,-32768,-32768,   -40,   -38,-32768,   -27,   511,-32768,    16,
-32768,-32768,-32768,-32768,   110,   335,   341,-32768,    -9,-32768,
-32768,-32768,     8,     6,    28,   252,    81,    56,   324,    47,
-32768,    64,   455,   455,-32768,-32768,-32768,-32768,    29,    32,
    52,    58,-32768,    75,   471,   471,-32768,-32768,-32768,-32768,
    65,    86,-32768,    63,   106,   347,   101,    76,   117,   431,
   121,   117,    14,   163,   126,   129,   181,-32768,   132,   134,
   378,   378,    81,    47,-32768,   298,-32768,   135,   136,-32768,
   188,-32768,   455,-32768,-32768,-32768,   461,   395,   117,   465,
   395,   117,   140,   384,   384,-32768,   471,-32768,-32768,-32768,
   384,   384,-32768,-32768,   138,   179,   190,   183,    72,-32768,
   152,   192,-32768,   161,   476,-32768,-32768,   196,   166,   165,
-32768,   160,    81,-32768,   185,   186,-32768,     1,-32768,    78,
-32768,-32768,-32768,    47,   160,   204,-32768,   395,   138,   395,
   217,   138,   395,-32768,   202,   207,   210,   211,   287,-32768,
   117,   229,-32768,   497,-32768,   -34,   209,-32768,   117,-32768,
   249,   214,   501,   213,-32768,   160,   160,   160,   131,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   160,-32768,-32768,   683,
-32768,-32768,-32768,-32768,    81,-32768,    47,-32768,   683,   117,
-32768,-32768,   138,   117,-32768,   138,-32768,-32768,-32768,-32768,
   248,   250,   287,   251,   160,-32768,-32768,   276,-32768,-32768,
-32768,-32768,-32768,-32768,   287,   216,   215,-32768,   234,    73,
   237,   -34,-32768,-32768,   239,   245,   247,   289,   254,-32768,
    21,    21,   557,   131,-32768,-32768,-32768,   256,    21,   160,
   160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
   258,   262,-32768,-32768,   395,-32768,   395,-32768,   160,   160,
   269,   421,   683,   261,-32768,-32768,-32768,-32768,    77,-32768,
   265,   507,-32768,-32768,   267,-32768,   273,   272,-32768,   256,
   270,   280,   683,   246,   246,   692,   692,   692,   692,   147,
   147,    21,    21,-32768,-32768,   138,   138,   575,   593,   284,
   294,   331,   302,   301,-32768,-32768,   304,-32768,   345,   310,
   308,-32768,-32768,   315,-32768,   352,   160,-32768,-32768,-32768,
   287,   287,   160,   160,   312,   336,   160,-32768,   326,-32768,
   507,-32768,-32768,   222,   350,-32768,   611,   629,   349,   160,
   327,-32768,-32768,   329,   160,-32768,   -15,-32768,   287,   330,
   287,   160,   647,   160,   160,   683,-32768,-32768,-32768,-32768,
   665,   287,   366,   683,   287,-32768,   287,-32768,-32768,   396,
   400,-32768
};

static const short yypgoto[] = {-32768,
-32768,   397,     0,-32768,-32768,   -13,-32768,   -72,-32768,-32768,
   277,   -69,   -66,-32768,-32768,   281,-32768,-32768,-32768,    82,
  -104,  -250,   172,   130,-32768,-32768,    67,-32768,-32768,-32768,
-32768,  -173,   -99,-32768,-32768,   404,-32768,    79,    11,-32768,
   408,-32768,    -6,   346,-32768,   390,     3,-32768,-32768,   372,
   -36,-32768,-32768,    10,-32768,-32768,-32768,   203,   -24,    12,
-32768,   -23
};


#define	YYLAST		710


static const short yytable[] = {    10,
    62,    31,    43,    43,   129,   150,   127,    10,    33,    99,
    15,   304,    16,    17,    89,    92,   219,   180,   142,    31,
    84,   220,   100,    18,    56,    65,    55,    52,    74,   261,
   189,    43,    98,   115,    61,   344,    85,   251,   252,   192,
   345,   266,   195,    53,    54,    86,    60,    87,    88,    91,
    90,   116,   117,   184,   185,   108,    57,    31,    31,   108,
    99,   231,   232,   233,    33,    33,    23,   193,   111,    84,
   196,   114,   239,   100,   137,    74,   341,   137,    57,    57,
    43,    43,    57,    98,   157,    85,   108,    43,    43,   108,
   154,   154,    66,   256,    86,   154,   258,    77,   140,    82,
   263,   143,    93,   363,   145,   146,    71,    72,    94,    95,
    96,   147,   148,   104,   162,   101,   102,   254,   253,    24,
    25,   103,   155,   270,   191,   105,   137,   306,   110,   137,
   186,   187,     1,     2,     3,   283,   284,   285,   286,   287,
   288,   289,   290,   291,   292,   293,    26,   335,   336,   125,
   126,   234,     6,   108,   298,   299,   109,   263,   249,   250,
   217,    27,   229,   251,   252,    28,    29,    57,   225,   166,
   167,   235,   236,   113,   119,   358,   120,   360,   168,   121,
   169,   237,   296,   122,   297,   123,   124,   133,   366,   134,
   135,   368,   144,   369,   149,   271,   319,   320,   151,   255,
   170,   152,   153,   257,   158,   171,   172,   173,   174,   175,
   176,   159,   334,   160,   177,   163,   164,   165,   337,   338,
   182,   183,   263,   190,   240,   241,   242,   243,   244,   245,
   246,   247,   248,   249,   250,   353,   194,   197,   251,   252,
   356,   137,   198,   137,   307,   199,   200,   361,   218,   263,
   364,   243,   244,   245,   246,   247,   248,   249,   250,   224,
   226,   303,   251,   252,   227,   230,   259,   268,   260,   262,
    63,   310,   344,   267,     1,     2,     3,   345,   240,   241,
   242,   243,   244,   245,   246,   247,   248,   249,   250,   269,
   272,   274,   251,   252,     6,   275,   166,   167,   300,   276,
   277,   318,   323,    64,   278,   168,   281,   169,   294,     1,
     2,     3,   295,   305,   201,   308,   202,   203,   204,   313,
     1,     2,     3,   314,   315,   317,   324,   170,   265,     6,
   310,   205,   171,   172,   173,   174,   175,   176,    27,   206,
     6,   177,   325,   149,    39,    40,     1,     2,     3,    73,
    39,    40,   326,   327,   328,   131,   329,     1,     2,     3,
   330,   331,   339,     1,     2,     3,     6,   332,   340,     1,
     2,     3,   106,   333,    41,    73,   342,     6,   349,   354,
    41,   352,   359,     6,   355,   367,    27,    24,    25,     6,
    42,    29,    27,    39,    40,   371,    51,    29,   107,   372,
     1,     2,     3,   181,    20,   280,     1,     2,     3,   316,
   188,    21,   343,   357,    26,    22,    97,     1,     2,     3,
     6,   132,    83,    41,   273,     0,     6,     0,     0,    27,
   166,   167,     0,     0,    29,    27,     0,     6,     0,   168,
    29,   169,     0,     1,     2,     3,    27,     0,     0,     0,
     0,     0,     0,     1,     2,     3,   112,     0,     0,     0,
     0,   170,     0,     6,    24,    25,   171,   172,   173,   174,
   175,   301,   302,     6,     0,   177,     0,     1,     2,     3,
    39,    40,   107,     1,     2,     3,   136,     1,     2,     3,
   141,    26,     0,     1,     2,     3,     0,     6,     1,     2,
     3,     0,     0,     6,     0,     0,    27,     6,     0,     0,
    41,     0,   107,     6,     0,     0,   107,     0,     6,     1,
     2,     3,    27,     1,     2,     3,     0,   161,     0,     1,
     2,     3,     0,     1,     2,     3,     0,     0,     0,     6,
     0,     0,     0,     6,     4,     5,     0,     0,   107,     6,
     0,     0,   228,     6,     7,     0,     0,     0,   309,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     0,     0,     0,   251,   252,     0,   279,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,     0,     0,
     0,   251,   252,     0,   321,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,     0,     0,     0,   251,
   252,     0,   322,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,     0,     0,     0,   251,   252,     0,
   350,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,     0,     0,     0,   251,   252,     0,   351,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     0,     0,     0,   251,   252,     0,   362,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,     0,     0,
     0,   251,   252,     0,   365,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,     0,     0,     0,   251,
   252,   247,   248,   249,   250,     0,     0,     0,   251,   252
};

static const short yycheck[] = {     0,
    25,    15,    16,    17,    74,   105,    73,     8,    15,    46,
    51,   262,    51,    52,    39,    40,    51,   122,    91,    33,
    34,    56,    46,    51,    19,    26,    19,    17,    29,   203,
   135,    45,    46,    20,    25,    51,    34,    17,    18,   139,
    56,   215,   142,    53,    54,    34,    19,    19,    39,    40,
    19,    38,    39,    53,    54,    56,    51,    71,    72,    60,
    97,   166,   167,   168,    71,    72,    51,   140,    59,    83,
   143,    62,   177,    97,    88,    76,   327,    91,    51,    51,
    94,    95,    51,    97,   109,    83,    87,   101,   102,    90,
    19,    19,    12,   193,    83,    19,   196,    51,    89,    36,
   205,    92,    51,   354,    94,    95,    51,    52,    51,    52,
    36,   101,   102,    51,   115,    51,    52,   187,   185,    10,
    11,    36,    51,    51,   138,    20,   140,    51,    53,   143,
    53,    54,    23,    24,    25,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,    37,   321,   322,    71,
    72,    21,    43,   154,   259,   260,    56,   262,    12,    13,
   151,    52,   163,    17,    18,    56,    57,    51,   159,    10,
    11,    41,    42,    53,    12,   349,    51,   351,    19,    51,
    21,    51,   255,     3,   257,    54,    53,    53,   362,    54,
     3,   365,    53,   367,    57,   220,   296,   297,    20,   190,
    41,    12,    20,   194,    53,    46,    47,    48,    49,    50,
    51,    20,   317,    53,    55,    20,    51,    53,   323,   324,
    36,    36,   327,    20,     3,     4,     5,     6,     7,     8,
     9,    10,    11,    12,    13,   340,    20,    36,    17,    18,
   345,   255,    36,   257,   269,    36,    36,   352,    20,   354,
   355,     6,     7,     8,     9,    10,    11,    12,    13,    51,
    12,   262,    17,    18,    51,    53,    19,    53,    19,    19,
    19,   272,    51,    58,    23,    24,    25,    56,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    56,
    54,    53,    17,    18,    43,    51,    10,    11,    30,    53,
    12,    22,    19,    52,    51,    19,    51,    21,    51,    23,
    24,    25,    51,    53,    28,    51,    30,    31,    32,    53,
    23,    24,    25,    51,    53,    56,    33,    41,    53,    43,
   331,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    43,    55,    12,    57,    10,    11,    23,    24,    25,    52,
    10,    11,    51,    53,    51,    58,    12,    23,    24,    25,
    51,    54,    51,    23,    24,    25,    43,    53,    33,    23,
    24,    25,    26,    22,    40,    52,    51,    43,    29,    53,
    40,    33,    53,    43,    56,    20,    52,    10,    11,    43,
    56,    57,    52,    10,    11,     0,    56,    57,    52,     0,
    23,    24,    25,   123,     8,   234,    23,    24,    25,   280,
   134,     8,   331,   347,    37,     8,    45,    23,    24,    25,
    43,    76,    33,    40,   222,    -1,    43,    -1,    -1,    52,
    10,    11,    -1,    -1,    57,    52,    -1,    43,    -1,    19,
    57,    21,    -1,    23,    24,    25,    52,    -1,    -1,    -1,
    -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,    -1,
    -1,    41,    -1,    43,    10,    11,    46,    47,    48,    49,
    50,    51,    52,    43,    -1,    55,    -1,    23,    24,    25,
    10,    11,    52,    23,    24,    25,    26,    23,    24,    25,
    26,    37,    -1,    23,    24,    25,    -1,    43,    23,    24,
    25,    -1,    -1,    43,    -1,    -1,    52,    43,    -1,    -1,
    40,    -1,    52,    43,    -1,    -1,    52,    -1,    43,    23,
    24,    25,    52,    23,    24,    25,    -1,    52,    -1,    23,
    24,    25,    -1,    23,    24,    25,    -1,    -1,    -1,    43,
    -1,    -1,    -1,    43,    34,    35,    -1,    -1,    52,    43,
    -1,    -1,    52,    43,    44,    -1,    -1,    -1,    52,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
    -1,    -1,    -1,    17,    18,    -1,    20,     3,     4,     5,
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
    18,    10,    11,    12,    13,    -1,    -1,    -1,    17,    18
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
#line 148 "bison_rules_with_code.y"
{yyval.Program = Program_node::createProgramNode(yyvsp[0].Function_and_class_list);;
    break;}
case 2:
#line 151 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassBlock(yyvsp[0].Class_block);;
    break;}
case 3:
#line 152 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromFunction(yyvsp[0].Function);;
    break;}
case 4:
#line 153 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassDeclarationList(yyvsp[0].Class_declaration_list);;
    break;}
case 5:
#line 154 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassBlock(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_block);;
    break;}
case 6:
#line 155 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromFunction(yyvsp[-1].Function_and_class_list, yyvsp[0].Function);;
    break;}
case 7:
#line 156 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassDeclarationList(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_declaration_list);;
    break;}
case 8:
#line 161 "bison_rules_with_code.y"
{yyval.Function = Function_node::createFunctionNode(yyvsp[-4].Type, yyvsp[-3].Identifier, yyvsp[0].Compound_statement);;
    break;}
case 9:
#line 164 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(INT_TYPE);;
    break;}
case 10:
#line 165 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(CHAR_TYPE);;
    break;}
case 11:
#line 166 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(FLOAT_TYPE);;
    break;}
case 12:
#line 167 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(ID_TYPE);;
    break;}
case 13:
#line 171 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromFloat(yyvsp[0].Float_constant);;
    break;}
case 14:
#line 172 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromInteger(yyvsp[0].Integer_constant);;
    break;}
case 15:
#line 175 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(STRING_CONSTANT_TYPE, yyvsp[0].String_constant);;
    break;}
case 16:
#line 176 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(CHAR_CONSTANT_TYPE, yyvsp[0].Char_constant);;
    break;}
case 17:
#line 177 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(NSSTRING_CONSTANT_TYPE, yyvsp[0].NSString_constant);;
    break;}
case 18:
#line 181 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Init_declarator_list);;
    break;}
case 19:
#line 182 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Init_declarator_list);
    break;}
case 20:
#line 185 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::createDeclarationListNode(yyvsp[0].Declaration);;
    break;}
case 21:
#line 186 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::addToDeclarationListNode(yyvsp[-1].Declaration_list, yyvsp[0].Declaration);;
    break;}
case 22:
#line 189 "bison_rules_with_code.y"
{yyval.Declaration_list = NULL;;
    break;}
case 23:
#line 190 "bison_rules_with_code.y"
{yyval.Declaration_list = yyvsp[0].Declaration_list;;
    break;}
case 24:
#line 193 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 25:
#line 194 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 26:
#line 197 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 27:
#line 198 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 28:
#line 201 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Declarator, NULL);;
    break;}
case 29:
#line 202 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Declarator, yyvsp[0].Expression);;
    break;}
case 30:
#line 205 "bison_rules_with_code.y"
{yyval.Declarator = Declarator_node::createDeclaratorNode(yyvsp[0].Identifier);;
    break;}
case 31:
#line 208 "bison_rules_with_code.y"
{yyval.Declarator = Declarator_node::createDeclaratorNode(yyvsp[0].Identifier);;
    break;}
case 32:
#line 211 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Declarator);;
    break;}
case 33:
#line 212 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-2].Declarator_list);;
    break;}
case 34:
#line 214 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Declarator);;
    break;}
case 35:
#line 215 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-2].Declarator_list);;
    break;}
case 36:
#line 218 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Declarator, NULL);;
    break;}
case 37:
#line 219 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Declarator, yyvsp[0].Expression);;
    break;}
case 38:
#line 222 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 39:
#line 223 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 40:
#line 226 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 41:
#line 227 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 42:
#line 230 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::createParameterListNode(yyvsp[0].Parameter_declaration);;
    break;}
case 43:
#line 231 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::addToParameterListNode(yyvsp[-2].Parameter_list, yyvsp[0].Parameter_declaration);;
    break;}
case 44:
#line 234 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(yyvsp[-1].Type, yyvsp[0].Identifier);;
    break;}
case 45:
#line 235 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier),yyvsp[0].Identifier);;
    break;}
case 46:
#line 240 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromIdentifier(yyvsp[0].Identifier);;
    break;}
case 47:
#line 241 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromLiteral(yyvsp[0].Literal);;
    break;}
case 48:
#line 242 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromNumericConstant(yyvsp[0].Numeric_constant);;
    break;}
case 49:
#line 243 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createSimpleExpressionNode(PRIORITY_EXPRESSION_TYPE, yyvsp[-1].Expression);;
    break;}
case 50:
#line 244 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSelf();;
    break;}
case 51:
#line 245 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 52:
#line 246 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UMINUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 53:
#line 247 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UPLUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 54:
#line 248 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UAMPERSAND_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 55:
#line 249 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(PLUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 56:
#line 250 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MINUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 57:
#line 251 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MUL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 58:
#line 252 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(DIV_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 59:
#line 253 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 60:
#line 254 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(NOT_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 61:
#line 255 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 62:
#line 256 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 63:
#line 257 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 64:
#line 258 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 65:
#line 259 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(ASSIGNMENT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 66:
#line 260 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMemberAccessOperator(DOT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Identifier);;
    break;}
case 67:
#line 261 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMemberAccessOperator(ARROW_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Identifier);;
    break;}
case 68:
#line 264 "bison_rules_with_code.y"
{yyval.Expression = NULL;;
    break;}
case 69:
#line 265 "bison_rules_with_code.y"
{yyval.Expression = yyvsp[0].Expression;;
    break;}
case 70:
#line 268 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);;
    break;}
case 71:
#line 269 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);;
    break;}
case 72:
#line 270 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(OBJECT_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 73:
#line 271 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 74:
#line 274 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[0].Identifier, NULL, NULL);;
    break;}
case 75:
#line 275 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Expression, yyvsp[0].Keyword_argument_list);;
    break;}
case 76:
#line 278 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = NULL;;
    break;}
case 77:
#line 279 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = yyvsp[0].Keyword_argument_list;;
    break;}
case 78:
#line 282 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::createKeywordArgumentListNode(yyvsp[0].Keyword_argument);;
    break;}
case 79:
#line 283 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::addToKeywordArgumentListNode(yyvsp[-1].Keyword_argument_list, yyvsp[0].Keyword_argument);;
    break;}
case 80:
#line 286 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITH_IDENTIFIER_KW_ARGUMENT_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 81:
#line 287 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 82:
#line 291 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITHOUT_ALTERNATIVE_IF_TYPE, yyvsp[-2].Expression, yyvsp[0].Statement, NULL);;
    break;}
case 83:
#line 292 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITH_ALTERNATIVE_IF_TYPE, yyvsp[-4].Expression, yyvsp[-2].Statement, yyvsp[0].Statement);;
    break;}
case 84:
#line 296 "bison_rules_with_code.y"
{yyval.While  = While_statement_node::createWhileStatementNode(yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 85:
#line 299 "bison_rules_with_code.y"
{yyval.Do_while = Do_while_statement_node::createDoWhileStatementNode(yyvsp[-2].Expression, yyvsp[-5].Statement);;
    break;}
case 86:
#line 302 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNode(yyvsp[-6].Expression, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 87:
#line 303 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 88:
#line 304 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, yyvsp[-5].Type, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 89:
#line 305 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-6].Identifier), yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 90:
#line 310 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);;
    break;}
case 91:
#line 311 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 92:
#line 312 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 93:
#line 313 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(IF_STATEMENT_TYPE, yyvsp[0].If);;
    break;}
case 94:
#line 314 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(WHILE_STATEMENT_TYPE, yyvsp[0].While);;
    break;}
case 95:
#line 315 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(DO_WHILE_STATEMENT_TYPE, yyvsp[0].Do_while);;
    break;}
case 96:
#line 316 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(FOR_STATEMENT_TYPE, yyvsp[0].For);;
    break;}
case 97:
#line 317 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(COMPOUND_STATEMENT_TYPE, yyvsp[0].Compound_statement);;
    break;}
case 98:
#line 318 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 99:
#line 321 "bison_rules_with_code.y"
{yyval.Compound_statement = Compound_statement_node::createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 100:
#line 324 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::createStatementListNode(yyvsp[0].Statement);;
    break;}
case 101:
#line 325 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::addToStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 102:
#line 328 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 103:
#line 329 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 104:
#line 332 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlockNodeFromInterface(yyvsp[0].Class_interface);;
    break;}
case 105:
#line 333 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlcokNodeFromImplementation(yyvsp[0].Class_implementation);;
    break;}
case 106:
#line 337 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 107:
#line 338 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 108:
#line 339 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 109:
#line 342 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Interface_declaration_list);;
    break;}
case 110:
#line 343 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 111:
#line 346 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Implementation_definition_list);;
    break;}
case 112:
#line 347 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 113:
#line 350 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 114:
#line 351 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 115:
#line 352 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 116:
#line 353 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 117:
#line 354 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 118:
#line 355 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 119:
#line 358 "bison_rules_with_code.y"
{yyval.Class_declaration_list = Class_declaration_list_node::createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 120:
#line 361 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::createClassListNode(yyvsp[0].Identifier);;
    break;}
case 121:
#line 362 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::addToClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 122:
#line 365 "bison_rules_with_code.y"
{yyval.Instance_variables = Instance_variables_node::createInstanceVariablesNode(yyvsp[-1].Instance_variables_declaration_list);;
    break;}
case 123:
#line 368 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Declarator_list);;
    break;}
case 124:
#line 369 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Declarator_list);;
    break;}
case 125:
#line 372 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::createInstanceVariablesDeclarationListNode(yyvsp[0].Instance_variables_declaration);;
    break;}
case 126:
#line 373 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::addToInstanceVariablesDeclarationListNode(yyvsp[-1].Instance_variables_declaration_list, yyvsp[0].Instance_variables_declaration);;
    break;}
case 127:
#line 376 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 128:
#line 377 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 129:
#line 378 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(yyvsp[0].Method_declaration);;
    break;}
case 130:
#line 379 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 131:
#line 380 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 132:
#line 381 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 133:
#line 384 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 134:
#line 385 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 135:
#line 388 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 136:
#line 389 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 137:
#line 390 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 138:
#line 393 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 139:
#line 394 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 140:
#line 395 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 141:
#line 398 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 142:
#line 399 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromSynthesize(yyvsp[0].Synthesize);;
    break;}
case 143:
#line 400 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(yyvsp[0].Method_definition);;
    break;}
case 144:
#line 401 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 145:
#line 402 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addSynthesizeToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Synthesize);;
    break;}
case 146:
#line 403 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 147:
#line 406 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 148:
#line 407 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 149:
#line 410 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 150:
#line 411 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 151:
#line 412 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 152:
#line 415 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 153:
#line 416 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 154:
#line 417 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 155:
#line 420 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 156:
#line 421 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Keyword_declaration, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 157:
#line 422 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Keyword_declaration, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_list);;
    break;}
case 158:
#line 425 "bison_rules_with_code.y"
{yyval.Keyword_selector = NULL;;
    break;}
case 159:
#line 426 "bison_rules_with_code.y"
{yyval.Keyword_selector = yyvsp[0].Keyword_selector;;
    break;}
case 160:
#line 429 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 161:
#line 430 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::addToKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 162:
#line 433 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 163:
#line 434 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 164:
#line 437 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 165:
#line 438 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 166:
#line 439 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 167:
#line 440 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 168:
#line 443 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(yyvsp[-1].Type);;
    break;}
case 169:
#line 444 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier);;
    break;}
case 170:
#line 447 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 171:
#line 448 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-5].Attribute, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 172:
#line 449 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 173:
#line 450 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 174:
#line 451 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 175:
#line 452 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 176:
#line 455 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 177:
#line 456 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READWRITE_ATTRIBUTE_TYPE);;
    break;}
case 178:
#line 459 "bison_rules_with_code.y"
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
#line 462 "bison_rules_with_code.y"


