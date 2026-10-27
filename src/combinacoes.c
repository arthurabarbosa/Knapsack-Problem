#include <stdio.h>
#include "combinacoes.h"

// Funcao recursiva pura para gerar todas as combinacoes possiveis de pokemons (forca bruta exaustiva)
void gera_combinacoes(Pokemon *vetor, int n, int indice, Pokemon *atual, int qtd_atual, int energia_atual, int poder_atual, int limite_energia, int *melhor_p, int *melhor_e, Pokemon *melhor_temp, int *tamanho_melhor) {
    
    // Condicao de paragem: avalia a combinacao completa ao atingir o fim do vetor de pokemons
    if (indice == n) {
        // Verifica se o consumo total respeita o limite de energia e se o poder e compativel
        if (energia_atual <= limite_energia && poder_atual >= *melhor_p) {
            // Se encontrar um poder maior ou um poder igual consumindo mais energia, atualiza a melhor opcao
            if (poder_atual > *melhor_p || (poder_atual == *melhor_p && energia_atual > *melhor_e)) {
                *melhor_p = poder_atual;
                *melhor_e = energia_atual;
                *tamanho_melhor = qtd_atual;
                for (int i = 0; i < qtd_atual; i++) {
                    melhor_temp[i] = atual[i];
                }
            }
        }
        return;
    }

    // Ramo principal: inclui o pokemon atual na combinacao em construção e avanca para o proximo indice
    atual[qtd_atual] = vetor[indice];
    gera_combinacoes(vetor, n, indice + 1, atual, qtd_atual + 1, energia_atual + vetor[indice].energia_gasta, poder_atual + vetor[indice].pt_poder, limite_energia, melhor_p, melhor_e, melhor_temp, tamanho_melhor);

    // Ramo alternativo: nao inclui o pokemon atual e avanca para o proximo indice mantendo o estado anterior
    gera_combinacoes(vetor, n, indice + 1, atual, qtd_atual, energia_atual, poder_atual, limite_energia, melhor_p, melhor_e, melhor_temp, tamanho_melhor);
}

// Funcao de interface chamada pela main para preparar os dados e iniciar a recursao
void combinacao_equipes(PokeLista *pokemons, int n, int limite_energia, PokeLista *equipe_vencedora, int *poder_maximo, int *energia_consumida) {
    
    // Converte a lista encadeada num vetor estatico para acesso rapido por indice
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

    // Dispara a geracao recursiva de todas as combinacoes possiveis
    gera_combinacoes(vetor, n, 0, atual, 0, 0, 0, limite_energia, &melhor_p, &melhor_e, melhor_temp, &tamanho_melhor);

    // Atribui os resultados maximos encontrados as variaveis de referencia
    *poder_maximo = melhor_p;
    *energia_consumida = melhor_e;

    // Inicializa a lista vencedora e preenche-a com os pokemons da melhor equipe otimizada
    inicializa_lista(equipe_vencedora);
    for (int i = 0; i < tamanho_melhor; i++) {
        insere_lista(equipe_vencedora, melhor_temp[i]);
    }
}