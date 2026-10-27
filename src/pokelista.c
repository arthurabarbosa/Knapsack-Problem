#include <stdio.h>
#include <stdlib.h>
#include "pokelista.h"

// Inicializa a lista encadeada criando a célula cabeça
int inicializa_lista(PokeLista *lista) {
    lista->primeiro = (Celula*) malloc(sizeof(Celula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    
    return 0;
}

// Insere um elemento no final da lista
int insere_lista(PokeLista *lista, Pokemon p) {
    lista->ultimo->prox = (Celula*) malloc(sizeof(Celula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->poke = p;
    lista->ultimo->prox = NULL;

    return 0;
}

// Remove o Pokémon correspondente ao ID informado
int remove_lista(PokeLista *lista, int id) {
    // Caso a lista esteja vazia
    if (lista->primeiro == lista->ultimo) {
        return 0; 
    }

    Celula *anterior = lista->primeiro;
    Celula *atual = lista->primeiro->prox;

    // Busca a célula que possui o ID fornecido
    while (atual != NULL && atual->poke.id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    // ID não encontrado
    if (atual == NULL) {
        return 0;
    }

    // Ajusta os ponteiros para desvincular o nó
    anterior->prox = atual->prox;
    
    // Se o elemento removido for o último, atualiza o ponteiro 'ultimo'
    if (atual == lista->ultimo) {
        lista->ultimo = anterior;
    }

    free(atual); // Libera a memória desalocada

    return 1;
}

// Busca e retorna os dados do Pokémon com determinado ID
Pokemon busca_lista(PokeLista *lista, int id) {
    Pokemon nao_encontrado;
    nao_encontrado.id = -1; // Retorno padrão para indicar insucesso

    if (lista->primeiro == lista->ultimo) {
        return nao_encontrado;
    }

    Celula *atual = lista->primeiro->prox;

    while (atual != NULL) {
        if (atual->poke.id == id) {
            return atual->poke;
        }
        atual = atual->prox;
    }

    return nao_encontrado;
}

// Percorre e imprime os dados de cada Pokémon da lista
int imprime_lista(PokeLista *lista) {
    if (lista->primeiro == lista->ultimo) {
        return 0;
    }
    Celula *atual = lista->primeiro->prox;
    int aux = 1;

    while (atual != NULL) {
        printf("ID do %do Pokemon: %d\n", aux, atual->poke.id);
        printf("Nome do %do Pokemon: %s\n", aux, atual->poke.nome);
        printf("\n");
        printf("Numero do %do Pokemon na Pokedex: %d\n", aux, atual->poke.numero_pokedex);
        printf("Coordenadas do %do Pokemon: (%d,%d)\n", aux, atual->poke.x, atual->poke.y);
        
        atual = atual->prox;
        aux++;
    }

    return 1;
}