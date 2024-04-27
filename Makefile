build:
	gcc -Wall main.c restaurante.c -o main

test: build
	bats --tap tests