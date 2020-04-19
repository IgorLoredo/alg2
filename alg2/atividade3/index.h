// igor guilherme pereira loredo
//11275071

#ifndef index_h
#define index_h

#include <stdlib.h>

#define TAM 16

struct aluno{
	int numUSP;
	char nome[TAM];
	char sobrenome[TAM];
	char curso[TAM];
	float nota;
};

struct index_primario{
    int nusp;
    int RRN;
};

struct LIST_INDEX{
    int RRN;
    struct LIST_INDEX *prox;
};

typedef struct LIST_INDEX list_index;

struct index_secundario{ // analisa a struct 
    int quant;
    char sobrenome[TAM];
    list_index *pri; // ligação para a primeira lista
};

typedef struct aluno Aluno;
typedef struct index_primario INDEX_Primario;
typedef struct index_secundario INDEX_Secundario;


FILE * criarArquivo(char *);

INDEX_Primario *CarregarIndexPri(FILE*,int);

INDEX_Secundario *CarregarIndexSec(FILE*);

int addPrimario(INDEX_Primario *,int,int, int);

Aluno *CriarAluno();

int addAlunoArquivo(FILE *, Aluno *, int);

int inserirAluno(FILE *, INDEX_Primario*,INDEX_Secundario *, int);


#endif
