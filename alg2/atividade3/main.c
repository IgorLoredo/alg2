//igor guilherme pereira loredo
//11275071

#include <stdio.h>
#include <stdlib.h>
#include "index.h"


int main(void) {
    int comando, flag = 1;
    // cria pega os arquivos 
    FILE *arq = criarArquivo("aluno.dat") ;
    FILE *index_primario = criarArquivo("index_prim.dat");
    FILE *index_sec = criarArquivo("index_sec.dat");
    FILE *index_sec = criarArquivo("list.dat");


   do{
        printf("1 - Adicionar\n");
        printf("2 - Buscar pelo nUSP\n");
        printf("3 - Buscar pelo sobrenome\n");
        printf("4 - Remover pelo nUSP\n");
        printf("5 - Remover pelo Sobrenome\n");
        printf("6 - Adicionar\n");
         scanf("%d", &comando);
        switch(comando){
            case 1:
            
            break;
            case 2:

            break;
            case 3:

            break;
            case 5:
            flag = 0;
            break;

        }


    } while(flag);