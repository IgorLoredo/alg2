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

    // visitaDFS_REC(new,matriz,1);
    for(i = 0; i < new->numVertices;i++){

        if(matriz[i] == BRANCO) {
            visitaDFS_REC(new,matriz,i);
            //  printf("%d \n",pos);
        }
    }
    return SUCESS;
}

int visitaDFS_REC(Grafo *grafo,int matriz[], tvertice node){
    matriz[node] = CINZA;
    //printf("node %d cinza\n",node);

    tvertice atual = primeiroAdj(grafo,node);
    tvertice prox = 0;
    tpeso peso;
    printf("entrando %d \n" , node+1);

    while(atual != -1){
        recuperaADJ(grafo,atual,&prox,&peso);
        // printf("node %d saindo \n",atual);
        if(matriz[prox] == BRANCO){
           
            visitaDFS_REC(grafo,matriz,prox);
        }            
        atual = proxAj(grafo,atual);
    }
    printf("            prox %d preto\n",node+1);
    matriz[node] = PRETO;
    return SUCESS;
}

tvertice primeiroAdj(Grafo *grafo, tvertice node){
    tvertice i;
    for(i =0; i<grafo->numVertices;i++){
        if(verificaArestaMatriz(grafo,node+1,i+1) > -1){
            return i;
        }
    }
    return ERROVERTICE;
}

tvertice proxAj(Grafo *grafo, tvertice node){
    tvertice i;
    for(i =node; i<grafo->numVertices;i++){
        if(  verificaArestaMatriz(grafo,node,i) > -1){
            return i;
        }
    }
    return ERROVERTICE;
}

int recuperaADJ(Grafo *grafo, tvertice atual, tvertice *prox, tpeso *peso){
    *prox = atual;
    *peso = verificaArestaMatriz(grafo,atual,*prox);
    return SUCESS;
}





void BFS(Grafo *grafo, tvertice verticebusca){
    tvertice v;
    int cor[MAX];
    for(v = 0; grafo->numVertices;v++){
        cor[v] = BRANCO;
    }
}