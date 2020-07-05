//igor guilherme pereira loredo nusp 11275071

#ifndef queue
#define queue

#include "matrizAd.h"

#define MAXFILA 1000

struct fila{
    int cont;
    int comeco;
    int fim;
    int elementos[MAXFILA];
};

typedef struct fila Fila;

Fila *criarFila();

void inserirFila(Fila*,tvertice);

void removerFila(Fila*);

tvertice pegaTop(Fila*);

void esvaziar(Fila*);

int Vazia(Fila *);

#endif