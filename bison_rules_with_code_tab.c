
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
     0,     2,     4,     6,     8,    11,    14,    17,    23,    25,
    27,    29,    31,    34,    36,    38,    40,    42,    44,    48,
    50,    53,    54,    56,    57,    59,    61,    65,    67,    71,
    73,    77,    80,    82,    84,    86,    90,    92,    97,   100,
   103,   106,   110,   114,   118,   122,   126,   130,   134,   138,
   142,   146,   150,   151,   153,   155,   157,   159,   161,   163,
   165,   168,   172,   175,   181,   189,   195,   203,   213,   221,
   230,   232,   235,   239,   241,   243,   245,   247,   249,   251,
   255,   257,   260,   261,   263,   265,   267,   274,   279,   286,
   289,   291,   294,   296,   301,   308,   313,   320,   327,   334,
   338,   340,   344,   348,   350,   352,   354,   357,   360,   363,
   365,   367,   372,   379,   383,   388,   395,   399,   401,   403,
   405,   408,   411,   414,   416,   418,   424,   432,   437,   443,
   451,   456,   458,   460,   464,   466,   469,   473,   476,   481,
   485,   489,   497,   499
};

static const short yyrhs[] = {    57,
     0,    84,     0,    58,     0,    89,     0,    57,    84,     0,
    57,    58,     0,    57,    89,     0,    59,    48,    17,    18,
    81,     0,    21,     0,    22,     0,    23,     0,    40,     0,
    49,    12,     0,    46,     0,    43,     0,    44,     0,    45,
     0,    47,     0,    59,    65,    50,     0,    62,     0,    63,
    62,     0,     0,    63,     0,     0,    66,     0,    67,     0,
    66,    51,    67,     0,    48,     0,    48,     3,    70,     0,
    69,     0,    68,    51,    69,     0,    59,    48,     0,    48,
     0,    61,     0,    60,     0,    17,    70,    18,     0,    38,
     0,    19,    72,    73,    20,     0,    11,    70,     0,    10,
    70,     0,    52,    70,     0,    70,    10,    70,     0,    70,
    11,    70,     0,    70,    12,    70,     0,    70,    13,    70,
     0,    70,     4,    70,     0,    70,     5,    70,     0,    70,
     7,    70,     0,    70,     6,    70,     0,    70,     8,    70,
     0,    70,     9,    70,     0,    70,     3,    70,     0,     0,
    70,     0,    39,     0,    38,     0,    49,     0,    48,     0,
    74,     0,    75,     0,    74,    75,     0,    48,    53,    70,
     0,    53,    70,     0,    26,    17,    70,    18,    80,     0,
    26,    17,    70,    18,    80,    27,    80,     0,    28,    17,
    70,    18,    80,     0,    29,    80,    28,    17,    70,    18,
    50,     0,    30,    17,    71,    50,    71,    50,    71,    18,
    80,     0,    30,    17,    48,    31,    70,    18,    80,     0,
    30,    17,    59,    48,    31,    70,    18,    80,     0,    50,
     0,    70,    50,     0,    42,    71,    50,     0,    76,     0,
    77,     0,    78,     0,    79,     0,    81,     0,    62,     0,
    54,    83,    55,     0,    80,     0,    82,    80,     0,     0,
    82,     0,    85,     0,    88,     0,    32,    48,    53,    48,
    86,    34,     0,    32,    48,    86,    34,     0,    32,    48,
    53,    49,    86,    34,     0,    91,    92,     0,    92,     0,
    91,    96,     0,    96,     0,    33,    48,    87,    34,     0,
    33,    48,    53,    48,    87,    34,     0,    33,    49,    87,
    34,     0,    33,    49,    53,    48,    87,    34,     0,    33,
    48,    53,    49,    87,    34,     0,    33,    49,    53,    49,
    87,    34,     0,    41,    90,    50,     0,    48,     0,    90,
    51,    48,     0,    54,    63,    55,     0,    62,     0,   104,
     0,    93,     0,    92,    62,     0,    92,    93,     0,    92,
   104,     0,    94,     0,    95,     0,    10,   103,   100,    50,
     0,    10,    17,    24,    18,   100,    50,     0,    10,   100,
    50,     0,    11,   103,   100,    50,     0,    11,    17,    24,
    18,   100,    50,     0,    11,   100,    50,     0,    62,     0,
   104,     0,    97,     0,    96,    62,     0,    96,    97,     0,
    96,   104,     0,    98,     0,    99,     0,    10,   103,   100,
    64,    81,     0,    10,    17,    24,    18,   100,    64,    81,
     0,    10,   100,    64,    81,     0,    11,   103,   100,    64,
    81,     0,    11,    17,    24,    18,   100,    64,    81,     0,
    11,   100,    64,    81,     0,    48,     0,   101,     0,   101,
    51,    68,     0,   102,     0,   101,   102,     0,    53,   103,
    48,     0,    53,    48,     0,    48,    53,   103,    48,     0,
    48,    53,    48,     0,    17,    59,    18,     0,    35,    17,
   105,    18,    59,    48,    50,     0,    36,     0,    37,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   136,   139,   140,   141,   142,   143,   144,   149,   152,   153,
   154,   155,   156,   160,   161,   164,   165,   166,   170,   173,
   174,   177,   178,   181,   182,   185,   186,   189,   190,   193,
   194,   197,   202,   203,   204,   205,   206,   207,   208,   209,
   210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
   220,   221,   224,   225,   228,   229,   230,   233,   234,   237,
   238,   241,   242,   246,   247,   251,   254,   257,   258,   259,
   264,   265,   266,   267,   268,   269,   270,   271,   272,   275,
   278,   279,   282,   283,   286,   287,   291,   292,   293,   296,
   297,   300,   301,   304,   305,   306,   307,   308,   309,   312,
   315,   316,   319,   322,   323,   324,   325,   326,   327,   330,
   331,   334,   335,   336,   339,   340,   341,   344,   345,   346,
   347,   348,   349,   352,   353,   356,   357,   358,   361,   362,
   363,   366,   367,   368,   371,   372,   375,   376,   377,   378,
   381,   384,   387,   388
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
"parameter_list","parameter_declaration","expression","expression_e","receiver",
"message_selector","keyword_argument_list","keyword_argument","if_statement",
"while_statement","do_while_statement","for_statement","statement","compound_statement",
"statement_list","statement_list_e","class_block","class_interface","interface_body",
"implementation_body","class_implementation","class_declaration_list","class_list",
"instance_variables","interface_declaration_list","method_declaration","class_method_declaration",
"instance_method_declaration","implementation_definition_list","method_definition",
"class_method_definition","instance_method_definition","method_selector","keyword_selector",
"keyword_declaration","method_type","property","attribute",""
};
#endif

