#include <stdlib.h>
#include <stdio.h>
#include "seach.h"

// matriz de adj
#include "matrizAd.h"


int DFSRec(Grafo *new){
    if(!new) return ERROGRAFO;
    //if(!node) return ERROVERTICE;
    
    /* if(new->Matriz[0][0] == tvertice){
        return node;
    }  */
    tvertice i;
    int matriz[new->numVertices];
    
    for(i = 0; i < new->numVertices; i++)
        matriz[i]= BRANCO;

    
    for(i = 0; i < new->numVertices;i++){
        if(matriz[i] == BRANCO) {
            int pos = visitaDFS_REC(new,matriz,i);
            printf("%d \n",pos);
        }
    }
    return SUCESS;
}

int visitaDFS_REC(Grafo *grafo,int matriz[], tvertice node){
    tpeso i = 0;
    int flag =1;
    matriz[node] = CINZA;
    tvertice atual = primeiroAdj(grafo,node);
    tvertice prox;
    tpeso peso;
    while(atual != -1){
        recuperaADJ(grafo,atual,&prox,&peso);
        if(matriz[prox] == BRANCO){
            visitaDFS_REC(grafo,matriz,prox);
        }            
        atual = proxAj(grafo,atual);
    }
    matriz[node] = PRETO;
    return SUCESS;
}

tvertice primeiroAdj(Grafo *grafo, tvertice node){
    tvertice i;
    for(i =0; i<grafo->numVertices;i++){
        if(verificaArestaMatriz(grafo,node,i) > -1){
            return i;
        }
    }

    return ERROVERTICE;
}

tvertice proxAj(Grafo *grafo, tvertice node){
    tvertice i;
    for(i =node; i<grafo->numVertices;i++){
        if(  verificaArestaMatriz(grafo,node ,i) > -1){
            return i;
        }
    }
    return ERROVERTICE;
}

int recuperaADJ(Grafo *grafo, tvertice atual, tvertice *prox, tpeso *peso){
    *prox = proxAj(grafo,atual);
    *peso = verificaArestaMatriz(grafo,atual,*prox);
    return SUCESS;
}