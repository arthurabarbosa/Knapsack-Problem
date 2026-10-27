#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pokemon.h"
#include "pokelista.h"
#include "treinador.h"
#include "algoritmos.h"

int main() {
    FILE *arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada!\n");
        return 1;
    }

    char nome_t1[50], nome_t2[50];
    int N, limite_energia;

    fscanf(arquivo, "%s", nome_t1);
    fscanf(arquivo, "%s", nome_t2);
    fscanf(arquivo, "%d", &N);
    fscanf(arquivo, "%d", &limite_energia);

    PokeLista pokemons;
    inicializa_lista(&pokemons);
    
    for (int i = 0; i < N; i++) {
        Pokemon p;
        
        int num, poder, energia;
        char nome[50], tipo[50];

        fscanf(arquivo, "%d %s %s %d %d", &num, nome, tipo, &poder, &energia);

        set(&p, i+1, num, nome, tipo, poder, energia);

        insere_lista(&pokemons, p);
    }
    fclose(arquivo);

    printf("--- Pokemons Carregados ---\n");
    imprime_lista(&pokemons);
    printf("\n");

    printf("=== Executando Selecao de Pokemons (Forca Bruta) ===\n\n");

    PokeLista equipe_escolhida;
    int poder_total = 0;
    int energia_total = 0;

    clock_t inicio, fim;

    inicio = clock();

    combinacao_equipes(&pokemons, N, limite_energia, &equipe_escolhida, &poder_total, &energia_total);

    fim = clock();

    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("=== Melhor Equipe Encontrada === \n");
    printf("Poder Total: %d\n", poder_total);
    printf("Energia Total Consumida: %d / %d\n", energia_total, limite_energia);
    printf("Tempo de Execucao: %f segundos (%f ms)\n\n", tempo_execucao, tempo_execucao*1000);

    printf("Pokemons Selecionados para a Equipe:\n");
    imprime_lista(&equipe_escolhida);
    printf("\n");

    Treinador t1, t2;
    inicializa_treinador(&t1, 1, nome_t1);
    inicializa_treinador(&t2, 2, nome_t2);

    Celula *atual = equipe_escolhida.primeiro->prox;
    int alternar = 0;
    while (atual != NULL) {
        if (alternar % 2 == 0) {
            insere_pokemon_treinador(&t1, atual->poke);
        } else {
            insere_pokemon_treinador(&t2, atual->poke);
        }
        atual = atual->prox;
        alternar++;
    }

    printf("=== Equipes dos Treinadores ===\n");
    printf("Treinador 1: %s\n", t1.nome);
    printf("Mochila do Treinador:\n");
    imprime_lista(&t1.mochila);
    printf("\n");

    printf("Treinador 2: %s\n", t2.nome);
    printf("Mochila do Treinador:\n");
    imprime_lista(&t2.mochila);
    printf("\n");

    return 0;
}