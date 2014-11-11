#include <cstring>
#include "bowler.h"

Bowler::Bowler(const Bowler &b){
is_maiden=b.is_maiden;
overs=b.overs;
runs_conceeded=b.runs_conceeded;
wickets=b.wickets;
maidens=b.maidens;
bowler_number=b.bowler_number;
overs_ball=b.overs_ball;
}


void Bowler::change_overs_ball(int r){
  overs_ball++;
  
  if(r>6)
  {
      wickets++;
  }
  else
  {
      runs_conceeded+=r;
  }

  if(r!=0){
  is_maiden=1;
  }


    if(overs_ball==6)
    {
    	overs_ball=0;
    	overs++;

    	if(is_maiden==0)
	{
		maidens++;
	}
	else
	{
		is_maiden=0;
	}
    }
}

int Bowler::get_overs_ball() const{
return overs_ball;
}

int Bowler::get_overs() const{
return overs;
}

int Bowler::get_maidens() const{
return maidens;
}

int Bowler::get_runs_conceeded() const{
return runs_conceeded;
}

int Bowler::get_wickets() const{
return wickets;
}

void Bowler::set_bowler_number(int num){
bowler_number=num;
}

int Bowler::get_bowler_number() const{
return bowler_number;
}

Bowler & Bowler::operator=(const Bowler &b){
is_maiden=b.is_maiden;
overs=b.overs;
runs_conceeded=b.runs_conceeded;
wickets=b.wickets;
maidens=b.maidens;
bowler_number=b.bowler_number;
overs_ball=b.overs_ball;
return *this;
}
