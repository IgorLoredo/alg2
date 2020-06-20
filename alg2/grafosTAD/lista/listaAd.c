//igor guilherme pereira loredo nusp 11275071
#include <stdlib.h>
#include <stdio.h>
#include <listaAd.h>



Grafo *criarGrafoLista(int num){
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

Vertice *criarVerticeLista(tvertice vert,tpeso peso){
     Vertice *novo = (Vertice*)calloc(1,sizeof(Vertice));
     novo->Peso=peso;
     novo->distino = vert;
    return novo;
 }

int inserirArestaLista(Grafo*lista, tvertice a,tvertice b,tpeso peso){
    if(!lista) return ERROGRAFO;
    if(!a || !b) return ERROVERTICE;

    Vertice *aux = &lista->Lista[a-1] ;
    for(; aux->prox !=NULL; aux = aux->prox ){
        // caso ja exita o nó insido
        if (aux->distino == b ) 
            return SUCESS;
    }
    printf("inseir %d\n",aux->distino);
    Vertice *novo = criarVerticeLista(b,peso);
    aux->prox = novo;
    return SUCESS;
}

int verificarArestaLista(Grafo *lista,tvertice a ,tvertice b){
    if(!lista) return ERROGRAFO;
    if(!a || !b) return ERROVERTICE;

    Vertice *aux = &lista->Lista[a-1] ;
    for(; aux->prox !=NULL; aux = aux->prox ){
        // caso encontre dentro da lista
        if (aux->distino == b ) 
            return aux->Peso;
    }
    // caso encontre no final da lista
    return aux->distino == b?  aux->Peso:ERRO;
}


int liberarGrafoLista(Grafo*lista){
    if(!lista) return ERROGRAFO;
    int i;
    Vertice *aux1 = NULL;
    Vertice *aux2 = NULL;
    for(i =0;i < lista->numVertice;i++){
        aux1 = &lista->Lista[i];
       for(; aux1->prox !=NULL; aux1 = aux1->prox ){
            aux2 = aux1->prox; 
            free(aux1); 
            aux1 = aux2;
       }
    } 
    free(lista);
    return SUCESS;
}

