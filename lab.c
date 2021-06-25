#include <stdlib.h>
#include <stdio.h>
#include"lab.h"
//#include"partition.h"
#include<time.h>
#include"DFS.h"



/*
graphere_t * generergraph(int n)
{
    int k=0;
    srand(time(NULL));
    graphere_t * graphe=malloc(sizeof(graphere_t));
    if(graphe!=NULL)
    {
        graphe->nbnoeuds=n;
       graphe->listearete=malloc(((n*(n-1))/2)*sizeof(arete_t));
       for(int i=1;i<graphe->nbnoeuds;i++)
       {
           for(int j=0;j<i;j++)
           {
               int t=rand()%2;
               if (t==1)
               {
                    ((graphe->listearete)[k]).deb=j;
                    ((graphe->listearete)[k]).fin=i;
                    k++;

               }
           }
           
       }
        ((graphe->listearete)[k]).deb=-1;  //fin du graph est marqué par le couple (-1,-1)
        ((graphe->listearete)[k]).fin=-1;

    }
    for(int i=0;i<graphe->nbnoeuds ;i++)
    {
        printf("( %d,%d)\n",((graphe->listearete)[i]).deb,((graphe->listearete)[i]).fin);
    }
    return graphe;

}
graphere_t *cmpconnex(part_t * partition, graphere_t * graphe)
{
    int k=0;

    while(((graphe->listearete)[k].deb)!= -1)
    {
        fusion(partition,graphe->nbnoeuds,((graphe->listearete)[k]).deb,((graphe->listearete)[k]).fin);
        ((graphe->listearete)[k]).deb=((graphe->listearete)[k]).deb;
        ((graphe->listearete)[k]).fin=((graphe->listearete)[k]).fin;
        k++;
        
    }
    return graphe;
}
void affichergraph(graphere_t *graphe, char * nomfichier,int n)
{
    FILE* fichier = NULL;

    fichier = fopen(nomfichier, "w");

    if (fichier != NULL)
    {
       fputs("graph G { \n",fichier);
       for (int i=0;i<n;i++)
       {
        
               
            fprintf(fichier,"   %d--%d  \n",((graphe->listearete)[i]).deb,((graphe->listearete)[i]).fin);
               
           
       }
       fprintf(fichier,"}");
        
        fclose(fichier); // On ferme le fichier qui a été ouvert
    }

}*/
/*

arete_t* init_arete(arete_t* listearete,int nbnoeuds, int nbarete)
{
    listearete = malloc( nbarete * sizeof(arete_t) );

    if(listearete == NULL) {
        exit(EXIT_FAILURE);
    }
    // printf("%d",nbnoeuds*(nb))

    return listearete;
}

*/
/*
graphe_t* init_graph(graphe_t* graphe, int nbnoeuds, int nbarete)
{
    graphe = malloc(sizeof(graphe_t));
    if( graphe == NULL) {
        exit(EXIT_FAILURE);
    }

    graphe->nbnoeuds = nbnoeuds ;
    graphe->nbarete = nbarete ;
    graphe->listearete = init_arete(graphe->listearete,nbnoeuds,nbarete);


    return graphe;
}*/



part_t* graphmini(graphe_t* g){
    part_t* p = initialisation(g->nbnoeuds);
    int j = 0;
    // for(j =0 ; j < g->nbnoeuds ; j++)
    // {
    //     printf("$ %d $\n",p->graphere[j]);
    // }
    
    for(j=0;j<(g->nbnoeuds*g->nbnoeuds)/2;j++){
        if(findtop( p,g->listearete[j].deb) != findtop( p,g->listearete[j].fin) ){
            fusion(g->listearete[j].deb,g->listearete[j].fin,p);
        }
    } 
    return p;  
}

