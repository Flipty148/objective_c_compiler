
/*  A Bison parser, made from bizon_rules.y with Bison version GNU Bison version 1.24
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
#define	ENUM	268
#define	CLASS_NAME	269
#define	VOID	270
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
#define	ELIPSIS	294


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

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		278
#define	YYFLAG		-32768
#define	YYNTBASE	57

#define YYTRANSLATE(x) ((unsigned)(x) <= 294 ? yytranslate[x] : 108)

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
     0,     2,     4,     7,    10,    12,    14,    16,    18,    21,
    23,    25,    27,    29,    31,    35,    37,    40,    41,    43,
    44,    46,    48,    52,    54,    58,    60,    64,    66,    70,
    73,    76,    78,    80,    82,    86,    88,    90,    93,    96,
    99,   103,   107,   111,   115,   119,   123,   127,   131,   135,
   139,   143,   144,   146,   151,   153,   155,   157,   159,   161,
   163,   166,   170,   173,   179,   187,   193,   201,   211,   219,
   228,   230,   233,   235,   237,   239,   241,   243,   245,   247,
   251,   253,   256,   257,   259,   261,   263,   265,   268,   275,
   280,   283,   285,   288,   290,   295,   302,   306,   308,   312,
   316,   321,   323,   325,   327,   330,   333,   336,   338,   340,
   345,   352,   356,   361,   368,   372,   374,   376,   378,   381,
   384,   387,   389,   391,   397,   405,   410,   416,   424,   429,
   431,   433,   437,   439,   442,   446,   449,   454,   458,   462,
   470,   472
};

static const short yyrhs[] = {    83,
     0,    86,     0,    83,    86,     0,    86,    83,     0,    21,
     0,    22,     0,    23,     0,    41,     0,    25,    12,     0,
    47,     0,    44,     0,    45,     0,    46,     0,    48,     0,
    58,    64,    51,     0,    61,     0,    62,    61,     0,     0,
    62,     0,     0,    65,     0,    66,     0,    65,    52,    66,
     0,    49,     0,    49,     3,    70,     0,    68,     0,    68,
    52,    50,     0,    69,     0,    68,    52,    69,     0,    58,
    49,     0,    25,    49,     0,    49,     0,    60,     0,    59,
     0,    17,    70,    18,     0,    39,     0,    72,     0,    11,
    70,     0,    10,    70,     0,    53,    70,     0,    70,    10,
    70,     0,    70,    11,    70,     0,    70,    12,    70,     0,
    70,    13,    70,     0,    70,     4,    70,     0,    70,     5,
    70,     0,    70,     7,    70,     0,    70,     6,    70,     0,
    70,     8,    70,     0,    70,     9,    70,     0,    70,     3,
    70,     0,     0,    70,     0,    19,    73,    74,    20,     0,
    40,     0,    39,     0,    25,     0,    49,     0,    75,     0,
    76,     0,    75,    76,     0,    49,    54,    70,     0,    54,
    70,     0,    27,    17,    70,    18,    81,     0,    27,    17,
    70,    18,    81,    28,    81,     0,    29,    17,    70,    18,
    81,     0,    30,    81,    29,    17,    70,    18,    51,     0,
    31,    17,    71,    51,    71,    51,    71,    18,    81,     0,
    31,    17,    49,    32,    70,    18,    81,     0,    31,    17,
    58,    49,    32,    70,    18,    81,     0,    51,     0,    70,
    51,     0,    77,     0,    78,     0,    79,     0,    80,     0,
    82,     0,    61,     0,    91,     0,    55,    84,    56,     0,
    81,     0,    83,    81,     0,     0,    83,     0,    87,     0,
    90,     0,    85,     0,    86,    85,     0,    33,    49,    54,
    49,    88,    35,     0,    33,    49,    88,    35,     0,    93,
    94,     0,    94,     0,    93,    98,     0,    98,     0,    34,
    49,    89,    35,     0,    34,    49,    54,    49,    89,    35,
     0,    42,    92,    51,     0,    49,     0,    92,    52,    49,
     0,    55,    62,    56,     0,    55,    62,    93,    56,     0,
    61,     0,   106,     0,    95,     0,    94,    61,     0,    94,
    95,     0,    94,   106,     0,    96,     0,    97,     0,    10,
   105,   102,    51,     0,    10,    17,    26,    18,   102,    51,
     0,    10,   102,    51,     0,    11,   105,   102,    51,     0,
    11,    17,    26,    18,   102,    51,     0,    11,   102,    51,
     0,    61,     0,   106,     0,    99,     0,    98,    61,     0,
    98,    99,     0,    98,   106,     0,   100,     0,   101,     0,
    10,   105,   102,    63,    82,     0,    10,    17,    26,    18,
   102,    63,    82,     0,    10,   102,    63,    82,     0,    11,
   105,   102,    63,    82,     0,    11,    17,    26,    18,   102,
    63,    82,     0,    11,   102,    63,    82,     0,    49,     0,
   103,     0,   103,    52,    67,     0,   104,     0,   103,   104,
     0,    54,   105,    49,     0,    54,    49,     0,    49,    54,
   105,    49,     0,    49,    54,    49,     0,    17,    58,    18,
     0,    36,    17,   107,    18,    58,    49,    51,     0,    37,
     0,    38,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    30,    31,    32,    33,    37,    38,    39,    40,    41,    45,
    46,    49,    50,    51,    55,    58,    59,    62,    63,    66,
    67,    70,    71,    74,    75,    78,    79,    82,    83,    86,
    87,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   114,   115,   117,   120,   121,   122,   125,   126,   129,
   130,   133,   134,   138,   139,   143,   146,   149,   150,   151,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   167,
   170,   171,   174,   175,   178,   179,   182,   183,   187,   188,
   191,   192,   195,   196,   199,   200,   203,   206,   207,   210,
   211,   215,   216,   217,   218,   219,   220,   223,   224,   227,
   228,   229,   232,   233,   234,   237,   238,   239,   240,   241,
   242,   245,   246,   249,   250,   251,   254,   255,   256,   259,
   260,   261,   264,   265,   268,   269,   270,   271,   274,   277,
   280,   281
};

static const char * const yytname[] = {   "$","error","$undefined.","'='","EQUAL",
"NOT_EQUAL","'<'","'>'","LESS_EQUAL","GREATER_EQUAL","'+'","'-'","'*'","'/'",
"UMINUS","UPLUS","UAMPERSAND","'('","')'","'['","']'","INT","CHAR","FLOAT","ENUM",
"CLASS_NAME","VOID","IF","ELSE","WHILE","DO","FOR","IN","INTERFACE","IMPLEMENTATION",
"END","PROPERTY","READONLY","READWRITE","SELF","SUPER","ID","CLASS","RETURN",
"INTEGER_CONSTANT","STRING_CONSTANT","CHAR_CONSTANT","FLOAT_CONSTANT","NSSTRING_CONSTANT",
"IDENTIFIER","ELIPSIS","';'","','","'&'","':'","'{'","'}'","program","type",
"numeric_constant","literal","declaration","declaration_list","declaration_list_e",
"init_declarator_list_e","init_declarator_list","init_declarator","parameter_type_list",
"parameter_list","parameter_declaration","expression","expression_e","message_expression",
"receiver","message_selector","keyword_argument_list","keyword_argument","if_statement",
"while_statement","do_while_statement","for_statement","statement","compound_statement",
"statement_list","statement_list_e","class_statement","class_statement_list",
"class_interface","interface_statement","implementation_statement","class_implementation",
"class_declaration_list","class_list","instance_variables","interface_declaration_list",
"method_declaration","class_method_declaration","instance_method_declaration",
"implementation_definition_list","method_definition","class_method_definition",
"instance_method_definition","method_selector","keyword_selector","keyword_declaration",
"method_type","property","attribute",""
};
#endif

static const short yyr1[] = {     0,
    57,    57,    57,    57,    58,    58,    58,    58,    58,    59,
    59,    60,    60,    60,    61,    62,    62,    63,    63,    64,
    64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
    69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
    70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
    70,    71,    71,    72,    73,    73,    73,    74,    74,    75,
    75,    76,    76,    77,    77,    78,    79,    80,    80,    80,
    81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
    83,    83,    84,    84,    85,    85,    86,    86,    87,    87,
    88,    88,    89,    89,    90,    90,    91,    92,    92,    93,
    93,    94,    94,    94,    94,    94,    94,    95,    95,    96,
    96,    96,    97,    97,    97,    98,    98,    98,    98,    98,
    98,    99,    99,   100,   100,   100,   101,   101,   101,   102,
   102,   102,   103,   103,   104,   104,   104,   104,   105,   106,
   107,   107
};

static const short yyr2[] = {     0,
     1,     1,     2,     2,     1,     1,     1,     1,     2,     1,
     1,     1,     1,     1,     3,     1,     2,     0,     1,     0,
     1,     1,     3,     1,     3,     1,     3,     1,     3,     2,
     2,     1,     1,     1,     3,     1,     1,     2,     2,     2,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     0,     1,     4,     1,     1,     1,     1,     1,     1,
     2,     3,     2,     5,     7,     5,     7,     9,     7,     8,
     1,     2,     1,     1,     1,     1,     1,     1,     1,     3,
     1,     2,     0,     1,     1,     1,     1,     2,     6,     4,
     2,     1,     2,     1,     4,     6,     3,     1,     3,     3,
     4,     1,     1,     1,     2,     2,     2,     1,     1,     4,
     6,     3,     4,     6,     3,     1,     1,     1,     2,     2,
     2,     1,     1,     5,     7,     4,     5,     7,     4,     1,
     1,     3,     1,     2,     3,     2,     4,     3,     3,     7,
     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     5,     6,     7,     0,     0,     0,
     0,     0,     0,     0,    36,     8,     0,    11,    12,    13,
    10,    14,    32,    71,     0,    83,    20,    34,    33,    78,
     0,    37,    73,    74,    75,    76,    81,    77,     1,    87,
     2,    85,    86,    79,    39,    38,     0,    57,    56,    55,
     0,     9,     0,     0,     0,    52,     0,     0,    98,     0,
    40,    84,     0,    24,     0,    21,    22,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    72,    82,
     3,     4,    88,    35,    58,     0,     0,    59,    60,     0,
     0,     0,    32,     0,    53,     0,     0,     0,     0,     0,
     0,   102,     0,     0,    92,   104,   108,   109,   103,     0,
     0,     0,   116,     0,     0,    94,   118,   122,   123,   117,
    97,     0,    80,     0,    15,     0,    51,    45,    46,    48,
    47,    49,    50,    41,    42,    43,    44,     0,    63,    54,
     0,    61,     0,     0,     0,     0,     0,    52,     0,   130,
     0,     0,   131,   133,     0,     0,     0,     0,     0,     0,
    16,     0,    90,    91,   105,   106,   107,     0,    18,     0,
     0,    18,     0,     0,    95,    93,   119,   120,   121,    99,
    25,    23,    62,    64,    66,     0,     0,     0,     0,     0,
     0,     0,     0,   136,     0,   112,     0,     0,   134,     0,
     0,   115,     0,   141,   142,     0,     0,   100,    17,     0,
     0,    19,     0,    18,     0,     0,    18,     0,     0,     0,
     0,     0,    52,     0,   139,   138,     0,   135,     0,     0,
   132,    26,    28,   110,     0,   113,     0,    89,   101,     0,
   126,     0,     0,   129,     0,    96,    65,    67,    69,     0,
     0,     0,   137,    31,    30,     0,     0,     0,    18,   124,
    18,   127,    70,     0,   111,    27,    29,   114,     0,     0,
     0,    68,   140,   125,   128,     0,     0,     0
};

static const short yydefgoto[] = {   276,
    27,    28,    29,    30,   212,   213,    65,    66,    67,   231,
   232,   233,    31,    96,    32,    51,    87,    88,    89,    33,
    34,    35,    36,    37,    38,    39,    63,    40,    41,    42,
   103,   114,    43,    44,    60,   104,   105,   106,   107,   108,
   116,   117,   118,   119,   152,   153,   154,   155,   109,   206
};

static const short yypact[] = {   227,
   365,   365,   365,     0,-32768,-32768,-32768,     3,    36,    50,
   273,    52,   -23,    34,-32768,-32768,    45,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   365,   273,    49,-32768,-32768,-32768,
   208,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   227,-32768,
   227,-32768,-32768,-32768,-32768,-32768,   473,-32768,-32768,-32768,
   -33,-32768,   365,   365,    72,   346,   168,   319,-32768,   -38,
-32768,   273,    46,   109,    65,    75,-32768,   365,   365,   365,
   365,   365,   365,   365,   365,   365,   365,   365,-32768,-32768,
    53,   273,-32768,-32768,    76,   365,   117,    82,-32768,   489,
   505,   124,   111,   102,   569,    96,     7,    80,   138,   121,
    98,-32768,   136,   405,   405,-32768,-32768,-32768,-32768,   105,
   108,   125,-32768,   140,   411,   411,-32768,-32768,-32768,-32768,
-32768,   127,-32768,   365,-32768,    49,   569,   455,   455,   252,
   252,   252,   252,    25,    25,-32768,-32768,   365,   569,-32768,
    76,-32768,   273,   273,   365,   365,   149,   365,   210,   128,
    10,   132,    59,-32768,   119,   417,   135,   119,     6,     9,
-32768,   144,-32768,   405,-32768,-32768,-32768,   428,    98,   119,
   434,    98,   119,   325,-32768,   411,-32768,-32768,-32768,-32768,
   569,-32768,   569,   159,-32768,   521,   537,   365,   137,   176,
   177,    19,    98,-32768,   148,-32768,   128,   356,-32768,   151,
   187,-32768,   155,-32768,-32768,   189,   190,-32768,-32768,   170,
   206,    98,   173,    98,   211,   173,    98,   195,   273,   183,
   273,   553,   365,   119,-32768,-32768,   191,-32768,     5,   192,
-32768,   203,-32768,-32768,   119,-32768,    98,-32768,-32768,   119,
-32768,   173,   119,-32768,   173,-32768,-32768,-32768,-32768,   273,
   224,   196,-32768,-32768,-32768,   266,   216,   221,    98,-32768,
    98,-32768,-32768,   273,-32768,-32768,-32768,-32768,   226,   173,
   173,-32768,-32768,-32768,-32768,   279,   281,-32768
};

static const short yypgoto[] = {-32768,
   -53,-32768,-32768,   -16,   184,  -168,-32768,-32768,   160,-32768,
-32768,    37,     4,  -139,-32768,-32768,-32768,-32768,   209,-32768,
-32768,-32768,-32768,   -11,  -107,    -8,-32768,   -29,   260,-32768,
   141,   131,-32768,-32768,-32768,   -57,   202,   -94,-32768,-32768,
   193,  -114,-32768,-32768,   -63,-32768,   156,   -88,   -50,-32768
};


#define	YYLAST		582


static const short yytable[] = {    55,
   115,   178,    94,   216,    45,    46,    47,   120,   189,   158,
   166,    83,   121,   122,    52,    85,    52,    62,    97,    98,
    86,   170,   173,   149,    48,    57,   193,    80,    61,     5,
     6,     7,    82,     8,   157,   193,    77,    78,    49,    50,
   102,   113,   204,   205,    99,   242,   169,   172,   245,    16,
    80,    83,    53,   254,   167,   150,    90,    91,   194,    95,
   151,   178,   195,   101,   120,   179,    54,   226,    56,   166,
    80,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,    58,   251,   161,    13,    14,   102,   165,   139,
   270,   200,   271,    59,   203,   191,   156,    64,   113,   177,
    92,   123,   191,   227,   210,   241,   214,   197,   244,   217,
   198,   124,   151,   167,   191,   125,   115,   191,     5,     6,
     7,   168,     8,   120,   171,   179,   126,   181,   150,   138,
   141,   184,   185,   151,   260,    86,   140,   262,    16,   191,
   145,   183,   146,   102,   230,   209,   148,   165,   186,   187,
   147,    95,   161,   150,   159,   161,   150,   113,   151,   177,
   252,   151,   274,   275,     5,     6,     7,   150,     8,   160,
   163,   257,   151,   174,   175,   180,   259,    97,    98,   261,
   188,   192,   196,   258,    16,   202,   219,   223,     5,     6,
     7,   222,     8,   224,   225,   209,   228,   161,   101,   208,
   161,   234,   230,    99,   235,   236,   237,   247,    16,   249,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,   100,   101,   240,   238,   239,    95,    26,   243,   246,
     5,     6,     7,   248,     8,   190,     1,     2,   263,   253,
   255,   264,   161,     3,   161,     4,   265,     5,     6,     7,
    16,     8,   272,     9,   256,    10,    11,    12,    79,    13,
    14,    75,    76,    77,    78,    15,   268,    16,    17,   269,
    18,    19,    20,    21,    22,    23,   273,    24,   277,    25,
   278,    26,     1,     2,   162,   182,     5,     6,     7,     3,
   229,     4,   267,     5,     6,     7,   142,     8,    81,     9,
   207,    10,    11,    12,   218,   164,    16,   176,   199,     0,
     0,    15,     0,    16,    17,   266,    18,    19,    20,    21,
    22,    23,     0,    24,     0,    25,     0,    26,   110,   111,
     0,     0,     0,     0,   110,   111,     0,     0,     0,     5,
     6,     7,     0,     8,     0,     5,     6,     7,     0,     8,
     0,     0,     0,     0,    99,     1,     2,     0,     0,    16,
    99,     0,     3,     0,     4,    16,     5,     6,     7,     0,
     8,     0,   112,   101,     1,     2,     5,     6,     7,   101,
   229,     3,     0,     4,    15,     0,    16,     0,     0,    18,
    19,    20,    21,    22,    93,     0,    16,     0,    25,     0,
     0,     0,     0,    15,     0,     0,     0,     0,    18,    19,
    20,    21,    22,    23,    97,    98,     0,    25,     0,     0,
   110,   111,     0,     0,     0,     5,     6,     7,     0,     8,
     0,     5,     6,     7,     0,     8,     0,     5,     6,     7,
    99,     8,   201,     0,     0,    16,    99,     0,     5,     6,
     7,    16,     8,   211,     5,     6,     7,    16,     8,   215,
    71,    72,    73,    74,    75,    76,    77,    78,    16,     0,
     0,     0,     0,     0,    16,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,     0,     0,     0,     0,
    84,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,     0,     0,     0,     0,   143,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,     0,     0,
     0,     0,   144,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,     0,     0,     0,     0,   220,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
     0,     0,     0,     0,   221,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,     0,     0,     0,     0,
   250,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78
};

static const short yycheck[] = {    11,
    58,   116,    56,   172,     1,     2,     3,    58,   148,    98,
   105,    41,    51,    52,    12,    49,    12,    26,    10,    11,
    54,   110,   111,    17,    25,    49,    17,    39,    25,    21,
    22,    23,    41,    25,    98,    17,    12,    13,    39,    40,
    57,    58,    37,    38,    36,   214,   110,   111,   217,    41,
    62,    81,    17,    49,   105,    49,    53,    54,    49,    56,
    54,   176,   151,    55,   115,   116,    17,    49,    17,   164,
    82,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    49,   223,   101,    33,    34,   104,   105,    86,
   259,   155,   261,    49,   158,   149,    17,    49,   115,   116,
    29,    56,   156,   192,   162,   213,   170,    49,   216,   173,
    52,     3,    54,   164,   168,    51,   174,   171,    21,    22,
    23,    17,    25,   174,    17,   176,    52,   124,    49,    54,
    49,   143,   144,    54,   242,    54,    20,   245,    41,   193,
    17,   138,    32,   160,   198,   162,    51,   164,   145,   146,
    49,   148,   169,    49,    17,   172,    49,   174,    54,   176,
   224,    54,   270,   271,    21,    22,    23,    49,    25,    49,
    35,   235,    54,    49,    35,    49,   240,    10,    11,   243,
    32,    54,    51,   237,    41,    51,    28,    51,    21,    22,
    23,   188,    25,    18,    18,   212,    49,   214,    55,    56,
   217,    51,   256,    36,    18,    51,    18,   219,    41,   221,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    54,    55,    18,    35,    56,   223,    55,    18,    35,
    21,    22,    23,    51,    25,    26,    10,    11,   250,    49,
    49,    18,   259,    17,   261,    19,    51,    21,    22,    23,
    41,    25,   264,    27,    52,    29,    30,    31,    51,    33,
    34,    10,    11,    12,    13,    39,    51,    41,    42,    49,
    44,    45,    46,    47,    48,    49,    51,    51,     0,    53,
     0,    55,    10,    11,   101,   126,    21,    22,    23,    17,
    25,    19,   256,    21,    22,    23,    88,    25,    39,    27,
   160,    29,    30,    31,   174,   104,    41,   115,   153,    -1,
    -1,    39,    -1,    41,    42,    50,    44,    45,    46,    47,
    48,    49,    -1,    51,    -1,    53,    -1,    55,    10,    11,
    -1,    -1,    -1,    -1,    10,    11,    -1,    -1,    -1,    21,
    22,    23,    -1,    25,    -1,    21,    22,    23,    -1,    25,
    -1,    -1,    -1,    -1,    36,    10,    11,    -1,    -1,    41,
    36,    -1,    17,    -1,    19,    41,    21,    22,    23,    -1,
    25,    -1,    54,    55,    10,    11,    21,    22,    23,    55,
    25,    17,    -1,    19,    39,    -1,    41,    -1,    -1,    44,
    45,    46,    47,    48,    49,    -1,    41,    -1,    53,    -1,
    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,
    46,    47,    48,    49,    10,    11,    -1,    53,    -1,    -1,
    10,    11,    -1,    -1,    -1,    21,    22,    23,    -1,    25,
    -1,    21,    22,    23,    -1,    25,    -1,    21,    22,    23,
    36,    25,    26,    -1,    -1,    41,    36,    -1,    21,    22,
    23,    41,    25,    26,    21,    22,    23,    41,    25,    26,
     6,     7,     8,     9,    10,    11,    12,    13,    41,    -1,
    -1,    -1,    -1,    -1,    41,     3,     4,     5,     6,     7,
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
#line 284 "bizon_rules.y"

