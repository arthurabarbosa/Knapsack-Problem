# Antes de tentar compilar ou rodar o programa, tenha o arquivo teste salvo na pasta do projeto com o nome 'arquivo.txt'
# Para compilar o programa, primeiro digite no terminal 'make compile' (para sistemas linux) ou 'mingw32-make compile' para sistemas Windows
# Para executar o programa, repita o processo anterior no terminal, mas trocando 'compile' por 'run'

CC = gcc
CFLAGS = -Wall -g -Iinclude -lm

compile:
	$(CC) src/*.c -o bin/main.exe $(CFLAGS)

run:
	./bin/main.exe

clean:
	rm -f bin/*.exe