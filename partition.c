#include <stdlib.h>
#include <stdio.h>
#include"partition.h"




part_t* initialisation(int taille)
{
    part_t * partition = malloc(sizeof(part_t));

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

int findtop(part_t* partition , int noeud)
{
    int racine=noeud;
    while(racine != (partition->pere)[racine])
        racine = (partition->pere)[racine];
    
    return racine;
}
/*

void fusion(part_t* partition ,  int taille , int x ,int y)
{
    if( x > (taille-1) || y > (taille-1) ) {
        fprintf(stderr, "ERREUR : indice n'existe pas \n");
    } 

    int tx = findtop(partition,x);
    int ty = findtop(partition,y);

    if( (partition->hauteur)[tx] < (partition->hauteur)[ty] )
        (partition->pere)[tx] = ty ;
    else if( (partition->hauteur)[tx] > (partition->hauteur)[ty] )
        (partition->pere)[ty] = tx ;
    else{
        (partition->pere)[ty] = tx ;
        (partition->hauteur)[tx]++;
    }
}

*/
void fusion(int el1, int el2, part_t * partition){
    int     classe1 = findtop(partition , el1);
     int      classe2 = findtop(partition, el2);

    if(classe1 != classe2){
        if(partition->hauteur[classe1] >= partition->pere[classe2]){
            partition->pere[classe2] = classe1;
            if(partition->hauteur[classe1] == partition->hauteur[classe2])
                partition->hauteur[classe1] += 1;
        }
        else{
            partition->pere[classe1] = classe2;
            //partition->hauteur[classe2] += 1;
        }
    }
}
void lister_classe(part_t* partition, int taille, int val)
{
    int racine = findtop(partition,val);
    int classe[taille];
    int k=0 , j=0;

    for(int i=0 ; i<taille ; i++)
    {
        int r_i = findtop(partition,i);
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

void lister_partition(part_t* partition , int taille)
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
