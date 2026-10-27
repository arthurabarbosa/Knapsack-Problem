#ifndef POKELISTA_H
#define POKELISTA_H
#include "pokemon.h"

// Célula da lista encadeada contendo um Pokémon e o ponteiro para a próxima célula
typedef struct Celula {
    Pokemon poke;
    struct Celula* prox;
} Celula;

// Estrutura do tipo Lista Dinâmica Simplesmente Encadeada (com Nó Cabeça)
typedef struct {
    Celula* primeiro; // Ponteiro para a célula cabeça
    Celula* ultimo;   // Ponteiro para o último elemento da lista
} PokeLista;

// Inicializa a lista encadeada criando o nó cabeça
int inicializa_lista(PokeLista *lista);

// Insere um Pokémon no final da lista
int insere_lista(PokeLista *lista, Pokemon p);

// Remove um Pokémon da lista com base no seu ID
int remove_lista(PokeLista *lista, int id);

// Procura um Pokémon pelo ID e retorna uma cópia dele
Pokemon busca_lista(PokeLista *lista, int id);

// Imprime todos os elementos da lista
int imprime_lista(PokeLista *lista);

#endif