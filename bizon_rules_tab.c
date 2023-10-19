
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



#define	YYFINAL		295
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
   228,   230,   233,   237,   239,   241,   243,   245,   247,   249,
   251,   255,   257,   260,   261,   263,   265,   267,   269,   272,
   279,   284,   291,   294,   296,   299,   301,   306,   313,   318,
   325,   332,   339,   343,   345,   349,   353,   355,   357,   359,
   362,   365,   368,   370,   372,   377,   384,   388,   393,   400,
   404,   406,   408,   410,   413,   416,   419,   421,   423,   429,
   437,   442,   448,   456,   461,   463,   465,   469,   471,   474,
   478,   481,   486,   490,   494,   502,   504
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
    51,     0,    43,    71,    51,     0,    77,     0,    78,     0,
    79,     0,    80,     0,    82,     0,    61,     0,    91,     0,
    55,    84,    56,     0,    81,     0,    83,    81,     0,     0,
    83,     0,    87,     0,    90,     0,    85,     0,    86,    85,
     0,    33,    49,    54,    49,    88,    35,     0,    33,    49,
    88,    35,     0,    33,    49,    54,    25,    88,    35,     0,
    93,    94,     0,    94,     0,    93,    98,     0,    98,     0,
    34,    49,    89,    35,     0,    34,    49,    54,    49,    89,
    35,     0,    34,    25,    89,    35,     0,    34,    25,    54,
    49,    89,    35,     0,    34,    49,    54,    25,    89,    35,
     0,    34,    25,    54,    25,    89,    35,     0,    42,    92,
    51,     0,    49,     0,    92,    52,    49,     0,    55,    62,
    56,     0,    61,     0,   106,     0,    95,     0,    94,    61,
     0,    94,    95,     0,    94,   106,     0,    96,     0,    97,
     0,    10,   105,   102,    51,     0,    10,    17,    26,    18,
   102,    51,     0,    10,   102,    51,     0,    11,   105,   102,
    51,     0,    11,    17,    26,    18,   102,    51,     0,    11,
   102,    51,     0,    61,     0,   106,     0,    99,     0,    98,
    61,     0,    98,    99,     0,    98,   106,     0,   100,     0,
   101,     0,    10,   105,   102,    63,    82,     0,    10,    17,
    26,    18,   102,    63,    82,     0,    10,   102,    63,    82,
     0,    11,   105,   102,    63,    82,     0,    11,    17,    26,
    18,   102,    63,    82,     0,    11,   102,    63,    82,     0,
    49,     0,   103,     0,   103,    52,    67,     0,   104,     0,
   103,   104,     0,    54,   105,    49,     0,    54,    49,     0,
    49,    54,   105,    49,     0,    49,    54,    49,     0,    17,
    58,    18,     0,    36,    17,   107,    18,    58,    49,    51,
     0,    37,     0,    38,     0
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
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   168,   171,   172,   175,   176,   179,   180,   183,   184,   188,
   189,   190,   193,   194,   197,   198,   201,   202,   203,   204,
   205,   206,   209,   212,   213,   216,   220,   221,   222,   223,
   224,   225,   228,   229,   232,   233,   234,   237,   238,   239,
   242,   243,   244,   245,   246,   247,   250,   251,   254,   255,
   256,   259,   260,   261,   264,   265,   266,   269,   270,   273,
   274,   275,   276,   279,   282,   285,   286
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
    81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
    82,    83,    83,    84,    84,    85,    85,    86,    86,    87,
    87,    87,    88,    88,    89,    89,    90,    90,    90,    90,
    90,    90,    91,    92,    92,    93,    94,    94,    94,    94,
    94,    94,    95,    95,    96,    96,    96,    97,    97,    97,
    98,    98,    98,    98,    98,    98,    99,    99,   100,   100,
   100,   101,   101,   101,   102,   102,   102,   103,   103,   104,
   104,   104,   104,   105,   106,   107,   107
};