static const short yyr1[] = {     0,
    56,    57,    57,    57,    57,    57,    57,    58,    59,    59,
    59,    59,    59,    60,    60,    61,    61,    61,    62,    63,
    63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
    68,    69,    70,    70,    70,    70,    70,    70,    70,    70,
    70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
    70,    70,    71,    71,    72,    72,    72,    73,    73,    74,
    74,    75,    75,    76,    76,    77,    78,    79,    79,    79,
    80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
    82,    82,    83,    83,    84,    84,    85,    85,    85,    86,
    86,    87,    87,    88,    88,    88,    88,    88,    88,    89,
    90,    90,    91,    92,    92,    92,    92,    92,    92,    93,
    93,    94,    94,    94,    95,    95,    95,    96,    96,    96,
    96,    96,    96,    97,    97,    98,    98,    98,    99,    99,
    99,   100,   100,   100,   101,   101,   102,   102,   102,   102,
   103,   104,   105,   105
};

static const short yyr2[] = {     0,
     1,     1,     1,     1,     2,     2,     2,     5,     1,     1,
     1,     1,     2,     1,     1,     1,     1,     1,     3,     1,
     2,     0,     1,     0,     1,     1,     3,     1,     3,     1,
     3,     2,     1,     1,     1,     3,     1,     4,     2,     2,
     2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     0,     1,     1,     1,     1,     1,     1,     1,
     2,     3,     2,     5,     7,     5,     7,     9,     7,     8,
     1,     2,     3,     1,     1,     1,     1,     1,     1,     3,
     1,     2,     0,     1,     1,     1,     6,     4,     6,     2,
     1,     2,     1,     4,     6,     4,     6,     6,     6,     3,
     1,     3,     3,     1,     1,     1,     2,     2,     2,     1,
     1,     4,     6,     3,     4,     6,     3,     1,     1,     1,
     2,     2,     2,     1,     1,     5,     7,     4,     5,     7,
     4,     1,     1,     3,     1,     2,     3,     2,     4,     3,
     3,     7,     1,     1
};

