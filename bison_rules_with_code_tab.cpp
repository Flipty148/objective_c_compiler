
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

#define YYTRANSLATE(x) ((unsigned)(x) <= 295 ? yytranslate[x] : 121)

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
    75,    80,    82,    86,    89,    94,    96,   100,   101,   103,
   105,   109,   112,   116,   118,   120,   122,   126,   128,   130,
   135,   140,   143,   146,   149,   153,   157,   161,   165,   169,
   173,   177,   181,   185,   189,   193,   197,   201,   202,   204,
   205,   207,   209,   213,   215,   217,   219,   221,   226,   228,
   233,   240,   241,   243,   245,   248,   252,   255,   261,   269,
   275,   283,   293,   304,   316,   324,   334,   336,   339,   343,
   345,   347,   349,   351,   353,   355,   359,   361,   364,   365,
   367,   369,   371,   378,   383,   390,   397,   402,   409,   410,
   412,   415,   417,   418,   420,   423,   425,   430,   437,   442,
   449,   456,   463,   467,   469,   473,   477,   478,   480,   484,
   488,   490,   493,   495,   497,   499,   502,   505,   508,   513,
   520,   524,   529,   536,   540,   542,   544,   546,   549,   552,
   555,   561,   569,   574,   580,   588,   593,   595,   600,   607,
   608,   610,   612,   615,   618,   620,   624,   627,   632,   636,
   640,   645,   651,   658,   659,   662,   666,   670
};

