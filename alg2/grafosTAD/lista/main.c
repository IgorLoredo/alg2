#include <stdlib.h>
#include <stdio.h>
#include <listaAd.h>


int main (){
    Grafo *lista = criarGrafoLista(5);
    printf("%d\n",inserirArestaLista(lista,1,2,10011));
     printf("%d\n",inserirArestaLista(lista,1,3,100));
     printf("%d\n",inserirArestaLista(lista,1,4,5));
    printf("%d\n",inserirArestaLista(lista,1,5,103330));
    printf(" aresta %d\n",verificarArestaLista(lista,1,2));

    return 0;
}

