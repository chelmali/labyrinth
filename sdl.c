
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include "lab.h"
#include "sdl.h"
#include "partition.h"
#include "DFS.h"

#define NBR_CELLULE 10
#define TAILLE_CELLULE 80
#define L_ECRAN (NBR_CELLULE * TAILLE_CELLULE)







void end_sdl(char ok,            // fin normale : ok = 0 ; anormale ok = 1
             char const *msg,    // message à afficher
             SDL_Window *window, // fenêtre à fermer
             SDL_Renderer *renderer)
{ // renderer à fermer
    char msg_formated[255];
    int l;

    if (!ok)
    {
        strncpy(msg_formated, msg, 250);
        l = strlen(msg_formated);
        strcpy(msg_formated + l, " : %s\n");

        SDL_Log(msg_formated, SDL_GetError());
    }

    if (renderer != NULL)
        SDL_DestroyRenderer(renderer);
    if (window != NULL)
        SDL_DestroyWindow(window);

    SDL_Quit();

    if (!ok)
    {
        exit(EXIT_FAILURE);
    }
}

void grille(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < NBR_CELLULE + 1; i++)
    {
        SDL_RenderDrawLine(renderer, i * TAILLE_CELLULE, 0,
                           i * TAILLE_CELLULE, L_ECRAN);
    }
    for (int i = 0; i < NBR_CELLULE + 1; i++)
    {
        SDL_RenderDrawLine(renderer, 0, i * TAILLE_CELLULE,
                           L_ECRAN, i * TAILLE_CELLULE);
    }
}

void drawrectangle(SDL_Renderer *r, int k, int l, SDL_Color couleur)
{
    SDL_Rect rectangle;
    SDL_SetRenderDrawColor(r, couleur.r, couleur.g, couleur.b, couleur.a);
    rectangle.x = (k)*TAILLE_CELLULE;
    rectangle.y = (l)*TAILLE_CELLULE;
    rectangle.w = TAILLE_CELLULE;
    rectangle.h = TAILLE_CELLULE;
    SDL_RenderFillRect(r, &rectangle);
}

void draw_lab(SDL_Renderer *renderer, graphe_t *arbre_couvrante)
{
    int i;
    for (i = 0; i < arbre_couvrante->nbarete; i++)
    {
        int d, f;
        d = arbre_couvrante->listearete[i].deb;
        f = arbre_couvrante->listearete[i].fin;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        if ((f == d + 1))
        {
            SDL_RenderDrawLine(renderer, (f % NBR_CELLULE) * TAILLE_CELLULE, (f / NBR_CELLULE) * TAILLE_CELLULE,
                               (f % NBR_CELLULE) * TAILLE_CELLULE, ((f / NBR_CELLULE) + 1) * TAILLE_CELLULE);
        }
        if (d + NBR_CELLULE == f)
        {
            SDL_RenderDrawLine(renderer, (f % NBR_CELLULE) * TAILLE_CELLULE, (f / NBR_CELLULE) * TAILLE_CELLULE,
                               ((f % NBR_CELLULE) + 1) * TAILLE_CELLULE, (f / NBR_CELLULE) * TAILLE_CELLULE);
        }
    }
}

SDL_Texture *load_texture_from_image(char *image_source, SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_Surface *my_image = NULL;   // Variable de passage
    SDL_Texture *my_texture = NULL; // La texture

    my_image = IMG_Load(image_source); // Chargement de l'image dans la surface
                                       // image=SDL_LoadBMP(image_source); fonction standard de la SDL, uniquement possible si l'image est au format bmp
    if (my_image == NULL)
        end_sdl(0, "Chargement de l'image impossible", window, renderer);

    my_texture = SDL_CreateTextureFromSurface(renderer, my_image); // Chargement de l'image de la surface vers la texture

    SDL_FreeSurface(my_image); // la SDL_Surface ne sert que comme élément transitoire
    if (my_texture == NULL)
        end_sdl(0, "Echec de la transformation de la surface en texture", window, renderer);

    return my_texture;
}

void laisser_trace(int placeX, int placeY, SDL_Texture *trace, SDL_Renderer* renderer)
{
    SDL_Rect source = {0}, destination = {0};

    SDL_QueryTexture(trace, NULL, NULL, &source.w, &source.h);

    destination.w = TAILLE_CELLULE * 0.5;
    destination.h = TAILLE_CELLULE * 0.5;
    destination.x = placeX;
    destination.y = placeY;

    SDL_RenderCopy(renderer, trace, &source, &destination);

}

