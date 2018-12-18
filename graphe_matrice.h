/* Maxime Fleury Corentin Hanon, L3 Informatique */

#ifndef GRAPHE_MATRICE_H_INCLUDED
#define GRAPHE_MATRICE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

/* representation d'un graphe oriente par une matrice d'adjacence */
	typedef struct {
		int n;				/* nombre de sommets dans le graphe */
		int **M;			/* matrice d'adjacence : M[i][j] = 1 <=> arc (i,j) dans le graphe */
	} MATRICE;

/* representation d'un graphe oriente par une matrice d'incidence */
	typedef struct {
		int n;				/* nombre de sommets dans le graphe (nombre de lignes) */
		int m;              /* nombre d'arcs du graphe (nombre de colonnes) */
		int **M;			/* matrice d'incidence : M[i][j] = 1 <=> arc j du graphe sort de i */
                            /*                       M[i][j] = -1 <=> arc j du graphe arrive en i */
	} MATRICE_INC;

/* structure utile pour trier les sommets */
	typedef struct {
        int s;              /* indice du sommet dans le graphe */
        int val;            /* valeur associee au sommet pour le tri */
    } sommet_tri;

  /* reservation en memoire de l'espace necessaire pour un graphe contenant n sommets */
	MATRICE reservation_MATRICE(int n);

  /* liberation de la memoire occupee par un graphe donne */
	void liberation_MATRICE(MATRICE g);

  /* ajout de l'arc (i,j) dans le graphe g */
	void add_arc(MATRICE *g, int i, int j);

  /* suppression de l'arc (i,j) dans le graphe g */
	void drop_arc(MATRICE *g, int i, int j);

  /* affichage du graphe donne */
    void affiche_MATRICE(MATRICE g);

  /* fonction qui retourne true si j est un successeur direct de i, false sinon */
	bool est_successeur(MATRICE g, int i, int j);

  /* convertit un graphe donne par sa matrice d'adjacence en un graphe represente par matrice d'incidence */
    MATRICE_INC conversion_MATRICE(MATRICE g);

#endif
