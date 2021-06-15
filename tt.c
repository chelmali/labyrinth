#include <SDL2/SDL.h>

#include <math.h>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <time.h>


/*********************************************************************************************************************/

/*                              Programme d'exemple de création de rendu + dessin                                    */

/*********************************************************************************************************************/


void end_sdl(char ok,                                                 // fin normale : ok = 0 ; anormale ok = 1

                  char const* msg,                                    // message à afficher

                  SDL_Window* window,                                 // fenêtre à fermer

                  SDL_Renderer* renderer) {                           // renderer à fermer

  char msg_formated[255];

  int l;


  if (!ok) {

         strncpy(msg_formated, msg, 250);

         l = strlen(msg_formated);

         strcpy(msg_formated + l, " : %s\n");


         SDL_Log(msg_formated, SDL_GetError());

  }


  if (renderer != NULL) SDL_DestroyRenderer(renderer);

  if (window != NULL)   SDL_DestroyWindow(window);


  SDL_Quit();


  if (!ok) {

         exit(EXIT_FAILURE);

  }

}

                                                               

 

  


   int a;

   int b;

   void draw(SDL_Renderer* renderer, int a, int b) {

   

       // Je pense que vous allez faire moins laid :)

   SDL_Rect rectangle;

   SDL_SetRenderDrawColor(renderer,

                               150,100, 110,                               // mode Red, Green, Blue (tous dans 0..255)

                              255);

                                // 0 = transparent ; 255 = opaque

  

  rectangle.x = a;                                                    // x haut gauche du rectangle

  rectangle.y =b;                                                    // y haut gauche du rectangle

  rectangle.w = 100;                                                  // sa largeur (w = width)

  rectangle.h = 100;                                          // sa hauteur (h = height)

 //SDL_DestroyRenderer(renderer);

  SDL_RenderFillRect(renderer, &rectangle);


  SDL_SetRenderDrawColor(renderer, 0 , 0, 0, 255);

  SDL_RenderDrawLine(renderer,

                          0, 0,                                       // x,y du point de la première extrémité

                          400, 400);

                               // x,y seconde extrémité

 //SDL_DestroyRenderer(renderer);


  }


  /* tracer un cercle n'est en fait pas trivial, voilà le résultat sans algo intelligent ... */

 /* for (float angle = 0; angle < 2 * M_PI; angle += M_PI / 4000) {

         SDL_SetRenderDrawColor(renderer,

                                (cos(angle * 2) + 1) * 255 / 2,       // quantité de Rouge

                                (cos(angle * 5) + 1) * 255 / 2,       //          de vert

                                (cos(angle) + 1) * 255 / 2,           //          de bleu

                                255);                                 // opaque

         SDL_RenderDrawPoint(renderer,

                             200 + 100 * cos(angle),                  // coordonnée en x

                             200 + 150 * sin(angle));                 //            en y

  }*/




int main(int argc, char** argv) {

  (void)argc;

  (void)argv;

   

  SDL_Window* window = NULL;

  SDL_Renderer* renderer = NULL;


  SDL_DisplayMode screen;


/*********************************************************************************************************************/

/*                         Initialisation de la SDL  + gestion de l'échec possible                                   */

  if (SDL_Init(SDL_INIT_VIDEO) != 0) end_sdl(0, "ERROR SDL INIT", window, renderer);


  SDL_GetCurrentDisplayMode(0, &screen);

  printf("Résolution écran\n\tw : %d\n\th : %d\n", screen.w,

              screen.h);


  /* Création de la fenêtre */

  window = SDL_CreateWindow("Premier dessin",

                            SDL_WINDOWPOS_CENTERED,

                            SDL_WINDOWPOS_CENTERED, screen.w * 0.66,

                            screen.h * 0.66,

                            SDL_WINDOW_OPENGL);

  if (window == NULL) end_sdl(0, "ERROR WINDOW CREATION", window, renderer);


  /* Création du renderer */

  renderer = SDL_CreateRenderer(

           window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (renderer == NULL) end_sdl(0, "ERROR RENDERER CREATION", window, renderer);


  /*********************************************************************************************************************/

  /*                                    On dessine dans le renderer                                                   */


    int g;

    int h;

    int i;

   

    srand(time(NULL) );

    for(i=0;i<1000;i++)

  {

   printf("ok");

   h= rand() % 100;

   g= rand() % 500;

   i+=20;

  draw(renderer, h, g);                                                    // appel de la fonction qui crée l'image

  SDL_RenderPresent(renderer);

      SDL_RenderClear(renderer);// affichage

  SDL_Delay(500);    }                                                  // Pause exprimée en ms

  //if ( i>=700)

  /*********************************************************************************************************************/

  /* on referme proprement la SDL */

  end_sdl(1, "Normal ending", window, renderer);

  return EXIT_SUCCESS;

}