#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include "team.h"

#define ARRAYSIZE 400


class Game : public Screen
{
private:
 //  double gamespeed;
   bool toss_change; //if 0 team[0] bat first, if 1 team[1] bats first
 //  int inningsnumber;
 //  int followon;
//	int shotarray[ARRAYSIZE][2];
//	int viewplayer;
//	int ballx,bally;

public:
	Team team[2];

        Game();
//        virtual int firstscreen()=0;  
};

#endif
