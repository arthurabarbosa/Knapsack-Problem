#include <stdio.h>
#include <string.h>
#include "treinador.h"

// Configura o treinador no estado inicial
int inicializa_treinador(Treinador *tr, int idt, char *name) {
    tr->idt = idt;
    strcpy(tr->nome, name);
    
    inicializa_lista(&tr->mochila);

    return 0;
}

// Insere o pokemon na mochila do treinador
int insere_pokemon_treinador(Treinador *tr, Pokemon pk) {
    insere_lista(&tr->mochila, pk);
    return 0;
}

// Distribui os pokemons da equipe escolhida de forma alternada entre os dois treinadores
int distribui_equipes(Treinador *t1, Treinador *t2, PokeLista *equipe_escolhida) {
    if (equipe_escolhida == NULL || equipe_escolhida->primeiro == equipe_escolhida->ultimo) {
        return 0;
    }

    Celula *atual = equipe_escolhida->primeiro->prox;
    int alternar = 0;
    
    while (atual != NULL) {
        if (alternar % 2 == 0) {
            insere_pokemon_treinador(t1, atual->poke);
        } else {
            insere_pokemon_treinador(t2, atual->poke);
        }
        atual = atual->prox;
        alternar++;
    }
    return 1;
}

// Imprime as informações do treinador de acordo com o exemplo
int imprime_treinador(Treinador *tr) {
    printf("Treinador %d: %s\n", tr->idt, tr->nome);
    printf("Mochila do Treinador:\n");
    imprime_lista(&tr->mochila);

    return 0;
}