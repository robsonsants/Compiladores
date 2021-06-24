%option yylineno
%{

%}

/**/
TEXTO [a-zA-Z]+
NUM_INT [0-9]+
NUM_REAL [0-9]*"."[0-9]+
STRING \"[^\"]*\"
RAIZ "raiz"
FUNC "function"

VARIAVEIS {TEXTO}({TEXTO}|{NUM_INT}|"_")*

COMENTARIO "#".*

/* INCREMENTO E DECREMENTO */ 
MAIS "++"
MENOS "--"

/* CONDICIONAL E REPETIÇÃO */
IF "if>>"
ELSE "else>>" 
WHILE "while>>"
FOR "for>>"

/* LEITURA E ESCRITA */
LEITURA "<<leia"
ESCRITA ">>escreva"

/* INICIO E FIM DO PROGRAMA EXECUTADO */
INICIO "start"
FIM "end"

IGNORAR [\ \t\s]

INVALIDO .
%%

"inteiro" {
    yylval.inteiro = 'i';
    return TIPO_INT;
}
"real" {
    yylval.inteiro = 'r';
    return TIPO_REAL;
}
"texto" {
    yylval.inteiro = 't';
    return TIPO_TEXT;
}
"void" {
    yylval.inteiro = 'v';
    return VOID;
}
{COMENTARIO} {;}
{MAIS} {return MAIS;}
{MENOS} {return MENOS;}
{FUNC} {return FUNC;}

 /* CARACTERES ARITMETICOS SIMPLES */
[-+/|*=^:;,\[\](){}] {
    return *yytext;
}
{LEITURA} {return LEITURA;}

 /* OPERADORES LOGICOS */
">" {yylval.fn = 1; return CMP; }
"<" {yylval.fn = 2; return CMP; }
"!=" {yylval.fn = 3; return CMP; }
"==" {yylval.fn = 4; return CMP; }
">=" {yylval.fn = 5; return CMP; }
"<=" {yylval.fn = 6; return CMP; }
"||" {yylval.fn = 7; return CMP; }
"&&" {yylval.fn = 8; return CMP; }
"?" { return '?'; }

[\n] {
    /* CONTADOR PARA SALTO DE LINHAS */
    yylineno++;
}
{INICIO} {
    return INICIO;
}
{FIM} {
    return FIM;
}
{NUM_REAL} {
    yylval.real = atof(yytext);
    return NUM_REAL;
}
{NUM_INT} {
    yylval.inteiro = atoi(yytext);
    return NUM_INT;
}
{RAIZ} {
    return RAIZ;
}
{ESCRITA} {
    return ESCRITA;
}
{IF} {
    return IF;
}
{ELSE} {
    return ELSE;
}
{WHILE} {
    return WHILE;
}
{FOR} {
    return FOR;
}
{VARIAVEIS} {
    strcpy(yylval.texto, yytext);
    return VARIAVEIS;
}
 /* O FOR É PARA PEGAR A STRING DENTRO DAS ASPAS */
{STRING} {
    for(int x=0; x<strlen(yytext); x++){
        yytext[x] = yytext[x+1];
    }
    yytext[strlen(yytext)-1] = '\0';
    strcpy(yylval.texto, yytext);
    return STRING;
}
{IGNORAR} {
    /* ignore */
}
{INVALIDO} {
    /* ignore */
}
%%