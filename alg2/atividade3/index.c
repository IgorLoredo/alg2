//igor guilherme pereira loredo
// 11275071

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "index.h"

FILE *criarArquivo(char *arquivo){
    FILE *arq;
    arq = fopen(arquivo, "r+");
    if(!arq) {
        arq = fopen(arquivo,"w+");
    }
    if(!arq) {
        printf("Erro ao criar/abrir %s\n",arquivo);
        return NULL;
    }
    return arq;
}


INDEX_Primario *CarregarIndexPri(FILE* arq,int *tam){
    // aadd todos os elementos no vetor(memoria ram)
    if(!arq) return NULL;
    int i;
    fseek(arq,0, SEEK_END);
    int aux=((int) ftell(arq))/sizeof(INDEX_Primario);
    *tam = aux;

    INDEX_Primario *vet =(INDEX_Primario*)malloc(aux*sizeof(INDEX_Primario));
    fseek(arq,0,SEEK_SET);
    for (i=0; i<aux; i++){
        fread(&vet[i],sizeof(INDEX_Primario),1,arq);
    }
    return vet;
}

INDEX_Secundario *CarregarIndexSec(FILE* arq, int *tam){
    if(!arq) return NULL;
    int i;
    fseek(arq,0,SEEK_END);
    int aux=((int) ftell(arq))/sizeof(INDEX_Secundario);
    *tam = aux;
    INDEX_Secundario *novo =  (INDEX_Secundario*)malloc(aux*sizeof(INDEX_Secundario));
    fseek(arq,0,SEEK_SET);
    for (i=0; i<aux; i++){
        fread(&novo[i],sizeof(INDEX_Secundario),1,arq);
    }

    return novo;
}


list_index *CarregarLista(FILE* arq,int *tam) {
    if(!arq) return NULL;
    int i;
    fseek(arq,0,SEEK_END);
    int aux=((int) ftell(arq))/sizeof(list_index);
    *tam = aux;
    list_index *vet = (list_index*)malloc(aux*sizeof(list_index));
    fseek(arq,0,SEEK_SET);
    for (i=0; i<aux; i++){

        /*fread(&vet[i].nusp,sizeof(int),1,arq);
        fread(&vet[i].prox,sizeof(int),1,arq);;*/
         fread(&vet[i],sizeof(list_index),1,arq)
    }
    return vet;

}

int tamArquivo(FILE*arq){
    if(!arq) return 0;
   // fseek(arq,0,SEEK_SET);
    fseek(arq,0,SEEK_END);
    int aux=((int) ftell(arq))/sizeof(Aluno);
    return aux;
}

int buscaListaPos(list_index *list, int pos){
    if(!list) return -1;
    if(pos < 0) return -2;
    int i;
    int aux = pos;

    while(list[aux].prox != -1){
       i = list[aux].prox;
        aux = i;
    }
    //printf("     aux %d ",aux);
    return aux;
}

void ordenarSec(INDEX_Secundario *vet, int tam){ // ordena o vetor de indice secundario
    int i,j;
    INDEX_Secundario x;
    for(i=1;i<tam;i++){
        x = vet[i];
        j = i-1;
            while(strcmp(x.sobrenome ,vet[j].sobrenome) < 0 ){
                vet[j+1] = vet[j];
                j--;
            }
         vet[j+1] = x;
    }
}

int Busca_Sec(INDEX_Secundario *index, int tam, char sobrenome[]){
    int i;
    for(i =0;i<tam;i++){
        if(strstr(index[i].sobrenome,sobrenome)){
            return index[i].pos;
        }
    }
    return -1;
}
//strcasecmp();


int addSec(INDEX_Secundario *vet,list_index *list,int tamSec, int tamList,int nusp,char sobrenome[]){ 
    // add no indice secundario e na lista
    if(!vet) return 0;
    if(!list) return -1;
    int indexPos = Busca_Sec(vet, tamSec, sobrenome);
    if(indexPos < 0){ // nao existe o aluno com esse sobrenome
        vet = (INDEX_Secundario*)realloc(vet,sizeof(INDEX_Secundario*)*(tamSec+1));
        list = (list_index*)realloc(list,(tamList+1)*sizeof(list_index));
        vet[tamSec].pos = tamList;
        strcpy(vet[tamSec].sobrenome,sobrenome); // inseri no final do arquivo
        list[tamList].nusp = nusp;
        list[tamList].prox = -1;
        ordenarSec(vet,tamSec+1);


    }else{ // existe o aluno com esse sobrenome
        list = (list_index*)realloc(list,(tamList+1)*sizeof(list_index));
        list[tamList].nusp = nusp;
        list[tamList].prox = -1; // insere no final da lista invertida
        int Poslist = buscaListaPos(list,vet[indexPos].pos);
        list[Poslist].prox = tamList;
       // printf("        nsup %d   prox %d",list[Poslist].nusp,list[Poslist].prox);
    } /* */

    printf("\n      Aluno inserido\n");

    return 1;
}


