#ifndef sdl_h
#define sdl_h


#include "lab.h"

void end_sdl(char ok, // fin normale : ok = 0 ; anormale ok = 1
 char const* msg, // message à afficher
 SDL_Window* window, // fenêtre à fermer
            SDL_Renderer* renderer);
void grille (SDL_Renderer* renderer);
void drawrectangle(SDL_Renderer* r,int k,int l,SDL_Color couleur);
void draw_lab(SDL_Renderer* renderer,graphe_t* arbre_couvrante);


#endif

