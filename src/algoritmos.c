#include <stdio.h>
#include "algoritmos.h"

void gera_combinacoes(Pokemon *vetor, int n, int indice, Pokemon *atual, int qtd_atual, int energia_atual, int poder_atual, int limite_energia, int *melhor_p, int *melhor_e, Pokemon *melhor_temp, int *tamanho_melhor) {
    
    if (indice == n) {
        if (energia_atual <= limite_energia && poder_atual > *melhor_p) {
            *melhor_p = poder_atual;
            *melhor_e = energia_atual;
            *tamanho_melhor = qtd_atual;
            for (int i = 0; i < qtd_atual; i++) {
                melhor_temp[i] = atual[i];
            }
        }
        return;
    }

    gera_combinacoes(vetor, n, indice + 1, atual, qtd_atual, energia_atual, poder_atual, limite_energia, melhor_p, melhor_e, melhor_temp, tamanho_melhor);

    atual[qtd_atual] = vetor[indice];
    gera_combinacoes(vetor, n, indice + 1, atual, qtd_atual + 1, energia_atual + vetor[indice].energia_gasta, poder_atual + vetor[indice].pt_poder, limite_energia, melhor_p, melhor_e, melhor_temp, tamanho_melhor);
}

void combinacao_equipes(PokeLista *pokemons, int n, int limite_energia, PokeLista *equipe_vencedora, int *poder_maximo, int *energia_consumida) {
    
    Pokemon vetor[n];
    Celula *no = pokemons->primeiro->prox;
    for (int i = 0; i < n && no != NULL; i++) {
        vetor[i] = no->poke;
        no = no->prox;
    }

    int melhor_p = -1;
    int melhor_e = 0;
    Pokemon melhor_temp[n];
    int tamanho_melhor = 0;
    Pokemon atual[n];

    gera_combinacoes(vetor, n, 0, atual, 0, 0, 0, limite_energia, &melhor_p, &melhor_e, melhor_temp, &tamanho_melhor);

    *poder_maximo = melhor_p;
    *energia_consumida = melhor_e;

    inicializa_lista(equipe_vencedora);
    for (int i = 0; i < tamanho_melhor; i++) {
        insere_lista(equipe_vencedora, melhor_temp[i]);
    }
}