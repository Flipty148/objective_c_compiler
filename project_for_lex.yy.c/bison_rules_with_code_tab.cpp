
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



#define	YYFINAL		371
#define	YYFLAG		-32768
#define	YYNTBASE	59

#define YYTRANSLATE(x) ((unsigned)(x) <= 295 ? yytranslate[x] : 123)

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
   200,   204,   206,   208,   210,   215,   217,   222,   229,   230,
   232,   234,   237,   241,   244,   250,   258,   264,   272,   282,
   290,   300,   302,   305,   309,   311,   313,   315,   317,   319,
   321,   325,   327,   330,   331,   333,   335,   337,   344,   349,
   356,   359,   361,   364,   366,   371,   378,   383,   390,   397,
   404,   408,   410,   414,   418,   422,   426,   428,   431,   433,
   435,   437,   440,   443,   446,   448,   450,   455,   462,   466,
   471,   478,   482,   484,   486,   488,   491,   494,   497,   499,
   501,   507,   515,   520,   526,   534,   539,   541,   546,   553,
   554,   556,   558,   561,   564,   566,   570,   573,   578,   582,
   586,   591,   599,   608,   613,   619,   626,   634,   636,   638
};

static const short yyrhs[] = {    60,
     0,    96,     0,    61,     0,   101,     0,    60,    96,     0,
    60,    61,     0,    60,   101,     0,    62,    51,    19,    20,
    93,     0,    23,     0,    24,     0,    25,     0,    43,     0,
    49,     0,    46,     0,    47,     0,    48,     0,    50,     0,
    62,    68,    53,     0,    52,    77,    53,     0,    65,     0,
    66,    65,     0,     0,    66,     0,     0,    69,     0,    70,
     0,    69,    54,    70,     0,    71,     0,    71,     3,    80,
     0,    51,     0,    12,    51,     0,    72,     0,    73,    54,
    72,     0,    71,     0,    74,    54,    71,     0,    72,     0,
    72,     3,    80,     0,    75,     0,    76,    54,    75,     0,
     0,    76,     0,    79,     0,    78,    54,    79,     0,    62,
    51,     0,    52,    12,    51,     0,    51,     0,    64,     0,
    63,     0,    19,    80,    20,     0,    41,     0,    21,    83,
    84,    22,     0,    11,    80,     0,    10,    80,     0,    55,
    80,     0,    80,    10,    80,     0,    80,    11,    80,     0,
    80,    12,    80,     0,    80,    13,    80,     0,    80,     4,
    80,     0,    80,     5,    80,     0,    80,     7,    80,     0,
    80,     6,    80,     0,    80,     8,    80,     0,    80,     9,
    80,     0,    80,     3,    80,     0,    80,    17,    51,     0,
    80,    18,    51,     0,     0,    80,     0,    80,     0,    82,
    54,    80,     0,    42,     0,    41,     0,    51,     0,    21,
    83,    84,    22,     0,    51,     0,    51,    56,    80,    85,
     0,    51,    56,    80,    85,    54,    82,     0,     0,    86,
     0,    87,     0,    86,    87,     0,    51,    56,    80,     0,
    56,    80,     0,    28,    19,    80,    20,    92,     0,    28,
    19,    80,    20,    92,    29,    92,     0,    30,    19,    80,
    20,    92,     0,    31,    92,    30,    19,    80,    20,    53,
     0,    32,    19,    81,    53,    81,    53,    81,    20,    92,
     0,    32,    19,    51,    33,    80,    20,    92,     0,    32,
    19,    52,    12,    51,    33,    80,    20,    92,     0,    53,
     0,    80,    53,     0,    45,    81,    53,     0,    88,     0,
    89,     0,    90,     0,    91,     0,    93,     0,    65,     0,
    57,    95,    58,     0,    92,     0,    94,    92,     0,     0,
    94,     0,    97,     0,   100,     0,    34,    51,    56,    51,
    98,    36,     0,    34,    51,    98,    36,     0,    34,    51,
    56,    52,    98,    36,     0,   103,   106,     0,   106,     0,
   103,   110,     0,   110,     0,    35,    51,    99,    36,     0,
    35,    51,    56,    51,    99,    36,     0,    35,    52,    99,
    36,     0,    35,    52,    56,    51,    99,    36,     0,    35,
    51,    56,    52,    99,    36,     0,    35,    52,    56,    52,
    99,    36,     0,    44,   102,    53,     0,    51,     0,   102,
    54,    51,     0,    57,   105,    58,     0,    62,    74,    53,
     0,    52,    73,    53,     0,   104,     0,   105,   104,     0,
    65,     0,   120,     0,   107,     0,   106,    65,     0,   106,
   107,     0,   106,   120,     0,   108,     0,   109,     0,    10,
   119,   114,    53,     0,    10,    19,    26,    20,   114,    53,
     0,    10,   114,    53,     0,    11,   119,   114,    53,     0,
    11,    19,    26,    20,   114,    53,     0,    11,   114,    53,
     0,    65,     0,   122,     0,   111,     0,   110,    65,     0,
   110,   122,     0,   110,   111,     0,   112,     0,   113,     0,
    10,   119,   114,    67,    93,     0,    10,    19,    26,    20,
   114,    67,    93,     0,    10,   114,    67,    93,     0,    11,
   119,   114,    67,    93,     0,    11,    19,    26,    20,   114,
    67,    93,     0,    11,   114,    67,    93,     0,    51,     0,
    51,    56,   117,   115,     0,    51,    56,   117,   115,    54,
    78,     0,     0,   116,     0,   118,     0,   116,   118,     0,
   119,    51,     0,    51,     0,    56,   119,    51,     0,    56,
    51,     0,    51,    56,   119,    51,     0,    51,    56,    51,
     0,    19,    62,    20,     0,    19,    52,    12,    20,     0,
    37,    19,   121,    20,    62,    51,    53,     0,    37,    19,
   121,    20,    52,    12,    51,    53,     0,    37,    62,    51,
    53,     0,    37,    52,    12,    51,    53,     0,    37,    19,
    20,    62,    51,    53,     0,    37,    19,    20,    52,    12,
    51,    53,     0,    38,     0,    39,     0,    40,    51,    53,
     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   152,   155,   156,   157,   158,   159,   160,   165,   168,   169,
   170,   171,   175,   176,   179,   180,   181,   185,   186,   189,
   190,   193,   194,   197,   198,   201,   202,   205,   206,   209,
   212,   215,   216,   218,   219,   222,   223,   226,   227,   230,
   231,   234,   235,   238,   239,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
   259,   260,   261,   262,   263,   264,   265,   268,   269,   272,
   273,   276,   277,   278,   279,   282,   283,   284,   287,   288,
   291,   292,   295,   296,   300,   301,   305,   308,   311,   312,
   313,   318,   319,   320,   321,   322,   323,   324,   325,   326,
   329,   332,   333,   336,   337,   340,   341,   345,   346,   347,
   350,   351,   354,   355,   358,   359,   360,   361,   362,   363,
   366,   369,   370,   373,   376,   377,   380,   381,   384,   385,
   386,   387,   388,   389,   392,   393,   396,   397,   398,   401,
   402,   403,   406,   407,   408,   409,   410,   411,   414,   415,
   418,   419,   420,   423,   424,   425,   428,   429,   430,   433,
   434,   437,   438,   441,   442,   445,   446,   447,   448,   451,
   452,   455,   456,   457,   458,   459,   460,   463,   464,   467
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
"parameter_list","parameter_declaration","expression","expression_e","expression_list",
"receiver","message_selector","keyword_argument_list_e","keyword_argument_list",
"keyword_argument","if_statement","while_statement","do_while_statement","for_statement",
"statement","compound_statement","statement_list","statement_list_e","class_block",
"class_interface","interface_body","implementation_body","class_implementation",
"class_declaration_list","class_list","instance_variables","instance_variables_declaration",
"instance_variables_declaration_list","interface_declaration_list","method_declaration",
"class_method_declaration","instance_method_declaration","implementation_definition_list",
"method_definition","class_method_definition","instance_method_definition","method_selector",
"keyword_selector_e","keyword_selector","keyword_declaration_without_identifier",
"keyword_declaration","method_type","property","attribute","synthesize",""
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
    82,    83,    83,    83,    83,    84,    84,    84,    85,    85,
    86,    86,    87,    87,    88,    88,    89,    90,    91,    91,
    91,    92,    92,    92,    92,    92,    92,    92,    92,    92,
    93,    94,    94,    95,    95,    96,    96,    97,    97,    97,
    98,    98,    99,    99,   100,   100,   100,   100,   100,   100,
   101,   102,   102,   103,   104,   104,   105,   105,   106,   106,
   106,   106,   106,   106,   107,   107,   108,   108,   108,   109,
   109,   109,   110,   110,   110,   110,   110,   110,   111,   111,
   112,   112,   112,   113,   113,   113,   114,   114,   114,   115,
   115,   116,   116,   117,   117,   118,   118,   118,   118,   119,
   119,   120,   120,   120,   120,   120,   120,   121,   121,   122
};

