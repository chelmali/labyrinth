#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
//#include<time.h>
#include"renderer.h"


/*afficher  l'erreur  ayant lieu lors de la création d'une fenetre ou d'un  rendu
    ok:booleen qui vaut vrai si il y a eu une erreur
    msg:message à afficher
    window:fenetre à fermer
    renderer:rendu à fermer*/
void end_sdl(char ok,                                                 
                  char const* msg,                                    
                  SDL_Window* window,                                 
                  SDL_Renderer* renderer) {                           
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
int main(int argc, char** argv) {
  (void)argc;
  (void)argv;
  int color=0;
  int offset1=0;
  int offset2=0;
  int offset3=1200;
  int offset4=0;
  int offset5=0;
  int offset6=0;

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
  window = SDL_CreateWindow("Animation",
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
  /*   
                                    On dessine dans le renderer
         //QUE LES RECTANGLES                                                                              */
  for (int i=0;i<40;i++)
  {
    drawrectangle(renderer,offset1,offset2,10,30,color);                                                     // appel de la fonction qui crée l'image  
    SDL_RenderPresent(renderer);  
    to_black_rectangle(renderer,offset1,offset2,10,30);                                 // affichage
    SDL_Delay(50); 
    color=color+100;   
    offset1=offset1+30; 
    offset2=offset2+10;                                             // Pause exprimée en ms
  }
  for (int j=0;j<40;j++)
  {
    drawrectangle(renderer,offset3,offset4,10,30,color);
    SDL_RenderPresent(renderer); 
    to_black_rectangle(renderer,offset3,offset4,10,30); 
    SDL_Delay(50); 
    color=color+100; 
    offset3=offset3-30;
    offset4=offset4+10;
  }
  for (int d=0;d<40;d++)
  {
    drawrectangle(renderer,600,offset5,10,30,color);
    SDL_RenderPresent(renderer); 
    to_black_rectangle(renderer,600,offset5,10,30); 
    SDL_Delay(50); 
    color=color+100; 
    offset5=offset5+10;
  }
  for (int l=0;l<40;l++)
  {
    drawrectangle(renderer,offset6,200,10,30,color);
    SDL_RenderPresent(renderer); 
    to_black_rectangle(renderer,offset6,200,10,30); 
    SDL_Delay(50); 
    color=color+100; 
    offset6=offset6+30;
  }
  //QUE LES CERCLEES

  for (int k=0;k<4*100;k=k+100)
  {
    drawcercle(renderer,200,100+k,150+k);
    SDL_RenderPresent(renderer);
    to_black_cercle(renderer,200,100+k,150+k);
    SDL_Delay(500);

  }
  for (int k=0;k<4*100;k=k+100)
  {
    drawcercle(renderer,800,50+k,200+k);
    SDL_RenderPresent(renderer);
    to_black_cercle(renderer,800,50+k,200+k);
    SDL_Delay(500);

  }
  
 
  /*********************************************************************************************************************/
  /* on referme proprement la SDL */
  end_sdl(1, "Normal ending", window, renderer);
  return EXIT_SUCCESS;
}
void drawrectangle(SDL_Renderer* renderer,int x,int y,int height,int width,int color)
{
    SDL_Rect rectangle;                                             

    SDL_SetRenderDrawColor(renderer,                                
                                30+color, 60+color, 100+color,                               // mode Red, Green, Blue (tous dans 0..255)
                                255);      
    //SDL_RenderClear(renderer);                                                         // 0 = transparent ; 255 = opaque
    rectangle.x = x;                                                    // x haut gauche du rectangle
    rectangle.y = y;                                                    // y haut gauche du rectangle
    rectangle.w = width;                                                  // sa largeur (w = width)
    rectangle.h = height;                                                  // sa hauteur (h = height)

    SDL_RenderFillRect(renderer, &rectangle);
    
}
void drawcercle(SDL_Renderer *renderer,int rayon,int abscissecentre,int ordonneecentre)
{
    for (float angle =0;angle<2 * M_PI;angle=angle+M_PI/4000)
    {
      SDL_SetRenderDrawColor(renderer,237,60+angle,100+angle,255);
      SDL_RenderDrawPoint(renderer, rayon + abscissecentre * cos(angle),rayon + ordonneecentre * sin(angle));

                             
    } 
}
void to_black_rectangle(SDL_Renderer* renderer,int x,int y,int height,int width)
{
      SDL_Rect rectangle;                                             

    SDL_SetRenderDrawColor(renderer,0,0,0,255);  
                                                    
    rectangle.x = x;                                                    
    rectangle.y = y;                                                    
    rectangle.w = width;                                               
    rectangle.h = height;                                               

    SDL_RenderFillRect(renderer, &rectangle);
    SDL_RenderClear(renderer);
}
void to_black_cercle(SDL_Renderer *renderer,int rayon,int abscissecentre,int ordonneecentre)
{
    for (float angle =0;angle<2 * M_PI;angle=angle+M_PI/4000)
    {
      SDL_SetRenderDrawColor(renderer,0,0,0,255);
      SDL_RenderDrawPoint(renderer, rayon + abscissecentre * cos(angle),rayon + ordonneecentre * sin(angle));

                             
    } 
    SDL_RenderClear(renderer);
}