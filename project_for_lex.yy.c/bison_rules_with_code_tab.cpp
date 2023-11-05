
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



#define	YYFINAL		390
#define	YYFLAG		-32768
#define	YYNTBASE	59

#define YYTRANSLATE(x) ((unsigned)(x) <= 295 ? yytranslate[x] : 119)

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
   524,   529,   536,   540,   542,   546,   548,   551,   556,   559,
   565,   573,   578,   584,   592,   597,   599,   604,   611,   612,
   614,   616,   619,   622,   624,   628,   631,   636,   640,   644,
   649,   655,   662,   663,   666,   670
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
     0,    38,    49,    51,     0,   110,     0,   109,    65,     0,
   109,    38,    49,    51,     0,   109,   110,     0,    10,   116,
   111,    67,    92,     0,    10,    19,    24,    20,   111,    67,
    92,     0,    10,   111,    67,    92,     0,    11,   116,   111,
    67,    92,     0,    11,    19,    24,    20,   111,    67,    92,
     0,    11,   111,    67,    92,     0,    49,     0,    49,    56,
   114,   112,     0,    49,    56,   114,   112,    52,    76,     0,
     0,   113,     0,   115,     0,   113,   115,     0,   116,    49,
     0,    49,     0,    56,   116,    49,     0,    56,    49,     0,
    49,    56,   116,    49,     0,    49,    56,    49,     0,    19,
    62,    20,     0,    19,    50,    12,    20,     0,    35,   118,
    62,    49,    51,     0,    35,   118,    50,    12,    49,    51,
     0,     0,    19,    20,     0,    19,    36,    20,     0,    19,
    37,    20,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   146,   149,   150,   151,   152,   153,   154,   159,   163,   164,
   165,   166,   170,   171,   174,   175,   176,   180,   181,   184,
   185,   188,   189,   192,   193,   196,   197,   200,   201,   204,
   205,   207,   208,   211,   212,   215,   216,   219,   220,   223,
   224,   227,   228,   233,   234,   235,   236,   237,   238,   239,
   240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
   250,   251,   252,   253,   254,   255,   256,   259,   260,   263,
   264,   267,   268,   271,   272,   273,   274,   275,   278,   279,
   280,   283,   284,   287,   288,   291,   292,   296,   297,   301,
   304,   307,   308,   309,   310,   311,   316,   317,   318,   319,
   320,   321,   322,   323,   324,   327,   330,   331,   334,   335,
   338,   339,   343,   344,   345,   346,   347,   348,   351,   352,
   355,   356,   359,   360,   363,   364,   367,   368,   369,   370,
   371,   372,   375,   378,   379,   382,   383,   386,   387,   390,
   391,   394,   395,   396,   397,   398,   399,   402,   403,   404,
   405,   406,   407,   410,   411,   412,   413,   414,   415,   418,
   419,   420,   421,   422,   423,   426,   427,   428,   431,   432,
   435,   436,   439,   440,   443,   444,   445,   446,   449,   450,
   453,   454,   457,   458,   459,   460
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
"property","attribute",""
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
   117,   117,   118,   118,   118,   118
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
     4,     6,     3,     1,     3,     1,     2,     4,     2,     5,
     7,     4,     5,     7,     4,     1,     4,     6,     0,     1,
     1,     2,     2,     1,     3,     2,     4,     3,     3,     4,
     5,     6,     0,     2,     3,     3
};

