
#ifndef lab_h
#define lab_h

#include "partition.h"

typedef struct{
    int deb;
    int fin;
    int distance;
}arete_t;

typedef struct{
    int nbnoeuds;
    int nbarete;
    arete_t* listearete;
}graphe_t;

arete_t* init_arete(arete_t* listearete,int nbnoeuds, int nbarete);
graphe_t* init_graph(graphe_t* graphe, int nbnoeuds, int nbarete);
part_t* graphmini(graphe_t* g);
// void graphmini(part_t *partition,graphe_t * arb,arete_t *listearete);
void echange(arete_t * ar1,arete_t * ar2);
void Fisher(graphe_t* graphe);
graphe_t * gengraph( int ligne, int colonne);
graphe_t* Kruskal(graphe_t* graphe);
void free_graph(graphe_t *arb);
void print_graph(graphe_t*);
void afficher_graphiz(graphe_t* graphe,const char* nom_fichier);

#endif
