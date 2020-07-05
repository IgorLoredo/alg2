//igor guilherme pereira loredo nusp 11275071

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Fila *criarFila(){
    Fila *new = (Fila*)calloc(1,sizeof(Fila));
    new->comeco =0;
    new->fim = -1;
    return new;
}

void inserirFila(Fila *fila,tvertice novo){
    if(fila->fim == MAXFILA - 1){
        return ; // caso a pilha estaja lotada
    }
    fila->fim+=1;
    fila->elementos[fila->fim] = novo;
}

void removerFila(Fila *fila){
    fila->comeco +=1;
}

tvertice pegaTop(Fila *fila){
    tvertice new  = fila->elementos[fila->comeco];
    return new;
}

void esvaziar(Fila *fila){
    free(fila);
}