static const short yydefact[] = {     0,
     9,    10,    11,     0,     0,    12,     0,     1,     3,     0,
     2,   111,   112,     4,   119,   119,   123,   123,   134,     0,
     6,     5,     7,     0,     0,     0,   183,    38,     0,   136,
    24,   142,     0,   120,   122,   144,   143,     0,     0,     0,
     0,     0,     0,   136,   154,     0,   124,   126,   156,     0,
     0,   133,     0,     0,     0,   166,     0,     0,     0,     0,
     0,     0,     0,     0,    36,    39,     0,   119,   119,     0,
     0,     0,   140,   137,    28,     0,    25,    26,   114,   145,
   146,   147,   119,   119,   117,     0,    22,     0,     0,    22,
     0,     0,   123,   123,     0,   127,     0,   157,   159,   123,
   123,   129,   135,     0,     0,     0,     0,     0,   150,     0,
     0,   153,     0,   184,     0,     0,     0,     0,    34,     0,
    19,     0,     0,     0,     0,    32,     0,     0,   141,     0,
    18,     0,     0,     0,     0,    20,    23,     0,    22,     0,
     0,    22,   155,     0,     0,     0,     0,     0,     0,   109,
     8,     0,     0,   179,     0,   174,   169,     0,   148,     0,
   151,   185,   186,     0,     0,     0,    37,   113,   115,    30,
   139,     0,   138,     0,   121,     0,     0,     0,    48,    49,
    14,    15,    16,    13,    17,    44,     0,     0,    46,    45,
    29,    27,   116,   118,     0,    21,   162,     0,     0,   165,
     0,   128,   131,   125,   158,   130,   132,     0,     0,     0,
     0,    68,    97,   105,     0,   100,   101,   102,   103,   107,
   104,   110,     0,     0,   180,     0,     0,   167,   170,   171,
   173,     0,     0,   181,    35,     0,    33,    53,    52,     0,
    70,    75,    74,    76,    77,     0,     0,    54,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    22,   160,    22,   163,     0,     0,     0,    68,    69,
     0,    98,   108,   106,   149,     0,   176,     0,     0,   172,
   152,   182,    31,    47,    72,     0,    71,     0,    79,     0,
    65,    59,    60,    62,    61,    63,    64,    55,    56,    57,
    58,    66,    67,     0,     0,     0,     0,     0,    44,     0,
    24,     0,    99,   178,     0,   175,     0,     0,   168,    40,
    51,     0,     0,     0,    50,   161,   164,     0,     0,     0,
     0,    24,     0,    68,   177,     0,    42,     0,    73,    78,
    82,    88,    90,     0,     0,    28,     0,    68,     0,    43,
    41,     0,     0,    80,    83,    84,     0,     0,     0,     0,
    68,     0,    68,     0,    87,     0,    85,    89,    91,    95,
     0,     0,    68,     0,    86,    81,     0,    68,     0,     0,
    96,     0,     0,    92,     0,    93,    94,     0,     0,     0
};

static const short yydefgoto[] = {   388,
     8,     9,    31,   189,   190,   214,   137,   138,    76,    77,
    78,   125,   127,    65,    66,    67,   319,   320,   215,   271,
   286,   287,   247,   290,   354,   355,   356,   216,   217,   218,
   219,   220,   221,   222,   223,    11,    12,    33,    34,    46,
    47,    13,    14,    20,    72,    73,    74,    35,    36,    48,
    49,    57,   228,   229,   157,   230,    58,    37,    63
};

