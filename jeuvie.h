#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
void end_sdl(char ok,char const* msg,SDL_Window* window,SDL_Renderer* renderer);
void drawgrille(SDL_Renderer * renderer);
void drawtraits(SDL_Renderer *renderer);
void drawrectangle(SDL_Renderer* renderer,int x,int y,int height,int width);
void initialisermatrice(int mat[10][10]);
void affichermatrice(int mat[10][10]);
int nbvoisins(int mat[10][10],int i,int j);
void regle(int mat[10][10],int i,int j,int mat2[10][10]);
void nouveauemplaire(int mat[10][10],int mat2[10][10]);