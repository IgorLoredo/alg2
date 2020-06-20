#include <stdlib.h>
#include <stdio.h>
#include <listaAd.h>


int main (){
    Grafo *lista = criarGrafo(5);
    printf("%d\n",inserirAresta(lista,1,2,10011));
     printf("%d\n",inserirAresta(lista,1,3,100));
     printf("%d\n",inserirAresta(lista,1,4,5));
     printf("%d\n",inserirAresta(lista,1,5,103330));
    printf(" aresta %d\n",verificarAresta(lista,1,2));

    return 0;
}