static const short yypact[] = {   543,
-32768,-32768,-32768,    30,    32,-32768,   -37,   543,-32768,   -26,
-32768,-32768,-32768,-32768,   334,   337,   342,   385,-32768,    33,
-32768,-32768,-32768,    48,   -13,    -9,    71,    17,    43,    10,
   -22,-32768,    65,-32768,   490,-32768,-32768,    46,    69,    -8,
    -1,    66,    74,    10,-32768,    85,-32768,   496,-32768,    76,
   104,-32768,    81,   122,   236,    92,   105,   109,   299,   117,
   109,    29,    90,   114,-32768,   128,   134,   390,   390,   161,
   137,   130,-32768,    10,   197,   150,   151,-32768,-32768,-32768,
-32768,-32768,   390,   390,-32768,   500,   112,   109,   506,   112,
   109,   153,   407,   407,   147,-32768,   162,-32768,-32768,   407,
   407,-32768,-32768,   155,   190,   203,   196,     5,-32768,   166,
   198,-32768,   179,-32768,   211,   212,   234,   204,   244,    17,
-32768,   218,   220,   206,   113,-32768,   115,   490,-32768,   450,
-32768,   -22,   227,   229,   247,-32768,   112,   155,   112,   253,
   155,   112,-32768,   241,   242,   522,   230,   246,   248,   286,
-32768,   109,   258,-32768,   530,-32768,    19,   235,-32768,   109,
-32768,-32768,-32768,   238,   239,   450,-32768,-32768,-32768,-32768,
-32768,   273,-32768,   240,   490,   450,   450,   450,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   275,   121,   450,-32768,-32768,
   692,-32768,-32768,-32768,   109,-32768,-32768,   155,   109,-32768,
   155,-32768,-32768,   496,-32768,-32768,-32768,   279,   280,   286,
   283,   450,-32768,-32768,   232,-32768,-32768,-32768,-32768,-32768,
-32768,   286,   252,   260,-32768,   261,     9,   267,    19,-32768,
-32768,   277,   291,-32768,   692,   243,-32768,   165,   165,   584,
   450,-32768,-32768,-32768,-32768,   121,   297,   165,   450,   450,
   450,   450,   450,   450,   450,   450,   450,   450,   450,   301,
   302,   112,-32768,   112,-32768,   450,   450,   296,   433,   692,
   303,-32768,-32768,-32768,-32768,    15,-32768,   312,   536,-32768,
-32768,-32768,-32768,-32768,   692,   346,   310,   297,   311,   314,
   692,   705,   705,   392,   392,   392,   392,    25,    25,   165,
   165,-32768,-32768,   155,   155,   602,   620,   351,    38,   359,
   -22,   322,-32768,-32768,   325,-32768,   364,   328,   327,-32768,
-32768,   450,   331,   450,-32768,-32768,-32768,   286,   286,   450,
   450,   332,   335,   450,-32768,   333,-32768,   536,   692,-32768,
   216,   361,-32768,   638,   656,    14,   338,   450,   363,-32768,
-32768,   341,   450,   367,    22,-32768,   286,   365,   286,   450,
   450,   369,   450,   450,   692,   450,-32768,-32768,-32768,-32768,
   674,   370,   450,   395,   692,   310,   286,   450,   402,   286,
-32768,   404,   286,-32768,   286,-32768,-32768,   427,   432,-32768
};

static const short yypgoto[] = {-32768,
-32768,   425,     0,-32768,-32768,     4,-32768,   -86,  -286,-32768,
   304,-32768,-32768,   317,-32768,-32768,-32768,   100,   -60,  -234,
-32768,    68,   193,   158,-32768,-32768,    94,-32768,-32768,-32768,
-32768,  -208,   -91,-32768,-32768,   442,-32768,    -7,-32768,     8,
-32768,-32768,   443,-32768,   409,   384,-32768,   339,   -30,   313,
   -45,    96,-32768,-32768,-32768,   233,   -25,   -28,-32768
};


#define	YYLAST		723


