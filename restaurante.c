#include <string.h>
#include "restaurante.h"

void adicionarPrato(Prato *listaPratos, int *numPratos, Prato pratoNovo)
{
    strcpy(listaPratos[*numPratos].nome, pratoNovo.nome);
    strcpy(listaPratos[*numPratos].descricao, pratoNovo.descricao);
    strcpy(listaPratos[*numPratos].tipo, pratoNovo.tipo);
    listaPratos[*numPratos].preco = pratoNovo.preco;
    (*numPratos)++; // Incrementar o número de pratos na lista
}

void removerPrato(Prato *listaPratos, int *numPratos, int indicePratoARemover)
{
    listaPratos[indicePratoARemover] = listaPratos[*numPratos - 1];
    (*numPratos)--; // Atualizar o número de pratos na lista
}

void atualizarPrato(Prato *listaPratos, int numPratos, int indice, Prato prato)
{
    Prato *pratoAEditar = &listaPratos[indice];
    strcpy(pratoAEditar->nome, prato.nome);
    strcpy(pratoAEditar->descricao, prato.descricao);
    strcpy(pratoAEditar->tipo, prato.tipo);
    pratoAEditar->preco = prato.preco;
}
