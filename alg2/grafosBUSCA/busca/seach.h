#ifndef  seach
#define seach

#include "matrizAd.h"

#define SUCESS 1
#define ERRO -1
#define ERROGRAFO -2
#define ERROVERTICE -3

   

#define BRANCO 0
#define CINZA 1
#define PRETO 2

int DFSIterativa(Grafo *);

tvertice proxAj(Grafo *, tvertice ,tvertice);

int recuperaADJ(Grafo *, tvertice ,tvertice, tvertice *, tpeso *);

tvertice primeiroAdj(Grafo *, tvertice );

int visitaDFS_REC(Grafo *,int[], tvertice );


int buscaBFS(Grafo*);

int visitaBFS(Grafo *, int [], tvertice );

#endif