#include "team.h"
#include "screen.h"

#define ARRAYSIZE 400


class game: public screen
{
private:
   double gamespeed;
	team team[2];
   int tosschange; //if toss won by team 1 tosschange=1
   int inningsnumber;
   int followon;
	int shotarray[ARRAYSIZE][2];
	int viewplayer;
	int ballx,bally;

public:

	game();
	void scoreboard(int,int);
	void toss();
   void inningsoverscreen();
	void pause(int);
	void createshotarray();
	int wicket(int,int);
   int closestwicket(void);
   int closestfielder(void);
	void shot(int);
   void over(int);
	int run(int,int);
  
};