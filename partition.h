#ifndef partition_h
#define partition_h

#include <stdlib.h>
#include <stdio.h>



typedef struct{
    int *pere;
    int *hauteur;
}part_t;

part_t* initialisation(int taille);
int findtop(part_t* partition , int noeud);
//void fusion(part_t* partition ,  int taille , int x ,int y);
void fusion(int el1, int el2, part_t * partition);
void lister_classe(part_t* partition, int taille, int val);
void lister_partition(part_t* partition , int taille);
void free_part(part_t* partition);
#endif
