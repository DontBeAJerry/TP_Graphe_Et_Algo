#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
                    //cout différent de 0
                    do {
                        M[i][j] = (int) (rand() % 11 - 5);
                    }while(M[i][j] == 0);
                    L = add_arete(&L, i, j, M[i][j]);
                    comptArrete++;
                }
            }
        }
    }
    L.n = n;
    L.m = m;

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
bool egale(MAILLON m1 , MAILLON m2){
    return m1.s==m2.s;
}



void bellmanFord(LISTE l, int s){
    int n = l.n;
    int m = l.m;
    int d[n];
    int absorbant = 0;
    MAILLON* tmp;


    /* Initialisation des distances à + l'infini
     * Distance source à 0
     */
    for (int i = 0; i < l.n; i++) {
        d[i] = INT_MAX;
    }
    d[s] = 0;

    //A faire n fois, n étant le nombre de sommet
    for(int j = 1; j<= n-1; j++) {
        //Parcours de tout les sommets et de leurs successeurs pour évaluer leur cout
        for (int i = 0; i < n; i++) {
            tmp = l.L[i];
            //Tant que le sommet à des successeurs
            while (tmp != NULL) {
                int source = i;
                int dest = tmp->s;
                int poids = tmp->c;

                //Ajout du cout pour le sommet indiqué
                if (d[source] + poids < d[dest]) {
                    d[dest] = d[source] + poids;
                }
                tmp = tmp->suivant;
            }

        }
    }

    for(int j = 1; j<= n-1; j++) {
        //Parcours de tout les sommets et de leurs successeurs pour évaluer leur cout
        for (int i = 0; i < n; i++) {
            tmp = l.L[i];
            while (tmp != NULL) {
                int source = s;
                int dest = tmp->s;
                int poids = tmp->c;

                if (d[source] + poids < d[dest]) {
                    absorbant = 1;
                }

                tmp = tmp->suivant;
            }
        }
    }



    if (absorbant == 0) {
        printf("Le graphe ne contient pas de circuit absorbant");
    }else{
        printf("Le graphe contient des circuits absorbants");
    }


    solution(d, n, s);



}

void solution(int dist[], int n, int s)
{
    // This function prints the final solution
    printf("\nSommet \tDistance depuis le sommet %d\n",s);

    for (int i = 0; i < n; ++i){
        printf("%d \t\t %d\n", i, dist[i]);
    }
}


