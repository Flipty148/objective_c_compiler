
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



#define	YYFINAL		389
#define	YYFLAG		-32768
#define	YYNTBASE	59

#define YYTRANSLATE(x) ((unsigned)(x) <= 295 ? yytranslate[x] : 120)

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
   412,   417,   419,   420,   422,   427,   429,   434,   441,   446,
   453,   460,   467,   471,   473,   477,   478,   480,   484,   488,
   490,   493,   495,   497,   499,   502,   505,   508,   513,   520,
   524,   529,   536,   540,   542,   544,   546,   549,   552,   555,
   561,   569,   574,   580,   588,   593,   595,   600,   607,   608,
   610,   612,   615,   618,   620,   624,   627,   632,   636,   640,
   645,   651,   658,   659,   662,   666,   670
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
     0,    57,   104,    58,   107,     0,   107,     0,     0,   100,
     0,    57,   104,    58,   109,     0,   109,     0,    33,    49,
    99,    34,     0,    33,    49,    56,    49,    99,    34,     0,
    33,    50,    99,    34,     0,    33,    50,    56,    49,    99,
    34,     0,    33,    49,    56,    50,    99,    34,     0,    33,
    50,    56,    50,    99,    34,     0,    42,   103,    51,     0,
    49,     0,   103,    52,    49,     0,     0,   106,     0,    62,
    72,    51,     0,    50,    71,    51,     0,   105,     0,   106,
   105,     0,    65,     0,   117,     0,   108,     0,   107,    65,
     0,   107,   108,     0,   107,   117,     0,    10,   116,   111,
    51,     0,    10,    19,    24,    20,   111,    51,     0,    10,
   111,    51,     0,    11,   116,   111,    51,     0,    11,    19,
    24,    20,   111,    51,     0,    11,   111,    51,     0,    65,
     0,   119,     0,   110,     0,   109,    65,     0,   109,   119,
     0,   109,   110,     0,    10,   116,   111,    67,    92,     0,
    10,    19,    24,    20,   111,    67,    92,     0,    10,   111,
    67,    92,     0,    11,   116,   111,    67,    92,     0,    11,
    19,    24,    20,   111,    67,    92,     0,    11,   111,    67,
    92,     0,    49,     0,    49,    56,   114,   112,     0,    49,
    56,   114,   112,    52,    76,     0,     0,   113,     0,   115,
     0,   113,   115,     0,   116,    49,     0,    49,     0,    56,
   116,    49,     0,    56,    49,     0,    49,    56,   116,    49,
     0,    49,    56,    49,     0,    19,    62,    20,     0,    19,
    50,    12,    20,     0,    35,   118,    62,    49,    51,     0,
    35,   118,    50,    12,    49,    51,     0,     0,    19,    20,
     0,    19,    36,    20,     0,    19,    37,    20,     0,    38,
    49,    51,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   148,   151,   152,   153,   154,   155,   156,   161,   165,   166,
   167,   168,   172,   173,   176,   177,   178,   182,   183,   186,
   187,   190,   191,   194,   195,   198,   199,   202,   203,   206,
   207,   209,   210,   213,   214,   217,   218,   221,   222,   225,
   226,   229,   230,   235,   236,   237,   238,   239,   240,   241,
   242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
   252,   253,   254,   255,   256,   257,   258,   261,   262,   265,
   266,   269,   270,   273,   274,   275,   276,   277,   280,   281,
   282,   285,   286,   289,   290,   293,   294,   298,   299,   303,
   306,   309,   310,   311,   312,   313,   318,   319,   320,   321,
   322,   323,   324,   325,   326,   329,   332,   333,   336,   337,
   340,   341,   345,   346,   347,   348,   349,   350,   353,   354,
   357,   358,   361,   362,   365,   366,   369,   370,   371,   372,
   373,   374,   377,   380,   381,   384,   385,   388,   389,   392,
   393,   396,   397,   398,   399,   400,   401,   404,   405,   406,
   407,   408,   409,   412,   413,   414,   415,   416,   417,   420,
   421,   422,   423,   424,   425,   428,   429,   430,   433,   434,
   437,   438,   441,   442,   445,   446,   447,   448,   451,   452,
   455,   456,   459,   460,   461,   462,   465
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
"instance_variables_declaration_list_e","instance_variables_declaration","instance_variables_declaration_list",
"interface_declaration_list","method_declaration","implementation_definition_list",
"method_definition","method_selector","keyword_selector_e","keyword_selector",
"keyword_declaration_without_identifier","keyword_declaration","method_type",
"property","attribute","synthesize",""
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
   101,   101,   102,   103,   103,   104,   104,   105,   105,   106,
   106,   107,   107,   107,   107,   107,   107,   108,   108,   108,
   108,   108,   108,   109,   109,   109,   109,   109,   109,   110,
   110,   110,   110,   110,   110,   111,   111,   111,   112,   112,
   113,   113,   114,   114,   115,   115,   115,   115,   116,   116,
   117,   117,   118,   118,   118,   118,   119
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
     4,     1,     0,     1,     4,     1,     4,     6,     4,     6,
     6,     6,     3,     1,     3,     0,     1,     3,     3,     1,
     2,     1,     1,     1,     2,     2,     2,     4,     6,     3,
     4,     6,     3,     1,     1,     1,     2,     2,     2,     5,
     7,     4,     5,     7,     4,     1,     4,     6,     0,     1,
     1,     2,     2,     1,     3,     2,     4,     3,     3,     4,
     5,     6,     0,     2,     3,     3,     3
};

