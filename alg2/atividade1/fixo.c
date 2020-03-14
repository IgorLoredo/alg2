/// Igor Guilherme Pereira Loredo
//11275071

#include <stdio.h>
#include <stdlib.h>


#define TAM 16
// cadrastar, pesquisar e apresentar resultados
// nusp, nome, sobrenome,curso e nota


struct tipoAluno{
	int numUSP;
	char nome[TAM];
	char sobrenome[TAM];
	char curso[TAM];
	float nota;
};

typedef struct tipoAluno Aluno;

void criaArquivo(FILE *df) {

    if (df== NULL) {
        df= fopen("alunos.dad", "w+");        /* Se nao existir, cria o arquivo de dados */
        fclose(df);
        df= NULL;
    }
} // cria arquivo

void insereRegistro(FILE *df,int *endereco, int nusp){
    Aluno novo;
    novo.numUSP = nusp;
    printf("Coloque seu nome:\n");
    scanf("%s",novo.nome);
    printf("Sobrenome:\n");
     scanf("%s",novo.sobrenome);
    printf("Curso:\n");
     scanf("%s",novo.curso);
    printf("Nota:\n");
     scanf("%f",&novo.nota);
    // posiciona o ponteiro no ultimo byte e add um novo arquivo
    fseek(df,*endereco,0); 
    fprintf(df,"%d %s %s %s %f ",novo.numUSP,novo.nome,novo.sobrenome,novo.curso,novo.nota); 
    *endereco = *endereco + sizeof(Aluno); // guarda ultimo 
} 
 
int procuraResgistro(FILE *df, int nusp, Aluno *aux){ // procura regitro e manda ele por refeencia
    fseek(df,0,0);
    while(fscanf(df,"\n%d %s %s %s %f",&aux->numUSP,aux->nome,aux->sobrenome,aux->curso,&aux->nota) != EOF){
        if(nusp == aux->numUSP){
            return 1;
        }
    }
    return 0;// caso nao encontre o registro
}

void Registros(FILE *arq){ // ler e imprime todos os arquivos
    Aluno novo;
    fseek(arq,0,0); 
    while(fscanf(arq,"\n%d %s %s %s %f",&novo.numUSP,novo.nome,novo.sobrenome,novo.curso,&novo.nota) != EOF){
        printf("nUSP:%d Nome:%s Sobrenome: %s Curso: %s Nota: %f\n",novo.numUSP,novo.nome,novo.sobrenome,novo.curso,novo.nota);
    }
}

int main(void) {
    FILE *df = NULL;
    int operacao = 0;
    int ultimoEnd = 0, nusp;
    Aluno aluno;

    do {
	    df= fopen("alunos.dad", "w+");        
	  if (df == NULL){
           criaArquivo(df);
           printf("\nArquivos criado\n\n");
      }
	} while(df== NULL); // ver se ja tem o arquivo e cria caso no exista
    
    do{ // roda pelo menos uma vez
        printf("\nOperacoes:\n- Gravar    1\n- Pesquisar 2\n- Imprimir Registros 3\n- Finalizar 4\n\n");
        scanf("%d",&operacao);
        if(operacao == 1){
            printf("\nInsere nUSP\n");
            scanf("%d",&nusp);
            if(procuraResgistro(df,nusp, &aluno) == 0){
                insereRegistro(df,&ultimoEnd, nusp); // insere o arquivo
                //printf("\nAluno registrado:\nnUSP:%d \nNome:%s \nSobrenome: %s\nCurso: %s\nNota: %f\n",aluno.numUSP,aluno.nome,aluno.sobrenome,aluno.curso,aluno.nota);

            }else{
                printf("\nJa existe o registro\n");
            }
        }

        else if(operacao == 2){
            printf("Digite o nUSP:\n");
            scanf("%d",&nusp);
            if(procuraResgistro(df,nusp, &aluno) == 1){ // verificar se o registro existe
                printf("\nnUSP:%d \nNome:%s \nSobrenome: %s\nCurso: %s\nNota: %f\n",aluno.numUSP,aluno.nome,aluno.sobrenome,aluno.curso,aluno.nota);
            }else{
                printf("\nNo existe esse registro");
            }
        }

       else if (operacao == 3){
           Registros(df);
        } 

    }while(operacao != 4);

    fclose(df);
    return 0;
}


