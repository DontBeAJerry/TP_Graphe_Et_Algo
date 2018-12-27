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
		int s;				        /* indice du sommet */
		int c;				        /* cout du sommet */
		struct maillon *suivant;	/* pointeur sur le suivant */
	} MAILLON;

	typedef struct {
        unsigned int n;              /* nombre de sommets du graphe */
        unsigned int m;              /* nombre d'arrêtes du graphe */
        MAILLON **L;        /* tableau de listes d'adjacence : L[i] <=> liste chainee des successeurs du sommet i */
	} LISTE;


  /* reservation en memoire du tableau de n listes chainees, initialisees e des listes vides */
	LISTE reservation_memoire_LISTE(unsigned int n);

  /* liberation memoire du graphe : appel d'une procedure de liberation de chacune des n listes chainees, puis
   liberation du tableau */
	void liberation_LISTE(LISTE g);

  /* ajout de l'arete (i,j) dans le graphe donne */
    LISTE add_arete(LISTE *g,unsigned int i,unsigned int j, int c);

  /* suppression de l'arete (i,j) dans le graphe donne */
    void drop_arete(LISTE *g,unsigned int i,unsigned int j);

  /* affichage du graphe represente par ses listes d'adjacence */
	void afficher_LISTE(LISTE g);

    void afficher_liste(MAILLON* l , unsigned int i);

#endif
