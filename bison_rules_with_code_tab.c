
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



#define	YYFINAL		334
#define	YYFLAG		-32768
#define	YYNTBASE	56

#define YYTRANSLATE(x) ((unsigned)(x) <= 293 ? yytranslate[x] : 112)

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
    75,    80,    82,    86,    87,    89,    91,    95,    98,   102,
   104,   106,   108,   112,   114,   119,   122,   125,   128,   132,
   136,   140,   144,   148,   152,   156,   160,   164,   168,   172,
   173,   175,   177,   179,   181,   186,   188,   193,   194,   196,
   198,   201,   205,   208,   214,   222,   228,   236,   246,   254,
   263,   273,   275,   278,   282,   284,   286,   288,   290,   292,
   294,   298,   300,   303,   304,   306,   308,   310,   317,   322,
   329,   332,   334,   337,   339,   344,   351,   356,   363,   370,
   377,   381,   383,   387,   391,   393,   395,   397,   400,   403,
   406,   408,   410,   415,   422,   426,   431,   438,   442,   444,
   446,   448,   451,   454,   457,   459,   461,   467,   475,   480,
   486,   494,   499,   501,   506,   513,   514,   516,   518,   521,
   524,   526,   530,   533,   538,   542,   546,   551,   559,   568,
   570
};

static const short yyrhs[] = {    57,
     0,    88,     0,    58,     0,    93,     0,    57,    88,     0,
    57,    58,     0,    57,    93,     0,    59,    48,    17,    18,
    85,     0,    21,     0,    22,     0,    23,     0,    40,     0,
    46,     0,    43,     0,    44,     0,    45,     0,    47,     0,
    59,    65,    50,     0,    49,    70,    50,     0,    62,     0,
    63,    62,     0,     0,    63,     0,     0,    66,     0,    67,
     0,    66,    51,    67,     0,    48,     0,    48,     3,    73,
     0,    12,    48,     0,    12,    48,     3,    73,     0,    68,
     0,    69,    51,    68,     0,     0,    69,     0,    72,     0,
    71,    51,    72,     0,    59,    48,     0,    49,    12,    48,
     0,    48,     0,    61,     0,    60,     0,    17,    73,    18,
     0,    38,     0,    19,    75,    76,    20,     0,    11,    73,
     0,    10,    73,     0,    52,    73,     0,    73,    10,    73,
     0,    73,    11,    73,     0,    73,    12,    73,     0,    73,
    13,    73,     0,    73,     4,    73,     0,    73,     5,    73,
     0,    73,     7,    73,     0,    73,     6,    73,     0,    73,
     8,    73,     0,    73,     9,    73,     0,    73,     3,    73,
     0,     0,    73,     0,    39,     0,    38,     0,    48,     0,
    19,    75,    76,    20,     0,    48,     0,    48,    53,    73,
    77,     0,     0,    78,     0,    79,     0,    78,    79,     0,
    48,    53,    73,     0,    53,    73,     0,    26,    17,    73,
    18,    84,     0,    26,    17,    73,    18,    84,    27,    84,
     0,    28,    17,    73,    18,    84,     0,    29,    84,    28,
    17,    73,    18,    50,     0,    30,    17,    74,    50,    74,
    50,    74,    18,    84,     0,    30,    17,    48,    31,    73,
    18,    84,     0,    30,    17,    59,    48,    31,    73,    18,
    84,     0,    30,    17,    49,    12,    48,    31,    73,    18,
    84,     0,    50,     0,    73,    50,     0,    42,    74,    50,
     0,    80,     0,    81,     0,    82,     0,    83,     0,    85,
     0,    62,     0,    54,    87,    55,     0,    84,     0,    86,
    84,     0,     0,    86,     0,    89,     0,    92,     0,    32,
    48,    53,    48,    90,    34,     0,    32,    48,    90,    34,
     0,    32,    48,    53,    49,    90,    34,     0,    95,    96,
     0,    96,     0,    95,   100,     0,   100,     0,    33,    48,
    91,    34,     0,    33,    48,    53,    48,    91,    34,     0,
    33,    49,    91,    34,     0,    33,    49,    53,    48,    91,
    34,     0,    33,    48,    53,    49,    91,    34,     0,    33,
    49,    53,    49,    91,    34,     0,    41,    94,    50,     0,
    48,     0,    94,    51,    48,     0,    54,    63,    55,     0,
    62,     0,   110,     0,    97,     0,    96,    62,     0,    96,
    97,     0,    96,   110,     0,    98,     0,    99,     0,    10,
   109,   104,    50,     0,    10,    17,    24,    18,   104,    50,
     0,    10,   104,    50,     0,    11,   109,   104,    50,     0,
    11,    17,    24,    18,   104,    50,     0,    11,   104,    50,
     0,    62,     0,   110,     0,   101,     0,   100,    62,     0,
   100,   101,     0,   100,   110,     0,   102,     0,   103,     0,
    10,   109,   104,    64,    85,     0,    10,    17,    24,    18,
   104,    64,    85,     0,    10,   104,    64,    85,     0,    11,
   109,   104,    64,    85,     0,    11,    17,    24,    18,   104,
    64,    85,     0,    11,   104,    64,    85,     0,    48,     0,
    48,    53,   107,   105,     0,    48,    53,   107,   105,    51,
    71,     0,     0,   106,     0,   108,     0,   106,   108,     0,
   109,    48,     0,    48,     0,    53,   109,    48,     0,    53,
    48,     0,    48,    53,   109,    48,     0,    48,    53,    48,
     0,    17,    59,    18,     0,    17,    49,    12,    18,     0,
    35,    17,   111,    18,    59,    48,    50,     0,    35,    17,
   111,    18,    49,    12,    48,    50,     0,    36,     0,    37,
     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   136,   139,   140,   141,   142,   143,   144,   149,   152,   153,
   154,   155,   159,   160,   163,   164,   165,   169,   170,   173,
   174,   177,   178,   181,   182,   185,   186,   189,   190,   193,
   194,   197,   198,   201,   202,   205,   206,   209,   210,   215,
   216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
   226,   227,   228,   229,   230,   231,   232,   233,   234,   237,
   238,   241,   242,   243,   244,   247,   248,   251,   252,   255,
   256,   259,   260,   264,   265,   269,   272,   275,   276,   277,
   278,   283,   284,   285,   286,   287,   288,   289,   290,   291,
   294,   297,   298,   301,   302,   305,   306,   310,   311,   312,
   315,   316,   319,   320,   323,   324,   325,   326,   327,   328,
   331,   334,   335,   338,   341,   342,   343,   344,   345,   346,
   349,   350,   353,   354,   355,   358,   359,   360,   363,   364,
   365,   366,   367,   368,   371,   372,   375,   376,   377,   380,
   381,   382,   385,   386,   387,   390,   391,   394,   395,   398,
   399,   402,   403,   404,   405,   408,   409,   412,   413,   416,
   417
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
"init_declarator_with_asterisk","init_declarator_with_asterisk_list","init_declarator_with_asterisk_list_e",
"parameter_list","parameter_declaration","expression","expression_e","receiver",
"message_selector","keyword_argument_list_e","keyword_argument_list","keyword_argument",
"if_statement","while_statement","do_while_statement","for_statement","statement",
"compound_statement","statement_list","statement_list_e","class_block","class_interface",
"interface_body","implementation_body","class_implementation","class_declaration_list",
"class_list","instance_variables","interface_declaration_list","method_declaration",
"class_method_declaration","instance_method_declaration","implementation_definition_list",
"method_definition","class_method_definition","instance_method_definition","method_selector",
"keyword_selector_e","keyword_selector","keyword_declaration_without_identifier",
"keyword_declaration","method_type","property","attribute",""
};
#endif

