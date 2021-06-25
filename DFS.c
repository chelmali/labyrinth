#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "partition.h"
#include "lab.h"
#include "DFS.h"



int* DFS(graphe_t labyrinthe, int depart)
{
    int *visited=calloc(labyrinthe.nbnoeuds+1,sizeof(int));
    if (visited == NULL) exit(EXIT_FAILURE);

    int *parcours=calloc(labyrinthe.nbnoeuds+1,sizeof(int));
    if (parcours == NULL) exit(EXIT_FAILURE);

    point_t points[labyrinthe.nbnoeuds+1];

    int l=0;

    ssDFS(labyrinthe,points, depart, visited, parcours,&l);


    liberer_points(points,labyrinthe.nbnoeuds);
    free(visited);

    return parcours;
}


void ssDFS(graphe_t labyrinthe, point_t* points, int point, int* visited, int* parcours, int* l)
{
    visited[point]=1;
    parcours[(*l)++]=point;

    
    rechercheFilsNoeud(points,point,labyrinthe);

    int i=0;
    while (points[point].fils[i] != -2)
    {
        int f=points[point].fils[i];
        if (visited[f]==0)
        {
            ssDFS(labyrinthe, points, f, visited, parcours, l);
        }
        i++; 
    }
    
}


void rechercheFilsNoeud(point_t* points,int point,graphe_t labyrinthe)
{
    points[point].num=point;

    points[point].fils=malloc(sizeof(int)*5);
    if(points[point].fils == NULL) exit(EXIT_FAILURE);

    for (int j=0;j<5;j++)
    {
        points[point].fils[j]=-2;
    }

    int k=0;
    for (int j=0;j<labyrinthe.nbnoeuds;j++)
    {
        if (labyrinthe.listearete[j].deb == point)
        {
            points[point].fils[k]=labyrinthe.listearete[j].fin;          
            k++;
        }
        else if (labyrinthe.listearete[j].fin == point)
        {
            points[point].fils[k]=labyrinthe.listearete[j].deb;
            k++;
        }   
    }
}


void liberer_points(point_t* points, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        free(points[i].fils);
    } 
}
