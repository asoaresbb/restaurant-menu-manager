build:
	gcc -Wall main.c restaurante.c -o main.exe

test: build
	gcc -Wall restaurante.c test_restaurante.c -o test_restaurante.exe
	./test_restaurante.exe

	#bats --tap tests