static const short yydefact[] = {     0,
     9,    10,    11,     0,     0,    12,     0,     1,     3,     0,
     2,   111,   112,     4,   119,   119,   123,   123,   134,     0,
     6,     5,     7,     0,     0,     0,   183,    38,     0,   136,
    24,   142,     0,   120,   122,   144,   143,     0,     0,     0,
     0,     0,     0,   136,   154,     0,   124,   126,   156,   155,
     0,     0,   133,     0,     0,     0,   166,     0,     0,     0,
     0,     0,     0,     0,     0,    36,    39,     0,   119,   119,
     0,     0,     0,   140,   137,    28,     0,    25,    26,   114,
   145,   146,   147,   119,   119,   117,     0,    22,     0,     0,
    22,     0,     0,   123,   123,     0,   127,   157,   159,   158,
   123,   123,   129,   135,     0,     0,     0,     0,     0,   150,
     0,     0,   153,     0,   184,     0,     0,     0,     0,    34,
     0,    19,     0,     0,     0,     0,    32,     0,     0,   141,
     0,    18,     0,     0,     0,     0,    20,    23,     0,    22,
     0,     0,    22,   187,     0,     0,     0,     0,     0,   109,
     8,     0,     0,   179,     0,   174,   169,     0,   148,     0,
   151,   185,   186,     0,     0,     0,    37,   113,   115,    30,
   139,     0,   138,     0,   121,     0,     0,     0,    48,    49,
    14,    15,    16,    13,    17,    44,     0,     0,    46,    45,
    29,    27,   116,   118,     0,    21,   162,     0,     0,   165,
     0,   128,   131,   125,   130,   132,     0,     0,     0,     0,
    68,    97,   105,     0,   100,   101,   102,   103,   107,   104,
   110,     0,     0,   180,     0,     0,   167,   170,   171,   173,
     0,     0,   181,    35,     0,    33,    53,    52,     0,    70,
    75,    74,    76,    77,     0,     0,    54,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    22,   160,    22,   163,     0,     0,     0,    68,    69,     0,
    98,   108,   106,   149,     0,   176,     0,     0,   172,   152,
   182,    31,    47,    72,     0,    71,     0,    79,     0,    65,
    59,    60,    62,    61,    63,    64,    55,    56,    57,    58,
    66,    67,     0,     0,     0,     0,     0,    44,     0,    24,
     0,    99,   178,     0,   175,     0,     0,   168,    40,    51,
     0,     0,     0,    50,   161,   164,     0,     0,     0,     0,
    24,     0,    68,   177,     0,    42,     0,    73,    78,    82,
    88,    90,     0,     0,    28,     0,    68,     0,    43,    41,
     0,     0,    80,    83,    84,     0,     0,     0,     0,    68,
     0,    68,     0,    87,     0,    85,    89,    91,    95,     0,
     0,    68,     0,    86,    81,     0,    68,     0,     0,    96,
     0,     0,    92,     0,    93,    94,     0,     0,     0
};

