
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
#define	SYNTHESIZE	282
#define	SELF	283
#define	SUPER	284
#define	ID	285
#define	CLASS	286
#define	RETURN	287
#define	INTEGER_CONSTANT	288
#define	STRING_CONSTANT	289
#define	CHAR_CONSTANT	290
#define	FLOAT_CONSTANT	291
#define	NSSTRING_CONSTANT	292
#define	IDENTIFIER	293
#define	CLASS_NAME	294

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



#define	YYFINAL		368
#define	YYFLAG		-32768
#define	YYNTBASE	57

#define YYTRANSLATE(x) ((unsigned)(x) <= 294 ? yytranslate[x] : 120)

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
     0,     2,     4,     6,     8,    11,    14,    17,    23,    25,
    27,    29,    31,    33,    35,    37,    39,    41,    45,    49,
    51,    54,    55,    57,    58,    60,    62,    66,    68,    72,
    74,    77,    79,    83,    85,    89,    91,    95,    97,   101,
   102,   104,   106,   110,   113,   117,   119,   121,   123,   127,
   129,   134,   137,   140,   143,   147,   151,   155,   159,   163,
   167,   171,   175,   179,   183,   187,   188,   190,   192,   194,
   196,   201,   203,   208,   209,   211,   213,   216,   220,   223,
   229,   237,   243,   251,   261,   269,   278,   288,   290,   293,
   297,   299,   301,   303,   305,   307,   309,   313,   315,   318,
   319,   321,   323,   325,   332,   337,   344,   347,   349,   352,
   354,   359,   366,   371,   378,   385,   392,   396,   398,   402,
   406,   410,   414,   416,   419,   421,   423,   425,   428,   431,
   434,   436,   438,   443,   450,   454,   459,   466,   470,   472,
   474,   476,   479,   482,   485,   487,   489,   495,   503,   508,
   514,   522,   527,   529,   534,   541,   542,   544,   546,   549,
   552,   554,   558,   561,   566,   570,   574,   579,   587,   596,
   601,   607,   614,   622,   624,   626
};

