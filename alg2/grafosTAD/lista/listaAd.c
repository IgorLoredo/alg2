#include <stdlib.h>
#include <stdio.h>
#include <listaAd.h>



Grafo *criarGrafo(int num){
    int i;
    Grafo *new = (Grafo*)calloc(1,sizeof(Grafo));
    new->numVertice = num;
    new->Lista = (Vertice*)calloc(num,sizeof(Vertice));
    for(i =0; i < num; i++){
        new->Lista->Peso = 0;
        new->Lista->distino = 0;
        new->Lista->prox = NULL;
    }
    return new;
}

int inserirAresta(Grafo*lista, tvertice a,tvertice b,tpeso peso){

    return SUCESS;
}