static const short yytable[] = {    10,
    61,   268,    99,   141,    81,    55,    82,    10,    39,    59,
    86,    19,   151,   273,    88,    91,   130,    89,    32,    32,
    45,    45,    24,   155,   333,    51,    75,   155,    64,    71,
     1,     2,     3,   155,   312,    56,   258,   259,    80,    56,
    56,   260,   261,    71,   360,   347,   197,    56,   114,   200,
     6,    98,   198,   156,   107,   201,   241,   277,   107,    70,
   122,   123,   118,   314,   115,   116,    54,   226,   331,   191,
   352,    32,    32,    71,   227,   133,   134,   353,    15,    16,
    17,    18,   158,    52,    53,   107,    32,    32,   107,    62,
   136,    68,    69,   136,    83,    84,    45,    45,    79,   349,
   144,   145,    85,    45,    45,   235,   263,   148,   149,   265,
     1,     2,     3,   362,    92,   238,   239,   240,    96,   342,
   343,    60,    93,    94,   100,   101,   372,   248,   374,   103,
     6,    32,     1,     2,     3,    87,    90,   102,   379,   117,
   196,   104,   136,   382,    81,   136,    82,   108,   368,    45,
   370,   270,     6,   110,   107,   109,   113,    56,    99,   242,
   243,    28,   119,   171,   172,   173,   174,   112,   381,   244,
   245,   384,   124,   246,   386,   304,   387,   305,    80,   120,
   285,   260,   261,   139,   121,   126,   142,   128,   291,   292,
   293,   294,   295,   296,   297,   298,   299,   300,   301,   130,
   131,   278,   132,   143,   146,   306,   307,    98,   270,   152,
   147,   150,   326,   327,   153,   154,   159,   160,   249,   250,
   251,   252,   253,   254,   255,   256,   257,   258,   259,   161,
   162,   163,   260,   261,   249,   250,   251,   252,   253,   254,
   255,   256,   257,   258,   259,   164,   166,   224,   260,   261,
   315,   168,   165,   169,   170,   232,     1,     2,     3,   105,
   193,   339,   194,   341,   352,   136,   195,   136,   311,   344,
   345,   353,   199,   270,   202,   203,     6,   225,   318,   206,
   205,   207,   272,   231,   236,   106,   233,   270,   237,   234,
   262,   283,   365,   241,   264,   176,   177,   266,   267,   371,
   270,   269,   270,   375,   178,   285,     1,     2,     3,   274,
   275,   208,   270,   209,   210,   211,   276,   270,   279,     1,
     2,     3,   111,   308,   179,   180,     6,   281,   212,   181,
   182,   183,   184,   185,   186,    28,   213,   318,   187,     6,
   188,   282,   150,    25,    26,   289,    25,    26,   106,   302,
   303,    40,    41,   313,     1,     2,     3,     1,     2,     3,
   316,   322,     1,     2,     3,   321,   324,   325,    27,   330,
   332,    27,   334,   335,     6,   336,   337,     6,   338,    42,
   346,   350,     6,    28,   340,   348,    28,   357,   361,    29,
    30,    28,    38,    30,    40,    41,   364,    43,    44,    25,
    26,   256,   257,   258,   259,     1,     2,     3,   260,   261,
     1,     2,     3,   363,   380,   369,    40,    41,   366,   373,
   378,   383,    42,   385,    27,     6,   389,     1,     2,     3,
     6,   390,    21,   376,    28,   192,   167,   351,   288,    28,
    50,    44,   176,   177,    42,   323,    30,     6,   367,    22,
    23,   178,    95,     1,     2,     3,    28,   129,   204,   176,
   177,   280,     0,    44,     0,     0,   175,     0,   178,     0,
     0,   179,   180,     6,     0,     0,   181,   182,   183,   184,
   185,   309,   310,     0,     0,   187,     0,   188,   179,   180,
     0,     0,     0,   181,   182,   183,   184,   185,   186,    25,
    26,     0,   187,     0,   188,    40,    41,     0,     0,     0,
     1,     2,     3,     0,     0,     0,     1,     2,     3,     0,
     1,     2,     3,   135,    27,     0,     1,     2,     3,   140,
     6,    40,    41,    97,     0,     0,     6,     0,     0,    28,
     6,     0,     1,     2,     3,    28,     6,     0,     0,   106,
     1,     2,     3,     0,     0,   106,     1,     2,     3,    42,
     0,     0,     6,     1,     2,     3,     0,     0,     0,     0,
     6,    28,     0,     0,     4,     5,     6,     0,     0,   106,
     0,     0,     0,     6,     7,   317,   249,   250,   251,   252,
   253,   254,   255,   256,   257,   258,   259,     0,     0,     0,
   260,   261,     0,   284,   249,   250,   251,   252,   253,   254,
   255,   256,   257,   258,   259,     0,     0,     0,   260,   261,
     0,   328,   249,   250,   251,   252,   253,   254,   255,   256,
   257,   258,   259,     0,     0,     0,   260,   261,     0,   329,
   249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
   259,     0,     0,     0,   260,   261,     0,   358,   249,   250,
   251,   252,   253,   254,   255,   256,   257,   258,   259,     0,
     0,     0,   260,   261,     0,   359,   249,   250,   251,   252,
   253,   254,   255,   256,   257,   258,   259,     0,     0,     0,
   260,   261,     0,   377,   249,   250,   251,   252,   253,   254,
   255,   256,   257,   258,   259,     0,     0,     0,   260,   261,
   252,   253,   254,   255,   256,   257,   258,   259,     0,     0,
     0,   260,   261
};