static const short yyrhs[] = {    58,
     0,    93,     0,    59,     0,    98,     0,    58,    93,     0,
    58,    59,     0,    58,    98,     0,    60,    49,    17,    18,
    90,     0,    21,     0,    22,     0,    23,     0,    41,     0,
    47,     0,    44,     0,    45,     0,    46,     0,    48,     0,
    60,    66,    51,     0,    50,    75,    51,     0,    63,     0,
    64,    63,     0,     0,    64,     0,     0,    67,     0,    68,
     0,    67,    52,    68,     0,    69,     0,    69,     3,    78,
     0,    49,     0,    12,    49,     0,    70,     0,    71,    52,
    70,     0,    69,     0,    72,    52,    69,     0,    70,     0,
    70,     3,    78,     0,    73,     0,    74,    52,    73,     0,
     0,    74,     0,    77,     0,    76,    52,    77,     0,    60,
    49,     0,    50,    12,    49,     0,    49,     0,    62,     0,
    61,     0,    17,    78,    18,     0,    39,     0,    19,    80,
    81,    20,     0,    11,    78,     0,    10,    78,     0,    53,
    78,     0,    78,    10,    78,     0,    78,    11,    78,     0,
    78,    12,    78,     0,    78,    13,    78,     0,    78,     4,
    78,     0,    78,     5,    78,     0,    78,     7,    78,     0,
    78,     6,    78,     0,    78,     8,    78,     0,    78,     9,
    78,     0,    78,     3,    78,     0,     0,    78,     0,    40,
     0,    39,     0,    49,     0,    19,    80,    81,    20,     0,
    49,     0,    49,    54,    78,    82,     0,     0,    83,     0,
    84,     0,    83,    84,     0,    49,    54,    78,     0,    54,
    78,     0,    26,    17,    78,    18,    89,     0,    26,    17,
    78,    18,    89,    27,    89,     0,    28,    17,    78,    18,
    89,     0,    29,    89,    28,    17,    78,    18,    51,     0,
    30,    17,    79,    51,    79,    51,    79,    18,    89,     0,
    30,    17,    49,    31,    78,    18,    89,     0,    30,    17,
    60,    49,    31,    78,    18,    89,     0,    30,    17,    50,
    12,    49,    31,    78,    18,    89,     0,    51,     0,    78,
    51,     0,    43,    79,    51,     0,    85,     0,    86,     0,
    87,     0,    88,     0,    90,     0,    63,     0,    55,    92,
    56,     0,    89,     0,    91,    89,     0,     0,    91,     0,
    94,     0,    97,     0,    32,    49,    54,    49,    95,    34,
     0,    32,    49,    95,    34,     0,    32,    49,    54,    50,
    95,    34,     0,   100,   103,     0,   103,     0,   100,   107,
     0,   107,     0,    33,    49,    96,    34,     0,    33,    49,
    54,    49,    96,    34,     0,    33,    50,    96,    34,     0,
    33,    50,    54,    49,    96,    34,     0,    33,    49,    54,
    50,    96,    34,     0,    33,    50,    54,    50,    96,    34,
     0,    42,    99,    51,     0,    49,     0,    99,    52,    49,
     0,    55,   102,    56,     0,    60,    72,    51,     0,    50,
    71,    51,     0,   101,     0,   102,   101,     0,    63,     0,
   117,     0,   104,     0,   103,    63,     0,   103,   104,     0,
   103,   117,     0,   105,     0,   106,     0,    10,   116,   111,
    51,     0,    10,    17,    24,    18,   111,    51,     0,    10,
   111,    51,     0,    11,   116,   111,    51,     0,    11,    17,
    24,    18,   111,    51,     0,    11,   111,    51,     0,    63,
     0,   119,     0,   108,     0,   107,    63,     0,   107,   119,
     0,   107,   108,     0,   109,     0,   110,     0,    10,   116,
   111,    65,    90,     0,    10,    17,    24,    18,   111,    65,
    90,     0,    10,   111,    65,    90,     0,    11,   116,   111,
    65,    90,     0,    11,    17,    24,    18,   111,    65,    90,
     0,    11,   111,    65,    90,     0,    49,     0,    49,    54,
   114,   112,     0,    49,    54,   114,   112,    52,    76,     0,
     0,   113,     0,   115,     0,   113,   115,     0,   116,    49,
     0,    49,     0,    54,   116,    49,     0,    54,    49,     0,
    49,    54,   116,    49,     0,    49,    54,    49,     0,    17,
    60,    18,     0,    17,    50,    12,    18,     0,    35,    17,
   118,    18,    60,    49,    51,     0,    35,    17,   118,    18,
    50,    12,    49,    51,     0,    35,    60,    49,    51,     0,
    35,    50,    12,    49,    51,     0,    35,    17,    18,    60,
    49,    51,     0,    35,    17,    18,    50,    12,    49,    51,
     0,    36,     0,    37,     0,    38,    49,    51,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   147,   150,   151,   152,   153,   154,   155,   160,   163,   164,
   165,   166,   170,   171,   174,   175,   176,   180,   181,   184,
   185,   188,   189,   192,   193,   196,   197,   200,   201,   204,
   207,   210,   211,   213,   214,   217,   218,   221,   222,   225,
   226,   229,   230,   233,   234,   239,   240,   241,   242,   243,
   244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
   254,   255,   256,   257,   258,   261,   262,   265,   266,   267,
   268,   271,   272,   275,   276,   279,   280,   283,   284,   288,
   289,   293,   296,   299,   300,   301,   302,   307,   308,   309,
   310,   311,   312,   313,   314,   315,   318,   321,   322,   325,
   326,   329,   330,   334,   335,   336,   339,   340,   343,   344,
   347,   348,   349,   350,   351,   352,   355,   358,   359,   362,
   365,   366,   369,   370,   373,   374,   375,   376,   377,   378,
   381,   382,   385,   386,   387,   390,   391,   392,   395,   396,
   397,   398,   399,   400,   403,   404,   407,   408,   409,   412,
   413,   414,   417,   418,   419,   422,   423,   426,   427,   430,
   431,   434,   435,   436,   437,   440,   441,   444,   445,   446,
   447,   448,   449,   452,   453,   456
};

static const char * const yytname[] = {   "$","error","$undefined.","'='","EQUAL",
"NOT_EQUAL","'<'","'>'","LESS_EQUAL","GREATER_EQUAL","'+'","'-'","'*'","'/'",
"UMINUS","UPLUS","UAMPERSAND","'('","')'","'['","']'","INT","CHAR","FLOAT","VOID",
"ENUM","IF","ELSE","WHILE","DO","FOR","IN","INTERFACE","IMPLEMENTATION","END",
"PROPERTY","READONLY","READWRITE","SYNTHESIZE","SELF","SUPER","ID","CLASS","RETURN",
"INTEGER_CONSTANT","STRING_CONSTANT","CHAR_CONSTANT","FLOAT_CONSTANT","NSSTRING_CONSTANT",
"IDENTIFIER","CLASS_NAME","';'","','","'&'","':'","'{'","'}'","program","function_and_class_list",
"function","type","numeric_constant","literal","declaration","declaration_list",
"declaration_list_e","init_declarator_list_e","init_declarator_list","init_declarator",
"declarator","declarator_with_asterisk","declarator_with_asterisk_list","declarator_list",
"init_declarator_with_asterisk","init_declarator_with_asterisk_list","init_declarator_with_asterisk_list_e",
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
    57,    58,    58,    58,    58,    58,    58,    59,    60,    60,
    60,    60,    61,    61,    62,    62,    62,    63,    63,    64,
    64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
    70,    71,    71,    72,    72,    73,    73,    74,    74,    75,
    75,    76,    76,    77,    77,    78,    78,    78,    78,    78,
    78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
    78,    78,    78,    78,    78,    79,    79,    80,    80,    80,
    80,    81,    81,    82,    82,    83,    83,    84,    84,    85,
    85,    86,    87,    88,    88,    88,    88,    89,    89,    89,
    89,    89,    89,    89,    89,    89,    90,    91,    91,    92,
    92,    93,    93,    94,    94,    94,    95,    95,    96,    96,
    97,    97,    97,    97,    97,    97,    98,    99,    99,   100,
   101,   101,   102,   102,   103,   103,   103,   103,   103,   103,
   104,   104,   105,   105,   105,   106,   106,   106,   107,   107,
   107,   107,   107,   107,   108,   108,   109,   109,   109,   110,
   110,   110,   111,   111,   111,   112,   112,   113,   113,   114,
   114,   115,   115,   115,   115,   116,   116,   117,   117,   117,
   117,   117,   117,   118,   118,   119
};

