# Gestor de Ementas em C

Aplicação de linha de comandos para gerir a ementa de um restaurante: cada prato tem nome, descrição, tipo e preço.

## Funcionalidades

- Adicionar, remover, editar e listar pratos
- Ementa com até 100 pratos, num módulo separado da interface
- Testes unitários do módulo da ementa

## Como correr

Requer `gcc` e `make`.

```sh
make run    # compila e abre o menu
make test   # testes unitários
```

## Estrutura

| Ficheiro | O que faz |
| --- | --- |
| `restaurante.c/.h` | A ementa: criar, adicionar, remover e atualizar pratos |
| `main.c` | Menu e interação com o utilizador |
| `test_restaurante.c` | Testes unitários |

## Contexto

Projeto da unidade curricular de Laboratório de Programação, Universidade Aberta, abril de 2024.

Desenvolvido em programação a pares com um mentor.
