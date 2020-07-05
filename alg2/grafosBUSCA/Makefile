#igor guilherme pereira loredo nusp 11275071
all: compile

compile-lista:
	@gcc -o listaExe lista/*.c -I lista/. -Wall

compile:
	@gcc -o matrizExe matriz/*.c -I matriz/. -Wall
	@gcc -o listaExe lista/*.c -I lista/. -Wall
	@gcc -o buscaExe busca/*.c -I. -Wall

compile-matriz:
	@gcc -o matrizExe matriz/*.c -I. -Wall

compile-busca:
	@gcc -o buscaExe busca/*.c -I. -Wall

run-busca:
	@./buscaExe

run-matriz:
	@./matrizExe

run-lista:
	@./listaExe
