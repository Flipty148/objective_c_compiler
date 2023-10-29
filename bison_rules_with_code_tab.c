
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



#define	YYFINAL		363
#define	YYFLAG		-32768
#define	YYNTBASE	56

#define YYTRANSLATE(x) ((unsigned)(x) <= 293 ? yytranslate[x] : 118)

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
   474,   477,   480,   482,   484,   490,   498,   503,   509,   517,
   522,   524,   529,   536,   537,   539,   541,   544,   547,   549,
   553,   556,   561,   565,   569,   574,   582,   591,   596,   602,
   609,   617,   619
};

static const short yyrhs[] = {    57,
     0,    92,     0,    58,     0,    97,     0,    57,    92,     0,
    57,    58,     0,    57,    97,     0,    59,    48,    17,    18,
    89,     0,    21,     0,    22,     0,    23,     0,    40,     0,
    46,     0,    43,     0,    44,     0,    45,     0,    47,     0,
    59,    65,    50,     0,    49,    74,    50,     0,    62,     0,
    63,    62,     0,     0,    63,     0,     0,    66,     0,    67,
     0,    66,    51,    67,     0,    68,     0,    68,     3,    77,
     0,    48,     0,    12,    48,     0,    69,     0,    70,    51,
    69,     0,    68,     0,    71,    51,    68,     0,    69,     0,
    69,     3,    77,     0,    72,     0,    73,    51,    72,     0,
     0,    73,     0,    76,     0,    75,    51,    76,     0,    59,
    48,     0,    49,    12,    48,     0,    48,     0,    61,     0,
    60,     0,    17,    77,    18,     0,    38,     0,    19,    79,
    80,    20,     0,    11,    77,     0,    10,    77,     0,    52,
    77,     0,    77,    10,    77,     0,    77,    11,    77,     0,
    77,    12,    77,     0,    77,    13,    77,     0,    77,     4,
    77,     0,    77,     5,    77,     0,    77,     7,    77,     0,
    77,     6,    77,     0,    77,     8,    77,     0,    77,     9,
    77,     0,    77,     3,    77,     0,     0,    77,     0,    39,
     0,    38,     0,    48,     0,    19,    79,    80,    20,     0,
    48,     0,    48,    53,    77,    81,     0,     0,    82,     0,
    83,     0,    82,    83,     0,    48,    53,    77,     0,    53,
    77,     0,    26,    17,    77,    18,    88,     0,    26,    17,
    77,    18,    88,    27,    88,     0,    28,    17,    77,    18,
    88,     0,    29,    88,    28,    17,    77,    18,    50,     0,
    30,    17,    78,    50,    78,    50,    78,    18,    88,     0,
    30,    17,    48,    31,    77,    18,    88,     0,    30,    17,
    59,    48,    31,    77,    18,    88,     0,    30,    17,    49,
    12,    48,    31,    77,    18,    88,     0,    50,     0,    77,
    50,     0,    42,    78,    50,     0,    84,     0,    85,     0,
    86,     0,    87,     0,    89,     0,    62,     0,    54,    91,
    55,     0,    88,     0,    90,    88,     0,     0,    90,     0,
    93,     0,    96,     0,    32,    48,    53,    48,    94,    34,
     0,    32,    48,    94,    34,     0,    32,    48,    53,    49,
    94,    34,     0,    99,   102,     0,   102,     0,    99,   106,
     0,   106,     0,    33,    48,    95,    34,     0,    33,    48,
    53,    48,    95,    34,     0,    33,    49,    95,    34,     0,
    33,    49,    53,    48,    95,    34,     0,    33,    48,    53,
    49,    95,    34,     0,    33,    49,    53,    49,    95,    34,
     0,    41,    98,    50,     0,    48,     0,    98,    51,    48,
     0,    54,   101,    55,     0,    59,    71,    50,     0,    49,
    70,    50,     0,   100,     0,   101,   100,     0,    62,     0,
   116,     0,   103,     0,   102,    62,     0,   102,   103,     0,
   102,   116,     0,   104,     0,   105,     0,    10,   115,   110,
    50,     0,    10,    17,    24,    18,   110,    50,     0,    10,
   110,    50,     0,    11,   115,   110,    50,     0,    11,    17,
    24,    18,   110,    50,     0,    11,   110,    50,     0,    62,
     0,   107,     0,   106,    62,     0,   106,   107,     0,   108,
     0,   109,     0,    10,   115,   110,    64,    89,     0,    10,
    17,    24,    18,   110,    64,    89,     0,    10,   110,    64,
    89,     0,    11,   115,   110,    64,    89,     0,    11,    17,
    24,    18,   110,    64,    89,     0,    11,   110,    64,    89,
     0,    48,     0,    48,    53,   113,   111,     0,    48,    53,
   113,   111,    51,    75,     0,     0,   112,     0,   114,     0,
   112,   114,     0,   115,    48,     0,    48,     0,    53,   115,
    48,     0,    53,    48,     0,    48,    53,   115,    48,     0,
    48,    53,    48,     0,    17,    59,    18,     0,    17,    49,
    12,    18,     0,    35,    17,   117,    18,    59,    48,    50,
     0,    35,    17,   117,    18,    49,    12,    48,    50,     0,
    35,    59,    48,    50,     0,    35,    49,    12,    48,    50,
     0,    35,    17,    18,    59,    48,    50,     0,    35,    17,
    18,    49,    12,    48,    50,     0,    36,     0,    37,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   144,   147,   148,   149,   150,   151,   152,   157,   160,   161,
   162,   163,   167,   168,   171,   172,   173,   177,   178,   181,
   182,   185,   186,   189,   190,   193,   194,   197,   198,   201,
   204,   207,   208,   210,   211,   214,   215,   218,   219,   222,
   223,   226,   227,   230,   231,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   258,   259,   262,   263,   264,
   265,   268,   269,   272,   273,   276,   277,   280,   281,   285,
   286,   290,   293,   296,   297,   298,   299,   304,   305,   306,
   307,   308,   309,   310,   311,   312,   315,   318,   319,   322,
   323,   326,   327,   331,   332,   333,   336,   337,   340,   341,
   344,   345,   346,   347,   348,   349,   352,   355,   356,   359,
   362,   363,   366,   367,   370,   371,   372,   373,   374,   375,
   378,   379,   382,   383,   384,   387,   388,   389,   392,   393,
   394,   395,   398,   399,   402,   403,   404,   407,   408,   409,
   412,   413,   414,   417,   418,   421,   422,   425,   426,   429,
   430,   431,   432,   435,   436,   439,   440,   441,   442,   443,
   444,   447,   448
};