static const short yyr2[] = {     0,
     1,     1,     1,     1,     2,     2,     2,     5,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
     2,     0,     1,     0,     1,     1,     3,     1,     3,     1,
     2,     1,     3,     1,     3,     1,     3,     1,     3,     0,
     1,     1,     3,     2,     3,     1,     1,     1,     3,     1,
     4,     2,     2,     2,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     0,     1,     1,     1,     1,
     4,     1,     4,     0,     1,     1,     2,     3,     2,     5,
     7,     5,     7,     9,     7,     8,     9,     1,     2,     3,
     1,     1,     1,     1,     1,     1,     3,     1,     2,     0,
     1,     1,     1,     6,     4,     6,     2,     1,     2,     1,
     4,     6,     4,     6,     6,     6,     3,     1,     3,     3,
     3,     3,     1,     2,     1,     1,     1,     2,     2,     2,
     1,     1,     4,     6,     3,     4,     6,     3,     1,     1,
     1,     2,     2,     2,     1,     1,     5,     7,     4,     5,
     7,     4,     1,     4,     6,     0,     1,     1,     2,     2,
     1,     3,     2,     4,     3,     3,     4,     7,     8,     4,
     5,     6,     7,     1,     1,     3
};

static const short yydefact[] = {     0,
     9,    10,    11,     0,     0,    12,     0,     1,     3,     0,
     2,   102,   103,     4,     0,     0,     0,   118,     0,     6,
     5,     7,     0,     0,     0,     0,    40,     0,     0,    24,
   125,     0,     0,   108,   127,   131,   132,   126,     0,     0,
     0,     0,   139,     0,     0,   110,   141,   145,   146,   140,
     0,     0,   117,     0,     0,     0,   153,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    36,    38,    41,     0,
     0,     0,     0,     0,   123,     0,    30,     0,    25,    26,
    28,   105,   107,   128,   129,   130,     0,    22,     0,     0,
    22,     0,     0,     0,     0,   111,   109,   142,   144,   143,
     0,     0,   113,   119,     0,     0,     0,     0,     0,   135,
     0,     0,   138,     0,     0,   174,   175,     0,     0,     0,
    31,     0,     0,    19,     0,     0,    32,     0,    34,     0,
   120,   124,    18,     0,     0,     0,    20,    23,     0,    22,
     0,     0,    22,   176,     0,     0,     0,     0,   100,     8,
     0,     0,   166,     0,   161,   156,     0,   133,     0,   136,
     0,     0,     0,     0,   170,     0,     0,     0,     0,    50,
    14,    15,    16,    13,    17,    46,     0,    48,    47,    37,
    39,   104,   106,   122,     0,   121,     0,    27,    29,     0,
    21,   149,     0,     0,   152,     0,   112,   115,   114,   116,
     0,     0,     0,     0,    66,    88,    96,     0,    91,    92,
    93,    94,    98,    95,   101,     0,     0,   167,     0,     0,
   154,   157,   158,   160,     0,     0,     0,     0,     0,   171,
    53,    52,     0,     0,    69,    68,    70,     0,    54,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    33,    35,    22,   147,    22,   150,     0,     0,     0,    66,
    67,     0,    89,    99,    97,   134,     0,   163,     0,     0,
   159,   137,     0,   172,     0,     0,    49,     0,    72,     0,
    65,    59,    60,    62,    61,    63,    64,    55,    56,    57,
    58,     0,     0,     0,     0,     0,    46,     0,     0,     0,
    90,   165,     0,   162,     0,     0,   155,    42,   173,     0,
   168,     0,     0,    51,   148,   151,     0,     0,     0,     0,
     0,     0,    66,   164,     0,    44,     0,   169,    71,    74,
    80,    82,     0,     0,     0,     0,     0,    45,    43,     0,
     0,    73,    75,    76,     0,     0,     0,     0,     0,    66,
     0,    79,    77,    81,    83,    85,     0,     0,     0,    78,
     0,    86,     0,    87,    84,     0,     0,     0
};