static const short yyr2[] = {     0,
     1,     1,     2,     2,     1,     1,     1,     1,     2,     1,
     1,     1,     1,     1,     3,     1,     2,     0,     1,     0,
     1,     1,     3,     1,     3,     1,     3,     1,     3,     2,
     2,     1,     1,     1,     3,     1,     1,     2,     2,     2,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     0,     1,     4,     1,     1,     1,     1,     1,     1,
     2,     3,     2,     5,     7,     5,     7,     9,     7,     8,
     1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
     3,     1,     2,     0,     1,     1,     1,     1,     2,     6,
     4,     6,     2,     1,     2,     1,     4,     6,     4,     6,
     6,     6,     3,     1,     3,     3,     1,     1,     1,     2,
     2,     2,     1,     1,     4,     6,     3,     4,     6,     3,
     1,     1,     1,     2,     2,     2,     1,     1,     5,     7,
     4,     5,     7,     4,     1,     1,     3,     1,     2,     3,
     2,     4,     3,     3,     7,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     5,     6,     7,     0,     0,     0,
     0,     0,     0,     0,    36,     8,     0,    52,    11,    12,
    13,    10,    14,    32,    71,     0,    84,    20,    34,    33,
    79,     0,    37,    74,    75,    76,    77,    82,    78,     1,
    88,     2,    86,    87,    80,    39,    38,     0,    57,    56,
    55,     0,     9,     0,     0,     0,    52,     0,     0,     0,
   104,     0,    53,     0,    40,    85,     0,    24,     0,    21,
    22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    72,    83,     3,     4,    89,    35,    58,     0,
     0,    59,    60,     0,     0,     0,    32,     0,     0,     0,
     0,     0,     0,     0,   107,     0,     0,    94,   109,   113,
   114,   108,     0,     0,     0,   121,     0,     0,    96,   123,
   127,   128,   122,     0,     0,   103,     0,    73,    81,     0,
    15,     0,    51,    45,    46,    48,    47,    49,    50,    41,
    42,    43,    44,     0,    63,    54,     0,    61,     0,     0,
     0,     0,     0,    52,     0,   135,     0,     0,   136,   138,
     0,     0,     0,     0,     0,     0,     0,    16,     0,    91,
    93,   110,   111,   112,     0,    18,     0,     0,    18,     0,
     0,     0,    99,    95,   124,   125,   126,     0,     0,    97,
   105,    25,    23,    62,    64,    66,     0,     0,     0,     0,
     0,     0,     0,     0,   141,     0,   117,     0,     0,   139,
     0,     0,   120,     0,   146,   147,     0,     0,     0,   106,
    17,     0,    19,     0,    18,     0,     0,    18,     0,     0,
     0,     0,     0,     0,     0,     0,    52,     0,   144,   143,
     0,   140,     0,     0,   137,    26,    28,   115,     0,   118,
     0,    92,    90,     0,   131,     0,     0,   134,     0,   102,
   100,   101,    98,    65,    67,    69,     0,     0,     0,   142,
    31,    30,     0,     0,     0,    18,   129,    18,   132,    70,
     0,   116,    27,    29,   119,     0,     0,     0,    68,   145,
   130,   133,     0,     0,     0
};

static const short yydefgoto[] = {   293,
    28,    29,    30,    31,   223,   224,    69,    70,    71,   245,
   246,   247,    32,    64,    33,    52,    91,    92,    93,    34,
    35,    36,    37,    38,    39,    40,    67,    41,    42,    43,
   106,   117,    44,    45,    62,   118,   108,   109,   110,   111,
   119,   120,   121,   122,   158,   159,   160,   161,   123,   217
};

static const short yypact[] = {   252,
   429,   429,   429,   107,-32768,-32768,-32768,    15,    -4,    18,
   298,    39,   -16,   -13,-32768,-32768,    21,   429,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   429,   298,    24,-32768,-32768,
-32768,   189,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   252,
-32768,   252,-32768,-32768,-32768,-32768,-32768,   514,-32768,-32768,
-32768,   -30,-32768,   429,   429,    38,   413,   210,   344,   350,
-32768,    45,   610,    42,-32768,   298,    43,   126,    82,    83,
-32768,   429,   429,   429,   429,   429,   429,   429,   429,   429,
   429,   429,-32768,-32768,   109,   298,-32768,-32768,   103,   429,
   117,   -23,-32768,   530,   546,   162,   152,   137,   136,    -3,
    -2,   172,    -9,   396,-32768,   155,   469,   469,-32768,-32768,
-32768,-32768,    17,    20,    13,-32768,   169,   475,   475,-32768,
-32768,-32768,-32768,    14,   170,-32768,   158,-32768,-32768,   429,
-32768,    24,   610,   618,   618,   277,   277,   277,   277,   148,
   148,-32768,-32768,   429,   610,-32768,   103,-32768,   298,   298,
   429,   429,   177,   429,   193,   156,     0,   161,   114,-32768,
    73,   204,   185,    73,   139,   367,   367,-32768,    84,-32768,
   469,-32768,-32768,-32768,   227,   396,    73,   309,   396,    73,
   390,   390,-32768,   475,-32768,-32768,-32768,   390,   390,-32768,
-32768,   610,-32768,   610,   195,-32768,   562,   578,   429,   186,
   220,   224,     1,   396,-32768,   164,-32768,   156,   428,-32768,
   192,   226,-32768,   196,-32768,-32768,   236,   222,   223,-32768,
-32768,   237,   396,   173,   396,   242,   173,   396,   231,   232,
   241,   243,   298,   221,   298,   594,   429,    73,-32768,-32768,
   235,-32768,    -1,   253,-32768,   228,-32768,-32768,    73,-32768,
   396,-32768,-32768,    73,-32768,   173,    73,-32768,   173,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   298,   274,   255,-32768,
-32768,-32768,    95,   259,   262,   396,-32768,   396,-32768,-32768,
   298,-32768,-32768,-32768,-32768,   261,   173,   173,-32768,-32768,
-32768,-32768,   304,   313,-32768
};

