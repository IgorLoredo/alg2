#ifndef matrizAd
#define matrizAd

#define SUCESS 1
#define ERRO -1
#define ERROGRAFO -2

#define MAX 100

typedef int tpeso;
typedef int tvertice;


struct grafo{
    tpeso **Matriz;
    int numVertices;
};

typedef struct grafo Grafo;

Grafo *iniciarGrafo(int);

int inserirAresta(Grafo*,tvertice ,tvertice,tpeso);

int verificaAresta(Grafo*,tvertice,tvertice);

int liberarGrafo(Grafo*);

#endif