static const short yyr2[] = {     0,
     1,     1,     1,     1,     2,     2,     2,     5,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
     2,     0,     1,     0,     1,     1,     3,     1,     3,     1,
     2,     1,     3,     1,     3,     1,     3,     1,     3,     0,
     1,     1,     3,     2,     3,     1,     1,     1,     3,     1,
     4,     2,     2,     2,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     0,     1,     1,
     3,     1,     1,     1,     4,     1,     4,     6,     0,     1,
     1,     2,     3,     2,     5,     7,     5,     7,     9,     7,
     9,     1,     2,     3,     1,     1,     1,     1,     1,     1,
     3,     1,     2,     0,     1,     1,     1,     6,     4,     6,
     2,     1,     2,     1,     4,     6,     4,     6,     6,     6,
     3,     1,     3,     3,     3,     3,     1,     2,     1,     1,
     1,     2,     2,     2,     1,     1,     4,     6,     3,     4,
     6,     3,     1,     1,     1,     2,     2,     2,     1,     1,
     5,     7,     4,     5,     7,     4,     1,     4,     6,     0,
     1,     1,     2,     2,     1,     3,     2,     4,     3,     3,
     4,     7,     8,     4,     5,     6,     7,     1,     1,     3
};

static const short yydefact[] = {     0,
     9,    10,    11,     0,     0,    12,     0,     1,     3,     0,
     2,   106,   107,     4,     0,     0,     0,   122,     0,     6,
     5,     7,     0,     0,     0,     0,    40,     0,     0,    24,
   129,     0,     0,   112,   131,   135,   136,   130,     0,     0,
     0,     0,   143,     0,     0,   114,   145,   149,   150,   144,
     0,     0,   121,     0,     0,     0,   157,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    36,    38,    41,     0,
     0,     0,     0,     0,   127,     0,    30,     0,    25,    26,
    28,   109,   111,   132,   133,   134,     0,    22,     0,     0,
    22,     0,     0,     0,     0,   115,   113,   146,   148,   147,
     0,     0,   117,   123,     0,     0,     0,     0,     0,   139,
     0,     0,   142,     0,     0,   178,   179,     0,     0,     0,
    31,     0,     0,    19,     0,     0,    32,     0,    34,     0,
   124,   128,    18,     0,     0,     0,    20,    23,     0,    22,
     0,     0,    22,   180,     0,     0,     0,     0,   104,     8,
     0,     0,   170,     0,   165,   160,     0,   137,     0,   140,
     0,     0,     0,     0,   174,     0,     0,     0,     0,    50,
    14,    15,    16,    13,    17,    46,     0,    48,    47,    37,
    39,   108,   110,   126,     0,   125,     0,    27,    29,     0,
    21,   153,     0,     0,   156,     0,   116,   119,   118,   120,
     0,     0,     0,     0,    68,    92,   100,     0,    95,    96,
    97,    98,   102,    99,   105,     0,     0,   171,     0,     0,
   158,   161,   162,   164,     0,     0,     0,     0,     0,   175,
    53,    52,     0,     0,    73,    72,    74,     0,    54,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    33,    35,    22,   151,    22,   154,     0,     0,
     0,    68,    69,     0,    93,   103,   101,   138,     0,   167,
     0,     0,   163,   141,     0,   176,     0,     0,    49,     0,
    76,     0,    65,    59,    60,    62,    61,    63,    64,    55,
    56,    57,    58,    66,    67,     0,     0,     0,     0,     0,
    46,     0,     0,    94,   169,     0,   166,     0,     0,   159,
    42,   177,     0,   172,     0,     0,    51,   152,   155,     0,
     0,     0,     0,     0,    68,   168,     0,    44,     0,   173,
    75,    79,    85,    87,     0,     0,     0,     0,    45,    43,
     0,     0,    77,    80,    81,     0,     0,     0,     0,    68,
     0,    84,     0,    82,    86,    88,    90,     0,     0,    83,
    70,    78,     0,     0,     0,    91,    89,    71,     0,     0,
     0
};

