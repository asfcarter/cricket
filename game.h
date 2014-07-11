#ifndef GAME_H
#define GAME_H

#include "team.h"

#define ARRAYSIZE 400


class Game
{
private:
   double gamespeed;
   int tosschange; //if toss won by team 1 tosschange=1
   int inningsnumber;
   int followon;
	int shotarray[ARRAYSIZE][2];
	int viewplayer;
	int ballx,bally;

public:
	Team team[2];

        Game();
        virtual int firstscreen()=0;  
};

#endif
