/* Maxime Fleury Corentin Hanon, L3 Informatique */

#ifndef GRAPHE_LISTE_H_INCLUDED
#define GRAPHE_LISTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

/* representation d'un graphe non oriente par listes d'adjacence */
	typedef struct maillon {
		unsigned int s;				        /* indice du sommet */
		struct maillon *suivant;	/* pointeur sur le suivant */
	} MAILLON;

	typedef struct {
        unsigned int n;              /* nombre de sommets du graphe */
        MAILLON **L;        /* tableau de listes d'adjacence : L[i] <=> liste chainee des successeurs du sommet i */
	} LISTE;


  /* reservation en memoire du tableau de n listes chainees, initialisees e des listes vides */
	LISTE reservation_memoire_LISTE(unsigned int n);

  /* liberation memoire du graphe : appel d'une procedure de liberation de chacune des n listes chainees, puis
   liberation du tableau */
	void liberation_LISTE(LISTE g);

  /* ajout de l'arete (i,j) dans le graphe donne */
    LISTE add_arete(LISTE *g,unsigned int i,unsigned int j);

  /* suppression de l'arete (i,j) dans le graphe donne */
    void drop_arete(LISTE *g,unsigned int i,unsigned int j);

  /* affichage du graphe represente par ses listes d'adjacence */
	void afficher_LISTE(LISTE g);

    void afficher_liste(MAILLON* l , unsigned int i);

 /* construit le graphe represente par liste des predecesseurs e partir de celui par listes des successeurs (listes d'adjacence) */
    LISTE succ_to_pred(LISTE g);

/* calcule les degres des sommets (remplissage du tableau d) */
	void calculs_degres(LISTE g, int *d);

/* implementation de l'algorithme de coloration de Welsh Powell e partir du graphe g en entree, et des degres
   des sommets (d) prealablement calcules.
   L'algorithme complete un tableau couleurs contenant les "couleurs" de chaque sommet (entier de 0 e nchro-1),
   nchro etant le nombre chromatique du graphe */
   void coloration_Welsh_Powell(LISTE g, int *d, int *couleurs, int *nchro);

#endif