static const short yyr1[] = {     0,
    56,    57,    57,    57,    57,    57,    57,    58,    59,    59,
    59,    59,    60,    60,    61,    61,    61,    62,    62,    63,
    63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
    68,    69,    69,    70,    70,    71,    71,    72,    72,    73,
    73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
    73,    73,    73,    73,    73,    73,    73,    73,    73,    74,
    74,    75,    75,    75,    75,    76,    76,    77,    77,    78,
    78,    79,    79,    80,    80,    81,    82,    83,    83,    83,
    83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
    85,    86,    86,    87,    87,    88,    88,    89,    89,    89,
    90,    90,    91,    91,    92,    92,    92,    92,    92,    92,
    93,    94,    94,    95,    96,    96,    96,    96,    96,    96,
    97,    97,    98,    98,    98,    99,    99,    99,   100,   100,
   100,   100,   100,   100,   101,   101,   102,   102,   102,   103,
   103,   103,   104,   104,   104,   105,   105,   106,   106,   107,
   107,   108,   108,   108,   108,   109,   109,   110,   110,   111,
   111
};

static const short yyr2[] = {     0,
     1,     1,     1,     1,     2,     2,     2,     5,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
     2,     0,     1,     0,     1,     1,     3,     1,     3,     2,
     4,     1,     3,     0,     1,     1,     3,     2,     3,     1,
     1,     1,     3,     1,     4,     2,     2,     2,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     0,
     1,     1,     1,     1,     4,     1,     4,     0,     1,     1,
     2,     3,     2,     5,     7,     5,     7,     9,     7,     8,
     9,     1,     2,     3,     1,     1,     1,     1,     1,     1,
     3,     1,     2,     0,     1,     1,     1,     6,     4,     6,
     2,     1,     2,     1,     4,     6,     4,     6,     6,     6,
     3,     1,     3,     3,     1,     1,     1,     2,     2,     2,
     1,     1,     4,     6,     3,     4,     6,     3,     1,     1,
     1,     2,     2,     2,     1,     1,     5,     7,     4,     5,
     7,     4,     1,     4,     6,     0,     1,     1,     2,     2,
     1,     3,     2,     4,     3,     3,     4,     7,     8,     1,
     1
};

