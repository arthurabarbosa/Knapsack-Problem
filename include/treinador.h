#ifndef TREINADOR_H
#define TREINADOR_H
#include "pokelista.h"
#define ID_TREINADOR_1 1
#define ID_TREINADOR_2 2

// Estrutura que representa o tipo Treinador
typedef struct {
    int idt;                 // Identificador único do Treinador
    char nome[TAMANHO_NOME];           // Nome do Treinador. O TAMANHO_NOME já está incluso por causa da pokelista.h que inclui pokemon.h
    PokeLista mochila;  // Lista encadeada contendo Pokémons sob posse do treinador
} Treinador;

// Inicializa o treinador com nome, idt e sua mochila/inventário de pokemons
int inicializa_treinador(Treinador *tr, int idt, char *name);

// Adiciona o Pokémon capturado à lista do treinador 
int insere_pokemon_treinador(Treinador *tr, Pokemon pk);

// Distribui os pokemons da equipe vencedora de forma alternada entre dois treinadores
int distribui_equipes(Treinador *t1, Treinador *t2, PokeLista *equipe_escolhida);

// Imprime no terminal o status do treinador
int imprime_treinador(Treinador *tr);

#endif