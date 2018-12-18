/* Maxime Fleury Corentin Hanon, L3 Informatique */

#include "graphe_matrice.h"

/* reservation en memoire de l'espace necessaire pour un graphe contenant n sommets */
MATRICE reservation_MATRICE(int n)
{
    int i;
    MATRICE g;

  /* representation par matrice d'adjacence : matrice carree n * n */
    g.n = n;
    g.M = (int **)calloc(n, sizeof(int *));
    assert(g.M != NULL);
    for(i=0; i<n; i++) {
        g.M[i] = (int *)calloc(n, sizeof(int));
        assert(g.M[i] != NULL);
    }
    return g;
}

/* liberation de la memoire occupee par un graphe donne */
void liberation_MATRICE(MATRICE g)
{
    int i;

    for(i=0; i<g.n; i++)
        free(g.M[i]);
    free(g.M);
}

/* ajout de l'arc (i,j) dans le graphe g */
void add_arc(MATRICE *g, int i, int j)
{
    assert(i< g->n && j < g->n);
    if(!g->M[i][j]){
        g->M[i][j] = 1;
    }
}

/* suppression de l'arc (i,j) dans le graphe g */
void drop_arc(MATRICE *g, int i, int j)
{
     assert(i< g->n && j < g->n);
    if(g->M[i][j]){
       g->M[i][j]=0;
    }
}

/* affichage du graphe donne */
void affiche_MATRICE(MATRICE g)
{
    for(int j=0;j<g.n;j++){
        for(int i=0;i<g.n;i++){
            printf("%d  ",g.M[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

/* fonction qui retourne true si j est un successeur direct de i, false sinon */
bool est_successeur(MATRICE g, int i, int j)
{

    assert(i< g.n && j < g.n);
    if(g.M[i][j] == 1)
        return true;
    else return false;


}

/* convertit un graphe donne par sa matrice d'adjacence en un graphe represente par matrice d'incidence */
MATRICE_INC conversion_MATRICE(MATRICE g)
{
    MATRICE_INC G;

    return G;
}
