#include<stdio.h>
#include<stdlib.h>
#include"con.h"
#include<time.h>
int ** generermatrice()
{
    int **tab=NULL;
    tab=(int * *)malloc(N*sizeof(int *));
    if (tab!=NULL)
    {
        for (int i=0;i<N;i++)
        {
        tab[i]=(int *)malloc(N*sizeof(int));
        }
    }
    return tab;
    
}
void remplirmatrcie(int **tab)
{


    srand(time(NULL));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            tab[i][j]=rand()%2;
        }
        
    }
}

void affichergraph(int **tab, char * nomfichier)
{
    FILE* fichier = NULL;

    fichier = fopen(nomfichier, "w");

    if (fichier != NULL)
    {
       fputs("graph G { \n",fichier);
       for (int i=0;i<N;i++)
       {
           for(int j=0;j<i;j++)
           {
               if(tab[i][j]==1)
               {
                  fprintf(fichier,"   %d--%d  \n",i,j); 
               }
           }
       }
       fprintf(fichier,"}");
        
        fclose(fichier); // On ferme le fichier qui a été ouvert
    }

}

void affichermatrice(int **tab)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            printf("%d ",tab[i][j]);
        }
        printf(" \n");
    }
}
void freematrice(int **tab)
{
    for(int i=0;i<N;i++)
    {
        free(tab[i]);
    }
    free(tab);
}
void matricenulle(int **tab)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            tab[i][j]=0;
        }
    }
}
void matriceprof(int **tab)
{
    tab[1][0]=1;
    tab[3][1]=1;
    tab[2][1]=1;
    tab[2][0]=1;
    tab[5][4]=1;
    tab[10][7]=1;
    tab[10][9]=1;
    tab[9][7]=1;
    tab[11][9]=1;
    tab[9][8]=1;
    tab[8][7]=1;
    tab[11][8]=1;
    tab[11][7]=1;

    
}