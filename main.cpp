

#include <stdio.h>
#include <iostream>

#include <SDL.h>


int main( int argc, char* args[] )
{
    SDL_Window* mainWindow = NULL;
    SDL_Surface* screen = NULL;
    SDL_Event event;
    bool done = false;
    mainWindow = SDL_CreateWindow( "SDL basic test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1980, 1080, SDL_WINDOW_FULLSCREEN );
    screen = SDL_GetWindowSurface( mainWindow );

    std::cout<<"Hello World SDL!!!!!"<<std::endl;

    while(!done)
    {
        while(SDL_PollEvent(&event)!=0)
        {
            if(event.type == SDL_KEYDOWN )
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        done = true;
                }
            }
        }
        SDL_FillRect( screen, NULL, SDL_MapRGB( screen->format, 0xF0, 0x00, 0x00 ) );
        SDL_UpdateWindowSurface( mainWindow );
    }

    SDL_DestroyWindow( mainWindow );
    SDL_Quit();

    return 0;
}