int main()
{

    //srand(time(NULL));
    graphe_t *g = gengraph(NBR_CELLULE, NBR_CELLULE);
    graphe_t *arbre_couvrante = NULL;
    afficher_graphiz(g, "graph.dot");
    //part_t* p = partitionner_graph(g);
    Fisher(g);
    arbre_couvrante = Kruskal(g);
    afficher_graphiz(arbre_couvrante, "compo_con.dot");

    SDL_Rect rectangle;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Error : SDL initialisation - %s\n", SDL_GetError());
    }

    window = SDL_CreateWindow(
        "MAZE",
        50, 50,
        L_ECRAN + 1, L_ECRAN + 1,
        SDL_WINDOW_RESIZABLE); // redimensionnable

    if (window == NULL)
    {
        SDL_Log("Error : SDL window 1 creation - %s\n", SDL_GetError()); // échec de la création de la fenêtre
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL)
    {
        SDL_DestroyWindow(window);
        SDL_Log("Error : SDL window 1 creation - %s\n", SDL_GetError()); // échec de la création de la fenêtre
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    SDL_Rect sourceA = {0}, destinationA = {0};
    SDL_Texture *player = load_texture_from_image("sakhra.png", window, renderer);
    SDL_QueryTexture(player, NULL, NULL, &sourceA.w, &sourceA.h);

    destinationA.w = 40;
    destinationA.h = 40;

    //Gestion des événements:
    SDL_bool program_on = SDL_TRUE;

    while (program_on == 1)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {

            switch (event.type)
            {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_q:
                    program_on = 0;
                    break;

                default:
                    break;
                }
                break;

            case SDL_QUIT:
                program_on = 0;
                break;

            default:
                break;
            }
        }

        //On utilise DFS pour determiner le chemin:
        int *chemin = DFS(*arbre_couvrante, 0);

        int i = 0;
        while ((i < arbre_couvrante->nbnoeuds) && (program_on == 1))
        {
            while (SDL_PollEvent(&event))
            {

                switch (event.type)
                {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_q:
                        program_on = 0;
                        break;

                    default:
                        break;
                    }
                    break;

                case SDL_QUIT:
                    program_on = 0;
                    break;

                default:
                    break;
                }
            }

            //La couleur désignée pour tracer les lignes (si nécessaire):
            /*SDL_SetRenderDrawColor(renderer, 200, 70, 20, 255);*/

            //Nettoyage:
            SDL_RenderClear(renderer);

            //Mouvement des aliens:
            destinationA.x = (chemin[i] % NBR_CELLULE) * TAILLE_CELLULE + (TAILLE_CELLULE - destinationA.w) / 2;
            destinationA.y = (chemin[i] / NBR_CELLULE) * TAILLE_CELLULE + (TAILLE_CELLULE - destinationA.h) / 2;

            //Affichage de L'arrière plan:
            //afficher_arriere_plan(fond, window, renderer);

            //Affichage du labyrinthe:
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            rectangle.x = 0;
            rectangle.y = 0;
            rectangle.w = L_ECRAN;
            rectangle.h = L_ECRAN;
            SDL_RenderFillRect(renderer, &rectangle);

            grille(renderer);

            /*Creation de graphe et d'arbre couvrante*/

            draw_lab(renderer, arbre_couvrante);

            //On dessine les murs:
            //dessiner_murs(labyrinthe, p, capacite, renderer, window);

            //Laisser les traces:
            int k = 0;

            while (k < i)
            {
                int destinationX = (chemin[k] % NBR_CELLULE) * TAILLE_CELLULE + (TAILLE_CELLULE - destinationA.w) / 2;
                int destinationY = (chemin[k] / NBR_CELLULE) * TAILLE_CELLULE + (TAILLE_CELLULE - destinationA.w) / 2;
                laisser_trace(destinationX, destinationY, player, renderer);
                k++;
            }

            //Affichage des aliens:
            SDL_RenderCopy(renderer, player, &sourceA, &destinationA);

            SDL_RenderPresent(renderer); // Affichage de la nouvelle image
            SDL_Delay(200);

            i++;
        }
        free(chemin);

        program_on = 0;
    }

    /*SDL_RenderPresent(renderer);
    SDL_Delay(5000);

    free_graph(g);
    free_graph(arbre_couvrante);
    free(p->arbre);
 free(p->hauteur);
 free(p);*/
    //SDL_DestroyWindow(window);
    //SDL_Quit();
    return 0;
}