static const short yypgoto[] = {-32768,
   -34,-32768,-32768,   -17,   212,  -125,-32768,-32768,   182,-32768,
-32768,    49,     4,   -56,-32768,-32768,-32768,-32768,   234,-32768,
-32768,-32768,-32768,   -11,  -199,    77,-32768,   -32,   278,-32768,
    16,   -58,-32768,-32768,-32768,   -54,   217,   -99,-32768,-32768,
   215,  -116,-32768,-32768,   -69,-32768,   179,   -93,     7,-32768
};


#define	YYLAST		631


static const short yytable[] = {    56,
    99,   125,   186,   107,    46,    47,    48,   164,   173,    87,
    53,    59,    54,   155,   162,   166,   204,   204,    89,   177,
   180,    63,    98,    90,   255,   147,    53,   258,    84,    65,
    90,   163,    58,   175,    55,    60,   178,   181,   188,   167,
   105,   116,   116,   176,   179,   156,   156,   271,   205,   240,
   157,   157,    87,   227,    84,    57,   277,    94,    95,   279,
    63,   182,   189,   206,   112,   156,    96,   186,   156,    61,
   157,   173,    68,   157,    84,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   168,   291,   292,   105,
   172,   211,   128,   145,   214,   126,   127,   200,   129,   256,
   116,   185,   259,    66,     5,     6,     7,   225,     8,   241,
   228,   107,   107,   112,   174,     5,     6,     7,    86,   243,
   202,   156,   229,   230,    16,   187,   157,   202,   130,   231,
   232,    49,   131,   192,   132,    16,   146,   195,   196,   220,
   202,    13,    14,   202,   283,    50,    51,   194,   105,   105,
   287,   221,   288,   172,   197,   198,   144,    63,   168,    81,
    82,   168,   208,   116,   116,   209,   185,   157,   269,   202,
   116,   116,   112,   112,   244,   215,   216,   174,   151,   274,
   268,   218,   219,   152,   276,   153,   154,   278,   165,   170,
   187,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,   236,   183,   190,   221,   191,   168,   199,   203,
   168,   207,   242,     5,     6,     7,   275,     8,   201,   100,
   101,   264,   233,   266,     5,     6,     7,    27,     8,   212,
     5,     6,     7,    16,     8,   213,   237,   238,   244,    83,
    63,   239,   248,   249,    16,   102,   250,     5,     6,     7,
    16,     8,   222,   251,   254,   280,   252,   253,   168,   257,
   168,     1,     2,   103,   104,   260,   261,    16,     3,   289,
     4,   265,     5,     6,     7,   262,     8,   263,     9,   273,
    10,    11,    12,   270,    13,    14,    79,    80,    81,    82,
    15,   281,    16,    17,    18,    19,    20,    21,    22,    23,
    24,   272,    25,   294,    26,   282,    27,     1,     2,   285,
   286,   290,   295,   193,     3,   169,     4,    85,     5,     6,
     7,   284,     8,   171,     9,   148,    10,    11,    12,     5,
     6,     7,   184,     8,   226,     0,    15,   210,    16,    17,
    18,    19,    20,    21,    22,    23,    24,     0,    25,    16,
    26,     0,    27,   113,   114,     0,     0,     0,     0,   113,
   114,     0,     0,     0,     5,     6,     7,     0,     8,     0,
     5,     6,     7,     0,     8,     0,   100,   101,     0,   102,
     0,     0,     0,     0,    16,   102,     0,     5,     6,     7,
    16,     8,     0,     0,     0,     0,     0,   115,   104,   113,
   114,     0,   102,   124,   104,     0,     0,    16,     0,     0,
     5,     6,     7,     0,     8,     0,     5,     6,     7,     0,
     8,   104,     1,     2,     0,   102,     0,     0,     0,     3,
    16,     4,     0,     5,     6,     7,    16,     8,     1,     2,
     0,     0,     0,     0,   104,     3,     0,     4,     5,     6,
     7,    15,   243,    16,     0,     0,    19,    20,    21,    22,
    23,    97,     0,     0,     0,    26,     0,    15,    16,     0,
     0,     0,    19,    20,    21,    22,    23,    24,   100,   101,
     0,    26,     0,     0,   113,   114,     0,     0,     0,     5,
     6,     7,     0,     8,     0,     5,     6,     7,     0,     8,
     0,     0,     0,     0,   102,     0,     0,     0,     0,    16,
   102,     0,     0,     0,     0,    16,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,     0,     0,     0,
     0,    88,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,     0,     0,     0,     0,   149,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
     0,     0,     0,   150,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,     0,     0,     0,     0,   234,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,     0,     0,     0,     0,   235,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,     0,     0,     0,
     0,   267,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    75,    76,    77,    78,    79,    80,    81,
    82
};