static const short yycheck[] = {     0,
    26,   210,    48,    90,    35,    19,    35,     8,    16,    19,
    19,    49,   104,   222,    40,    41,     3,    19,    15,    16,
    17,    18,    49,    19,   311,    18,    49,    19,    12,    30,
    21,    22,    23,    19,   269,    49,    12,    13,    35,    49,
    49,    17,    18,    44,    31,   332,   138,    49,    20,   141,
    41,    48,   139,    49,    55,   142,    19,    49,    59,    50,
    68,    69,    63,    49,    36,    37,    19,    49,    31,   130,
    49,    68,    69,    74,    56,    83,    84,    56,    49,    50,
    49,    50,   108,    51,    52,    86,    83,    84,    89,    19,
    87,    49,    50,    90,    49,    50,    93,    94,    34,   334,
    93,    94,    34,   100,   101,   166,   198,   100,   101,   201,
    21,    22,    23,   348,    49,   176,   177,   178,    34,   328,
   329,    26,    49,    50,    49,    50,   361,   188,   363,    49,
    41,   128,    21,    22,    23,    40,    41,    34,   373,    50,
   137,    20,   139,   378,   175,   142,   175,    56,   357,   146,
   359,   212,    41,    58,   155,    51,    61,    49,   204,    39,
    40,    50,    49,    51,    52,    51,    52,    51,   377,    49,
    50,   380,    12,    53,   383,   262,   385,   264,   175,    52,
   241,    17,    18,    88,    51,    49,    91,    58,   249,   250,
   251,   252,   253,   254,   255,   256,   257,   258,   259,     3,
    51,   227,    52,    51,    58,   266,   267,   204,   269,    20,
    49,    57,   304,   305,    12,    20,    51,    20,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    51,
    20,    20,    17,    18,     3,     4,     5,     6,     7,     8,
     9,    10,    11,    12,    13,    12,     3,   152,    17,    18,
   276,    34,    49,    34,    49,   160,    21,    22,    23,    24,
    34,   322,    34,   324,    49,   262,    20,   264,   269,   330,
   331,    56,    20,   334,    34,    34,    41,    20,   279,    34,
    51,    34,    51,    49,    12,    50,    49,   348,    49,    51,
   195,    49,   353,    19,   199,    10,    11,    19,    19,   360,
   361,    19,   363,   364,    19,   366,    21,    22,    23,    58,
    51,    26,   373,    28,    29,    30,    56,   378,    52,    21,
    22,    23,    24,    28,    39,    40,    41,    51,    43,    44,
    45,    46,    47,    48,    49,    50,    51,   338,    53,    41,
    55,    51,    57,    10,    11,    49,    10,    11,    50,    49,
    49,    10,    11,    51,    21,    22,    23,    21,    22,    23,
    49,    52,    21,    22,    23,    20,    56,    54,    35,    19,
    12,    35,    51,    49,    41,    12,    49,    41,    52,    38,
    49,    49,    41,    50,    54,    51,    50,    27,    51,    56,
    57,    50,    56,    57,    10,    11,    56,    56,    57,    10,
    11,    10,    11,    12,    13,    21,    22,    23,    17,    18,
    21,    22,    23,    51,    20,    51,    10,    11,    52,    51,
    51,    20,    38,    20,    35,    41,     0,    21,    22,    23,
    41,     0,     8,   366,    50,   132,   120,   338,   246,    50,
    56,    57,    10,    11,    38,   288,    57,    41,   355,     8,
     8,    19,    44,    21,    22,    23,    50,    74,   146,    10,
    11,   229,    -1,    57,    -1,    -1,   128,    -1,    19,    -1,
    -1,    39,    40,    41,    -1,    -1,    44,    45,    46,    47,
    48,    49,    50,    -1,    -1,    53,    -1,    55,    39,    40,
    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    10,
    11,    -1,    53,    -1,    55,    10,    11,    -1,    -1,    -1,
    21,    22,    23,    -1,    -1,    -1,    21,    22,    23,    -1,
    21,    22,    23,    24,    35,    -1,    21,    22,    23,    24,
    41,    10,    11,    38,    -1,    -1,    41,    -1,    -1,    50,
    41,    -1,    21,    22,    23,    50,    41,    -1,    -1,    50,
    21,    22,    23,    -1,    -1,    50,    21,    22,    23,    38,
    -1,    -1,    41,    21,    22,    23,    -1,    -1,    -1,    -1,
    41,    50,    -1,    -1,    32,    33,    41,    -1,    -1,    50,
    -1,    -1,    -1,    41,    42,    50,     3,     4,     5,     6,
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
    -1,    17,    18
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
#line 146 "bison_rules_with_code.y"
{yyval.Program = root = Program_node::createProgramNode(yyvsp[0].Function_and_class_list);;
    break;}
case 2:
#line 149 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassBlock(yyvsp[0].Class_block);;
    break;}
