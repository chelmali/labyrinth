#ifndef TT_H
#define TT_H
#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include"time.h"
void end_sdl(char ok,char const* msg, SDL_Window* window,SDL_Renderer* renderer);
 void draw(SDL_Renderer* renderer, int a, int b);

 #endif