//igor guilherme pereira loredo
// 11275071

#include <stdio.h>
#include <stdlib.h>
#include "index.h"

FILE * criarArquivo(char *arquivo){
    FILE *arq;
    arq = fopen(arquivo, "r+");
    if(!arq) {
        arq = fopen(arquivo,"w+");
        printf("Arquivo criado %s\n", arquivo);
    }
    if(!arq) {
        printf("Erro ao criar/abrir %s\n",arquivo);
        return NULL;
    }
    return arq;
}


INDEX_Primario *CarregarIndexPri(FILE* arq,int tam){
    // aadd todos os elementos no vetor(memoria ram)
    if(!arq) return NULL;
    int i, aux =0;
    fseek(arq,0, SEEK_END);
    aux= ftell(arq);
    tam = aux / 8;
    INDEX_Primario *vet =(INDEX_Primario*)malloc(tam*sizeof(INDEX_Primario));
     rewind(arq);
     for (i=0; i<tam; i++)
        fread(&vet[i], sizeof(INDEX_Primario), 1, arq);
    return vet;
}

INDEX_Secundario *CarregarIndexSec(FILE* arq){
    if(!arq) return NULL;
    INDEX_Secundario *novo =  (INDEX_Secundario*)calloc(1,sizeof(INDEX_Secundario));


    

}
int LerIndexPri(FILE* index, INDEX_Primario*novo){ // ler conteudo do arquivo index e coloca em um vetor index
    if(!index) return -1;
    int quant=0 ,i;
    rewind(index);
    fseek(index, 0, SEEK_END);
    quant = ((int) ftell(index))/sizeof(INDEX_Primario); 
    rewind(index);
    if(quant > 0){
        for(i =0; i < quant;i++){
	    fread(&index[i], sizeof(INDEX_Primario*), 1, index); // Faz leitura dos indices
        }
    }
    if(quant)
        return quant;
    else 
        return 0;
}  // tudo ok


int addPrimario(INDEX_Primario *vet, int tam,int nusp, int rrn){
    // add novos 
    if(!vet) return 0;
    vet = realloc(vet,sizeof(INDEX_Primario)*(tam+1));
    vet[tam-1].nusp = nusp;
    vet[tam-1].RRN = rrn;
    tam++; 
    return 1;
}


Aluno *CriarAluno(){ // pera o resgistro do aluno
    Aluno *novo = (Aluno*)calloc(1,sizeof(Aluno));
    printf("Nome:");
    scanf("%[^\n]s",novo->nome);
    printf("Sobrenome:");
    scanf("%[^\n]s",novo->sobrenome);
    printf("Curso:");
    scanf("%[^\n]s",novo->curso);
    printf("nUSP:");
    scanf("%d",&novo->numUSP);
    printf("Nota:");
    scanf("%f",&novo->nota);
    return novo;
}

int addAlunoArquivo(FILE *arq, Aluno *aluno, int endereco){
    if(!arq) return 0;
    if(!aluno) return -1;

    rewind(arq);
    fseek(arq, 0, SEEK_END); 
    endereco = ftell(arq);
	fwrite(&aluno, sizeof(Aluno), 1, arq);
    fseek(arq, 0, SEEK_CUR);
	rewind(arq);
    return 1;
}

int inserirAluno(FILE *arq, INDEX_Primario* vetPRi,INDEX_Secundario *vetSecun, int tam){
    if(!arq) return 0;
    if (!vetPRi) return -1;
    if(!vetSecun) return -2;

    Aluno *novo = CriarAluno();
    return 1;
}