static const short yydefact[] = {     0,
     9,    10,    11,     0,     0,    12,     0,     1,     3,     0,
     2,    96,    97,     4,     0,     0,     0,   112,     0,     6,
     5,     7,     0,     0,     0,     0,    34,     0,     0,    24,
   115,     0,     0,   102,   117,   121,   122,   116,     0,     0,
     0,   129,     0,     0,   104,   131,   135,   136,   130,     0,
     0,   111,     0,     0,     0,   143,     0,     0,     0,     0,
     0,     0,     0,    32,    35,     0,     0,     0,    20,     0,
    28,     0,    25,    26,    99,   101,   118,   119,   120,     0,
    22,     0,     0,    22,     0,     0,     0,   105,   103,   132,
   133,   134,     0,     0,   107,   113,     0,     0,     0,     0,
     0,   125,     0,     0,   128,     0,   160,   161,     0,    30,
     0,    19,     0,     0,   114,    21,     0,    18,     0,     0,
    23,     0,    22,     0,     0,    22,     0,     0,     0,     0,
    94,     8,     0,     0,   156,     0,   151,   146,     0,   123,
     0,   126,     0,     0,    33,    98,   100,     0,     0,     0,
     0,    44,    14,    15,    16,    13,    17,    40,     0,    42,
    41,    29,    27,     0,   139,     0,     0,   142,     0,   106,
   109,   108,   110,     0,     0,     0,     0,    60,    82,    90,
     0,    85,    86,    87,    88,    92,    89,    95,     0,     0,
   157,     0,     0,   144,   147,   148,   150,     0,     0,     0,
    31,    47,    46,     0,     0,    63,    62,    64,     0,    48,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    22,   137,    22,   140,     0,     0,     0,    60,    61,
     0,    83,    93,    91,   124,     0,   153,     0,     0,   149,
   127,     0,     0,    43,     0,    66,     0,    59,    53,    54,
    56,    55,    57,    58,    49,    50,    51,    52,     0,     0,
     0,     0,     0,    40,     0,     0,     0,    84,   155,     0,
   152,     0,     0,   145,    36,     0,   158,     0,     0,    45,
   138,   141,     0,     0,     0,     0,     0,     0,    60,   154,
     0,    38,     0,   159,    65,    68,    74,    76,     0,     0,
     0,     0,     0,    39,    37,     0,     0,    67,    69,    70,
     0,     0,     0,     0,     0,    60,     0,    73,    71,    75,
    77,    79,     0,     0,     0,    72,     0,    80,     0,    81,
    78,     0,     0,     0
};

static const short yydefgoto[] = {   332,
     8,     9,    30,   160,   161,   180,   121,   122,    72,    73,
    74,    64,    65,    66,   274,   275,   181,   231,   209,   247,
   308,   309,   310,   182,   183,   184,   185,   186,   187,   188,
   189,    11,    12,    32,    43,    13,    14,    19,    44,    34,
    35,    36,    37,    45,    46,    47,    48,    57,   194,   195,
   138,   196,    58,    49,   109
};

static const short yypact[] = {   375,
-32768,-32768,-32768,   -22,   -17,-32768,    -6,   375,-32768,    -1,
-32768,-32768,-32768,-32768,   324,   327,   330,-32768,    19,-32768,
-32768,-32768,    16,   -10,    -4,    33,    48,    25,   155,    27,
-32768,    44,   203,   203,-32768,-32768,-32768,-32768,     4,     6,
    37,-32768,    62,   467,   467,-32768,-32768,-32768,-32768,    43,
    74,-32768,    63,    49,   263,    61,    67,    76,   371,    81,
    76,    58,    87,-32768,    91,    88,   364,   364,-32768,   111,
   143,    98,   105,-32768,-32768,   203,-32768,-32768,-32768,   446,
   155,    76,   460,   155,    76,   379,   379,-32768,   467,-32768,
-32768,-32768,   379,   379,-32768,-32768,   103,   134,   146,   145,
    10,-32768,   114,   149,-32768,   118,-32768,-32768,   152,   158,
    48,-32768,   139,   140,-32768,-32768,   428,-32768,    27,   166,
   155,   103,   155,   167,   103,   155,   148,   153,   160,   162,
   279,-32768,    76,   181,-32768,   470,-32768,   -31,   157,-32768,
    76,-32768,   475,   428,-32768,-32768,-32768,   428,   428,   428,
   106,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   428,-32768,
-32768,   641,-32768,    76,-32768,   103,    76,-32768,   103,-32768,
-32768,-32768,-32768,   184,   189,   279,   190,   428,-32768,-32768,
   266,-32768,-32768,-32768,-32768,-32768,-32768,   279,   156,   165,
-32768,   163,    20,   159,   -31,-32768,-32768,   168,   196,   172,
   641,-32768,-32768,   529,   106,-32768,-32768,-32768,   173,-32768,
   428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
   428,   155,-32768,   155,-32768,   428,   428,   194,   413,   641,
   177,-32768,-32768,-32768,-32768,    24,-32768,   175,   482,-32768,
-32768,   180,   183,-32768,   173,   182,   210,   641,   238,   238,
   179,   179,   179,   179,   107,   107,-32768,-32768,   103,   103,
   545,   561,   219,   206,   229,   218,   217,-32768,-32768,   232,
-32768,   269,   234,   237,-32768,   233,-32768,   271,   428,-32768,
-32768,-32768,   279,   279,   428,   428,   244,   264,   428,-32768,
   246,-32768,   482,-32768,-32768,   251,   270,-32768,   577,   593,
   275,   428,   260,-32768,-32768,   258,   428,-32768,   -28,-32768,
   279,   265,   279,   428,   609,   428,   428,   641,-32768,-32768,
-32768,-32768,   625,   279,   295,   641,   279,-32768,   279,-32768,
-32768,   314,   318,-32768
};

