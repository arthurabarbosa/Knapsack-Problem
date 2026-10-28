#include <stdio.h>
#include <time.h>
#include "pokemon.h"
#include "pokelista.h"
#include "treinador.h"
#include "combinacoes.h"

int main() {
    // Abre o ficheiro de entrada em modo de leitura
    FILE *arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada!\n");
        return 1;
    }

    char nome_t1[50], nome_t2[50];
    int N, limite_energia;

    // Le o cabecalho contendo o nome dos treinadores, a quantidade de pokemons e o limite de energia
    fscanf(arquivo, "%s", nome_t1);
    fscanf(arquivo, "%s", nome_t2);
    fscanf(arquivo, "%d", &N);
    fscanf(arquivo, "%d", &limite_energia);

    // Inicializa a lista encadeada para armazenar os pokemons disponiveis
    PokeLista pokemons;
    inicializa_lista(&pokemons);
    
    // Le cada um dos pokemons do ficheiro e insere-os na lista
    for (int i = 0; i < N; i++) {
        Pokemon p;
        
        int num, poder, energia;
        char nome[50], tipo[50];

        // Le os atributos individuais de cada pokemon
        fscanf(arquivo, "%d %s %s %d %d", &num, nome, tipo, &poder, &energia);

        // Configura os dados do pokemon e adiciona-o a lista
        set(&p, num, num, nome, tipo, poder, energia);
        insere_lista(&pokemons, p);
    }
    // Fecha o ficheiro apos concluir a leitura
    fclose(arquivo);

    // Exibe os pokemons carregados no terminal
    printf("--- Pokemons Carregados ---\n");
    imprime_lista(&pokemons);
    printf("\n");

    printf("=== Executando Selecao de Pokemons (Forca Bruta) ===\n\n");

    PokeLista equipe_escolhida;
    int poder_total = 0;
    int energia_total = 0;

    // Variaveis para medir o tempo de processamento
    clock_t inicio, fim;

    // Regista o momento inicial da execucao do algoritmo
    inicio = clock();

    // Executa o algoritmo de forca bruta recursiva para encontrar a melhor equipe
    combinacao_equipes(&pokemons, N, limite_energia, &equipe_escolhida, &poder_total, &energia_total);

    // Regista o momento final da execucao
    fim = clock();

    // Calcula o tempo total decorrido em segundos
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Exibe o resumo com os resultados obtidos pela selecao
    printf("=== Melhor Equipe Encontrada === \n");
    printf("Poder Total: %d\n", poder_total);
    printf("Energia Total Consumida: %d / %d\n", energia_total, limite_energia);
    printf("Tempo de Execucao: %f segundos (%f ms)\n\n", tempo_execucao, tempo_execucao*1000.0);

    // Exibe os pokemons que compõem a equipe ideal vencedora
    printf("Pokemons Selecionados para a Equipe:\n");
    imprime_lista(&equipe_escolhida);
    printf("\n");

    // Inicializa as estruturas dos treinadores com base nos nomes lidos do ficheiro
    Treinador t1, t2;
    inicializa_treinador(&t1, 1, nome_t1);
    inicializa_treinador(&t2, 2, nome_t2);

    distribui_equipes(&t1, &t2, &equipe_escolhida);

    // Exibe o conteudo final das mochilas de cada treinador
    printf("=== Equipes dos Treinadores ===\n");
    printf("Treinador 1: %s\n", t1.nome);
    printf("Mochila do Treinador:\n");
    imprime_lista(&t1.mochila);
    printf("\n");

    printf("Treinador 2: %s\n", t2.nome);
    printf("Mochila do Treinador:\n");
    imprime_lista(&t2.mochila);
    printf("\n");

    return 0; // Termina o programa com sucesso
}