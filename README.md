# Restaurant Menu Manager in C

A command-line application for managing a restaurant's menu: each dish has a name, description, type and price. The interface is in Portuguese.

## Features

- Add, remove, edit and list dishes
- A menu of up to 100 dishes, in a module separate from the interface
- Unit tests for the menu module

## Running

Requires `gcc` and `make`.

```sh
make run    # compiles and opens the menu
make test   # unit tests
```

## Structure

| File | What it does |
| --- | --- |
| `restaurante.c/.h` | The menu: create it, and add, remove and update dishes |
| `main.c` | Menu and user interaction |
| `test_restaurante.c` | Unit tests |

## Context

Course project for Programming Lab (Laboratório de Programação), Universidade Aberta, April 2024.

Built through pair programming with a mentor.
