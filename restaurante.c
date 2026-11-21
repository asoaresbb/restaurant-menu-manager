#include <string.h>
#include <stdlib.h>
#include "restaurante.h"

Cardapio *criarCardapio()
{
    // calloc preenche a memória a zeros: o cardápio começa com quantidade 0.
    // Com malloc, a quantidade ficava com o lixo que estivesse na memória.
    return (Cardapio *)calloc(1, sizeof(Cardapio));
}

void adicionarPrato(Cardapio *cardapio, Prato pratoNovo)
{
    strcpy(cardapio->pratos[cardapio->quantidade].nome, pratoNovo.nome);
    strcpy(cardapio->pratos[cardapio->quantidade].descricao, pratoNovo.descricao);
    strcpy(cardapio->pratos[cardapio->quantidade].tipo, pratoNovo.tipo);
    cardapio->pratos[cardapio->quantidade].preco = pratoNovo.preco;
    cardapio->quantidade++; // Incrementar o número de pratos na lista
}

void removerPrato(Cardapio *cardapio, int indicePratoARemover)
{
    cardapio->pratos[indicePratoARemover] = cardapio->pratos[cardapio->quantidade - 1];
    cardapio->quantidade--; // Atualizar o número de pratos na lista
}

void atualizarPrato(Cardapio *cardapio, int indice, Prato prato)
{
    Prato *pratoAEditar = &cardapio->pratos[indice];
    strcpy(pratoAEditar->nome, prato.nome);
    strcpy(pratoAEditar->descricao, prato.descricao);
    strcpy(pratoAEditar->tipo, prato.tipo);
    pratoAEditar->preco = prato.preco;
}
