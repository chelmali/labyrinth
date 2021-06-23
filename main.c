#include <stdlib.h>
#include <stdio.h>
#include"graph.h"
#include<time.h>

int main(int argc,char ** argv)
{
    (void)argc;
    (void)argv;
    int i=0;
    part_t* partition=initialisation( partition,5);
    arbre_t * arb=generergraph(5);

    FILE* fichier1 = NULL;

    fichier1 = fopen("graph1.gv", "w");

    if (fichier1 != NULL)
    {
      int i=0;
       fputs("graph G { \n",fichier1);
         while(((arb->listearete)[i]).tab[0]!=-1)
       {
        
               
            fprintf(fichier1,"   %d--%d  \n",((arb->listearete)[i]).tab[0],((arb->listearete)[i]).tab[1]); 
             i++;
               
           
       }

       fprintf(fichier1,"}");
       fclose(fichier1);
    }
    // affichergraph(arb,"graph.gv",5);
    
    // arb=cmpconnex( partition, arb);
     //graphmini(partition,arb);
     kruskal(partition,arb);

    FILE* fichier = NULL;

    fichier = fopen("graph.gv", "w");

    if (fichier != NULL)
    {
       fputs("graph G { \n",fichier);
       int j=0;
       while(((arb->listearete)[j]).tab[0]!=-1)
         
       {
        
               
            fprintf(fichier,"   %d--%d  \n",((arb->listearete)[j]).tab[0],((arb->listearete)[j]).tab[1]); 
            j++;
               
           
       }
       fprintf(fichier,"}");
        
        fclose(fichier); // On ferme le fichier qui a été ouvert
    }
}