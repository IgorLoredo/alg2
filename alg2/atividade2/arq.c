//igor guilherme pereira loredo
// nusp 11275071

#include <stdio.h>
#include <stdlib.h>
#include "arq.h"



void criaArquivo(FILE *df) {
    if (df== NULL) {
        df= fopen("alunos.dad", "w+");    // cria arquivo caso n tenha     

        fclose(df);
        df= NULL;
    }
} // tudo ok
void criaIndex(FILE *df) {
    if (df== NULL) {
        df= fopen("index.dad", "w+");      
        fclose(df);
        df= NULL;
    }
}

int LerIndex(FILE* index, INDEX*novo){ // ler conteudo do arquivo index e coloca em um vetor index
    if(!index) return -1;
    int quant=0 ,i;
    rewind(index);
    fseek(index, 0, SEEK_END);
    quant = ((int) ftell(index))/sizeof(INDEX); 
    rewind(index);
    if(quant > 0){
        for(i =0; i < quant;i++){
	    fread(&index[i], sizeof(INDEX*), 1, index); // Faz leitura dos indices
        }
    }
    if(quant)
        return quant;
    else 
        return 0;
}  // tudo ok

void ordenaIndex (INDEX *index, int tam){ // ordena os index
    int i,j;
    INDEX novo;

    for(i=0;i<tam;i++){
        for(j=0;j<tam-1;j++){
            if(index[j].id > index[j+1].id){
                novo = index[j];
                index[j] = index[j+1];
                index[j+1] = novo;
            }
        }
    }

} 




int PesquisaBinaria(INDEX*vet, int chave, int Tam){
     int inf = 0;     // limite inferior (o primeiro índice de vetor em C é zero          )
     int sup = Tam-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)
     int meio;
     
     while (inf <= sup){
          meio = (inf + sup)/2;
          if (chave == vet[meio].id)
               return meio;
          if (chave < vet[meio].id)
               sup = meio-1;
          else
               inf = meio+1;
     }
     return -1;   // não encontrado
}


int pesquisaIndex(FILE* df,INDEX*index,ALUNO reg, int nusp, int tam){
    int op = PesquisaBinaria(index,nusp,tam);
    if( op > -1){
        rewind(df);
        fseek(df, sizeof(ALUNO)*op, SEEK_SET);
        fread(&reg, sizeof(ALUNO), 1, df);
        return 1;
    }
    return 0; // caso indice no existir
}


void insereAluno(FILE *df, ALUNO novo, int nusp,long endereco){// segue o mesmo esquema do 
    novo.numUSP = nusp;
    printf("Coloque seu nome:\n");
    scanf("%s",novo.nome);
    printf("Sobrenome:\n");
     scanf("%s",novo.sobrenome);
    printf("Curso:\n");
     scanf("%s",novo.curso);
    printf("Nota:\n");
     scanf("%f",&novo.nota);
    // posiciona o ponteiro no ultimo byte e add um novo 5regiostro

    rewind(df);
    fseek(df, 0, SEEK_END); 
    endereco = ftell(df);
	fwrite(&novo, sizeof(ALUNO), 1, df);
    fseek(df, 0, SEEK_CUR);
    //tam = ((int)ftell(df))/sizeof(ALUNO); 
	rewind(df);

}
 
void insereIndex(INDEX* index,long endereco, int nusp, int *tamIndex){ // insere no registro index
    //  
    INDEX novo;
    
    novo.id = nusp;
    novo.byte = endereco;
    index[*tamIndex] = novo;
    (*tamIndex) = (*tamIndex) +1;
    index = (INDEX*)realloc(index,sizeof(INDEX)*((*tamIndex)+1));
    ordenaIndex(index,*tamIndex);
    

} // tudo ok
void insereRegistro(FILE* df,INDEX*vet,int nusp, int tamVET,long endereco){
    ALUNO novo;
    insereAluno(df,novo,nusp,endereco);
    insereIndex(vet,endereco,nusp ,&tamVET);
}


void GeraIndex(FILE*df,INDEX* vet,int*tam){
    int i;
    rewind(df);
    fseek(df, 0, SEEK_END); 
    for(i =0 ;i< *tam;i++){
	        fwrite(&vet[i], sizeof(INDEX), 1, df);

    }
    free(vet);
 
}

void imprimeRegistro( ALUNO aluno) {
	 printf("nUSP:%d Nome:%s Sobrenome: %s Curso: %s Nota: %f\n",aluno.numUSP,aluno.nome,aluno.sobrenome,aluno.curso,aluno.nota);
}


void removeIndex(INDEX *vet, int pos){
    vet[pos].id = (vet[pos].id)*-1;
} 


void removeRegistro(FILE *df, int pos){ // remoça logica
    rewind(df);
    fseek(df, sizeof(ALUNO)*pos,SEEK_SET);
    char c = '*';
    fwrite(&c,sizeof(char),1,df);
    rewind(df);
}
 void remover(FILE *df,INDEX *vet, int tamVET, int nusp){
     int op = PesquisaBinaria(vet,nusp,tamVET);
     removeRegistro(df,op);
     removeIndex(vet,op);

 }

void menu(){
    printf("\nOperacoes:");
    printf("\n- Gravar    1");
    printf("\n- Pesquisar 2");
    printf("\n- Remover   3");
    printf("\n- Sair      4\n\n");
}