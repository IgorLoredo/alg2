//igor guilherme pereira loredo
// nusp 11275071

#include <stdio.h>
#include <stdlib.h>
#include <arq.h>

int main(void) {
    int comando,nusp;
    int tamIndex =0;
    long endereco=0;
    ALUNO aux;
    INDEX **vetIndex = (INDEX**)malloc(sizeof(INDEX*));
    FILE *df = NULL;
    FILE *index = NULL;

    do {
	    df= fopen("alunos.dad", "r+");        
	    if (df == NULL){
           criaArquivo(df);
           printf("\nArquivos criado\n\n");
      }
	} while(df== NULL); // ver se ja tem o arquivo e cria caso no exista

    do {
	    index= fopen("index.dad", "r+");        
	    if (index == NULL){
           criaIndex(index);
           printf("\nArquivos index criado\n\n");
      }
	} while(index== NULL); // ver se ja tem o arquivo e cria caso no exista
    
     tamIndex = LerIndex(index, vetIndex); // pega o tamanho do fileindex junto e colcoa em um vetor
    
    do {
		 printf("\nOperacoes:\n- Gravar    1\n- Pesquisar 2\n- Remover 3\n- Sair 4\n\n");
        scanf("%d",&comando);

        if(comando == 1){
            printf("Inseri nUSP:");
            scanf("%d",&nusp); 
            if(pesquisaIndex(df,vetIndex,aux,nusp,tamIndex) == 0){
                insereRegistro(df,vetIndex,nusp,tamIndex, endereco);
            } 

        }else if(comando == 2){
            printf("\nInseri nUSP:\n");
            scanf("%d",&nusp);     
            if(pesquisaIndex(df,vetIndex,aux,nusp,tamIndex) != 0 )
               imprimeRegistro(aux);
             else
                printf("\t\nRegistro nao existe ou foi apagado\n");
            
        }else if(comando == 3){
            printf("\nInseri nUSP:\n");
            scanf("%d",&nusp);
            if(pesquisaIndex(df,vetIndex,aux,nusp,tamIndex) != 0 )
               remover(df,vetIndex,tamIndex,nusp);
             else
                printf("\t\nRegistro nao existe ou ja foi apagado\n");
        }
		
	} while(comando != 4); 

   GeraIndex(index,vetIndex,&tamIndex);
    fclose(index);
    fclose(df);

  return 0;
}