static const short yydefgoto[] = {   369,
     8,     9,    30,   178,   179,   207,   138,   139,    78,    79,
    80,    81,    67,   128,   130,    68,    69,    70,   310,   311,
   208,   264,   362,   238,   282,   343,   344,   345,   209,   210,
   211,   212,   213,   214,   215,   216,    11,    12,    32,    44,
    13,    14,    19,    45,    75,    76,    34,    35,    36,    37,
    46,    47,    48,    49,    58,   221,   222,   156,   223,    59,
    38,   118,    50
};

static const short yypact[] = {   471,
-32768,-32768,-32768,   -27,    45,-32768,   -13,   471,-32768,    -3,
-32768,-32768,-32768,-32768,   187,    95,   333,-32768,    68,-32768,
-32768,-32768,     3,    -9,     2,   149,    15,    88,    50,     4,
-32768,    22,   404,   404,-32768,-32768,-32768,-32768,    26,    27,
    28,    98,-32768,    48,   426,   426,-32768,-32768,-32768,-32768,
   113,    52,-32768,    41,    83,   323,    56,    89,    94,   336,
   108,    94,     5,   145,   119,   140,   179,-32768,   139,   146,
   340,   340,    15,     4,-32768,   -11,-32768,   160,   161,-32768,
   213,-32768,   404,-32768,-32768,-32768,   419,   269,    94,   429,
   269,    94,   164,   344,   344,-32768,   426,-32768,-32768,-32768,
   344,   344,-32768,-32768,   165,   201,   211,   205,    53,-32768,
   174,   208,-32768,   176,   434,-32768,-32768,   212,   180,   183,
-32768,   384,    15,-32768,   202,   204,-32768,   127,-32768,   131,
-32768,-32768,-32768,     4,   384,   221,-32768,   269,   165,   269,
   222,   165,   269,-32768,   210,   225,   226,   227,   285,-32768,
    94,   228,-32768,   440,-32768,   -23,   196,-32768,    94,-32768,
   254,   216,   450,   215,-32768,   384,   384,   384,   137,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   384,-32768,-32768,   622,
-32768,-32768,-32768,-32768,    15,-32768,     4,-32768,   622,    94,
-32768,-32768,   165,    94,-32768,   165,-32768,-32768,-32768,-32768,
   250,   251,   285,   252,   384,-32768,-32768,   270,-32768,-32768,
-32768,-32768,-32768,-32768,   285,   231,   232,-32768,   230,    90,
   236,   -23,-32768,-32768,   238,   233,   244,   287,   249,-32768,
   169,   169,   514,   137,-32768,-32768,-32768,   256,   169,   384,
   384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
   260,   263,-32768,-32768,   269,-32768,   269,-32768,   384,   384,
   271,   361,   622,   265,-32768,-32768,-32768,-32768,   104,-32768,
   268,   464,-32768,-32768,   272,-32768,   273,   274,-32768,   256,
   246,   283,   622,   635,   635,   644,   644,   644,   644,    18,
    18,   169,   169,-32768,-32768,   165,   165,   532,   550,   320,
   308,   341,   292,-32768,-32768,   301,-32768,   358,   327,   332,
-32768,-32768,   321,-32768,   359,   384,-32768,-32768,-32768,   285,
   285,   384,   384,   342,   384,-32768,   347,-32768,   464,-32768,
-32768,   247,   362,-32768,   568,   586,   366,   351,-32768,-32768,
   350,   384,   346,   -17,-32768,   285,   364,   285,   384,   384,
   384,   622,   384,-32768,-32768,-32768,-32768,   604,   398,   622,
   622,   365,   285,   285,   384,-32768,-32768,   622,   420,   421,
-32768
};

