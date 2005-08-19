#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 76 "yacc.txt"

#define _MACHINE_UNIT(_func, _params) \
	{ \
		MACHINE_UNIT mu; \
		mu.func = _func; \
		mu.params = _params; \
		mu.udt = UDT_FUNC; \
		CProgram::m_pyyUnits->push_back(mu); \
	}

#define _END_LINE CProgram::m_pyyUnits->back().udt = UNIT_DATA_TYPE(CProgram::m_pyyUnits->back().udt | UDT_LINE)

#define _FOUND_PARAM ++CProgram::m_params.back()

#line 36 "y.tab.c"
#define MUL_ASSIGN 257
#define DIV_ASSIGN 258
#define MOD_ASSIGN 259
#define ADD_ASSIGN 260
#define SUB_ASSIGN 261
#define LS_ASSIGN 262
#define RS_ASSIGN 263
#define AND_ASSIGN 264
#define OR_ASSIGN 265
#define POW_ASSIGN 266
#define XOR_ASSIGN 267
#define EQ 268
#define IEQ 269
#define MEM 270
#define MUL 271
#define ADD 272
#define SUB 273
#define NOT 274
#define BNOT 275
#define DIV 276
#define MOD 277
#define LS 278
#define RS 279
#define LTE 280
#define GTE 281
#define LT 282
#define GT 283
#define AND 284
#define POW 285
#define XOR 286
#define OR 287
#define LAND 288
#define LOR 289
#define ASSIGN 290
#define INC 291
#define DEC 292
#define SEMICOLON 293
#define IDENTIFIER 294
#define NUMBER 295
#define STRING 296
#define LPARAN 297
#define RPARAN 298
#define LARRAY 299
#define RARRAY 300
#define LCURL 301
#define RCURL 302
#define LIT 303
#define FOR 304
#define COMMA 305
#define QUESTION 306
#define COLON 307
#define METHOD 308
#define RETURN 309
#define HIGHEST 310
#define CLASS 311
#define STRUCT 312
#define PUBLIC 313
#define PRIVATE 314
#define VAR 315
#define DOT 316
#define INCLUDE 317
#define CONDITIONAL 318
#define NEG 319
#define PREF_DEC 320
#define PREF_INC 321
#define POST_DEC 322
#define POST_INC 323
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    1,    1,    1,    2,    4,    4,    4,    4,    4,    4,
    5,    5,    7,    7,    7,    7,    9,    9,    9,    3,
    3,   10,    6,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,   12,   12,   12,   13,
   13,   14,   15,   16,   16,   16,   17,   17,   17,   19,
   20,   18,   21,   21,   22,   22,   24,   25,   26,   23,
   27,   28,   29,   29,   30,   30,   31,   31,   33,   32,
   34,   35,   35,   36,   37,   37,   38,   38,   38,   38,
   38,   38,   38,   38,   38,   39,   39,    0,    0,
};
short yylen[] = {                                         2,
    1,    1,    0,    2,    1,    5,    3,    3,    3,    1,
    1,    1,    3,    1,    1,    1,    3,    1,    0,    1,
    3,    0,    5,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    2,    2,
    2,    2,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    5,    1,    1,    1,    2,
    1,    1,    2,    3,    1,    0,    1,    4,    2,    0,
    0,    7,    1,    0,    1,    0,    0,    0,    0,   11,
    2,    1,    3,    1,    2,    0,    1,    1,    0,    4,
    2,    3,    1,    2,    2,    4,    1,    1,    1,    1,
    2,    2,    1,    1,    1,    2,    3,    0,    2,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,   97,    0,   15,   16,    0,   98,
   99,    0,    0,    0,  127,  128,    0,    0,    0,    0,
    0,    5,    0,    0,    0,   10,   11,   14,    0,    0,
  138,  144,  137,    0,  139,  140,  143,    0,    0,   63,
   64,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  142,  141,    0,    0,  134,  135,    0,    2,    1,
    4,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   60,   62,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  100,    0,
  129,  102,  146,  149,   21,    7,   13,    0,  117,    0,
   33,   32,   31,   30,   29,   28,   27,   26,   25,   34,
   24,   42,   41,   53,   50,   49,   55,   52,   51,   48,
   47,   44,   43,   46,   45,   40,   54,   39,   38,   37,
   36,   35,   57,   58,  110,   56,  109,  131,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    9,    8,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  147,    0,    0,    0,
    0,  132,  136,    0,    0,    0,    0,    0,  130,    0,
    0,    0,    0,  111,    0,   23,    6,    0,  122,    0,
  125,    0,    0,  103,    0,    0,   17,    0,  118,  104,
  112,  123,    0,  119,    0,  120,
};
short yydgoto[] = {                                      21,
   61,   22,   23,   24,   25,   26,   27,   28,  195,   62,
  147,   29,   30,  103,  203,  204,   50,   31,  191,  216,
  109,  213,   32,  189,  223,  225,   33,  210,  211,  199,
   34,   35,  188,   55,   56,   36,   37,   38,   39,
};
short yysindex[] = {                                   -266,
  -76,  -76,  -76,  -76,    0, -303,    0,    0,  -76,    0,
    0, -282, -260,  -76,    0,    0, -267, -247, -233, -238,
    0,    0, -264,  257,  949,    0,    0,    0, -281,  185,
    0,    0,    0, -217,    0,    0,    0, -281, -266,    0,
    0,  257,  949,  257, -216,  246, -243,  -76, -225, -153,
  949,    0,    0, -264, -204,    0,    0, -194,    0,    0,
    0, -180,  -76,  -76,  -76,  -76,  -76,  -76,  -76,  -76,
  -76,  -76,  -76,  -76,    0,    0,  -76,  -76,  -76, -172,
  -76,  -76,  -76,  -76,  -76,  -76,  -76,  -76,  -76,  -76,
  -76,  -76,  -76,  -76,  -76,  -76,  -76,  -76,    0, -281,
    0,    0,    0,    0,    0,    0,    0,  949,    0, -162,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -233, -148,
  -76,  949,  949,  949,  949,  949,  949,  949,  949,  949,
  949,  949,  949,  879, 1265, 1249,    0,    0, -268, -130,
 1000, -248, -252,  622,  969,  899, 1281,  255, 1297, 1233,
 -116, 1215, 1177, 1136, 1094,  602,    0, -151, -132, -260,
 -113,    0,    0,  918, -102, -264,  -76,  -82,    0,  -76,
 -109, -264, -104,    0,  -76,    0,    0,  949,    0,  -92,
    0,  949,  -79,    0, -113,  -75,    0,  -82,    0,    0,
    0,    0,  -76,    0,  -59,    0,
};
short yyrindex[] = {                                    222,
    0,    0,    0,    0,    0,   62,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  113,  282, -239,    0,    0,    0,    1,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  222,    0,
    0,  322,    0,  362,    0,  980, 1011,  -49,  -31,    0,
 -150,    0,    0, -249, -144,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -284,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -36, 1285, 1295, 1305, 1315, 1325, 1335, 1345, 1355, 1365,
 1375, 1385, 1395,    0,  839, 1032,    0,    0,  442,  562,
  632,  482,  522,  667,  702,  786,  813,  730,  758,  -16,
  402, 1054, 1096, 1137, 1175,    0,    0,  -98,    0,    0,
  -35,    0,    0,  -34,    0,  164,    0,    0,    0,  -28,
  -73, -241,  -29,    0,  -36,    0,    0, 1405,    0,  -93,
    0,  -26,    0,    0,  -35,    0,    0,    0,    0,    0,
    0,    0,  -22,    0,    0,    0,
};
short yygindex[] = {                                    239,
  -54,  199,    0,  202,    2,  200,  272,    0,   78,    0,
    0,    0,    3,  187,    0,   79,  109,    0,    0,    0,
   77,    0,    0,    0,    0,    0,    0,    0,   83,    0,
    0,    0,    0,    0,  153,    0,    0,  273,    0,
};
#define YYTABLESIZE 1712
short yytable[] = {                                     148,
  101,   80,   40,   41,   43,   43,    1,    2,  113,   59,
   43,    5,   45,  113,   48,   51,   93,   80,   81,   10,
   11,   80,   81,   84,    3,    4,    5,    6,    7,    8,
    9,   99,   93,   49,   10,   11,   93,   12,   60,   52,
  102,   13,   14,    3,   15,   16,   17,   18,   19,  108,
   20,    3,    3,  145,  107,    3,    3,   57,   58,   53,
   54,  145,  145,    3,  152,  153,  154,  155,  156,  157,
  158,  159,  160,  161,  162,  163,  101,  105,  164,  165,
  166,  110,  169,  170,  171,  172,  173,  174,  175,  176,
  177,  178,  179,  180,  181,  182,  183,  184,  185,  186,
  149,  150,  102,  111,  112,  113,  114,  115,  116,  117,
  118,  119,  120,  121,  122,  123,  151,  124,  125,  126,
  127,    6,  128,  129,  130,  131,  132,  133,  134,  135,
  136,  137,  138,  139,  140,  141,  142,  143,  144,   80,
   81,  207,  121,  145,  190,   84,   85,  214,  133,  193,
  121,  121,  194,   80,   93,  198,  133,  133,  122,  123,
  200,  124,  125,  126,  127,  146,  128,  129,  130,  131,
  132,  133,  134,  135,  136,  137,  138,  139,  140,  141,
  202,  143,  144,  108,  108,  108,  108,  108,  108,  108,
  108,  108,  108,  108,  126,  206,    1,    2,  208,  124,
  215,  212,  126,  126,   42,   44,  194,  124,  124,  146,
   46,  209,  218,  219,    3,    4,  108,    6,    7,    8,
    9,  148,  221,  108,  108,  107,  107,  107,  107,  107,
  107,  107,  107,  107,  107,  107,  107,  107,  226,  107,
  107,  107,  107,  114,  107,  107,  107,  107,  107,  107,
  107,  107,  107,  107,  107,  107,  107,  107,  107,  107,
  107,   19,  106,   18,  116,  107,  115,   81,  105,   81,
   81,   81,   81,  101,  101,  114,   81,  104,  167,  168,
   47,   81,  217,   81,   81,   81,  187,  107,   81,   81,
   81,  101,  101,  220,  101,  101,  101,  101,  201,  224,
  222,  192,  100,    0,  101,    0,    0,    0,  101,  101,
    0,  101,  101,  101,  101,  101,    0,  101,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,    0,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,    0,    0,    0,   20,   20,
   20,   20,   20,   20,   20,    0,   20,   20,   20,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    0,    0,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    0,    0,    0,   22,
    3,    3,    3,    3,    3,    0,    0,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    0,    0,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    1,    2,    0,
    0,    3,    3,    3,    3,    3,    0,    0,    3,    3,
    3,    0,    0,    0,    0,    3,    4,    0,    6,    7,
    8,    9,    0,    0,    0,    0,    0,    0,   12,    0,
    0,    0,   13,   14,    0,   15,   16,   17,   18,   19,
    0,   20,   63,   64,   65,   66,   67,   68,   69,   70,
   71,   72,   73,   63,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   73,   80,   81,   82,   83,    0,    0,
   84,   85,   86,   87,    0,   74,   75,   76,    0,   93,
    0,    0,    0,  106,   77,    0,   74,   75,   76,   12,
   12,   12,   12,   12,   12,   77,    0,   12,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,    0,    0,    0,   12,    0,    0,    0,    0,   12,
    0,   12,   12,   12,    0,    0,   12,   12,   12,   12,
   12,   12,   12,   12,   12,    0,    0,   12,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,    0,    0,    0,   59,    0,    0,    0,    0,   59,
    0,   59,   59,   59,    0,    0,   59,   12,   59,   12,
   12,   12,   12,   12,   12,    0,    0,   12,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,    0,    0,    0,   61,    0,    0,    0,    0,   61,
    0,   61,   61,   61,    0,    0,   61,   12,   61,   95,
   95,    0,   95,   95,   95,    0,    0,   95,   95,   95,
   95,   95,   95,   95,   95,   95,   95,   95,   95,   95,
   95,    0,    0,    0,   95,    0,    0,    0,    0,   95,
    0,   95,   95,   95,    0,    0,   95,   95,   95,   94,
   94,    0,   94,   94,   94,    0,    0,   94,   94,   94,
   94,   94,   94,   94,   94,   94,    0,   94,   94,   94,
   94,    0,    0,    0,   94,    0,    0,    0,    0,   94,
    0,   94,   94,   94,    0,    0,   94,   94,   94,   93,
   93,    0,    0,   93,   93,    0,    0,   93,   93,   93,
   93,   93,   93,   93,   93,   93,    0,   93,   93,   93,
   93,    0,    0,    0,   93,    0,    0,    0,    0,   93,
    0,   93,   93,   93,    0,    0,   93,   93,   93,   92,
   92,    0,    0,   92,   92,    0,    0,    0,   92,   92,
   92,   92,   92,   92,   92,   92,    0,   92,   92,   92,
   92,    0,    0,    0,   92,    0,    0,    0,    0,   92,
    0,   92,   92,   92,    0,    0,   92,   92,   92,   91,
   91,    0,    0,   91,   91,    0,    0,    0,    0,   91,
   91,   91,   91,   91,   91,   91,    0,   91,   91,   91,
   91,    0,    0,    0,   91,    0,    0,    0,    0,   91,
    0,   91,   91,   91,    0,    0,   91,   91,   91,   78,
   79,   80,   81,   82,   83,    0,    0,   84,   85,   86,
   87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
   97,   80,   81,   82,   83,    0,    0,   84,   85,   90,
   90,    0,    0,    0,   90,    0,   93,   98,  197,   90,
   90,   90,   90,   90,   90,   90,    0,   90,   90,   90,
   90,    0,    0,    0,   90,    0,    0,    0,    0,   90,
    0,   90,   90,   90,   89,   89,   90,   90,   90,    0,
    0,    0,    0,    0,   89,   89,   89,   89,   89,   89,
   89,    0,   89,   89,   89,   89,    0,    0,    0,   89,
    0,    0,    0,    0,   89,    0,   89,   89,   89,   88,
   88,   89,   89,   89,    0,    0,    0,    0,    0,    0,
   88,   88,   88,   88,   88,   88,    0,   88,   88,   88,
   88,    0,    0,    0,   88,    0,    0,   87,   87,   88,
    0,   88,   88,   88,    0,    0,   88,   88,   88,   87,
   87,   87,   87,   87,    0,   87,   87,   87,   87,    0,
    0,    0,   87,    0,    0,   86,   86,   87,    0,   87,
   87,   87,    0,    0,   87,   87,   87,   86,   86,    0,
   86,   86,    0,   86,   86,   86,   86,    0,    0,    0,
   86,    0,    0,   85,   85,   86,    0,   86,   86,   86,
    0,    0,   86,   86,   86,   85,   85,    0,    0,   85,
    0,   85,   85,   85,   85,    0,    0,    0,   85,    0,
   84,   84,    0,   85,    0,   85,   85,   85,    0,    0,
   85,   85,   85,   84,    0,    0,   84,    0,   84,   84,
   84,   84,    0,    0,    0,   84,   83,   83,    0,    0,
   84,    0,   84,   84,   84,    0,    0,   84,   84,   84,
    0,    0,   83,    0,   83,   83,   83,   83,    0,    0,
    0,   83,    0,    0,    0,    0,   83,    0,   83,   83,
   83,    0,    0,   83,   83,   83,   78,   79,   80,   81,
   82,   83,    0,    0,   84,   85,   86,   87,   88,   89,
   90,   91,   92,   93,   94,   95,   96,   97,   80,   81,
   82,   83,    0,    0,   84,   85,   86,   87,  196,    0,
   90,   91,    0,   93,   98,   78,   79,   80,   81,   82,
   83,    0,    0,   84,   85,   86,   87,   88,   89,   90,
   91,   92,   93,   94,   95,   96,   97,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   78,   79,   80,   81,
   82,   83,  205,   98,   84,   85,   86,   87,   88,   89,
   90,   91,   92,   93,   94,   95,   96,   97,   80,   81,
   82,   83,    0,    0,   84,   85,   86,   12,   12,   12,
   12,   12,   12,   93,   98,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   80,
   81,   82,    0,    0,    0,   84,   85,    0,   11,   11,
   11,   11,   11,   11,   93,   12,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   82,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   82,   11,   82,   82,   82,
   82,    0,    0,    0,   82,    0,    0,    0,    0,   82,
    0,   82,   82,   82,    0,    0,   82,   82,   82,   80,
   80,   80,   80,    0,    0,    0,   80,    0,    0,    0,
    0,   80,    0,   80,   80,   80,    0,    0,   80,   80,
   80,   78,   79,   80,   81,   82,   83,    0,    0,   84,
   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
   95,   96,   79,   79,   79,    0,    0,    0,   79,    0,
    0,    0,    0,   79,    0,   79,   79,   79,    0,    0,
   79,   79,   79,   78,   79,   80,   81,   82,   83,    0,
    0,   84,   85,   86,   87,   88,   89,   90,   91,   92,
   93,   94,   95,    0,   78,   78,    0,    0,    0,   78,
    0,    0,    0,    0,   78,    0,   78,   78,   78,    0,
    0,   78,   78,   78,   78,   79,   80,   81,   82,   83,
    0,    0,   84,   85,   86,   87,   88,   89,   90,   91,
   92,   93,   94,   77,    0,    0,    0,   77,    0,    0,
    0,    0,   77,    0,   77,   77,   77,    0,    0,   77,
   77,   77,   78,   79,   80,   81,   82,   83,    0,    0,
   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,
   78,   79,   80,   81,   82,   83,    0,    0,   84,   85,
   86,   87,   88,   89,   90,   91,   78,   93,   80,   81,
   82,   83,    0,    0,   84,   85,   86,   87,   88,   89,
   90,   91,    0,   93,   80,   81,   82,   83,    0,    0,
   84,   85,   86,   87,   88,   89,   90,   91,    0,   93,
   80,   81,   82,   83,    0,    0,   84,   85,   86,   87,
   88,    0,   90,   91,    0,   93,   80,   81,   82,   83,
    0,    0,   84,   85,   86,   87,    0,   74,   90,    0,
    0,   93,   74,    0,   74,   74,   74,   73,    0,   74,
    0,   74,   73,    0,   73,   73,   73,   72,    0,   73,
    0,   73,   72,    0,   72,   72,   72,   71,    0,   72,
    0,   72,   71,    0,   71,   71,   71,   70,    0,   71,
    0,   71,   70,    0,   70,   70,   70,   69,    0,   70,
    0,   70,   69,    0,   69,   69,   69,   68,    0,   69,
    0,   69,   68,    0,   68,   68,   68,   67,    0,   68,
    0,   68,   67,    0,   67,   67,   67,   66,    0,   67,
    0,   67,   66,    0,   66,   66,   66,   75,    0,   66,
    0,   66,   75,    0,   75,   75,   75,   65,    0,   75,
    0,   75,   65,    0,   65,   65,   65,   76,    0,   65,
    0,   65,   76,    0,   76,   76,   76,   96,    0,   76,
    0,   76,   96,    0,   96,   96,   96,    0,    0,   96,
    0,   96,
};
short yycheck[] = {                                      54,
    0,  270,    1,    2,    3,    4,  273,  274,  293,  274,
    9,  293,  316,  298,  297,   14,  285,  270,  271,  301,
  302,  270,  271,  276,  291,  292,  293,  294,  295,  296,
  297,   29,  285,  294,  301,  302,  285,  304,  303,  307,
   38,  308,  309,  293,  311,  312,  313,  314,  315,   48,
  317,  301,  302,  293,  298,  305,  298,  296,  297,  307,
  294,  301,  302,  305,   63,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   73,   74,  294,  294,   77,   78,
   79,  307,   81,   82,   83,   84,   85,   86,   87,   88,
   89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
  305,  296,  100,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  297,  271,  272,  273,
  274,  294,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  292,  270,
  271,  196,  293,  297,  307,  276,  277,  202,  293,  298,
  301,  302,  151,  270,  285,  307,  301,  302,  268,  269,
  293,  271,  272,  273,  274,  319,  276,  277,  278,  279,
  280,  281,  282,  283,  284,  285,  286,  287,  288,  289,
  294,  291,  292,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  293,  298,  273,  274,  197,  293,
  305,  200,  301,  302,    3,    4,  205,  301,  302,  319,
    9,  294,  305,  293,  291,  292,  290,  294,  295,  296,
  297,    0,  298,  297,  223,  257,  258,  259,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  298,  271,
  272,  273,  274,  293,  276,  277,  278,  279,  280,  281,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
  292,  298,  298,  298,  293,  297,  293,  284,  298,  286,
  287,  288,  289,  273,  274,  298,  293,   39,   80,   80,
    9,  298,  205,  300,  301,  302,  100,  319,  305,  306,
  307,  291,  292,  215,  294,  295,  296,  297,  190,  223,
  218,  149,   30,   -1,  304,   -1,   -1,   -1,  308,  309,
   -1,  311,  312,  313,  314,  315,   -1,  317,  257,  258,
  259,  260,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,  273,  274,   -1,  276,  277,  278,
  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  292,  293,   -1,   -1,   -1,  297,  298,
  299,  300,  301,  302,  303,   -1,  305,  306,  307,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,  273,   -1,   -1,  276,  277,
  278,  279,  280,  281,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,  293,   -1,   -1,   -1,  297,
  298,  299,  300,  301,  302,   -1,   -1,  305,  306,  307,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  273,   -1,   -1,  276,
  277,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  287,  288,  289,  290,  291,  292,  293,  273,  274,   -1,
   -1,  298,  299,  300,  301,  302,   -1,   -1,  305,  306,
  307,   -1,   -1,   -1,   -1,  291,  292,   -1,  294,  295,
  296,  297,   -1,   -1,   -1,   -1,   -1,   -1,  304,   -1,
   -1,   -1,  308,  309,   -1,  311,  312,  313,  314,  315,
   -1,  317,  257,  258,  259,  260,  261,  262,  263,  264,
  265,  266,  267,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  270,  271,  272,  273,   -1,   -1,
  276,  277,  278,  279,   -1,  290,  291,  292,   -1,  285,
   -1,   -1,   -1,  298,  299,   -1,  290,  291,  292,  268,
  269,  270,  271,  272,  273,  299,   -1,  276,  277,  278,
  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,
  289,   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,  298,
   -1,  300,  301,  302,   -1,   -1,  305,  306,  307,  268,
  269,  270,  271,  272,  273,   -1,   -1,  276,  277,  278,
  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,
  289,   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,  298,
   -1,  300,  301,  302,   -1,   -1,  305,  306,  307,  268,
  269,  270,  271,  272,  273,   -1,   -1,  276,  277,  278,
  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,
  289,   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,  298,
   -1,  300,  301,  302,   -1,   -1,  305,  306,  307,  268,
  269,   -1,  271,  272,  273,   -1,   -1,  276,  277,  278,
  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,
  289,   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,  298,
   -1,  300,  301,  302,   -1,   -1,  305,  306,  307,  268,
  269,   -1,  271,  272,  273,   -1,   -1,  276,  277,  278,
  279,  280,  281,  282,  283,  284,   -1,  286,  287,  288,
  289,   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,  298,
   -1,  300,  301,  302,   -1,   -1,  305,  306,  307,  268,
  269,   -1,   -1,  272,  273,   -1,   -1,  276,  277,  278,
  279,  280,  281,  282,  283,  284,   -1,  286,  287,  288,
  289,   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,  298,
   -1,  300,  301,  302,   -1,   -1,  305,  306,  307,  268,
  269,   -1,   -1,  272,  273,   -1,   -1,   -1,  277,  278,
  279,  280,  281,  282,  283,  284,   -1,  286,  287,  288,
  289,   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,  298,
   -1,  300,  301,  302,   -1,   -1,  305,  306,  307,  268,
  269,   -1,   -1,  272,  273,   -1,   -1,   -1,   -1,  278,
  279,  280,  281,  282,  283,  284,   -1,  286,  287,  288,
  289,   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,  298,
   -1,  300,  301,  302,   -1,   -1,  305,  306,  307,  268,
  269,  270,  271,  272,  273,   -1,   -1,  276,  277,  278,
  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,
  289,  270,  271,  272,  273,   -1,   -1,  276,  277,  268,
  269,   -1,   -1,   -1,  273,   -1,  285,  306,  307,  278,
  279,  280,  281,  282,  283,  284,   -1,  286,  287,  288,
  289,   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,  298,
   -1,  300,  301,  302,  268,  269,  305,  306,  307,   -1,
   -1,   -1,   -1,   -1,  278,  279,  280,  281,  282,  283,
  284,   -1,  286,  287,  288,  289,   -1,   -1,   -1,  293,
   -1,   -1,   -1,   -1,  298,   -1,  300,  301,  302,  268,
  269,  305,  306,  307,   -1,   -1,   -1,   -1,   -1,   -1,
  279,  280,  281,  282,  283,  284,   -1,  286,  287,  288,
  289,   -1,   -1,   -1,  293,   -1,   -1,  268,  269,  298,
   -1,  300,  301,  302,   -1,   -1,  305,  306,  307,  280,
  281,  282,  283,  284,   -1,  286,  287,  288,  289,   -1,
   -1,   -1,  293,   -1,   -1,  268,  269,  298,   -1,  300,
  301,  302,   -1,   -1,  305,  306,  307,  280,  281,   -1,
  283,  284,   -1,  286,  287,  288,  289,   -1,   -1,   -1,
  293,   -1,   -1,  268,  269,  298,   -1,  300,  301,  302,
   -1,   -1,  305,  306,  307,  280,  281,   -1,   -1,  284,
   -1,  286,  287,  288,  289,   -1,   -1,   -1,  293,   -1,
  268,  269,   -1,  298,   -1,  300,  301,  302,   -1,   -1,
  305,  306,  307,  281,   -1,   -1,  284,   -1,  286,  287,
  288,  289,   -1,   -1,   -1,  293,  268,  269,   -1,   -1,
  298,   -1,  300,  301,  302,   -1,   -1,  305,  306,  307,
   -1,   -1,  284,   -1,  286,  287,  288,  289,   -1,   -1,
   -1,  293,   -1,   -1,   -1,   -1,  298,   -1,  300,  301,
  302,   -1,   -1,  305,  306,  307,  268,  269,  270,  271,
  272,  273,   -1,   -1,  276,  277,  278,  279,  280,  281,
  282,  283,  284,  285,  286,  287,  288,  289,  270,  271,
  272,  273,   -1,   -1,  276,  277,  278,  279,  300,   -1,
  282,  283,   -1,  285,  306,  268,  269,  270,  271,  272,
  273,   -1,   -1,  276,  277,  278,  279,  280,  281,  282,
  283,  284,  285,  286,  287,  288,  289,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,  270,  271,
  272,  273,  305,  306,  276,  277,  278,  279,  280,  281,
  282,  283,  284,  285,  286,  287,  288,  289,  270,  271,
  272,  273,   -1,   -1,  276,  277,  278,  268,  269,  270,
  271,  272,  273,  285,  306,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  285,  286,  287,  288,  289,  270,
  271,  272,   -1,   -1,   -1,  276,  277,   -1,  268,  269,
  270,  271,  272,  273,  285,  306,  276,  277,  278,  279,
  280,  281,  282,  283,  284,  285,  286,  287,  288,  289,
  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  284,  306,  286,  287,  288,
  289,   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,  298,
   -1,  300,  301,  302,   -1,   -1,  305,  306,  307,  286,
  287,  288,  289,   -1,   -1,   -1,  293,   -1,   -1,   -1,
   -1,  298,   -1,  300,  301,  302,   -1,   -1,  305,  306,
  307,  268,  269,  270,  271,  272,  273,   -1,   -1,  276,
  277,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  287,  288,  287,  288,  289,   -1,   -1,   -1,  293,   -1,
   -1,   -1,   -1,  298,   -1,  300,  301,  302,   -1,   -1,
  305,  306,  307,  268,  269,  270,  271,  272,  273,   -1,
   -1,  276,  277,  278,  279,  280,  281,  282,  283,  284,
  285,  286,  287,   -1,  288,  289,   -1,   -1,   -1,  293,
   -1,   -1,   -1,   -1,  298,   -1,  300,  301,  302,   -1,
   -1,  305,  306,  307,  268,  269,  270,  271,  272,  273,
   -1,   -1,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  285,  286,  289,   -1,   -1,   -1,  293,   -1,   -1,
   -1,   -1,  298,   -1,  300,  301,  302,   -1,   -1,  305,
  306,  307,  268,  269,  270,  271,  272,  273,   -1,   -1,
  276,  277,  278,  279,  280,  281,  282,  283,  284,  285,
  268,  269,  270,  271,  272,  273,   -1,   -1,  276,  277,
  278,  279,  280,  281,  282,  283,  268,  285,  270,  271,
  272,  273,   -1,   -1,  276,  277,  278,  279,  280,  281,
  282,  283,   -1,  285,  270,  271,  272,  273,   -1,   -1,
  276,  277,  278,  279,  280,  281,  282,  283,   -1,  285,
  270,  271,  272,  273,   -1,   -1,  276,  277,  278,  279,
  280,   -1,  282,  283,   -1,  285,  270,  271,  272,  273,
   -1,   -1,  276,  277,  278,  279,   -1,  293,  282,   -1,
   -1,  285,  298,   -1,  300,  301,  302,  293,   -1,  305,
   -1,  307,  298,   -1,  300,  301,  302,  293,   -1,  305,
   -1,  307,  298,   -1,  300,  301,  302,  293,   -1,  305,
   -1,  307,  298,   -1,  300,  301,  302,  293,   -1,  305,
   -1,  307,  298,   -1,  300,  301,  302,  293,   -1,  305,
   -1,  307,  298,   -1,  300,  301,  302,  293,   -1,  305,
   -1,  307,  298,   -1,  300,  301,  302,  293,   -1,  305,
   -1,  307,  298,   -1,  300,  301,  302,  293,   -1,  305,
   -1,  307,  298,   -1,  300,  301,  302,  293,   -1,  305,
   -1,  307,  298,   -1,  300,  301,  302,  293,   -1,  305,
   -1,  307,  298,   -1,  300,  301,  302,  293,   -1,  305,
   -1,  307,  298,   -1,  300,  301,  302,  293,   -1,  305,
   -1,  307,  298,   -1,  300,  301,  302,   -1,   -1,  305,
   -1,  307,
};
#define YYFINAL 21
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 323
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"MUL_ASSIGN","DIV_ASSIGN",
"MOD_ASSIGN","ADD_ASSIGN","SUB_ASSIGN","LS_ASSIGN","RS_ASSIGN","AND_ASSIGN",
"OR_ASSIGN","POW_ASSIGN","XOR_ASSIGN","EQ","IEQ","MEM","MUL","ADD","SUB","NOT",
"BNOT","DIV","MOD","LS","RS","LTE","GTE","LT","GT","AND","POW","XOR","OR",
"LAND","LOR","ASSIGN","INC","DEC","SEMICOLON","IDENTIFIER","NUMBER","STRING",
"LPARAN","RPARAN","LARRAY","RARRAY","LCURL","RCURL","LIT","FOR","COMMA",
"QUESTION","COLON","METHOD","RETURN","HIGHEST","CLASS","STRUCT","PUBLIC",
"PRIVATE","VAR","DOT","INCLUDE","CONDITIONAL","NEG","PREF_DEC","PREF_INC",
"POST_DEC","POST_INC",
};
char *yyrule[] = {
"$accept : begin",
"tdc : LIT",
"tdc : NOT",
"tdc :",
"var_identifier : function_identifier tdc",
"identifier : var_identifier",
"identifier : identifier LARRAY value RARRAY tdc",
"identifier : LPARAN identifier RPARAN",
"identifier : value MEM function",
"identifier : value MEM var_identifier",
"identifier : function",
"value : _value",
"value : identifier",
"_value : LPARAN _value RPARAN",
"_value : operators",
"_value : NUMBER",
"_value : STRING",
"params : value COMMA params",
"params : value",
"params :",
"function_identifier : IDENTIFIER",
"function_identifier : IDENTIFIER DOT IDENTIFIER",
"$$1 :",
"function : function_identifier $$1 LPARAN params RPARAN",
"operator : XOR_ASSIGN",
"operator : OR_ASSIGN",
"operator : AND_ASSIGN",
"operator : RS_ASSIGN",
"operator : LS_ASSIGN",
"operator : SUB_ASSIGN",
"operator : ADD_ASSIGN",
"operator : MOD_ASSIGN",
"operator : DIV_ASSIGN",
"operator : MUL_ASSIGN",
"operator : POW_ASSIGN",
"operator : ASSIGN",
"operator : LOR",
"operator : LAND",
"operator : OR",
"operator : XOR",
"operator : AND",
"operator : IEQ",
"operator : EQ",
"operator : GTE",
"operator : LTE",
"operator : GT",
"operator : LT",
"operator : RS",
"operator : LS",
"operator : SUB",
"operator : ADD",
"operator : MOD",
"operator : DIV",
"operator : MUL",
"operator : POW",
"operator : NOT",
"operator : NEG",
"operator : INC",
"operator : DEC",
"operators : INC identifier",
"operators : identifier INC",
"operators : DEC identifier",
"operators : identifier DEC",
"operators : SUB value",
"operators : NOT value",
"operators : identifier XOR_ASSIGN value",
"operators : identifier OR_ASSIGN value",
"operators : identifier AND_ASSIGN value",
"operators : identifier RS_ASSIGN value",
"operators : identifier LS_ASSIGN value",
"operators : identifier SUB_ASSIGN value",
"operators : identifier ADD_ASSIGN value",
"operators : identifier MOD_ASSIGN value",
"operators : identifier DIV_ASSIGN value",
"operators : identifier MUL_ASSIGN value",
"operators : identifier POW_ASSIGN value",
"operators : identifier ASSIGN value",
"operators : value LOR value",
"operators : value LAND value",
"operators : value OR value",
"operators : value XOR value",
"operators : value AND value",
"operators : value IEQ value",
"operators : value EQ value",
"operators : value GTE value",
"operators : value LTE value",
"operators : value GT value",
"operators : value LT value",
"operators : value RS value",
"operators : value LS value",
"operators : value SUB value",
"operators : value ADD value",
"operators : value MOD value",
"operators : value DIV value",
"operators : value MUL value",
"operators : value POW value",
"operators : value QUESTION value COLON value",
"line_terminator : SEMICOLON",
"line_terminator : LCURL",
"line_terminator : RCURL",
"line_terminators : line_terminator line_terminators",
"line_terminators : line_terminator",
"finale : line_terminators",
"method_param : IDENTIFIER tdc",
"method_params : method_param COMMA method_params",
"method_params : method_param",
"method_params :",
"method_name : IDENTIFIER",
"method_name : IDENTIFIER COLON COLON method_name",
"method_name : method_name operator",
"$$2 :",
"$$3 :",
"method : METHOD method_name LPARAN $$2 method_params $$3 RPARAN",
"for_loop_value : value",
"for_loop_value :",
"for_loop_value_centre : value",
"for_loop_value_centre :",
"$$4 :",
"$$5 :",
"$$6 :",
"for_loop : FOR LPARAN for_loop_value $$4 SEMICOLON for_loop_value_centre SEMICOLON $$5 for_loop_value $$6 RPARAN",
"return_val : RETURN value",
"inherit_class : IDENTIFIER",
"class_list : inherit_class COMMA class_list",
"class_list : inherit_class",
"inherits : COLON class_list",
"inherits :",
"class_declarator : CLASS",
"class_declarator : STRUCT",
"$$7 :",
"class : class_declarator IDENTIFIER $$7 inherits",
"class_member : IDENTIFIER tdc",
"var_list : class_member COMMA var_list",
"var_list : class_member",
"class_members : VAR var_list",
"inclusion : INCLUDE STRING",
"inclusion : INCLUDE LPARAN STRING RPARAN",
"statement : return_val",
"statement : method",
"statement : class",
"statement : class_members",
"statement : PRIVATE COLON",
"statement : PUBLIC COLON",
"statement : inclusion",
"statement : for_loop",
"statement : value",
"line : statement finale",
"line : line_terminators statement finale",
"begin :",
"begin : line begin",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 618 "yacc.txt"

#include "lex.yy.c"
LPMACHINE_UNITS g_yyOldUnits = NULL;
std::deque<std::map<std::string, int> > g_methods;
std::map<std::string, tagClass>::value_type *g_pClass = NULL;
CLASS_VISIBILITY g_vis = CV_PRIVATE;
#line 794 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 3:
#line 98 "yacc.txt"
{ }
break;
case 4:
#line 107 "yacc.txt"
{
			MACHINE_UNIT mu;
			if (g_methods.size() && g_methods.back().count(yyvsp[-1].getLit()))
			{
				(mu.lit = " ") += char(g_methods.back()[yyvsp[-1].getLit()] + 1);
			}
			else
			{
				mu.lit = yyvsp[-1].getLit();
			}
			mu.udt = UDT_ID;
			CProgram::m_pyyUnits->push_back(mu);
		}
break;
case 6:
#line 125 "yacc.txt"
{ _MACHINE_UNIT(operators::array, 2); }
break;
case 8:
#line 128 "yacc.txt"
{
			/** MACHINE_UNIT &mu = *(CProgram::m_pyyUnits->end() - CProgram::m_pyyUnits->back().params - 2);
			mu.udt = UNIT_DATA_TYPE(mu.udt | UDT_OBJ); **/
			if (CProgram::m_pyyUnits->back().func == CProgram::methodCall)
			{
				MACHINE_UNIT &name = *(CProgram::m_pyyUnits->end() - 2);
				name.udt = UNIT_DATA_TYPE(name.udt | UDT_OBJ);
			}
			++CProgram::m_pyyUnits->back().params;
		}
break;
case 9:
#line 139 "yacc.txt"
{ _MACHINE_UNIT(operators::member, 2); }
break;
case 15:
#line 152 "yacc.txt"
{
			MACHINE_UNIT mu;
			mu.num = yyvsp[0].getNum();
			mu.udt = UDT_NUM;
			CProgram::m_pyyUnits->push_back(mu);
		}
break;
case 16:
#line 159 "yacc.txt"
{
			MACHINE_UNIT mu;
			mu.lit = yyvsp[0].getLit().substr(1, yyvsp[0].getLit().length() - 2);
			mu.udt = UDT_LIT;
			CProgram::m_pyyUnits->push_back(mu);
		}
break;
case 17:
#line 169 "yacc.txt"
{ _FOUND_PARAM; }
break;
case 18:
#line 171 "yacc.txt"
{ _FOUND_PARAM; }
break;
case 19:
#line 173 "yacc.txt"
{ }
break;
case 21:
#line 179 "yacc.txt"
{ CProgram::m_inclusions.push_back(yyvsp[-2].getLit() + ".prg"); yyval = yyvsp[0]; }
break;
case 22:
#line 184 "yacc.txt"
{ CProgram::m_params.push_back(0); }
break;
case 23:
#line 186 "yacc.txt"
{
			MACHINE_FUNC pFunc = NULL;
			if (CProgram::m_functions.count(yyvsp[-4].getLit()))
			{
				pFunc = CProgram::m_functions[yyvsp[-4].getLit()];
			}
			else
			{
				MACHINE_UNIT mu;
				mu.udt = UDT_ID;
				mu.lit = yyvsp[-4].getLit();
				CProgram::m_pyyUnits->push_back(mu);
				_FOUND_PARAM;
				pFunc = CProgram::methodCall;
			}
			_MACHINE_UNIT(pFunc, CProgram::m_params.back());
			CProgram::m_params.pop_back();
		}
break;
case 59:
#line 246 "yacc.txt"
{ _MACHINE_UNIT(operators::prefixIncrement, 1); }
break;
case 60:
#line 248 "yacc.txt"
{ _MACHINE_UNIT(operators::postfixIncrement, 1); }
break;
case 61:
#line 250 "yacc.txt"
{ _MACHINE_UNIT(operators::prefixDecrement, 1); }
break;
case 62:
#line 252 "yacc.txt"
{ _MACHINE_UNIT(operators::postfixDecrement, 1); }
break;
case 63:
#line 254 "yacc.txt"
{ _MACHINE_UNIT(operators::unaryNegation, 1); }
break;
case 64:
#line 256 "yacc.txt"
{ _MACHINE_UNIT(operators::lnot, 1); }
break;
case 65:
#line 258 "yacc.txt"
{ _MACHINE_UNIT(operators::xor_assign, 2); }
break;
case 66:
#line 260 "yacc.txt"
{ _MACHINE_UNIT(operators::or_assign, 2); }
break;
case 67:
#line 262 "yacc.txt"
{ _MACHINE_UNIT(operators::and_assign, 2); }
break;
case 68:
#line 264 "yacc.txt"
{ _MACHINE_UNIT(operators::rs_assign, 2); }
break;
case 69:
#line 266 "yacc.txt"
{ _MACHINE_UNIT(operators::ls_assign, 2); }
break;
case 70:
#line 268 "yacc.txt"
{ _MACHINE_UNIT(operators::sub_assign, 2); }
break;
case 71:
#line 270 "yacc.txt"
{ _MACHINE_UNIT(operators::add_assign, 2); }
break;
case 72:
#line 272 "yacc.txt"
{ _MACHINE_UNIT(operators::mod_assign, 2); }
break;
case 73:
#line 274 "yacc.txt"
{ _MACHINE_UNIT(operators::div_assign, 2); }
break;
case 74:
#line 276 "yacc.txt"
{ _MACHINE_UNIT(operators::mul_assign, 2); }
break;
case 75:
#line 278 "yacc.txt"
{ _MACHINE_UNIT(operators::pow_assign, 2); }
break;
case 76:
#line 280 "yacc.txt"
{ _MACHINE_UNIT(operators::assign, 2); }
break;
case 77:
#line 282 "yacc.txt"
{ _MACHINE_UNIT(operators::lor, 2); }
break;
case 78:
#line 284 "yacc.txt"
{ _MACHINE_UNIT(operators::land, 2); }
break;
case 79:
#line 286 "yacc.txt"
{ _MACHINE_UNIT(operators::bor, 2); }
break;
case 80:
#line 288 "yacc.txt"
{ _MACHINE_UNIT(operators::bxor, 2); }
break;
case 81:
#line 290 "yacc.txt"
{ _MACHINE_UNIT(operators::band, 2); }
break;
case 82:
#line 292 "yacc.txt"
{ _MACHINE_UNIT(operators::ieq, 2); }
break;
case 83:
#line 294 "yacc.txt"
{ _MACHINE_UNIT(operators::eq, 2); }
break;
case 84:
#line 296 "yacc.txt"
{ _MACHINE_UNIT(operators::gte, 2); }
break;
case 85:
#line 298 "yacc.txt"
{ _MACHINE_UNIT(operators::lte, 2); }
break;
case 86:
#line 300 "yacc.txt"
{ _MACHINE_UNIT(operators::gt, 2); }
break;
case 87:
#line 302 "yacc.txt"
{ _MACHINE_UNIT(operators::lt, 2); }
break;
case 88:
#line 304 "yacc.txt"
{ _MACHINE_UNIT(operators::rs, 2); }
break;
case 89:
#line 306 "yacc.txt"
{ _MACHINE_UNIT(operators::ls, 2); }
break;
case 90:
#line 308 "yacc.txt"
{ _MACHINE_UNIT(operators::sub, 2); }
break;
case 91:
#line 310 "yacc.txt"
{ _MACHINE_UNIT(operators::add, 2); }
break;
case 92:
#line 312 "yacc.txt"
{ _MACHINE_UNIT(operators::mod, 2); }
break;
case 93:
#line 314 "yacc.txt"
{ _MACHINE_UNIT(operators::div, 2); }
break;
case 94:
#line 316 "yacc.txt"
{ _MACHINE_UNIT(operators::mul, 2); }
break;
case 95:
#line 318 "yacc.txt"
{ _MACHINE_UNIT(operators::pow, 2); }
break;
case 96:
#line 320 "yacc.txt"
{ _MACHINE_UNIT(operators::tertiary, 3); }
break;
case 98:
#line 326 "yacc.txt"
{
			_END_LINE;
			MACHINE_UNIT mu;
			mu.udt = UDT_OPEN;
			CProgram::m_pyyUnits->push_back(mu);
		}
break;
case 99:
#line 333 "yacc.txt"
{
			_END_LINE;
			MACHINE_UNIT mu;
			mu.udt = UDT_CLOSE;
			/* Find the corresponding opening brace. */
			POS i = CProgram::m_pyyUnits->end() - 1;
			int depth = 0;
			for (; i != CProgram::m_pyyUnits->begin(); --i)
			{
				if ((i->udt & UDT_OPEN) && (depth++ == 0))
				{
					unsigned long *const pLines = (unsigned long *)&mu.num;
					pLines[0] = i - CProgram::m_pyyUnits->begin();
					if ((i - 1)->udt & UDT_FUNC)
					{
						if ((i - 1)->func == CProgram::forLoop)
						{
							CONST_POS j = CProgram::m_yyFors.back().begin();
							for (; j != CProgram::m_yyFors.back().end(); ++j)
							{
								CProgram::m_pyyUnits->push_back(*j);
							}
							CProgram::m_yyFors.pop_back();
						}
						else if ((i - 1)->func == CProgram::skipMethod)
						{
							g_methods.pop_back();
						}
						else if ((i - 1)->func == CProgram::skipClass)
						{
							MACHINE_UNIT &mu = *(CProgram::m_pyyUnits->end() - 1);
							if ((mu.udt & UDT_FUNC) && (mu.func == CProgram::skipMethod) && !(CProgram::m_pyyUnits->back().udt & UDT_OPEN))
							{
								g_pClass->second.methods.back().first.i = NAMED_METHOD::m_methods.back().i = 0xffffff;
								g_methods.pop_back();
							}
							g_pClass = NULL;
						}
					}
					i->num = CProgram::m_pyyUnits->size();
					for (; i != CProgram::m_pyyUnits->begin(); --i)
					{
						if ((i->udt & UDT_LINE) && (++depth == 3)) break;
					}
					pLines[1] = i - CProgram::m_pyyUnits->begin() + 1;
					break;
				}
				else if (i->udt & UDT_CLOSE) --depth;
			}
			CProgram::m_pyyUnits->push_back(mu);
		}
break;
case 102:
#line 393 "yacc.txt"
{
			_END_LINE;
			if (CProgram::m_pyyUnits->size() > 1)
			{
				MACHINE_UNIT &mu = *(CProgram::m_pyyUnits->end() - 1);
				if (g_pClass && (mu.udt & UDT_FUNC) && (mu.func == CProgram::skipMethod) && !(CProgram::m_pyyUnits->back().udt & UDT_OPEN))
				{
					g_pClass->second.methods.back().first.i = NAMED_METHOD::m_methods.back().i = 0xffffff;
					g_methods.pop_back();
				}
			}
		}
break;
case 104:
#line 413 "yacc.txt"
{ g_methods.back()[yyvsp[-2].getLit()] = g_methods.back().size(); }
break;
case 105:
#line 415 "yacc.txt"
{ g_methods.back()[yyvsp[0].getLit()] = g_methods.back().size(); }
break;
case 106:
#line 417 "yacc.txt"
{ }
break;
case 108:
#line 423 "yacc.txt"
{ yyval = yyvsp[-3].getLit() + "::" + yyvsp[0].getLit(); }
break;
case 110:
#line 429 "yacc.txt"
{ g_methods.push_back(std::map<std::string, int>()); }
break;
case 111:
#line 431 "yacc.txt"
{
			const std::string name = (g_pClass ? (g_pClass->first + "::") : "") + yyvsp[-3].getLit();
			if (NAMED_METHOD::locate(name, g_methods.back().size(), false))
			{
				char str[255];
				itoa(g_methods.back().size(), str, 10);
				char line[255];
				itoa(g_lines + 1, line, 10);
				CProgram::debugger(std::string("Line ") + line + ": Method \"" + name + "\" with a parameter count of " + str + " already exists.");
			}
			else
			{
				const std::string::size_type pos = name.find("::");
				if (!g_pClass && (pos != std::string::npos))
				{
					const std::string clsName = name.substr(0, pos);
					const std::string method = name.substr(pos + 2);
					LPNAMED_METHOD p = NAMED_METHOD::locate(name, g_methods.back().size(), true);
					if (p)
					{
						(*CProgram::m_pClasses)[clsName].locate(method, g_methods.back().size(), CV_PRIVATE)->i =
							p->i = CProgram::m_pyyUnits->end() - CProgram::m_pyyUnits->begin();
					}
					else
					{
						char str[255];
						itoa(g_methods.back().size(), str, 10);
						char line[255];
						itoa(g_lines + 1, line, 10);
						CProgram::debugger(std::string("Line ") + line + ": Class \"" + clsName + "\" has no method \"" + method + "\" with a parameter count of " + str + ".");
					}
				}
				else
				{
					NAMED_METHOD method;
					method.name = name;
					method.params = g_methods.back().size();
					method.i = CProgram::m_pyyUnits->end() - CProgram::m_pyyUnits->begin();
					NAMED_METHOD::m_methods.push_back(method);
					if (g_pClass)
					{
						method.name = yyvsp[-3].getLit();
						g_pClass->second.methods.push_back(std::pair<NAMED_METHOD, CLASS_VISIBILITY>(method, g_vis));
					}
				}
			}
			_MACHINE_UNIT(CProgram::skipMethod, 0);
			CProgram::m_pyyUnits->back().lit = name;
			CProgram::m_pyyUnits->back().num = g_methods.back().size();
		}
break;
case 114:
#line 487 "yacc.txt"
{ }
break;
case 116:
#line 493 "yacc.txt"
{
			MACHINE_UNIT mu;
			mu.udt = UDT_NUM;
			mu.num = 1;
			CProgram::m_pyyUnits->push_back(mu);
		}
break;
case 117:
#line 503 "yacc.txt"
{ _END_LINE; }
break;
case 118:
#line 505 "yacc.txt"
{
			g_yyOldUnits = CProgram::m_pyyUnits;
			CProgram::m_yyFors.push_back(MACHINE_UNITS());
			CProgram::m_pyyUnits = &CProgram::m_yyFors.back();
		}
break;
case 119:
#line 511 "yacc.txt"
{
			_END_LINE;
			CProgram::m_pyyUnits = g_yyOldUnits;
			_MACHINE_UNIT(CProgram::forLoop, 1);
		}
break;
case 121:
#line 521 "yacc.txt"
{ _MACHINE_UNIT(CProgram::returnVal, 1); }
break;
case 122:
#line 526 "yacc.txt"
{ g_pClass->second.inherits.push_back(yyvsp[0].getLit()); }
break;
case 126:
#line 537 "yacc.txt"
{ }
break;
case 127:
#line 542 "yacc.txt"
{ g_vis = CV_PRIVATE; }
break;
case 128:
#line 544 "yacc.txt"
{ g_vis = CV_PUBLIC; }
break;
case 129:
#line 549 "yacc.txt"
{
			g_pClass = &*CProgram::m_pClasses->insert(std::map<std::string, tagClass>::value_type(yyvsp[0].getLit(), tagClass())).first;
			_MACHINE_UNIT(CProgram::skipClass, 0);
			CProgram::m_pyyUnits->back().num = g_vis;
		}
break;
case 131:
#line 559 "yacc.txt"
{
			if (g_pClass)
			{
				g_pClass->second.members.push_back(std::pair<std::string, CLASS_VISIBILITY>(yyvsp[-1].getLit(), g_vis));
			}
		}
break;
case 135:
#line 578 "yacc.txt"
{ CProgram::m_inclusions.push_back(yyvsp[0].getLit().substr(1, yyvsp[0].getLit().length() - 2)); }
break;
case 136:
#line 580 "yacc.txt"
{ CProgram::m_inclusions.push_back(yyvsp[-1].getLit().substr(1, yyvsp[-1].getLit().length() - 2)); }
break;
case 141:
#line 589 "yacc.txt"
{
			MACHINE_UNIT mu;
			mu.udt = UNIT_DATA_TYPE(UDT_ID | UDT_NUM);
			mu.num = g_vis = CV_PRIVATE;
			CProgram::m_pyyUnits->push_back(mu);
		}
break;
case 142:
#line 596 "yacc.txt"
{
			MACHINE_UNIT mu;
			mu.udt = UNIT_DATA_TYPE(UDT_ID | UDT_NUM);
			mu.num = g_vis = CV_PUBLIC;
			CProgram::m_pyyUnits->push_back(mu);
		}
break;
#line 1471 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
