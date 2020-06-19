#include <stdlib.h>
#include <stdio.h>
#include <listaAd.h>



Grafo *criarGrafo(int num){
    int i;
    Grafo *new = (Grafo*)calloc(1,sizeof(Grafo));
    new->numVertice = num;
    new->Matriz = (Vertice*)calloc(num,sizeof(Vertice));
    for(i =0; i < num; i++){
        new->Matriz->Peso = 0;
        new->Matriz->distino = 0;
        new->Matriz->prox = NULL;
    }
    return new;
}

