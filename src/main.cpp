#include "utils/LoggingUtil.hpp"
#include "settings.hpp"
#include "include/SDL2/SDL.h"

#include <stdio.h>

int main(int argc, char* argv[]){
    Log::clearLog();
    SettingsReader sR("settings.txt");

    int WIDTH = sR.getSetting("width");
    int HEIGHT = sR.getSetting("height");

    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    
    Log::l(ErrorP, "Error testing!");

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        Log::l(ErrorP, "SDL could not be initalised!");
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else {

        Log::l(TraceP, "SDL has been initialised");
        window = SDL_CreateWindow("Lukas Engine Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        if( window == NULL )
        {
            Log::l(ErrorP, "Window could not be created, please check console for more data!");
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            Log::l(TraceP, "Window has been created");
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    Log::l(TraceP, "SDL has shut down!");
    return 0;
}