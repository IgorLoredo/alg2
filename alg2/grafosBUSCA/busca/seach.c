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

tpeso visitaDFS(Grafo *grafo,int matriz[], tvertice node){
    tpeso soma =0;
    tpeso i = 0;
    int flag =1;
    while(flag){
        if(i != grafo->numVertices){
            soma += verificaArestaMatriz(grafo,node -1,i);
            i +=1;
        }else{
            flag =0;
        }
    }
    return soma;
}