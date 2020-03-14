// nUSP 11275071
// igor guilherme pereira loredo

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TAM 16
// cadrastar, pesquisar e apresentar resultados
// nusp, nome, sobrenome,curso e nota


/*
    sscanf para  para ler os arquivos
*/


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
        df= fopen("alunos.dad", "w");/* Se nao existir, cria o arquivo de dados */
        fclose(df);
        df= NULL;
    }
} // cria arquivo

void insereRegistro(FILE *arq,int nusp, int endereco){ // insere o regritro
    char contByte;
    Aluno novo;
    char string[1000];
    printf("Coloque seu nome:");
    scanf(" %s",novo.nome);
    //inserePalavra(novo.nome);
    printf("Sobrenome:");
    scanf(" %s",novo.sobrenome);
    //inserePalavra(novo.sobrenome);
    printf("Curso:");
    scanf(" %s",novo.curso);
    //inserePalavra(novo.curso );
    printf("Nota:");
    scanf("%f", &novo.nota);
   
    sprintf(string,"|%s|%s|%s ",novo.nome,novo.sobrenome,novo.curso);
    contByte = strlen(string);
    fprintf(arq," %d |%d",contByte,nusp);
    fwrite(string,contByte,1,arq);
    fprintf(arq,"|%f|",novo.nota);
    endereco = endereco+contByte+8;
}


char *parser(char *buffer, int *pos) {
    int posi = *pos;

    while(buffer[*pos]!='|')
        (*pos)++;
    buffer[*pos] = '\0';
    (*pos)++;
    return &buffer[posi];
}

int procuraResgistro(FILE *df, int nusp, Aluno *reg){ // procura regitro e manda ele por refeencia
    int pos;
    int quantByte;
    char *pal = (char*)malloc(sizeof(char)*1000);
    fseek(df,0,0);  
    while(fscanf(df,"\n%d |%d %s|",&quantByte,&reg->numUSP,pal) !=EOF){
        
         if(reg->numUSP == nusp){
             printf("%f\n",reg->nota);
             printf("\n%s",pal); // imrpiem registro
                return 1;
        }
    }
    
    return 0; // caso n exista registro
}

/*void registro(FILE *arq){
    Aluno *reg;
    int q
    fseek(arq,0,0);  
    char *pal = (char*)malloc(sizeof(char)*1000);
    while(fscanf(df,"\n%d |%d %s|",&quantByte,&reg->numUSP,pal) !=EOF){
             printf("%f\n",reg->nota);
             printf("\n%s",pal);
        }
    }

}*/

int main(void) {
    FILE *df = NULL;
    int operacao = 0;
    int ultimoEnd = 0, nusp;
    Aluno *aluno;

    do {
	    df= fopen("alunos.dad", "a+");        
	  if (df == NULL){
           criaArquivo(df);
           printf("\nArquivos criado\n\n");
      }
	} while(df== NULL); // ver se ja tem o arquivo e cria caso no exista
    
    do{
        printf("\nOperacoes:\n- Gravar    1\n- Pesquisar 2\n- Imprimir Registros 3\n- Finalizar 4\n\n");
        scanf("%d",&operacao);

        if(operacao == 1){
            printf("\nInsere nUSP\n");
            scanf("%d",&nusp);
            if(procuraResgistro(df,nusp,aluno)!= 1){
            insereRegistro(df,nusp,ultimoEnd);
            }else{
                printf("ja existe o registro");
            }
        }else if(operacao == 2){
            printf("\nInseri nUSP\n");
            scanf("%d",&nusp);
            if(procuraResgistro(df,nusp,aluno)!= 1){
                printf("\nNo existe esse registro");
            } 
        }/*else if(operacao == 3){

        }*/
    }while(operacao != 4);

    fclose(df);
    return 0;
}