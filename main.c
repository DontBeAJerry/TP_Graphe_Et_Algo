#include <stdio.h>
#include "graphe_liste.h"
#include "utils.h"


LISTE generationFixe();
LISTE generationAlea();



int main() {

    LISTE l;

    int choixGraphe = 0;
    int choixAlgo = 0;
    int n = 0;
    int m = 0;

    printf("\nPour des raisons évidentes liées à l'aléatoire, les algorithmes utiliseront des graphes préconstruits\n\n");
    printf("\t1/ Génération d'un graphe aléatoire\n");
    printf("\t2/ Génération d'un graphe fixe de 5 sommets et de 10 arrêtes\n");
    printf("\t3/ Quitter\n");
    printf("Choix : ");
    scanf("%d", &choixGraphe);

    while(choixGraphe != 9) {
        switch (choixGraphe) {
            case 1 :
                l = generationAlea();
                afficher_LISTE(l);
                break;
            case 2 :
                l = generationFixe();
                printf("\n");
                printf("\t1/ BellmanFord\n");
                printf("\t2/ Dijkstra\n");
                printf("\t9/ Quitter\n");
                printf("Choix : ");
                scanf("%d", &choixAlgo);

                while(choixAlgo != 9) {
                    switch (choixAlgo) {
                        case 1 :
                            printf("La source du graphe est le sommet 0\n");
                            afficher_LISTE(l);
                            bellmanFord(l, 0);
                            break;
                        case 2 :
                            printf("La source du graphe est le sommet 0\n");
                            dijkstra_fixe(l, 0);
                            break;
                        default:
                            printf("Le choix n\'existe pas, veuillez relancer le programme.");
                            break;
                    }
                }
                break;
            default:
                printf("Le choix n\'existe pas, veuillez relancer le programme.");
                break;
        }

    }

    return 0;
}

/*
 * Permet de tester rapidement une liste fixe
 * @param n nombre de sommets
 * @param m nombre d'arrêtes
 */
LISTE generationFixe(){
    int n = 9;
    int m = 27;

    LISTE l = reservation_memoire_LISTE(n);

    /*int M[5][5] = { {0,6,7,0,0},
                    {0,0,8,5,-4},
                    {0,0,0,-3,9},
                    {0,-2,0,0,0},
                    {2,0,0,7,0}};
    */

    int M[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };




    for(int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            if(M[i][j] != 0){
                l = add_arete(&l, i, j, M[i][j]);
            }
        }
    }
    l.n = n;
    l.m = m;

    //Affichage de la matrice d'adjacence
    for(unsigned int i = 0; i<n ; i++) {
        for (unsigned int j = 0; j < n; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    return l;
}

LISTE generationAlea() {
    int n, m = 0;
    printf("Veuillez choisir le nombre de sommet S pour le graphe :");
    if (scanf("%d", &n)==1)
        do {
            printf("Veuillez choisir le nombre d'arrete A pour le graphe (A <= %d) : ", (n*(n-1)) );
            if(scanf("%d", &m)==1){
                if ( m > (n*(n-1))){
                    printf("Votre nombre de sommet n\'est pas valide. Veuillez recommencez.\n");
                }
            }
        }while(m > (n*(n-1)));

    return generationAleat(n, m);
}
