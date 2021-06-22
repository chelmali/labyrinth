#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"con.h"
#include"part.h"
#define TAILLE 12
#define N 12



int main(int argc,char ** argv)
{
    (void)argc;
    (void)argv;
    int ** tab=generermatrice();
    remplirmatrcie(tab);
    affichermatrice(tab);
    //affichergraph(tab,"graph.gv");
    part_t* partition = init(partition,TAILLE);
    list_partition(partition,TAILLE);
    printf("\n\n");

    for(int i=1 ;i<N ;i++)
    {
        for(int j=0 ; j<i ; j++)
        {
            if( tab[i][j] == 1)
                fusion(partition , TAILLE , i , j);
        }
    }

    list_partition(partition,TAILLE);
    printf("\n\n\n\n");
    freematrice(tab);
    free_part(partition);
    matricenulle(tab);
    matriceprof(tab);
    affichergraph(tab,"graph.gv");
    
}