static const short yypgoto[] = {-32768,
-32768,   414,     0,-32768,-32768,    65,-32768,   -86,-32768,-32768,
   289,   -70,   -71,-32768,-32768,   303,-32768,-32768,-32768,   109,
  -116,  -255,-32768,   190,   166,-32768,-32768,    96,-32768,-32768,
-32768,-32768,  -144,  -102,-32768,-32768,   452,-32768,   118,     6,
-32768,   453,-32768,    -6,   372,-32768,   435,   -16,-32768,-32768,
   422,   -35,-32768,-32768,    24,-32768,-32768,-32768,   248,   -24,
   -14,-32768,   -29
};


#define	YYLAST		662


static const short yytable[] = {    10,
    62,   127,   150,   129,   142,   180,   303,    10,    33,    56,
    99,     1,     2,     3,    89,    92,   100,    85,   189,    86,
    60,    55,    52,    15,   115,    65,    66,   219,    74,   249,
   250,     6,   220,   341,   251,   252,   192,    18,   342,   195,
    73,    57,   116,   117,    87,    90,   131,    23,    61,   231,
   232,   233,    57,   193,    77,   108,   196,    82,   261,   108,
   239,    99,    88,    91,    33,    33,    85,   100,    86,   338,
   266,   154,     1,     2,     3,    74,    57,    57,    93,    31,
    43,    43,   111,    96,   157,   114,   108,   103,   263,   108,
   256,   104,     6,   258,   359,    16,    17,    31,    84,   145,
   146,    73,   105,   155,    39,    40,   147,   148,   154,    43,
    98,   109,   140,   253,   162,   143,   254,     1,     2,     3,
    53,    54,   154,   283,   284,   285,   286,   287,   288,   289,
   290,   291,   292,   293,    41,    31,    31,     6,    71,    72,
   270,   110,   298,   299,    57,   263,    27,    84,    94,    95,
    42,    29,   137,   108,   305,   137,   119,   234,    43,    43,
   113,    98,   229,   101,   102,    43,    43,    63,   296,   120,
   297,     1,     2,     3,   217,   333,   334,   235,   236,   184,
   185,   122,   225,   186,   187,   251,   252,   237,   125,   126,
   121,     6,   123,   318,   319,   271,    24,    25,   124,   332,
    64,   355,   191,   357,   137,   335,   336,   137,   263,     1,
     2,     3,   133,   255,   134,   135,   144,   257,   366,   367,
   151,   149,   152,    26,   153,   352,   158,   159,   160,     6,
   164,   163,   358,   263,   360,   165,   361,   182,    27,   183,
   190,   194,    28,    29,   306,   197,   224,   218,   368,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   198,   199,   200,   251,   252,   226,   227,   230,   259,   260,
   262,   309,   240,   241,   242,   243,   244,   245,   246,   247,
   248,   249,   250,   275,   268,   269,   251,   252,   267,   272,
   274,     1,     2,     3,   166,   167,   276,   341,   277,   278,
   300,   316,   342,   168,   317,   169,   281,     1,     2,     3,
   294,     6,   201,   295,   202,   203,   204,   304,   307,   137,
    27,   137,   265,   313,   312,   170,   314,     6,   309,   205,
   171,   172,   173,   174,   175,   176,    27,   206,   322,   177,
   323,   149,    39,    40,   325,     1,     2,     3,   106,    24,
    25,   326,   324,    39,    40,     1,     2,     3,     1,     2,
     3,   112,     1,     2,     3,     6,     1,     2,     3,   327,
   166,   167,    41,   330,   107,     6,    26,   328,     6,   168,
   331,   169,     6,    41,    27,   329,     6,   107,    51,    29,
   346,    27,   337,   166,   167,    27,    29,   339,   349,   353,
    29,   170,   168,   350,   169,   351,   171,   172,   173,   174,
   175,   301,   302,    24,    25,   177,   356,   364,   365,   370,
   371,    20,   188,   280,   170,   181,     1,     2,     3,   171,
   172,   173,   174,   175,   176,    39,    40,   340,   177,   354,
    26,     1,     2,     3,   136,   315,     6,   132,     1,     2,
     3,     1,     2,     3,   141,    27,     1,     2,     3,    21,
    22,     6,     1,     2,     3,    41,    97,    83,     6,   273,
   107,     6,     1,     2,     3,     0,     6,    27,     0,     0,
   107,     0,     6,     0,     0,   161,     1,     2,     3,     0,
     0,   107,     6,     1,     2,     3,     0,     0,     0,     0,
     0,   228,     0,     0,     4,     5,     6,     0,     0,     0,
     0,     0,     0,     6,     7,   308,   240,   241,   242,   243,
   244,   245,   246,   247,   248,   249,   250,     0,     0,     0,
   251,   252,     0,   279,   240,   241,   242,   243,   244,   245,
   246,   247,   248,   249,   250,     0,     0,     0,   251,   252,
     0,   320,   240,   241,   242,   243,   244,   245,   246,   247,
   248,   249,   250,     0,     0,     0,   251,   252,     0,   321,
   240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
   250,     0,     0,     0,   251,   252,     0,   347,   240,   241,
   242,   243,   244,   245,   246,   247,   248,   249,   250,     0,
     0,     0,   251,   252,     0,   348,   240,   241,   242,   243,
   244,   245,   246,   247,   248,   249,   250,     0,     0,     0,
   251,   252,     0,   363,   240,   241,   242,   243,   244,   245,
   246,   247,   248,   249,   250,     0,     0,     0,   251,   252,
   243,   244,   245,   246,   247,   248,   249,   250,     0,     0,
     0,   251,   252,   247,   248,   249,   250,     0,     0,     0,
   251,   252
};

