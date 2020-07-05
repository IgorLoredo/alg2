//igor guilherme pereira loredo nusp 11275071

#include <stdlib.h>
#include <stdio.h>
#include "seach.h"
#include "queue.h"



int main(){
    Grafo *matriz = iniciarGrafoMatriz(6);
    inserirArestaMatriz(matriz,1,2,10);
    inserirArestaMatriz(matriz,1,6,10);

    inserirArestaMatriz(matriz,2,3,10);
    inserirArestaMatriz(matriz,2,4,10);
   inserirArestaMatriz(matriz,5,5,10);
    inserirArestaMatriz(matriz,4,5,10);
    
    // DFSRec(matriz);
     buscaBFS(matriz);

    //  for(int i =0; i< matriz->numVertices;i++){
    //     for(int j = 0; j < matriz->numVertices;j++){
    //         printf("%d ",matriz->Matriz[i][j]);
    //     }
    //     printf("\n");
    //  }
    return 0;
}