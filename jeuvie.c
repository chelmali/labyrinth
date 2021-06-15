#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
void end_sdl(char ok,char const* msg,SDL_Window* window,SDL_Renderer* renderer) {                           
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
void drawtraits(SDL_Renderer *renderer)
{
  for (int k=0;k<1500;k=k+30)
  {
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderDrawLine(renderer,k,0,k,900);
  }
  for (int l=0;l<1500;l=l+30)
  {
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderDrawLine(renderer,0,l,1500,l);
  }
}
void drawgrille(SDL_Renderer *renderer)
{
    SDL_Rect rectangle;
    rectangle.x=0;
    rectangle.y=0;
    rectangle.w=1200;
    rectangle.h=1200;
    SDL_SetRenderDrawColor(renderer,237,237,237,255);
    SDL_RenderFillRect(renderer,&rectangle);
    for (int k=0;k<500;k=k+50)
    {
      SDL_RenderDrawLine(renderer,100+k,0,100+k,600);
    }
    
}
void drawrectangle(SDL_Renderer* renderer,int x,int y,int height,int width)
{
    SDL_Rect rectangle;                                             

    SDL_SetRenderDrawColor(renderer,0,0,0,255);                                                              
    rectangle.x = x;                                                    
    rectangle.y = y;                                                    
    rectangle.w = width;                                                 
    rectangle.h = height;                           
    SDL_RenderFillRect(renderer, &rectangle);
    
}
void to_white_rectangle(SDL_Renderer* renderer,int x,int y,int height,int width)
{
    SDL_Rect rectangle;                                             

    SDL_SetRenderDrawColor(renderer,255,255,255,255);  
                                                    
    rectangle.x = x;                                                    
    rectangle.y = y;                                                    
    rectangle.w = width;                                               
    rectangle.h = height;                                               

    SDL_RenderFillRect(renderer, &rectangle);
    SDL_RenderClear(renderer);
}
int main(int argc, char** argv) {
  (void)argc;
  (void)argv;
  //int offset3=0;
  //int offset4=0;

  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;

  SDL_DisplayMode screen;
  if (SDL_Init(SDL_INIT_VIDEO) != 0) end_sdl(0, "ERROR SDL INIT", window, renderer);

  SDL_GetCurrentDisplayMode(0, &screen);
  printf("Résolution écran\n\tw : %d\n\th : %d\n", screen.w,
              screen.h);
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
  drawgrille(renderer);
  drawtraits(renderer);
  //drawrectangle(renderer,0,0,30,30);
  /*for (int j=0;j<20;j++)
  {
    drawrectangle(renderer,offset3,offset4,30,30);
    SDL_RenderPresent(renderer); 
    to_white_rectangle(renderer,offset3,offset4,30,30); 
    SDL_Delay(500);  
    offset3=offset3+30;
    offset4=offset4+30;
  }*/
  SDL_RenderPresent(renderer);
  SDL_Delay(2000);

}