static const short yycheck[] = {     0,
    25,    73,   105,    74,    91,   122,   262,     8,    15,    19,
    46,    23,    24,    25,    39,    40,    46,    34,   135,    34,
    19,    19,    17,    51,    20,    26,    12,    51,    29,    12,
    13,    43,    56,    51,    17,    18,   139,    51,    56,   142,
    52,    51,    38,    39,    19,    19,    58,    51,    25,   166,
   167,   168,    51,   140,    51,    56,   143,    36,   203,    60,
   177,    97,    39,    40,    71,    72,    83,    97,    83,   325,
   215,    19,    23,    24,    25,    76,    51,    51,    51,    15,
    16,    17,    59,    36,   109,    62,    87,    36,   205,    90,
   193,    51,    43,   196,   350,    51,    52,    33,    34,    94,
    95,    52,    20,    51,    10,    11,   101,   102,    19,    45,
    46,    56,    89,   185,   115,    92,   187,    23,    24,    25,
    53,    54,    19,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,    40,    71,    72,    43,    51,    52,
    51,    53,   259,   260,    51,   262,    52,    83,    51,    52,
    56,    57,    88,   154,    51,    91,    12,    21,    94,    95,
    53,    97,   163,    51,    52,   101,   102,    19,   255,    51,
   257,    23,    24,    25,   151,   320,   321,    41,    42,    53,
    54,     3,   159,    53,    54,    17,    18,    51,    71,    72,
    51,    43,    54,   296,   297,   220,    10,    11,    53,   316,
    52,   346,   138,   348,   140,   322,   323,   143,   325,    23,
    24,    25,    53,   190,    54,     3,    53,   194,   363,   364,
    20,    57,    12,    37,    20,   342,    53,    20,    53,    43,
    51,    20,   349,   350,   351,    53,   353,    36,    52,    36,
    20,    20,    56,    57,   269,    36,    51,    20,   365,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
    36,    36,    36,    17,    18,    12,    51,    53,    19,    19,
    19,   272,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    51,    53,    56,    17,    18,    58,    54,
    53,    23,    24,    25,    10,    11,    53,    51,    12,    51,
    30,    56,    56,    19,    22,    21,    51,    23,    24,    25,
    51,    43,    28,    51,    30,    31,    32,    53,    51,   255,
    52,   257,    53,    51,    53,    41,    53,    43,   329,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    19,    55,
    33,    57,    10,    11,    53,    23,    24,    25,    26,    10,
    11,    51,    12,    10,    11,    23,    24,    25,    23,    24,
    25,    26,    23,    24,    25,    43,    23,    24,    25,    12,
    10,    11,    40,    53,    52,    43,    37,    51,    43,    19,
    22,    21,    43,    40,    52,    54,    43,    52,    56,    57,
    29,    52,    51,    10,    11,    52,    57,    51,    33,    54,
    57,    41,    19,    53,    21,    56,    46,    47,    48,    49,
    50,    51,    52,    10,    11,    55,    53,    20,    54,     0,
     0,     8,   134,   234,    41,   123,    23,    24,    25,    46,
    47,    48,    49,    50,    51,    10,    11,   329,    55,   344,
    37,    23,    24,    25,    26,   280,    43,    76,    23,    24,
    25,    23,    24,    25,    26,    52,    23,    24,    25,     8,
     8,    43,    23,    24,    25,    40,    45,    33,    43,   222,
    52,    43,    23,    24,    25,    -1,    43,    52,    -1,    -1,
    52,    -1,    43,    -1,    -1,    52,    23,    24,    25,    -1,
    -1,    52,    43,    23,    24,    25,    -1,    -1,    -1,    -1,
    -1,    52,    -1,    -1,    34,    35,    43,    -1,    -1,    -1,
    -1,    -1,    -1,    43,    44,    52,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
    17,    18,    -1,    20,     3,     4,     5,     6,     7,     8,
     9,    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,
    -1,    20,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    -1,    -1,    -1,    17,    18,    -1,    20,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
    -1,    -1,    17,    18,    -1,    20,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
    17,    18,    -1,    20,     3,     4,     5,     6,     7,     8,
     9,    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,
     6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
    -1,    17,    18,    10,    11,    12,    13,    -1,    -1,    -1,
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
{yyval.Program = Program_node::createProgramNode(yyvsp[0].Function_and_class_list);;
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
#line 168 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(INT_TYPE);;
    break;}
case 10:
#line 169 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(CHAR_TYPE);;
    break;}
