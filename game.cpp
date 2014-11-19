#include <iostream>
#include "game.h"

using namespace std;

Game::Game(){
SDL_Keycode ret_val;
init_screen();

team[0].setteamcomputer1();
team[1].setteamcomputer2();

firstscreen();
ret_val=secondscreen();

if(ret_val == SDLK_y)
cout << "yyyy";
else if(ret_val == SDLK_n)
cout << "nnnnnn";
else
cout << ret_val << "what\n";

display_scoreboard(team[0],team[1]);
toss_change=toss_screen(team);

destroy_screen();

//cout << a->team[0].innings[1].player[4].getname();

cout << "\nhello\n";


}