static const short yypgoto[] = {-32768,
-32768,   312,     0,-32768,-32768,    -5,   301,   -75,-32768,-32768,
   213,   225,-32768,-32768,-32768,    46,  -114,  -223,   137,    99,
-32768,-32768,    34,-32768,-32768,-32768,-32768,  -174,   -79,-32768,
-32768,   346,-32768,    60,    36,-32768,   347,-32768,   -11,   323,
   -15,-32768,-32768,   313,   -40,-32768,-32768,   101,-32768,-32768,
-32768,   171,   -24,   164,-32768
};


#define	YYLAST		654


static const short yytable[] = {    10,
    61,   228,   162,    33,    91,   267,    55,    10,   125,    31,
    42,    42,    59,   233,    82,    85,   192,   132,    78,   306,
    80,   193,    83,    69,   307,    15,   136,    31,    77,   201,
    16,    17,    54,   202,   203,   204,   136,    56,    42,    90,
   136,    18,   165,    56,   210,   168,    23,   166,    91,    62,
   169,    56,    51,    56,   100,    33,    33,   137,   100,    63,
    78,    31,    31,   230,   116,   303,    97,   237,    52,    53,
    77,   269,    67,    68,    71,    69,   139,    75,    69,   100,
    42,    42,   100,    90,    86,    87,   223,    42,    42,   225,
    93,    94,   325,   107,   108,    88,   248,   249,   250,   251,
   252,   253,   254,   255,   256,   257,   258,    95,   297,   298,
    96,   261,   262,   101,   230,   116,   102,    69,   220,   221,
    69,   127,   128,    56,   205,    60,   113,   114,   129,   130,
   105,     1,     2,     3,   110,   100,   320,   112,   322,    81,
    84,   111,   200,   206,   207,   117,   259,   118,   260,   328,
     6,   133,   330,   208,   331,   119,   131,   134,   103,    27,
   144,   106,   135,   140,   296,   115,   141,   142,   238,   143,
   299,   300,   146,   147,   230,     1,     2,     3,    38,   281,
   282,   170,   123,   164,   167,   126,   171,   315,   218,   219,
   220,   221,   318,   172,     6,   173,    38,    79,   191,   323,
   226,   230,   326,    27,   197,   227,   229,   242,    92,   239,
   234,   270,    24,    25,   235,   236,    69,   241,    69,   243,
   246,   263,   271,     1,     2,     3,   268,   276,   266,   280,
    38,    38,   277,   190,   279,   285,   286,    26,   273,    79,
   287,   198,     6,   214,   215,   216,   217,   218,   219,   220,
   221,    27,    92,   211,   212,   213,   214,   215,   216,   217,
   218,   219,   220,   221,   222,   288,   289,   224,   211,   212,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   290,
   291,   292,   294,     1,     2,     3,    98,   293,   148,   149,
   295,   301,   273,   304,   302,   150,   311,   151,   306,     1,
     2,     3,     6,   307,   174,   314,   175,   176,   177,   316,
   317,    99,   329,   333,   321,   232,   152,   334,     6,    20,
   178,   153,   154,   155,   156,   157,   158,    27,   179,    70,
   159,   163,   131,    24,    25,   145,    39,    40,   305,    39,
    40,   245,   319,   278,     1,     2,     3,     1,     2,     3,
     1,     2,     3,    21,    22,    76,    89,     0,    26,     0,
     0,    26,     0,     6,    26,   240,     6,     0,     0,     6,
     0,     0,    27,    24,    25,    27,    28,    29,    27,    41,
    29,     0,    50,    29,     1,     2,     3,     0,    39,    40,
     0,     1,     2,     3,   104,     1,     2,     3,    26,     1,
     2,     3,     0,     6,     0,     0,     4,     5,     0,     0,
     6,     0,    27,    26,     6,     7,     0,    29,     6,    99,
     0,     0,   148,   149,     0,     0,     0,    27,     0,   150,
     0,   151,    29,     1,     2,     3,     0,   148,   149,     0,
     0,     0,     0,     0,   150,     0,   151,     0,     0,     0,
   152,     0,     6,     0,     0,   153,   154,   155,   156,   157,
   264,   265,     0,     0,   159,   152,     1,     2,     3,   120,
   153,   154,   155,   156,   157,   158,    39,    40,     0,   159,
     1,     2,     3,   124,     0,     6,     0,     1,     2,     3,
     1,     2,     3,     0,    99,     1,     2,     3,     0,     6,
     0,    26,     1,     2,     3,     0,     6,     0,    99,     6,
     0,     0,     0,     0,     6,    27,     0,     0,    99,     0,
     0,     6,     0,   199,     0,     0,     0,     0,     0,     0,
   272,   211,   212,   213,   214,   215,   216,   217,   218,   219,
   220,   221,     0,     0,     0,     0,   244,   211,   212,   213,
   214,   215,   216,   217,   218,   219,   220,   221,     0,     0,
     0,     0,   283,   211,   212,   213,   214,   215,   216,   217,
   218,   219,   220,   221,     0,     0,     0,     0,   284,   211,
   212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     0,     0,     0,     0,   312,   211,   212,   213,   214,   215,
   216,   217,   218,   219,   220,   221,     0,     0,     0,     0,
   313,   211,   212,   213,   214,   215,   216,   217,   218,   219,
   220,   221,     0,     0,     0,     0,   324,   211,   212,   213,
   214,   215,   216,   217,   218,   219,   220,   221,     0,     0,
     0,     0,   327,   211,   212,   213,   214,   215,   216,   217,
   218,   219,   220,   221
};

