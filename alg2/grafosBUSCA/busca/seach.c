#include <stdlib.h>
#include <stdio.h>
#include "seach.h"

// matriz de adj
#include "matrizAd.h"


tvertice DFSIterativa(Grafo *new, tvertice node, tpeso soma){
    if(!new) return ERROGRAFO;
    if(!node) return ERROVERTICE;
    
    if(new->Matriz[0][0] == tvertice ){
        return node;
    }
    int i;
    tvertice aux;
    tvertice matriz[new->numVertices][new->numVertices];
    for(i = 0; i < new->numVertices; i++)
        matriz[i][i]= BRANCO;

    for(){

    }
    return aux;
}