Aluno CriarAluno(){ // pera o resgistro do aluno
    Aluno novo;
    printf("Nome:");
    scanf(" %[^\n]s",novo.nome);
    printf("Sobrenome:");
    scanf(" %[^\n]s",novo.sobrenome);
    printf("Curso:");
    scanf(" %[^\n]s",novo.curso);
    printf("nUSP:");
    scanf("%d",&novo.numUSP);
    printf("Nota:");
    scanf("%f",&novo.nota);
    return novo;
}

int BuscaBinaria_Prim(INDEX_Primario *index, int a, int b, int nUSP){
  int meio;
    while (a<=b) {
		meio = (int)(a+b)/2;
       // printf("      busca %d\n", meio);
 		if (index[meio].nusp == nUSP)
		    return meio;
		else if (nUSP > index[meio].nusp)
            a = meio+1;
		else
            b = meio-1;
	}

  return -1;
}

Aluno *PesquisaPrim(FILE *arq,INDEX_Primario *index,int tam,int nusp){
    if(!arq) return NULL;
    if(!index) return NULL;
    int op = BuscaBinaria_Prim(index,0,tam,nusp);
    //printf(    "%d \n",op);
    if(op > -1){ // quando h regitros
        int pos = index[op].RRN*sizeof(Aluno);
        rewind(arq);
        fseek(arq,pos,SEEK_SET);
        Aluno aux;
        fread(&aux,sizeof(Aluno),1,arq);
        Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
        novo->numUSP = aux.numUSP;
        novo->nota = aux.nota;
        strcpy(novo->sobrenome,aux.sobrenome);
        strcpy(novo->curso, aux.curso);
        strcpy(novo->nome,aux.nome);
        return novo;
    } else{
        printf("\n      Aluno nao existe\n");
    }
    return NULL;
}


int addPrim(FILE *arq,INDEX_Primario *vet, int tam,int nusp, int rrn){
    int i;
    vet = (INDEX_Primario*)realloc(vet,(tam+1)*sizeof(INDEX_Primario));
    vet[tam].nusp = nusp;
    fseek(arq,0,SEEK_END);
    vet[tam].RRN = rrn;
    i = tam+1;

    INDEX_Primario aux;

    while (--i && vet[i].nusp  < vet[i-1].nusp){ // organizar
        aux = vet[i];
        vet[i] = vet[i];
        vet[i-1] = aux;
    }

    return 0;
}

Aluno* addArquivo(FILE *arq,INDEX_Primario *vet,int tamPrim, int tamArq){
    // add no arquivo e no indice primario
    if(!arq) return NULL;
    if(!vet) return NULL;
    Aluno novo  = CriarAluno();
    int op = BuscaBinaria_Prim(vet,0,tamPrim-1,novo.numUSP);

   if(op < 0){
        fseek(arq, 0, SEEK_END);
        fwrite(&novo.numUSP,sizeof(int),1,arq);
        fwrite(&novo.nome,sizeof(char),TAM,arq);
        fwrite(&novo.sobrenome,sizeof(char),TAM,arq);
        fwrite(&novo.curso,sizeof(char),TAM,arq);
        fwrite(&novo.nota,sizeof(float),1,arq);
        /* fwrite(&novo,sizeof(Aluno),1,arq);  */

        addPrim(arq,vet,tamPrim,novo.numUSP,tamArq);
        Aluno *aux = &novo;
        return aux;
    } else{
        printf("\n      Aluno ja tem cadrastro\n\n");
        // caso o aluno ja tenha cadrastro
    }
     return NULL;
}

int descarregarIndexPrim(FILE *arq, INDEX_Primario**vet, int tam){
    if(!arq) return 0;
    if(!vet) return -1;
    int i;
    fseek(arq,0,SEEK_SET);
    for(i =0; i < tam;i++){
        if(vet[i].nusp > -1){
            fwrite(&vet[i].nusp,sizeof(int),1,arq); // qualquer coisa colocar o &(nsup  e rnn)
            fwrite(&vet[i].RRN,sizeof(int),1,arq);
        }
    }

    return 1;
}

int descarregarLista(FILE *arq, list_index **list, int tam){
    if(!arq) return 0;
    if(!list) return -1;
    int i;
    rewind(arq);// qualquer coisa colocar o &(nsup  e rnn)
    for(i =0; i < tam;i++){
        if(list[i].nusp >-1){            
                fwrite(&list[i].nusp,sizeof(int),1,arq); 
                fwrite(&list[i].prox,sizeof(int),1,arq);
        }
    }

    return 1;
}

int descarregarIndexSec(FILE *arq, INDEX_Secundario **index, int tam){
    if(!arq) return 0;
    if(!index) return -1;
    int i;
    fseek(arq,0,SEEK_SET);
     char c[] ="*"; //  tria os cadrastro que tem o sobrenome *
    for(i =0 ; i < tam;i++){   
        if( strcmp(index[i].sobrenome,c) != 0){
            fwrite(&index[i].sobrenome,sizeof(char),TAM,arq);
            fwrite(&index[i].pos,sizeof(int),1,arq);
        }        
    }

    return 1;
}