static const short yyrhs[] = {    60,
     0,    95,     0,    61,     0,   102,     0,    60,    95,     0,
    60,    61,     0,    60,   102,     0,    62,    49,    19,    20,
    92,     0,    21,     0,    22,     0,    23,     0,    41,     0,
    47,     0,    44,     0,    45,     0,    46,     0,    48,     0,
    62,    68,    51,     0,    50,    75,    51,     0,    65,     0,
    66,    65,     0,     0,    66,     0,     0,    69,     0,    70,
     0,    69,    52,    70,     0,    49,     0,    49,     3,    78,
     0,    12,    49,     0,    71,    52,    12,    49,     0,    49,
     0,    72,    52,    49,     0,    12,    49,     0,    12,    49,
     3,    78,     0,    73,     0,    74,    52,    73,     0,     0,
    74,     0,    77,     0,    76,    52,    77,     0,    62,    49,
     0,    50,    12,    49,     0,    49,     0,    64,     0,    63,
     0,    19,    78,    20,     0,    39,     0,    40,     0,    53,
    82,    83,    54,     0,    49,    19,    80,    20,     0,    11,
    78,     0,    10,    78,     0,    55,    78,     0,    78,    10,
    78,     0,    78,    11,    78,     0,    78,    12,    78,     0,
    78,    13,    78,     0,    78,     4,    78,     0,    78,     5,
    78,     0,    78,     7,    78,     0,    78,     6,    78,     0,
    78,     8,    78,     0,    78,     9,    78,     0,    78,     3,
    78,     0,    78,    17,    49,     0,    78,    18,    49,     0,
     0,    78,     0,     0,    81,     0,    78,     0,    81,    52,
    78,     0,    40,     0,    39,     0,    49,     0,    50,     0,
    53,    82,    83,    54,     0,    49,     0,    49,    56,    78,
    84,     0,    49,    56,    78,    84,    52,    81,     0,     0,
    85,     0,    86,     0,    85,    86,     0,    49,    56,    78,
     0,    56,    78,     0,    26,    19,    78,    20,    91,     0,
    26,    19,    78,    20,    91,    27,    91,     0,    28,    19,
    78,    20,    91,     0,    29,    91,    28,    19,    78,    20,
    51,     0,    30,    19,    79,    51,    79,    51,    79,    20,
    91,     0,    30,    19,    62,    68,    51,    79,    51,    79,
    20,    91,     0,    30,    19,    50,    12,    68,    51,    79,
    51,    79,    20,    91,     0,    30,    19,    49,    31,    78,
    20,    91,     0,    30,    19,    50,    12,    49,    31,    78,
    20,    91,     0,    51,     0,    78,    51,     0,    43,    79,
    51,     0,    87,     0,    88,     0,    89,     0,    90,     0,
    92,     0,    65,     0,    57,    94,    58,     0,    91,     0,
    93,    91,     0,     0,    93,     0,    96,     0,   101,     0,
    32,    49,    56,    49,    97,    34,     0,    32,    49,    97,
    34,     0,    32,    49,    56,    50,    97,    34,     0,    32,
    50,    56,    49,    97,    34,     0,    32,    50,    97,    34,
     0,    32,    50,    56,    50,    97,    34,     0,     0,    98,
     0,   104,   108,     0,   108,     0,     0,   100,     0,   104,
   110,     0,   110,     0,    33,    49,    99,    34,     0,    33,
    49,    56,    49,    99,    34,     0,    33,    50,    99,    34,
     0,    33,    50,    56,    49,    99,    34,     0,    33,    49,
    56,    50,    99,    34,     0,    33,    50,    56,    50,    99,
    34,     0,    42,   103,    51,     0,    49,     0,   103,    52,
    49,     0,    57,   105,    58,     0,     0,   107,     0,    62,
    72,    51,     0,    50,    71,    51,     0,   106,     0,   107,
   106,     0,    65,     0,   118,     0,   109,     0,   108,    65,
     0,   108,   109,     0,   108,   118,     0,    10,   117,   112,
    51,     0,    10,    19,    24,    20,   112,    51,     0,    10,
   112,    51,     0,    11,   117,   112,    51,     0,    11,    19,
    24,    20,   112,    51,     0,    11,   112,    51,     0,    65,
     0,   120,     0,   111,     0,   110,    65,     0,   110,   120,
     0,   110,   111,     0,    10,   117,   112,    67,    92,     0,
    10,    19,    24,    20,   112,    67,    92,     0,    10,   112,
    67,    92,     0,    11,   117,   112,    67,    92,     0,    11,
    19,    24,    20,   112,    67,    92,     0,    11,   112,    67,
    92,     0,    49,     0,    49,    56,   115,   113,     0,    49,
    56,   115,   113,    52,    76,     0,     0,   114,     0,   116,
     0,   114,   116,     0,   117,    49,     0,    49,     0,    56,
   117,    49,     0,    56,    49,     0,    49,    56,   117,    49,
     0,    49,    56,    49,     0,    19,    62,    20,     0,    19,
    50,    12,    20,     0,    35,   119,    62,    49,    51,     0,
    35,   119,    50,    12,    49,    51,     0,     0,    19,    20,
     0,    19,    36,    20,     0,    19,    37,    20,     0,    38,
    49,    51,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   150,   153,   154,   155,   156,   157,   158,   163,   167,   168,
   169,   170,   174,   175,   178,   179,   180,   184,   185,   188,
   189,   192,   193,   196,   197,   200,   201,   204,   205,   208,
   209,   211,   212,   215,   216,   219,   220,   223,   224,   227,
   228,   231,   232,   237,   238,   239,   240,   241,   242,   243,
   244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
   254,   255,   256,   257,   258,   259,   260,   263,   264,   267,
   268,   271,   272,   275,   276,   277,   278,   279,   282,   283,
   284,   287,   288,   291,   292,   295,   296,   300,   301,   305,
   308,   311,   312,   313,   314,   315,   320,   321,   322,   323,
   324,   325,   326,   327,   328,   331,   334,   335,   338,   339,
   342,   343,   347,   348,   349,   350,   351,   352,   355,   356,
   359,   360,   363,   364,   367,   368,   371,   372,   373,   374,
   375,   376,   379,   382,   383,   386,   389,   390,   393,   394,
   397,   398,   401,   402,   403,   404,   405,   406,   409,   410,
   411,   412,   413,   414,   417,   418,   419,   420,   421,   422,
   425,   426,   427,   428,   429,   430,   433,   434,   435,   438,
   439,   442,   443,   446,   447,   450,   451,   452,   453,   456,
   457,   460,   461,   464,   465,   466,   467,   470
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
"init_declarator_list","init_declarator","declarator_with_asterisk_list","declarator_list",
"init_declarator_with_asterisk","init_declarator_with_asterisk_list","init_declarator_with_asterisk_list_e",
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
    71,    72,    72,    73,    73,    74,    74,    75,    75,    76,
    76,    77,    77,    78,    78,    78,    78,    78,    78,    78,
    78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
    78,    78,    78,    78,    78,    78,    78,    79,    79,    80,
    80,    81,    81,    82,    82,    82,    82,    82,    83,    83,
    83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
    89,    90,    90,    90,    90,    90,    91,    91,    91,    91,
    91,    91,    91,    91,    91,    92,    93,    93,    94,    94,
    95,    95,    96,    96,    96,    96,    96,    96,    97,    97,
    98,    98,    99,    99,   100,   100,   101,   101,   101,   101,
   101,   101,   102,   103,   103,   104,   105,   105,   106,   106,
   107,   107,   108,   108,   108,   108,   108,   108,   109,   109,
   109,   109,   109,   109,   110,   110,   110,   110,   110,   110,
   111,   111,   111,   111,   111,   111,   112,   112,   112,   113,
   113,   114,   114,   115,   115,   116,   116,   116,   116,   117,
   117,   118,   118,   119,   119,   119,   119,   120
};

static const short yyr2[] = {     0,
     1,     1,     1,     1,     2,     2,     2,     5,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
     2,     0,     1,     0,     1,     1,     3,     1,     3,     2,
     4,     1,     3,     2,     4,     1,     3,     0,     1,     1,
     3,     2,     3,     1,     1,     1,     3,     1,     1,     4,
     4,     2,     2,     2,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     0,     1,     0,
     1,     1,     3,     1,     1,     1,     1,     4,     1,     4,
     6,     0,     1,     1,     2,     3,     2,     5,     7,     5,
     7,     9,    10,    11,     7,     9,     1,     2,     3,     1,
     1,     1,     1,     1,     1,     3,     1,     2,     0,     1,
     1,     1,     6,     4,     6,     6,     4,     6,     0,     1,
     2,     1,     0,     1,     2,     1,     4,     6,     4,     6,
     6,     6,     3,     1,     3,     3,     0,     1,     3,     3,
     1,     2,     1,     1,     1,     2,     2,     2,     4,     6,
     3,     4,     6,     3,     1,     1,     1,     2,     2,     2,
     5,     7,     4,     5,     7,     4,     1,     4,     6,     0,
     1,     1,     2,     2,     1,     3,     2,     4,     3,     3,
     4,     5,     6,     0,     2,     3,     3,     3
};

