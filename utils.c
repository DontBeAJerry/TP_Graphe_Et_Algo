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
    unsigned int comptArrete = 0;
    int M[n][n];

    if(m<=(n*(n-1))){
        //Initialisation de la matrice
        for(unsigned int i = 0; i<n ; i++){
            for(unsigned int j = 0; j<n; j++){
                M[i][j] = 0;
            }
        }

        //Création d'une matrice d'adjacence aléatoire
        srand(time(NULL));
        while (comptArrete < m){
            unsigned int i = (unsigned int) (rand() / (double) RAND_MAX * (n));
            unsigned int j = (unsigned int) (rand() / (double) RAND_MAX * (n));
            if(M[i][j] == 0){
                unsigned int aleatoire = (unsigned int) (rand() / (double) RAND_MAX * (101 - 1) + 1);
                if(aleatoire > 50){
                    M[i][j] = (int) (rand()%11 -5 );
                    L = add_arete(&L, i, j, M[i][j]);
                    comptArrete++;
                }
            }
        }
    }


        //Affichage de la matrice d'adjacence
        for(unsigned int i = 0; i<n ; i++) {
            for (unsigned int j = 0; j < n; j++) {
                printf("%d ", M[i][j]);
            }
            printf("\n");
        }



    return L;
}

//Comparaison en tre deux maillons
unsigned int egale(MAILLON m1 , MAILLON m2){
    return m1.s==m2.s;
}

/*
void bellmanFord(){
    for(int i=0; i<l.n; i++){
        break;
    }

}*/

int bellmanFord(LISTE l, int i, int s){





    return 0;
}