static const char * const yytname[] = {   "$","error","$undefined.","'='","EQUAL",
"NOT_EQUAL","'<'","'>'","LESS_EQUAL","GREATER_EQUAL","'+'","'-'","'*'","'/'",
"UMINUS","UPLUS","UAMPERSAND","'('","')'","'['","']'","INT","CHAR","FLOAT","VOID",
"ENUM","IF","ELSE","WHILE","DO","FOR","IN","INTERFACE","IMPLEMENTATION","END",
"PROPERTY","READONLY","READWRITE","SELF","SUPER","ID","CLASS","RETURN","INTEGER_CONSTANT",
"STRING_CONSTANT","CHAR_CONSTANT","FLOAT_CONSTANT","NSSTRING_CONSTANT","IDENTIFIER",
"CLASS_NAME","';'","','","'&'","':'","'{'","'}'","program","function_and_class_list",
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
"method_type","property","attribute",""
};
#endif

static const short yyr1[] = {     0,
    56,    57,    57,    57,    57,    57,    57,    58,    59,    59,
    59,    59,    60,    60,    61,    61,    61,    62,    62,    63,
    63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
    69,    70,    70,    71,    71,    72,    72,    73,    73,    74,
    74,    75,    75,    76,    76,    77,    77,    77,    77,    77,
    77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
    77,    77,    77,    77,    77,    78,    78,    79,    79,    79,
    79,    80,    80,    81,    81,    82,    82,    83,    83,    84,
    84,    85,    86,    87,    87,    87,    87,    88,    88,    88,
    88,    88,    88,    88,    88,    88,    89,    90,    90,    91,
    91,    92,    92,    93,    93,    93,    94,    94,    95,    95,
    96,    96,    96,    96,    96,    96,    97,    98,    98,    99,
   100,   100,   101,   101,   102,   102,   102,   102,   102,   102,
   103,   103,   104,   104,   104,   105,   105,   105,   106,   106,
   106,   106,   107,   107,   108,   108,   108,   109,   109,   109,
   110,   110,   110,   111,   111,   112,   112,   113,   113,   114,
   114,   114,   114,   115,   115,   116,   116,   116,   116,   116,
   116,   117,   117
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
     2,     2,     1,     1,     5,     7,     4,     5,     7,     4,
     1,     4,     6,     0,     1,     1,     2,     2,     1,     3,
     2,     4,     3,     3,     4,     7,     8,     4,     5,     6,
     7,     1,     1
};

