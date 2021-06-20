#include<stdio.h>
#include<stdlib.h>
#include"tas.h"
tas_t *createtas(void)
{
    tas_t * tas=malloc(sizeof(tas_t));
    if (tas!=NULL)
    {
        tas->tab=malloc(2 *sizeof(int));
        tas->capacite=TAILLE;
        tas->size=0;
    }
    return tas;
}
//inserer un element dans le tas
void insererelement(tas_t * tas,int v)
{
    if (tas->size==tas->capacite) tas_realloc(tas); //si la capacite du tableau est atteinte
    tas->size=tas->size+1; //le size du tableau est incrementé
    tas->tab[tas->size]=v;    // on inserer l'element a la fin 
    modifiertas(tas);      // on reorganise le tableau
}

//reorganiser le tableau apres insertion
void modifiertas(tas_t * tas)
{
    int temp;
    int size=tas->size;
    int pere=size/2;
    while(tas->tab[pere]>tas->tab[size] && size>1)
    {
        temp=tas->tab[size];
        tas->tab[size]=tas->tab[pere];
        tas->tab[pere]=temp;
        size=size/2;
        pere=pere/2;
    }
}
//liberer le tas
void freetas(tas_t *tas)
{
    free(tas->tab);
    free(tas);
}


//redimendionner le tas
 void tas_realloc(tas_t *tas)
{
    int new_size = 2*tas->capacite;
    tas->tab = realloc(tas->tab, new_size*sizeof(int));
    tas->capacite = new_size;
}
int popNode(tas_t *tas)
{
    int tmp;
    int indexUp = 1;
    int indexDn = 2;

    if(tas->size==0) return -1;

    int value = tas->tab[1];
    tas->tab[1] = tas->tab[tas->size];
    tas->size--;

    while(indexDn<=tas->size)
    {
        if(indexDn+1 <= tas->size && tas->tab[indexDn] > tas->tab[indexDn+1])
        {
            indexDn++;
        }
        if(tas->tab[indexDn] < tas->tab[indexUp])
        {
            tmp = tas->tab[indexDn];
            tas->tab[indexDn] = tas->tab[indexUp];
            tas->tab[indexUp] = tmp;
        }
        indexUp = indexDn;
        indexDn *= 2;
    }
    return value;
}
void  tri_par_tas(int tab[TAILLE])
{
    int fin =TAILLE;
    int temp;
    int vitesse;
    while(fin>1)
    {
        vitesse++;
        temp=tab[0];
        tab[0]=tab[fin-1];
        fin--;
        int j=0;
        while(2*j+1<fin)
        {
            int k=2*j;
            if (k+2<fin)
            {
                if(tab[k+1]>tab[k+2]&&tab[j]<tab[k+1])
                {
                    temp=tab[k+1];
                    tab[k+1]=tab[j];
                    j=k+1;
                }
                else if(tab[j]<tab[k+2])
                {
                    temp=tab[k+2];
                    tab[k+2]=tab[j];
                    tab[j]=temp;
                    j=k+2;
                }
                else 
                    break;
            }
            else if(k+1<fin)
            {
                if (tab[j]<tab[k+1])
                {
                    temp=tab[k+1];
                    tab[k+1]=tab[j];
                    tab[j]=temp;
                }
                else 
                    break;
            }
        }
    }
    
}

int main(int argc,char **argv)
{
    (void)argc;
    (void)argv;
    int tab[6]={9,3,5,6,7,9};
    tas_t * tas=createtas();
    insererelement(tas,25);
    insererelement(tas,11);
    insererelement(tas,9);
    insererelement(tas,14);
     printf("la valeur du tete est %d\n",popNode(tas));
    printf("la valeur du tete est %d\n",popNode(tas));
    printf("la valeur du tete est %d\n",popNode(tas));
    printf("la valeur du tete est %d\n",popNode(tas));
    //printf("la valeur du tete est %d\n",popNode(tas));   // on retourne -1 si le tas est vide
    //int tab2[6]={1,3,2,7,89};
    tri_par_tas(tab);
    for (int i=1;i<6;i++)
    {
        printf("%d\n",tab[i]);
    }
    




}