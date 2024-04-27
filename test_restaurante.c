#include "restaurante.h"
#include <assert.h>
#include <string.h>

void assertStrEqual(char *expected, char *actual)
{
    assert(strcmp(expected, actual) == 0);
}

void test_adicionar_prato()
{
    Cardapio *cardapio = criarCardapio();
    Prato prato1 = {"Picanha", "Suculenta picanha grelhada", "Carne", 35.50};

    adicionarPrato(cardapio, prato1);

    assert(cardapio->quantidade == 1);
    assertStrEqual(cardapio->pratos[0].nome, "Picanha");
    assertStrEqual(cardapio->pratos[0].descricao, "Suculenta picanha grelhada");
    assertStrEqual(cardapio->pratos[0].tipo, "Carne");
    assert(cardapio->pratos[0].preco == 35.50f);
}

void test_atualizar_prato()
{
    Cardapio *cardapio = criarCardapio();
    Prato prato1 = {"Picanha", "Suculenta picanha grelhada", "Carne", 35.50};
    adicionarPrato(cardapio, prato1);
    Prato pratoSubstituto = {"dourada", "dourada grelhada", "Peixe", 10.0};

    atualizarPrato(cardapio, 0, pratoSubstituto);
    assert(cardapio->quantidade == 1);
    assertStrEqual(cardapio->pratos[0].nome, "dourada");
    assertStrEqual(cardapio->pratos[0].descricao, "dourada grelhada");
    assertStrEqual(cardapio->pratos[0].tipo, "Peixe");
    assert(cardapio->pratos[0].preco == 10.0f);
}

void test_remover_prato()
{
    Cardapio *cardapio = criarCardapio();
    Prato prato1 = {"Picanha", "Suculenta picanha grelhada", "Carne", 35.50};
    adicionarPrato(cardapio, prato1);

    removerPrato(cardapio, 0);

    assert(cardapio->quantidade == 0);
}

int main()
{
    test_adicionar_prato();
    test_atualizar_prato();
    test_remover_prato();
}
