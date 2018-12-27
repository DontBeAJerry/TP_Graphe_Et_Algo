#include <stdio.h>
#include "graphe_liste.h"
#include "utils.h"

LISTE generationFixe(int n, int m);

int main() {

    unsigned int n = 0;
    unsigned int m = 0;

    /*
    printf("Veuillez choisir le nombre de sommet S pour le graphe.");
    if (scanf("%d", &n)==1)
    do {
        printf("Veuillez choisir le nombre d'arrete A pour le graphe (A <= %d)", (n*(n-1)) );
        if(scanf("%d", &m)==1){
            if ( m > (n*(n-1))){
                printf("Votre nombre de sommet n\'est pas valide. Veuillez recommencez.");
            }
        }
    }while(m > (n*(n-1)));

    */
    LISTE l;
    //l = generationAleat(5, 10);
    l = generationFixe(5,10);
    afficher_LISTE(l);

    bellmanFord(l, 0);

    return 0;
}

//Permet de tester rapidement une liste fixe
LISTE generationFixe(int n, int m){
    LISTE l = reservation_memoire_LISTE(n);
    int M[5][5] = { {0,6,7,0,0},
                    {0,0,8,5,-4},
                    {0,0,0,-3,9},
                    {0,-2,0,0,0},
                    {2,0,0,7,0}};

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