void menu(){
    printf("\n\n*******************************\n");
    printf("    1 - Adicionar\n");
    printf("    2 - Buscar pelo nUSP\n");
    printf("    3 - Buscar pelo sobrenome\n");
    printf("    4 - Remover pelo nUSP\n");
    printf("    5 - Remover pelo Sobrenome\n");
    printf("    6 - Sair\n");
    printf("*******************************\n\n");
}

void imprimeAluno(Aluno*novo){
    printf("\nnUSP:%d \nNome:%s \nSobrenome: %s \nCurso: %s \nNota: %f\n",novo->numUSP,novo->nome,novo->sobrenome,novo->curso,novo->nota);
}


int *buscaList(list_index *vet, int pos, int *tamResult){
    if(!vet) return NULL;

    if(pos < 0) return NULL;
    int i=0,j=1,flag = 1,aux;
    int *novo= (int*)malloc(sizeof(int));
    novo[0] = vet[pos].nusp;

    if( vet[pos].prox == -1){
        *tamResult = 1;
        return novo; // caso s exista esse elemento de primeira
    }
    i = vet[pos].prox;

    do{
        if(vet[i].prox == -1){            
            novo = (int*)realloc(novo,sizeof(int)*(j+1));
            novo[j] = vet[i].nusp;
            j+=1;
            flag = 0;
        }else{
            novo = (int*)realloc(novo,sizeof(int)*(j+1));
            novo[j] = vet[i].nusp;
            aux  = i;
            i = vet[aux].prox;
            j+=1;
        }
    }while(flag);
    
   *tamResult = j;
    return novo;
}
/*
    
*/

int buscaSobrenome(FILE *arq,INDEX_Primario *vetPri ,INDEX_Secundario *vetSec,list_index *list,int tamPri, int tamList,int tamSec, char Sobrenome[]){
    if(!arq) return 0;
    if(!vetSec) return -1;

    int tam =1, i,num;
    int pos = Busca_Sec(vetSec,tamSec,Sobrenome);
    
   if(pos>-1){
        int *vet = buscaList(list,pos,&tam);
        printf("\nNusp com esse sobrenome:\n");
        for(i =0;i < tam;i++){
            if(vet[i] > -1)
                printf("    %d\n",vet[i]);
        }
        printf("\nEscolha um para ver os dados\n");
        scanf("%d", &num);
        Aluno *aux;
        aux = PesquisaPrim(arq,vetPri,tamPri,num);
        imprimeAluno(aux);
        free(vet);
    }else{
        printf("Não existe alunos com esse sobrenome\n");
    } 
    
    return 1;
}


int removerNusp(INDEX_Primario *vetPri, list_index *list,int nusp, int tamPrim, int tamList){
    int i;
    int flag = 0;
    for(i =0; i < tamPrim;i++){ // procura o nusp e negativa ele
        if(vetPri[i].nusp == nusp){
            int aux = vetPri[i].nusp *(-1);
            vetPri[i].nusp = aux;
            vetPri[i].RRN = -1;
            flag =1;
            break;
        }
    }
   
    if(flag){
        for(i =0 ; i < tamList;i++){
            if(list[i].){

            }
        }
        return 1;
    }
    return -1;
}

int removerSobrome(FILE *arq,INDEX_Primario *vetPri ,INDEX_Secundario *vetSec,list_index *list,int tamPri, int tamList,int tamSec, char Sobrenome[]){
    if(!arq) return 0;
    if(!vetSec) return -1;
    if(!vetPri) return  -1;
    int tam,i,j, flag = 1;
    int pos =  Busca_Sec(vetSec,tamSec,Sobrenome);

    if(pos> -1){
        int *vet = buscaList(list,pos,&tam);
        printf("\nNusp com esse sobrenome e que vão ser removidos:\n");
        for(i =0;i < tam;i++){
            if(vet[i] > -1)
                printf("    %d\n",vet[i]);
        }
        for(i =0; i < tam;i++){
            if(removerNusp(&vetPri,&vet[i],tamList, tamPri) != 1){
                printf("    ERRO  ao remover o numUSP: %d\n",vet[i]);
                flag = 0;
            }
        }
        char c[] ="*";
        strcpy(vetSec[pos].sobrenome,c); // muda o sobrenome para n dar erro

        for(i = 0; i < tamList;i++){ // remove da lista
            for(j =0; j < tam;j++){
                if(vet[j] == list[i].nusp){
                    list[i].nusp = list[i].nusp*(-1);
                }
            }
        }
    }else{
        printf("    Nao existe esse Sobrenome\n");
    }
    
    if(flag){
        return 1;
    }

    return -1;
}