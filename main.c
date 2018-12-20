#include <stdio.h>
#include "graphe_liste.h"
#include "utils.h"

int main() {

    unsigned int n = 0;
    unsigned int m = 0;

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


    LISTE l;

    l = generationAleat(n, m);
    afficher_LISTE(l);
    return 0;
}
