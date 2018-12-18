/* Maxime Fleury Corentin Hanon, L3 Informatique */

#include "graphe_liste.h"

/* reservation en memoire du tableau de n listes chainees, initialisees e des listes vides */
LISTE reservation_memoire_LISTE(int n)
{
    int i;
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
    int i;

    assert(g.L != NULL);
    for(i=0; i<g.n; i++)
        liberation_liste(&g.L[i]);
    free(g.L);
}

/* ajout de l'arete (i,j) dans le graphe donne */
LISTE add_arete(LISTE *g, int i, int j)
{
    i--;
    if (i < g->n)
    {
        MAILLON *new = (MAILLON*)malloc(sizeof(MAILLON));
        assert (new != NULL);
        new->s = j;
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
void drop_arete(LISTE *g, int i, int j)
{
    i--;
    if (i < g->n)
    {
        int cpt = 0;
        int debutListe = 1;
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
        printf ("%d : " , i+1);
    else
    {
        afficher_liste(l->suivant , i);
        printf("%d->", l->s);
    }
}

/* construit le graphe par matrice d'adjacence d'un graphe donne par listes d'adjacences */
MATRICE liste_to_matrice(LISTE g)
{
    MATRICE m;

    return m;
}

/* construit le graphe represente par liste des predecesseurs e partir de celui par listes des successeurs (listes d'adjacence) */
LISTE succ_to_pred(LISTE g)
{
    LISTE gp;

    return gp;
}

/* calcule les degres des sommets (remplissage du tableau d) */
void calculs_degres(LISTE g, int *d)
{

}

/* fonction de tri utilise dans l'appel de qsort (voir coloration_Welsh_Powell */
static int tri_decroissant(const void *a, const void *b)
{
    if(((sommet_tri *)a)->val < ((sommet_tri *)b)->val)
        return 1;
    if(((sommet_tri *)a)->val > ((sommet_tri *)b)->val)
        return -1;
    if(((sommet_tri *)a)->s > ((sommet_tri *)b)->s)
        return 1;
    if(((sommet_tri *)a)->s < ((sommet_tri *)b)->s)
        return -1;
    return 0;
}

/* implementation de l'algorithme de coloration de Welsh Powell e partir du graphe g en entree, et des degres
   des sommets (d) prealablement calcules.
   L'algorithme complete un tableau couleurs contenant les "couleurs" de chaque sommet (entier de 0 e nchro-1),
   nchro etant le nombre chromatique du graphe */
void coloration_Welsh_Powell(LISTE g, int *d, int *couleurs, int *nchro)
{
    int i;
    sommet_tri *s;

    /* etape 1 : tri des sommets par degre decroissant */
    s = (sommet_tri *)calloc(g.n, sizeof(sommet_tri));
    assert(s != NULL);
    for(i=0; i<g.n; i++) {
        s[i].s = i;             /* sauvegarde de l'indice original du sommet */
        s[i].val = d[i];        /* valeur utile pour le tri = degre */
    }
    /* tri du tableau ainsi genere => la case 0 contiendra l'indice du sommet ayant le plus grand degre */
    qsort((void *)s, (size_t)g.n, (size_t)sizeof(sommet_tri), tri_decroissant);

    /* ................... */

    /* liberation memoire du tableau temporaire */
    free(s);
}
