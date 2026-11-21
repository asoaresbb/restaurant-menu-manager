#include <string.h>
#include <stdlib.h>
#include "restaurante.h"

Cardapio *criarCardapio()
{
    // calloc preenche a memória a zeros: o cardápio começa com quantidade 0.
    // Com malloc, a quantidade ficava com o lixo que estivesse na memória.
    return (Cardapio *)calloc(1, sizeof(Cardapio));
}

bool adicionarPrato(Cardapio *cardapio, Prato pratoNovo)
{
    if (cardapio->quantidade >= MAX_PRATOS)
        return false; // Não há espaço no array para mais pratos
    strcpy(cardapio->pratos[cardapio->quantidade].nome, pratoNovo.nome);
    strcpy(cardapio->pratos[cardapio->quantidade].descricao, pratoNovo.descricao);
    strcpy(cardapio->pratos[cardapio->quantidade].tipo, pratoNovo.tipo);
    cardapio->pratos[cardapio->quantidade].preco = pratoNovo.preco;
    cardapio->quantidade++; // Incrementar o número de pratos na lista
    return true;
}

// Os índices válidos vão de 0 a quantidade - 1
static bool indiceValido(Cardapio *cardapio, int indice)
{
    return indice >= 0 && indice < cardapio->quantidade;
}

bool removerPrato(Cardapio *cardapio, int indicePratoARemover)
{
    if (!indiceValido(cardapio, indicePratoARemover))
        return false;
    cardapio->pratos[indicePratoARemover] = cardapio->pratos[cardapio->quantidade - 1];
    cardapio->quantidade--; // Atualizar o número de pratos na lista
    return true;
}

bool atualizarPrato(Cardapio *cardapio, int indice, Prato prato)
{
    if (!indiceValido(cardapio, indice))
        return false;
    Prato *pratoAEditar = &cardapio->pratos[indice];
    strcpy(pratoAEditar->nome, prato.nome);
    strcpy(pratoAEditar->descricao, prato.descricao);
    strcpy(pratoAEditar->tipo, prato.tipo);
    pratoAEditar->preco = prato.preco;
    return true;
}