static const short yydefact[] = {     0,
     9,    10,    11,     0,     0,    12,     0,     1,     3,     0,
     2,   111,   112,     4,   119,   119,   123,   123,   134,     0,
     6,     5,     7,     0,     0,     0,   184,    38,     0,   137,
    24,   143,     0,   120,     0,   122,   145,   144,     0,     0,
     0,     0,     0,     0,   155,     0,   124,     0,   126,   157,
   156,     0,     0,   133,     0,     0,     0,   167,     0,     0,
     0,     0,     0,     0,     0,     0,    36,    39,     0,   119,
   119,     0,     0,     0,   141,   138,    28,     0,    25,    26,
   114,   121,   146,   147,   148,   119,   119,   117,     0,    22,
     0,     0,    22,     0,     0,   123,   123,   127,   125,   158,
   160,   159,   123,   123,   129,   135,     0,     0,     0,     0,
     0,   151,     0,     0,   154,     0,   185,     0,     0,     0,
     0,    34,     0,    19,     0,     0,     0,     0,    32,     0,
   136,   142,     0,    18,     0,     0,     0,     0,    20,    23,
     0,    22,     0,     0,    22,   188,     0,     0,     0,     0,
   109,     8,     0,     0,   180,     0,   175,   170,     0,   149,
     0,   152,   186,   187,     0,     0,     0,    37,   113,   115,
    30,   140,     0,   139,     0,     0,     0,     0,    48,    49,
    14,    15,    16,    13,    17,    44,     0,     0,    46,    45,
    29,    27,   116,   118,     0,    21,   163,     0,     0,   166,
     0,   128,   131,   130,   132,     0,     0,     0,     0,    68,
    97,   105,     0,   100,   101,   102,   103,   107,   104,   110,
     0,     0,   181,     0,     0,   168,   171,   172,   174,     0,
     0,   182,    35,     0,    33,    53,    52,     0,    70,    75,
    74,    76,    77,     0,     0,    54,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
   161,    22,   164,     0,     0,     0,    68,    69,     0,    98,
   108,   106,   150,     0,   177,     0,     0,   173,   153,   183,
    31,    47,    72,     0,    71,     0,    79,     0,    65,    59,
    60,    62,    61,    63,    64,    55,    56,    57,    58,    66,
    67,     0,     0,     0,     0,     0,    44,     0,    24,     0,
    99,   179,     0,   176,     0,     0,   169,    40,    51,     0,
     0,     0,    50,   162,   165,     0,     0,     0,     0,    24,
     0,    68,   178,     0,    42,     0,    73,    78,    82,    88,
    90,     0,     0,    28,     0,    68,     0,    43,    41,     0,
     0,    80,    83,    84,     0,     0,     0,     0,    68,     0,
    68,     0,    87,     0,    85,    89,    91,    95,     0,     0,
    68,     0,    86,    81,     0,    68,     0,     0,    96,     0,
     0,    92,     0,    93,    94,     0,     0,     0
};

static const short yydefgoto[] = {   386,
     8,     9,    31,   189,   190,   212,   140,   141,    78,    79,
    80,   128,   130,    67,    68,    69,   317,   318,   213,   269,
   284,   285,   245,   288,   352,   353,   354,   214,   215,   216,
   217,   218,   219,   220,   221,    11,    12,    33,    34,    46,
    47,    13,    14,    20,    35,    74,    75,    76,    36,    37,
    49,    50,    59,   226,   227,   158,   228,    60,    38,    65,
    51
};

