#include <iostream>
#include "game.h"
#include "global.h"

using namespace std;

Game::Game(){
	init_screen();
	innings_number=0;
	toss_change=0;
	follow_on=0;
}

bool Game::run(){
SDL_Keycode ret_val;


//	firstscreen();
	ret_val=secondscreen();

	if(ret_val == SDLK_y)
	{
		team[0].setteamcomputer1();
		team[1].setteamcomputer2();
	}
	else if(ret_val == SDLK_n)
	{
		team[0].setteamcomputer1();
		team[1].setteamcomputer2();
	}

//	display_scoreboard(&team[0],&team[0],innings_number);
//	spacebar_to_continue(135,420,WHITE,15);
//	display_scoreboard(&team[1],&team[1],innings_number);
//	spacebar_to_continue(135,420,WHITE,15);

	toss_change=toss_screen(team);

//  	innings_number | toss_change | follow_on | %2 | /2
//      --------------------------------------------------
//	0              |     0       |   0       | 0  | 0
//	1              |     0       |   0       | 1  | 0
//	2              |     0       |   0       | 0  | 1
//	3              |     0       |   0       | 1  | 1
//	               |             |           |    |  
//	0              |     1       |   0       | 1  | 0
//	1              |     1       |   0       | 0  | 0
//	2              |     1       |   0       | 1  | 1
//	3              |     1       |   0       | 0  | 1
//	               |             |           |    |  
//	0              |     0       |   0       | 1  | 0
//	1              |     0       |   0       | 0  | 0
//	2              |     0       |   1       | 0  | 1
//	3              |     0       |   1       | 1  | 1
//	               |             |           |    |  
//	0              |     1       |   0       | 0  | 0
//	1              |     1       |   0       | 1  | 0
//	2              |     1       |   1       | 1  | 1
//	3              |     1       |   1       | 0  | 1


	do{

		while(!((team[((toss_change+innings_number+follow_on)%2)].innings[innings_number/2].get_declared()) || (team[((toss_change+innings_number+follow_on)%2)].innings[innings_number/2].get_wickets()==10) || ((team[toss_change].innings[0].get_innings_total()-team[toss_change].innings[0].get_innings_total()+team[(toss_change+follow_on)%2].innings[1].get_innings_total()-team[!(toss_change+follow_on)%2].innings[1].get_innings_total()<0)&&(innings_number==3))))
		{	
//	send ball into innings
					
			if((team[((toss_change+innings_number+follow_on)%2)].innings[innings_number/2].get_batsman_how_out(team[((toss_change+innings_number+follow_on)%2)].innings[innings_number/2].get_batsman_facing()) != NOT_OUT)||(team[((toss_change+innings_number+follow_on)%2)].innings[innings_number/2].get_batsman_how_out(team[((toss_change+innings_number+follow_on)%2)].innings[innings_number/2].get_non_striker()) != NOT_OUT))
			{	display_new_batsman(&team[((toss_change+innings_number+follow_on)%2)],&team[!((toss_change+innings_number+follow_on)%2)],innings_number/2);
        SDL_Delay(500);  // Pause execution for 3000 milliseconds, for example
			}
			else if((team[((toss_change+innings_number+follow_on)%2)].innings[innings_number/2].get_current_bowler()==0)||(team[((toss_change+innings_number+follow_on)%2)].innings[innings_number/2].get_balls()==0))
			{
display_new_bowler(&team[((toss_change+innings_number+follow_on)%2)],&team[!((toss_change+innings_number+follow_on)%2)],innings_number/2);
			}
else
{
      display_ball_field(&team[((toss_change+innings_number+follow_on)%2)],&team[!((toss_change+innings_number+follow_on)%2)],innings_number/2);
team[((toss_change+innings_number+follow_on)%2)].innings[innings_number/2].change_innings_runs(2,1,1);
}

			if(team[((toss_change+innings_number+follow_on)%2)].innings[innings_number/2].get_wickets()==10)
			{
				display_scoreboard(&team[((toss_change+innings_number+follow_on)%2)],&team[!((toss_change+innings_number+follow_on)%2)],innings_number/2);
				spacebar_to_continue(135,420,WHITE,15);
			}


		}
		

		if((innings_number==1)&&(team[toss_change].innings[0].get_innings_total() > (team[toss_change].innings[0].get_innings_total()+200)))
		{
			//Do you want to enforce follow on?
			follow_on=1;
		}
		
		innings_number++;
	}while(innings_number!=4);

return play_again();
}

Game::~Game(){
	destroy_screen();
}