static const short yydefgoto[] = {   387,
     8,     9,    31,   189,   190,   213,   138,   139,    77,    78,
    79,   126,   128,    66,    67,    68,   318,   319,   214,   270,
   285,   286,   246,   289,   353,   354,   355,   215,   216,   217,
   218,   219,   220,   221,   222,    11,    12,    33,    34,    46,
    47,    13,    14,    20,    73,    74,    75,    35,    36,    48,
    49,    58,   227,   228,   157,   229,    59,    37,    64,    50
};

static const short yypact[] = {   275,
-32768,-32768,-32768,    36,    44,-32768,   -42,   275,-32768,   -31,
-32768,-32768,-32768,-32768,   216,   219,   373,   377,-32768,    50,
-32768,-32768,-32768,     7,    -9,    -7,    10,    19,    54,   264,
    -3,-32768,    21,-32768,   211,-32768,-32768,    65,    32,     8,
     9,    28,    73,   264,-32768,    34,-32768,   482,-32768,-32768,
    85,    45,-32768,    42,    61,   117,    52,    69,    67,   336,
    79,    67,    33,   289,    96,-32768,    98,    97,    26,    26,
   141,   120,   110,-32768,   264,   172,   131,   135,-32768,-32768,
-32768,-32768,-32768,    26,    26,-32768,   418,   340,    67,   477,
   340,    67,   149,   381,   381,   146,-32768,-32768,-32768,-32768,
   381,   381,-32768,-32768,   148,   203,   223,   208,    13,-32768,
   180,   225,-32768,   192,-32768,   227,   228,   237,   204,   252,
    19,-32768,   224,   243,   210,   126,-32768,   133,   211,-32768,
   442,-32768,    -3,   248,   250,   269,-32768,   340,   148,   340,
   272,   148,   340,-32768,   261,   265,   482,   268,   281,   325,
-32768,    67,   311,-32768,   387,-32768,    -6,   260,-32768,    67,
-32768,-32768,-32768,   283,   287,   442,-32768,-32768,-32768,-32768,
-32768,   328,-32768,   292,   211,   442,   442,   442,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   323,   241,   442,-32768,-32768,
   620,-32768,-32768,-32768,    67,-32768,-32768,   148,    67,-32768,
   148,-32768,-32768,   482,-32768,-32768,   324,   326,   325,   330,
   442,-32768,-32768,   316,-32768,-32768,-32768,-32768,-32768,-32768,
   325,   294,   299,-32768,   300,    14,   327,    -6,-32768,-32768,
   334,   338,-32768,   620,   344,-32768,   119,   119,   504,   442,
-32768,-32768,-32768,-32768,   241,   348,   119,   442,   442,   442,
   442,   442,   442,   442,   442,   442,   442,   442,   352,   356,
   340,-32768,   340,-32768,   442,   442,   378,   425,   620,   361,
-32768,-32768,-32768,-32768,    16,-32768,   358,   435,-32768,-32768,
-32768,-32768,-32768,   620,   393,   364,   348,   365,   363,   620,
   633,   633,   642,   642,   642,   642,   153,   153,   119,   119,
-32768,-32768,   148,   148,   530,   548,   401,    -8,   412,    -3,
   374,-32768,-32768,   383,-32768,   414,   394,   397,-32768,-32768,
   442,   391,   442,-32768,-32768,-32768,   325,   325,   442,   442,
   402,   399,   442,-32768,   405,-32768,   435,   620,-32768,   207,
   428,-32768,   566,   584,     3,   409,   442,   411,-32768,-32768,
   407,   442,   415,    22,-32768,   325,   426,   325,   442,   442,
   432,   442,   442,   620,   442,-32768,-32768,-32768,-32768,   602,
   433,   442,   459,   620,   364,   325,   442,   474,   325,-32768,
   476,   325,-32768,   325,-32768,-32768,   502,   506,-32768
};

static const short yypgoto[] = {-32768,
-32768,   511,     0,-32768,-32768,     4,-32768,   -89,  -286,-32768,
   392,-32768,-32768,   408,-32768,-32768,-32768,   189,   -59,  -251,
-32768,   163,   285,   244,-32768,-32768,   190,-32768,-32768,-32768,
-32768,  -196,  -101,-32768,-32768,   537,-32768,    43,-32768,    62,
-32768,-32768,   538,-32768,   505,   487,-32768,   434,   -26,   417,
   -45,    84,-32768,-32768,-32768,   339,   -25,   -21,-32768,   -43
};


#define	YYLAST		660


