// igor guilherme pereira loredo
//11275071

#ifndef index_h
#define index_h

#include <stdlib.h>

#define TAM 16

struct aluno{
	int numUSP;
	char nome[TAM]; // 16
	char sobrenome[TAM]; // 16
	char curso[TAM]; // 16
	float nota;
};

struct index_primario{
    int nusp;
    int RRN;
};

struct  LIST_INDEX {
    int prox;
    int nusp;
};

struct index_secundario{ // analisa a struct 
    char sobrenome[TAM]; // 16
    int pos;
}; 

typedef struct aluno Aluno;
typedef struct index_primario INDEX_Primario;
typedef struct index_secundario INDEX_Secundario;
typedef struct LIST_INDEX list_index;

//criar arquivos e carregar
FILE *criarArquivo(char *);

INDEX_Primario *CarregarIndexPri(FILE*,int*);

INDEX_Secundario *CarregarIndexSec(FILE*, int* );

list_index *CarregarLista(FILE*,int*);

Aluno CriarAluno();

Aluno *PesquisaPrim(FILE *,INDEX_Primario *,int ,int );


// seta o tamanho do arquivo 
int tamArquivo(FILE*);


int addPrim(FILE*,INDEX_Primario *,int, int,int);

int addSec(INDEX_Secundario *,list_index*,int,int,int,char[]);

Aluno* addArquivo(FILE *,INDEX_Primario *,int , int);

int addAlunoArquivo(FILE*, Aluno *, int);

//int inserirAluno(FILE*, INDEX_Primario**,INDEX_Secundario**, int);


// descarregar a memoria ram nos arquivos
int descarregarIndexPrim(FILE *, INDEX_Primario*, int);

int descarregarIndexSec(FILE *, INDEX_Secundario *, int);

int descarregarLista(FILE *, list_index *, int);


// menus
void menu();

void imprimeAluno(Aluno*);

// buscas
int BuscaBinaria_Prim(INDEX_Primario *,int,int, int);

int BuscaBinaria_Sec(INDEX_Secundario *, int , int , char[]);

int *buscaList(list_index *,int, int*);

int buscaSobrenome(FILE *,INDEX_Primario*, INDEX_Secundario *,list_index *, int, int ,int , char []);

// remover
int removerNusp(INDEX_Primario**,list_index**,int, int, int);

int removerSobrenome(FILE *,INDEX_Primario ** ,INDEX_Secundario **,list_index **,int, int ,int,char[]);


#endif