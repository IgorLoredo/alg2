//igor guilherme pereira loredo
// nusp 11275071

#ifndef arq_h
#define arq_h

#include <stdio.h> // adiciona a biblioteca par funcionar os pondeiros

#define TAM 16

struct Index{ // 12 bytes
    int id;// numero usp
    long byte; // codigo no arquivo 
};

struct tipoAluno {  // 56 bytes
	int numUSP; // 4 bytes
	char nome[TAM]; // 16 bytes
	char sobrenome[TAM]; // 16 bytes
	char curso[TAM]; // 16 bytes
	float nota; // 4 bytes
};

typedef struct tipoAluno ALUNO;
typedef struct Index INDEX;

void criaArquivo(FILE *);

void criaIndex(FILE *);

int LerIndex(FILE*, INDEX**);

void insereAluno(FILE *,ALUNO*, int, long);

void insereIndex(INDEX**,long,int, int*);

void ordenaIndex(INDEX**, int);

int pesquisaIndex(FILE*,INDEX **,ALUNO*,int, int);

void insereRegistro(FILE*,INDEX**,int, int, long);

void GeraIndex(FILE*,INDEX**,int*);

void imprimeRegistro( ALUNO);

void removeRegistro(FILE *, int );
void removeIndex(INDEX**,int);

void remover(FILE *,INDEX **, int, int);

int PesquisaBinaria (INDEX **, int, int );

#endif