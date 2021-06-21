#include<stdio.h>
#include<stdlib.h>
#include"code.h"
#include<math.h>
//#include<graphviz/gvc.h>
//#include<graphviz/cgraph.h>

// la fonction creer revient à créer un tableau de taille l'elemnt donné en parametre 
int * creer(int x)
{
    
    int *tab=(int *)malloc(x*sizeof(int));
    if (tab!=NULL)
    {
        for (int i=0;i<x;i++)
        {
            tab[i]=i;
        }
    }
    return tab;
}
void fusionner(int i,int j,int * tab)
{
    int level1=0;
    int level2=0;
    if (tab[i]==i && tab[j]==j)
    {
        if (i>j)
        {
            tab[i]=tab[j];
        }
        else tab[j]=tab[i];
    }
    if (tab[i]==i && tab[j]!=j)
    {
        while(tab[j]!=j)
        {
            j=tab[j];
        }
        tab[i]=tab[j];
    }
    if (tab[j]==j && tab[i]!=i)
    {
        while(tab[i]!=i)
        {
            i=tab[i];
        }
        tab[j]=i;
    }
    if (tab[i]!=i && tab[j]!=j)
    {
        while(tab[i]!=i)
        {
            
            i=tab[i];
            level1++;
        }
        while(tab[j]!=j)
        {
            j=tab[j];
            level2++;
        }
        if (level1<level2) tab[i]=tab[j];
        else tab[j]=tab[i];
    }   
}
void afficher(int *tab, char * nomfichier,int x)
{
    FILE* fichier = NULL;

    fichier = fopen(nomfichier, "r");

    if (fichier != NULL)
    {
       fputs("digraph G { \n",fichier);
       for(int i=0;i<x;i++)
       {
           fprintf(fichier,"   %d->%d  \n",i,tab[i]);
       }
       fprintf(fichier,"}");
        
        fclose(fichier); // On ferme le fichier qui a été ouvert
    }

}
int recupererclasse(int i,int *tab)
{
    while(tab[i]!=i)
    {
        i=tab[i];
    }
    return tab[i];
        
}
void  listerpartition(int *tab,int x)
{
    
    
    for (int i=0;i<x;i++)
    {
       if(tab[i]==i)
       {
           printf("%d ",i);
       } 
    }
    printf("\n");

    
    
}
void  listeclasse(int *tab,int x,int etiquette)
{
    for(int i=0;i<x;i++)
    {
        if(tab[i]==etiquette)
        {
            printf("%d ",i);
        }
        else
        {
            int j=i;
            int fin=0;
            while(tab[j]!=etiquette && fin==0)
            {
                if(tab[j]==j)
                {
                    fin=1;
                }
                else{
                    j=tab[j];
                }
            }
            if(fin ==0)
            {
                printf("%d",i);
            }
        }
        
    }
}
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    int *tab=creer(11);
    for(int i=0;i<11;i++)
    {
        tab[i]=i;
    }
    for(int i=0;i<11;i++)
    {
        printf("   %d  ",tab[i]);
    }
    printf("\n");
    fusionner(0,1,tab);
    afficher(tab,"g1.gv",11);
    for(int i=0;i<11;i++)
    {
        printf("   %d  ",tab[i]);
    }
    printf("\n");
    fusionner(2,3,tab);
     for(int i=0;i<11;i++)
    {
        printf("   %d  ",tab[i]);
    }
    printf("\n");
    fusionner(10,3,tab);
     for(int i=0;i<11;i++)
    {
        printf("   %d  ",tab[i]);
    }
    printf("\n");
    fusionner(5,9,tab);
     for(int i=0;i<11;i++)
    {
        printf("   %d  ",tab[i]);
    }
    printf("\n");
    fusionner(4,6,tab);
     for(int i=0;i<11;i++)
    {
        printf("   %d  ",tab[i]);
    }
    printf("\n");
    fusionner(8,7,tab);
    afficher(tab,"g2.gv",11);
     for(int i=0;i<11;i++)
    {
        printf("   %d  ",tab[i]);
    }
    printf("\n");
    fusionner(9,7,tab);
     for(int i=0;i<11;i++)
    {
        printf("   %d  ",tab[i]);
    }
    printf("\n");
    fusionner(6,8,tab);
     for(int i=0;i<11;i++)
    {
        printf("   %d  ",tab[i]);
    }
    printf("\n");
    printf("la classe de 4 est %d \n",recupererclasse(4,tab));
    printf("la classe de 8 est %d \n",recupererclasse(8,tab));
    afficher(tab,"g.gv",11);
    listerpartition(tab,11);
    // for(int i=0;i<11;i++)
    // {
    //     printf("%d ",liste[i]);
    // }
    // printf("\n");
    listeclasse(tab,11,5);
    printf("\n");
    listeclasse(tab,11,2);

    return 0;
}