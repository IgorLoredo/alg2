#include <stdlib.h>
#include <stdio.h>
#include "seach.h"




int main(){
    Grafo *matriz = iniciarGrafoMatriz(7);
    inserirArestaMatriz(matriz,1,2,10);
    inserirArestaMatriz(matriz,1,7,10);

    inserirArestaMatriz(matriz,2,3,10);
    inserirArestaMatriz(matriz,2,4,10);
   
    inserirArestaMatriz(matriz,4,6,10);
    
    DFSRec(matriz);
    liberarGrafoMatriz(matriz);
    return 0;
}