static const short yycheck[] = {     0,
    25,   176,   117,    15,    45,   229,    17,     8,    84,    15,
    16,    17,    17,   188,    39,    40,    48,    97,    34,    48,
    17,    53,    17,    29,    53,    48,    17,    33,    34,   144,
    48,    49,    17,   148,   149,   150,    17,    48,    44,    45,
    17,    48,   122,    48,   159,   125,    48,   123,    89,    17,
   126,    48,    17,    48,    55,    67,    68,    48,    59,    12,
    76,    67,    68,   178,    70,   289,    18,    48,    50,    51,
    76,    48,    48,    49,    48,    81,   101,    34,    84,    80,
    86,    87,    83,    89,    48,    49,   166,    93,    94,   169,
    48,    49,   316,    36,    37,    34,   211,   212,   213,   214,
   215,   216,   217,   218,   219,   220,   221,    34,   283,   284,
    48,   226,   227,    53,   229,   121,    50,   123,    12,    13,
   126,    86,    87,    48,    19,    25,    67,    68,    93,    94,
    50,    21,    22,    23,    48,   136,   311,    50,   313,    39,
    40,    51,   143,    38,    39,     3,   222,    50,   224,   324,
    40,    18,   327,    48,   329,    51,    54,    12,    58,    49,
     3,    61,    18,    50,   279,    55,    18,    50,   193,    18,
   285,   286,    34,    34,   289,    21,    22,    23,    15,   259,
   260,    34,    82,    18,    18,    85,    34,   302,    10,    11,
    12,    13,   307,    34,    40,    34,    33,    34,    18,   314,
    17,   316,   317,    49,    48,    17,    17,    12,    45,    51,
    55,   236,    10,    11,    50,    53,   222,    50,   224,    48,
    48,    28,    48,    21,    22,    23,    50,    48,   229,    20,
    67,    68,    50,   133,    53,    17,    31,    35,   239,    76,
    12,   141,    40,     6,     7,     8,     9,    10,    11,    12,
    13,    49,    89,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,   164,    48,    50,   167,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    48,
    12,    48,    50,    21,    22,    23,    24,    51,    10,    11,
    20,    48,   293,    48,    31,    17,    27,    19,    48,    21,
    22,    23,    40,    53,    26,    31,    28,    29,    30,    50,
    53,    49,    18,     0,    50,    50,    38,     0,    40,     8,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    29,
    52,   119,    54,    10,    11,   111,    10,    11,   293,    10,
    11,   205,   309,   245,    21,    22,    23,    21,    22,    23,
    21,    22,    23,     8,     8,    33,    44,    -1,    35,    -1,
    -1,    35,    -1,    40,    35,   195,    40,    -1,    -1,    40,
    -1,    -1,    49,    10,    11,    49,    53,    54,    49,    53,
    54,    -1,    53,    54,    21,    22,    23,    -1,    10,    11,
    -1,    21,    22,    23,    24,    21,    22,    23,    35,    21,
    22,    23,    -1,    40,    -1,    -1,    32,    33,    -1,    -1,
    40,    -1,    49,    35,    40,    41,    -1,    54,    40,    49,
    -1,    -1,    10,    11,    -1,    -1,    -1,    49,    -1,    17,
    -1,    19,    54,    21,    22,    23,    -1,    10,    11,    -1,
    -1,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,
    38,    -1,    40,    -1,    -1,    43,    44,    45,    46,    47,
    48,    49,    -1,    -1,    52,    38,    21,    22,    23,    24,
    43,    44,    45,    46,    47,    48,    10,    11,    -1,    52,
    21,    22,    23,    24,    -1,    40,    -1,    21,    22,    23,
    21,    22,    23,    -1,    49,    21,    22,    23,    -1,    40,
    -1,    35,    21,    22,    23,    -1,    40,    -1,    49,    40,
    -1,    -1,    -1,    -1,    40,    49,    -1,    -1,    49,    -1,
    -1,    40,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
    49,     3,     4,     5,     6,     7,     8,     9,    10,    11,
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
#line 159 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromFloat(yyvsp[0].Float_constant);;
    break;}
case 14:
#line 160 "bison_rules_with_code.y"
{yyval.Numeric_constant = Numeric_constant_node::createNumericConstantNodeFromInteger(yyvsp[0].Integer_constant);;
    break;}
case 15:
#line 163 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(STRING_CONSTANT_TYPE, yyvsp[0].String_constant);;
    break;}
case 16:
#line 164 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(CHAR_CONSTANT_TYPE, yyvsp[0].Char_constant);;
    break;}
case 17:
#line 165 "bison_rules_with_code.y"
{yyval.Literal = Literal_node::createLiteralNode(NSSTRING_CONSTANT_TYPE, yyvsp[0].NSString_constant);;
    break;}
case 18:
#line 169 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(yyvsp[-2].Type, yyvsp[-1].Init_declarator_list);;
    break;}
case 19:
#line 170 "bison_rules_with_code.y"
{yyval.Declaration = Declaration_node::createDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier), yyvsp[-1].Init_declarator_list);
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
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(SIMPLE_DECLARATOR_TYPE, yyvsp[0].Identifier, NULL);;
    break;}