static const short yydefact[] = {     0,
     9,    10,    11,     0,     0,    12,     0,     0,     1,     3,
     0,     2,    85,    86,     4,     0,     0,     0,   101,     0,
    13,     6,     5,     7,     0,     0,     0,     0,     0,     0,
    24,   104,     0,     0,    91,   106,   110,   111,   105,     0,
     0,     0,   118,     0,     0,    93,   120,   124,   125,   119,
     0,     0,   100,     0,     0,     0,   132,     0,     0,   133,
   135,     0,     0,     0,     0,     0,     0,     0,    20,     0,
    28,     0,    25,    26,    88,    90,   107,   108,   109,     0,
    22,     0,     0,    22,     0,     0,     0,    94,    92,   121,
   122,   123,     0,     0,    96,   102,     0,     0,     0,     0,
     0,   138,     0,   114,     0,     0,   136,     0,     0,   117,
     0,   143,   144,     0,     0,     0,   103,    21,     0,    19,
     0,     0,    23,     0,    22,     0,     0,    22,     0,     0,
     0,     0,    83,     8,     0,   141,   140,     0,   137,     0,
   134,    30,   112,     0,   115,     0,    87,    89,     0,     0,
     0,     0,    37,    15,    16,    17,    14,    18,    33,     0,
    35,    34,    29,    27,     0,   128,     0,     0,   131,     0,
    95,    98,    97,    99,     0,     0,     0,     0,    53,    71,
    79,     0,    74,    75,    76,    77,    81,    78,    84,     0,
     0,   139,    32,     0,     0,     0,    40,    39,     0,    56,
    55,    57,     0,    41,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    22,   126,    22,   129,     0,
     0,     0,    53,    54,     0,    72,    82,    80,   113,    31,
   116,     0,    36,    58,     0,     0,    59,    60,    52,    46,
    47,    49,    48,    50,    51,    42,    43,    44,    45,     0,
     0,     0,     0,     0,    33,     0,     0,    73,   142,     0,
    63,    38,     0,    61,   127,   130,     0,     0,     0,     0,
     0,    53,    62,    64,    66,     0,     0,     0,     0,     0,
     0,     0,     0,    53,    65,    67,    69,     0,     0,    70,
     0,    68,     0,     0,     0
};

static const short yydefgoto[] = {   293,
     9,    10,    31,   161,   162,   181,   123,   124,    72,    73,
    74,   141,   142,   182,   225,   203,   236,   237,   238,   183,
   184,   185,   186,   187,   188,   189,   190,    12,    13,    33,
    44,    14,    15,    20,    45,    35,    36,    37,    38,    46,
    47,    48,    49,    59,    60,    61,    62,    50,   114
};