case 11:
#line 170 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(FLOAT_TYPE);;
    break;}
case 12:
#line 171 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(ID_TYPE);;
    break;}
case 13:
#line 175 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromFloat(yyvsp[0].Float_constant);;
    break;}
case 14:
#line 176 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromInteger(yyvsp[0].Integer_constant);;
    break;}
case 15:
#line 179 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(STRING_CONSTANT_TYPE, yyvsp[0].String_constant);;
    break;}
case 16:
#line 180 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(CHAR_CONSTANT_TYPE, yyvsp[0].Char_constant);;
    break;}
case 17:
#line 181 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(NSSTRING_CONSTANT_TYPE, yyvsp[0].NSString_constant);;
    break;}
case 18:
#line 185 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Init_declarator_list);;
    break;}
case 19:
#line 186 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Init_declarator_list);
    break;}
case 20:
#line 189 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::createDeclarationListNode(yyvsp[0].Declaration);;
    break;}
case 21:
#line 190 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::addToDeclarationListNode(yyvsp[-1].Declaration_list, yyvsp[0].Declaration);;
    break;}
case 22:
#line 193 "bison_rules_with_code.y"
{yyval.Declaration_list = NULL;;
    break;}
case 23:
#line 194 "bison_rules_with_code.y"
{yyval.Declaration_list = yyvsp[0].Declaration_list;;
    break;}
case 24:
#line 197 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 25:
#line 198 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 26:
#line 201 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 27:
#line 202 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 28:
#line 205 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Declarator, NULL);;
    break;}
case 29:
#line 206 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Declarator, yyvsp[0].Expression);;
    break;}
case 30:
#line 209 "bison_rules_with_code.y"
{yyval.Declarator = Declarator_node::createDeclaratorNode(yyvsp[0].Identifier);;
    break;}
case 31:
#line 212 "bison_rules_with_code.y"
{yyval.Declarator = Declarator_node::createDeclaratorNode(yyvsp[0].Identifier);;
    break;}
