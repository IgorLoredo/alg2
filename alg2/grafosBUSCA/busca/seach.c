#include <stdlib.h>
#include <stdio.h>
#include "seach.h"

// matriz de adj
#include "matrizAd.h"


int DFSIterativa(Grafo *new){
    if(!new) return ERROGRAFO;
    //if(!node) return ERROVERTICE;
    
    /* if(new->Matriz[0][0] == tvertice){
        return node;
    }  */
    int i;
    int matriz[new->numVertices];
    
    for(i = 0; i < new->numVertices; i++)
        matriz[i]= BRANCO;

    
    for(i = 0; i < new->numVertices;i++){
        if(matriz[i] == BRANCO) {
            visitaDFS(new,matriz,i);
        }
    }
    return SUCESS;
}

tpeso visitaDFS_REC(Grafo *grafo,int matriz[], tvertice node){
    tpeso i = 0;
    int flag =1;
    matriz[node] = CINZA;
    tvertice atual = primeiroAdj(grafo,node);

    while(atual != -1){
        

    }
    matriz[node] = PRETO;
    return SUCESS;
}

tvertice primeiroAdj(Grafo *grafo, tvertice node){
    int i;
    for(i =0; i<grafo->numVertices;i++){
        if(verificaArestaMatriz(grafo,node,i) > -1){
            return i;
        }
    }

    return ERROVERTICE;
}

tvertice proxAj(Grafo *grafo, tvertice node){
    int i;
    for(i =node; i<grafo->numVertices;i++){
        if(  verificaArestaMatriz(grafo,node ,i) > -1){
            return i;
        }
    }

    return ERROVERTICE;

}