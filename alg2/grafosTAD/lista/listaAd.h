#ifndef listaAd
#define listaAd

// defines erros
#define SUCESS 1
#define ERRO -1
#define ERROGRAFO -2
#define ERROVERTICE -3

#define MAX 100

typedef int tpeso;
typedef int tvertice;

struct vertice{
    struct vertice *prox;
    tvertice distino;   
    tpeso Peso;

};


struct grafo{
    struct vertice *Lista;    
    int numVertice;
};


typedef struct grafo Grafo;
typedef struct vertice Vertice;

// liberar 
// criar grafo

Grafo *criarGrafo(int);
int inserirAresta(Grafo *,tvertice,tvertice,tpeso);
Vertice *criarVertice(tvertice,tpeso);


#endif
