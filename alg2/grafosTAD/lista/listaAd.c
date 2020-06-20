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

Vertice *criarVertice(tvertice vert,tpeso peso){
     Vertice *novo = (Vertice*)calloc(1,sizeof(Vertice));
     novo->Peso=peso;
     novo->distino = vert;
    return novo;
 }

int inserirAresta(Grafo*lista, tvertice a,tvertice b,tpeso peso){
    if(!lista) return ERROGRAFO;
    if(!a || !b) return ERROVERTICE;

    Vertice *aux = &lista->Lista[a-1] ;
    for(; aux->prox !=NULL; aux = aux->prox ){
        // caso ja exita o nó insido
        if (aux->distino == b ) 
            return SUCESS;
    }
    printf("%d ddddddd",aux->distino);
    Vertice *novo = criarVertice(b,peso);
    aux->prox = novo;
    return SUCESS;
}