case 32:
#line 215 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Declarator);;
    break;}
case 33:
#line 216 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-2].Declarator_list, yyvsp[0].Declarator);;
    break;}
case 34:
#line 218 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Declarator);;
    break;}
case 35:
#line 219 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-2].Declarator_list,yyvsp[0].Declarator);;
    break;}
case 36:
#line 222 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Declarator, NULL);;
    break;}
case 37:
#line 223 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Declarator, yyvsp[0].Expression);;
    break;}
case 38:
#line 226 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 39:
#line 227 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 40:
#line 230 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 41:
#line 231 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 42:
#line 234 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::createParameterListNode(yyvsp[0].Parameter_declaration);;
    break;}
case 43:
#line 235 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::addToParameterListNode(yyvsp[-2].Parameter_list, yyvsp[0].Parameter_declaration);;
    break;}
case 44:
#line 238 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(yyvsp[-1].Type, yyvsp[0].Identifier);;
    break;}
case 45:
#line 239 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier),yyvsp[0].Identifier);;
    break;}
case 46:
#line 244 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromIdentifier(yyvsp[0].Identifier);;
    break;}
case 47:
#line 245 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromLiteral(yyvsp[0].Literal);;
    break;}
case 48:
#line 246 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromNumericConstant(yyvsp[0].Numeric_constant);;
    break;}
case 49:
#line 247 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSimpleExpression(PRIORITY_EXPRESSION_TYPE, yyvsp[-1].Expression);;
    break;}
case 50:
#line 248 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSelf();;
    break;}
case 51:
#line 249 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 52:
#line 250 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UMINUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 53:
#line 251 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UPLUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 54:
#line 252 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UAMPERSAND_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 55:
#line 253 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(PLUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 56:
#line 254 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MINUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 57:
#line 255 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MUL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 58:
#line 256 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(DIV_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 59:
#line 257 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 60:
#line 258 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(NOT_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 61:
#line 259 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 62:
#line 260 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 63:
#line 261 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 64:
#line 262 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 65:
#line 263 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(ASSIGNMENT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 66:
#line 264 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMemberAccessOperator(DOT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Identifier);;
    break;}
case 67:
#line 265 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMemberAccessOperator(ARROW_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Identifier);;
    break;}
case 68:
#line 268 "bison_rules_with_code.y"
{yyval.Expression = NULL;;
    break;}
case 69:
#line 269 "bison_rules_with_code.y"
{yyval.Expression = yyvsp[0].Expression;;
    break;}
case 70:
#line 272 "bison_rules_with_code.y"
{yyval.Expression_list = Expression_list_node::createExpressionListNode(yyvsp[0].Expression);;
    break;}
case 71:
#line 273 "bison_rules_with_code.y"
{yyval.Expression_list = Expression_list_node::addToExpressionListNode(yyvsp[-2].Expression_list, yyvsp[0].Expression);;
    break;}
case 72:
#line 276 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);;
    break;}
case 73:
#line 277 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);;
    break;}
case 74:
#line 278 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(OBJECT_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 75:
#line 279 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 76:
#line 282 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 77:
#line 283 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Expression, yyvsp[0].Keyword_argument_list, NULL);;
    break;}
case 78:
#line 284 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Expression, yyvsp[-2].Keyword_argument_list, yyvsp[0].Expression_list);;
    break;}
case 79:
#line 287 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = NULL;;
    break;}
case 80:
#line 288 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = yyvsp[0].Keyword_argument_list;;
    break;}
case 81:
#line 291 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::createKeywordArgumentListNode(yyvsp[0].Keyword_argument);;
    break;}
case 82:
#line 292 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::addToKeywordArgumentListNode(yyvsp[-1].Keyword_argument_list, yyvsp[0].Keyword_argument);;
    break;}
case 83:
#line 295 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITH_IDENTIFIER_KW_ARGUMENT_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 84:
#line 296 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 85:
#line 300 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITHOUT_ALTERNATIVE_IF_TYPE, yyvsp[-2].Expression, yyvsp[0].Statement, NULL);;
    break;}
case 86:
#line 301 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITH_ALTERNATIVE_IF_TYPE, yyvsp[-4].Expression, yyvsp[-2].Statement, yyvsp[0].Statement);;
    break;}
case 87:
#line 305 "bison_rules_with_code.y"
{yyval.While  = While_statement_node::createWhileStatementNode(yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 88:
#line 308 "bison_rules_with_code.y"
{yyval.Do_while = Do_while_statement_node::createDoWhileStatementNode(yyvsp[-2].Expression, yyvsp[-5].Statement);;
    break;}
case 89:
#line 311 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNode(yyvsp[-6].Expression, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 90:
#line 312 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 91:
#line 313 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-6].Identifier), yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 92:
#line 318 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);;
    break;}
case 93:
#line 319 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 94:
#line 320 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 95:
#line 321 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(IF_STATEMENT_TYPE, yyvsp[0].If);;
    break;}
