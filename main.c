#include <stdio.h>
#include "graphe_liste.h"
#include "graphe_matrice.h"
#include "utils.h"

int main() {
    printf("Hello, World!\n");
    return 0;
}

/*
 * Génération d'une liste d'adjacence aléatoire
 * @param n nombre de sommets
 * @param m nombre d'arrêtes avec m <= n*(n-1)
 */
void generationAleat(int n, int m){
    if(m<=(n*(n-1))){
        int comptArrete = 0;
        int M[n][n];

        //Initialisation de la matrice
        for(unsigned int i = 0; i<n ; i++){
            for(unsigned int j = 0; j<n; j++){
                M[i][j] = 0;
            }
        }


        //Création d'une matrice d'adjacence aléatoire
        while (comptArrete < m){
            for(unsigned int i = 0; i<n ; i++){
                for(unsigned int j = 0; j<n; j++){
                    if(M[i][j] == 0){
                        //TODO Random
                        int rand = 0;
                        if(rand > 50){
                            M[i][j] = 1;
                            comptArrete++;
                        }
                    }
                }
            }
        }
    }
}


