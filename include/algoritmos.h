#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include "treinador.h"

void gera_combinacoes(Pokemon *arr, int n, int indice, Pokemon *atual, int qtd_atual, int energia_atual, int poder_atual, int limite_energia, int *melhor_p, int *melhor_e, Pokemon *melhor_temp, int *tamanho_melhor);
void combinacao_equipes(PokeLista *disponiveis, int n, int limite_energia, PokeLista *equipe_vencedora, int *poder_maximo, int *energia_consumida);

#endif