case 3:
#line 150 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromFunction(yyvsp[0].Function);;
    break;}
case 4:
#line 151 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::createFunctionAndClassListNodeFromClassDeclarationList(yyvsp[0].Class_declaration_list);;
    break;}
case 5:
#line 152 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassBlock(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_block);;
    break;}
case 6:
#line 153 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromFunction(yyvsp[-1].Function_and_class_list, yyvsp[0].Function);;
    break;}
case 7:
#line 154 "bison_rules_with_code.y"
{yyval.Function_and_class_list = Function_and_class_list_node::addToFunctionAndClassListNodeFromClassDeclarationList(yyvsp[-1].Function_and_class_list, yyvsp[0].Class_declaration_list);;
    break;}
case 8:
#line 159 "bison_rules_with_code.y"
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
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Identifier, NULL);;
    break;}
case 29:
#line 201 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 30:
#line 204 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Identifier);;
    break;}
case 31:
#line 205 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-3].Declarator_list, yyvsp[0].Identifier);;
    break;}
case 32:
#line 207 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::createDeclaratorListNode(yyvsp[0].Identifier);;
    break;}
case 33:
#line 208 "bison_rules_with_code.y"
{yyval.Declarator_list = Declarator_list_node::addToDeclaratorListNode(yyvsp[-2].Declarator_list,yyvsp[0].Identifier);;
    break;}
case 34:
#line 211 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Identifier, NULL);;
    break;}
case 35:
#line 212 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 36:
#line 215 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 37:
#line 216 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 38:
#line 219 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 39:
#line 220 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 40:
#line 223 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::createParameterListNode(yyvsp[0].Parameter_declaration);;
    break;}
case 41:
#line 224 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::addToParameterListNode(yyvsp[-2].Parameter_list, yyvsp[0].Parameter_declaration);;
    break;}
case 42:
#line 227 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(yyvsp[-1].Type, yyvsp[0].Identifier);;
    break;}
case 43:
#line 228 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier),yyvsp[0].Identifier);;
    break;}
case 44:
#line 233 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromIdentifier(yyvsp[0].Identifier);;
    break;}
case 45:
#line 234 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromLiteral(yyvsp[0].Literal);;
    break;}
case 46:
#line 235 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromNumericConstant(yyvsp[0].Numeric_constant);;
    break;}
case 47:
#line 236 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSimpleExpression(PRIORITY_EXPRESSION_TYPE, yyvsp[-1].Expression);;
    break;}
case 48:
#line 237 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSelf();;
    break;}
case 49:
#line 238 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSuper();;
    break;}
case 50:
#line 239 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 51:
#line 240 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromFunctionCall(yyvsp[-3].Identifier, yyvsp[-1].Expression_list);;
    break;}
case 52:
#line 241 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UMINUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 53:
#line 242 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UPLUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 54:
#line 243 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UAMPERSAND_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 55:
#line 244 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(PLUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 56:
#line 245 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MINUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 57:
#line 246 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MUL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 58:
#line 247 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(DIV_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 59:
#line 248 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 60:
#line 249 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(NOT_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 61:
#line 250 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 62:
#line 251 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 63:
#line 252 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 64:
#line 253 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 65:
#line 254 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(ASSIGNMENT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 66:
#line 255 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMemberAccessOperator(DOT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Identifier);;
    break;}
case 67:
#line 256 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMemberAccessOperator(ARROW_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Identifier);;
    break;}
case 68:
#line 259 "bison_rules_with_code.y"
{yyval.Expression = NULL;;
    break;}
case 69:
#line 260 "bison_rules_with_code.y"
{yyval.Expression = yyvsp[0].Expression;;
    break;}
case 70:
#line 263 "bison_rules_with_code.y"
{yyval.Expression_list = NULL;;
    break;}
