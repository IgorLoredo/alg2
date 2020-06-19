#ifndef matrizAd
#define matrizAd


#define ERRO -1

#define MAX 100

typedef int tpeso;
typedef int tvertice;


 struct vertice{
    tvertice Vertice;
    tpeso Peso;

 };


struct grafo{
   
    tpeso Peso;

};

typedef struct vertice Vertice;
typedef struct grafo Grafo;

Grafo *iniciarGrafo();




#endif