static const short yydefact[] = {     0,
     9,    10,    11,     0,     0,    12,     0,     1,     3,     0,
     2,   102,   103,     4,     0,     0,     0,   118,     0,     6,
     5,     7,     0,     0,     0,     0,    40,     0,     0,    24,
   125,     0,     0,   108,   127,   131,   132,   126,     0,     0,
     0,   139,     0,     0,   110,   140,   143,   144,     0,     0,
   117,     0,     0,     0,   151,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    36,    38,    41,     0,     0,     0,
     0,     0,   123,     0,    30,     0,    25,    26,    28,   105,
   107,   128,   129,   130,     0,    22,     0,     0,    22,     0,
     0,     0,   111,   109,   141,   142,     0,     0,   113,   119,
     0,     0,     0,     0,     0,   135,     0,     0,   138,     0,
     0,   172,   173,     0,     0,     0,    31,     0,     0,    19,
     0,     0,    32,     0,    34,     0,   120,   124,    18,     0,
     0,     0,    20,    23,     0,    22,     0,     0,    22,     0,
     0,     0,     0,   100,     8,     0,     0,   164,     0,   159,
   154,     0,   133,     0,   136,     0,     0,     0,     0,   168,
     0,     0,     0,     0,    50,    14,    15,    16,    13,    17,
    46,     0,    48,    47,    37,    39,   104,   106,   122,     0,
   121,     0,    27,    29,     0,    21,   147,     0,     0,   150,
     0,   112,   115,   114,   116,     0,     0,     0,     0,    66,
    88,    96,     0,    91,    92,    93,    94,    98,    95,   101,
     0,     0,   165,     0,     0,   152,   155,   156,   158,     0,
     0,     0,     0,     0,   169,    53,    52,     0,     0,    69,
    68,    70,     0,    54,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    33,    35,    22,   145,    22,
   148,     0,     0,     0,    66,    67,     0,    89,    99,    97,
   134,     0,   161,     0,     0,   157,   137,     0,   170,     0,
     0,    49,     0,    72,     0,    65,    59,    60,    62,    61,
    63,    64,    55,    56,    57,    58,     0,     0,     0,     0,
     0,    46,     0,     0,     0,    90,   163,     0,   160,     0,
     0,   153,    42,   171,     0,   166,     0,     0,    51,   146,
   149,     0,     0,     0,     0,     0,     0,    66,   162,     0,
    44,     0,   167,    71,    74,    80,    82,     0,     0,     0,
     0,     0,    45,    43,     0,     0,    73,    75,    76,     0,
     0,     0,     0,     0,    66,     0,    79,    77,    81,    83,
    85,     0,     0,     0,    78,     0,    86,     0,    87,    84,
     0,     0,     0
};

static const short yydefgoto[] = {   361,
     8,     9,    30,   173,   174,   202,   134,   135,    76,    77,
    78,    79,    65,   124,   126,    66,    67,    68,   302,   303,
   203,   257,   233,   275,   337,   338,   339,   204,   205,   206,
   207,   208,   209,   210,   211,    11,    12,    32,    43,    13,
    14,    19,    44,    73,    74,    34,    35,    36,    37,    45,
    46,    47,    48,    56,   216,   217,   151,   218,    57,    38,
   114
};