static const short yypact[] = {   383,
-32768,-32768,-32768,   -44,   -11,-32768,   -30,    22,   383,-32768,
    -8,-32768,-32768,-32768,-32768,   157,   177,   285,-32768,   -40,
-32768,-32768,-32768,-32768,    27,   -12,    43,    47,    46,   326,
    19,-32768,    41,   387,   387,-32768,-32768,-32768,-32768,    59,
    72,    96,-32768,    54,   391,   391,-32768,-32768,-32768,-32768,
   133,    68,-32768,    57,    93,   397,    64,     6,    69,    33,
-32768,   -31,   420,    76,   -31,   149,   288,   288,-32768,   224,
   134,    89,   100,-32768,-32768,   387,-32768,-32768,-32768,   426,
   326,   -31,   430,   326,   -31,   291,   291,-32768,   391,-32768,
-32768,-32768,   291,   291,-32768,-32768,   117,   159,   171,     9,
   326,-32768,   145,-32768,    64,   326,-32768,   152,   186,-32768,
   155,-32768,-32768,   195,   161,   180,-32768,-32768,   348,-32768,
    19,   197,   326,   117,   326,   198,   117,   326,   188,   190,
   191,   194,   240,-32768,   -31,-32768,-32768,   172,-32768,   181,
   201,-32768,-32768,   -31,-32768,   326,-32768,-32768,   348,   348,
   348,    -6,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   348,
-32768,-32768,   573,-32768,   -31,-32768,   117,   -31,-32768,   117,
-32768,-32768,-32768,-32768,   215,   232,   240,   236,   348,-32768,
-32768,   231,-32768,-32768,-32768,-32768,-32768,-32768,   240,   193,
   204,-32768,-32768,   326,   205,   208,-32768,-32768,   477,-32768,
-32768,-32768,   -24,-32768,   348,   348,   348,   348,   348,   348,
   348,   348,   348,   348,   348,   326,-32768,   326,-32768,   348,
   348,   230,   333,   573,   210,-32768,-32768,-32768,-32768,-32768,
-32768,   217,-32768,   212,   348,   251,    44,-32768,   573,   123,
   123,   137,   137,   137,   137,   178,   178,-32768,-32768,   117,
   117,   493,   509,   255,   243,   227,   226,-32768,-32768,   348,
   573,-32768,   212,-32768,-32768,-32768,   240,   240,   348,   348,
   246,   348,   573,   264,-32768,   525,   541,   348,   247,   240,
   250,   240,   557,   348,-32768,-32768,-32768,   240,   275,-32768,
   240,-32768,   303,   304,-32768
};

static const short yypgoto[] = {-32768,
-32768,   296,     0,-32768,-32768,   -15,   286,   -78,-32768,-32768,
   196,-32768,   121,   -51,  -207,-32768,-32768,-32768,    81,-32768,
-32768,-32768,-32768,  -164,   -85,-32768,-32768,   310,-32768,   140,
    28,-32768,   312,-32768,    -9,   290,   -14,-32768,-32768,   277,
   -38,-32768,-32768,     8,-32768,   267,   -13,   107,-32768
};


#define	YYLAST		586


