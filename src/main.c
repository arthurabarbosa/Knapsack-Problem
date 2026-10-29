#include <stdio.h>
#include <time.h>
#include "pokemon.h"
#include "pokelista.h"
#include "treinador.h"
#include "combinacoes.h"
#define ARQUIVO_PADRAO "arquivo.txt"
#define MS_POR_SEGUNDO 1000.0

int main() {
    // Abre o arquivo de entrada em modo de leitura
    FILE *arquivo = fopen(ARQUIVO_PADRAO, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada!\n");
        return 1;
    }

    // Declaração de variáveis
    char nome_t1[TAMANHO_NOME], nome_t2[TAMANHO_NOME];
    int N, limite_energia;

    // Lê o cabeçalho contendo o nome dos treinadores, a quantidade de pokémons e o limite de energia
    fscanf(arquivo, "%s", nome_t1);
    fscanf(arquivo, "%s", nome_t2);
    fscanf(arquivo, "%d", &N);
    fscanf(arquivo, "%d", &limite_energia);

    // Inicializa a lista encadeada para armazenar os pokémons disponiveis
    PokeLista pokemons;
    inicializa_lista(&pokemons);
    
    // Lê cada um dos pokémons do arquivo e insere eles na lista
    for (int i = 0; i < N; i++) {
        Pokemon p;
        
        int num, poder, energia;
        char nome[TAMANHO_NOME], tipo[TAMANHO_TIPO];

        // Lê os atributos de cada pokemon
        fscanf(arquivo, "%d %s %s %d %d", &num, nome, tipo, &poder, &energia);

        // Configura os dados do pokémon e adiciona-o à lista
        set(&p, num, num, nome, tipo, poder, energia);
        insere_lista(&pokemons, p);
    }

    // Fecha o arquivo após concluir a leitura
    fclose(arquivo);

    // Exibe os pokemons carregados no terminal
    printf("--- Pokemons Carregados ---\n");
    imprime_lista(&pokemons);
    printf("\n");

    printf("=== Executando Selecao de Pokemons (Forca Bruta) ===\n\n");

    PokeLista equipe_escolhida;
    int poder_total = 0;
    int energia_total = 0;

    // Variáveis para medição de tempo
    struct timespec inicioTempo, fimTempo;

    // Registra o instante inicial
    timespec_get(&inicioTempo, TIME_UTC);

    // Executa o algoritmo de força bruta recursivo
    combinacao_equipes(&pokemons, N, limite_energia, &equipe_escolhida, &poder_total, &energia_total);

    // Registra o instante final
    timespec_get(&fimTempo, TIME_UTC);

    // Calcula o tempo decorrido em segundos
    double tempo_execucao = (fimTempo.tv_sec - inicioTempo.tv_sec) + (fimTempo.tv_nsec - inicioTempo.tv_nsec) / 1e9;

    // Exibe o resumo com os resultados obtidos pela seleção
    printf("=== Melhor Equipe Encontrada === \n");
    printf("Poder Total: %d\n", poder_total);
    printf("Energia Total Consumida: %d / %d\n", energia_total, limite_energia);
    printf("Tempo de Execucao: %f segundos (%f ms)\n\n", tempo_execucao, tempo_execucao * MS_POR_SEGUNDO);

    // Exibe os pokemons que compõem a equipe ideal escolhida
    printf("Pokemons Selecionados para a Equipe:\n");
    imprime_lista(&equipe_escolhida);
    printf("\n");

    // Inicializa as estruturas dos treinadores com base nos nomes lidos do arquivo
    Treinador t1, t2;
    inicializa_treinador(&t1, ID_TREINADOR_1, nome_t1);
    inicializa_treinador(&t2, ID_TREINADOR_2, nome_t2);

    distribui_equipes(&t1, &t2, &equipe_escolhida);

    // Mostra o conteudo das mochilas dos treinadores sem precisar de uma quantidade grande de 'printf'
    printf("=== Equipes dos Treinadores ===\n");
    imprime_treinador(&t1);
    printf("\n");

    imprime_treinador(&t2);
    printf("\n");

    return 0;
}