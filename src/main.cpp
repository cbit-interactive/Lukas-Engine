#include "utils/LoggingUtil.hpp"
#include "settings.hpp"
#include "include/SDL2/SDL.h"
//#include "localisation.hpp"

#include <stdio.h>
#include <sstream>
#include <string>

int main(int argc, char* argv[]){
    Log::clearLog();
    SettingsReader sR("settings.txt");

    int langIDstr = sR.getSetting("language"); // Get settings

    //stringstream langID; // lang id getting converting to string!
    //langID << langIDstr;
    
    //Locale::setLanguage(langID.str()); // Set the default language (en)

    int WIDTH = sR.getSetting("width");
    int HEIGHT = sR.getSetting("height");

    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    
    Log::l(ErrorP, "Error testing!");

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        Log::l(ErrorP, "COULD NOT INITIALISE SDL");
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else {

        Log::l(TraceP, "SDL HAS BEEN INITIALISED");
        window = SDL_CreateWindow("Lukas Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        if( window == NULL )
        {
            Log::l(ErrorP, "Window could not be created");
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
    Log::l(TraceP, "SDL SHUTDOWN");
    return 0;
}