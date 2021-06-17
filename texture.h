#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <bits/sigaction.h>
void end_sdl(char ok,char const* msg,SDL_Window* window,SDL_Renderer* renderer);
void play_texture1(SDL_Texture * texture,SDL_Window *window,SDL_Renderer * renderer);
SDL_Texture* load_texture_from_image(char  *  file_image_name, SDL_Window *window, SDL_Renderer *renderer );
void play_with_texture_2(SDL_Texture* my_texture,SDL_Window* window,SDL_Renderer* renderer) ;
void play_with_texture_3(SDL_Texture* my_texture,SDL_Window* window,SDL_Renderer* renderer) ;
//void play_with_texture_4(SDL_Texture* my_texture,SDL_Window* window,SDL_Renderer* renderer);
void play_with_texture_5(SDL_Texture *bg_texture,SDL_Texture *my_texture,SDL_Window *window,SDL_Renderer *renderer);
void play_with_texture_1_1(SDL_Texture * texture,SDL_Window *window,SDL_Renderer * renderer);
void play_with_texture_4(SDL_Texture* my_texture,SDL_Texture * texture2,SDL_Window* window,SDL_Renderer* renderer) ; //autre version de play-with 4 afin de garder la fenetre fixe background