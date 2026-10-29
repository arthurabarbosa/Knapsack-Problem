#include <stdio.h>
#include <time.h>
#include "pokelista.h"
#include "treinador.h"
#include "combinacoes.h"
#include "dadosentrada.h"
#define ARQUIVO_PADRAO "arquivo.txt"

int main() {

    DadosEntrada dados;

    carregar_dados(ARQUIVO_PADRAO, &dados);

    // Exibe os pokemons carregados no terminal
    printf("--- Pokemons Carregados ---\n");
    imprime_lista(get_pokemons(&dados));
    printf("\n");

    printf("=== Executando Selecao de Pokemons (Forca Bruta) ===\n\n");

    PokeLista equipe_escolhida;

    // Variáveis para medição de tempo
    struct timespec iniciotempo, fimtempo;

    // Registra o instante inicial
    timespec_get(&iniciotempo, TIME_UTC);

    // Executa o algoritmo de força bruta recursivo
    combinacao_equipes(get_pokemons(&dados), get_numpokes(&dados), get_limenergia(&dados), &equipe_escolhida, get_podertotal(&dados), get_energiatotal(&dados));

    // Registra o instante final
    timespec_get(&fimtempo, TIME_UTC);

    // Calcula o tempo decorrido em segundos
    double tempo_execucao = (fimtempo.tv_sec - iniciotempo.tv_sec) + (fimtempo.tv_nsec - iniciotempo.tv_nsec) / 1e9;

    // Exibe o resumo com os resultados obtidos pela seleção
    printf("=== Melhor Equipe Encontrada === \n");
    printf("Poder Total: %d\n", *get_podertotal(&dados));
    printf("Energia Total Consumida: %d / %d\n", *get_energiatotal(&dados), get_limenergia(&dados));
    printf("Tempo de Execucao: %.9f segundos (%.6f ms)\n\n", tempo_execucao, tempo_execucao * MS_POR_SEGUNDO);

    // Exibe os pokemons que compõem a equipe ideal escolhida
    printf("Pokemons Selecionados para a Equipe:\n");
    imprime_lista(&equipe_escolhida);
    printf("\n");

    // Inicializa as estruturas dos treinadores com base nos nomes lidos do arquivo
    Treinador t1, t2;
    inicializa_treinador(&t1, ID_TREINADOR_1, get_nome_t1(&dados));
    inicializa_treinador(&t2, ID_TREINADOR_2, get_nome_t2(&dados));

    distribui_equipes(&t1, &t2, &equipe_escolhida);

    // Mostra o conteudo das mochilas dos treinadores sem precisar de uma quantidade grande de 'printf'
    printf("=== Equipes dos Treinadores ===\n");
    imprime_treinador(&t1);
    printf("\n");

    imprime_treinador(&t2);
    printf("\n");

    return 0;
}