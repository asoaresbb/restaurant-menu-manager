#include "restaurante.h"
#include <assert.h>
#include <string.h>

void assertStrEqual(char *expected, char *actual)
{
    assert(strcmp(expected, actual) == 0);
}

void test_adicionar()
{
    Prato listaPratos[100];
    int numPratos = 0;
    Prato prato1 = {"Picanha", "Suculenta picanha grelhada", "Carne", 35.50};

    adicionarPrato(listaPratos, &numPratos, prato1);

    assert(numPratos == 1);
    assertStrEqual(listaPratos[0].nome, "Picanha");
    assertStrEqual(listaPratos[0].descricao, "Suculenta picanha grelhada");
    assertStrEqual(listaPratos[0].tipo, "Carne");
    assert(listaPratos[0].preco == 35.50f);
}

void test_atualizar_prato()
{
    Prato listaPratos[100];
    int numPratos = 0;
    Prato prato1 = {"Picanha", "Suculenta picanha grelhada", "Carne", 35.50};
    adicionarPrato(listaPratos, &numPratos, prato1);
    Prato pratoSubstituto = {"dourada", "dourada grelhada", "Peixe", 10.0};

    atualizarPrato(listaPratos, numPratos, 0, pratoSubstituto);
    assert(numPratos == 1);
    assertStrEqual(listaPratos[0].nome, "dourada");
    assertStrEqual(listaPratos[0].descricao, "dourada grelhada");
    assertStrEqual(listaPratos[0].tipo, "Peixe");
    assert(listaPratos[0].preco == 10.0f);
}

int main()
{
    test_adicionar();
    test_atualizar_prato();
}
