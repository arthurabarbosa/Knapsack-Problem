#ifndef TREINADOR_H
#define TREINADOR_H
#include "pokelista.h"

// Estrutura que representa um Treinador
typedef struct {
    int idt;               // Identificador único do Treinador
    char nome[50];         // Nome do Treinador
    PokeLista mochila;  // Lista encadeada contendo Pokémons sob posse do treinador
} Treinador;

// Inicializa o treinador com nome, idt e sua mochila/inventário de pokemons
int inicializa_treinador(Treinador *tr, int idt, char *name);

// Adiciona o Pokémon capturado à lista do treinador 
int insere_pokemon_treinador(Treinador *tr, Pokemon pk);

// Imprime no terminal o status do treinador
int imprime_treinador(Treinador *tr);

#endif