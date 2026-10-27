# Knapsack Problem - TP2 de Análise e Estrutura de Dados

Repositório dedicado à implementação em Linguagem C do Trabalho Prático 2 (TP2) da disciplina de Análise e Estrutura de Dados. O projeto resolve o Problema da Mochila Exponencial aplicado a um contexto de seleção e gerenciamento de equipes de Pokémon.

## Sobre o Projeto
O programa lê um conjunto de dados de um arquivo de entrada, carrega as informações utilizando Tipos Abstratos de Dados (TADs) modularizados e aplica um algoritmo recursivo de força bruta pura (explorando exaustivamente todas as combinações possíveis) para encontrar a equipe ideal dentro de um limite restrito de energia. Ao final, a equipe vencedora é distribuída de forma alternada entre dois treinadores.

## Estrutura de Pastas
O projeto segue uma arquitetura modularizada organizada da seguinte forma:
- **'src/'**: Contém todos os códigos-fonte em C ('main.c', 'algoritmos.c', 'pokemon.c', 'pokelista.c', 'treinador.c').
- **'include/'**: Contém os arquivos de cabeçalho ('.h') correspondentes aos TADs e algoritmos.
- **'bin/'**: Diretório de destino para os binários compilados.

## Como Compilar e Executar
O projeto conta com um Makefile automatizado para facilitar a compilação e execução.
Antes de tentar compilar ou rodar o programa, tenha o arquivo teste salvo na pasta do projeto com o nome 'arquivo.txt'.

### No Linux:
Para compilar o programa, digite no terminal:
- **'make compile'**
Para executar o programa, repita o processo anterior no terminal, mas trocando 'compile' por 'run'

### No Windows:
Para compilar o programa, digite no terminal:
- **'mingw32-make compile'**
Para executar o programa, repita o processo anterior no terminal, mas trocando 'compile' por 'run'