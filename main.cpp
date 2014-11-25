#include <iostream>
#include "game.h"


using namespace std;

int main(int argc, char **argv)
{
Game g;
bool run_game=true;

	do
	{
		run_game=g.run();
	}while(run_game);
}