static const short yypact[] = {   273,
-32768,-32768,-32768,   -22,    -6,-32768,     5,   273,-32768,    11,
-32768,-32768,-32768,-32768,   371,   374,   233,   379,-32768,   -14,
-32768,-32768,-32768,    30,     1,    15,    63,    58,    13,   243,
    31,-32768,    65,-32768,   511,   511,-32768,-32768,    76,    68,
    17,    22,    36,    86,-32768,    81,-32768,   517,   517,-32768,
-32768,    96,    97,-32768,    46,   113,   188,    64,    87,    92,
   336,   102,    92,    61,   259,   108,-32768,   107,   126,   422,
   422,   168,   133,   125,-32768,   243,   182,   147,   149,-32768,
-32768,   511,-32768,-32768,-32768,   422,   422,-32768,   521,   433,
    92,   527,   433,    92,   148,   427,   427,-32768,   517,-32768,
-32768,-32768,   427,   427,-32768,-32768,   145,   183,   203,   196,
    23,-32768,   177,   210,-32768,   185,-32768,   217,   230,   239,
   193,   255,    58,-32768,   227,   242,   224,   100,-32768,   118,
-32768,-32768,   471,-32768,    31,   244,   251,   267,-32768,   433,
   145,   433,   268,   145,   433,-32768,   258,   263,   269,   274,
   323,-32768,    92,   287,-32768,   542,-32768,   -30,   261,-32768,
    92,-32768,-32768,-32768,   264,   277,   471,-32768,-32768,-32768,
-32768,-32768,   300,-32768,   280,   471,   471,   471,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   311,    74,   471,-32768,-32768,
   708,-32768,-32768,-32768,    92,-32768,-32768,   145,    92,-32768,
   145,-32768,-32768,-32768,-32768,   316,   318,   323,   319,   471,
-32768,-32768,   314,-32768,-32768,-32768,-32768,-32768,-32768,   323,
   281,   289,-32768,   285,    28,   291,   -30,-32768,-32768,   296,
   297,-32768,   708,   301,-32768,   158,   158,   600,   471,-32768,
-32768,-32768,-32768,    74,   305,   158,   471,   471,   471,   471,
   471,   471,   471,   471,   471,   471,   471,   306,   307,   433,
-32768,   433,-32768,   471,   471,   333,   448,   708,   324,-32768,
-32768,-32768,-32768,    59,-32768,   330,   552,-32768,-32768,-32768,
-32768,-32768,   708,   363,   335,   305,   332,   337,   708,   155,
   155,   235,   235,   235,   235,   222,   222,   158,   158,-32768,
-32768,   145,   145,   618,   636,   380,   -10,   386,    31,   352,
-32768,-32768,   355,-32768,   393,   358,   356,-32768,-32768,   471,
   357,   471,-32768,-32768,-32768,   323,   323,   471,   471,   361,
   362,   471,-32768,   365,-32768,   552,   708,-32768,   214,   389,
-32768,   654,   672,     4,   367,   471,   368,-32768,-32768,   366,
   471,   373,   -27,-32768,   323,   372,   323,   471,   471,   375,
   471,   471,   708,   471,-32768,-32768,-32768,-32768,   690,   383,
   471,   419,   708,   335,   323,   471,   420,   323,-32768,   421,
   323,-32768,   323,-32768,-32768,   442,   446,-32768
};

static const short yypgoto[] = {-32768,
-32768,   439,     0,-32768,-32768,    -3,-32768,   -54,  -299,-32768,
   317,-32768,-32768,   328,-32768,-32768,-32768,   117,   -60,  -227,
-32768,    98,   216,   175,-32768,-32768,   111,-32768,-32768,-32768,
-32768,  -197,   -89,-32768,-32768,   458,-32768,   -12,-32768,    51,
-32768,-32768,   465,-32768,     7,-32768,   399,-32768,   441,   -34,
   430,   -46,    80,-32768,-32768,-32768,   253,   -25,   -31,-32768,
   -43
};


#define	YYLAST		726


