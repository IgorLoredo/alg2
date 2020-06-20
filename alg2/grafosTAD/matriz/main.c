#include <stdlib.h>
#include <stdio.h>
#include <matrizAd.h>


int main (){
    Grafo *matriz = iniciarGrafoMatriz(5);
    inserirArestaMatriz(matriz,1,2,2100);
    printf("%d\n",verificaArestaMatriz(matriz,1,1));
    liberarGrafoMatriz(matriz);
    return 0;
}