/*
 void graphmini(part_t *partition,graphe_t * graphe,arete_t *listearete)
{
     int k=0;
     int j=0;
    listearete->deb=graphe->listearete[k].deb;
     listearete->fin=graphe->listearete[k].fin;
       while(((graphe->listearete)[k].deb)!= -1)
    {
        if(findtop(partition,((graphe->listearete)[k].deb))!=findtop(partition,graphe->listearete[k].fin))
       {
            fusion(((graphe->listearete)[k].deb),((graphe->listearete)[k].fin),partition);
           ((graphe->listearete)[j].deb)=((graphe->listearete)[k].deb);
             ((graphe->listearete)[j].deb)=((graphe->listearete)[k].deb);
             j++;
            
            
         }
        k++;

        
     }
     (graphe->listearete)[j].deb=-1;
     (graphe->listearete)[j].fin=-1;
  }*/
/*
 graphe_t* Kruskal(graphe_t* graphe)
 {
     graphe_t  * graphs=NULL;
     graphs =malloc(sizeof(graphe_t));
     // graphe=init_graph(graphe,taille);
     if (graphe==NULL)
     {
         exit(0);
     }
     
     part_t* partition = initialisation(graphe->nbnoeuds);
   


     lister_partition(partition,graphe->nbnoeuds);
     printf("kjdkjned\n");
     graphmini(partition,graphe,graphs->listearete);
     printf("kjdkjned\n");
     lister_partition(partition,graphe->nbnoeuds);

    return graphs;
 }

*/


graphe_t* Kruskal(graphe_t* graphe){
   // graphe_t * arbre_couvrante = init_graph(arbre_couvrante, graphe->nbnoeuds, graphe->nbarete);
    graphe_t  * arbre_couvrante=NULL;
    arbre_couvrante=malloc(sizeof(graphe_t));
    // graphe=init_graph(graphe,taille);
    if (arbre_couvrante==NULL)
    {
        exit(0);
    }
    arbre_couvrante->nbnoeuds= graphe->nbnoeuds;
    int l=graphe->nbarete ;
    arbre_couvrante->listearete=malloc((((l+2)*(l-1))/2)*sizeof(arete_t));
    part_t * partition = initialisation(graphe->nbnoeuds);
    arbre_couvrante->nbarete = 0;
    int i;
    int j=0;
    //int deb, fin;
    //int l=graphe->nbarete;

    for(i=0; i<l; i++){
       // deb = graphe.listearete[i].deb;
       //fin = graphe.listearete[i].fin;
        //poids = graphe.table_arretes[i].poids;

        if (findtop(partition, graphe->listearete[i].deb) != findtop(partition, graphe->listearete[i].fin)){
        
            fusion(graphe->listearete[i].deb, graphe->listearete[i].fin, partition);
            arbre_couvrante->listearete[j] = graphe->listearete[i];
          //  arbre_couvrante->listearete[j].fin = graphe->listearete[i].fin;
            j++;
            (arbre_couvrante->nbarete)++;
            //ajouter_arrete_graphe(noeud1, noeud2, poids, &arbre_cou);
        }
      
        
}
    return arbre_couvrante;
}
/*graphe_t* Kruskal(graphe_t* g){
    part_t* p1 = initialisation(g->nbnoeuds);
    int l=g->nbnoeuds;

    graphe_t* arbre_couvrante = malloc(sizeof(graphe_t));
    arbre_couvrante->listearete = malloc(sizeof(arete_t)*((l+2)*(l-1))/2);
    arbre_couvrante->nbnoeuds = g->nbnoeuds;
    printf("debut %d \n",l);
    
    int i,j=0;
    for(i = 0; i< g->nbnoeuds ; i++){
        printf(" arete %d \n",g->listearete[i].deb);
        if (findtop(p1, g->listearete[i].deb) != findtop(p1, g->listearete[i].fin)){
            arbre_couvrante->listearete[j].deb = g->listearete[i].deb;
            arbre_couvrante->listearete[j].fin = g->listearete[i].fin;
            j++;
            printf("suite \n");
            fusion(g->listearete[i].deb,g->listearete[i].fin,p1);

        }
        printf("i=%d\n",i);
    }
    // free(p1->pere);
    // free(p1->hauteur);
    // free(p1);
    return arbre_couvrante;
}
*/
// dot -Tpng graph.gv -o file.png && sxiv file.png
void echange(arete_t * ar1,arete_t * ar2)
{
    /*
    arete_t  sauv ;
    sauv.deb = ar1->deb;
    sauv.deb = ar1->fin;
    sauv.distance = ar1->distance;

    ar1->deb = ar2->deb;
    ar1->fin = ar2->fin;
    ar1->distance = ar2->distance;

    ar2->deb = sauv.deb;
    ar2->fin = sauv.fin;
    ar2->distance = sauv.distance;
     */
    arete_t* e = malloc(sizeof(arete_t));
    *e = *ar1;
    *ar1 = *ar2 ;
    *ar2 = *e;
    free(e);


}


