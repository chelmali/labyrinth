#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"djikstra.h"

// #include "dijkstra.h"

// #include"tas.h"
// #define infinity 120
// //tester si une arete existe entre deux noeuds k et l dans un graphe
// arete_t * arete (arbre_t  * graph, int k, int l)
// {
//     arete_t * areterecherche=NULL
//     int nb=graph->nbnoeuds;
//     int nbaretes=((nb+2)*(nb-1))/2;
//     int bool=0;
//     for(int i=0;i<nbaretes;i++)
//     {
//         areterecherche=&(graph->listearete[i]);
//         if((areterecherche.tab[0]==k && areterecherche.tab[1]==l) || (areterecherche.tab[0]==l && areterecherche.tab[1]==k))
//         {
//             bool=1;
//         }
//         break;
//     }
//     return areterecherche;
// }
// //initialiser un tableau de distance de tout les noeus du graph 
// int * initialiser_distance(arbre_t * graph)
// {
//     int nb=graph->nbnoeuds;
//     int * distance=(int *)malloc(nb*sizeof(int));
//     if (distance==NULL)
//     {
//         printf("erreur lors de l'allocation du tableau des distances");
//         exit(EXIT_FAILURE);
//     }
//     else
//     {
//         for (int i=0;i<nb;i++)
//         {
//             distance[i]=infinity;
//         }
//     }
//     return distance;
// }
// //initialiser le tableau de pere pour tous les noeuds du graph
// int *initialiser_pere(arbre_t *graph)
// {
//     int nb=graph->nbnoeuds;
//     int * pere=(int *)malloc(nb*sizeof(int))
//     for (int i=0,i<nb,i++)
//     {
//             pere[i]=-1;
//     }
// }

// #define TAILLE 5			/* nombre de sommets du graphe */
// #define MAXINT 1000			/* un tres grand entier */

// typedef struct cellule			/* noeud, poids et pointeur */
// {	int numero;
// 	int poids;
// 	struct cellule *suivant;
// } Cellule, *LISTE;

// LISTE graphe[TAILLE];			/* graphe = tableau de listes */
// int D[TAILLE];				/* Les distances trouvees a chaque instant */
// int queue[TAILLE];			/* file pour les sommets selon D croissant */
// int ordre[TAILLE];			/* Ordre de chaque sommet dans la file selon D croissant */
// int explore[TAILLE];			/* Pour les sommets deja ajoutes */
// int C[TAILLE];				/* pour le predecesseur de chaque sommet ajoute */

/// fonction qui permet l'allocation d'un noeud
noeud_t  *initialisation()
{
  noeud_t *noeud = (noeud_t *) malloc(sizeof(noeud_t));
  return noeud;
}

/* initialiser un noeud en specifian t son id et sa distance. */
noeud_t *Creenoeud(int l, int k)
{
  noeud_t *noeud = initialisation();
  noeud->id = l;
  noeud->poids = k;
  noeud->suivant = NULL;
  return noeud;
}

/* Initialisation des diverses variables */
void init(void)
{
  for(int i = 0; i<taille; i++)
  {
    distances[i] = infinity; heap[i] = i; rang[i] = i; visite[i] = 0;
  }
  distances[0] = 0; predecesseur[0] = -1;			/* On commence par 0 */
}

/* Operation sur les files d'attente */
void swap(int i, int j)		/* echanger deux sommets dans la queue */
{
    int a;
    rang[heap[i]] = j; rang[heap[j]] = i;
    a = heap[i]; 
    heap[i] = heap[j];
    heap[j] = a;
}

/* retablit la condition de file de maniere descendante sur les longueur positions de la file */
void swap_descendant(int longueur, int i)
{
  int fils=2*i+1; //fils gauche 
  if(fils>=longueur) return;
  if((fils<longueur-1)&&(distances[heap[fils]]>distances[heap[fils+1]])) fils=fils+1;
  if(distances[heap[i]]>distances[heap[fils]])
   {
      swap(i,fils);
      swap_descendant(longueur, fils);
   }
}

/* retablit la condition de file de maniere ascendante sur les longueur positions de la file */
void swap_montant(int longueur, int i)
{
  int pere=(i-1)/2;
  if(distances[heap[i]]<distances[heap[pere]])
   {
      swap(pere,i);
      swap_montant(longueur, pere);
   }
}

/* retourne le minimum dans la file et retablit l'ordre */
int minimum(int longueur)
{
  int a = heap[0];  //recuperer le premier element dans la file de priorité
  visite[a] = 1;
  if(longueur > 1)
  {
    swap(0, longueur-1);
    swap_descendant(longueur-1, 0);
  }
  return a;
}

/* algorithme de Dijkstra. Premiere etape, on ajoute un sommet, puis on actualise */
void dijkstra_iteration(int longueur)	/* nombre de sommets non encore inclus */
{
  noeud_t *c;
  int a = minimum(longueur);		/* extraction du minimum */
  int j;
  for(c=graphe[a]; c != NULL; c=c->suivant)
  {
    j = c->id;
    if((visite[j] == 0)&&(distances[a] + c->poids < distances[j]))
    {
      distances[j] = distances[a] + c->poids; predecesseur[j] = a; 
      swap_montant(longueur-1, rang[j]); /* si actualisation */
    }
  }
}

void dijkstra(void)
{
  int i;
  init();
  for(i=taille; i>0; i--) 
  dijkstra_iteration(i);
}

int main(void)
{
    FILE * file1=fopen("gragh.gv","w");
    FILE *fichier=fopen("graph1.gv","w");
    fputs("graph G { \n",fichier);
    if (file1 !=NULL)
    {

        fputs("graph G { \n",file1);   
        int i;
        noeud_t *c1, *c2, *c3;
        c1 = Creenoeud(1,1); 
        fprintf(file1,"   1--1 --\n") ;
        c2 = Creenoeud(3,2); 
        fprintf(file1,"   3--2 --\n") ;
        c3 = Creenoeud(4,9);
        fprintf(file1,"   4--9 --\n") ;
        graphe[0]=c1; 
        c1->suivant=c2; 
        c2->suivant=c3;
        c1 = Creenoeud(2,5);
        fprintf(file1,"   2--5 --\n") ;
        graphe[1]=c1;
        c1 = Creenoeud(4,1);
        fprintf(file1,"   4--1 --\n");
        graphe[2]=c1;
        c1 = Creenoeud(2,2);
        fprintf(file1,"   2--2 --\n"); 
        c2 = Creenoeud(4,6);
        fprintf(file1,"   4--6 --\n");
        fprintf(file1,"}\n");
        graphe[3]=c1; c1->suivant=c2;
        graphe[4]=NULL;
        dijkstra();
        for(i=0; i<taille; i++)
        {
            printf("sommet %d, distance %d, origine %d\n", i, distances[i], predecesseur[i]);
              fprintf(fichier,"   %d--%d  \n",i, predecesseur[i]);
            
        }
        fprintf(fichier,"}\n");
     
    }
    else
    {
        printf("erreu \n");
    }
}
