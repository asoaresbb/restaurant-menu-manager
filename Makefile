build:
	gcc -Wall main.c restaurante.c -o main.exe

run: build
	./main.exe

test:
	gcc -Wall restaurante.c test_restaurante.c -o test_restaurante.exe
	./test_restaurante.exe
