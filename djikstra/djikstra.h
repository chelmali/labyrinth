#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define taille 12
#define infinity 1200
typedef struct noeud
{
    int id;
    int poids;
    struct noeud * suivant;
}noeud_t,*liste;
liste graphe[taille];
int heap[taille]; //file de peiorite selon les distances decroissants
int distances[taille]; //tableau de distance 
int visite[taille]; // tableau pour stocker les sommets deja visités
int predecesseur[taille]; // tableau qui stocke le predecesseur de chaque sommet ajouté
int rang[taille];  //l'ordre de chaque sommet dans la file de priorité

noeud_t * initialistion(void);
void dijkstra(void);
void dijkstra_iteration(int longueur);
int minimum(int longueur);
void swap_montant(int longueur, int i);
void swap_descendant(int longueur, int i);
void swap(int i, int j)	;
void init(void);
noeud_t *Creenoeud(int l, int k);