static const short yydefgoto[] = {   366,
     8,     9,    30,   178,   179,   207,   138,   139,    78,    79,
    80,    81,    67,   128,   130,    68,    69,    70,   307,   308,
   208,   262,   238,   280,   342,   343,   344,   209,   210,   211,
   212,   213,   214,   215,   216,    11,    12,    32,    44,    13,
    14,    19,    45,    75,    76,    34,    35,    36,    37,    46,
    47,    48,    49,    58,   221,   222,   156,   223,    59,    38,
   118,    50
};

static const short yypact[] = {   465,
-32768,-32768,-32768,    -7,   -19,-32768,    -5,   465,-32768,    -1,
-32768,-32768,-32768,-32768,   281,   287,   322,-32768,    66,-32768,
-32768,-32768,    48,    -4,     2,   297,    60,    79,   246,    44,
-32768,    80,   411,   411,-32768,-32768,-32768,-32768,    22,    84,
    87,   121,-32768,   100,    85,    85,-32768,-32768,-32768,-32768,
   123,   128,-32768,   106,   147,   403,   120,   127,   131,   407,
   134,   131,    16,   180,   148,   166,   213,-32768,   165,   170,
   329,   329,    60,    44,-32768,    81,-32768,   171,   183,-32768,
   234,-32768,   411,-32768,-32768,-32768,   414,   428,   131,   418,
   428,   131,   187,   344,   344,-32768,    85,-32768,-32768,-32768,
   344,   344,-32768,-32768,   184,   229,   241,   237,   102,-32768,
   208,   244,-32768,   215,   444,-32768,-32768,   253,   224,   226,
-32768,   142,    60,-32768,   255,   259,-32768,   125,-32768,   158,
-32768,-32768,-32768,    44,   142,   257,-32768,   428,   184,   428,
   276,   184,   428,-32768,   261,   265,   266,   267,   235,-32768,
   131,   288,-32768,   449,-32768,    -8,   256,-32768,   131,-32768,
   295,   262,   452,   264,-32768,   142,   142,   142,    -2,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   142,-32768,-32768,   619,
-32768,-32768,-32768,-32768,    60,-32768,    44,-32768,   619,   131,
-32768,-32768,   184,   131,-32768,   184,-32768,-32768,-32768,-32768,
   296,   300,   235,   304,   142,-32768,-32768,   221,-32768,-32768,
-32768,-32768,-32768,-32768,   235,   268,   272,-32768,   258,   107,
   274,    -8,-32768,-32768,   278,   285,   279,   334,   299,-32768,
-32768,-32768,   507,    -2,-32768,-32768,-32768,   307,-32768,   142,
   142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
-32768,-32768,   428,-32768,   428,-32768,   142,   142,   321,   370,
   619,   302,-32768,-32768,-32768,-32768,   115,-32768,   308,   459,
-32768,-32768,   310,-32768,   309,   311,-32768,   307,   305,   348,
   619,   394,   394,    99,    99,    99,    99,    15,    15,-32768,
-32768,   184,   184,   523,   539,   352,   340,   361,   325,   324,
-32768,-32768,   337,-32768,   366,   339,   331,-32768,-32768,   345,
-32768,   375,   142,-32768,-32768,-32768,   235,   235,   142,   142,
   341,   367,   142,-32768,   359,-32768,   459,-32768,-32768,   195,
   383,-32768,   555,   571,   381,   142,   346,-32768,-32768,   389,
   142,-32768,     1,-32768,   235,   362,   235,   142,   587,   142,
   142,   619,-32768,-32768,-32768,-32768,   603,   235,   427,   619,
   235,-32768,   235,-32768,-32768,   447,   454,-32768
};

static const short yypgoto[] = {-32768,
-32768,   448,     0,-32768,-32768,   -13,-32768,   -86,-32768,-32768,
   326,   -67,   -64,-32768,-32768,   335,-32768,-32768,-32768,   135,
  -100,  -250,   242,   185,-32768,-32768,   136,-32768,-32768,-32768,
-32768,  -179,   -99,-32768,-32768,   469,-32768,   140,    -3,-32768,
   475,-32768,     8,   408,-32768,   456,   -22,-32768,-32768,   446,
   -35,-32768,-32768,    24,-32768,-32768,-32768,   270,   -24,    -9,
-32768,   -28
};


#define	YYLAST		632


