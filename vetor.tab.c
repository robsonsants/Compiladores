/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM_REAL = 258,
     NUM_INT = 259,
     VARIAVEIS = 260,
     FUNC = 261,
     STRING = 262,
     MAIS = 263,
     MENOS = 264,
     TIPO_REAL = 265,
     TIPO_INT = 266,
     TIPO_TEXT = 267,
     VOID = 268,
     IF = 269,
     ELSE = 270,
     WHILE = 271,
     FOR = 272,
     INICIO = 273,
     FIM = 274,
     RAIZ = 275,
     LEITURA = 276,
     ESCRITA = 277,
     COMENTARIO = 278,
     CMP = 279,
     VET = 280,
     FUN = 281,
     NEG = 282,
     IFX = 283
   };
#endif
/* Tokens.  */
#define NUM_REAL 258
#define NUM_INT 259
#define VARIAVEIS 260
#define FUNC 261
#define STRING 262
#define MAIS 263
#define MENOS 264
#define TIPO_REAL 265
#define TIPO_INT 266
#define TIPO_TEXT 267
#define VOID 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define FOR 272
#define INICIO 273
#define FIM 274
#define RAIZ 275
#define LEITURA 276
#define ESCRITA 277
#define COMENTARIO 278
#define CMP 279
#define VET 280
#define FUN 281
#define NEG 282
#define IFX 283




