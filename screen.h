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
      void display_scoreboard(Team *batting, Team *bowling, int innings_number);
      void display_new_bowler(Team *batting, Team *bowling, int innings_number);
      void display_new_batsman(Team *batting, Team *bowling, int innings_number);

      void display_ball_field(Team *batting, Team *bowling, int innings_num);
      bool play_again();
      bool match_summary_screen(Team *batting, Team *bowling, int innings_number, int follow_on);
      void shot(int shot_number, int *ballx, int *bally);
      bool follow_on_decision(Team *batting, Team *bowling);
      int closestfielder(Team *team, int ballx, int bally);
      int closestwicket(int ballx, int bally);
      void run(Team *team, int innings_num, int extratag, int closest_field, int ballx, int bally);

      void boundary();
      void wickets(int i,int j);
      void brokenwicket(int i,int j);
      void batsmanready();
      void batsmannonstrike(int i,int j);
      void batsmanshot(int stumped);
      void wicketkeeper(int i,int j);
      void fielderready(int i,int j,int selected);
      void fieldergo(int i,int j);
      void fielderrun(int i,int j);
      void bowlerbowled(int i,int j);
      void bowler(int i,int j);
      void spacebar_to_continue(int i, int j, SDL_Color text_colour, int text_size);

      void get_batsman_number(int i, int j, SDL_Color text_colour, int text_size);

      void arc(int x,int y,int start_angle,int end_angle,int radius);
      int destroy_screen();
};

#endif