static const short yytable[] = {    11,
    32,    43,    43,    16,    56,   127,    34,    91,    11,    53,
    54,   134,   222,    65,    69,   257,    57,    19,    32,    77,
    78,    58,   101,   234,   227,   101,    82,    85,   235,    43,
    90,   200,   201,    21,    64,    57,    17,    18,   166,    25,
    58,   169,   202,    55,   103,    52,   167,    81,    84,   170,
    91,    32,    32,   102,   118,    99,   137,    34,    34,    63,
    77,    78,    99,    66,   279,    69,    71,   163,    69,   108,
    43,    43,   111,    90,    75,    80,   289,    43,    43,    99,
   105,   217,    99,   106,   219,    58,   138,    88,    83,   125,
    57,   263,   128,    67,    68,    58,   235,   197,   198,   199,
    99,    95,   274,   275,    96,   140,    57,   118,   204,    69,
    97,    58,    69,   129,   130,   285,   100,   287,   104,    57,
   131,   132,    39,   290,    58,   110,   292,   224,   208,   209,
   210,   211,   212,   213,   214,   215,   119,   250,   120,   251,
    39,    79,   191,    86,    87,   196,   212,   213,   214,   215,
   121,   195,    92,   239,   240,   241,   242,   243,   244,   245,
   246,   247,   248,   249,   265,   266,    26,    27,   252,   253,
   133,   224,   216,    39,    39,   218,   135,     1,     2,     3,
    93,    94,    79,   261,   112,   113,    40,    41,   136,   214,
   215,    28,   139,   140,   147,    92,     6,     1,     2,     3,
    69,   143,    69,   144,   145,     8,   115,   116,   273,    29,
    30,    28,   146,   148,   165,   168,     6,   276,   277,   192,
   224,   171,   256,   172,   173,     8,   283,   174,   193,    42,
    30,   220,   224,   205,   206,   207,   208,   209,   210,   211,
   212,   213,   214,   215,     1,     2,     3,   228,   221,   149,
   150,   194,   223,   229,   231,   232,   151,   254,   152,   258,
     1,     2,     3,     6,   260,   175,   259,   176,   177,   178,
   262,   269,     8,   270,   271,   272,   278,   153,   117,     6,
   226,   179,   154,   155,   156,   157,   158,   159,     8,   180,
   280,   160,   291,   133,    40,    41,   284,    26,    27,   286,
    40,    41,   294,   295,    22,     1,     2,     3,     1,     2,
     3,     1,     2,     3,   230,    70,   164,   264,    23,    28,
    24,    89,    28,    76,     6,    28,   107,     6,     0,     0,
     6,     0,     0,     8,     0,     0,     8,    51,    30,     8,
     0,    30,   149,   150,    30,     0,     1,     2,     3,   151,
     0,   152,     0,     1,     2,     3,     0,   149,   150,     0,
     0,     0,     0,     0,   151,     6,   152,     0,     0,     0,
   153,     0,     6,     0,     8,   154,   155,   156,   157,   158,
   255,     8,     0,     0,   160,   153,     0,     0,     0,     0,
   154,   155,   156,   157,   158,   159,    26,    27,     0,   160,
    40,    41,     0,     1,     2,     3,     0,     1,     2,     3,
     0,     1,     2,     3,     4,     5,     0,     1,     2,     3,
    98,    28,     6,     7,     0,    28,     6,     0,     0,     0,
     6,     8,     0,     0,     0,     8,     6,     0,     0,     8,
     1,     2,     3,   109,     0,     8,     1,     2,     3,   122,
     1,     2,     3,   126,     0,     0,     0,     0,     0,     6,
     0,     0,     0,     0,     0,     6,     0,     0,     8,     6,
     0,     0,     0,     0,     8,     0,     0,     0,     8,   205,
   206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     0,     0,     0,     0,   233,   205,   206,   207,   208,   209,
   210,   211,   212,   213,   214,   215,     0,     0,     0,     0,
   267,   205,   206,   207,   208,   209,   210,   211,   212,   213,
   214,   215,     0,     0,     0,     0,   268,   205,   206,   207,
   208,   209,   210,   211,   212,   213,   214,   215,     0,     0,
     0,     0,   281,   205,   206,   207,   208,   209,   210,   211,
   212,   213,   214,   215,     0,     0,     0,     0,   282,   205,
   206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     0,     0,     0,     0,   288,   205,   206,   207,   208,   209,
   210,   211,   212,   213,   214,   215
};