static const short yytable[] = {    10,
    62,    31,    43,    43,   142,   150,   129,    10,   127,   300,
    99,    85,    56,    52,    89,    92,   234,   100,    60,    31,
    84,   180,    33,   259,    86,    65,   249,   250,    74,    16,
    17,    43,    98,   115,   189,   264,   235,   236,    87,   192,
   219,    15,   195,    18,    57,   220,   237,    23,    61,   340,
    57,   116,   117,   193,   341,   108,   196,    31,    31,   108,
    85,    99,    88,    91,    55,   231,   232,   233,   100,    84,
    57,    66,   337,    86,   137,    74,   239,   137,    33,    33,
    43,    43,   111,    98,   157,   114,   108,    43,    43,   108,
   145,   146,    77,   254,    39,    40,   256,   147,   148,   359,
    90,     1,     2,     3,   261,     1,     2,     3,   247,   248,
   249,   250,   140,    82,   162,   143,    53,    54,   154,   252,
   251,     6,    41,   154,   191,     6,   137,    71,    72,   137,
    73,   154,    57,    96,    27,    93,   131,   331,   332,   281,
   282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
   155,   166,   167,   108,   104,   268,   294,   295,   168,   261,
   169,   103,   229,   302,   105,   354,   292,   356,   293,    94,
    95,   101,   102,   109,   217,   184,   185,   110,   362,    57,
   170,   364,   225,   365,   113,   171,   172,   173,   174,   175,
   176,   119,   315,   316,   177,   269,   120,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   186,   187,
   125,   126,   330,   253,   121,   122,   123,   255,   333,   334,
   124,   133,   261,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   134,   349,   135,   144,   149,   137,
   352,   137,   303,   340,   166,   167,   151,   357,   341,   261,
   360,   168,   152,   169,   153,     1,     2,     3,   158,   299,
   201,   159,   202,   203,   204,   160,     1,     2,     3,   306,
   163,   263,   164,   170,   190,     6,   165,   205,   171,   172,
   173,   174,   175,   176,    27,   206,     6,   177,   182,   149,
    24,    25,   183,   194,   197,    73,    39,    40,   198,   199,
   200,     1,     2,     3,   224,   218,   226,     1,     2,     3,
   227,   267,   257,    63,   230,    26,   258,     1,     2,     3,
   260,     6,   266,   265,    41,   270,   306,     6,   272,   274,
    27,    39,    40,   273,    28,    29,    27,     6,    24,    25,
    42,    29,     1,     2,     3,   275,    64,   276,   296,     1,
     2,     3,   301,    39,    40,   279,   304,   310,   313,    41,
   309,   311,     6,    26,     1,     2,     3,   314,   319,     6,
   320,    27,   321,   322,   323,    51,    29,   325,    27,   166,
   167,    41,   327,    29,     6,   324,   168,   326,   169,   335,
     1,     2,     3,    27,   329,   328,   350,   336,    29,   243,
   244,   245,   246,   247,   248,   249,   250,   338,   170,   345,
     6,   348,   355,   171,   172,   173,   174,   175,   297,   298,
    24,    25,   177,     1,     2,     3,   106,     1,     2,     3,
   112,     1,     2,     3,     1,     2,     3,   136,     1,     2,
     3,   141,   351,     6,   363,    26,   367,     6,     1,     2,
     3,     6,   107,   368,     6,    20,   107,   181,     6,   188,
    27,   339,   312,   107,     1,     2,     3,   107,     6,     1,
     2,     3,     1,     2,     3,   278,    21,    27,   353,     1,
     2,     3,    22,   132,     6,     1,     2,     3,    83,     6,
    97,   271,     6,   161,     0,     0,     4,     5,   107,     6,
     0,   228,     0,     0,     0,     6,     7,     0,   305,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     0,     0,     0,     0,   277,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,     0,     0,     0,     0,
   317,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,     0,     0,     0,     0,   318,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,     0,     0,
     0,     0,   346,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,     0,     0,     0,     0,   347,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     0,     0,     0,     0,   358,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,     0,     0,     0,     0,
   361,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250
};

