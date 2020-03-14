/*  SCC0503 - Algoritmos e Estruturas de Dados II - Pratica 1 - Arquivos */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define TAM 16

typedef int tipoChave;

typedef struct {
	tipoChave numUSP;
	char nome[TAM];
	char sobrenome[TAM];
	char curso[TAM];
	float nota;
} tipoAluno;

void criaArquivo(FILE *);
void insereRegistro();
void pesquisaRegistro();
void imprimeRegistro();
void finalizaExecucao(FILE *);

int main(void) {
	FILE *df;
	int comando= 0;

	do {
	    df= fopen("alunos.dad", "r+");
	    if (df== NULL) criaArquivo(df);
	} while(df== NULL);


	do {
		printf("Operacoes:\n- Gravar\n- Pesquisar\n- Finalizar\n\n");


		/* Programa deve proceder de acordo com a operacao desejada */


	} while(comando> 0);


	finalizaExecucao(df);

return 0;

}

void criaArquivo(FILE *df) {

    if (df== NULL) {
        df= fopen("alunos.dad", "w");        /* Se nao existir, cria o arquivo de dados */
        fclose(df);
        df= NULL;
    }
}


/* demais metodos a serem implementados */


void finalizaExecucao(FILE *df) {
    /* Arquivo de dados deve ser fechado com a finalizacao do programa */
}