static const short yytable[] = {    10,
    63,    84,   101,    40,    85,   102,   133,    10,   239,   331,
   266,    32,    32,    45,    45,    91,    94,   152,   224,    57,
   329,   350,   271,    48,    48,   225,    15,    16,   351,    73,
   345,    32,    83,    61,   358,    89,    54,    55,   144,   310,
    92,   156,    17,    18,    45,   100,   156,    84,    56,    58,
    85,   197,   101,    19,   200,   102,   110,   125,   126,    24,
   110,    70,    71,    58,   121,    58,    32,    32,    53,    66,
    58,   157,   191,   136,   137,    73,   275,   156,    83,    77,
   117,    64,    32,    32,    95,   159,   139,   198,   110,   139,
   201,   110,    45,    45,   106,   100,   118,   119,    81,    45,
    45,    88,    48,    48,   347,    62,   233,   312,   261,    48,
    48,   263,   240,   241,    98,   236,   237,   238,   360,   111,
    90,    93,   242,   243,    86,    87,   244,   246,   340,   341,
   105,   370,   107,   372,    96,    97,   196,   112,   139,   113,
    58,   139,   116,   377,   103,   104,   147,   148,   380,   268,
   172,   173,   115,   149,   150,   110,   122,   366,   123,   368,
   250,   251,   252,   253,   254,   255,   256,   257,   174,   175,
   142,   258,   259,   145,   258,   259,   124,   379,   283,   127,
   382,   129,   131,   384,   133,   385,   289,   290,   291,   292,
   293,   294,   295,   296,   297,   298,   299,   134,   146,   276,
   135,   151,   153,   304,   305,   302,   268,   303,     1,     2,
     3,   108,   324,   325,   154,   155,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,   160,     6,   161,
   258,   259,   222,   256,   257,   162,   163,   109,   258,   259,
   230,   166,    41,    42,   254,   255,   256,   257,   313,   164,
   165,   258,   259,     1,     2,     3,   139,   167,   139,   337,
   169,   339,   350,     1,     2,     3,   309,   342,   343,   351,
    43,   268,   171,     6,   260,   170,   316,   193,   262,     1,
     2,     3,    28,     6,   194,   268,   195,   199,    44,    30,
   363,   202,    72,     1,     2,     3,   203,   369,   268,     6,
   268,   373,   204,   283,     4,     5,   223,   205,   120,   229,
   268,   234,   231,     6,     7,   268,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,   232,   235,   239,
   258,   259,   176,   177,   264,   316,   265,   267,   272,   273,
   274,   178,   277,     1,     2,     3,   279,   280,   206,   281,
   207,   208,   209,   287,   300,   301,     1,     2,     3,   114,
   306,   179,   180,     6,   270,   210,   181,   182,   183,   184,
   185,   186,    28,   211,   311,   187,     6,   188,   314,   151,
    25,    26,   319,    25,    26,   109,   320,   322,    41,    42,
   323,     1,     2,     3,     1,     2,     3,   330,   328,     1,
     2,     3,   332,   333,   334,    27,   335,   336,    27,   344,
   338,     6,   346,   348,     6,   355,    43,   359,   361,     6,
    28,   362,   367,    28,   364,   371,    29,    30,    28,    39,
    30,    25,    26,   376,    52,    30,    41,    42,   378,   381,
   383,   387,     1,     2,     3,   388,    21,     1,     2,     3,
   168,   192,   349,     1,     2,     3,    27,   176,   177,   286,
   321,   374,     6,   365,    43,    22,   178,     6,     1,     2,
     3,    28,    23,     6,   132,    82,    28,    99,    30,   278,
   176,   177,    28,    30,     0,     0,   179,   180,     6,   178,
     0,   181,   182,   183,   184,   185,   307,   308,     0,     0,
   187,     0,   188,     0,     0,     0,     0,     0,     0,   179,
   180,     0,     0,     0,   181,   182,   183,   184,   185,   186,
    25,    26,     0,   187,     0,   188,    41,    42,     0,     0,
     0,     1,     2,     3,     0,     0,     0,     1,     2,     3,
     0,     1,     2,     3,   138,    27,     0,     1,     2,     3,
   143,     6,     0,     0,    43,     0,     0,     6,     0,     0,
    28,     6,     1,     2,     3,     0,    28,     6,     0,     0,
   109,     0,     1,     2,     3,     0,   109,     0,     0,     0,
     0,     0,     6,     0,     0,     0,     0,     0,     0,     0,
     0,   109,     6,     0,     0,     0,     0,     0,     0,     0,
     0,   315,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,     0,     0,     0,   258,   259,     0,   282,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,     0,     0,     0,   258,   259,     0,   326,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,     0,
     0,     0,   258,   259,     0,   327,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,     0,     0,     0,
   258,   259,     0,   356,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,     0,     0,     0,   258,   259,
     0,   357,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,     0,     0,     0,   258,   259,     0,   375,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,     0,     0,     0,   258,   259
};