static const short yytable[] = {    10,
    62,   142,    99,   151,   100,   131,    19,    10,    82,    56,
   240,    60,   267,    83,    89,    92,   311,    24,    32,    32,
    45,    45,   330,   332,   272,    55,    87,    90,    63,    72,
    65,   155,   155,   359,   155,    25,    26,   197,    81,    57,
   200,    57,   225,    72,   346,    76,     1,     2,     3,   226,
   198,    98,   115,   201,    80,   108,    57,    57,    39,   108,
    27,   156,   276,   119,   313,    86,     6,    97,   116,   117,
   351,   191,    32,    32,    72,    28,    93,   352,   103,    52,
   105,   348,    30,   158,    15,    16,   108,    32,    32,   108,
   104,   137,    17,    18,   137,   361,   262,    45,    45,   264,
    53,    54,    69,    70,    45,    45,   234,   109,   371,    61,
   373,   123,   124,    84,    85,    57,   237,   238,   239,   110,
   378,    94,    95,    88,    91,   381,   134,   135,   247,   113,
   341,   342,    32,   101,   102,   259,   260,     1,     2,     3,
   106,   196,   111,   137,   120,   114,   137,   122,    82,   121,
    45,   269,   125,    83,   108,   145,   146,     6,    99,   367,
   100,   369,   148,   149,   257,   258,   107,   129,   127,   259,
   260,   303,   140,   304,   131,   143,   171,   172,    81,   380,
   284,   132,   383,   173,   174,   385,   133,   386,   290,   291,
   292,   293,   294,   295,   296,   297,   298,   299,   300,   144,
   277,   325,   326,   147,   150,   305,   306,    98,   269,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
    25,    26,   152,   259,   260,    25,    26,   154,    25,    26,
   159,     1,     2,     3,   153,   223,     1,     2,     3,     1,
     2,     3,   161,   231,   160,    27,   162,   163,   164,   314,
    27,     6,   165,    27,   166,   351,     6,   168,   170,     6,
    28,   338,   352,   340,   137,    28,   137,   310,    28,   343,
   344,    29,    30,   269,    38,    30,   169,   317,   261,   241,
   242,   193,   263,   194,     1,     2,     3,   269,   195,   243,
   244,   199,   364,   245,   202,     1,     2,     3,   203,   370,
   269,   205,   269,   374,     6,   284,     4,     5,   230,     1,
     2,     3,   269,    71,   206,     6,     7,   269,   248,   249,
   250,   251,   252,   253,   254,   255,   256,   257,   258,     6,
   224,   232,   259,   260,   176,   177,   317,   233,   118,   235,
   236,   240,   265,   178,   266,     1,     2,     3,   268,   274,
   207,   273,   208,   209,   210,   275,     1,     2,     3,   112,
     1,     2,     3,   179,   180,     6,   271,   211,   181,   182,
   183,   184,   185,   186,    28,   212,     6,   187,   278,   188,
     6,   150,    40,    41,   280,   107,    40,    41,   281,    28,
    40,    41,   282,     1,     2,     3,   288,     1,     2,     3,
   301,     1,     2,     3,   302,   307,   315,     1,     2,     3,
    42,   312,   320,     6,    42,   321,   324,     6,    42,   329,
   323,     6,    28,   331,   333,   335,    28,     6,    43,    44,
    28,   334,    51,    44,   176,   177,   107,    44,     1,     2,
     3,   136,   336,   178,   339,     1,     2,     3,   337,   347,
   345,   176,   177,   349,   356,     1,     2,     3,     6,   360,
   178,   362,   363,   179,   180,     6,   365,   107,   181,   182,
   183,   184,   185,   308,   309,     6,   368,   187,   379,   188,
   179,   180,   372,   377,   316,   181,   182,   183,   184,   185,
   186,    40,    41,   382,   187,   384,   188,     1,     2,     3,
   141,   388,     1,     2,     3,   389,   248,   249,   250,   251,
   252,   253,   254,   255,   256,   257,   258,     6,    21,    42,
   259,   260,     6,   283,   192,   350,   107,   375,   167,   287,
   322,    28,   248,   249,   250,   251,   252,   253,   254,   255,
   256,   257,   258,   366,    22,    23,   259,   260,    96,   327,
   248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
   258,   130,   175,   204,   259,   260,   279,   328,   248,   249,
   250,   251,   252,   253,   254,   255,   256,   257,   258,     0,
     0,     0,   259,   260,     0,   357,   248,   249,   250,   251,
   252,   253,   254,   255,   256,   257,   258,     0,     0,     0,
   259,   260,     0,   358,   248,   249,   250,   251,   252,   253,
   254,   255,   256,   257,   258,     0,     0,     0,   259,   260,
     0,   376,   248,   249,   250,   251,   252,   253,   254,   255,
   256,   257,   258,     0,     0,     0,   259,   260,   251,   252,
   253,   254,   255,   256,   257,   258,     0,     0,     0,   259,
   260,   255,   256,   257,   258,     0,     0,     0,   259,   260
};

