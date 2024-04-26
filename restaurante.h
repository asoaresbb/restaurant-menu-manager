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

void adicionarPrato(Prato *, int *, Prato);
void removerPrato(Prato *, int, int *);
void atualizarPrato(Prato *listaPratos, int numPratos, int indice, Prato prato);

#endif