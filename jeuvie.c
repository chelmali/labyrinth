
#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include"time.h"
#include"jeuvie.h"

int Tabsurvie[9]={0,1,1,0,0,0,0,0,0};
int TABnaissance[9]={0,0,1,0,0,0,0,0,0};
int largeur =30;
int hauteur =30;
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

int main(int argc, char** argv) {
  (void)argc;
  (void)argv;
  int mat[10][10];
  int mat2[10][10];
  int i=0;
  int j=0;
  int x=0;
  int y=0;
  SDL_bool program_launche= SDL_TRUE;
  int pause=0; 


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

  initialisermatrice(mat);
  affichermatrice(mat);
  printf("  \n%d\n",nbvoisins(mat,0,0));
  nouveauemplaire(mat,mat2);
  affichermatrice(mat);
  while(program_launche)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      switch(event.type)
      {
        case SDL_QUIT:
          program_launche=SDL_FALSE;
          break;
        case SDL_KEYDOWN:
          switch(event.key.keysym.sym)
          {
            case SDLK_q:
              program_launche=SDL_FALSE;
            // case SDLK_SPACE:
            //   pause=1;
              

            default :
              continue;

          }
        case SDL_MOUSEBUTTONDOWN:
          initialisermatrice(mat);
          

        default :
          continue ;
      }
    }
      if (pause==0)
      {
        nouveauemplaire(mat,mat2);
        affichermatrice(mat);
        SDL_SetRenderDrawColor(renderer,250,250,250,250);
        SDL_RenderClear(renderer);
        while(i<30)
      {
          while(j<30)
          {
              SDL_Rect rectangle ={x,y,largeur,hauteur};
              x=x+largeur;
              SDL_SetRenderDrawColor(renderer,0,0,0,255);
              if (mat[i][j]==0)
              {
                  SDL_RenderFillRect(renderer,&rectangle);
              }
              j++;
          }
          y=y+hauteur;
          j=0;
          x=0;
          i++;
      }
      SDL_RenderPresent(renderer);
      SDL_Delay(50);
      i=0;
      j=0;
      x=0;
      y=0;
        
      }
      // nouveauemplaire(mat,mat2);
      // affichermatrice(mat);
      // SDL_SetRenderDrawColor(renderer,250,250,250,250);
      // SDL_RenderClear(renderer);
      // while(i<30)
      // {
      //     while(j<30)
      //     {
      //         SDL_Rect rectangle ={x,y,largeur,hauteur};
      //         x=x+largeur;
      //         SDL_SetRenderDrawColor(renderer,0,0,0,255);
      //         if (mat[i][j]==0)
      //         {
      //             SDL_RenderFillRect(renderer,&rectangle);
      //         }
      //         j++;
      //     }
      //     y=y+hauteur;
      //     j=0;
      //     x=0;
      //     i++;
      // }
      // SDL_RenderPresent(renderer);
      // SDL_Delay(50);
      // i=0;
      // j=0;
      // x=0;
      // y=0;
    
  }
  return 0;


}
void initialisermatrice(int mat[10][10])
{
  srand(time(NULL));
  for (int i=0;i<10;i++)
  {
    for (int j=0;j<10;j++)
    {
      mat[i][j]=rand()%2;
    }
  }
}
void affichermatrice(int mat[10][10])
{
  for (int i=0;i<10;i++)
  {
    for (int j=0;j<10;j++)
    {
      printf("%d ",mat[i][j]);
    }
    printf("\n");
  }
}
int  nbvoisins(int mat[10][10],int i,int j)
{

  int count=0;
  for (int x=-1;x<2;x++)
  {
    for (int y=-1;y<2;y++)
    {
      count=count+mat[(i+10+x)%10][(j+y+10)%10];
    }
  }
  count-=mat[i][j];
  return count;
}
void regle(int mat[10][10],int i,int j,int mat2[10][10])
{
  int voisin;
  voisin=nbvoisins(mat,i,j);
  if (mat[i][j]==1)
  {
    mat2[i][j]=Tabsurvie[voisin];
  }
  else 
  {
    mat2[i][j]=TABnaissance[voisin];
  }
  
 
  
}
void nouveauemplaire(int mat[10][10],int mat2[10][10])
{
  for (int i=0;i<10;i++)
  {
    for (int j=0;j<10;j++)
    {
      regle(mat,i,j,mat2);
    }
  }
  for (int k=0;k<10;k++)
  {
    for (int l=0;l<10;l++)
    {
      mat[k][l]=mat2[k][l];
    }
  }
}
//gcc jeuvie.c  -Wall -Wextra  -lm -lSDL2_image -o jeu $(sdl2-config --cflags --libs)