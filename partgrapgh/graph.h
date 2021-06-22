#include <stdlib.h>
#include <stdio.h>



typedef struct part
{
    int *pere;
    int *hauteur;
}part_t;
part_t* init(part_t* partition,int taille);
int chercher_racine(part_t* partition , int noeud);
void fusion(part_t* partition ,  int taille , int x ,int y);
void lister_classe(part_t* partition, int taille, int val);
void list_partition(part_t* partition , int taille);
void free_part(part_t* partition);
typedef struct arete
{
    int tab[2];
}arete_t;
typedef struct arbre
{
    int nbnoeuds;
    arete_t * listearete;
}arbre_t;
arbre_t * generergraph(int n);
void affichergraph(arbre_t *arb, char * nomfichier,int n);
arbre_t *cmpconnex(part_t * partition, arbre_t * arb);