static const short yycheck[] = {     0,
    16,    17,    18,    48,    17,    84,    16,    46,     9,    50,
    51,    97,   177,    27,    30,   223,    48,    48,    34,    35,
    35,    53,    17,    48,   189,    17,    40,    41,    53,    45,
    46,    38,    39,    12,    27,    48,    48,    49,   124,    48,
    53,   127,    49,    17,    58,    18,   125,    40,    41,   128,
    89,    67,    68,    48,    70,    56,    48,    67,    68,    17,
    76,    76,    63,    17,   272,    81,    48,   119,    84,    62,
    86,    87,    65,    89,    34,    17,   284,    93,    94,    80,
    48,   167,    83,    51,   170,    53,   100,    34,    17,    82,
    48,    48,    85,    48,    49,    53,    53,   149,   150,   151,
   101,    34,   267,   268,    48,   106,    48,   123,   160,   125,
    18,    53,   128,    86,    87,   280,    53,   282,    50,    48,
    93,    94,    16,   288,    53,    50,   291,   179,     6,     7,
     8,     9,    10,    11,    12,    13,     3,   216,    50,   218,
    34,    35,   135,    48,    49,   146,    10,    11,    12,    13,
    51,   144,    46,   205,   206,   207,   208,   209,   210,   211,
   212,   213,   214,   215,   250,   251,    10,    11,   220,   221,
    54,   223,   165,    67,    68,   168,    18,    21,    22,    23,
    48,    49,    76,   235,    36,    37,    10,    11,    18,    12,
    13,    35,    48,   194,    34,    89,    40,    21,    22,    23,
   216,    50,   218,    18,    50,    49,    67,    68,   260,    53,
    54,    35,    18,    34,    18,    18,    40,   269,   270,    48,
   272,    34,   223,    34,    34,    49,   278,    34,    48,    53,
    54,    17,   284,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    21,    22,    23,    55,    17,    10,
    11,    51,    17,    50,    50,    48,    17,    28,    19,    50,
    21,    22,    23,    40,    53,    26,    50,    28,    29,    30,
    20,    17,    49,    31,    48,    50,    31,    38,    55,    40,
    50,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    27,    52,    18,    54,    10,    11,    50,    10,    11,    50,
    10,    11,     0,     0,     9,    21,    22,    23,    21,    22,
    23,    21,    22,    23,   194,    30,   121,   237,     9,    35,
     9,    45,    35,    34,    40,    35,    60,    40,    -1,    -1,
    40,    -1,    -1,    49,    -1,    -1,    49,    53,    54,    49,
    -1,    54,    10,    11,    54,    -1,    21,    22,    23,    17,
    -1,    19,    -1,    21,    22,    23,    -1,    10,    11,    -1,
    -1,    -1,    -1,    -1,    17,    40,    19,    -1,    -1,    -1,
    38,    -1,    40,    -1,    49,    43,    44,    45,    46,    47,
    48,    49,    -1,    -1,    52,    38,    -1,    -1,    -1,    -1,
    43,    44,    45,    46,    47,    48,    10,    11,    -1,    52,
    10,    11,    -1,    21,    22,    23,    -1,    21,    22,    23,
    -1,    21,    22,    23,    32,    33,    -1,    21,    22,    23,
    24,    35,    40,    41,    -1,    35,    40,    -1,    -1,    -1,
    40,    49,    -1,    -1,    -1,    49,    40,    -1,    -1,    49,
    21,    22,    23,    24,    -1,    49,    21,    22,    23,    24,
    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    40,
    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    49,    40,
    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    49,     3,
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
#line 136 "bison_rules_with_code.y"
{yyval.Program = Program_node::createProgramNode(yyvsp[0].Function_and_class_list);;
    break;}
case 2:
#line 139 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassBlock(yyvsp[0].Class_block);;
    break;}
case 3:
#line 140 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromFunction(yyvsp[0].Function);;
    break;}
case 4:
#line 141 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassDeclarationList(yyvsp[0].Class_declaration_list);;
    break;}
case 5:
#line 142 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassBlock(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_block);;
    break;}
case 6:
#line 143 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromFunction(yyvsp[-1].Function_and_class_list, yyvsp[0].Function);;
    break;}
case 7:
#line 144 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassDeclarationList(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_declaration_list);;
    break;}
case 8:
#line 149 "bison_rules_with_code.y"
{yyval.Function = Function_node::createFunctionNode(yyvsp[-4].Type, yyvsp[-3].Identifier, yyvsp[0].Compound_statement);;
    break;}
case 9:
#line 152 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(INT_TYPE);;
    break;}
case 10:
#line 153 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(CHAR_TYPE);;
    break;}
case 11:
#line 154 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(FLOAT_TYPE);;
    break;}
case 12:
#line 155 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(ID_TYPE);;
    break;}
case 13:
#line 156 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-1].Identifier);;
    break;}
case 14:
#line 160 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromFloat(yyvsp[0].Float_constant);;
    break;}
