#include <stdio.h>
#include <string.h>
#include "restaurante.h"

void limparBufferEntrada()
{
    while ((getchar()) != '\n')
        ; // Limpar o buffer de entrada
}

void trataAdicionarPrato(Prato *listaPratos, int *numPratos);

void removerPrato(Prato *listaPratos, int *numPratos);

void imprimirListaPratos(Prato *listaPratos, int numPratos);

void editarPrato(Prato *listaPratos, int numPratos);

// void pesquisarPrato(listaPratos, numPratos);
// void gerarRelatorios(listaPratos, numPratos);
void registarPedido(Prato *listaPratos, int numPratos);

void atribuirPedidoMesa();

void controlarEstadoPedidos();

int main()
{
    Prato listaPratos[100]; // Lista de pratos
    int numPratos = 0;      // Número atual de pratos na lista

    // Adicionando pratos manualmente (substituir por CSV)
    Prato novoPrato1 = {"Picanha", "Suculenta picanha grelhada", "Carne", 35.50};
    Prato novoPrato2 = {"Salmao", "Salmao fresco grelhado", "Peixe", 25.99};

    listaPratos[numPratos++] = novoPrato1;
    listaPratos[numPratos++] = novoPrato2;

    int opcao;
    while (1)
    {
        // Exibir opções do menu
        printf("\nMenu:\n");
        printf("1 - Adicionar prato\n");
        printf("2 - Remover prato\n");
        printf("3 - Editar prato\n");
        printf("4 - Pesquisar prato\n");
        printf("5 - Imprimir a lista de pratos\n");
        printf("6 - Registar pedido\n");
        printf("7 - Atribuir pedido a mesa\n");
        printf("8 - Controlar estado dos pedidos\n");
        printf("9 - Gerar relatorios\n");
        printf("0 - Sair do programa\n");
        printf("Escolha uma opcao:\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            trataAdicionarPrato(listaPratos, &numPratos);
            break;
        case 2:
            removerPrato(listaPratos, &numPratos);
            break;
        case 3:
            editarPrato(listaPratos, numPratos);
            break;
        case 4:
            // pesquisarPrato(listaPratos, numPratos);
            break;
        case 5:
            imprimirListaPratos(listaPratos, numPratos);
            break;
        case 6:
            registarPedido(listaPratos, numPratos);
            break;
        case 7:
            atribuirPedidoMesa();
            break;
        case 8:
            controlarEstadoPedidos();
            break;
        case 9:
            // gerarRelatorios(listaPratos, numPratos);
            break;
        case 0:
            printf("A sair do programa...\n");
            return 0;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    }
    return 0;
}

void trataAdicionarPrato(Prato *listaPratos, int *numPratos)
{
    Prato pratoNovo;
    printf("Digite o nome do prato: ");
    scanf(" %49[^\n]", pratoNovo.nome);
    printf("Digite a descricao do prato: ");
    scanf(" %99[^\n]", pratoNovo.descricao);
    printf("Digite o tipo do prato: ");
    scanf(" %19[^\n]", pratoNovo.tipo);
    printf("Digite o preco do prato: ");
    scanf("%f", &pratoNovo.preco);
    adicionarPrato(listaPratos, numPratos, pratoNovo);
    printf("✅");
}

void removerPrato(Prato *listaPratos, int *numPratos)
{
    char nomeParaRemover[50];
    limparBufferEntrada();
    printf("Digite o nome do prato que deseja remover:");
    fgets(nomeParaRemover, sizeof(nomeParaRemover), stdin);

    // Remover o caractere de nova linha (\n) da entrada
    nomeParaRemover[strcspn(nomeParaRemover, "\n")] = '\0';

    // Remover o prato da lista se for encontrado
    for (int i = 0; i < *numPratos; i++)
    {
        if (strcmp(listaPratos[i].nome, nomeParaRemover) == 0)
        {
            // Deslocar os pratos restantes para preencher o espaço do prato removido
            listaPratos[i] = listaPratos[*numPratos - 1];
            (*numPratos)--; // Atualizar o número de pratos na lista
            printf("Prato removido com sucesso!\n");
            return;
        }
    }

    // Se o prato não for encontrado na lista
    printf("O prato '%s' nao foi encontrado na lista.\n", nomeParaRemover);
}

void imprimirListaPratos(Prato *listaPratos, int numPratos)
{
    if (numPratos == 0)
    {
        printf("A lista de pratos esta vazia.\n");
        return;
    }

    for (int i = 0; i < numPratos; i++)
    {
        printf("Prato %d:\n", i + 1);
        printf("Nome: %s\n", listaPratos[i].nome);
        printf("Descricao: %s\n", listaPratos[i].descricao);
        printf("Tipo: %s\n", listaPratos[i].tipo);
        printf("Preco: %.2f\n", listaPratos[i].preco);
        printf("\n");
    }
}

void editarPrato(Prato *listaPratos, int numPratos)
{
    for (int i = 0; i < numPratos; ++i)
    {
        printf("Prato %d: %s\n", i + 1, listaPratos[i].nome);
    }

    printf("Qual o numero do prato quer editar? ");
    int indicePratoAEditar = 0;
    scanf("%d", &indicePratoAEditar);
    indicePratoAEditar--;

    if (indicePratoAEditar < 0 || indicePratoAEditar >= numPratos)
    {
        printf("O prato escolhido nao existe.\n");
        return;
    }
    limparBufferEntrada();

    Prato *pratoAEditar = &listaPratos[indicePratoAEditar];
    char textoLido[50];

    printf("Digite nome do prato (enter para manter %s): ", pratoAEditar->nome);
    fgets(textoLido, sizeof(textoLido), stdin);
    textoLido[strcspn(textoLido, "\n")] = '\0';
    if (strlen(textoLido) > 0)
        strcpy(pratoAEditar->nome, textoLido);

    printf("Digite a nova descricao do prato: ");
    scanf(" %99[^\n]", pratoAEditar->descricao);

    printf("Digite o tipo do prato: ");
    scanf(" %19[^\n]", pratoAEditar->tipo);

    printf("Digite o novo preco do prato: ");
    scanf(" %f", &pratoAEditar->preco);
}

// void pesquisarPrato(listaPratos, numPratos) {
// pedir texto de pesquisa
// percorrer listaPRatos
// em cada posicao, ver se faz match num dos campos
// se sim, imprimi-lo
//}

// void gerarRelatorios(listaPratos, numPratos);

void registarPedido(Prato *listaPratos, int numPratos)
{
    // Implementar a função para registrar um pedido (ainda não implementada)
}

void atribuirPedidoMesa()
{
    // Implementar a função para atribuir um pedido a uma mesa (ainda não implementada)
}

void controlarEstadoPedidos()
{
    // Implementar a função para controlar o estado dos pedidos (ainda não implementada)
}
