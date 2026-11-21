#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "restaurante.h"

void limparBufferEntrada()
{
    int caracter;
    // Pára também no fim do input (EOF), senão o ciclo nunca acabava
    while ((caracter = getchar()) != '\n' && caracter != EOF)
        ;
}

// Lê uma linha com no máximo tamanho - 1 caracteres, sem o '\n'.
// O que passar do limite é descartado, para não ser lido na pergunta seguinte.
void lerLinha(char *texto, int tamanho)
{
    if (fgets(texto, tamanho, stdin) == NULL)
    {
        texto[0] = '\0';
        return;
    }
    if (strchr(texto, '\n') == NULL)
        limparBufferEntrada();
    texto[strcspn(texto, "\n")] = '\0';
}

// Descarta o resto da linha depois de um scanf com limite, sem consumir o '\n'
void descartarRestoDaLinha()
{
    scanf("%*[^\n]");
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

    printf("\n🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️\n");
    printf("🍽️ 🍽️ 🍽️  Gestor de Restaurante  🍽️ 🍽️ 🍽️ \n");
    printf("🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️ 🍽️ \n\n");

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
            printf(" ℹ️ A sair do programa...\n");
            free(cardapio);
            return 0;
        default:
            printf(" ℹ️ Opção inválida. Tente novamente.\n");
        }
        limparBufferEntrada();
    }
    return 0;
}

char pedirOpcaoMenu()
{
    printf(" ❓ Escolha uma opção:\n");
    printf("   +  Adicionar prato\n");
    printf("   -  Remover prato\n");
    printf("   e  Editar prato\n");
    printf("   l  Imprimir a lista de pratos\n");
    printf("   p  Pesquisar prato\n");
    printf("   s  Sair do programa\n");
    char opcao[10];
    if (scanf("%9s", opcao) != 1) // Fim do input: sair, em vez de usar lixo como opção
        return 's';
    return tolower(opcao[0]);
}

void trataAdicionarPrato(Cardapio *cardapio)
{
    limparBufferEntrada();
    Prato pratoNovo;
    printf(" ❓ Digite o nome do prato: ");
    scanf(" %49[^\n]", pratoNovo.nome);
    descartarRestoDaLinha();
    printf(" ❓ Digite a descricao do prato: ");
    scanf(" %99[^\n]", pratoNovo.descricao);
    descartarRestoDaLinha();
    printf(" ❓ Digite o tipo do prato: ");
    scanf(" %19[^\n]", pratoNovo.tipo);
    descartarRestoDaLinha();
    printf(" ❓ Digite o preco do prato: ");
    scanf("%f", &pratoNovo.preco);
    if (!adicionarPrato(cardapio, pratoNovo))
    {
        printf(" ℹ️ O cardápio está cheio (máximo de %d pratos).\n", MAX_PRATOS);
        return;
    }
    printf(" ℹ️ O prato %s foi adicionado.\n", pratoNovo.nome);
    printf("\n");
}

void trataRemoverPrato(Cardapio *cardapio)
{
    imprimirListaPratos(cardapio);
    printf(" ❓ Selecione numero do prato a remover:");

    int indicePratoARemover = 0;
    scanf("%d", &indicePratoARemover);
    indicePratoARemover--;
    if (!removerPrato(cardapio, indicePratoARemover))
    {
        printf(" ℹ️ O prato escolhido nao existe.\n");
        return;
    }

    printf(" ℹ️ Prato removido com sucesso!\n");
    printf("\n");
    return;
}

void imprimirListaPratos(Cardapio *cardapio)
{
    if (cardapio->quantidade == 0)
    {
        printf(" ℹ️ A lista de pratos está vazia.\n");
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
    printf(" ❓ Que prato quer editar? ");
    int indicePratoEditado = 0;
    scanf("%d", &indicePratoEditado);
    indicePratoEditado--;
    limparBufferEntrada();
    if (indicePratoEditado < 0 || indicePratoEditado >= cardapio->quantidade)
    {
        printf(" ℹ️ O prato escolhido nao existe.\n");
        return;
    }

    Prato pratoEditado = cardapio->pratos[indicePratoEditado];
    // Cada leitura fica limitada ao tamanho do campo, para o strcpy não escrever fora dele
    char textoLido[sizeof(pratoEditado.descricao)];

    printf(" ❓ Digite nome do prato (enter para manter %s): ", pratoEditado.nome);
    lerLinha(textoLido, sizeof(pratoEditado.nome));
    if (strlen(textoLido) > 0) // Verifica se foi digitado algo antes do Enter
        strcpy(pratoEditado.nome, textoLido);

    printf(" ❓ Digite a nova descricao (enter para manter %s): ", pratoEditado.descricao);
    lerLinha(textoLido, sizeof(pratoEditado.descricao));
    if (strlen(textoLido) > 0)
        strcpy(pratoEditado.descricao, textoLido);

    printf(" ❓ Digite o novo tipo (enter para manter %s): ", pratoEditado.tipo);
    lerLinha(textoLido, sizeof(pratoEditado.tipo));
    if (strlen(textoLido) > 0)
        strcpy(pratoEditado.tipo, textoLido);

    printf(" ❓ Digite o novo preco (enter para manter %.2f): ", pratoEditado.preco);
    lerLinha(textoLido, sizeof(textoLido));
    if (strlen(textoLido) > 0)
        pratoEditado.preco = atof(textoLido);  // Converte para float

    atualizarPrato(cardapio, indicePratoEditado, pratoEditado);

    printf(" ℹ️ Prato atualizado com sucesso. (enter para voltar ao menu)\n");
}