static const short yypact[] = {   500,
-32768,-32768,-32768,   -31,    42,-32768,   -23,   500,-32768,   -17,
-32768,-32768,-32768,-32768,   326,   329,   332,-32768,    59,-32768,
-32768,-32768,    10,   -10,    -6,   110,    32,    73,   107,   -14,
-32768,    12,   460,   460,-32768,-32768,-32768,-32768,    13,    15,
    92,-32768,    21,   464,   464,-32768,-32768,-32768,    97,    33,
-32768,     9,    51,   207,    25,    30,    35,   248,    52,    35,
    50,   100,    67,    86,   133,-32768,   101,    93,   366,   366,
    32,   -14,-32768,     1,-32768,    98,   106,-32768,   157,-32768,
   460,-32768,-32768,-32768,   292,   256,    35,   373,   256,    35,
   381,   381,-32768,   464,-32768,-32768,   381,   381,-32768,-32768,
   108,   148,   166,   172,    18,-32768,   177,   180,-32768,   187,
   439,-32768,-32768,   221,   192,   191,-32768,   421,    32,-32768,
   208,   209,-32768,   104,-32768,   144,-32768,-32768,-32768,   -14,
   421,   226,-32768,   256,   108,   256,   228,   108,   256,   214,
   215,   220,   227,   281,-32768,    35,   239,-32768,   468,-32768,
   -20,   216,-32768,    35,-32768,   254,   225,   471,   218,-32768,
   421,   421,   421,    60,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   421,-32768,-32768,   651,-32768,-32768,-32768,-32768,    32,
-32768,   -14,-32768,   651,    35,-32768,-32768,   108,    35,-32768,
   108,-32768,-32768,-32768,-32768,   257,   259,   281,   264,   421,
-32768,-32768,   210,-32768,-32768,-32768,-32768,-32768,-32768,   281,
   229,   232,-32768,   230,    22,   234,   -20,-32768,-32768,   236,
   245,   244,   283,   251,-32768,-32768,-32768,   539,    60,-32768,
-32768,-32768,   253,-32768,   421,   421,   421,   421,   421,   421,
   421,   421,   421,   421,   421,-32768,-32768,   256,-32768,   256,
-32768,   421,   421,   278,   406,   651,   258,-32768,-32768,-32768,
-32768,    34,-32768,   269,   475,-32768,-32768,   262,-32768,   270,
   284,-32768,   253,   267,   318,   651,   164,   164,   223,   223,
   223,   223,   199,   199,-32768,-32768,   108,   108,   555,   571,
   327,   314,   334,   308,   307,-32768,-32768,   310,-32768,   347,
   312,   311,-32768,-32768,   313,-32768,   344,   421,-32768,-32768,
-32768,   281,   281,   421,   421,   317,   336,   421,-32768,   320,
-32768,   475,-32768,-32768,   197,   343,-32768,   587,   603,   340,
   421,   323,-32768,-32768,   321,   421,-32768,    23,-32768,   281,
   348,   281,   421,   619,   421,   421,   651,-32768,-32768,-32768,
-32768,   635,   281,   372,   651,   281,-32768,   281,-32768,-32768,
   384,   393,-32768
};

static const short yypgoto[] = {-32768,
-32768,   391,     0,-32768,-32768,     3,-32768,   -87,-32768,-32768,
   275,   -69,   -66,-32768,-32768,   288,-32768,-32768,-32768,    87,
   -56,  -241,   171,   135,-32768,-32768,    72,-32768,-32768,-32768,
-32768,  -189,   -95,-32768,-32768,   403,-32768,   156,    28,-32768,
   404,-32768,    -5,   345,-32768,   385,   -22,-32768,-32768,   370,
   -41,-32768,-32768,    78,-32768,-32768,-32768,   217,   -24,   -21,
-32768
};


#define	YYLAST		664


