#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdlib.h>
#include"sdl.h"

//int creationfentre(void);
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    creationfentre();
    //creationfentre();

}
int creationfentre()
{
    SDL_Window *window1=NULL;
    SDL_Window *window2=NULL;
    if (SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        SDL_Log("ERROR :SDL INITIALISATION - %s \n",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    window1=SDL_CreateWindow("Fenetre gauche",0,0,400,300,SDL_WINDOW_RESIZABLE);
    if(window1==NULL)
    {
        SDL_Log("ERROR :SDL CREATION FENETRE 1   - %s \n",SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    window2=SDL_CreateWindow("FENETRE DROITE",400,300,500,300,0);
    if(window2==NULL)
    {
        SDL_Log("ERREUR :SDL CREATION FENETRE 2 -%s",SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    //SDL_SetWindowPosition(window1,2,4);
    //SDL_SetWindowPosition(window2,10,11);
    SDL_Delay(3000);

    SDL_DestroyWindow(window2);
    SDL_DestroyWindow(window1);
    SDL_Quit();
    return 0;
}