case 71:
#line 264 "bison_rules_with_code.y"
{yyval.Expression_list = yyvsp[0].Expression_list;;
    break;}
case 72:
#line 267 "bison_rules_with_code.y"
{yyval.Expression_list = Expression_list_node::createExpressionListNode(yyvsp[0].Expression);;
    break;}
case 73:
#line 268 "bison_rules_with_code.y"
{yyval.Expression_list = Expression_list_node::addToExpressionListNode(yyvsp[-2].Expression_list, yyvsp[0].Expression);;
    break;}
case 74:
#line 271 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);;
    break;}
case 75:
#line 272 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);;
    break;}
case 76:
#line 273 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(OBJECT_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 77:
#line 274 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(CLASS_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 78:
#line 275 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 79:
#line 278 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 80:
#line 279 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Expression, yyvsp[0].Keyword_argument_list, NULL);;
    break;}
case 81:
#line 280 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Expression, yyvsp[-2].Keyword_argument_list, yyvsp[0].Expression_list);;
    break;}
case 82:
#line 283 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = NULL;;
    break;}
case 83:
#line 284 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = yyvsp[0].Keyword_argument_list;;
    break;}
case 84:
#line 287 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::createKeywordArgumentListNode(yyvsp[0].Keyword_argument);;
    break;}
case 85:
#line 288 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::addToKeywordArgumentListNode(yyvsp[-1].Keyword_argument_list, yyvsp[0].Keyword_argument);;
    break;}
case 86:
#line 291 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITH_IDENTIFIER_KW_ARGUMENT_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 87:
#line 292 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 88:
#line 296 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITHOUT_ALTERNATIVE_IF_TYPE, yyvsp[-2].Expression, yyvsp[0].Statement, NULL);;
    break;}
case 89:
#line 297 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITH_ALTERNATIVE_IF_TYPE, yyvsp[-4].Expression, yyvsp[-2].Statement, yyvsp[0].Statement);;
    break;}
case 90:
#line 301 "bison_rules_with_code.y"
{yyval.While  = While_statement_node::createWhileStatementNode(yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 91:
#line 304 "bison_rules_with_code.y"
{yyval.Do_while = Do_while_statement_node::createDoWhileStatementNode(yyvsp[-2].Expression, yyvsp[-5].Statement);;
    break;}
case 92:
#line 307 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNode(yyvsp[-6].Expression, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 93:
#line 308 "bison_rules_with_code.y"
{yyval.For =For_statement_node::createForStatementNodeFromForWithDeclaration(yyvsp[-7].Type, yyvsp[-6].Init_declarator_list, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 94:
#line 309 "bison_rules_with_code.y"
{yyval.For =For_statement_node::createForStatementNodeFromForWithDeclaration(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-8].Identifier), yyvsp[-6].Init_declarator_list, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 95:
#line 310 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 96:
#line 311 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-6].Identifier), yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 97:
#line 316 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);;
    break;}
case 98:
#line 317 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 99:
#line 318 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 100:
#line 319 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].If;;
    break;}
case 101:
#line 320 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].While;;
    break;}
case 102:
#line 321 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].Do_while;;
    break;}
case 103:
#line 322 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].For;;
    break;}
case 104:
#line 323 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].Compound_statement;;
    break;}
case 105:
#line 324 "bison_rules_with_code.y"
{yyval.Statement = yyvsp[0].Declaration;;
    break;}
case 106:
#line 327 "bison_rules_with_code.y"
{yyval.Compound_statement = Compound_statement_node::createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 107:
#line 330 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::createStatementListNode(yyvsp[0].Statement);;
    break;}
case 108:
#line 331 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::addToStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 109:
#line 334 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 110:
#line 335 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 111:
#line 338 "bison_rules_with_code.y"
{yyval.Class_block = yyvsp[0].Class_interface;;
    break;}
case 112:
#line 339 "bison_rules_with_code.y"
{yyval.Class_block = yyvsp[0].Class_implementation;;
    break;}
case 113:
#line 343 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 114:
#line 344 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 115:
#line 345 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 116:
#line 346 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 117:
#line 347 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 118:
#line 348 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 119:
#line 351 "bison_rules_with_code.y"
{yyval.Interface_body = NULL;;
    break;}
