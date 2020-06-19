#include <stdlib.h>
#include <stdio.h>
#include <matrizAd.h>


int main (){
    Grafo *matriz = iniciarGrafo(5);
    inserirAresta(matriz,1,2,2100);
    printf("%d\n",verificaAresta(matriz,1,1));
    liberarGrafo(matriz);
    return 0;
}

