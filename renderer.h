#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
//void draw(SDL_Renderer* renderer) ;
void to_black_cercle(SDL_Renderer *renderer,int rayon,int abscissecentre,int ordonneecentre);
void to_black_rectangle(SDL_Renderer* renderer,int x,int y,int height,int width);
void drawcercle(SDL_Renderer *renderer,int rayon,int abscissecentre,int ordonneecentre);
void drawrectangle(SDL_Renderer* renderer,int x,int y,int height,int width,int color);
//void draw(SDL_Renderer* renderer,int x,int y,int height,int width,int color);
void end_sdl(char ok,                                                 // fin normale : ok = 0 ; anormale ok = 1
                  char const* msg,                                    // message à afficher
                  SDL_Window* window,                                 // fenêtre à fermer
                  SDL_Renderer* renderer);