static const short yytable[] = {    10,
    60,   138,   125,    96,   123,   145,    54,    10,   254,    33,
    58,    83,    84,   295,    87,    90,    15,    31,    42,    42,
   259,     1,     2,     3,    18,    63,    53,   214,    72,    85,
    23,    88,   215,    75,   149,    31,    82,    55,   149,   187,
     6,    55,   190,    64,    50,    80,    42,    95,   188,    71,
   149,   191,    96,   104,    93,   127,   100,   104,    83,    84,
    55,   175,    55,    33,    33,   150,    99,   111,   101,   263,
   335,    31,    31,    72,   184,   336,   332,   105,   229,   106,
   152,   297,    55,    82,   104,   112,   113,   104,   133,    16,
    17,   133,   249,    42,    42,   251,    95,   230,   231,    42,
    42,   109,    59,   354,   226,   227,   228,   232,    51,    52,
   157,   115,   247,   246,   116,   234,    86,    89,   140,   141,
    69,    70,   326,   327,   142,   143,    61,     1,     2,     3,
     1,     2,     3,   117,   107,   118,   186,   110,   133,    91,
    92,   133,   120,   256,    97,    98,     6,   129,   104,     6,
   349,   119,   351,   179,   180,    71,   130,   224,    62,   131,
   287,   144,   288,   357,   136,   146,   359,   139,   360,   238,
   239,   240,   241,   242,   243,   244,   245,   147,   276,   277,
   278,   279,   280,   281,   282,   283,   284,   285,   286,   148,
   264,   310,   311,   181,   182,   289,   290,   154,   256,   235,
   236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
   244,   245,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   212,   121,   122,   153,     1,     2,     3,
   102,   220,   242,   243,   244,   245,   155,   298,   158,   159,
   160,   177,   178,   185,   335,   189,     6,   192,   193,   336,
   133,   325,   133,   194,   294,   103,   213,   328,   329,   258,
   195,   256,   248,   219,   301,   221,   250,   225,     1,     2,
     3,   108,   222,   252,   344,   253,     1,     2,     3,   347,
   255,   261,   262,   260,   265,   267,   352,     6,   256,   355,
   161,   162,   268,   269,   270,     6,   103,   163,   271,   164,
   274,     1,     2,     3,    27,   291,   196,   296,   197,   198,
   199,   304,     1,     2,     3,   132,   299,   305,   165,   308,
     6,   301,   200,   166,   167,   168,   169,   170,   171,    27,
   201,     6,   172,   306,   144,    24,    25,   309,    39,    40,
   103,    39,    40,   314,   315,   316,     1,     2,     3,     1,
     2,     3,     1,     2,     3,   317,   318,   319,   320,   321,
    26,   322,   323,   324,   330,     6,   331,   333,     6,   340,
   343,     6,   345,   346,    27,    24,    25,    27,    28,    29,
    27,    41,    29,   362,    49,    29,     1,     2,     3,   358,
    39,    40,   363,     1,     2,     3,   137,   350,    20,   273,
    26,     1,     2,     3,   183,     6,   176,   307,   334,   348,
    21,    22,     6,    94,    27,   161,   162,    81,   128,    29,
     6,   103,   163,     0,   164,     0,     1,     2,     3,    27,
   161,   162,     0,   266,    29,     0,     0,   163,     0,   164,
     0,     0,     0,   165,     0,     6,     0,     0,   166,   167,
   168,   169,   170,   292,   293,     0,     0,   172,   165,     1,
     2,     3,     0,   166,   167,   168,   169,   170,   171,    24,
    25,     0,   172,    39,    40,     0,     0,     0,     6,     0,
     1,     2,     3,     0,     1,     2,     3,   156,     1,     2,
     3,     1,     2,     3,    26,     1,     2,     3,     0,     6,
     0,     0,     0,     6,     0,     0,     0,     6,    27,     0,
     6,     0,    27,     0,     6,     0,   103,     0,     0,   223,
     1,     2,     3,   300,     0,     0,     0,     0,     0,     0,
     0,     4,     5,     0,     0,     0,     0,     0,     0,     6,
     7,   235,   236,   237,   238,   239,   240,   241,   242,   243,
   244,   245,     0,     0,     0,     0,   272,   235,   236,   237,
   238,   239,   240,   241,   242,   243,   244,   245,     0,     0,
     0,     0,   312,   235,   236,   237,   238,   239,   240,   241,
   242,   243,   244,   245,     0,     0,     0,     0,   313,   235,
   236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     0,     0,     0,     0,   341,   235,   236,   237,   238,   239,
   240,   241,   242,   243,   244,   245,     0,     0,     0,     0,
   342,   235,   236,   237,   238,   239,   240,   241,   242,   243,
   244,   245,     0,     0,     0,     0,   353,   235,   236,   237,
   238,   239,   240,   241,   242,   243,   244,   245,     0,     0,
     0,     0,   356,   235,   236,   237,   238,   239,   240,   241,
   242,   243,   244,   245
};