static const short yycheck[] = {     0,
    25,    15,    16,    17,    91,   105,    74,     8,    73,   260,
    46,    34,    17,    17,    39,    40,    19,    46,    17,    33,
    34,   122,    15,   203,    34,    26,    12,    13,    29,    49,
    50,    45,    46,    18,   135,   215,    39,    40,    17,   139,
    49,    49,   142,    49,    49,    54,    49,    49,    25,    49,
    49,    36,    37,   140,    54,    56,   143,    71,    72,    60,
    83,    97,    39,    40,    17,   166,   167,   168,    97,    83,
    49,    12,   323,    83,    88,    76,   177,    91,    71,    72,
    94,    95,    59,    97,   109,    62,    87,   101,   102,    90,
    94,    95,    49,   193,    10,    11,   196,   101,   102,   350,
    17,    21,    22,    23,   205,    21,    22,    23,    10,    11,
    12,    13,    89,    34,   115,    92,    51,    52,    17,   187,
   185,    41,    38,    17,   138,    41,   140,    49,    50,   143,
    50,    17,    49,    34,    50,    49,    56,   317,   318,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
    49,    10,    11,   154,    49,    49,   257,   258,    17,   260,
    19,    34,   163,    49,    18,   345,   253,   347,   255,    49,
    50,    49,    50,    54,   151,    51,    52,    51,   358,    49,
    39,   361,   159,   363,    51,    44,    45,    46,    47,    48,
    49,    12,   292,   293,    53,   220,    49,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    51,    52,
    71,    72,   313,   190,    49,     3,    52,   194,   319,   320,
    51,    51,   323,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    52,   336,     3,    51,    55,   253,
   341,   255,   267,    49,    10,    11,    18,   348,    54,   350,
   351,    17,    12,    19,    18,    21,    22,    23,    51,   260,
    26,    18,    28,    29,    30,    51,    21,    22,    23,   270,
    18,    51,    49,    39,    18,    41,    51,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    41,    53,    34,    55,
    10,    11,    34,    18,    34,    50,    10,    11,    34,    34,
    34,    21,    22,    23,    49,    18,    12,    21,    22,    23,
    49,    54,    17,    17,    51,    35,    17,    21,    22,    23,
    17,    41,    51,    56,    38,    52,   327,    41,    51,    51,
    50,    10,    11,    49,    54,    55,    50,    41,    10,    11,
    54,    55,    21,    22,    23,    12,    50,    49,    28,    21,
    22,    23,    51,    10,    11,    49,    49,    49,    54,    38,
    51,    51,    41,    35,    21,    22,    23,    20,    17,    41,
    31,    50,    12,    49,    51,    54,    55,    12,    50,    10,
    11,    38,    52,    55,    41,    49,    17,    49,    19,    49,
    21,    22,    23,    50,    20,    51,    51,    31,    55,     6,
     7,     8,     9,    10,    11,    12,    13,    49,    39,    27,
    41,    31,    51,    44,    45,    46,    47,    48,    49,    50,
    10,    11,    53,    21,    22,    23,    24,    21,    22,    23,
    24,    21,    22,    23,    21,    22,    23,    24,    21,    22,
    23,    24,    54,    41,    18,    35,     0,    41,    21,    22,
    23,    41,    50,     0,    41,     8,    50,   123,    41,   134,
    50,   327,   278,    50,    21,    22,    23,    50,    41,    21,
    22,    23,    21,    22,    23,   234,     8,    50,   343,    21,
    22,    23,     8,    76,    41,    21,    22,    23,    33,    41,
    45,   222,    41,    50,    -1,    -1,    32,    33,    50,    41,
    -1,    50,    -1,    -1,    -1,    41,    42,    -1,    50,     3,
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
     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
    18,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    13
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
#line 147 "bison_rules_with_code.y"
{yyval.Program = Program_node::createProgramNode(yyvsp[0].Function_and_class_list);;
    break;}
case 2:
#line 150 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassBlock(yyvsp[0].Class_block);;
    break;}
case 3:
#line 151 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromFunction(yyvsp[0].Function);;
    break;}
case 4:
#line 152 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassDeclarationList(yyvsp[0].Class_declaration_list);;
    break;}
case 5:
#line 153 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassBlock(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_block);;
    break;}
case 6:
#line 154 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromFunction(yyvsp[-1].Function_and_class_list, yyvsp[0].Function);;
    break;}
case 7:
#line 155 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassDeclarationList(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_declaration_list);;
    break;}
case 8:
#line 160 "bison_rules_with_code.y"
{yyval.Function = Function_node::createFunctionNode(yyvsp[-4].Type, yyvsp[-3].Identifier, yyvsp[0].Compound_statement);;
    break;}
case 9:
#line 163 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(INT_TYPE);;
    break;}
case 10:
#line 164 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(CHAR_TYPE);;
    break;}
case 11:
#line 165 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(FLOAT_TYPE);;
    break;}
case 12:
#line 166 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(ID_TYPE);;
    break;}
case 13:
#line 170 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromFloat(yyvsp[0].Float_constant);;
    break;}
case 14:
#line 171 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromInteger(yyvsp[0].Integer_constant);;
    break;}
case 15:
#line 174 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(STRING_CONSTANT_TYPE, yyvsp[0].String_constant);;
    break;}
case 16:
#line 175 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(CHAR_CONSTANT_TYPE, yyvsp[0].Char_constant);;
    break;}
case 17:
#line 176 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(NSSTRING_CONSTANT_TYPE, yyvsp[0].NSString_constant);;
    break;}
case 18:
#line 180 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Init_declarator_list);;
    break;}
case 19:
#line 181 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Init_declarator_list);
    break;}
case 20:
#line 184 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::createDeclarationListNode(yyvsp[0].Declaration);;
    break;}
case 21:
#line 185 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::addToDeclarationListNode(yyvsp[-1].Declaration_list, yyvsp[0].Declaration);;
    break;}
