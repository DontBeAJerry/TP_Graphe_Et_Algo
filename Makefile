all: main

main: main.o graphe_liste.o graphe_matrice.o
	gcc  graphe_liste.o graphe_matrice.o main.o -o main -lm

graphe_liste.o: graphe_liste.h graphe_liste.c
	gcc -c graphe_liste.c -o graphe_liste.o -Wall -extra -O2

graphe_matrice.o: graphe_matrice.h graphe_matrice.c
	gcc -c graphe_matrice.c -o graphe_matrice.o -Wall -Wextra -O2

main.o: graphe_matrice.h graphe_liste.h main.c
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
