#ifndef SCREEN_H
#define SCREEN_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "team.h"

#define BLACK (SDL_Color){0,0,0,0}
#define WHITE (SDL_Color){255,255,255,255}
#define YELLOW (SDL_Color){255,255,0,255}
#define GREEN (SDL_Color){0,255,0,255}
#define RED (SDL_Color){255,0,0,255}
#define BLUE (SDL_Color){0,0,255,255}
#define GREY (SDL_Color){100,155,155,255}
#define CYAN (SDL_Color){80,155,155,255}

class Screen
{
private:
	SDL_Renderer *renderer;
	SDL_Window *window;

public:
      
      Screen() {};
      
      int init_screen();
      int firstscreen();
      SDL_Keycode secondscreen();
      bool toss_screen(Team team[2]);
      void display_scoreboard(Team batting, Team bowling);
      int destroy_screen();
};

#endif