case 22:
#line 188 "bison_rules_with_code.y"
{yyval.Declaration_list = NULL;;
    break;}
case 23:
#line 189 "bison_rules_with_code.y"
{yyval.Declaration_list = yyvsp[0].Declaration_list;;
    break;}
case 24:
#line 192 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 25:
#line 193 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 26:
#line 196 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 27:
#line 197 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 28:
#line 200 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Declarator, NULL);;
    break;}
case 29:
#line 201 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Declarator, yyvsp[0].Expression);;
    break;}
case 30:
#line 204 "bison_rules_with_code.y"
{yyval.Declarator = Declarator_node::createDeclaratorNode(yyvsp[0].Identifier);;
    break;}
case 31:
#line 207 "bison_rules_with_code.y"
{yyval.Declarator = Declarator_node::createDeclaratorNode(yyvsp[0].Identifier);;
    break;}
case 32:
#line 210 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Declarator);;
    break;}
case 33:
#line 211 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-2].Declarator_list);;
    break;}
case 34:
#line 213 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Declarator);;
    break;}
case 35:
#line 214 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-2].Declarator_list);;
    break;}
case 36:
#line 217 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Declarator, NULL);;
    break;}
case 37:
#line 218 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Declarator, yyvsp[0].Expression);;
    break;}
case 38:
#line 221 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 39:
#line 222 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 40:
#line 225 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 41:
#line 226 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 42:
#line 229 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::createParameterListNode(yyvsp[0].Parameter_declaration);;
    break;}
case 43:
#line 230 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::addToParameterListNode(yyvsp[-2].Parameter_list, yyvsp[0].Parameter_declaration);;
    break;}
case 44:
#line 233 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(yyvsp[-1].Type, yyvsp[0].Identifier);;
    break;}
case 45:
#line 234 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier),yyvsp[0].Identifier);;
    break;}
case 46:
#line 239 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromIdentifier(yyvsp[0].Identifier);;
    break;}
case 47:
#line 240 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromLiteral(yyvsp[0].Literal);;
    break;}
case 48:
#line 241 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromNumericConstant(yyvsp[0].Numeric_constant);;
    break;}
case 49:
#line 242 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createSimpleExpressionNode(PRIORITY_EXPRESSION_TYPE, yyvsp[-1].Expression);;
    break;}
case 50:
#line 243 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSelf();;
    break;}
case 51:
#line 244 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 52:
#line 245 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UMINUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 53:
#line 246 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UPLUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 54:
#line 247 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UAMPERSAND_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 55:
#line 248 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(PLUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 56:
#line 249 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MINUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 57:
#line 250 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MUL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 58:
#line 251 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(DIV_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 59:
#line 252 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 60:
#line 253 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(NOT_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 61:
#line 254 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 62:
#line 255 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 63:
#line 256 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 64:
#line 257 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 65:
#line 258 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(ASSIGNMENT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 66:
#line 261 "bison_rules_with_code.y"
{yyval.Expression = NULL;;
    break;}
case 67:
#line 262 "bison_rules_with_code.y"
{yyval.Expression = yyvsp[0].Expression;;
    break;}
case 68:
#line 265 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);;
    break;}
case 69:
#line 266 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);;
    break;}
case 70:
#line 267 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(OBJECT_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 71:
#line 268 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 72:
#line 271 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[0].Identifier, NULL, NULL);;
    break;}
case 73:
#line 272 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Expression, yyvsp[0].Keyword_argument_list);;
    break;}
case 74:
#line 275 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = NULL;;
    break;}
case 75:
#line 276 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = yyvsp[0].Keyword_argument_list;;
    break;}
case 76:
#line 279 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::createKeywordArgumentListNode(yyvsp[0].Keyword_argument);;
    break;}
case 77:
#line 280 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::addToKeywordArgumentListNode(yyvsp[-1].Keyword_argument_list, yyvsp[0].Keyword_argument);;
    break;}
case 78:
#line 283 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITH_IDENTIFIER_KW_ARGUMENT_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 79:
#line 284 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 80:
#line 288 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITHOUT_ALTERNATIVE_IF_TYPE, yyvsp[-2].Expression, yyvsp[0].Statement, NULL);;
    break;}
case 81:
#line 289 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITH_ALTERNATIVE_IF_TYPE, yyvsp[-4].Expression, yyvsp[-2].Statement, yyvsp[0].Statement);;
    break;}
case 82:
#line 293 "bison_rules_with_code.y"
{yyval.While  = While_statement_node::createWhileStatementNode(yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 83:
#line 296 "bison_rules_with_code.y"
{yyval.Do_while = Do_while_statement_node::createDoWhileStatementNode(yyvsp[-2].Expression, yyvsp[-5].Statement);;
    break;}
case 84:
#line 299 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNode(yyvsp[-6].Expression, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 85:
#line 300 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 86:
#line 301 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, yyvsp[-5].Type, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 87:
#line 302 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-6].Identifier), yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 88:
#line 307 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);;
    break;}
case 89:
#line 308 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 90:
#line 309 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 91:
#line 310 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(IF_STATEMENT_TYPE, yyvsp[0].If);;
    break;}
