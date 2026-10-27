#ifndef POKEMON_H
#define POKEMON_H

// Estrutura que representa um Pokémon
typedef struct {
    int id;             // Identificador único do Pokémon na execução
    int numero_pokedex; // Número correspondente na Pokédex
    char nome[50];      // Nome do Pokémon
    char tipo[50];      // Tipo (ex: Fogo, Água, etc.)
    int pt_poder;       // Pontos de poder do pokemon
    int energia_gasta;  // Energia gasta pelo PokeMonitor
} Pokemon;

// Atribui os valores aos campos do Pokémon
int set(Pokemon *pk, int id, int numero, char *name, char *type, int pt_poder, int energia_gasta);

// Funções Getters para acessar as propriedades do Pokémon
int get_id(Pokemon *pk);
int get_numeropokedex(Pokemon *pk);
void get_nome(Pokemon *pk, char *name);
void get_tipo(Pokemon *pk, char *type);
int get_pt_poder(Pokemon *pk);
int get_energia_gasta(Pokemon *pk);


// Imprime informações básicas sobre o Pokémon
void imprime_pokemon(Pokemon *pk);

#endif