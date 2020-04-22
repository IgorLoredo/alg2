//igor guilherme pereira loredo
//11275071

#include <stdio.h>
#include <stdlib.h>
#include "index.h"

 
int main(void) {
    int comando, flag = 1;
    int tamPri, tamSec, tamList,num;
    char sobrenome[TAM];

    // cria pega os arquivos 
    FILE *arq = criarArquivo("aluno.dat") ;
    FILE *index_prim = criarArquivo("index_prim.dat");
    FILE *index_sec = criarArquivo("index_sec.dat");
    FILE *list = criarArquivo("list.dat");

    // carrega os arquivos em memoria ram
    INDEX_Primario *vetPri = CarregarIndexPri(index_prim,&tamPri);
    
    INDEX_Secundario *vetSec = CarregarIndexSec(index_sec, &tamSec);
    
    list_index *listVet = CarregarLista(list,&tamList);

    
    //pega o tamanho do arquivo
    int tamArq = tamArquivo(arq);
    list_index a;
    rewind(list);
    
   /* for(int i =0 ; i< tamPri;i++){
            //
            fread(&a,sizeof(list_index),1,arq);
            printf("nsusp %d %d\n",a.nusp,a.prox);
    } */
     Aluno *aux;
    do{
        menu();
        scanf("%d", &comando);
        switch(comando){
            case 1:
            aux = addArquivo(arq,vetPri,tamPri,tamArq);
                if(aux){
                    addSec(vetSec,listVet,tamSec,tamList,aux->numUSP,aux->sobrenome);
                    tamList +=1;
                    tamSec +=1;
                    tamPri +=1;
                    tamArq +=1; 
                    printf("list %d prim %d sec %d  arq %d\n",tamList,tamPri,tamSec,tamArq);
                }/* */
            aux = NULL;
            break;

            case 2:
                printf("\nInsira o nUSP\n");
                scanf("%d",&num);
               aux = PesquisaPrim(arq,vetPri,tamPri,num);
                if (aux){
                    imprimeAluno(aux);
                }
                aux = NULL;
            break;
            case 3:
                printf("Insira o Sobrenome:\n");
                scanf(" %[^\n]s",sobrenome);
                buscaSobrenome(arq,vetSec,listVet,tamList,tamSec,sobrenome);
            break;
            case 4: // remover pelo nusp
                printf("\nInsira o nUSP\n");
                scanf("%d",&num);
            break;
            case 5: // remover pelo sobrenome
                printf("Insira o Sobrenome:\n");
                scanf(" %[^\n]s",sobrenome);
            
            break;
            case 6: // sair
                flag = 0;
                printf("\n          Saindo e Salvando dados\n\n");
            break;

            default:
                printf("Erro, comando nao valido");
            break;
        }

    }while(flag); 

    for(int i =0 ; i< tamPri;i++){
       
        printf("nsusp %d %d\n",listVet[i].nusp, listVet[i].prox);
    }


    // carrega arquivos
    descarregarIndexPrim(index_prim,vetPri,tamPri);
    descarregarIndexSec(index_sec,vetSec,tamSec);
    descarregarLista(list,listVet,tamList);

    // fecha arquivos
    fclose(arq);
    fclose(index_prim);
    fclose(index_sec);
    fclose(list);

    return 0;
}