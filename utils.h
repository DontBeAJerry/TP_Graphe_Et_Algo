//
// Created by MAXIMEFleury on 18/12/2018.
//

#ifndef TP_GRAPHE_ET_ALGO_UTILS_H
#define TP_GRAPHE_ET_ALGO_UTILS_H

    #include "graphe_liste.h"
    LISTE generationAleat(unsigned int n,unsigned int m);

    bool egale(MAILLON m1 , MAILLON m2);
    void bellmanFord(LISTE l, int s);
    void solution(int dist[], int n, int s);

#endif //TP_GRAPHE_ET_ALGO_UTILS_H
