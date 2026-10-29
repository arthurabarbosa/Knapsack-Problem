#ifndef COMBINACOES_H
#define COMBINACOES_H
#include "treinador.h"

// Assinatura da funcao recursiva que explora todas as combinacoes de pokemons sem podas antecipadas
void gera_combinacoes(Pokemon *vetor, int n, int indice, Pokemon *atual, int qtd_atual, int energia_atual, int poder_atual, int limite_energia, int *melhor_p, int *melhor_e, Pokemon *melhor_temp, int *tamanho_melhor);

// Assinatura da funcao principal responsavel por coordenar a busca da melhor equipe de pokemons
void combinacao_equipes(PokeLista *pokemons, int n, int limite_energia, PokeLista *equipe_vencedora, int *poder_maximo, int *energia_consumida);

#endif