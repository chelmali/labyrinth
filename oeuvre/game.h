#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#define S_WIDTH 1024
#define S_HEIGHT 768

void end_sdl(char ok, char const *msg, SDL_Window *window, SDL_Renderer *renderer);
SDL_Texture *load_texture_from_image(char *file_image_name, SDL_Window *window, SDL_Renderer *renderer);
void play_with_texture_1_1(SDL_Texture *my_texture, SDL_Window *window, SDL_Renderer *renderer);
int Game(SDL_Texture *bg_texture, SDL_Texture *my_texture, SDL_Texture *my_texture2, SDL_Rect *Source2, SDL_Rect *destination2,
            SDL_Window *window, SDL_Renderer *renderer, int *intersection, int vie, int temps);
int collision(SDL_Rect *feu, SDL_Rect *joueur);
void affichage_vie(SDL_Renderer *renderer, SDL_Window *window, int vie);
void fin_jeu(SDL_Texture *bg_texture, SDL_Renderer *renderer, SDL_Window *window);