static const short yycheck[] = {     0,
    25,    89,    72,    45,    71,   101,    17,     8,   198,    15,
    17,    34,    34,   255,    39,    40,    48,    15,    16,    17,
   210,    21,    22,    23,    48,    26,    17,    48,    29,    17,
    48,    17,    53,    48,    17,    33,    34,    48,    17,   135,
    40,    48,   138,    12,    17,    34,    44,    45,   136,    49,
    17,   139,    94,    54,    34,    55,    48,    58,    81,    81,
    48,   118,    48,    69,    70,    48,    34,    18,    18,    48,
    48,    69,    70,    74,   131,    53,   318,    53,    19,    50,
   105,    48,    48,    81,    85,    36,    37,    88,    86,    48,
    49,    89,   188,    91,    92,   191,    94,    38,    39,    97,
    98,    50,    25,   345,   161,   162,   163,    48,    50,    51,
   111,    12,   182,   180,    48,   172,    39,    40,    91,    92,
    48,    49,   312,   313,    97,    98,    17,    21,    22,    23,
    21,    22,    23,    48,    57,     3,   134,    60,   136,    48,
    49,   139,    50,   200,    48,    49,    40,    50,   149,    40,
   340,    51,   342,    50,    51,    49,    51,   158,    49,     3,
   248,    54,   250,   353,    87,    18,   356,    90,   358,     6,
     7,     8,     9,    10,    11,    12,    13,    12,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,    18,
   215,   287,   288,    50,    51,   252,   253,    18,   255,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
    12,    13,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,   146,    69,    70,    50,    21,    22,    23,
    24,   154,    10,    11,    12,    13,    50,   262,    18,    48,
    50,    34,    34,    18,    48,    18,    40,    34,    34,    53,
   248,   308,   250,    34,   255,    49,    18,   314,   315,    50,
    34,   318,   185,    48,   265,    12,   189,    50,    21,    22,
    23,    24,    48,    17,   331,    17,    21,    22,    23,   336,
    17,    50,    53,    55,    51,    50,   343,    40,   345,   346,
    10,    11,    48,    50,    12,    40,    49,    17,    48,    19,
    48,    21,    22,    23,    49,    28,    26,    50,    28,    29,
    30,    50,    21,    22,    23,    24,    48,    48,    38,    53,
    40,   322,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    40,    52,    50,    54,    10,    11,    20,    10,    11,
    49,    10,    11,    17,    31,    12,    21,    22,    23,    21,
    22,    23,    21,    22,    23,    48,    50,    48,    12,    48,
    35,    51,    50,    20,    48,    40,    31,    48,    40,    27,
    31,    40,    50,    53,    49,    10,    11,    49,    53,    54,
    49,    53,    54,     0,    53,    54,    21,    22,    23,    18,
    10,    11,     0,    21,    22,    23,    24,    50,     8,   229,
    35,    21,    22,    23,   130,    40,   119,   273,   322,   338,
     8,     8,    40,    44,    49,    10,    11,    33,    74,    54,
    40,    49,    17,    -1,    19,    -1,    21,    22,    23,    49,
    10,    11,    -1,   217,    54,    -1,    -1,    17,    -1,    19,
    -1,    -1,    -1,    38,    -1,    40,    -1,    -1,    43,    44,
    45,    46,    47,    48,    49,    -1,    -1,    52,    38,    21,
    22,    23,    -1,    43,    44,    45,    46,    47,    48,    10,
    11,    -1,    52,    10,    11,    -1,    -1,    -1,    40,    -1,
    21,    22,    23,    -1,    21,    22,    23,    49,    21,    22,
    23,    21,    22,    23,    35,    21,    22,    23,    -1,    40,
    -1,    -1,    -1,    40,    -1,    -1,    -1,    40,    49,    -1,
    40,    -1,    49,    -1,    40,    -1,    49,    -1,    -1,    49,
    21,    22,    23,    49,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,
    41,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    13,    -1,    -1,    -1,    -1,    18,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
    -1,    -1,    18,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
    -1,    -1,    -1,    -1,    18,     3,     4,     5,     6,     7,
     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
    18,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    13,    -1,    -1,    -1,    -1,    18,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
    -1,    -1,    18,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13
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
#line 144 "bison_rules_with_code.y"
{yyval.Program = Program_node::createProgramNode(yyvsp[0].Function_and_class_list);;
    break;}
case 2:
#line 147 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassBlock(yyvsp[0].Class_block);;
    break;}
case 3:
#line 148 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromFunction(yyvsp[0].Function);;
    break;}
case 4:
#line 149 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassDeclarationList(yyvsp[0].Class_declaration_list);;
    break;}
case 5:
#line 150 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassBlock(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_block);;
    break;}
case 6:
#line 151 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromFunction(yyvsp[-1].Function_and_class_list, yyvsp[0].Function);;
    break;}
case 7:
#line 152 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassDeclarationList(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_declaration_list);;
    break;}
case 8:
#line 157 "bison_rules_with_code.y"
{yyval.Function = Function_node::createFunctionNode(yyvsp[-4].Type, yyvsp[-3].Identifier, yyvsp[0].Compound_statement);;
    break;}
case 9:
#line 160 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(INT_TYPE);;
    break;}
case 10:
#line 161 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(CHAR_TYPE);;
    break;}
case 11:
#line 162 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(FLOAT_TYPE);;
    break;}
case 12:
#line 163 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(ID_TYPE);;
    break;}
case 13:
#line 167 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromFloat(yyvsp[0].Float_constant);;
    break;}
case 14:
#line 168 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromInteger(yyvsp[0].Integer_constant);;
    break;}
case 15:
#line 171 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(STRING_CONSTANT_TYPE, yyvsp[0].String_constant);;
    break;}
case 16:
#line 172 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(CHAR_CONSTANT_TYPE, yyvsp[0].Char_constant);;
    break;}
case 17:
#line 173 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(NSSTRING_CONSTANT_TYPE, yyvsp[0].NSString_constant);;
    break;}
case 18:
#line 177 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Init_declarator_list);;
    break;}
case 19:
#line 178 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Init_declarator_list);
    break;}
case 20:
#line 181 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::createDeclarationListNode(yyvsp[0].Declaration);;
    break;}
case 21:
#line 182 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::addToDeclarationListNode(yyvsp[-1].Declaration_list, yyvsp[0].Declaration);;
    break;}
case 22:
#line 185 "bison_rules_with_code.y"
{yyval.Declaration_list = NULL;;
    break;}
