all: main

main: main.o graphe_liste.o utils.o
	gcc graphe_liste.o utils.o main.o -o main -lm

graphe_liste.o: graphe_liste.h graphe_liste.c
	gcc -c graphe_liste.c -o graphe_liste.o -Wall -extra -O2

utils.o: utils.h graphe_liste.h utils.c
	gcc -c utils.c -o utils.o -Wall -Wextra -O2

main.o: utils.h graphe_liste.h main.c
	clear
	gcc -c main.c -o main.o -Wall -Wextra -O2

mrProper:
	clear
	rm *.o
	rm main

do:
	clear
	./main

clear:
	clear
