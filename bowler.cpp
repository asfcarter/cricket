#include <cstring>
#include "bowler.h"
#include "global.h"

Bowler::Bowler(const Bowler &b){
is_maiden=b.is_maiden;
overs=b.overs;
runs_conceeded=b.runs_conceeded;
wickets=b.wickets;
maidens=b.maidens;
overs_ball=b.overs_ball;
}


int Bowler::change_overs_ball(int r, int wicket){
  overs_ball++;
  
  if(wicket!=NOT_OUT)
  {
      wickets++;
  }
  
  runs_conceeded+=r;

  if(r!=0){
  is_maiden=1;
  }


    if(overs_ball==7)
    {
    	overs_ball=1;
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
    
return overs_ball;    
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

Bowler & Bowler::operator=(const Bowler &b){
is_maiden=b.is_maiden;
overs=b.overs;
runs_conceeded=b.runs_conceeded;
wickets=b.wickets;
maidens=b.maidens;
overs_ball=b.overs_ball;
return *this;
}

bowler_info Bowler::get_info() const{
bowler_info temp;
	temp.overs=get_overs();
	temp.maidens=get_maidens();
	temp.runs_conceeded=get_runs_conceeded();
	temp.wickets=get_wickets();
return temp;
}

