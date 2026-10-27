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

// Exibe informações sobre o treinador 
int imprime_treinador(Treinador *tr) {
    printf("Treinador(a) %s", tr->nome);
    return 0;
}