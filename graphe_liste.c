/* Maxime Fleury Corentin Hanon, L3 Informatique */

#include "graphe_liste.h"

/* reservation en memoire du tableau de n listes chainees, initialisees e des listes vides */
LISTE reservation_memoire_LISTE(unsigned int n)
{
    unsigned int i;
    LISTE g;

    /* allocation memoire d'un tableau de n listes chainees */
    g.n = n;
    g.L = (MAILLON **)calloc(n, sizeof(MAILLON *));
    assert(g.L != NULL);
    /* chaque liste chainee est initialement vide */
    for(i=0; i<n; i++)
        g.L[i] = NULL;
    return g;
}

/* liberation memoire de la liste chainee passee en argument */
void liberation_liste(MAILLON **l)
{
    MAILLON *courant;
    while(*l != NULL) {
        courant = *l;
        *l = (*l)->suivant;
        free(courant);
    }
    *l = NULL;
}

/* liberation memoire du graphe : appel d'une procedure de liberation de chacune des n listes chainees, puis
   liberation du tableau */
void liberation_LISTE(LISTE g)
{
    unsigned int i;

    assert(g.L != NULL);
    for(i=0; i<g.n; i++)
        liberation_liste(&g.L[i]);
    free(g.L);
}

/* ajout de l'arete (i,j) dans le graphe donne */
LISTE add_arete(LISTE *g,unsigned int i,unsigned int j, int c)
{
    if (i < g->n)
    {
        MAILLON *new = (MAILLON*)malloc(sizeof(MAILLON));
        assert (new != NULL);
        new->s = j;
        new->c = c;
        new->suivant = g->L[i];
        g->L[i] = new;
    }
    else
    {
        printf("\nImpossible d'inserer l'élément\n");
    }
    return *g;
}

/* suppression de l'arete (i,j) dans le graphe donne */
void drop_arete(LISTE *g,unsigned int i,unsigned int j)
{
    i--;
    if (i < g->n)
    {
        unsigned int cpt = 0;
        MAILLON *precedentTemp = (MAILLON*)malloc(sizeof(MAILLON));
        MAILLON *tmp = (MAILLON*) malloc(sizeof(MAILLON));
        tmp = g->L[i];
        precedentTemp = g->L[i];
        while(tmp->s != j && tmp->suivant != NULL){
            if(cpt>0){
                precedentTemp = precedentTemp->suivant;
            }
            tmp = tmp->suivant;
            cpt++;
        }
        if(cpt==0 && tmp->s == j){
            g->L[i] = tmp->suivant;
            //printf("Element en tete\n ");
            free(tmp);
        }
        else  if(cpt>0 && tmp->s == j && tmp->suivant != NULL){
            precedentTemp->suivant = precedentTemp->suivant->suivant;
            //printf("Milieu de liste\n");
            free(tmp);
        }
        else if(tmp->s == j && tmp->suivant == NULL){
            tmp = NULL;
            precedentTemp->suivant = NULL;
            free(tmp);
            //printf("Fin de liste\n");
        }
        printf("Element suprimé");
    }
    else
        printf("\nL'élément n'existe pas\n");
}

/* affichage du graphe represente par ses listes d'adjacence */
void afficher_LISTE(LISTE g)
{
    printf("\n");
    for (unsigned int i = 0 ; i < g.n ; i++)
    {
        afficher_liste(g.L[i] , i);
        printf ("\n");
    }
}

void afficher_liste(MAILLON* l , unsigned int i)
{
    if (!l)
        printf ("%d : " , i);
    else
    {
        afficher_liste(l->suivant , i);
        printf("(%d , %d) // ", l->s , l->c);
    }
}