static const short yycheck[] = {     0,
    26,    91,    48,   105,    48,     3,    49,     8,    35,    19,
    19,    19,   209,    35,    40,    41,   268,    49,    15,    16,
    17,    18,    31,   310,   221,    19,    19,    19,    19,    30,
    12,    19,    19,    31,    19,    10,    11,   139,    35,    49,
   142,    49,    49,    44,   331,    49,    21,    22,    23,    56,
   140,    48,    20,   143,    34,    56,    49,    49,    16,    60,
    35,    49,    49,    64,    49,    34,    41,    34,    36,    37,
    49,   131,    69,    70,    75,    50,    49,    56,    34,    18,
    20,   333,    57,   109,    49,    50,    87,    84,    85,    90,
    49,    88,    49,    50,    91,   347,   198,    94,    95,   201,
    51,    52,    49,    50,   101,   102,   166,    56,   360,    26,
   362,    69,    70,    49,    50,    49,   176,   177,   178,    51,
   372,    49,    50,    40,    41,   377,    84,    85,   188,    51,
   327,   328,   129,    49,    50,    17,    18,    21,    22,    23,
    24,   138,    59,   140,    49,    62,   143,    51,   175,    52,
   147,   211,    12,   175,   155,    94,    95,    41,   204,   356,
   204,   358,   101,   102,    12,    13,    50,    58,    49,    17,
    18,   261,    89,   263,     3,    92,    51,    52,   175,   376,
   240,    51,   379,    51,    52,   382,    52,   384,   248,   249,
   250,   251,   252,   253,   254,   255,   256,   257,   258,    51,
   226,   303,   304,    58,    57,   265,   266,   204,   268,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
    10,    11,    20,    17,    18,    10,    11,    20,    10,    11,
    51,    21,    22,    23,    12,   152,    21,    22,    23,    21,
    22,    23,    51,   160,    20,    35,    20,    20,    12,   275,
    35,    41,    49,    35,     3,    49,    41,    34,    49,    41,
    50,   321,    56,   323,   261,    50,   263,   268,    50,   329,
   330,    56,    57,   333,    56,    57,    34,   278,   195,    39,
    40,    34,   199,    34,    21,    22,    23,   347,    20,    49,
    50,    20,   352,    53,    34,    21,    22,    23,    34,   359,
   360,    34,   362,   363,    41,   365,    32,    33,    49,    21,
    22,    23,   372,    50,    34,    41,    42,   377,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    41,
    20,    49,    17,    18,    10,    11,   337,    51,    50,    12,
    49,    19,    19,    19,    19,    21,    22,    23,    19,    51,
    26,    58,    28,    29,    30,    56,    21,    22,    23,    24,
    21,    22,    23,    39,    40,    41,    51,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    41,    53,    52,    55,
    41,    57,    10,    11,    51,    50,    10,    11,    51,    50,
    10,    11,    49,    21,    22,    23,    49,    21,    22,    23,
    49,    21,    22,    23,    49,    28,    49,    21,    22,    23,
    38,    51,    20,    41,    38,    52,    54,    41,    38,    19,
    56,    41,    50,    12,    51,    12,    50,    41,    56,    57,
    50,    49,    56,    57,    10,    11,    50,    57,    21,    22,
    23,    24,    49,    19,    54,    21,    22,    23,    52,    51,
    49,    10,    11,    49,    27,    21,    22,    23,    41,    51,
    19,    51,    56,    39,    40,    41,    52,    50,    44,    45,
    46,    47,    48,    49,    50,    41,    51,    53,    20,    55,
    39,    40,    51,    51,    50,    44,    45,    46,    47,    48,
    49,    10,    11,    20,    53,    20,    55,    21,    22,    23,
    24,     0,    21,    22,    23,     0,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    41,     8,    38,
    17,    18,    41,    20,   133,   337,    50,   365,   121,   245,
   287,    50,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,   354,     8,     8,    17,    18,    44,    20,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    75,   129,   147,    17,    18,   228,    20,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
    -1,    -1,    17,    18,    -1,    20,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
    17,    18,    -1,    20,     3,     4,     5,     6,     7,     8,
     9,    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,
    -1,    20,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    -1,    -1,    -1,    17,    18,     6,     7,
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
{yyval.Program = root = Program_node::createProgramNode(yyvsp[0].Function_and_class_list);;
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
#line 165 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(INT_TYPE);;
    break;}
case 10:
#line 166 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(CHAR_TYPE);;
    break;}
