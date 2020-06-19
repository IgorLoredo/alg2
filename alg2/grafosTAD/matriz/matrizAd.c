#include <stdio.h>
#include <stdlib.h>
#include "matrizAd.h"





Grafo *iniciarGrafo(int num){
    int i,j;
    Grafo *new = (Grafo*)calloc(1,sizeof(Grafo));
    new->numVertices = num;
    new->Matriz = (tpeso**)calloc(num,sizeof(tpeso*));

    for(i = 0; i < num; i++)
        new->Matriz[i] = (tpeso*)calloc(num,sizeof(tpeso));
    
    for(i =0 ; i < num;i++){
        for (j =0 ; j < num; j++){
            new->Matriz[i][j] = 0;
        }
    }
    return new;
}

int inserirAresta(Grafo *new,tvertice a, tvertice b, tpeso peso ){
    if(!new) return ERROGRAFO;
    if(a < 0 || b < 0 ) return ERRO;
    new->Matriz[a-1][b-1] = peso;
    return SUCESS;
}


int verificaAresta(Grafo* matriz,tvertice a,tvertice b){
    if(!matriz) return ERROGRAFO;
    return matriz->Matriz[a-1][b-1] != 0 ? matriz->Matriz[a-1][b-1] : ERRO;
}


int liberarGrafo(Grafo* matriz){
    int i;
    for(i =0; i < matriz->numVertices;i++)
        free(matriz->Matriz[i]);
    free(matriz->Matriz);
    free(matriz);
    return SUCESS;
}