static const short yycheck[] = {    11,
    57,    60,   119,    58,     1,     2,     3,   101,   108,    42,
    12,    25,    17,    17,    17,    25,    17,    17,    49,   113,
   114,    18,    57,    54,   224,    49,    12,   227,    40,    26,
    54,   101,    49,    17,    17,    49,    17,    25,    25,    49,
    58,    59,    60,   113,   114,    49,    49,    49,    49,    49,
    54,    54,    85,   179,    66,    17,   256,    54,    55,   259,
    57,    49,    49,   157,    58,    49,    29,   184,    49,    49,
    54,   171,    49,    54,    86,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,   104,   287,   288,   107,
   108,   161,    51,    90,   164,    51,    52,   154,    56,   225,
   118,   119,   228,    27,    21,    22,    23,   177,    25,   203,
   180,   166,   167,   107,   108,    21,    22,    23,    42,    25,
   155,    49,   181,   182,    41,   119,    54,   162,     3,   188,
   189,    25,    51,   130,    52,    41,    20,   149,   150,    56,
   175,    33,    34,   178,    50,    39,    40,   144,   166,   167,
   276,   169,   278,   171,   151,   152,    54,   154,   176,    12,
    13,   179,    49,   181,   182,    52,   184,    54,   238,   204,
   188,   189,   166,   167,   209,    37,    38,   171,    17,   249,
   237,   166,   167,    32,   254,    49,    51,   257,    17,    35,
   184,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    13,   199,    35,    35,   223,    49,   225,    32,    54,
   228,    51,    49,    21,    22,    23,   251,    25,    26,    10,
    11,   233,    28,   235,    21,    22,    23,    55,    25,    26,
    21,    22,    23,    41,    25,    51,    51,    18,   273,    51,
   237,    18,    51,    18,    41,    36,    51,    21,    22,    23,
    41,    25,    26,    18,    18,   267,    35,    35,   276,    18,
   278,    10,    11,    54,    55,    35,    35,    41,    17,   281,
    19,    51,    21,    22,    23,    35,    25,    35,    27,    52,
    29,    30,    31,    49,    33,    34,    10,    11,    12,    13,
    39,    18,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    49,    51,     0,    53,    51,    55,    10,    11,    51,
    49,    51,     0,   132,    17,   104,    19,    40,    21,    22,
    23,   273,    25,   107,    27,    92,    29,    30,    31,    21,
    22,    23,   118,    25,    26,    -1,    39,   159,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    -1,    51,    41,
    53,    -1,    55,    10,    11,    -1,    -1,    -1,    -1,    10,
    11,    -1,    -1,    -1,    21,    22,    23,    -1,    25,    -1,
    21,    22,    23,    -1,    25,    -1,    10,    11,    -1,    36,
    -1,    -1,    -1,    -1,    41,    36,    -1,    21,    22,    23,
    41,    25,    -1,    -1,    -1,    -1,    -1,    54,    55,    10,
    11,    -1,    36,    54,    55,    -1,    -1,    41,    -1,    -1,
    21,    22,    23,    -1,    25,    -1,    21,    22,    23,    -1,
    25,    55,    10,    11,    -1,    36,    -1,    -1,    -1,    17,
    41,    19,    -1,    21,    22,    23,    41,    25,    10,    11,
    -1,    -1,    -1,    -1,    55,    17,    -1,    19,    21,    22,
    23,    39,    25,    41,    -1,    -1,    44,    45,    46,    47,
    48,    49,    -1,    -1,    -1,    53,    -1,    39,    41,    -1,
    -1,    -1,    44,    45,    46,    47,    48,    49,    10,    11,
    -1,    53,    -1,    -1,    10,    11,    -1,    -1,    -1,    21,
    22,    23,    -1,    25,    -1,    21,    22,    23,    -1,    25,
    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,
    36,    -1,    -1,    -1,    -1,    41,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
    -1,    18,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    -1,    -1,    -1,    -1,    18,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
    -1,    -1,    -1,    18,     3,     4,     5,     6,     7,     8,
     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    -1,    -1,    -1,    -1,    18,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
    -1,    18,     3,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,     6,     7,     8,     9,    10,    11,    12,
    13
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
#line 289 "bizon_rules.y"

