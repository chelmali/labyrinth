#include <stdlib.h>
#include <stdio.h>



typedef struct part
{
    int *pere;
    int *hauteur;
}part_t;
part_t* initialisation(part_t* partition,int taille);
int findtop(part_t* partition , int noeud);
void fusion(part_t* partition ,  int taille , int x ,int y);
void lister_classe(part_t* partition, int taille, int val);
void lister_partition(part_t* partition , int taille);
void free_part(part_t* partition);
typedef struct arete
{
    int tab[2];    //tab[0] est le debut de l'arete et tab[1] est la fin de l'arete
}arete_t;
typedef struct arbre
{
    int nbnoeuds;
    arete_t * listearete;
}arbre_t;
arbre_t * generergraph(int n);
void affichergraph(arbre_t *arb, char * nomfichier,int n);
arbre_t *cmpconnex(part_t * partition, arbre_t * arb);
void graphmini(part_t *partition,arbre_t * arb,arete_t * listearete);
arbre_t* kruskal(part_t* partition,arbre_t* arb);