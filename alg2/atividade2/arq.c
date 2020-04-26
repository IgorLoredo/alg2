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


int tamArquivo(FILE*arq){ // acha o tamanho do arquivo de armazenamento
    if(!arq) return 0;
    fseek(arq,0,SEEK_END);
    int aux=((int) ftell(arq))/sizeof(ALUNO);
    return aux;
}


INDEX* LerIndex(FILE* index, int *tam){ // ler conteudo do arquivo index e coloca em um vetor index
    if(!index) return NULL;
    int quant=0 ,i;
    fseek(index, 0, SEEK_END);
    quant = (int)( ftell(index))/sizeof(INDEX);
    INDEX* novo = (INDEX*)malloc(sizeof(INDEX)*(quant+1)); 
    fseek(index, 0, SEEK_SET);
    if(quant > 0){
        for(i =0; i < quant;i++){
	        fread(&novo[i], sizeof(INDEX), 1, index); 
           // printf("      %d  f", novo[i].id);
        }
        *tam = quant;
        return novo;
    }
        return NULL;
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

ALUNO CriarAluno(){ // pega o resgistro do aluno e retona um tipo aluno
    ALUNO novo;
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

int insereIndex(INDEX* index,int endereco, int nusp, int *tamIndex){ // insere no registro index
    if(!index) return 0;
    index = (INDEX*)realloc(index,sizeof(INDEX)*(*tamIndex+1));
    index[*tamIndex].id = nusp;
    index[*tamIndex].rrn = endereco;
    return 1;
}


int insereReg(FILE *df,INDEX*vet  ,int endereco, int TamIndex){// segue o mesmo esquema do 
    if(!df)return -1;
    ALUNO novo = CriarAluno();  // pega registro 
    if(PesquisaBinaria(vet,novo.numUSP,TamIndex) < 0){
        fseek(df, 0, SEEK_END); 
	    fwrite(&novo, sizeof(ALUNO), 1, df);
        insereIndex(vet,endereco+1,novo.numUSP, &TamIndex);
        return 1;
    }else{
        printf("    Aluno ja tem cadrastro\n");
    }
    
    return 0;
}
 

void GeraIndex(FILE*df, INDEX* vet,int*tam){
    int i;
    fseek(df, 0, SEEK_SET); 
    for(i =0 ;i< *tam;i++){
	    fwrite(&vet[i], sizeof(INDEX), 1, df);
        printf("%d \n",  vet[i].id);

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