case 11:
#line 167 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(FLOAT_TYPE);;
    break;}
case 12:
#line 168 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(ID_TYPE);;
    break;}
case 13:
#line 172 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromFloat(yyvsp[0].Float_constant);;
    break;}
case 14:
#line 173 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromInteger(yyvsp[0].Integer_constant);;
    break;}
case 15:
#line 176 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(STRING_CONSTANT_TYPE, yyvsp[0].String_constant);;
    break;}
case 16:
#line 177 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(CHAR_CONSTANT_TYPE, yyvsp[0].Char_constant);;
    break;}
case 17:
#line 178 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(NSSTRING_CONSTANT_TYPE, yyvsp[0].NSString_constant);;
    break;}
case 18:
#line 182 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Init_declarator_list);;
    break;}
case 19:
#line 183 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Init_declarator_list);
    break;}
case 20:
#line 186 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::createDeclarationListNode(yyvsp[0].Declaration);;
    break;}
case 21:
#line 187 "bison_rules_with_code.y"
{yyval.Declaration_list = Declaration_list_node::addToDeclarationListNode(yyvsp[-1].Declaration_list, yyvsp[0].Declaration);;
    break;}
case 22:
#line 190 "bison_rules_with_code.y"
{yyval.Declaration_list = NULL;;
    break;}
case 23:
#line 191 "bison_rules_with_code.y"
{yyval.Declaration_list = yyvsp[0].Declaration_list;;
    break;}
case 24:
#line 194 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 25:
#line 195 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 26:
#line 198 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 27:
#line 199 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 28:
#line 202 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Identifier, NULL);;
    break;}
case 29:
#line 203 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 30:
#line 206 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Identifier);;
    break;}
case 31:
#line 207 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-3].Declarator_list, yyvsp[0].Identifier);;
    break;}
case 32:
#line 209 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Identifier);;
    break;}
case 33:
#line 210 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-2].Declarator_list,yyvsp[0].Identifier);;
    break;}
case 34:
#line 213 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Identifier, NULL);;
    break;}
case 35:
#line 214 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 36:
#line 217 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 37:
#line 218 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 38:
#line 221 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 39:
#line 222 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 40:
#line 225 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::createParameterListNode(yyvsp[0].Parameter_declaration);;
    break;}
case 41:
#line 226 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::addToParameterListNode(yyvsp[-2].Parameter_list, yyvsp[0].Parameter_declaration);;
    break;}
case 42:
#line 229 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(yyvsp[-1].Type, yyvsp[0].Identifier);;
    break;}
case 43:
#line 230 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier),yyvsp[0].Identifier);;
    break;}
case 44:
#line 235 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromIdentifier(yyvsp[0].Identifier);;
    break;}
case 45:
#line 236 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromLiteral(yyvsp[0].Literal);;
    break;}
case 46:
#line 237 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromNumericConstant(yyvsp[0].Numeric_constant);;
    break;}
case 47:
#line 238 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSimpleExpression(PRIORITY_EXPRESSION_TYPE, yyvsp[-1].Expression);;
    break;}
case 48:
#line 239 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSelf();;
    break;}
case 49:
#line 240 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSuper();;
    break;}
case 50:
#line 241 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 51:
#line 242 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromFunctionCall(yyvsp[-3].Identifier, yyvsp[-1].Expression_list);;
    break;}
case 52:
#line 243 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UMINUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 53:
#line 244 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UPLUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 54:
#line 245 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UAMPERSAND_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 55:
#line 246 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(PLUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 56:
#line 247 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MINUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 57:
#line 248 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MUL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 58:
#line 249 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(DIV_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 59:
#line 250 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 60:
#line 251 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(NOT_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 61:
#line 252 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 62:
#line 253 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 63:
#line 254 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 64:
#line 255 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 65:
#line 256 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(ASSIGNMENT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 66:
#line 257 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMemberAccessOperator(DOT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Identifier);;
    break;}