case 23:
#line 186 "bison_rules_with_code.y"
{yyval.Declaration_list = yyvsp[0].Declaration_list;;
    break;}
case 24:
#line 189 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 25:
#line 190 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 26:
#line 193 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 27:
#line 194 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 28:
#line 197 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Declarator, NULL);;
    break;}
case 29:
#line 198 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Declarator, yyvsp[0].Expression);;
    break;}
case 30:
#line 201 "bison_rules_with_code.y"
{yyval.Declarator = Declarator_node::createDeclaratorNode(yyvsp[0].Identifier);;
    break;}
case 31:
#line 204 "bison_rules_with_code.y"
{yyval.Declarator = Declarator_node::createDeclaratorNode(yyvsp[0].Identifier);;
    break;}
case 32:
#line 207 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Declarator);;
    break;}
case 33:
#line 208 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-2].Declarator_list);;
    break;}
case 34:
#line 210 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Declarator);;
    break;}
case 35:
#line 211 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-2].Declarator_list);;
    break;}
case 36:
#line 214 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Declarator, NULL);;
    break;}
case 37:
#line 215 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Declarator, yyvsp[0].Expression);;
    break;}
case 38:
#line 218 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 39:
#line 219 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 40:
#line 222 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 41:
#line 223 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 42:
#line 226 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::createParameterListNode(yyvsp[0].Parameter_declaration);;
    break;}
case 43:
#line 227 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::addToParameterListNode(yyvsp[-2].Parameter_list, yyvsp[0].Parameter_declaration);;
    break;}
case 44:
#line 230 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(yyvsp[-1].Type, yyvsp[0].Identifier);;
    break;}
case 45:
#line 231 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier),yyvsp[0].Identifier);;
    break;}
case 46:
#line 236 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromIdentifier(yyvsp[0].Identifier);;
    break;}
case 47:
#line 237 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromLiteral(yyvsp[0].Literal);;
    break;}
case 48:
#line 238 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromNumericConstant(yyvsp[0].Numeric_constant);;
    break;}
case 49:
#line 239 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createSimpleExpressionNode(PRIORITY_EXPRESSION_TYPE, yyvsp[-1].Expression);;
    break;}
case 50:
#line 240 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSelf();;
    break;}
case 51:
#line 241 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 52:
#line 242 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UMINUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 53:
#line 243 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UPLUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 54:
#line 244 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UAMPERSAND_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 55:
#line 245 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(PLUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 56:
#line 246 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MINUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 57:
#line 247 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MUL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 58:
#line 248 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(DIV_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 59:
#line 249 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 60:
#line 250 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(NOT_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 61:
#line 251 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 62:
#line 252 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 63:
#line 253 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 64:
#line 254 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 65:
#line 255 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(ASSIGNMENT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 66:
#line 258 "bison_rules_with_code.y"
{yyval.Expression = NULL;;
    break;}
case 67:
#line 259 "bison_rules_with_code.y"
{yyval.Expression = yyvsp[0].Expression;;
    break;}
case 68:
#line 262 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);;
    break;}
case 69:
#line 263 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);;
    break;}
case 70:
#line 264 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(OBJECT_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 71:
#line 265 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 72:
#line 268 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[0].Identifier, NULL, NULL);;
    break;}
case 73:
#line 269 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Expression, yyvsp[0].Keyword_argument_list);;
    break;}
case 74:
#line 272 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = NULL;;
    break;}
case 75:
#line 273 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = yyvsp[0].Keyword_argument_list;;
    break;}
case 76:
#line 276 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::createKeywordArgumentListNode(yyvsp[0].Keyword_argument);;
    break;}
case 77:
#line 277 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::addToKeywordArgumentListNode(yyvsp[-1].Keyword_argument_list, yyvsp[0].Keyword_argument);;
    break;}
case 78:
#line 280 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITH_IDENTIFIER_KW_ARGUMENT_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 79:
#line 281 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 80:
#line 285 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITHOUT_ALTERNATIVE_IF_TYPE, yyvsp[-2].Expression, yyvsp[0].Statement, NULL);;
    break;}
case 81:
#line 286 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITH_ALTERNATIVE_IF_TYPE, yyvsp[-4].Expression, yyvsp[-2].Statement, yyvsp[0].Statement);;
    break;}
case 82:
#line 290 "bison_rules_with_code.y"
{yyval.While  = While_statement_node::createWhileStatementNode(yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 83:
#line 293 "bison_rules_with_code.y"
{yyval.Do_while = Do_while_statement_node::createDoWhileStatementNode(yyvsp[-2].Expression, yyvsp[-5].Statement);;
    break;}
case 84:
#line 296 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNode(yyvsp[-6].Expression, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 85:
#line 297 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 86:
#line 298 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, yyvsp[-5].Type, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 87:
#line 299 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-6].Identifier), yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 88:
#line 304 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);;
    break;}
case 89:
#line 305 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 90:
#line 306 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 91:
#line 307 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(IF_STATEMENT_TYPE, yyvsp[0].If);;
    break;}