case 31:
#line 194 "bison_rules_with_code.y"
{yyval.Init_declarator = Init_declarator_node::createInitDeclaratorNode(DECLARATOR_WITH_INITIALIZING_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 32:
#line 197 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::createInitDeclaratorListNode(yyvsp[0].Init_declarator);;
    break;}
case 33:
#line 198 "bison_rules_with_code.y"
{yyval.Init_declarator_list = Init_declarator_list_node::addToInitDeclaratorListNode(yyvsp[-2].Init_declarator_list, yyvsp[0].Init_declarator);;
    break;}
case 34:
#line 201 "bison_rules_with_code.y"
{yyval.Init_declarator_list = NULL;;
    break;}
case 35:
#line 202 "bison_rules_with_code.y"
{yyval.Init_declarator_list = yyvsp[0].Init_declarator_list;;
    break;}
case 36:
#line 205 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::createParameterListNode(yyvsp[0].Parameter_declaration);;
    break;}
case 37:
#line 206 "bison_rules_with_code.y"
{yyval.Parameter_list = Parameter_list_node::addToParameterListNode(yyvsp[-2].Parameter_list, yyvsp[0].Parameter_declaration);;
    break;}
case 38:
#line 209 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(yyvsp[-1].Type, yyvsp[0].Identifier);;
    break;}
case 39:
#line 210 "bison_rules_with_code.y"
{yyval.Parameter_declaration = Parameter_declaration_node::createParameterDeclarationNode(Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier),yyvsp[0].Identifier);;
    break;}
case 40:
#line 215 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromIdentifier(yyvsp[0].Identifier);;
    break;}
case 41:
#line 216 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromLiteral(yyvsp[0].Literal);;
    break;}
case 42:
#line 217 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromNumericConstant(yyvsp[0].Numeric_constant);;
    break;}
case 43:
#line 218 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createSimpleExpressionNode(PRIORITY_EXPRESSION_TYPE, yyvsp[-1].Expression);;
    break;}
case 44:
#line 219 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromSelf();;
    break;}
case 45:
#line 220 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 46:
#line 221 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UMINUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 47:
#line 222 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UPLUS_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 48:
#line 223 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(UAMPERSAND_EXPRESSION_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 49:
#line 224 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(PLUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 50:
#line 225 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MINUS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 51:
#line 226 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(MUL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 52:
#line 227 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(DIV_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 53:
#line 228 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 54:
#line 229 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(NOT_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 55:
#line 230 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 56:
#line 231 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 57:
#line 232 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(LESS_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 58:
#line 233 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(GREATER_EQUAL_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 59:
#line 234 "bison_rules_with_code.y"
{yyval.Expression = Expression_node::createExpressionNodeFromOperator(ASSIGNMENT_EXPRESSION_TYPE, yyvsp[-2].Expression, yyvsp[0].Expression);;
    break;}
case 60:
#line 237 "bison_rules_with_code.y"
{yyval.Expression = NULL;;
    break;}
case 61:
#line 238 "bison_rules_with_code.y"
{yyval.Expression = yyvsp[0].Expression;;
    break;}
case 62:
#line 241 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SUPER_RECEIVER_TYPE, NULL);;
    break;}
case 63:
#line 242 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(SELF_RECEIVER_TYPE, NULL);;
    break;}
case 64:
#line 243 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNode(OBJECT_NAME_RECEIVER_TYPE, yyvsp[0].Identifier);;
    break;}
case 65:
#line 244 "bison_rules_with_code.y"
{yyval.Receiver = Receiver_node::createReceiverNodeFromMessageExpression(yyvsp[-2].Receiver, yyvsp[-1].Message_selector);;
    break;}
case 66:
#line 247 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[0].Identifier, NULL, NULL);;
    break;}
case 67:
#line 248 "bison_rules_with_code.y"
{yyval.Message_selector = Message_selector_node::createMessageSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Expression, yyvsp[0].Keyword_argument_list);;
    break;}
case 68:
#line 251 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = NULL;;
    break;}
case 69:
#line 252 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = yyvsp[0].Keyword_argument_list;;
    break;}
case 70:
#line 255 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::createKeywordArgumentListNode(yyvsp[0].Keyword_argument);;
    break;}
case 71:
#line 256 "bison_rules_with_code.y"
{yyval.Keyword_argument_list = Keyword_argument_list_node::addToKeywordArgumentListNode(yyvsp[-1].Keyword_argument_list, yyvsp[0].Keyword_argument);;
    break;}
case 72:
#line 259 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITH_IDENTIFIER_KW_ARGUMENT_TYPE, yyvsp[-2].Identifier, yyvsp[0].Expression);;
    break;}
case 73:
#line 260 "bison_rules_with_code.y"
{yyval.Keyword_argument = Keyword_argument_node::createKeywordArgumentNode(WITHOUT_IDENTIFIER_KW_ARGUMENT_TYPE, NULL, yyvsp[0].Expression);;
    break;}
case 74:
#line 264 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITHOUT_ALTERNATIVE_IF_TYPE, yyvsp[-2].Expression, yyvsp[0].Statement, NULL);;
    break;}
case 75:
#line 265 "bison_rules_with_code.y"
{yyval.If = If_statement_node::createIfStatementNode(WITH_ALTERNATIVE_IF_TYPE, yyvsp[-4].Expression, yyvsp[-2].Statement, yyvsp[0].Statement);;
    break;}
