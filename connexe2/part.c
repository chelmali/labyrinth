#include <stdlib.h>
#include <stdio.h>
#include "part.h"




part_t* init(part_t* partition,int taille)
{
    partition = malloc(sizeof(part_t));

    if( partition == NULL) {
        fprintf(stderr, "ERREUR : allocation echouee \n");
    } 
    partition->pere = malloc(taille*sizeof(int));
    partition->hauteur = malloc(taille*sizeof(int));

    if( partition->pere == NULL) {
        fprintf(stderr, "ERREUR : allocation echouee \n");
    } 

    if( partition->hauteur == NULL) {
        fprintf(stderr, "ERREUR : allocation echouee \n");
    } 

    for(int i=0 ; i<taille ;i++)
    {
        (partition->pere)[i]=i;
        (partition->hauteur)[i]=1;
    }

    return partition;
}

int chercher_racine(part_t* partition , int noeud)
{
    int racine=noeud;
    while(racine != (partition->pere)[racine])
        racine = (partition->pere)[racine];
    
    return racine;
}


void fusion(part_t* partition ,  int taille , int x ,int y)
{
    if( x > (taille-1) || y > (taille-1) ) {
        fprintf(stderr, "ERREUR : indice n'existe pas \n");
    } 

    int r_x = chercher_racine(partition,x);
    int r_y = chercher_racine(partition,y);

    if( (partition->hauteur)[r_x] < (partition->hauteur)[r_y] )
        (partition->pere)[r_x] = r_y ;
    else if( (partition->hauteur)[r_x] > (partition->hauteur)[r_y] )
        (partition->pere)[r_y] = r_x ;
    else{
        (partition->pere)[r_y] = r_x ;
        (partition->hauteur)[r_x]++;
    }
}


void lister_classe(part_t* partition, int taille, int val)
{
    int racine = chercher_racine(partition,val);
    int classe[taille];
    int k=0 , j=0;

    for(int i=0 ; i<taille ; i++)
    {
        int r_i = chercher_racine(partition,i);
        if(r_i == racine)
        {
            classe[k]=i;
            k++;
        }
    }
    classe[k]=-1;
    printf("{");

    while(classe[j] != -1)
    {
        printf(" %d",classe[j]);
        j++;
    }
    
    printf(" }");
}

void list_partition(part_t* partition , int taille)
{
    printf("{");
    for(int i=0 ; i<taille ; i++)
    {
        if( (partition->pere)[i] == i )
        {
            lister_classe(partition,taille,i);
        }
    }
    printf("}");
}


void free_part(part_t* partition)
{
    free(partition->pere);
    free(partition->hauteur);
    free(partition);
}