case 96:
#line 322 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(WHILE_STATEMENT_TYPE, yyvsp[0].While);;
    break;}
case 97:
#line 323 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(DO_WHILE_STATEMENT_TYPE, yyvsp[0].Do_while);;
    break;}
case 98:
#line 324 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(FOR_STATEMENT_TYPE, yyvsp[0].For);;
    break;}
case 99:
#line 325 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(COMPOUND_STATEMENT_TYPE, yyvsp[0].Compound_statement);;
    break;}
case 100:
#line 326 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 101:
#line 329 "bison_rules_with_code.y"
{yyval.Compound_statement = Compound_statement_node::createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 102:
#line 332 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::createStatementListNode(yyvsp[0].Statement);;
    break;}
case 103:
#line 333 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::addToStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 104:
#line 336 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 105:
#line 337 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 106:
#line 340 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlockNodeFromInterface(yyvsp[0].Class_interface);;
    break;}
case 107:
#line 341 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlockNodeFromImplementation(yyvsp[0].Class_implementation);;
    break;}
case 108:
#line 345 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 109:
#line 346 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 110:
#line 347 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 111:
#line 350 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Interface_declaration_list);;
    break;}
case 112:
#line 351 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 113:
#line 354 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Implementation_definition_list);;
    break;}
case 114:
#line 355 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 115:
#line 358 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 116:
#line 359 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 117:
#line 360 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 118:
#line 361 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 119:
#line 362 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 120:
#line 363 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 121:
#line 366 "bison_rules_with_code.y"
{yyval.Class_declaration_list = Class_declaration_list_node::createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 122:
#line 369 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::createClassListNode(yyvsp[0].Identifier);;
    break;}
case 123:
#line 370 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::addToClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 124:
#line 373 "bison_rules_with_code.y"
{yyval.Instance_variables = Instance_variables_node::createInstanceVariablesNode(yyvsp[-1].Instance_variables_declaration_list);;
    break;}
case 125:
#line 376 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Declarator_list);;
    break;}
case 126:
#line 377 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Declarator_list);;
    break;}
case 127:
#line 380 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::createInstanceVariablesDeclarationListNode(yyvsp[0].Instance_variables_declaration);;
    break;}
case 128:
#line 381 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::addToInstanceVariablesDeclarationListNode(yyvsp[-1].Instance_variables_declaration_list, yyvsp[0].Instance_variables_declaration);;
    break;}
case 129:
#line 384 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 130:
#line 385 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 131:
#line 386 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(yyvsp[0].Method_declaration);;
    break;}
case 132:
#line 387 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 133:
#line 388 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 134:
#line 389 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 135:
#line 392 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 136:
#line 393 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 137:
#line 396 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 138:
#line 397 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 139:
#line 398 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 140:
#line 401 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 141:
#line 402 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 142:
#line 403 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 143:
#line 406 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 144:
#line 407 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromSynthesize(yyvsp[0].Synthesize);;
    break;}
case 145:
#line 408 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(yyvsp[0].Method_definition);;
    break;}
case 146:
#line 409 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 147:
#line 410 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addSynthesizeToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Synthesize);;
    break;}
case 148:
#line 411 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 149:
#line 414 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 150:
#line 415 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 151:
#line 418 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 152:
#line 419 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 153:
#line 420 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 154:
#line 423 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 155:
#line 424 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 156:
#line 425 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 157:
#line 428 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 158:
#line 429 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Keyword_declaration, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 159:
#line 430 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Keyword_declaration, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_list);;
    break;}
case 160:
#line 433 "bison_rules_with_code.y"
{yyval.Keyword_selector = NULL;;
    break;}
case 161:
#line 434 "bison_rules_with_code.y"
{yyval.Keyword_selector = yyvsp[0].Keyword_selector;;
    break;}
case 162:
#line 437 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 163:
#line 438 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::addToKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 164:
#line 441 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 165:
#line 442 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 166:
#line 445 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 167:
#line 446 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 168:
#line 447 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 169:
#line 448 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 170:
#line 451 "bison_rules_with_code.y"
{yyval.Type = yyvsp[-1].Type;;
    break;}
case 171:
#line 452 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier);;
    break;}
case 172:
#line 455 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 173:
#line 456 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-5].Attribute, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 174:
#line 457 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 175:
#line 458 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 176:
#line 459 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 177:
#line 460 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(NULL, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 178:
#line 463 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 179:
#line 464 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READWRITE_ATTRIBUTE_TYPE);;
    break;}
case 180:
#line 467 "bison_rules_with_code.y"
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
#line 470 "bison_rules_with_code.y"


void yyerror(char const *s)
{
	printf("%s",s);
}
