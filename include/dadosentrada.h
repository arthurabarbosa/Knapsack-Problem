#ifndef DADOSENTRADA_H
#define DADOSENTRADA_H
#define MS_POR_SEGUNDO 1000.0
#define ARQUIVO_PADRAO "arquivo.txt"

#include "pokemon.h"
#include "pokelista.h"

typedef struct {
    char nome_t1[TAMANHO_NOME];
    char nome_t2[TAMANHO_NOME];
    int N;
    int limite_energia;
    int poder_total;
    int energia_total;
    PokeLista pokemons;
} DadosEntrada;

// Carrega os dados vindos do arquivo de entrada
int carregar_dados(char *caminho_arquivo, DadosEntrada *dados);

// Funções get para manter o encapsulamento na main
char* get_nome_t1(DadosEntrada *dados);
char* get_nome_t2(DadosEntrada *dados);
int get_numpokes(DadosEntrada *dados);
int get_limenergia(DadosEntrada *dados);
int* get_podertotal(DadosEntrada *dados);
int* get_energiatotal(DadosEntrada *dados);
PokeLista* get_pokemons(DadosEntrada *dados);

#endif