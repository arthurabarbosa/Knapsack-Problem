#ifndef TREINADOR_H
#define TREINADOR_H
#include "pokelista.h"
#include "pokemon.h"

// Estrutura que representa um Treinador
typedef struct {
    int idt;               // Identificador único do Treinador
    int pokebolas;         // Quantidade atual de Pokébolas disponíveis
    char nome[50];         // Nome do Treinador
    int x;                 // Posição atual X no mapa
    int y;                 // Posição atual Y no mapa
    PokeLista capturados;  // Lista encadeada contendo Pokémons sob posse do treinador
} Treinador;

// Inicializa o treinador com nome, id, pokébolas e lista de capturados
int inicializa_treinador(Treinador *tr, int idt, char *name, int pokebolas);

// Atualiza as coordenadas do treinador
int move_treinador(Treinador *tr, int x, int y);

// Adiciona o Pokémon capturado à lista do treinador e decrementa as Pokébolas
int captura_treinador(Treinador *tr, Pokemon pk);

// Remove um Pokémon da lista de capturados do treinador
int retira_treinador(Treinador *tr, int id);

// Imprime no terminal o status do treinador
int imprime_treinador(Treinador *tr);

// Calcula a distância euclidiana entre dois treinadores e um Pokémon alvo
// Retorna o ponteiro para o treinador mais próximo (ou de menor ID em caso de empate)
Treinador *calculo_distancia(Treinador *tr, Treinador *tr2, Pokemon *pk, double *dist1, double *dist2);

#endif