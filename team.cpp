#include "team.h"
//#include <conio>
//#include "stdlib.h"

Team::Team()
{
//strcpy(teamname,"               ");
}


char* Team::get_team_name()
{
return teamname;
}


void Team::setteamcomputer1()
{
strcpy(teamname,"England");
player[0].set_name("Atherton");
player[1].set_name("Knight");
player[2].set_name("Hussain");
player[3].set_name("Thorpe");
player[4].set_name("Hick");
player[5].set_name("Stewart");
player[6].set_name("Flintoff");
player[7].set_name("Caddick");
player[8].set_name("Gough");
player[9].set_name("Croft");
player[10].set_name("Mullally");

player[7].set_bowler_number(1);
player[8].set_bowler_number(2);
player[10].set_bowler_number(3);
player[9].set_bowler_number(4);
player[6].set_bowler_number(5);
player[4].set_bowler_number(6);

player[0].set_position(220,325);
player[1].set_position(235,340);
player[2].set_position(265,390);
player[3].set_position(310,410);
player[4].set_position(370,370);
player[5].set_position(400,280);
player[6].set_position(330,220);
player[7].set_position(265,230);
player[8].set_position(190,280);
player[9].set_position(245,310);
}

void Team::setteamcomputer2()
{
strcpy(teamname,"South Africa");
player[0].set_name("Kirsten");
player[1].set_name("Gibbs");
player[2].set_name("Kallis");
player[3].set_name("Cullinan");
player[4].set_name("Cronje");
player[5].set_name("Rhodes");
player[6].set_name("Klusneur");
player[7].set_name("Pollock");
player[8].set_name("Boucher");
player[9].set_name("Adams");
player[10].set_name("Donald");

player[10].set_bowler_number(1);
player[7].set_bowler_number(2);
player[9].set_bowler_number(3);
player[6].set_bowler_number(4);
player[2].set_bowler_number(5);
player[4].set_bowler_number(6);

player[0].set_position(220,325);
player[1].set_position(235,340);
player[2].set_position(265,390);
player[3].set_position(310,410);
player[4].set_position(370,370);
player[5].set_position(400,280);
player[6].set_position(330,220);
player[7].set_position(265,230);
player[8].set_position(190,280);
player[9].set_position(245,310);
player[10].set_position(245,310);	
}


void Team::setteammanual()
{

}

int Team::get_bowler_player_number(const int bowler_number) const{
int player_num;

	for(player_num=1;player_num<12;player_num++)
	{				
		if(player[player_num-1].get_bowler_number()==bowler_number)
		{
			break;
		}
	}
	
return player_num;
}
