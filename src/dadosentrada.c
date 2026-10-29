#include <stdio.h>
#include "dadosentrada.h"

// Carrega os dados vindos do arquivo de entrada
int carregar_dados(char *caminho_arquivo, DadosEntrada *dados) {
    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada!\n");
        return 0;
    }

    dados->energia_total = 0;
    dados->poder_total = 0;

    // Lê o arquivo direto para a estrutura
    fscanf(arquivo, "%s", dados->nome_t1);
    fscanf(arquivo, "%s", dados->nome_t2);
    fscanf(arquivo, "%d", &dados->N);
    fscanf(arquivo, "%d", &dados->limite_energia);

    // Inicializa a lista encadeada dentro da estrutura
    inicializa_lista(&dados->pokemons);

    // Lê os N pokémons
    for (int i = 0; i < dados->N; i++) {
        Pokemon p;
        int num, poder, energia;
        char nome[TAMANHO_NOME], tipo[TAMANHO_TIPO];

        fscanf(arquivo, "%d %s %s %d %d", &num, nome, tipo, &poder, &energia);
        set(&p, num, num, nome, tipo, poder, energia);
        insere_lista(&dados->pokemons, p);
    }

    fclose(arquivo);
    return 1;
}


// Retorna o ponteiro para o nome do primeiro treinador
char* get_nome_t1(DadosEntrada *dados) {
    return dados->nome_t1;
}

// Retorna o ponteiro para o nome do segundo treinador
char* get_nome_t2(DadosEntrada *dados) {
    return dados->nome_t2;
}

// Retorna a quantidade N de Pokémons disponíveis
int get_numpokes(DadosEntrada *dados) {
    return dados->N;
}

// Retorna o limite de energia suportado
int get_limenergia(DadosEntrada *dados) {
    return dados->limite_energia;
}

// Retorna o endereço de memória do poder total
int* get_podertotal(DadosEntrada *dados) {
    return &dados->poder_total;
}

// Retorna o endereço de memória da energia total
int* get_energiatotal(DadosEntrada *dados) {
    return &dados->energia_total;
}

// Retorna o ponteiro para a lista encadeada de pokemons
PokeLista* get_pokemons(DadosEntrada *dados) {
    return &dados->pokemons;
}