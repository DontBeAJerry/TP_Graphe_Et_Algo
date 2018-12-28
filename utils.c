#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "time.h"
#include "utils.h"

#define V 9;

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
        printf("\nMatrice d'adjacence : \n");
        for(unsigned int i = 0; i<n ; i++) {
            for (unsigned int j = 0; j < n; j++) {
                printf("%d ", M[i][j]);
            }
            printf("\n");
        }



    return L;
}

//Comparaison entre deux maillons
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
        printf("Le graphe ne contient pas de circuit absorbant\n");
    }else{
        printf("\n********************************************************\n");
        printf("* Erreur :\tLe graphe contient des circuits absorbants *");
        printf("\n********************************************************\n");
    }

    solution(d, n, s);
}

void dijkstra(LISTE l, int src){

    int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    int u;
    int dist[l.n];
    bool sptSet[l.n]; //Sera 1 si le sommet i fait parti de la solution
    /*
    int graph[l.n][l.n];
    MAILLON* tmp;
    //Initialisation de la matrice
    for(unsigned int i = 0; i<l.n ; i++){
        for(unsigned int j = 0; j<l.n; j++){
            graph[i][j] = 0;
        }
    }
    for(int i = 0; i<l.n;i++){
        tmp = l.L[i];
        while(tmp != NULL){
            graph[i][tmp->s] = tmp->c;
            tmp = tmp->suivant;
        }
    }

    //Affichage de la matrice d'adjacence
    printf("\nMatrice d'adjacence : \n");
    for(unsigned int i = 0; i<l.n ; i++) {
        for (unsigned int j = 0; j < l.n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }*/

    //initialisation des listes de distances et de solution
    for (int i = 0; i < l.n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;


    //Pour chaque sommet, trouver le PCC
    for (int count = 0; count < l.n-1; count++){

        int min = INT_MAX;
        int min_index =0;

        for (int v = 0; v < l.n; v++)
            if (!sptSet[v] && (dist[v] <= min)) {
                min = dist[v];
                min_index = v;
            }
        int u = min_index;
        //Marqué le sommet u comme faisant parti de la solution
        sptSet[u] = true;

        // Mise à jour des distances
        for (int v = 0; v < l.n; v++) {
            if (!sptSet[v] && (graph[u][v] != INT_MAX) &&
                dist[u] != INT_MAX && (dist[u] + graph[u][v] < dist[v]) )
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print the constructed distance array
    printf("\nSommet \tDistance depuis le sommet %d\n",src);

    for (int i = 0; i < l.n; ++i){
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void solution(int dist[], int n, int s)
{
    // This function prints the final solution
    printf("\nSommet \tDistance depuis le sommet %d\n",s);

    for (int i = 0; i < n; ++i){
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int minDistance(int * dist, int * sptSet, int V){

    int min = INT_MAX;
    int min_index =0;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

void dijkstra2()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    int src = 0;
    int dist[V];     // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++) {
        int min = INT_MAX, min_index;

        for (int v = 0; v < V; v++){
            if (sptSet[v] == false && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printf("\nSommet \tDistance depuis le sommet %d\n",src);

    for (int i = 0; i < V; ++i){
        printf("%d \t\t %d\n", i, dist[i]);
    }


}