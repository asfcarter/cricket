#include <cstring>
#include "bowler.h"

void Bowler::change_overs_ball(int r){
  oversball++;
  runsconceeded+=r;
  if(r!=0){
  ismaiden=1;
  }

    if(oversball==6)
    {
    	oversball=0;
    	overs++;

    	if(ismaiden==0)
	{
		maidens++;
	}
	else
	{
		ismaiden=0;
	}
    }
}

int Bowler::get_overs_ball(){
return oversball;
}

int Bowler::get_overs(){
return overs;
}

int Bowler::get_maidens(){
return maidens;
}

int Bowler::get_runs_conceeded(){
return runsconceeded;
}

void Bowler::change_wickets(){
wickets++;
}

int Bowler::get_wickets(){
return wickets;
}

void Bowler::set_bowler_num(int num){
bowlernumber=num;
}

int Bowler::get_bowler_num(){
return bowlernumber;
}
