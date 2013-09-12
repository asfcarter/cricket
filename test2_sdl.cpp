#include <cstdlib>
#include "SDL.h"

int main(int argc, char** argv)
{
    // Initialize SDL, using only the video library.
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
            exit(1); 
    }
    atexit(SDL_Quit); //clean up the library when you are done with it.
    
    // Create a screen surface, and set the video mode 
    SDL_Surface *screen;
    screen = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE);
    if ( screen == NULL ) {
       fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
       exit(1);
    }

    SDL_Event event;
    bool running = true;
    // Loop forever, waiting for the user to quit
    while(running){
       while ( SDL_PollEvent(&event) ) {
          switch (event.type) {
             case SDL_KEYDOWN:
             case SDL_KEYUP:
                if (event.key.type == SDL_KEYUP)
                   printf("RELEASED: ");
                else
                   printf("PRESSED: ");
                 printf( "%s\n", SDL_GetKeyName(event.key.keysym.sym));
             break;
             case SDL_MOUSEMOTION:
                printf("Mouse moved by %d,%d to (%d,%d)\n", 
                    event.motion.xrel, event.motion.yrel, event.motion.x, event.motion.y);
              break;
              case SDL_MOUSEBUTTONDOWN:
                   printf("Mouse button %d pressed at (%d,%d)\n",
                       event.button.button, event.button.x, event.button.y);
               break;
               case SDL_QUIT:
                  running = false;
               }
           }
        }

    return 0;
}