case 67:
#line 258 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMemberAccessOperator(ARROW_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Identifier);;
    break;}
case 68:
#line 261 "bison_rules_with_code.y"
{yyval.Expression = NULL;;
    break;}
case 69:
#line 262 "bison_rules_with_code.y"
{yyval.Expression = yyvsp[0].Expression;;
    break;}
case 70:
#line 265 "bison_rules_with_code.y"
{yyval.Expression_list = NULL;;
    break;}
case 71:
#line 266 "bison_rules_with_code.y"
{yyval.Expression_list = yyvsp[0].Expression_list;;
    break;}
case 72:
#line 269 "bison_rules_with_code.y"
{yyval.Expression_list = Expression_list_node::createExpressionListNode(yyvsp[0].Expression);;
    break;}
case 73:
#line 270 "bison_rules_with_code.y"
{yyval.Expression_list = Expression_list_node::addToExpressionListNode(yyvsp[-2].Expression_list, yyvsp[0].Expression);;
    break;}
case 74:
#line 273 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);;
    break;}
case 75:
#line 274 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);;
    break;}
case 76:
#line 275 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(OBJECT_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 77:
#line 276 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(CLASS_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 78:
#line 277 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 79:
#line 280 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 80:
#line 281 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Expression, yyvsp[0].Keyword_argument_list, NULL);;
    break;}
case 81:
#line 282 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Expression, yyvsp[-2].Keyword_argument_list, yyvsp[0].Expression_list);;
    break;}
case 82:
#line 285 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = NULL;;
    break;}
case 83:
#line 286 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = yyvsp[0].Keyword_argument_list;;
    break;}
case 84:
#line 289 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::createKeywordArgumentListNode(yyvsp[0].Keyword_argument);;
    break;}
case 85:
#line 290 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::addToKeywordArgumentListNode(yyvsp[-1].Keyword_argument_list, yyvsp[0].Keyword_argument);;
    break;}
case 86:
#line 293 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITH_IDENTIFIER_KW_ARGUMENT_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 87:
#line 294 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 88:
#line 298 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITHOUT_ALTERNATIVE_IF_TYPE, yyvsp[-2].Expression, yyvsp[0].Statement, NULL);;
    break;}
case 89:
#line 299 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITH_ALTERNATIVE_IF_TYPE, yyvsp[-4].Expression, yyvsp[-2].Statement, yyvsp[0].Statement);;
    break;}
case 90:
#line 303 "bison_rules_with_code.y"
{yyval.While  = While_statement_node::createWhileStatementNode(yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 91:
#line 306 "bison_rules_with_code.y"
{yyval.Do_while = Do_while_statement_node::createDoWhileStatementNode(yyvsp[-2].Expression, yyvsp[-5].Statement);;
    break;}
case 92:
#line 309 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNode(yyvsp[-6].Expression, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 93:
#line 310 "bison_rules_with_code.y"
{yyval.For =For_statement_node::createForStatementNodeFromForWithDeclaration(yyvsp[-7].Type, yyvsp[-6].Init_declarator_list, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 94:
#line 311 "bison_rules_with_code.y"
{yyval.For =For_statement_node::createForStatementNodeFromForWithDeclaration(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-8].Identifier), yyvsp[-6].Init_declarator_list, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 95:
#line 312 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 96:
#line 313 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-6].Identifier), yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 97:
#line 318 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);;
    break;}
case 98:
#line 319 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 99:
#line 320 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 100:
#line 321 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].If;;
    break;}
case 101:
#line 322 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].While;;
    break;}
case 102:
#line 323 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].Do_while;;
    break;}
case 103:
#line 324 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].For;;
    break;}
case 104:
#line 325 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].Compound_statement;;
    break;}
case 105:
#line 326 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].Declaration;;
    break;}
case 106:
#line 329 "bison_rules_with_code.y"
{yyval.Compound_statement = Compound_statement_node::createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 107:
#line 332 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::createStatementListNode(yyvsp[0].Statement);;
    break;}
case 108:
#line 333 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::addToStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 109:
#line 336 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 110:
#line 337 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 111:
#line 340 "bison_rules_with_code.y"
{yyval.Class_block = yyvsp[0].Class_interface;;
    break;}
