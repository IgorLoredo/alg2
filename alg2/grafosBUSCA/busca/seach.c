#include <stdlib.h>
#include <stdio.h>
#include "seach.h"

#include "queue.h"

// matriz de adj
#include "matrizAd.h"


int DFSRec(Grafo *new){
    if(!new) return ERROGRAFO;
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
        recuperaADJ(grafo,atual,node,&prox,&peso);
        // printf("node %d saindo \n",atual);
        if(matriz[prox] == BRANCO){
           
            visitaDFS_REC(grafo,matriz,prox);
        }            
        atual = proxAj(grafo,atual,prox);
    }
    printf("            prox %d preto\n",node+1);
    matriz[node] = PRETO;
    return SUCESS;
}

tvertice primeiroAdj(Grafo *grafo, tvertice node){
    tvertice i;
    for(i =0; i<grafo->numVertices;i++){
        if(grafo->Matriz[node][i] != 0){
            return i;
        }
    }
    return ERROVERTICE;
}

tvertice proxAj(Grafo *grafo, tvertice node,tvertice prox){
    tvertice i;
    for(i =prox+1; i<grafo->numVertices;i++){
        if( grafo->Matriz[node][i] != 0){
            return i;
        }
    }
    return ERROVERTICE;
}

int recuperaADJ(Grafo *grafo, tvertice atual, tvertice v,tvertice *prox, tpeso *peso){
    *prox = atual;
    *peso = verificaArestaMatriz(grafo,atual,v);
    return SUCESS;
}

int buscaBFS(Grafo *grafo){
    tvertice i;
    int matriz[grafo->numVertices];
    
    for(i = 0; i < grafo->numVertices; i++)
        matriz[i]= BRANCO;
     

    for(i = 0; i < grafo->numVertices;i++){
         if(matriz[i] == BRANCO){
             visitaBFS(grafo,matriz,i);
         }
     }
    return SUCESS;
}


int visitaBFS(Grafo *grafo, int cor[], tvertice v){
    tvertice w;
    tvertice apontar;
    tpeso peso;
    
    Fila *Queue = criarFila();
    cor[v] = CINZA;    
    inserirFila(Queue,v);// igual


    printf("\n cinza : %d ",  v+1);

    while(Vazia(Queue) == 1){
        v = pegaTop(Queue);
        removerFila(Queue);//igual
            apontar = primeiroAdj(grafo,v);
            printf("  prox: %d",apontar);
        while(apontar> -3){
            recuperaADJ(grafo,apontar,v,&w,&peso);
            printf(" %d", w+1);
            if(cor[w] == BRANCO){
                cor[w] = CINZA;
                inserirFila(Queue,w);
            }
            apontar = proxAj(grafo,v,apontar);
        }
        cor[v] = PRETO;
        printf("  preto  %d\n",v+1);
    }

    return SUCESS;
}