case 92:
#line 308 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(WHILE_STATEMENT_TYPE, yyvsp[0].While);;
    break;}
case 93:
#line 309 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(DO_WHILE_STATEMENT_TYPE, yyvsp[0].Do_while);;
    break;}
case 94:
#line 310 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(FOR_STATEMENT_TYPE, yyvsp[0].For);;
    break;}
case 95:
#line 311 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(COMPOUND_STATEMENT_TYPE, yyvsp[0].Compound_statement);;
    break;}
case 96:
#line 312 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 97:
#line 315 "bison_rules_with_code.y"
{yyval.Compound_statement = Compound_statement_node::createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 98:
#line 318 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::createStatementListNode(yyvsp[0].Statement);;
    break;}
case 99:
#line 319 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::addToStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 100:
#line 322 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 101:
#line 323 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 102:
#line 326 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlockNodeFromInterface(yyvsp[0].Class_interface);;
    break;}
case 103:
#line 327 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlcokNodeFromImplementation(yyvsp[0].Class_implementation);;
    break;}
case 104:
#line 331 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 105:
#line 332 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 106:
#line 333 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 107:
#line 336 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Interface_declaration_list);;
    break;}
case 108:
#line 337 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 109:
#line 340 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Implementation_definition_list);;
    break;}
case 110:
#line 341 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 111:
#line 344 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 112:
#line 345 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 113:
#line 346 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 114:
#line 347 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 115:
#line 348 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 116:
#line 349 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 117:
#line 352 "bison_rules_with_code.y"
{yyval.Class_declaration_list = Class_declaration_list_node::createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 118:
#line 355 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::createClassListNode(yyvsp[0].Identifier);;
    break;}
case 119:
#line 356 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::addToClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 120:
#line 359 "bison_rules_with_code.y"
{yyval.Instance_variables = Instance_variables_node::createInstanceVariablesNode(yyvsp[-1].Instance_variables_declaration_list);;
    break;}
case 121:
#line 362 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Declarator_list);;
    break;}
case 122:
#line 363 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Declarator_list);;
    break;}
case 123:
#line 366 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::createInstanceVariablesDeclarationListNode(yyvsp[0].Instance_variables_declaration);;
    break;}
case 124:
#line 367 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::addToInstanceVariablesDeclarationListNode(yyvsp[-1].Instance_variables_declaration_list, yyvsp[0].Instance_variables_declaration);;
    break;}
case 125:
#line 370 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 126:
#line 371 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 127:
#line 372 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(yyvsp[0].Method_declaration);;
    break;}
case 128:
#line 373 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 129:
#line 374 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 130:
#line 375 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 131:
#line 378 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 132:
#line 379 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 133:
#line 382 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 134:
#line 383 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 135:
#line 384 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 136:
#line 387 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 137:
#line 388 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 138:
#line 389 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 139:
#line 392 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 140:
#line 393 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(yyvsp[0].Method_definition);;
    break;}
case 141:
#line 394 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 142:
#line 395 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 143:
#line 398 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 144:
#line 399 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 145:
#line 402 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 146:
#line 403 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 147:
#line 404 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 148:
#line 407 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 149:
#line 408 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 150:
#line 409 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 151:
#line 412 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 152:
#line 413 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Keyword_declaration, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 153:
#line 414 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Keyword_declaration, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_list);;
    break;}
case 154:
#line 417 "bison_rules_with_code.y"
{yyval.Keyword_selector = NULL;;
    break;}
case 155:
#line 418 "bison_rules_with_code.y"
{yyval.Keyword_selector = yyvsp[0].Keyword_selector;;
    break;}
case 156:
#line 421 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 157:
#line 422 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::addToKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 158:
#line 425 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 159:
#line 426 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 160:
#line 429 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 161:
#line 430 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 162:
#line 431 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 163:
#line 432 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 164:
#line 435 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(yyvsp[-1].Type);;
    break;}
case 165:
#line 436 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier);;
    break;}
case 166:
#line 439 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 167:
#line 440 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-5].Attribute, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 168:
#line 441 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 169:
#line 442 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 170:
#line 443 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 171:
#line 444 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 172:
#line 447 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 173:
#line 448 "bison_rules_with_code.y"
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
#line 451 "bison_rules_with_code.y"