static const short yycheck[] = {     0,
    26,    36,    49,    16,    36,    49,     3,     8,    19,   309,
   208,    15,    16,    17,    18,    41,    42,   107,    49,    19,
    31,    49,   220,    17,    18,    56,    49,    50,    56,    30,
   330,    35,    36,    19,    31,    19,    51,    52,    93,   267,
    19,    19,    49,    50,    48,    49,    19,    82,    19,    49,
    82,   141,    99,    49,   144,    99,    57,    70,    71,    49,
    61,    49,    50,    49,    65,    49,    70,    71,    18,    12,
    49,    49,   133,    86,    87,    76,    49,    19,    82,    49,
    20,    19,    86,    87,    49,   111,    90,   142,    89,    93,
   145,    92,    96,    97,    49,    99,    36,    37,    34,   103,
   104,    34,    96,    97,   332,    26,   167,    49,   198,   103,
   104,   201,    39,    40,    34,   176,   177,   178,   346,    56,
    41,    42,    49,    50,    49,    50,    53,   188,   326,   327,
    34,   359,    20,   361,    49,    50,   140,    51,   142,    60,
    49,   145,    63,   371,    49,    50,    96,    97,   376,   210,
    51,    52,    51,   103,   104,   156,    49,   355,    52,   357,
     6,     7,     8,     9,    10,    11,    12,    13,    51,    52,
    91,    17,    18,    94,    17,    18,    51,   375,   239,    12,
   378,    49,    58,   381,     3,   383,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    51,    51,   225,
    52,    57,    20,   264,   265,   260,   267,   262,    21,    22,
    23,    24,   302,   303,    12,    20,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    51,    41,    20,
    17,    18,   153,    12,    13,    51,    20,    50,    17,    18,
   161,    49,    10,    11,    10,    11,    12,    13,   274,    20,
    12,    17,    18,    21,    22,    23,   260,     3,   262,   320,
    34,   322,    49,    21,    22,    23,   267,   328,   329,    56,
    38,   332,    49,    41,   195,    34,   277,    34,   199,    21,
    22,    23,    50,    41,    34,   346,    20,    20,    56,    57,
   351,    34,    50,    21,    22,    23,    34,   358,   359,    41,
   361,   362,    34,   364,    32,    33,    20,    34,    50,    49,
   371,    12,    49,    41,    42,   376,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    51,    49,    19,
    17,    18,    10,    11,    19,   336,    19,    19,    58,    51,
    56,    19,    52,    21,    22,    23,    51,    51,    26,    49,
    28,    29,    30,    49,    49,    49,    21,    22,    23,    24,
    28,    39,    40,    41,    51,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    51,    53,    41,    55,    49,    57,
    10,    11,    20,    10,    11,    50,    52,    56,    10,    11,
    54,    21,    22,    23,    21,    22,    23,    12,    19,    21,
    22,    23,    51,    49,    12,    35,    49,    52,    35,    49,
    54,    41,    51,    49,    41,    27,    38,    51,    51,    41,
    50,    56,    51,    50,    52,    51,    56,    57,    50,    56,
    57,    10,    11,    51,    56,    57,    10,    11,    20,    20,
    20,     0,    21,    22,    23,     0,     8,    21,    22,    23,
   123,   135,   336,    21,    22,    23,    35,    10,    11,   244,
   286,   364,    41,   353,    38,     8,    19,    41,    21,    22,
    23,    50,     8,    41,    76,    35,    50,    48,    57,   227,
    10,    11,    50,    57,    -1,    -1,    39,    40,    41,    19,
    -1,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    39,
    40,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
    10,    11,    -1,    53,    -1,    55,    10,    11,    -1,    -1,
    -1,    21,    22,    23,    -1,    -1,    -1,    21,    22,    23,
    -1,    21,    22,    23,    24,    35,    -1,    21,    22,    23,
    24,    41,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,
    50,    41,    21,    22,    23,    -1,    50,    41,    -1,    -1,
    50,    -1,    21,    22,    23,    -1,    50,    -1,    -1,    -1,
    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    50,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    50,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    -1,    -1,    -1,    17,    18,    -1,    20,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
    -1,    -1,    17,    18,    -1,    20,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
    17,    18,    -1,    20,     3,     4,     5,     6,     7,     8,
     9,    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,
    -1,    20,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    -1,    -1,    -1,    17,    18
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
#line 150 "bison_rules_with_code.y"
{yyval.Program = root = Program_node::createProgramNode(yyvsp[0].Function_and_class_list);;
    break;}
case 2:
#line 153 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassBlock(yyvsp[0].Class_block);;
    break;}
case 3:
#line 154 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromFunction(yyvsp[0].Function);;
    break;}
case 4:
#line 155 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassDeclarationList(yyvsp[0].Class_declaration_list);;
    break;}
case 5:
#line 156 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassBlock(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_block);;
    break;}
case 6:
#line 157 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromFunction(yyvsp[-1].Function_and_class_list, yyvsp[0].Function);;
    break;}
case 7:
#line 158 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassDeclarationList(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_declaration_list);;
    break;}
case 8:
#line 163 "bison_rules_with_code.y"
{yyval.Function = Function_node::createFunctionNode(yyvsp[-4].Type, yyvsp[-3].Identifier, yyvsp[0].Compound_statement);;
    break;}
case 9:
#line 167 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(INT_TYPE);;
    break;}
case 10:
#line 168 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(CHAR_TYPE);;
    break;}
case 11:
#line 169 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(FLOAT_TYPE);;
    break;}
case 12:
#line 170 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(ID_TYPE);;
    break;}
case 13:
#line 174 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromFloat(yyvsp[0].Float_constant);;
    break;}
case 14:
#line 175 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromInteger(yyvsp[0].Integer_constant);;
    break;}
case 15:
#line 178 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(STRING_CONSTANT_TYPE, yyvsp[0].String_constant);;
    break;}
case 16:
#line 179 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(CHAR_CONSTANT_TYPE, yyvsp[0].Char_constant);;
    break;}
case 17:
#line 180 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(NSSTRING_CONSTANT_TYPE, yyvsp[0].NSString_constant);;
    break;}
case 18:
#line 184 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Init_declarator_list);;
    break;}
case 19:
#line 185 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Init_declarator_list);
    break;}
case 20:
#line 188 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::createDeclarationListNode(yyvsp[0].Declaration);;
    break;}
case 21:
#line 189 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::addToDeclarationListNode(yyvsp[-1].Declaration_list, yyvsp[0].Declaration);;
    break;}
case 22:
#line 192 "bison_rules_with_code.y"
{yyval.Declaration_list = NULL;;
    break;}
case 23:
#line 193 "bison_rules_with_code.y"
{yyval.Declaration_list = yyvsp[0].Declaration_list;;
    break;}
case 24:
#line 196 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 25:
#line 197 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 26:
#line 200 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 27:
#line 201 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 28:
#line 204 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Identifier, NULL);;
    break;}
case 29:
#line 205 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 30:
#line 208 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Identifier);;
    break;}
case 31:
#line 209 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-3].Declarator_list, yyvsp[0].Identifier);;
    break;}
case 32:
#line 211 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Identifier);;
    break;}
case 33:
#line 212 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-2].Declarator_list,yyvsp[0].Identifier);;
    break;}
