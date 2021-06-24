#include<stdio.h>
#include<stdlib.h>
#define TAILLE 1000
#define newcapacity 3
//definir la structure Heap
typedef struct
{
    int capacite;
    int size;
    int * tab ;
}tas_t;
//creation d'un tas
tas_t *createtas(void);
//inserer un element à la fin du tableau
void insererelement(tas_t * tas,int v);
void modifiertas(tas_t * tas);
//liberer le tas
void freetas(tas_t *tas);
void supprimerelemnt(tas_t *tas);
void tas_realloc(tas_t *tas);
int popNode(tas_t *tas);
void tri_par_tas(int tab[TAILLE]);
int est_vide_tas(tas_t tas);