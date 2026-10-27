#include <stdio.h>
#include <string.h>
#include <math.h>
#include "treinador.h"

// Configura o treinador no estado inicial
int inicializa_treinador(Treinador *tr, int idt, char *name, int pokebolas) {
    tr->idt = idt;
    tr->pokebolas = pokebolas; 
    strcpy(tr->nome, name);
    
    // Inicia no Centro de Pesquisa (0,0)
    tr->x = 0;
    tr->y = 0;
    
    inicializa_lista(&tr->capturados);

    return 0;
}

// Altera a localização do treinador
int move_treinador(Treinador *tr, int x, int y) {
    tr->x = x;
    tr->y = y;
    return 0;
}

// Registra a captura: insere na lista e gasta 1 pokébola
int captura_treinador(Treinador *tr, Pokemon pk) {
    insere_lista(&tr->capturados, pk);
    tr->pokebolas--;
    return 0;
}

// Remove o Pokémon capturado da lista do treinador
int retira_treinador(Treinador *tr, int id) {
    remove_lista(&tr->capturados, id);
    return 0;
}

// Exibe informações de localização e recursos do treinador
int imprime_treinador(Treinador *tr) {
    printf("Treinador(a) %s: posição (%d,%d) | Pokébolas: %d\n", tr->nome, tr->x, tr->y, tr->pokebolas);
    return 0;
}

// Calcula a distância dos dois treinadores até o Pokémon alvo
Treinador *calculo_distancia(Treinador *tr, Treinador *tr2, Pokemon *pk, double *dist1, double *dist2) {
    // Fórmula: sqrt((x1 - x2)^2 + (y1 - y2)^2)
    *dist1 = sqrt(pow(tr->x - get_x(pk), 2.0) + pow(tr->y - get_y(pk), 2.0));
    *dist2 = sqrt(pow(tr2->x - get_x(pk), 2.0) + pow(tr2->y - get_y(pk), 2.0));

    // Retorna o treinador que estiver mais próximo
    if (*dist1 < *dist2) {
        return tr;
    }
    else if (*dist2 < *dist1) {
        return tr2;
    }
    else {
        // Critério de desempate: treinador com menor idt
        if (tr->idt < tr2->idt) {
            return tr;
        }
        else {
            return tr2;
        }
    }
}