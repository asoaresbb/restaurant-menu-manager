#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <stdbool.h>

#define MAX_PRATOS 100

// Definição da estrutura para representar um prato
typedef struct
{
    char nome[50];
    char descricao[100];
    char tipo[20];
    float preco;
} Prato;

typedef struct
{
    Prato pratos[MAX_PRATOS];
    int quantidade;
} Cardapio;

Cardapio *criarCardapio();
bool adicionarPrato(Cardapio *cardapio, Prato pratoNovo); // false se o cardápio estiver cheio
void removerPrato(Cardapio *cardapio, int indice);
void atualizarPrato(Cardapio *cardapio, int indice, Prato prato);

#endif