case 92:
#line 311 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(WHILE_STATEMENT_TYPE, yyvsp[0].While);;
    break;}
case 93:
#line 312 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(DO_WHILE_STATEMENT_TYPE, yyvsp[0].Do_while);;
    break;}
case 94:
#line 313 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(FOR_STATEMENT_TYPE, yyvsp[0].For);;
    break;}
case 95:
#line 314 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(COMPOUND_STATEMENT_TYPE, yyvsp[0].Compound_statement);;
    break;}
case 96:
#line 315 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 97:
#line 318 "bison_rules_with_code.y"
{yyval.Compound_statement = Compound_statement_node::createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 98:
#line 321 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::createStatementListNode(yyvsp[0].Statement);;
    break;}
case 99:
#line 322 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::addToStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 100:
#line 325 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 101:
#line 326 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 102:
#line 329 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlockNodeFromInterface(yyvsp[0].Class_interface);;
    break;}
case 103:
#line 330 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlcokNodeFromImplementation(yyvsp[0].Class_implementation);;
    break;}
case 104:
#line 334 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 105:
#line 335 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 106:
#line 336 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 107:
#line 339 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Interface_declaration_list);;
    break;}
case 108:
#line 340 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 109:
#line 343 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Implementation_definition_list);;
    break;}
case 110:
#line 344 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 111:
#line 347 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 112:
#line 348 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 113:
#line 349 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 114:
#line 350 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 115:
#line 351 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 116:
#line 352 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 117:
#line 355 "bison_rules_with_code.y"
{yyval.Class_declaration_list = Class_declaration_list_node::createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 118:
#line 358 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::createClassListNode(yyvsp[0].Identifier);;
    break;}
case 119:
#line 359 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::addToClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 120:
#line 362 "bison_rules_with_code.y"
{yyval.Instance_variables = Instance_variables_node::createInstanceVariablesNode(yyvsp[-1].Instance_variables_declaration_list);;
    break;}
case 121:
#line 365 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Declarator_list);;
    break;}
case 122:
#line 366 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Declarator_list);;
    break;}
case 123:
#line 369 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::createInstanceVariablesDeclarationListNode(yyvsp[0].Instance_variables_declaration);;
    break;}
case 124:
#line 370 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::addToInstanceVariablesDeclarationListNode(yyvsp[-1].Instance_variables_declaration_list, yyvsp[0].Instance_variables_declaration);;
    break;}
case 125:
#line 373 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 126:
#line 374 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 127:
#line 375 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(yyvsp[0].Method_declaration);;
    break;}
case 128:
#line 376 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 129:
#line 377 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 130:
#line 378 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 131:
#line 381 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 132:
#line 382 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 133:
#line 385 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 134:
#line 386 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 135:
#line 387 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 136:
#line 390 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 137:
#line 391 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 138:
#line 392 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 139:
#line 395 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 140:
#line 396 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromSynthesize(yyvsp[0].Synthesize);;
    break;}
case 141:
#line 397 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(yyvsp[0].Method_definition);;
    break;}
case 142:
#line 398 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 143:
#line 399 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addSynthesizeToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Synthesize);;
    break;}
case 144:
#line 400 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 145:
#line 403 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 146:
#line 404 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 147:
#line 407 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 148:
#line 408 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 149:
#line 409 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 150:
#line 412 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 151:
#line 413 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 152:
#line 414 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 153:
#line 417 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 154:
#line 418 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Keyword_declaration, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 155:
#line 419 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Keyword_declaration, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_list);;
    break;}
case 156:
#line 422 "bison_rules_with_code.y"
{yyval.Keyword_selector = NULL;;
    break;}
case 157:
#line 423 "bison_rules_with_code.y"
{yyval.Keyword_selector = yyvsp[0].Keyword_selector;;
    break;}
case 158:
#line 426 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 159:
#line 427 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::addToKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 160:
#line 430 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 161:
#line 431 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 162:
#line 434 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 163:
#line 435 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 164:
#line 436 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 165:
#line 437 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 166:
#line 440 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(yyvsp[-1].Type);;
    break;}
case 167:
#line 441 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier);;
    break;}
case 168:
#line 444 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 169:
#line 445 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-5].Attribute, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 170:
#line 446 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 171:
#line 447 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 172:
#line 448 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 173:
#line 449 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 174:
#line 452 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 175:
#line 453 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READWRITE_ATTRIBUTE_TYPE);;
    break;}
case 176:
#line 456 "bison_rules_with_code.y"
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
#line 459 "bison_rules_with_code.y"


