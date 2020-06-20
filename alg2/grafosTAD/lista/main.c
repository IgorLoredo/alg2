#include <stdlib.h>
#include <stdio.h>
#include <listaAd.h>


int main (){
    Grafo *lista = criarGrafo(5);
    printf("%d\n",inserirAresta(lista,1,2,100));
    printf("%d\n",inserirAresta(lista,1,3,100));
    printf("%d\n",inserirAresta(lista,3,1,100));
    
    return 0;
}