void Fisher(graphe_t * graphe)
{
    srand(time(NULL));
    // int l=graphe->nbnoeuds;
    int j=0;
    for (int i=1; i<graphe->nbarete;i++)
    {
        j= rand() % i;
        //printf("echange %d %d \n",i,j);
        echange (&(graphe->listearete[i]),&(graphe->listearete[j]));
        printf("echange %d %d \n",i,j);
    }
    printf("fin \n");
}


graphe_t * gengraph(int ligne, int colonne)
{
        graphe_t  * graphe=NULL;
        graphe=malloc(sizeof(graphe_t));
        // graphe=init_graph(graphe,taille);
        if (graphe==NULL)
        {
            exit(0);
        }
        graphe->nbnoeuds=ligne*colonne;
        int l=graphe->nbnoeuds ;
        graphe->nbarete = (l*(l-1))/2;
        
        graphe->listearete=malloc((graphe->nbarete)*sizeof(arete_t));
        int k=0;
        for( int i= 0; i< ligne-1;i++)
        {
            for(int j=0; j<colonne-1; j++)
            {
                graphe->listearete[k].deb = i + j*colonne;
                graphe->listearete[k].fin = i +1 +j*colonne;
                graphe->listearete[k].distance=1;
                k++;
                graphe->listearete[k].deb=j*colonne + i;
                graphe->listearete[k].fin=i+(1 +j)* colonne;
                graphe->listearete[k].distance=1;
                k++;

            }
        
        }
        
        for(int i=0 ; i< colonne-1 ;i++)
            {
                graphe->listearete[k].deb=(ligne-1)+i*colonne ;
                graphe->listearete[k].fin=(ligne-1)+colonne*(i+1);
                graphe->listearete[k].distance=1;
                k++;
            }

        for(int i=0 ; i<ligne-1;i++)
            {
                graphe->listearete[k].deb=i+(colonne-1)*colonne;
                graphe->listearete[k].fin=i+1+ colonne*(colonne-1);
                graphe->listearete[k].distance=1;
                k++;
            }

            // graphe->listearete[k].deb = -1;
            // graphe->listearete[k].fin = -1;


            return graphe;
}
void free_graph(graphe_t* g){
    free(g->listearete);
    free(g);
}
void print_graph(graphe_t* g){
    printf("%d ", g->nbnoeuds);
    
    int i = 0;
    for(i = 0;i< ((g->nbnoeuds + 2)*(g->nbnoeuds - 1)/2);i++){
        printf("(%d , %d ,%d)\n",g->listearete[i].deb,g->listearete[i].fin,g->listearete[i].distance);
    }

}
void afficher_graphiz(graphe_t *graphe,const char* nom_fichier)
{
 FILE *fichier = fopen(nom_fichier, "w");
 if (fichier == NULL) exit(EXIT_FAILURE);

 fputs("graph G {\n", fichier);
    for (int i = 0; i < graphe->nbnoeuds; i++)
  {
     fprintf(fichier, "\t%d ;\n", i);
 }
 for (int i = 0; i < graphe->nbarete; i++)
 {
    if (graphe->listearete[i].deb != graphe->listearete[i].fin)
    {
        fprintf(fichier, "\t%d -- %d [label = %d];\n", graphe->listearete[i].deb, graphe->listearete[i].fin, graphe->listearete[i].distance);
    }
 }
 fputs("}", fichier);
 fclose(fichier);
}





