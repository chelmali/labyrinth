#ifndef DFS_
#define DFS_



typedef struct point{
    int num;
    int* fils;
} point_t;


int* DFS(graphe_t labyrinthe, int depart);
void ssDFS(graphe_t labyrinthe, point_t* points, int point, int* visited, int* parcours, int* l);
void rechercheFilsNoeud(point_t* points,int point,graphe_t labyrinthe);
void liberer_points(point_t* points, int taille);




#endif
