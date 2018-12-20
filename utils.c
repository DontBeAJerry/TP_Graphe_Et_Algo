#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "utils.h"

/*
* Génération d'une liste d'adjacence aléatoire puis converti en liste
* @param n nombre de sommets
* @param m nombre d'arrêtes avec m <= n*(n-1)
*/
LISTE generationAleat(unsigned int n,unsigned int m){
    LISTE L = reservation_memoire_LISTE(n);

    if(m<=(n*(n-1))){
        unsigned int comptArrete = 0;
        int M[n][n];

        //Initialisation de la matrice
        for(unsigned int i = 0; i<n ; i++){
            for(unsigned int j = 0; j<n; j++){
                M[i][j] = 0;
            }
        }

        //Création d'une matrice d'adjacence aléatoire
        srand(time(NULL));
        while (comptArrete < m){
            for(unsigned int i = 0; i<n ; i++){
                for(unsigned int j = 0; j<n; j++){
                    if(M[i][j] == 0){
                        unsigned int aleatoire = (unsigned int) (rand() / (double) RAND_MAX * (101 - 1) + 1);
                            if(aleatoire > 50){
                            M[i][j] = 1;
                            comptArrete++;
                        }
                    }
                }
            }
        }
        for(unsigned int i = 0; i<n ; i++){
            for(unsigned int j = 0; j<n; j++){
                if(M[i][j] == 1){
                    L = add_arete(&L, i, j);
                }
            }
        }
    }
    return L;
}
