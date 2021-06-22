#include <stdlib.h>
#include <stdio.h>
#include"graph.h"
#include<time.h>
// #include"part.h"
int main(int argc,char ** argv)
{
    (void)argc;
    (void)argv;
    int i=0;
    part_t* partition=init( partition,5);
    arbre_t * arb=generergraph(5);
    //affichergraph(arb,"graph.gv",5);
    arb=cmpconnex( partition, arb);
    for(int i=0;i<5;i++)
    {
        
        printf("{");       
        printf( "%d",((arb->listearete)[i]));
            
               
           
    }
    printf("}\n");

    FILE* fichier = NULL;

    fichier = fopen("graph.gv", "w");

    if (fichier != NULL)
    {
       fputs("graph G { \n",fichier);
         for(int i=0;i<5;i++)
       {
        
               
            fprintf(fichier,"   %d--%d  \n",((arb->listearete)[i]).tab[0],((arb->listearete)[i]).tab[1]); 
            // i++;
               
           
       }
       fprintf(fichier,"}");
        
        fclose(fichier); // On ferme le fichier qui a été ouvert
    }
}