case 15:
#line 161 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromInteger(yyvsp[0].Integer_constant);;
    break;}
case 16:
#line 164 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(STRING_CONSTANT_TYPE, yyvsp[0].String_constant);;
    break;}
case 17:
#line 165 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(CHAR_CONSTANT_TYPE, yyvsp[0].Char_constant);;
    break;}
case 18:
#line 166 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(NSSTRING_CONSTANT_TYPE, yyvsp[0].NSString_constant);;
    break;}
case 19:
#line 170 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Init_declarator_list);;
    break;}
case 20:
#line 173 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::createDeclarationListNode(yyvsp[0].Declaration);;
    break;}
case 21:
#line 174 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::addToDeclarationListNode(yyvsp[-1].Declaration_list, yyvsp[0].Declaration);;
    break;}
case 22:
#line 177 "bison_rules_with_code.y"
{yyval.Declaration_list = NULL;;
    break;}
case 23:
#line 178 "bison_rules_with_code.y"
{yyval.Declaration_list = yyvsp[0].Declaration_list;;
    break;}
case 24:
#line 181 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 25:
#line 182 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 26:
#line 185 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 27:
#line 186 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 28:
#line 189 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Identifier, NULL);;
    break;}
case 29:
#line 190 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 30:
#line 193 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::createParameterListNode(yyvsp[0].Parameter_declaration);;
    break;}
case 31:
#line 194 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::addToParameterListNode(yyvsp[-2].Parameter_list, yyvsp[0].Parameter_declaration);;
    break;}
case 32:
#line 197 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(yyvsp[-1].Type, yyvsp[0].Identifier);;
    break;}
case 33:
#line 202 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromIdentifier(yyvsp[0].Identifier);;
    break;}
case 34:
#line 203 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromLiteral(yyvsp[0].Literal);;
    break;}
case 35:
#line 204 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromNumericConstant(yyvsp[0].Numeric_constant);;
    break;}
case 36:
#line 205 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createSimpleExpressionNode(PRIORITY_EXPRESSION_TYPE, yyvsp[-1].Expression);;
    break;}
case 37:
#line 206 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSelf();;
    break;}
case 38:
#line 207 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 39:
#line 208 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UMINUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 40:
#line 209 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UPLUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 41:
#line 210 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UAMPERSAND_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 42:
#line 211 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(PLUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 43:
#line 212 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MINUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 44:
#line 213 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MUL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 45:
#line 214 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(DIV_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 46:
#line 215 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 47:
#line 216 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(NOT_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 48:
#line 217 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 49:
#line 218 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 50:
#line 219 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 51:
#line 220 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 52:
#line 221 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(ASSIGNMENT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 53:
#line 224 "bison_rules_with_code.y"
{yyval.Expression = NULL;;
    break;}
case 54:
#line 225 "bison_rules_with_code.y"
{yyval.Expression = yyvsp[0].Expression;;
    break;}
case 55:
#line 228 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);;
    break;}
case 56:
#line 229 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);;
    break;}
case 57:
#line 230 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(CLASS_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 58:
#line 233 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[0].Identifier, NULL);;
    break;}
case 59:
#line 234 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(NULL, yyvsp[0].Keyword_argument_list);;
    break;}
case 60:
#line 237 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::createKeywordArgumentListNode(yyvsp[0].Keyword_argument);;
    break;}
case 61:
#line 238 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::addToKeywordArgumentListNode(yyvsp[-1].Keyword_argument_list, yyvsp[0].Keyword_argument);;
    break;}
case 62:
#line 241 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITH_IDENTIFIER_KW_ARGUMENT_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 63:
#line 242 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 64:
#line 246 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITHOUT_ALTERNATIVE_IF_TYPE, yyvsp[-2].Expression, yyvsp[0].Statement, NULL);;
    break;}
case 65:
#line 247 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITH_ALTERNATIVE_IF_TYPE, yyvsp[-4].Expression, yyvsp[-2].Statement, yyvsp[0].Statement);;
    break;}
