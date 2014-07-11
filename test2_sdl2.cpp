#include "SDL.h"
#include "SDL_opengl.h"
#include <stdio.h>

int main(int argc, char** argv)
{

  SDL_Window *window;        // Declare a pointer to an SDL_Window
  int i,len;
  char ar[10] ="abcdefg";

  SDL_Init(SDL_INIT_VIDEO);   // Initialize SDL2

  // Create an application window with the following settings:
  window = SDL_CreateWindow( 
    "An SDL2 window",                  //    window title
    SDL_WINDOWPOS_UNDEFINED,           //    initial x position
    SDL_WINDOWPOS_UNDEFINED,           //    initial y position
    640,                               //    width, in pixels
    480,                               //    height, in pixels
    SDL_WINDOW_OPENGL                  //    flags - see below
  );
  
  // Check that the window was successfully made
  if(window==NULL){   
    // In the event that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }
  
  glcolor3f(150,150,150);
  glRasterPos2f(50,50);
  len = (int)strlen(ar);
  for(i=0;i<len;i++)
  {
     glutBitmapCharacter(font,ar[i]);
  }
  
  
  
  // The window is open: enter program loop (see SDL_PollEvent)

  SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example
  
  // Close and destroy the window
  SDL_DestroyWindow(window); 
   
  // Clean up
  SDL_Quit(); 
  return 0;   
 
}
