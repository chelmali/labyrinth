#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// la fonction creer revient à créer un tableau de taille l'elemnt donné en parametre 
int * creer(int x);
void fusionner(int i,int j,int * tab);
int recupererclasse(int i,int *tab);
void afficher(int *tab, char * nomfichier,int x);
void  listerpartition(int *tab,int x);
void  listeclasse(int *tab,int x,int etiquette);