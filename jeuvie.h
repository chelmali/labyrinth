#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
void end_sdl(char ok,char const* msg,SDL_Window* window,SDL_Renderer* renderer);
void drawgrille(SDL_Renderer * renderer);
void drawtraits(SDL_Renderer *renderer);
void drawrectangle(SDL_Renderer* renderer,int x,int y,int height,int width);
void to_white_rectangle(SDL_Renderer* renderer,int x,int y,int height,int width);