case 76:
#line 269 "bison_rules_with_code.y"
{yyval.While  = While_statement_node::createWhileStatementNode(yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 77:
#line 272 "bison_rules_with_code.y"
{yyval.Do_while = Do_while_statement_node::createDoWhileStatementNode(yyvsp[-2].Expression, yyvsp[-5].Statement);;
    break;}
case 78:
#line 275 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNode(yyvsp[-6].Expression, yyvsp[-4].Expression, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 79:
#line 276 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_FOR_TYPE, NULL, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 80:
#line 277 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, yyvsp[-5].Type, yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 81:
#line 278 "bison_rules_with_code.y"
{yyval.For = For_statement_node::createForStatementNodeFromForeach(FOREACH_WITH_DECLARATION_FOR_TYPE, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-6].Identifier), yyvsp[-4].Identifier, yyvsp[-2].Expression, yyvsp[0].Statement);;
    break;}
case 82:
#line 283 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(EMPTY_STATEMENT_TYPE, NULL);;
    break;}
case 83:
#line 284 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(SIMPLE_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 84:
#line 285 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, yyvsp[-1].Expression);;
    break;}
case 85:
#line 286 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(IF_STATEMENT_TYPE, yyvsp[0].If);;
    break;}
case 86:
#line 287 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(WHILE_STATEMENT_TYPE, yyvsp[0].While);;
    break;}
case 87:
#line 288 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(DO_WHILE_STATEMENT_TYPE, yyvsp[0].Do_while);;
    break;}
case 88:
#line 289 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(FOR_STATEMENT_TYPE, yyvsp[0].For);;
    break;}
case 89:
#line 290 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromComplexStatement(COMPOUND_STATEMENT_TYPE, yyvsp[0].Compound_statement);;
    break;}
case 90:
#line 291 "bison_rules_with_code.y"
{yyval.Statement = Statement_node::createStatementNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 91:
#line 294 "bison_rules_with_code.y"
{yyval.Compound_statement = Compound_statement_node::createCompoundStatementNode(yyvsp[-1].Statement_list);;
    break;}
case 92:
#line 297 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::createStatementListNode(yyvsp[0].Statement);;
    break;}
case 93:
#line 298 "bison_rules_with_code.y"
{yyval.Statement_list = Statement_list_node::addToStatementListNode(yyvsp[-1].Statement_list, yyvsp[0].Statement);;
    break;}
case 94:
#line 301 "bison_rules_with_code.y"
{yyval.Statement_list = NULL;;
    break;}
case 95:
#line 302 "bison_rules_with_code.y"
{yyval.Statement_list = yyvsp[0].Statement_list;;
    break;}
case 96:
#line 305 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlockNodeFromInterface(yyvsp[0].Class_interface);;
    break;}
case 97:
#line 306 "bison_rules_with_code.y"
{yyval.Class_block = Class_block_node::createClassBlcokNodeFromImplementation(yyvsp[0].Class_implementation);;
    break;}
case 98:
#line 310 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 99:
#line 311 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Interface_body);;
    break;}
case 100:
#line 312 "bison_rules_with_code.y"
{yyval.Class_interface = Class_interface_node::createClassInterfaceNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Interface_body);;
    break;}
case 101:
#line 315 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Interface_declaration_list);;
    break;}
case 102:
#line 316 "bison_rules_with_code.y"
{yyval.Interface_body = Interface_body_node::createInterfaceBodyNode(NULL, yyvsp[0].Interface_declaration_list);;
    break;}
case 103:
#line 319 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(yyvsp[-1].Instance_variables, yyvsp[0].Implementation_definition_list);;
    break;}
case 104:
#line 320 "bison_rules_with_code.y"
{yyval.Implementation_body = Implementation_body_node::createImplementationBodyNode(NULL, yyvsp[0].Implementation_definition_list);;
    break;}
case 105:
#line 323 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 106:
#line 324 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 107:
#line 325 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-2].Identifier, NULL, yyvsp[-1].Implementation_body);;
    break;}
case 108:
#line 326 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 109:
#line 327 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 110:
#line 328 "bison_rules_with_code.y"
{yyval.Class_implementation = Class_implementation_node::createClassImplementationNode(yyvsp[-4].Identifier, yyvsp[-2].Identifier, yyvsp[-1].Implementation_body);;
    break;}
case 111:
#line 331 "bison_rules_with_code.y"
{yyval.Class_declaration_list = Class_declaration_list_node::createClassDeclarationListNode(yyvsp[-1].Class_list);;
    break;}
case 112:
#line 334 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::createClassListNode(yyvsp[0].Identifier);;
    break;}
case 113:
#line 335 "bison_rules_with_code.y"
{yyval.Class_list = Class_list_node::addToClassListNode(yyvsp[-2].Class_list, yyvsp[0].Identifier);;
    break;}
case 114:
#line 338 "bison_rules_with_code.y"
{yyval.Instance_variables = Instance_variables_node::createInstanceVariablesNode(yyvsp[-1].Declaration_list);;
    break;}
case 115:
#line 341 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 116:
#line 342 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 117:
#line 343 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::createInterfaceDeclarationListNodeFromMethodDeclaration(yyvsp[0].Method_declaration);;
    break;}
case 118:
#line 344 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Declaration);;
    break;}
