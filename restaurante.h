#ifndef RESTAURANTE_H
#define RESTAURANTE_H

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
    Prato pratos[100];
    int quantidade;
} Cardapio;

Cardapio *criarCardapio();
void adicionarPrato(Cardapio *cardapio, Prato pratoNovo);
void removerPrato(Cardapio *cardapio, int indice);
void atualizarPrato(Cardapio *cardapio, int indice, Prato prato);

#endif