case 34:
#line 215 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Identifier, NULL);;
    break;}
case 35:
#line 216 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 36:
#line 219 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 37:
#line 220 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 38:
#line 223 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 39:
#line 224 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 40:
#line 227 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::createParameterListNode(yyvsp[0].Parameter_declaration);;
    break;}
case 41:
#line 228 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::addToParameterListNode(yyvsp[-2].Parameter_list, yyvsp[0].Parameter_declaration);;
    break;}
case 42:
#line 231 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(yyvsp[-1].Type, yyvsp[0].Identifier);;
    break;}
case 43:
#line 232 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier),yyvsp[0].Identifier);;
    break;}
case 44:
#line 237 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromIdentifier(yyvsp[0].Identifier);;
    break;}
case 45:
#line 238 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromLiteral(yyvsp[0].Literal);;
    break;}
case 46:
#line 239 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromNumericConstant(yyvsp[0].Numeric_constant);;
    break;}
case 47:
#line 240 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSimpleExpression(PRIORITY_EXPRESSION_TYPE, yyvsp[-1].Expression);;
    break;}
case 48:
#line 241 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSelf();;
    break;}
case 49:
#line 242 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSuper();;
    break;}
case 50:
#line 243 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 51:
#line 244 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromFunctionCall(yyvsp[-3].Identifier, yyvsp[-1].Expression_list);;
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
#line 259 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMemberAccessOperator(DOT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Identifier);;
    break;}
case 67:
#line 260 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMemberAccessOperator(ARROW_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Identifier);;
    break;}
case 68:
#line 263 "bison_rules_with_code.y"
{yyval.Expression = NULL;;
    break;}
case 69:
#line 264 "bison_rules_with_code.y"
{yyval.Expression = yyvsp[0].Expression;;
    break;}
case 70:
#line 267 "bison_rules_with_code.y"
{yyval.Expression_list = NULL;;
    break;}
case 71:
#line 268 "bison_rules_with_code.y"
{yyval.Expression_list = yyvsp[0].Expression_list;;
    break;}
case 72:
#line 271 "bison_rules_with_code.y"
{yyval.Expression_list = Expression_list_node::createExpressionListNode(yyvsp[0].Expression);;
    break;}
case 73:
#line 272 "bison_rules_with_code.y"
{yyval.Expression_list = Expression_list_node::addToExpressionListNode(yyvsp[-2].Expression_list, yyvsp[0].Expression);;
    break;}
case 74:
#line 275 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);;
    break;}
case 75:
#line 276 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);;
    break;}
case 76:
#line 277 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(OBJECT_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 77:
#line 278 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(CLASS_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 78:
#line 279 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 79:
#line 282 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 80:
#line 283 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Expression, yyvsp[0].Keyword_argument_list, NULL);;
    break;}
case 81:
#line 284 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Expression, yyvsp[-2].Keyword_argument_list, yyvsp[0].Expression_list);;
    break;}
case 82:
#line 287 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = NULL;;
    break;}
case 83:
#line 288 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = yyvsp[0].Keyword_argument_list;;
    break;}
case 84:
#line 291 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::createKeywordArgumentListNode(yyvsp[0].Keyword_argument);;
    break;}
case 85:
#line 292 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::addToKeywordArgumentListNode(yyvsp[-1].Keyword_argument_list, yyvsp[0].Keyword_argument);;
    break;}
case 86:
#line 295 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITH_IDENTIFIER_KW_ARGUMENT_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 87:
#line 296 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 88:
#line 300 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITHOUT_ALTERNATIVE_IF_TYPE, yyvsp[-2].Expression, yyvsp[0].Statement, NULL);;
    break;}
case 89:
#line 301 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITH_ALTERNATIVE_IF_TYPE, yyvsp[-4].Expression, yyvsp[-2].Statement, yyvsp[0].Statement);;
    break;}
case 90:
#line 305 "bison_rules_with_code.y"
{yyval.While  = While_statement_node::createWhileStatementNode(yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 91:
#line 308 "bison_rules_with_code.y"
{yyval.Do_while = Do_while_statement_node::createDoWhileStatementNode(yyvsp[-2].Expression, yyvsp[-5].Statement);;
    break;}
case 92:
#line 311 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNode(yyvsp[-6].Expression, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 93:
#line 312 "bison_rules_with_code.y"
{yyval.For =For_statement_node::createForStatementNodeFromForWithDeclaration(yyvsp[-7].Type, yyvsp[-6].Init_declarator_list, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 94:
#line 313 "bison_rules_with_code.y"
{yyval.For =For_statement_node::createForStatementNodeFromForWithDeclaration(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-8].Identifier), yyvsp[-6].Init_declarator_list, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 95:
#line 314 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 96:
#line 315 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-6].Identifier), yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 97:
#line 320 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);;
    break;}
case 98:
#line 321 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 99:
#line 322 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 100:
#line 323 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].If;;
    break;}
case 101:
#line 324 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].While;;
    break;}
case 102:
#line 325 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].Do_while;;
    break;}
case 103:
#line 326 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].For;;
    break;}