case 119:
#line 345 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addMethodDeclarationToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Method_declaration);;
    break;}
case 120:
#line 346 "bison_rules_with_code.y"
{yyval.Interface_declaration_list = Interface_declaration_list_node::addPropertyToInterfaceDeclarationListNode(yyvsp[-1].Interface_declaration_list, yyvsp[0].Property);;
    break;}
case 121:
#line 349 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 122:
#line 350 "bison_rules_with_code.y"
{yyval.Method_declaration = yyvsp[0].Method_declaration;;
    break;}
case 123:
#line 353 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 124:
#line 354 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 125:
#line 355 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(CLASS_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 126:
#line 358 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, yyvsp[-2].Type, yyvsp[-1].Method_selector);;
    break;}
case 127:
#line 359 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-1].Method_selector);;
    break;}
case 128:
#line 360 "bison_rules_with_code.y"
{yyval.Method_declaration = Method_declaration_node::createMethodDeclarationNode(INSTANCE_METHOD_DECLARATION_TYPE, NULL, yyvsp[-1].Method_selector);;
    break;}
case 129:
#line 363 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromDeclaration(yyvsp[0].Declaration);;
    break;}
case 130:
#line 364 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromProperty(yyvsp[0].Property);;
    break;}
case 131:
#line 365 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::createImplementationDefinitionListNodeFromMethodDeclaration(yyvsp[0].Method_definition);;
    break;}
case 132:
#line 366 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Declaration);;
    break;}
case 133:
#line 367 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addMethodDeclarationToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Method_definition);;
    break;}
case 134:
#line 368 "bison_rules_with_code.y"
{yyval.Implementation_definition_list = Implementation_definition_list_node::addPropertyToImplementationDefinitionListNode(yyvsp[-1].Implementation_definition_list, yyvsp[0].Property);;
    break;}
case 135:
#line 371 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 136:
#line 372 "bison_rules_with_code.y"
{yyval.Method_definition = yyvsp[0].Method_definition;;
    break;}
case 137:
#line 375 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 138:
#line 376 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 139:
#line 377 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(CLASS_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 140:
#line 380 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, yyvsp[-3].Type, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 141:
#line 381 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, Type_node::createTypeNode(VOID_TYPE), yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 142:
#line 382 "bison_rules_with_code.y"
{yyval.Method_definition = Method_definition_node::createMethodDefinitionNode(INSTANCE_METHOD_DEFINITION_TYPE, NULL, yyvsp[-2].Method_selector, yyvsp[-1].Declaration_list, yyvsp[0].Compound_statement);;
    break;}
case 143:
#line 385 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[0].Identifier, NULL, NULL, NULL);;
    break;}
case 144:
#line 386 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-3].Identifier, yyvsp[-1].Keyword_declaration, yyvsp[0].Keyword_selector, NULL);;
    break;}
case 145:
#line 387 "bison_rules_with_code.y"
{yyval.Method_selector = Method_selector_node::createMethodSelectorNode(yyvsp[-5].Identifier, yyvsp[-3].Keyword_declaration, yyvsp[-2].Keyword_selector, yyvsp[0].Parameter_list);;
    break;}
case 146:
#line 390 "bison_rules_with_code.y"
{yyval.Keyword_selector = NULL;;
    break;}
case 147:
#line 391 "bison_rules_with_code.y"
{yyval.Keyword_selector = yyvsp[0].Keyword_selector;;
    break;}
case 148:
#line 394 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::createKeywordSelectorNode(yyvsp[0].Keyword_declaration);;
    break;}
case 149:
#line 395 "bison_rules_with_code.y"
{yyval.Keyword_selector = Keyword_selector_node::addToKeywordSelectorNode(yyvsp[-1].Keyword_selector, yyvsp[0].Keyword_declaration);;
    break;}
case 150:
#line 398 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 151:
#line 399 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 152:
#line 402 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, NULL, yyvsp[0].Identifier);;
    break;}
case 153:
#line 403 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, NULL, yyvsp[0].Identifier);;
    break;}
case 154:
#line 404 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(yyvsp[-1].Type, yyvsp[-3].Identifier, yyvsp[0].Identifier);;
    break;}
case 155:
#line 405 "bison_rules_with_code.y"
{yyval.Keyword_declaration = Keyword_declaration_node::createKeywordDeclarationNode(NULL, yyvsp[-2].Identifier, yyvsp[0].Identifier);;
    break;}
case 156:
#line 408 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNode(yyvsp[-1].Type);;
    break;}
case 157:
#line 409 "bison_rules_with_code.y"
{yyval.Type = Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-2].Identifier);;
    break;}
case 158:
#line 412 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-4].Attribute, yyvsp[-2].Type, yyvsp[-1].Identifier);;
    break;}
case 159:
#line 413 "bison_rules_with_code.y"
{yyval.Property = Property_node::createPropertyNode(yyvsp[-5].Attribute, Type_node::createTypeNodeFromClassName(CLASS_NAME_TYPE, yyvsp[-3].Identifier), yyvsp[-1].Identifier);;
    break;}
case 160:
#line 416 "bison_rules_with_code.y"
{yyval.Attribute = Attribute_node::createAttributeNode(READONLY_ATTRIBUTE_TYPE);;
    break;}
case 161:
#line 417 "bison_rules_with_code.y"
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
#line 420 "bison_rules_with_code.y"


