#ifndef listaAd.h
#define listaAd.h

// defines erros
#define SUCESS 1
#define ERRO -1
#define ERROGRAFO -2

#define MAX 100

typedef int tpeso;
typedef int tvertice;

struct vertice{
    struct vertice *prox;
    tpeso Peso;

};


struct grafo{
    struct vertice *Matriz;    
    int numVertice;
};


typedef struct grafo Grafo;
typedef struct vertice Vertice;

// liberar 
// criar grafo

Grafo *criarGrafo(int);

#endif
