/// Igor Guilherme Pereira Loredo
//11275071

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define TAM 16
// cadrastar, pesquisar e apresentar resultados
// nusp, nome, sobrenome,curso e nota
//#define DEL "*"

struct tipoAluno{
	int numUSP;
	char nome[TAM];
	char sobrenome[TAM];
	char curso[TAM];
	float nota;
};

typedef struct tipoAluno Aluno;

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

void insereRegistro(FILE *df, int *endereco ){
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
    scanf("%f",&novo.nota);;
    rewind(df);
    fseek(df,*endereco,0); 
    //fprintf(df,"\n%d %s %s %s %f",novo->numUSP,novo->nome,novo->sobrenome,novo->curso,novo->nota);
    fwrite(&novo, sizeof(Aluno), 1, df);
    *endereco = *endereco + sizeof(Aluno);

}

void imprimeAluno(Aluno*novo){
    printf("nUSP:%d Nome:%s Sobrenome: %s Curso: %s Nota: %f\n",novo->numUSP,novo->nome,novo->sobrenome,novo->curso,novo->nota);
}

Aluno *procuraResgistro(FILE *arq, int nusp, int tamArq){
    int i;
    int flag = 0,tam  = (int)(tamArq/sizeof(Aluno));
    rewind(arq);
    Aluno *novo;
    Aluno aux;
    printf("%d\n",tam);
    for(i =0;i < tam;i++){
        fread(&aux,sizeof(Aluno),1,arq);
        if(aux.numUSP == nusp){
            flag = 1;
            break;
        }
    }
    if(flag){
        Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
        novo->numUSP = aux.numUSP;
        novo->nota = aux.nota;
        strcpy(novo->sobrenome,aux.sobrenome);
        strcpy(novo->curso, aux.curso);
        strcpy(novo->nome,aux.nome);
        return novo;
    }
    return NULL;
}


int remover(FILE *arq, int nusp, int tamArq){

    int i,flag = 0,tam  = (int)(tamArq/sizeof(Aluno));
    rewind(arq);
    Aluno *novo;
    Aluno aux;
    for(i =0;i < tam;i++){
        fread(&aux,sizeof(Aluno),1,arq);
        if(aux.numUSP == nusp){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        fseek(arq, -sizeof(Aluno), SEEK_CUR);
        //fwrite(DEL, sizeof(DEL),1, arq);
        char c ='*';
        fputc(c, arq);
    }
    
    return -1;
}




int main(void) {
    int num,operacao = 0;
    Aluno *aux;
    FILE *df = criarArquivo("alunos.dad");
    
    fseek(df,0, SEEK_END);
    int ultimoEnd =ftell(df);

    do{
        printf("\nOperacoes:\n- Gravar    1\n- Pesquisar 2\n- Remover   3\n- Sair      4\n");
        scanf("%d",&operacao);
        if(operacao == 1){
            insereRegistro(df,&ultimoEnd);
        }

        if(operacao == 2){
            printf("\nInsira o nUSP\n");
                scanf("%d",&num);
                aux  = procuraResgistro(df,num,ultimoEnd);
                if (aux){
                    imprimeAluno(aux);
                }else{
                    printf("Aluno nao encontrado\n");
                }
                aux = NULL;
        }
        if(operacao == 3){
            printf("\nInsira o nUSP para Remover\n");
            scanf("%d",&num);
            if(remover(df, num,ultimoEnd)){
                printf("Removeu com Sucesso\n");
            }else{
                printf("ERRO ao Remover");
            }
        }

    }while(operacao != 4);

   // free(aux);
    fclose(df);
  return 0;
}