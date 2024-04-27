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

void trataAdicionarPrato(Cardapio *cardapio);

char pedirOpcaoMenu();

void trataRemoverPrato(Cardapio *cardapio);

void imprimirListaPratos(Cardapio *cardapio);

void trataEditarPrato(Cardapio *cardapio);

int main()
{
    Cardapio *cardapio = criarCardapio();
    // Adicionando pratos manualmente (substituir por CSV)
    Prato novoPrato1 = {"Picanha", "Suculenta picanha grelhada", "Carne", 35.50};
    Prato novoPrato2 = {"Salmao", "Salmao fresco grelhado", "Peixe", 25.99};

    adicionarPrato(cardapio, novoPrato1);
    adicionarPrato(cardapio, novoPrato2);

    while (1)
    {
        switch (pedirOpcaoMenu())
        {
        case '+':
        case 'a':
            printf("\n");
            trataAdicionarPrato(cardapio);
            break;
        case '-':
        case 'r':
            printf("\n");
            trataRemoverPrato(cardapio);
            break;
        case 'e':
            printf("\n");
            trataEditarPrato(cardapio);
            break;
        case 'p':
            printf("\n");
            // pesquisarPrato(cardapio);
            break;
        case 'l':
            printf("\n");
            imprimirListaPratos(cardapio);
            break;
        case 's':
        case 'q':
            printf("\nA sair do programa...\n");
            return 0;
        default:
            printf("\nOpção inválida. Tente novamente.\n");
            break;
        }
        limparBufferEntrada();
    }

    return 0;
}

char pedirOpcaoMenu()
{
    printf("🍽️ 🍽️ 🍽️  Menu 🍽️ 🍽️ 🍽️ \n");
    printf("   +  Adicionar prato\n");
    printf("   -  Remover prato\n");
    printf("   e  Editar prato\n");
    printf("   p  Pesquisar prato\n");
    printf("   l  Imprimir a lista de pratos\n");
    printf("   s  Sair do programa\n");
    printf("👉 Escolha uma opção: ");
    char opcao[10];
    scanf("%s", opcao);
    return tolower(opcao[0]);
}

void trataAdicionarPrato(Cardapio *cardapio)
{
    limparBufferEntrada();
    Prato pratoNovo;
    printf("👉 Digite o nome do prato: ");
    scanf(" %49[^\n]", pratoNovo.nome);
    printf("👉 Digite a descricao do prato: ");
    scanf(" %99[^\n]", pratoNovo.descricao);
    printf("👉 Digite o tipo do prato: ");
    scanf(" %19[^\n]", pratoNovo.tipo);
    printf("👉 Digite o preco do prato: ");
    scanf("%f", &pratoNovo.preco);
    adicionarPrato(cardapio, pratoNovo);
    printf("✅");
}

void trataRemoverPrato(Cardapio *cardapio)
{
    imprimirListaPratos(cardapio);
    printf("👉 Selecione numero do prato a remover:");

    int indicePratoARemover = 0;
    scanf("%d", &indicePratoARemover);
    indicePratoARemover--;
    if (indicePratoARemover < 0 || indicePratoARemover > cardapio->quantidade)
    {
        printf("O prato escolhido nao existe.\n");
        return;
    }

    removerPrato(cardapio, indicePratoARemover);
    printf("Prato removido com sucesso!\n");
    return;
}

void imprimirListaPratos(Cardapio *cardapio)
{
    if (cardapio->quantidade == 0)
    {
        printf("A lista de pratos está vazia.\n");
        return;
    }
    for (int i = 0; i < cardapio->quantidade; i++)
    {
        printf("%d: %s (%s) - %.2f€\n", i + 1, cardapio->pratos[i].nome, cardapio->pratos[i].tipo, cardapio->pratos[i].preco);
        printf("   %s\n", cardapio->pratos[i].descricao);
    }
    printf("\n");
}

void trataEditarPrato(Cardapio *cardapio)
{
    imprimirListaPratos(cardapio);
    printf("👉 Que prato quer editar? ");
    int indicePratoEditado = 0;
    scanf("%d", &indicePratoEditado);
    indicePratoEditado--;
    limparBufferEntrada();
    if (indicePratoEditado < 0 || indicePratoEditado > cardapio->quantidade)
    {
        printf("O prato escolhido nao existe.\n");
        return;
    }

    Prato pratoEditado = cardapio->pratos[indicePratoEditado];
    char textoLido[50];

    printf("👉 Digite nome do prato (enter para manter %s):", pratoEditado.nome);
    fgets(textoLido, sizeof(textoLido), stdin);
    textoLido[strcspn(textoLido, "\n")] = '\0';
    if (strlen(textoLido) > 0)
        strcpy(pratoEditado.nome, textoLido);

    printf("👉 Digite a nova descricao (enter para manter %s): ", pratoEditado.descricao);
    fgets(textoLido, sizeof(textoLido), stdin);
    textoLido[strcspn(textoLido, "\n")] = '\0';
    if (strlen(textoLido) > 0)
        strcpy(pratoEditado.descricao, textoLido);

    printf("👉 Digite o novo tipo (enter para manter %s): ", pratoEditado.tipo);
    fgets(textoLido, sizeof(textoLido), stdin);
    textoLido[strcspn(textoLido, "\n")] = '\0';
    if (strlen(textoLido) > 0)
        strcpy(pratoEditado.tipo, textoLido);

    printf("👉 Digite o novo preco (enter para manter %f): ", pratoEditado.preco);
    fgets(textoLido, sizeof(textoLido), stdin);
    textoLido[strcspn(textoLido, "\n")] = '\0';
    if (strlen(textoLido) > 0)
        pratoEditado.preco = atoi(textoLido);

    atualizarPrato(cardapio, indicePratoEditado, pratoEditado);
}