case 104:
#line 327 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].Compound_statement;;
    break;}
case 105:
#line 328 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].Declaration;;
    break;}
case 106:
#line 331 "bison_rules_with_code.y"
{yyval.Compound_statement = Compound_statement_node::createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 107:
#line 334 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::createStatementListNode(yyvsp[0].Statement);;
    break;}
case 108:
#line 335 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::addToStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 109:
#line 338 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 110:
#line 339 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 111:
#line 342 "bison_rules_with_code.y"
{yyval.Class_block = yyvsp[0].Class_interface;;
    break;}
case 112:
#line 343 "bison_rules_with_code.y"
{yyval.Class_block = yyvsp[0].Class_implementation;;
    break;}
case 113:
#line 347 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 114:
#line 348 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 115:
#line 349 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 116:
#line 350 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 117:
#line 351 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 118:
#line 352 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 119:
#line 355 "bison_rules_with_code.y"
{yyval.Interface_body = NULL;;
    break;}
case 120:
#line 356 "bison_rules_with_code.y"
{yyval.Interface_body = yyvsp[0].Interface_body;;
    break;}
case 121:
#line 359 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Interface_declaration_list);;
    break;}
case 122:
#line 360 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 123:
#line 363 "bison_rules_with_code.y"
{yyval.Implementation_body = NULL;;
    break;}
case 124:
#line 364 "bison_rules_with_code.y"
{yyval.Implementation_body = yyvsp[0].Implementation_body;;
    break;}
case 125:
#line 367 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Implementation_definition_list);;
    break;}
case 126:
#line 368 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 127:
#line 371 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 128:
#line 372 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 129:
#line 373 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 130:
#line 374 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 131:
#line 375 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 132:
#line 376 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 133:
#line 379 "bison_rules_with_code.y"
{yyval.Class_declaration_list = Class_declaration_list_node::createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 134:
#line 382 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::createClassListNode(yyvsp[0].Identifier);;
    break;}
case 135:
#line 383 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::addToClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 136:
#line 386 "bison_rules_with_code.y"
{yyval.Instance_variables = Instance_variables_node::createInstanceVariablesNode(yyvsp[-1].Instance_variables_declaration_list);;
    break;}
case 137:
#line 389 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = NULL;;
    break;}
case 138:
#line 390 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = yyvsp[0].Instance_variables_declaration_list;;
    break;}
case 139:
#line 393 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Declarator_list);;
    break;}
case 140:
#line 394 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Declarator_list);;
    break;}
case 141:
#line 397 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::createInstanceVariablesDeclarationListNode(yyvsp[0].Instance_variables_declaration);;
    break;}
case 142:
#line 398 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::addToInstanceVariablesDeclarationListNode(yyvsp[-1].Instance_variables_declaration_list, yyvsp[0].Instance_variables_declaration);;
    break;}
case 143:
#line 401 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 144:
#line 402 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 145:
#line 403 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(yyvsp[0].Method_declaration);;
    break;}
case 146:
#line 404 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 147:
#line 405 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 148:
#line 406 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 149:
#line 409 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 150:
#line 410 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 151:
#line 411 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 152:
#line 412 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 153:
#line 413 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 154:
#line 414 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 155:
#line 417 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 156:
#line 418 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromSynthesize(yyvsp[0].Synthesize);;
    break;}
case 157:
#line 419 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(yyvsp[0].Method_definition);;
    break;}
case 158:
#line 420 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 159:
#line 421 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addSynthesizeToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Synthesize);;
    break;}
case 160:
#line 422 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 161:
#line 425 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 162:
#line 426 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 163:
#line 427 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 164:
#line 428 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 165:
#line 429 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 166:
#line 430 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 167:
#line 433 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 168:
#line 434 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Keyword_declaration, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 169:
#line 435 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Keyword_declaration, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_list);;
    break;}
case 170:
#line 438 "bison_rules_with_code.y"
{yyval.Keyword_selector = NULL;;
    break;}
case 171:
#line 439 "bison_rules_with_code.y"
{yyval.Keyword_selector = yyvsp[0].Keyword_selector;;
    break;}
case 172:
#line 442 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 173:
#line 443 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::addToKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 174:
#line 446 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 175:
#line 447 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 176:
#line 450 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 177:
#line 451 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 178:
#line 452 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 179:
#line 453 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 180:
#line 456 "bison_rules_with_code.y"
{yyval.Type = yyvsp[-1].Type;;
    break;}
case 181:
#line 457 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier);;
    break;}
case 182:
#line 460 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-3].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 183:
#line 461 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 184:
#line 464 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(EMPTY_ATTRIBUTE_TYPE);;
    break;}
case 185:
#line 465 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(EMPTY_ATTRIBUTE_TYPE);;
    break;}
case 186:
#line 466 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 187:
#line 467 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READWRITE_ATTRIBUTE_TYPE);;
    break;}
case 188:
#line 470 "bison_rules_with_code.y"
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
#line 473 "bison_rules_with_code.y"


void yyerror(char const *s)
{
	printf("%s",s);
}
