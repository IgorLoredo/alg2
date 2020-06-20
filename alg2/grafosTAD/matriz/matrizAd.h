#ifndef matrizAd
#define matrizAd

// defines erros
#define SUCESS 1
#define ERRO -1
#define ERROGRAFO -2
#define ERROVERTICE -3

#define MAX 100

typedef int tpeso;
typedef int tvertice;


struct grafo{
    tpeso **Matriz;
    int numVertices;
};

typedef struct grafo Grafo;

Grafo *iniciarGrafoMatriz(int);

int inserirArestaMatriz(Grafo*,tvertice ,tvertice,tpeso);

int verificaArestaMatriz(Grafo*,tvertice,tvertice);

int liberarGrafoMatriz(Grafo*);

#endif
