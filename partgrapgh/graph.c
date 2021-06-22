#include <stdlib.h>
#include <stdio.h>
#include"graph.h"
#include<time.h>
//  #include"part.h"



arbre_t * generergraph(int n)
{
    int k=0;
    srand(time(NULL));
    arbre_t * arb=malloc(sizeof(arbre_t));
    if(arb!=NULL)
    {
        arb->nbnoeuds=n;
       arb->listearete=malloc(((n*(n-1))/2)*sizeof(arete_t));
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<i;j++)
           {
               int t=rand()%2;
               if (t==1)
               {
                    ((arb->listearete)[k]).tab[0]=j;
                    ((arb->listearete)[k]).tab[1]=i;
                    k++;

               }
           }
           
       }
    }
    for(int i=0;i<n;i++)
    {
        printf("( %d,%d)\n",((arb->listearete)[i]).tab[0],((arb->listearete)[i]).tab[1]);
    }
    return arb;

}
arbre_t *cmpconnex(part_t * partition, arbre_t * arb)
{
    int k=0;

    while(((arb->listearete)[k].tab[0])!= -1)
    {
        fusion(partition,arb->nbnoeuds,((arb->listearete)[k]).tab[0],((arb->listearete)[k]).tab[1]);
        k++;
        
    }
    return arb;
}
void affichergraph(arbre_t *arb, char * nomfichier,int n)
{
    FILE* fichier = NULL;

    fichier = fopen(nomfichier, "w");

    if (fichier != NULL)
    {
       fputs("graph G { \n",fichier);
       for (int i=0;i<n;i++)
       {
        
               
            fprintf(fichier,"   %d--%d  \n",((arb->listearete)[i]).tab[0],((arb->listearete)[i]).tab[1]); 
               
           
       }
       fprintf(fichier,"}");
        
        fclose(fichier); // On ferme le fichier qui a été ouvert
    }

}

// dot -Tpng graph.gv -o file.png && sxiv file.png
