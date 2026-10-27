#include <stdio.h>
#include <string.h>
#include "pokemon.h"

// Define todos os dados do Pokémon passado por ponteiro
int set(Pokemon *pk, int id, int numero, char *name, char *type, int x, int y) {
    pk->id = id;
    pk->numero_pokedex = numero;
    strcpy(pk->nome, name);
    strcpy(pk->tipo, type);
    pk->x = x;
    pk->y = y;

    return 0;
}

// Retorna o ID único do Pokémon
int get_id(Pokemon *pk) {
    return pk->id;
}

// Retorna o número do Pokémon na Pokédex
int get_numeropokedex(Pokemon *pk) {
    return pk->numero_pokedex;
}

// Copia o nome do Pokémon para a variável de saída
void get_nome(Pokemon *pk, char *name) {
    strcpy(name, pk->nome);
}

// Copia o tipo do Pokémon para a variável de saída
void get_tipo(Pokemon *pk, char *type) {
    strcpy(type, pk->tipo);
}

// Retorna a posição X
int get_x(Pokemon *pk) {
    return pk->x;
}

// Retorna a posição Y
int get_y(Pokemon *pk) {
    return pk->y;
}

// Exibe na tela o nome e a localização do Pokémon
void imprime_pokemon(Pokemon *pk) {
    printf("Pokémon alvo: %s\n", pk->nome);
    printf("Localização: (%d,%d)\n", pk->x, pk->y);
}