case 112:
#line 341 "bison_rules_with_code.y"
{yyval.Class_block = yyvsp[0].Class_implementation;;
    break;}
case 113:
#line 345 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 114:
#line 346 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 115:
#line 347 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 116:
#line 348 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 117:
#line 349 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 118:
#line 350 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 119:
#line 353 "bison_rules_with_code.y"
{yyval.Interface_body = NULL;;
    break;}
case 120:
#line 354 "bison_rules_with_code.y"
{yyval.Interface_body = yyvsp[0].Interface_body;;
    break;}
case 121:
#line 357 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(yyvsp[-2].Instance_variables_declaration_list, yyvsp[0].Interface_declaration_list);;
    break;}
case 122:
#line 358 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 123:
#line 361 "bison_rules_with_code.y"
{yyval.Implementation_body = NULL;;
    break;}
case 124:
#line 362 "bison_rules_with_code.y"
{yyval.Implementation_body = yyvsp[0].Implementation_body;;
    break;}
case 125:
#line 365 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(yyvsp[-2].Instance_variables_declaration_list, yyvsp[0].Implementation_definition_list);;
    break;}
case 126:
#line 366 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 127:
#line 369 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 128:
#line 370 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 129:
#line 371 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 130:
#line 372 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 131:
#line 373 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 132:
#line 374 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 133:
#line 377 "bison_rules_with_code.y"
{yyval.Class_declaration_list = Class_declaration_list_node::createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 134:
#line 380 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::createClassListNode(yyvsp[0].Identifier);;
    break;}
case 135:
#line 381 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::addToClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 136:
#line 384 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = NULL;;
    break;}
case 137:
#line 385 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = yyvsp[0].Instance_variables_declaration_list;;
    break;}
case 138:
#line 388 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Declarator_list);;
    break;}
case 139:
#line 389 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Declarator_list);;
    break;}
case 140:
#line 392 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::createInstanceVariablesDeclarationListNode(yyvsp[0].Instance_variables_declaration);;
    break;}
case 141:
#line 393 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::addToInstanceVariablesDeclarationListNode(yyvsp[-1].Instance_variables_declaration_list, yyvsp[0].Instance_variables_declaration);;
    break;}
case 142:
#line 396 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 143:
#line 397 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 144:
#line 398 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(yyvsp[0].Method_declaration);;
    break;}
case 145:
#line 399 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 146:
#line 400 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 147:
#line 401 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 148:
#line 404 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 149:
#line 405 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 150:
#line 406 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 151:
#line 407 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 152:
#line 408 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 153:
#line 409 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 154:
#line 412 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 155:
#line 413 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromSynthesize(yyvsp[0].Synthesize);;
    break;}
case 156:
#line 414 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(yyvsp[0].Method_definition);;
    break;}
case 157:
#line 415 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 158:
#line 416 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addSynthesizeToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Synthesize);;
    break;}
case 159:
#line 417 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 160:
#line 420 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 161:
#line 421 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 162:
#line 422 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 163:
#line 423 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 164:
#line 424 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 165:
#line 425 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 166:
#line 428 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 167:
#line 429 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Keyword_declaration, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 168:
#line 430 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Keyword_declaration, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_list);;
    break;}
case 169:
#line 433 "bison_rules_with_code.y"
{yyval.Keyword_selector = NULL;;
    break;}
case 170:
#line 434 "bison_rules_with_code.y"
{yyval.Keyword_selector = yyvsp[0].Keyword_selector;;
    break;}
case 171:
#line 437 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 172:
#line 438 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::addToKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 173:
#line 441 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 174:
#line 442 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 175:
#line 445 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 176:
#line 446 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 177:
#line 447 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 178:
#line 448 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 179:
#line 451 "bison_rules_with_code.y"
{yyval.Type = yyvsp[-1].Type;;
    break;}
case 180:
#line 452 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier);;
    break;}
case 181:
#line 455 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-3].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 182:
#line 456 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 183:
#line 459 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(EMPTY_ATTRIBUTE_TYPE);;
    break;}
case 184:
#line 460 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(EMPTY_ATTRIBUTE_TYPE);;
    break;}
case 185:
#line 461 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 186:
#line 462 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READWRITE_ATTRIBUTE_TYPE);;
    break;}
case 187:
#line 465 "bison_rules_with_code.y"
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
#line 468 "bison_rules_with_code.y"


void yyerror(char const *s)
{
	printf("%s",s);
}
