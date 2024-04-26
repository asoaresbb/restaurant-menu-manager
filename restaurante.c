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

void removerPrato(Prato *listaPratos, int indicePratoARemover, int *numPratos)
{
    listaPratos[indicePratoARemover] = listaPratos[*numPratos - 1];
    (*numPratos)--; // Atualizar o número de pratos na lista
}