/* Copy the first part of user declarations.  */
#line 1 "vetor.y"

    //Codigo C
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <math.h>
    #include <ctype.h>
    #include<stdbool.h>
    extern int yylineno;
    
    int yylex();
    void yyerror(const char *str)
    {
        fprintf(stderr,"Error: %s\n Linha: %d\n", str, yylineno);
    }

    #define name_size 50
    #define string_size 1000

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo real
    typedef struct vars {
		char name[name_size];
		float v;
        float *vet;
		struct vars * prox;
	} VARS;

    // Adicionar nova variavel do tipo real na lista
    VARS * ins(VARS *l, char n[]){
		VARS *new =(VARS*)malloc(sizeof(VARS));
		strcpy(new->name, n);
		new->prox = l;
		return new;
	}

    VARS * ins_a(VARS *l, char n[], int tamanho){
		VARS *new =(VARS*)malloc(sizeof(VARS));
		strcpy(new->name, n);
        new->vet = (float*)malloc(tamanho * sizeof(float));
		new->prox = l;
		return new;
	}
    
    // Busca uma variável do tipo real na lista de variáveis
	VARS *srch(VARS *l, char n[]){
		VARS *aux = l;
		while(aux != NULL){
			if(strcmp(n, aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}
    
    // Verificar se o valor dado é real
    bool is_real(char test[]){
        int i = 0;
        int ponto = 0;
        do{
            if(isdigit(test[i])!=0 || test[i] == '.'){
                if(test[i]=='.')
                    ponto = ponto + 1;
                if(ponto>1)
                    return false;
                i=i+1;
            }
            else
                return false;
        }while(test[i]!='\0');
        
        return true;
    }

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo string
    typedef struct VARST {
		char name[name_size];
		char v[string_size];
        char **vet;
		struct VARST * prox;
	} VARST;

    // Adicionar nova variável do tipo string na lista 
    VARST * inst(VARST *l, char n[]){
		VARST *new =(VARST*)malloc(sizeof(VARST));
		strcpy(new->name, n);
        strcpy(new->v, "");
		new->prox = l;
		return new;
	}

    VARST * inst_a(VARST *l, char n[], int tamanho){
		VARST *new =(VARST*)malloc(sizeof(VARST));
		strcpy(new->name, n);
        new->vet = (char**)malloc(tamanho * sizeof(char));
		new->prox = l;
		return new;
	}

    // Busca uma nova variável do tipo string na lista de variáveis
    VARST *srcht(VARST *l, char n[]){
		VARST *aux = l;
		while(aux != NULL){
			if(strcmp(n,aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo inteiro
    typedef struct varsi {
		char name[name_size];
		int v;
        int *vet;
		struct varsi * prox;
	} VARSI;

    // Adicionar nova variavel inteiro na lista de variáveis inteiro
    VARSI * insi(VARSI *l, char n[]){
		VARSI *new =(VARSI*)malloc(sizeof(VARSI));
		strcpy(new->name, n);
		new->prox = l;
		return new;
	}

    // Insercao de inteiros no array
    VARSI * insi_a(VARSI *l, char n[], int tamanho){
		VARSI *new =(VARSI*)malloc(sizeof(VARSI));
		strcpy(new->name, n);
        new->vet = (int*)malloc(tamanho * sizeof(int));
		new->prox = l;
		return new;
	}

    // Busca uma variável inteiro na lista de variáveis inteiro
	VARSI *srchi(VARSI *l, char n[]){
		VARSI *aux = l;
		while(aux != NULL){
			if(strcmp(n, aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}

    // Verificar se o valor dado é inteiro
    bool is_int(char test[]){
        int i = 0;
        int ponto = 0;
        do{
            if(isdigit(test[i])!=0){
                i=i+1;
            }
            else
                return false;
        }while(test[i]!='\0');
        
        return true;
    }

	VARS *rvar = NULL;
    VARSI *ivar = NULL;
    VARST *tvar = NULL;

    /* O nodetype serve para indicar o tipo de nó que está na árvore. Isso serve para a função eval entender o que realizar naquele no */
    typedef struct ast { /*Estrutura de um nó*/
        int nodetype;
        struct ast *l; /*Esquerda*/
        struct ast *r; /*Direita*/
    }Ast; 

    typedef struct intval { /*Estrutura de uma variavel inteira*/
        int nodetype;
        int v;
    }Intval;

    typedef struct realval { /* Estrutura de uma variavel real */
        int nodetype;
        double v;
    }Realval;

    typedef struct textoval { /*Estrutura de uma variavel texto*/
        int nodetype;
        char v[string_size];
    }Textoval;

    typedef struct varval { /*Estrutura de um nome de variável, nesse exemplo uma variável é um número no vetor var[26]*/
        int nodetype;
        char var[name_size];
        int size;
        Ast * n; /* carrega as declaracoes do mesmo tipo na mesma linha */
        Ast * pos; /* posicao no vetor */
    }Varval;

    typedef struct flow { /*Estrutura de um desvio (if/else/while)*/
	    int nodetype;
	    Ast *cond;		/*condição*/
	    Ast *tl;		/*then, ou seja, verdade*/
	    Ast *el;		/*else*/
    }Flow;

    /*Estrutura para um nó de atribuição. Para atrubuir o valor de v em s*/
    typedef struct symasgn { 
        int nodetype;
        char s[name_size];
        Ast *v;
        Ast *n;
        Ast * pos; /* posicao para atribuir um valor novo nela no array */
    }Symasgn;

    typedef struct function {
        int nodetype;
        int type;
		char name[name_size];
        Ast *v;
        struct function * prox;
	} Function;

    /*Função para criar um nó*/
    Ast * newast(int nodetype, Ast *l, Ast *r){ 

	    Ast *a = (Ast*) malloc(sizeof(Ast));
	    if(!a) {
		    printf("out of space");
		    exit(0);
	}
	    a->nodetype = nodetype;
	    a->l = l;
	    a->r = r;
	    return a;
    }

    /*Estrutura de um fluxo para o FOR*/
    typedef struct flowfor{ 
        int nodetype;
        Ast* v1;
        Ast* v2;
        Ast* v3;
    }Flowfor;

    /*Função que cria um nó de FOR*/
    Ast * newflowfor(int nodetype, Ast *b1, Ast *b2, Ast *b3, Ast *tl, Ast *el){ 
        Flow *a = (Flow*)malloc(sizeof(Flow));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        Flowfor *b = (Flowfor*)malloc(sizeof(Flowfor));
        if(!b) {
            printf("out of space");
            exit(0);
        }
        b->nodetype = 'F';
        b->v1 = b1;
        b->v2 = b2;
        b->v3 = b3;
        a->nodetype = nodetype;
        a->cond = (Ast*)b;
        a->tl = tl;
        a->el = el;
        return (Ast *)a;
    }

    /* Função de que cria um número inteiro (folha)*/
    Ast * newint(int d) {	
        Intval *a = (Intval*) malloc(sizeof(Intval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'k';
        a->v = d;
        return (Ast*)a;
    }


    /*Função de que cria um número real (folha)*/
    Ast * newreal(double d) {		
        Realval *a = (Realval*) malloc(sizeof(Realval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'K';
        a->v = d;
        return (Ast*)a;
    }

    /*Função de que cria um novo texto (folha)*/
    Ast * newtexto(char d[]) {			
        Textoval *a = (Textoval*) malloc(sizeof(Textoval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'm';
        strcpy(a->v, d);
        return (Ast*)a;
    }

    /*Função de que cria uma nova variável array*/
    Ast * newarray(int nodetype, char nome[], int tam, Ast* n) {
        Varval *a = (Varval*) malloc(sizeof(Varval) * tam);
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = nodetype;
        strcpy(a->var,nome);
        a->size = tam;
        a->n = n;
        return (Ast*)a;
    }

    /*Função que cria um nó de if/else/while*/
    Ast * newflow(int nodetype, Ast *cond, Ast *tl, Ast *el){ 
        Flow *a = (Flow*)malloc(sizeof(Flow));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = nodetype;
        a->cond = cond;
        a->tl = tl;
        a->el = el;
        return (Ast *)a;
    }

    /*Função que cria um nó para testes lógicos*/
    Ast * newcmp(int cmptype, Ast *l, Ast *r){
        Ast *a = (Ast*)malloc(sizeof(Ast));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = '0' + cmptype; /*Para pegar o tipe de teste, definido no arquivo.l e utilizar na função eval()*/
        a->l = l;
        a->r = r;
        return a;
    }

    /* Funcão que cria um nó para a variavel do tipo inteiro ou real ou texto e atribui o valor */
    Ast * newvar(int t, char s[], Ast *v, Ast *n){
        Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = t; /*tipo i, r ou t, conforme arquivo .l*/
        strcpy(a->s, s); /*Símbolo/variável*/
        a->v = v; /*Valor*/
        a->n = n; /*proxima declaração*/
        return (Ast *)a;
    }

    /*Função para um nó de atribuição*/
    Ast * newasgn(char s[], Ast *v) { 
        Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = '=';
        strcpy(a->s, s); /*Símbolo/variável*/
        a->v = v; /*Valor*/
        return (Ast *)a;
    }

     /*Função para um nó de atribuição em um array*/
    Ast * newasgn_a(char s[], Ast *v, Ast * pos) { 
        Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = 'D';
        strcpy(a->s, s); /*Símbolo/variável*/
        a->v = v; /*Valor*/
        a->pos = pos;
        return (Ast *)a;
    }

    /*Função que recupera o nome/referência de uma variável*/
    Ast * newValorVal(char s[]) { 
        Varval *a = (Varval*) malloc(sizeof(Varval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'N';
        strcpy(a->var, s);
        return (Ast*)a;
        
    }

    /*Função que recupera o nome/referência de um array */
    Ast * newValorVal_a(char s[], Ast * i) { 
        Varval *a = (Varval*) malloc(sizeof(Varval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'E';
        strcpy(a->var, s);
        a->pos = i;
        return (Ast*)a;
        
    }

    /*Função para criar um nó para salvar a funcao na lista de funcoes*/
    Ast * newfunction(int type, char n[], Ast *fun){
        Function *aux = (Function*)malloc(sizeof(Function));
        if(!aux){
            printf("out of space in newfuntion()");
            exit(1);
        }
        aux->nodetype = 'f';
        aux->type = type;
        strcpy(aux->name, n);
        aux->v = fun;
        return (Ast*)aux;
    }

    /* Verificar se a variavel existe na lista de variaveis */
    bool varexiste(char v[]) {
        VARS* xr = srch(rvar, v);
        VARSI* xi = srchi(ivar, v);
        VARST* xt = srcht(tvar, v);

    if(!xr && !xi && !xt) 
        return false; // se tudo NULL, variavel nao existe
    else
        return true;  // se tudo for TRUE, variavel existe
    }

    Function * listFunction = NULL;

    // Busca uma função por nome na lista de funções
    Function *srchfunction(Function *l, char n[]){
		Function *aux = l;
        //printf("open srchfuntion\n");
		while(aux != NULL){
			if(strcmp(n,aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
        //printf("function NULL\n");
		return aux;
	}

    /*Função que executa operações a partir de um nó*/
    double eval(Ast *a) { 
        double v;
        char v1[50];
        int pos;
        Function *auxFunction; //armazena o resultado da busca na lista de funções

        if(!a) {
            printf("internal error, null eval\n");
            return 0.0;
        }
        //printf("nodetype: %c\n", a->nodetype);
        switch(a->nodetype) {
            case 'k': v = ((Intval *)a)->v; break; 	/*Recupera um número inteiro*/
            case 'K': v = ((Realval *)a)->v; break; 	/*Recupera um número real*/
            case 'm': v = atof(((Textoval *)a)->v); break; 	/*Recupera um número real dentro de string*/
            case 'N':; /*  Verificar se foi realizado a declaracao da variavel corretamente */
                VARS * aux = (VARS*)malloc(sizeof(VARS));
                aux = srch(rvar, ((Varval*)a)->var);
                if (!aux){
                    VARSI * aux2 = (VARSI*)malloc(sizeof(VARSI));
                    aux2 = srchi(ivar, ((Varval*)a)->var);
                    if (!aux2){
                        VARST * aux3 = (VARST*)malloc(sizeof(VARST));
                        if(!aux3){
                                printf("out of space");
                                exit(0);
                            }
                        aux3 = srcht(tvar, ((Varval*)a)->var);
                        if (!aux3){
                            printf ("Erro 'sem valor'. Variavel '%s' nao foi declarada.\n", ((Varval*)a)->var);
                            v = 0.0;
                        }
                        else{
                            v = atof(aux3->v);
                        }
                    }
                    else{
                        v = (double)aux2->v;
                    }
                }
                else{
                    v = aux->v;
                }
                break;
            case '+': v = eval(a->l) + eval(a->r); break;	/*Operações "árv esq   +   árv dir"*/
            case '-': v = eval(a->l) - eval(a->r); break;	/*Operações de subtração */
            case '*': v = eval(a->l) * eval(a->r); break;	/*Operações de multiplicação */
            case '/': v = eval(a->l) / eval(a->r); break; /*Operação de divisão */
            case 'R': v = sqrt(eval(a->l)); break;				/*Operações RAIZ*/
            case 'M': v = -eval(a->l); break;				/*Operações, número negativo*/
            case '|': v = fabs(eval(a->l)); break;          /*Operações de módulo*/

            case '1': v = (eval(a->l) > eval(a->r))? 1 : 0; break;	/* Operações lógicas. "árv esq   >   árv dir"  Se verdade 1, falso 0 */
            case '2': v = (eval(a->l) < eval(a->r))? 1 : 0; break;
            case '3': v = (eval(a->l) != eval(a->r))? 1 : 0; break;
            case '4': v = (eval(a->l) == eval(a->r))? 1 : 0; break;
            case '5': v = (eval(a->l) >= eval(a->r))? 1 : 0; break;
            case '6': v = (eval(a->l) <= eval(a->r))? 1 : 0; break;
            case '7': v = (eval(a->l) || eval(a->r))? 1 : 0; break;
            case '8': v = (eval(a->l) && eval(a->r))? 1 : 0; break;
            case '?': (eval(((Flow *)a)->cond)) != 0 ? eval(((Flow *)a)->tl) : eval(((Flow *)a)->el); break; /* Case para operador iterator */
            
            /* Atribuicao */
            case '=':;
                v = eval(((Symasgn *)a)->v); /*Recupera o valor*/
                
                VARS * x = (VARS*)malloc(sizeof(VARS));
                if(!x) {
                    printf("out of space");
                    exit(0);
                }
                x = srch(rvar, ((Symasgn *)a)->s);
                if(!x){
                    VARSI * xi = (VARSI*)malloc(sizeof(VARSI));
                    if(!xi) {
                        printf("out of space");
                        exit(0);
                    }
                    xi = srchi(ivar, ((Symasgn *)a)->s);
                    if(!xi){
                        printf("Erro 'atribuir valor'. Var '%s' nao declarada.\n", ((Symasgn *)a)->s);
                    } else
                        xi->v = (int)v; /*Atribui à variável*/
                } else {
                    x->v = v;   /*Atribui à variável*/
                }
                break;

            /* caso if ou if/else */
            case 'I': 
                if (eval(((Flow *)a)->cond) != 0) {	/*executa a condição / teste*/
                    if (((Flow *)a)->tl)		/*Se existir árvore*/
                        v = eval(((Flow *)a)->tl); /*Verdade*/
                    else
                        v = 0.0;
                } else {
                    if( ((Flow *)a)->el) {
                        v = eval(((Flow *)a)->el); /*Falso*/
                    } else
                        v = 0.0;
                    }
                break;

            /* caso while */
            case 'W':
                v = 0.0;
                if( ((Flow *)a)->tl) {
                    while( eval(((Flow *)a)->cond) != 0){
                        v = eval(((Flow *)a)->tl);
                        }
                }
            break;

            // leitura das variaveis: int, real e texto
            case 'c':; 
                //v = eval(((Symasgn *)a)->v); /*Recupera o valor*/
                VARS * xcr = (VARS*)malloc(sizeof(VARS));
                if(!xcr) {
                    printf("out of space");
                    exit(0);
                }
                xcr = srch(rvar, ((Varval *)a->l)->var);
                if(xcr){
                    scanf("%f", &xcr->v);
                } else {
                    VARSI * xci = (VARSI*)malloc(sizeof(VARSI));
                    if(!xci) {
                        printf("out of space");
                        exit(0);
                    }
                    xci = srchi(ivar, ((Varval *)a->l)->var);
                    if(xci){
                        scanf("%d", &xci->v);
                    } else {
                        VARST * xct = (VARST*)malloc(sizeof(VARST));
                        if(!xct) {
                            printf("out of space");
                            exit(0);
                        }
                        xct = srcht(tvar, ((Varval *)a->l)->var);
                        if(xct){
                            scanf("%s", xct->v);
                        } else {
                            printf("Variavel inválida!\n");
                        }
                    }
                }
                break;
            
            case 'L': eval(a->l); v = eval(a->r); break; /*Lista de operções em um bloco IF/ELSE/WHILE. Assim o analisador não se perde entre os blocos*/
            case 'n': 
            { /* printar os tipos de variaveis corretamente na saída */
                VARS * auxn = (VARS*)malloc(sizeof(VARS));
                auxn = srch(rvar, ((Varval*)a)->var);
                if (!auxn){
                    VARSI * auxn2 = srchi(ivar, ((Varval*)a)->var);
                    if (!auxn2){
                        VARST * auxn3 = srcht(tvar, ((Varval*)a)->var);
                        if (!auxn3){
                            printf ("359 - Variavel '%s' nao foi declarada.\n", ((Varval*)a)->var);
                            v = 0.0;
                        }
                        else{
                            Ast * auxnt = (Ast*)malloc(sizeof(Ast));
                            if(!auxnt){
                                printf("out of space");
                                exit(0);
                            }
                            printf("%s", auxn3->v);
                            v = atof(auxn3->v);
                        }
                    }
                    else{
                        Ast * auxni = (Ast*)malloc(sizeof(Ast));
                        if(!auxni){
                            printf("out of space");
                            exit(0);
                        }
                        printf("%d", auxn2->v);
                        v = (double)auxn2->v;
                    }
                }
                else{
                    Ast * auxnr = (Ast*)malloc(sizeof(Ast));
                    if(!auxnr){
                        printf("out of space");
                        exit(0);
                    }
                    printf("%.2f", auxn->v);
                    v = auxn->v;
                }
                break;
            }
            /* O case P é um comando de print geral, mas ele não trabalha pesado,
            *  o case 'n' ajuda quando precisar imprimir variaveis
            */
            case 'P': 
                //printf("P1: %c\nP2: %c\n", a->nodetype, a->l->nodetype);
                if(a->l==NULL)
                    break;
                /* printf("node %c\n", a->l->nodetype);*/
                if (a->l->nodetype == 'E') {
                    a->l->nodetype = 'H';
                    v = eval(a->l);
                }
                else if(a->l->nodetype == 'N'){
                    a->l->nodetype = 'n';
                    v = eval(a->l);
                    //printf("\nnodetype 'N'\n");
                } else {
                    v = eval(a->l);
                    if(a->l->nodetype != 'n' && a->l->nodetype != 'k' && a->l->nodetype != 'K' && a->l->nodetype != 'm' && a->l->nodetype != 'H')
                        printf("%.2f", v);
                }
                if(((Intval*)a->l)->nodetype == 'k') {
                    printf ("%d", ((Intval*)a->l)->v);		/*Recupera um valor inteiro*/
                }
                else if(((Realval*)a->l)->nodetype == 'K') {
                    printf ("%.2f", ((Realval*)a->l)->v);		/*Recupera um valor real*/
                }
                else if(((Textoval*)a->l)->nodetype == 'm') {
                    if(strcmp(((Textoval*)a->l)->v, "\\n")==0)
                        printf("\n");
                    else
                        printf ("%s", ((Textoval*)a->l)->v);		/*Recupera um valor texto*/
                }
                if(a->r==NULL){
                    /* printf("\n");*/ 
                    /* printf("Quebra linha entra variaveis"); */
                }else{
                    v = eval(a->r);
                    /* printf("\n");*/
                }
                break; 
            /* caso para a opcao FOR */
            case 'F':
                v = 0.0;
                if( ((Flow *)a)->tl ) {
                    for(eval(((Flowfor*)((Flow *)a)->cond)->v1); 
                        eval(((Flowfor*)((Flow *)a)->cond)->v2); 
                        eval(((Flowfor*)((Flow *)a)->cond)->v3)
                        ){
                            v =  eval(((Flow *)a)->tl);
                    }
                }
                break;
            // declaracao da variavel inteira
            case 'i':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);

                if(!varexiste(((Symasgn *)a)->s)){
                    ivar = insi(ivar, ((Symasgn *)a)->s);
                    VARSI * xi = (VARSI*)malloc(sizeof(VARSI));
                    if(!xi) {
                        printf("out of space");
                        exit(0);
                    }
                    xi = srchi(ivar, ((Symasgn *)a)->s);
                    if(((Symasgn *)a)->v)
                        xi->v = (int)eval(((Symasgn *)a)->v); /*Atribui à variável*/
                }else{
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                }
                break;
            // declaracao da variavel real
            case 'r':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);

                if(!varexiste(((Symasgn *)a)->s)){
                    rvar = ins(rvar, ((Symasgn *)a)->s);
                    VARS * xr = (VARS*)malloc(sizeof(VARS));
                    if(!xr) {
                        printf("out of space");
                        exit(0);
                    }
                    xr = srch(rvar, ((Symasgn *)a)->s);
                    if(((Symasgn *)a)->v)
                        xr->v = eval(((Symasgn *)a)->v);
                }else
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                break;
            // declara a variavel texto
            case 't':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);

                if(!varexiste(((Symasgn *)a)->s)){
                    tvar = inst(tvar, ((Symasgn *)a)->s);
                    VARST * xt = (VARST*)malloc(sizeof(VARST));
                    if(!xt) {
                        printf("out of space");
                        exit(0);
                    }
                    xt = srcht(tvar, ((Symasgn *)a)->s);
                    if((((Symasgn *)a)->v))
                        strcpy(xt->v, ((Textoval*)((Symasgn*)a)->v)->v);
                }else
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                break;
            /* Case referente a execucao da funcao */    
            case 'a':;
                auxFunction = srchfunction(listFunction, ((Textoval*)a->l)->v);
                if(auxFunction != NULL) {
                   eval(auxFunction->v);
                }
                else {
                    printf("\nErro (case 'a'): chamada de funcao errada\n");
                }
                break;
            /* Case para adicionar uma funcao em uma lista de funcoes */
            case 'f':;
                if(srchfunction(listFunction, ((Function*)a)->name) == NULL) {
                    ((Function*)a)->prox = listFunction; //faz o elemento atual apontar o inicio da lista
                    listFunction = (Function*)a; // faz o elemento atual ser o inicio da lista
                }else{
                    printf("\nErro (case 'f'): reescrita de funcao nao permitada.\n");
                    printf("Function %s\n", ((Function*)a)->name);
                }
                break;
            case 'z':;
                printf("THATS ALL FOLKS\n");
                free(ivar);
                ivar = NULL;
                free(rvar);
                rvar = NULL;
                free(tvar);
                tvar = NULL;
                exit(0);
                break;
            case 'A':; //inserir uma array de inteiros
                if(((Varval*)a)->n)
                    eval(((Varval*)a)->n);

                if(!varexiste(((Varval*)a)->var)){
                    ivar = insi_a(ivar,((Varval*)a)->var,((Varval*)a)->size);
                }else{
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                }
                break;
            case 'B':; //inserir uma array de real
                if(((Varval*)a)->n)
                    eval(((Varval*)a)->n);

                if(!varexiste(((Varval*)a)->var)){
                    rvar  = ins_a(rvar,((Varval*)a)->var,((Varval*)a)->size);
                }else{
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                }
                break;
            case 'C':; //inserir uma array de texto
                if(((Varval*)a)->n)
                    eval(((Varval*)a)->n);

                if(!varexiste(((Varval*)a)->var)){
                    tvar = inst_a(tvar,((Varval*)a)->var,((Varval*)a)->size);
                }else{
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                }
                break;
            case 'D':; //atribuir em um array 
                v = eval(((Symasgn *)a)->v);  //valor que sera atriuido no array
                pos = (int)eval(((Symasgn *)a)->pos);
                VARS * vx = srch(rvar, ((Symasgn *)a)->s);
                VARSI * vxi = srchi(ivar, ((Symasgn *)a)->s);
                VARST * vxt = srcht(tvar, ((Symasgn *)a)->s);

                if(vx != NULL){
                    vx->vet[pos] = v; /*Atribui à variável*/
                } else if (vxi != NULL) {
                    vxi->vet[pos] = (int)v; /*Atribui à variável*/
                } else if (vxt != NULL) {
                    VARST * auxVxt = srcht(tvar, ((Textoval*)((Symasgn*)a)->v)->v);
                    if (auxVxt != NULL) {
                        vxt->vet[pos] = auxVxt->v;
                    }
                    else {
                        vxt->vet[pos] = ((Textoval*)((Symasgn*)a)->v)->v; /*Atribui à variável*/
                    }
                } else {
                    printf("Erro 'atribuir valor'. Var '%s' nao declarada.\n", ((Symasgn *)a)->s);
                }
                break;
            case 'E':; /*  Verificar se foi realizado a declaracao da variavel corretamente */
                pos = (int)eval(((Varval *)a)->pos);
                VARS * evx = srch(rvar, ((Varval *)a)->var);
                VARSI * evxi = srchi(ivar, ((Varval *)a)->var);
                VARST * evxt = srcht(tvar, ((Varval *)a)->var);

                if(evx != NULL){
                    v = evx->vet[pos];
                } else if (evxi != NULL) {
                    v = evxi->vet[pos];
                } else if (evxt != NULL) {
                    v = atof(evxt->vet[pos]);
                }

                break;

            // leitura das variaveis: int, real e texto de um array array
            case 'G':; 
                VARSI * posvxi = srchi(ivar, ((Varval *)a->r)->var);
                if(posvxi != NULL){
                   pos = posvxi->v;
                }
    
                VARS * apvx = srch(rvar, ((Varval *)a->l)->var);
                VARSI * apvxi = srchi(ivar, ((Varval *)a->l)->var);
                VARST * apvxt = srcht(tvar, ((Varval *)a->l)->var);

                if(apvx != NULL){
                    scanf("%f", &apvx->vet[pos]); 
                } else if (apvxi != NULL) {
                    scanf("%d", &apvxi->vet[pos]);
                } else if (apvxt != NULL) {
                    scanf("%s", apvxt->vet[pos]);
                }
                break;
            case 'H':; /*  imprimir array */
                pos = (int)eval(((Varval *)a)->pos);
                VARS * pvx = srch(rvar, ((Varval *)a)->var);
                VARSI * pvxi = srchi(ivar, ((Varval *)a)->var);
                VARST * pvxt = srcht(tvar, ((Varval *)a)->var);

                if(pvx != NULL){
                    v = pvx->vet[pos];
                    printf("%.2f\n", pvx->vet[pos]); 
                } else if (pvxi != NULL) {
                    v = pvxi->vet[pos];
                    printf("%d\n", pvxi->vet[pos]);
                } else if (pvxt != NULL) {
                    v = 0.0;
                    printf("%s\n", pvxt->vet[pos]);
                } 

                break;

            default: printf("internal error: bad node %c\n", a->nodetype);
        }
        return v;
    }



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 902 "vetor.y"
{
    char texto[50];
    double real;
    int inteiro;
    int fn;
    Ast *ast;
}
/* Line 193 of yacc.c.  */
#line 1061 "vetor.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 1074 "vetor.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    31,    28,    26,    44,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    41,
       2,    25,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      33,    34,    35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    12,    20,    32,    40,    44,
      48,    55,    62,    69,    71,    73,    78,    83,    91,    99,
     111,   113,   116,   119,   121,   123,   130,   133,   136,   138,
     147,   151,   155,   161,   168,   171,   176,   179,   184,   190,
     196,   200,   207,   213,   216,   221,   227,   229,   233,   235,
     239,   241,   244,   248,   253,   257,   261,   265,   269,   273,
     277,   281,   284,   286,   288,   290,   292,   297
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    18,    47,    19,    -1,    48,    -1,    47,
      48,    -1,    14,    32,    57,    31,    37,    55,    38,    -1,
      14,    32,    57,    31,    37,    55,    38,    15,    37,    55,
      38,    -1,    16,    32,    57,    31,    37,    55,    38,    -1,
       5,    25,    57,    -1,     5,    25,     7,    -1,     5,    39,
       4,    40,    25,    57,    -1,     5,    39,     5,    40,    25,
      57,    -1,     5,    39,     4,    40,    25,     7,    -1,    52,
      -1,    53,    -1,    22,    32,    54,    31,    -1,    21,    32,
       5,    31,    -1,    21,    32,     5,    39,     4,    40,    31,
      -1,    21,    32,     5,    39,     5,    40,    31,    -1,    17,
      32,    56,    41,    57,    41,    48,    31,    37,    55,    38,
      -1,    49,    -1,     5,     8,    -1,     5,     9,    -1,    23,
      -1,    51,    -1,    57,    42,    50,    43,    50,    41,    -1,
       5,     8,    -1,     5,     9,    -1,    57,    -1,    13,     6,
       5,    32,    31,    37,    55,    38,    -1,     5,    32,    31,
      -1,    52,    44,     5,    -1,    52,    44,     5,    25,    57,
      -1,    52,    44,     5,    39,     4,    40,    -1,    11,     5,
      -1,    11,     5,    25,    57,    -1,    10,     5,    -1,    10,
       5,    25,    57,    -1,    11,     5,    39,     4,    40,    -1,
      10,     5,    39,     4,    40,    -1,    53,    44,     5,    -1,
      53,    44,     5,    39,     4,    40,    -1,    53,    44,     5,
      25,     7,    -1,    12,     5,    -1,    12,     5,    25,     7,
      -1,    12,     5,    39,     4,    40,    -1,    57,    -1,    57,
      44,    54,    -1,     7,    -1,     7,    44,    54,    -1,    48,
      -1,    55,    48,    -1,     5,    25,    57,    -1,    20,    32,
      57,    31,    -1,    57,    26,    57,    -1,    57,    27,    57,
      -1,    57,    28,    57,    -1,    57,    29,    57,    -1,    32,
      57,    31,    -1,    57,    30,    57,    -1,    57,    24,    57,
      -1,    27,    57,    -1,    58,    -1,     4,    -1,     3,    -1,
       5,    -1,     5,    39,     4,    40,    -1,     5,    39,     5,
      40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   949,   949,   953,   954,   958,   959,   960,   961,   962,
     963,   964,   965,   966,   967,   968,   969,   970,   971,   972,
     973,   974,   975,   976,   977,   981,   985,   986,   987,   989,
     990,   994,   999,  1004,  1009,  1010,  1011,  1012,  1013,  1014,
    1018,  1019,  1020,  1021,  1022,  1023,  1027,  1028,  1029,  1030,
    1034,  1035,  1039,  1043,  1046,  1049,  1052,  1055,  1058,  1061,
    1064,  1067,  1070,  1076,  1077,  1078,  1079,  1080
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM_REAL", "NUM_INT", "VARIAVEIS",
  "FUNC", "STRING", "MAIS", "MENOS", "TIPO_REAL", "TIPO_INT", "TIPO_TEXT",
  "VOID", "IF", "ELSE", "WHILE", "FOR", "INICIO", "FIM", "RAIZ", "LEITURA",
  "ESCRITA", "COMENTARIO", "CMP", "'='", "'+'", "'-'", "'*'", "'/'", "'^'",
  "')'", "'('", "VET", "FUN", "NEG", "IFX", "'{'", "'}'", "'['", "']'",
  "';'", "'?'", "':'", "','", "$accept", "begin", "body", "exp",
  "ternario", "exp2", "function", "decl", "decl2", "escrever", "list",
  "var", "arit", "valores", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    61,    43,    45,    42,    47,
      94,    41,    40,   280,   281,   282,   283,   123,   125,    91,
      93,    59,    63,    58,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    50,    50,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    53,    53,    53,    53,    54,    54,    54,    54,
      55,    55,    56,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    58,    58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     2,     7,    11,     7,     3,     3,
       6,     6,     6,     1,     1,     4,     4,     7,     7,    11,
       1,     2,     2,     1,     1,     6,     2,     2,     1,     8,
       3,     3,     5,     6,     2,     4,     2,     4,     5,     5,
       3,     6,     5,     2,     4,     5,     1,     3,     1,     3,
       1,     2,     3,     4,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     1,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    64,    63,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       3,    20,    24,    13,    14,     0,    62,     1,    21,    22,
       0,     0,     0,    36,    34,    43,     0,     0,     0,     0,
       0,     0,     0,    65,    61,     0,     2,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     8,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,    46,     0,    58,
      31,    40,    60,    54,    55,    56,    57,    59,    65,     0,
      28,    66,    67,    37,     0,    35,     0,    44,     0,     0,
       0,     0,     0,     0,    53,    16,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,    26,    27,     0,     0,
       0,    39,    38,    45,     0,     0,     0,    52,     0,     0,
       0,    49,    47,    66,    67,    32,     0,    42,     0,     0,
      12,    10,    11,     0,    50,     0,     0,     0,     0,     0,
      33,    41,    25,     0,     5,    51,     7,     0,    17,    18,
      29,     0,     0,     0,     0,     0,     0,     6,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    19,   144,    21,    89,    22,    23,    24,    76,
     145,    72,    25,    26
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -121
static const yytype_int16 yypact[] =
{
      -9,   261,    17,  -121,  -121,    22,    20,    47,    60,    39,
      44,    58,    69,    78,    81,    82,  -121,   150,   150,   236,
    -121,  -121,  -121,    41,    48,   277,  -121,  -121,  -121,  -121,
       0,    93,     8,   -10,    -6,     3,   120,   150,   150,   129,
     150,   142,   116,   122,  -121,   111,  -121,  -121,   166,   167,
     150,   150,   150,   150,   150,   150,   291,  -121,   102,  -121,
     134,   135,   150,   172,   150,   179,   178,   187,   162,   305,
     314,   170,   159,   322,   -23,   158,   173,    53,    67,  -121,
      49,    50,  -121,   177,   177,    40,    40,    40,     2,   169,
     102,   188,   190,   102,   181,   102,   184,  -121,   185,   199,
     194,   195,   150,   150,  -121,  -121,    90,   116,  -121,   116,
     196,   197,   150,   230,   228,   238,  -121,  -121,   291,   282,
     150,  -121,  -121,  -121,   208,   261,   261,   102,   298,   203,
     211,  -121,  -121,  -121,  -121,   102,   214,  -121,   220,   221,
    -121,   102,   102,   261,  -121,    46,    95,   261,   239,   245,
    -121,  -121,  -121,   146,   246,  -121,  -121,   248,  -121,  -121,
    -121,   232,   243,   261,   261,   176,   206,  -121,  -121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,    -1,  -121,   149,  -121,  -121,  -121,   -54,
    -120,  -121,   -16,  -121
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      20,    44,    45,     3,     4,    43,   146,    57,   105,     1,
     116,   117,    60,    61,    58,    62,   106,    27,    47,    64,
      13,    69,    70,   153,    73,    33,    77,    17,    66,    63,
      28,    29,    18,    65,    82,    83,    84,    85,    86,    87,
      90,    78,    67,   165,   166,    36,    93,    30,    95,     3,
       4,     5,    34,   131,    31,   132,     6,     7,     8,     9,
      10,    32,    11,    12,    50,    35,    13,    14,    15,    16,
      55,   110,   111,    17,   112,   114,    37,    50,    18,    51,
      52,    53,    54,    55,   154,    48,   127,   128,   113,   115,
      38,    77,    49,    77,   129,   130,   135,   109,     3,     4,
       5,    39,    90,   141,   142,     6,     7,     8,     9,    10,
      40,    11,    12,    41,    42,    13,    14,    15,    16,     3,
       4,    43,    17,    75,    59,    68,    50,    18,    51,    52,
      53,    54,    55,   156,    71,    50,    13,    51,    52,    53,
      54,    55,    79,    17,   155,   155,   157,    74,    18,     3,
       4,     5,   155,     3,     4,    43,     6,     7,     8,     9,
      10,    78,    11,    12,   155,   155,    13,    14,    15,    16,
      13,    80,    81,    17,    91,    92,    94,    17,    18,     3,
       4,     5,    18,    96,   160,    97,     6,     7,     8,     9,
      10,    98,    11,    12,    99,   102,    13,    14,    15,    16,
     103,    50,   107,    17,   108,    53,    54,    55,    18,     3,
       4,     5,   118,   119,   167,   120,     6,     7,     8,     9,
      10,   121,    11,    12,   122,   123,    13,    14,    15,    16,
     124,   125,   126,    17,   136,   137,   133,   134,    18,     3,
       4,     5,   138,   148,   168,   143,     6,     7,     8,     9,
      10,   149,    11,    12,   150,    46,    13,    14,    15,    16,
     151,   161,   152,    17,     3,     4,     5,   139,    18,   163,
     158,     6,     7,     8,     9,    10,   159,    11,    12,   162,
     164,    13,    14,    15,    16,     3,     4,    43,    17,   140,
       0,     0,     0,    18,     3,     4,    88,     0,     0,     0,
       0,    50,    13,    51,    52,    53,    54,    55,     0,    17,
       0,    13,     0,     0,    18,     0,     0,     0,    17,    56,
       0,     0,    50,    18,    51,    52,    53,    54,    55,    50,
       0,    51,    52,    53,    54,    55,   100,     0,    50,   147,
      51,    52,    53,    54,    55,   101,    50,     0,    51,    52,
      53,    54,    55,   104
};

static const yytype_int16 yycheck[] =
{
       1,    17,    18,     3,     4,     5,   126,     7,    31,    18,
       8,     9,     4,     5,    30,    25,    39,     0,    19,    25,
      20,    37,    38,   143,    40,     5,    42,    27,    25,    39,
       8,     9,    32,    39,    50,    51,    52,    53,    54,    55,
      56,    39,    39,   163,   164,     6,    62,    25,    64,     3,
       4,     5,     5,   107,    32,   109,    10,    11,    12,    13,
      14,    39,    16,    17,    24,     5,    20,    21,    22,    23,
      30,     4,     5,    27,    25,    25,    32,    24,    32,    26,
      27,    28,    29,    30,    38,    44,   102,   103,    39,    39,
      32,   107,    44,   109,     4,     5,   112,    44,     3,     4,
       5,    32,   118,   119,   120,    10,    11,    12,    13,    14,
      32,    16,    17,    32,    32,    20,    21,    22,    23,     3,
       4,     5,    27,     7,    31,     5,    24,    32,    26,    27,
      28,    29,    30,    38,     5,    24,    20,    26,    27,    28,
      29,    30,    31,    27,   145,   146,   147,     5,    32,     3,
       4,     5,   153,     3,     4,     5,    10,    11,    12,    13,
      14,    39,    16,    17,   165,   166,    20,    21,    22,    23,
      20,     5,     5,    27,    40,    40,     4,    27,    32,     3,
       4,     5,    32,     4,    38,     7,    10,    11,    12,    13,
      14,     4,    16,    17,    32,    25,    20,    21,    22,    23,
      41,    24,    44,    27,    31,    28,    29,    30,    32,     3,
       4,     5,    43,    25,    38,    25,    10,    11,    12,    13,
      14,    40,    16,    17,    40,    40,    20,    21,    22,    23,
      31,    37,    37,    27,     4,     7,    40,    40,    32,     3,
       4,     5,     4,    40,    38,    37,    10,    11,    12,    13,
      14,    40,    16,    17,    40,    19,    20,    21,    22,    23,
      40,    15,    41,    27,     3,     4,     5,   118,    32,    37,
      31,    10,    11,    12,    13,    14,    31,    16,    17,    31,
      37,    20,    21,    22,    23,     3,     4,     5,    27,     7,
      -1,    -1,    -1,    32,     3,     4,     5,    -1,    -1,    -1,
      -1,    24,    20,    26,    27,    28,    29,    30,    -1,    27,
      -1,    20,    -1,    -1,    32,    -1,    -1,    -1,    27,    42,
      -1,    -1,    24,    32,    26,    27,    28,    29,    30,    24,
      -1,    26,    27,    28,    29,    30,    31,    -1,    24,    41,
      26,    27,    28,    29,    30,    31,    24,    -1,    26,    27,
      28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    46,     3,     4,     5,    10,    11,    12,    13,
      14,    16,    17,    20,    21,    22,    23,    27,    32,    47,
      48,    49,    51,    52,    53,    57,    58,     0,     8,     9,
      25,    32,    39,     5,     5,     5,     6,    32,    32,    32,
      32,    32,    32,     5,    57,    57,    19,    48,    44,    44,
      24,    26,    27,    28,    29,    30,    42,     7,    57,    31,
       4,     5,    25,    39,    25,    39,    25,    39,     5,    57,
      57,     5,    56,    57,     5,     7,    54,    57,    39,    31,
       5,     5,    57,    57,    57,    57,    57,    57,     5,    50,
      57,    40,    40,    57,     4,    57,     4,     7,     4,    32,
      31,    31,    25,    41,    31,    31,    39,    44,    31,    44,
       4,     5,    25,    39,    25,    39,     8,     9,    43,    25,
      25,    40,    40,    40,    31,    37,    37,    57,    57,     4,
       5,    54,    54,    40,    40,    57,     4,     7,     4,    50,
       7,    57,    57,    37,    48,    55,    55,    41,    40,    40,
      40,    40,    41,    55,    38,    48,    38,    48,    31,    31,
      38,    15,    31,    37,    37,    55,    55,    38,    38
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 949 "vetor.y"
    {eval(newast('z', NULL, NULL));;}
    break;

  case 3:
#line 953 "vetor.y"
    {eval((yyvsp[(1) - (1)].ast));;}
    break;

  case 4:
#line 954 "vetor.y"
    {eval((yyvsp[(2) - (2)].ast));;}
    break;

  case 5:
#line 958 "vetor.y"
    {(yyval.ast) = newflow('I', (yyvsp[(3) - (7)].ast), (yyvsp[(6) - (7)].ast), NULL);;}
    break;

  case 6:
#line 959 "vetor.y"
    {(yyval.ast) = newflow('I', (yyvsp[(3) - (11)].ast), (yyvsp[(6) - (11)].ast), (yyvsp[(10) - (11)].ast));;}
    break;

  case 7:
#line 960 "vetor.y"
    {(yyval.ast) = newflow('W', (yyvsp[(3) - (7)].ast), (yyvsp[(6) - (7)].ast), NULL);;}
    break;

  case 8:
#line 961 "vetor.y"
    {(yyval.ast) = newasgn((yyvsp[(1) - (3)].texto), (yyvsp[(3) - (3)].ast));;}
    break;

  case 9:
#line 962 "vetor.y"
    {(yyval.ast) = newasgn((yyvsp[(1) - (3)].texto), newtexto((yyvsp[(3) - (3)].texto)));;}
    break;

  case 10:
#line 963 "vetor.y"
    {(yyval.ast) = newasgn_a((yyvsp[(1) - (6)].texto), (yyvsp[(6) - (6)].ast), newint((yyvsp[(3) - (6)].inteiro)));;}
    break;

  case 11:
#line 964 "vetor.y"
    {(yyval.ast) = newasgn_a((yyvsp[(1) - (6)].texto), (yyvsp[(6) - (6)].ast), newValorVal((yyvsp[(3) - (6)].texto)));;}
    break;

  case 12:
#line 965 "vetor.y"
    {(yyval.ast) = newasgn_a((yyvsp[(1) - (6)].texto), newtexto((yyvsp[(6) - (6)].texto)), newint((yyvsp[(3) - (6)].inteiro)));;}
    break;

  case 13:
#line 966 "vetor.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast) ;;}
    break;

  case 14:
#line 967 "vetor.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast) ;;}
    break;

  case 15:
#line 968 "vetor.y"
    {(yyval.ast) = (yyvsp[(3) - (4)].ast);;}
    break;

  case 16:
#line 969 "vetor.y"
    {(yyval.ast) = newast('c', newValorVal((yyvsp[(3) - (4)].texto)), NULL);;}
    break;

  case 17:
#line 970 "vetor.y"
    {(yyval.ast) = newast('G', newValorVal((yyvsp[(3) - (7)].texto)), newint((yyvsp[(5) - (7)].inteiro)));;}
    break;

  case 18:
#line 971 "vetor.y"
    {(yyval.ast) = newast('G', newValorVal((yyvsp[(3) - (7)].texto)), newValorVal((yyvsp[(5) - (7)].texto)));;}
    break;

  case 19:
#line 972 "vetor.y"
    { (yyval.ast) = newflowfor('F', (yyvsp[(3) - (11)].ast), (yyvsp[(5) - (11)].ast), (yyvsp[(7) - (11)].ast), (yyvsp[(10) - (11)].ast), NULL);;}
    break;

  case 20:
#line 973 "vetor.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 21:
#line 974 "vetor.y"
    {(yyval.ast) = newasgn((yyvsp[(1) - (2)].texto), newast('+',newValorVal((yyvsp[(1) - (2)].texto)),newint(1)));;}
    break;

  case 22:
#line 975 "vetor.y"
    {(yyval.ast) = newasgn((yyvsp[(1) - (2)].texto), newast('-',newValorVal((yyvsp[(1) - (2)].texto)),newint(1)));;}
    break;

  case 23:
#line 976 "vetor.y"
    {(yyval.ast) = newast('P', NULL, NULL);;}
    break;

  case 24:
#line 977 "vetor.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast) ;;}
    break;

  case 25:
#line 981 "vetor.y"
    {(yyval.ast) = newflow('?', (yyvsp[(1) - (6)].ast), (yyvsp[(3) - (6)].ast), (yyvsp[(5) - (6)].ast));;}
    break;

  case 26:
#line 985 "vetor.y"
    {(yyval.ast) = newasgn((yyvsp[(1) - (2)].texto), newast('+',newValorVal((yyvsp[(1) - (2)].texto)),newint(1)));;}
    break;

  case 27:
#line 986 "vetor.y"
    {(yyval.ast) = newasgn((yyvsp[(1) - (2)].texto), newast('-',newValorVal((yyvsp[(1) - (2)].texto)),newint(1)));;}
    break;

  case 28:
#line 987 "vetor.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast) ;;}
    break;

  case 29:
#line 989 "vetor.y"
    {(yyval.ast) = newfunction((yyvsp[(1) - (8)].inteiro), (yyvsp[(3) - (8)].texto), (yyvsp[(7) - (8)].ast));;}
    break;

  case 30:
#line 990 "vetor.y"
    {(yyval.ast) = newast('a', newtexto((yyvsp[(1) - (3)].texto)), NULL);;}
    break;

  case 31:
#line 994 "vetor.y"
    {
        if ((yyvsp[(1) - (3)].ast)->nodetype=='A') (yyval.ast) = newvar('i', (yyvsp[(3) - (3)].texto), NULL, (yyvsp[(1) - (3)].ast));
        else if ((yyvsp[(1) - (3)].ast)->nodetype=='B') (yyval.ast) = newvar('r', (yyvsp[(3) - (3)].texto), NULL, (yyvsp[(1) - (3)].ast));
        else (yyval.ast) = newvar((yyvsp[(1) - (3)].ast)->nodetype, (yyvsp[(3) - (3)].texto), NULL, (yyvsp[(1) - (3)].ast));
    ;}
    break;

  case 32:
#line 999 "vetor.y"
    {
        if ((yyvsp[(1) - (5)].ast)->nodetype=='A') (yyval.ast) = newvar('i', (yyvsp[(3) - (5)].texto), (yyvsp[(5) - (5)].ast), (yyvsp[(1) - (5)].ast));
        else if ((yyvsp[(1) - (5)].ast)->nodetype=='B') (yyval.ast) = newvar('r', (yyvsp[(3) - (5)].texto), (yyvsp[(5) - (5)].ast), (yyvsp[(1) - (5)].ast));
        else (yyval.ast) = newvar((yyvsp[(1) - (5)].ast)->nodetype, (yyvsp[(3) - (5)].texto), (yyvsp[(5) - (5)].ast), (yyvsp[(1) - (5)].ast));
    ;}
    break;

  case 33:
#line 1004 "vetor.y"
    {
        if ((yyvsp[(1) - (6)].ast)->nodetype=='i') (yyval.ast) = newarray('A', (yyvsp[(3) - (6)].texto), (yyvsp[(5) - (6)].inteiro), (yyvsp[(1) - (6)].ast));
        else if ((yyvsp[(1) - (6)].ast)->nodetype=='r') (yyval.ast) = newarray('B', (yyvsp[(3) - (6)].texto), (yyvsp[(5) - (6)].inteiro), (yyvsp[(1) - (6)].ast));
        else (yyval.ast) = newarray((yyvsp[(1) - (6)].ast)->nodetype, (yyvsp[(3) - (6)].texto), (yyvsp[(5) - (6)].inteiro), (yyvsp[(1) - (6)].ast));
    ;}
    break;

  case 34:
#line 1009 "vetor.y"
    {(yyval.ast) = newvar((yyvsp[(1) - (2)].inteiro), (yyvsp[(2) - (2)].texto), NULL, NULL);;}
    break;

  case 35:
#line 1010 "vetor.y"
    {(yyval.ast) = newvar((yyvsp[(1) - (4)].inteiro), (yyvsp[(2) - (4)].texto), (yyvsp[(4) - (4)].ast), NULL);;}
    break;

  case 36:
#line 1011 "vetor.y"
    {(yyval.ast) = newvar((yyvsp[(1) - (2)].inteiro), (yyvsp[(2) - (2)].texto), NULL, NULL);;}
    break;

  case 37:
#line 1012 "vetor.y"
    {(yyval.ast) = newvar((yyvsp[(1) - (4)].inteiro), (yyvsp[(2) - (4)].texto), (yyvsp[(4) - (4)].ast), NULL);;}
    break;

  case 38:
#line 1013 "vetor.y"
    { (yyval.ast) = newarray('A', (yyvsp[(2) - (5)].texto), (yyvsp[(4) - (5)].inteiro), NULL);;}
    break;

  case 39:
#line 1014 "vetor.y"
    { (yyval.ast) = newarray('B', (yyvsp[(2) - (5)].texto), (yyvsp[(4) - (5)].inteiro), NULL);;}
    break;

  case 40:
#line 1018 "vetor.y"
    {(yyval.ast) = newvar('t', (yyvsp[(3) - (3)].texto), NULL, (yyvsp[(1) - (3)].ast));;}
    break;

  case 41:
#line 1019 "vetor.y"
    { (yyval.ast) = newarray('C', (yyvsp[(3) - (6)].texto), (yyvsp[(5) - (6)].inteiro), (yyvsp[(1) - (6)].ast));;}
    break;

  case 42:
#line 1020 "vetor.y"
    {(yyval.ast) = newvar('t', (yyvsp[(3) - (5)].texto), newtexto((yyvsp[(5) - (5)].texto)), (yyvsp[(1) - (5)].ast));;}
    break;

  case 43:
#line 1021 "vetor.y"
    {(yyval.ast) = newvar((yyvsp[(1) - (2)].inteiro), (yyvsp[(2) - (2)].texto), NULL, NULL);;}
    break;

  case 44:
#line 1022 "vetor.y"
    {(yyval.ast) = newvar((yyvsp[(1) - (4)].inteiro), (yyvsp[(2) - (4)].texto), newtexto((yyvsp[(4) - (4)].texto)), NULL);;}
    break;

  case 45:
#line 1023 "vetor.y"
    { (yyval.ast) = newarray('C',(yyvsp[(2) - (5)].texto), (yyvsp[(4) - (5)].inteiro), NULL);;}
    break;

  case 46:
#line 1027 "vetor.y"
    {(yyval.ast) = newast('P', (yyvsp[(1) - (1)].ast), NULL);;}
    break;

  case 47:
#line 1028 "vetor.y"
    {(yyval.ast) = newast('P', (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));;}
    break;

  case 48:
#line 1029 "vetor.y"
    {(yyval.ast) = newast('P', newtexto((yyvsp[(1) - (1)].texto)), NULL);;}
    break;

  case 49:
#line 1030 "vetor.y"
    {(yyval.ast) = newast('P', newtexto((yyvsp[(1) - (3)].texto)), (yyvsp[(3) - (3)].ast));;}
    break;

  case 50:
#line 1034 "vetor.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 51:
#line 1035 "vetor.y"
    { (yyval.ast) = newast('L', (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast));;}
    break;

  case 52:
#line 1039 "vetor.y"
    {(yyval.ast) = newasgn((yyvsp[(1) - (3)].texto), (yyvsp[(3) - (3)].ast));;}
    break;

  case 53:
#line 1043 "vetor.y"
    { 
        {(yyval.ast) = newast('R',(yyvsp[(3) - (4)].ast),NULL);}
    ;}
    break;

  case 54:
#line 1046 "vetor.y"
    {
        (yyval.ast) = newast('+', (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 55:
#line 1049 "vetor.y"
    {
        (yyval.ast) = newast('-',(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 56:
#line 1052 "vetor.y"
    {
        (yyval.ast) = newast('*',(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 57:
#line 1055 "vetor.y"
    {
        (yyval.ast) = newast('/',(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 58:
#line 1058 "vetor.y"
    {
        (yyval.ast) = (yyvsp[(2) - (3)].ast);
    ;}
    break;

  case 59:
#line 1061 "vetor.y"
    {
        (yyval.ast) = newast('^',(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 60:
#line 1064 "vetor.y"
    { /* Testes condicionais */
        (yyval.ast) = newcmp((yyvsp[(2) - (3)].fn),(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 61:
#line 1067 "vetor.y"
    {
        (yyval.ast) = newast('M',(yyvsp[(2) - (2)].ast),NULL); 
    ;}
    break;

  case 62:
#line 1070 "vetor.y"
    { 
        (yyval.ast) = (yyvsp[(1) - (1)].ast); 
    ;}
    break;

  case 63:
#line 1076 "vetor.y"
    { (yyval.ast) = newint((yyvsp[(1) - (1)].inteiro));;}
    break;

  case 64:
#line 1077 "vetor.y"
    { (yyval.ast) = newreal((yyvsp[(1) - (1)].real));;}
    break;

  case 65:
#line 1078 "vetor.y"
    { (yyval.ast) = newValorVal((yyvsp[(1) - (1)].texto)); ;}
    break;

  case 66:
#line 1079 "vetor.y"
    {(yyval.ast) = newValorVal_a((yyvsp[(1) - (4)].texto), newint((yyvsp[(3) - (4)].inteiro)));;}
    break;

  case 67:
#line 1080 "vetor.y"
    {(yyval.ast) = newValorVal_a((yyvsp[(1) - (4)].texto), newValorVal((yyvsp[(3) - (4)].texto)));;}
    break;


/* Line 1267 of yacc.c.  */
#line 2802 "vetor.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1083 "vetor.y"


#include "lex.yy.c"

int main(){
    yyin=fopen("entrada3.txt", "r");
    
    yyparse();
    yylex();
    fclose(yyin);
    return 0;

}

int yywrap(){
    return 0;
}