case 66:
#line 251 "bison_rules_with_code.y"
{yyval.While  = While_statement_node::createWhileStatementNode(yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 67:
#line 254 "bison_rules_with_code.y"
{yyval.Do_while = Do_while_statement_node::createDoWhileStatementNode(yyvsp[-2].Expression, yyvsp[-5].Statement);;
    break;}
case 68:
#line 257 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNode(yyvsp[-6].Expression, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 69:
#line 258 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 70:
#line 259 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, yyvsp[-5].Type, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 71:
#line 264 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);;
    break;}
case 72:
#line 265 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 73:
#line 266 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 74:
#line 267 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(IF_STATEMENT_TYPE, yyvsp[0].If);;
    break;}
case 75:
#line 268 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(WHILE_STATEMENT_TYPE, yyvsp[0].While);;
    break;}
case 76:
#line 269 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(DO_WHILE_STATEMENT_TYPE, yyvsp[0].Do_while);;
    break;}
case 77:
#line 270 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(FOR_STATEMENT_TYPE, yyvsp[0].For);;
    break;}
case 78:
#line 271 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(COMPOUND_STATEMENT_TYPE, yyvsp[0].Compound_statement);;
    break;}
case 79:
#line 272 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 80:
#line 275 "bison_rules_with_code.y"
{yyval.Compound_statement = Compound_statement_node::createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 81:
#line 278 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::createStatementListNode(yyvsp[0].Statement);;
    break;}
case 82:
#line 279 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::addToStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 83:
#line 282 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 84:
#line 283 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 85:
#line 286 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlockNodeFromInterface(yyvsp[0].Class_interface);;
    break;}
case 86:
#line 287 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlcokNodeFromImplementation(yyvsp[0].Class_implementation);;
    break;}
case 87:
#line 291 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 88:
#line 292 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 89:
#line 293 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 90:
#line 296 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Interface_declaration_list);;
    break;}
case 91:
#line 297 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 92:
#line 300 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Implementation_definition_list);;
    break;}
case 93:
#line 301 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 94:
#line 304 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 95:
#line 305 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 96:
#line 306 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 97:
#line 307 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 98:
#line 308 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 99:
#line 309 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 100:
#line 312 "bison_rules_with_code.y"
{yyval.Class_declaration_list = Class_declaration_list_node::createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 101:
#line 315 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::createClassListNode(yyvsp[0].Identifier);;
    break;}
case 102:
#line 316 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::addToClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 103:
#line 319 "bison_rules_with_code.y"
{yyval.Instance_variables = Instance_variables_node::createInstanceVariablesNode(yyvsp[-1].Declaration_list);;
    break;}
case 104:
#line 322 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 105:
#line 323 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 106:
#line 324 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(yyvsp[0].Method_declaration);;
    break;}
case 107:
#line 325 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 108:
#line 326 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 109:
#line 327 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 110:
#line 330 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 111:
#line 331 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 112:
#line 334 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 113:
#line 335 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 114:
#line 336 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 115:
#line 339 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 116:
#line 340 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 117:
#line 341 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 118:
#line 344 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 119:
#line 345 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 120:
#line 346 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(yyvsp[0].Method_definition);;
    break;}
case 121:
#line 347 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 122:
#line 348 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 123:
#line 349 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addPropertyToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Property);;
    break;}
case 124:
#line 352 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 125:
#line 353 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 126:
#line 356 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 127:
#line 357 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 128:
#line 358 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 129:
#line 361 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 130:
#line 362 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 131:
#line 363 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 132:
#line 366 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL);;
    break;}
case 133:
#line 367 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(NULL, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 134:
#line 368 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(NULL, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_list);;
    break;}
case 135:
#line 371 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 136:
#line 372 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::addToKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 137:
#line 375 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 138:
#line 376 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 139:
#line 377 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 140:
#line 378 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 141:
#line 381 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(yyvsp[-1].Type);;
    break;}
case 142:
#line 384 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 143:
#line 387 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 144:
#line 388 "bison_rules_with_code.y"
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
#line 391 "bison_rules_with_code.y"


