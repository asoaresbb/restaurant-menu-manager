#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "restaurante.h"

void limparBufferEntrada()
{
    while ((getchar()) != '\n')
        ;
}

void trataAdicionarPrato(Prato *listaPratos, int *numPratos);

void trataRemoverPrato(Prato *listaPratos, int *numPratos);

void imprimirListaPratos(Prato *listaPratos, int numPratos);

void trataEditarPrato(Prato *listaPratos, int numPratos);

void imprimeListaCompacta(Prato *listaPratos, int numPratos);

int main()
{
    Prato listaPratos[100]; // Lista de pratos
    int numPratos = 0;      // Número atual de pratos na lista

    // Adicionando pratos manualmente (substituir por CSV)
    Prato novoPrato1 = {"Picanha", "Suculenta picanha grelhada", "Carne", 35.50};
    Prato novoPrato2 = {"Salmao", "Salmao fresco grelhado", "Peixe", 25.99};

    listaPratos[numPratos++] = novoPrato1;
    listaPratos[numPratos++] = novoPrato2;

    char opcao[10];
    while (1)
    {
        // Exibir opções do menu
        printf("🍛🍛 Menu 🍛🍛\n");
        printf(" +  Adicionar prato\n");
        printf(" -  Remover prato\n");
        printf(" e  Editar prato\n");
        printf(" p  Pesquisar prato\n");
        printf(" l  Imprimir a lista de pratos\n");
        printf(" s  Sair do programa\n");
        printf(" 👉 Escolha uma opção: ");

        scanf("%s", opcao);

        switch (tolower(opcao[0]))
        {
        case '+':
            printf("\n");
            trataAdicionarPrato(listaPratos, &numPratos);
            break;
        case '-':
            printf("\n");
            trataRemoverPrato(listaPratos, &numPratos);
            break;
        case 'e':
            printf("\n");
            trataEditarPrato(listaPratos, numPratos);
            break;
        case 'p':
            printf("\n");
            // pesquisarPrato(listaPratos, numPratos);
            break;
        case 'l':
            printf("\n");
            imprimirListaPratos(listaPratos, numPratos);
            break;
        case 's':
            printf("\nA sair do programa...\n");
            return 0;
        default:
            printf("\nOpcao %s invalida. Tente novamente.\n", opcao);
            limparBufferEntrada();
            break;
        }
    }

    return 0;
}

void trataAdicionarPrato(Prato *listaPratos, int *numPratos)
{
    Prato pratoNovo;
    printf(" 👉 Digite o nome do prato: ");
    scanf(" %49[^\n]", pratoNovo.nome);
    printf("Digite a descricao do prato: ");
    scanf(" %99[^\n]", pratoNovo.descricao);
    printf(" 👉 Digite o tipo do prato: ");
    scanf(" %19[^\n]", pratoNovo.tipo);
    printf(" 👉 Digite o preco do prato: ");
    scanf("%f", &pratoNovo.preco);
    adicionarPrato(listaPratos, numPratos, pratoNovo);
    printf("✅");
}

void trataRemoverPrato(Prato *listaPratos, int *numPratos)
{
    imprimeListaCompacta(listaPratos, *numPratos);
    printf(" 👉 Selecione numero do prato a remover:");

    int indicePratoARemover = 0;
    scanf("%d", &indicePratoARemover);
    indicePratoARemover--;
    if (indicePratoARemover < 0 || indicePratoARemover > *numPratos)
    {
        printf("O prato escolhido nao existe.\n");
        return;
    }

    removerPrato(listaPratos, indicePratoARemover, numPratos);
    printf("Prato removido com sucesso!\n");
    return;
}

void imprimirListaPratos(Prato *listaPratos, int numPratos)
{
    if (numPratos == 0)
    {
        printf("A lista de pratos está vazia.\n");
        return;
    }

    for (int i = 0; i < numPratos; i++)
    {
        printf("---- Prato %d ----\n", i + 1);
        printf("Nome: %s\n", listaPratos[i].nome);
        printf("Descricao: %s\n", listaPratos[i].descricao);
        printf("Tipo: %s\n", listaPratos[i].tipo);
        printf("Preco: %.2f\n", listaPratos[i].preco);
        printf("\n");
    }
}

void trataEditarPrato(Prato *listaPratos, int numPratos)
{
    imprimeListaCompacta(listaPratos, numPratos);

    printf(" 👉 Qual numero do prato quer editar? ");
    int indicePratoEditado = 0;
    scanf("%d", &indicePratoEditado);
    indicePratoEditado--;
    if (indicePratoEditado < 0 || indicePratoEditado > numPratos)
    {
        printf("O prato escolhido nao existe.\n");
        return;
    }

    Prato pratoEditado = listaPratos[indicePratoEditado];
    char textoLido[50];

    printf(" 👉 Digite nome do prato (enter para manter %s):", pratoEditado.nome);
    fgets(textoLido, sizeof(textoLido), stdin);
    textoLido[strcspn(textoLido, "\n")] = '\0';
    if (strlen(textoLido) > 0)
        strcpy(pratoEditado.nome, textoLido);

    printf(" 👉 Digite a nova descricao (enter para manter %s): ", pratoEditado.descricao);
    fgets(textoLido, sizeof(textoLido), stdin);
    textoLido[strcspn(textoLido, "\n")] = '\0';
    if (strlen(textoLido) > 0)
        strcpy(pratoEditado.descricao, textoLido);

    printf(" 👉 Digite o novo tipo (enter para manter %s): ", pratoEditado.tipo);
    fgets(textoLido, sizeof(textoLido), stdin);
    textoLido[strcspn(textoLido, "\n")] = '\0';
    if (strlen(textoLido) > 0)
        strcpy(pratoEditado.tipo, textoLido);

    printf(" 👉 Digite o novo preco (enter para manter %f): ", pratoEditado.preco);
    fgets(textoLido, sizeof(textoLido), stdin);
    textoLido[strcspn(textoLido, "\n")] = '\0';
    if (strlen(textoLido) > 0)
        pratoEditado.preco = atoi(textoLido);

    atualizarPrato(listaPratos, numPratos, indicePratoEditado, pratoEditado);
}

void imprimeListaCompacta(Prato *listaPratos, int numPratos)
{
    for (int i = 0; i < numPratos; ++i)
    {
        printf("Prato %d: %s\n", i + 1, listaPratos[i].nome);
    }
}