case 120:
#line 352 "bison_rules_with_code.y"
{yyval.Interface_body = yyvsp[0].Interface_body;;
    break;}
case 121:
#line 355 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(yyvsp[-2].Instance_variables_declaration_list, yyvsp[0].Interface_declaration_list);;
    break;}
case 122:
#line 356 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 123:
#line 359 "bison_rules_with_code.y"
{yyval.Implementation_body = NULL;;
    break;}
case 124:
#line 360 "bison_rules_with_code.y"
{yyval.Implementation_body = yyvsp[0].Implementation_body;;
    break;}
case 125:
#line 363 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(yyvsp[-2].Instance_variables_declaration_list, yyvsp[0].Implementation_definition_list);;
    break;}
case 126:
#line 364 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 127:
#line 367 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 128:
#line 368 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 129:
#line 369 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 130:
#line 370 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 131:
#line 371 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 132:
#line 372 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 133:
#line 375 "bison_rules_with_code.y"
{yyval.Class_declaration_list = Class_declaration_list_node::createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 134:
#line 378 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::createClassListNode(yyvsp[0].Identifier);;
    break;}
case 135:
#line 379 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::addToClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 136:
#line 382 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = NULL;;
    break;}
case 137:
#line 383 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = yyvsp[0].Instance_variables_declaration_list;;
    break;}
case 138:
#line 386 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Declarator_list);;
    break;}
case 139:
#line 387 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration = Instance_variables_declaration_node::createInstanceVariablesDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Declarator_list);;
    break;}
case 140:
#line 390 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::createInstanceVariablesDeclarationListNode(yyvsp[0].Instance_variables_declaration);;
    break;}
case 141:
#line 391 "bison_rules_with_code.y"
{yyval.Instance_variables_declaration_list = Instance_variables_declaration_list_node::addToInstanceVariablesDeclarationListNode(yyvsp[-1].Instance_variables_declaration_list, yyvsp[0].Instance_variables_declaration);;
    break;}
case 142:
#line 394 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 143:
#line 395 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 144:
#line 396 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(yyvsp[0].Method_declaration);;
    break;}
case 145:
#line 397 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 146:
#line 398 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 147:
#line 399 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 148:
#line 402 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 149:
#line 403 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 150:
#line 404 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 151:
#line 405 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 152:
#line 406 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 153:
#line 407 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 154:
#line 410 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 155:
#line 411 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromSynthesize(yyvsp[-1].Identifier);;
    break;}
case 156:
#line 412 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(yyvsp[0].Method_definition);;
    break;}
case 157:
#line 413 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 158:
#line 414 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addSynthesizeToImplementationDefinitionListNode(yyvsp[-3].Implementation_definition_list, yyvsp[-1].Identifier);;
    break;}
case 159:
#line 415 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 160:
#line 418 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 161:
#line 419 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 162:
#line 420 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 163:
#line 421 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 164:
#line 422 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 165:
#line 423 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 166:
#line 426 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 167:
#line 427 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Keyword_declaration, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 168:
#line 428 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Keyword_declaration, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_list);;
    break;}
case 169:
#line 431 "bison_rules_with_code.y"
{yyval.Keyword_selector = NULL;;
    break;}
case 170:
#line 432 "bison_rules_with_code.y"
{yyval.Keyword_selector = yyvsp[0].Keyword_selector;;
    break;}
case 171:
#line 435 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 172:
#line 436 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::addToKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 173:
#line 439 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 174:
#line 440 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 175:
#line 443 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 176:
#line 444 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 177:
#line 445 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 178:
#line 446 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 179:
#line 449 "bison_rules_with_code.y"
{yyval.Type = yyvsp[-1].Type;;
    break;}
case 180:
#line 450 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier);;
    break;}
case 181:
#line 453 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-3].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 182:
#line 454 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 183:
#line 457 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(EMPTY_ATTRIBUTE_TYPE);;
    break;}
case 184:
#line 458 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(EMPTY_ATTRIBUTE_TYPE);;
    break;}
case 185:
#line 459 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 186:
#line 460 "bison_rules_with_code.y"
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
#line 463 "bison_rules_with_code.y"


void yyerror(char const *s)
{
	printf("%s",s);
}
