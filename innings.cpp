#include <iostream>

#include "innings.h"
#include "global.h"

Innings::Innings(){
int i;
  declared=innings_total=wickets=extras=overs=ball=num_batsman_selected=0;
  
  for(i=0;i<11;i++){
    batsman[i].set_batsman_number(i+1);
    wicket_fall[i]=0;
  }

batsman_facing=non_striker=current_bowler=last_bowler=0;
}

void Innings::change_innings_runs(int run, bool is_extra, int wicket){
int temp;
int run_temp=run;

  innings_total+=run;

  if(is_extra)
  {
  	extras+=run;
  	run=0;
  }

  if(wicket != NOT_OUT)
  {
    set_wicket_fall();
  }

  if(wicket == RUN_OUT_NON_STRIKER)
  {
	batsman[batsman_facing-1].change_balls_faced(run,NOT_OUT);
  	batsman[non_striker-1].set_how_out(RUN_OUT);  
	set_non_striker(0);
	ball=bowler[current_bowler-1].change_overs_ball(run,NOT_OUT);
  }
  else
  {
  	if((wicket!=NOT_OUT)&&(wicket!=RUN_OUT))
	{
		wicket+=(current_bowler*10);
	}
	 
	batsman[batsman_facing-1].change_balls_faced(run,wicket);
	
	if(wicket!=NOT_OUT)
	{
		set_batsman_facing(0);
	}

	if(wicket==RUN_OUT)
	{
		ball=bowler[current_bowler-1].change_overs_ball(run,NOT_OUT);
	}
	else
	{
		ball=bowler[current_bowler-1].change_overs_ball(run,wicket);
	}
  }


  if((wicket==RUN_OUT)||(wicket==RUN_OUT_NON_STRIKER))
  {
  	run_temp++;
  }
  
  if(run_temp%2==1)
  {
  	temp=get_batsman_facing();
        set_batsman_facing(get_non_striker());
        set_non_striker(temp);
  }
  
  if(ball==1)
  {
  	ball=0;
	last_bowler=current_bowler;
	temp=get_batsman_facing();
        set_batsman_facing(get_non_striker());
        set_non_striker(temp);
	overs++;	
  }
}

int Innings::get_innings_total(){
return innings_total;
}

int Innings::get_extras(){
return extras;
}

int Innings::get_wickets(){
return wickets;
}

int Innings::get_wicket_fall(int wicket_number){
return wicket_fall[wicket_number-1];
}

void Innings::set_wicket_fall(){
wicket_fall[wickets]=innings_total;
wickets++;
}

Innings& Innings::operator=(const Innings &i)
{
int j;
innings_total=i.innings_total;
wickets=i.wickets;
  for(j=0;j<11;j++){
  wicket_fall[j]=i.wicket_fall[j];
  batsman[j]=i.batsman[j];
  bowler[j]=i.bowler[j];
  }

extras=i.extras;
overs=i.overs;
batsman_facing=i.batsman_facing;
non_striker=i.non_striker;
last_bowler=i.last_bowler;
declared=i.declared;

 return *this; 
}

int Innings::get_overs()
{
return overs;
}

int Innings::get_balls() const{
return ball;
}

void Innings::set_batsman_facing(int n)
{
batsman_facing=n;
}

int Innings::get_batsman_facing() const
{
return batsman_facing;
}

void Innings::set_non_striker(int n)
{
non_striker=n;
}

int Innings::get_non_striker() const
{
return non_striker;
}


void Innings::set_last_bowler(int n)
{
last_bowler=n;
}

void Innings::set_current_bowler(int bowler_number)
{
	current_bowler=bowler_number;
	ball=1;
}

int Innings::get_last_bowler()
{
return last_bowler;
}

int Innings::get_current_bowler() const{
return current_bowler;
}

void Innings::set_declared()
{
declared=1;
}

int Innings::get_declared()
{
return declared;
}

int Innings::get_player_number(const int batsman_number) const
{
return batsman[batsman_number-1].get_batsman_number();
}

int Innings::get_batsman_how_out(const int batsman_number) const
{
return batsman[batsman_number-1].get_how_out();
} 

int Innings::get_batsman_runs(const int batsman_num) const
{
return batsman[batsman_num-1].get_runs_scored();
} 

bowler_info Innings::get_bowler_info(const int bowler_num) const
{
return bowler[bowler_num-1].get_info();
}


bool Innings::set_new_batsman(const int player_number)
{
int i;
int temp_batsman_number;
	
	if(player_number > 11)
	{
		return false;
	}
	else if(player_number!=DECLARED)
  	{
		if(player_number > num_batsman_selected)
		{
			
			if(get_batsman_facing() == 0)
			{
				batsman[num_batsman_selected].set_not_out();
			
				temp_batsman_number=batsman[player_number-1].get_batsman_number();
				
				for(i=player_number-1;i>num_batsman_selected;i--)
				{
					 batsman[i].set_batsman_number(batsman[i-1].get_batsman_number());				
				}
				batsman[num_batsman_selected].set_batsman_number(temp_batsman_number);
							
				num_batsman_selected++;
				
				set_batsman_facing(num_batsman_selected);
			}
			else if(get_non_striker()  == 0)
			{
				batsman[num_batsman_selected].set_not_out();
			
				temp_batsman_number=batsman[player_number-1].get_batsman_number();
				
				for(i=player_number-1;i>num_batsman_selected;i--)
				{
					 batsman[i].set_batsman_number(batsman[i-1].get_batsman_number());
				}
				batsman[num_batsman_selected].set_batsman_number(temp_batsman_number);
							
				num_batsman_selected++;
				set_non_striker(num_batsman_selected);
			}
			else
			{
				return false;
			}
  		}
		else
		{
			return false;
		}
	}
	else
	{
		set_declared();
	}
	
return true;
}
bool Innings::set_new_bowler(const int bowler_number)
{
	if(bowler_number==DECLARED)
  	{
		set_declared();
	}
	else
	{
		if(get_last_bowler() != bowler_number)
		{
			set_last_bowler(current_bowler);
			set_current_bowler(bowler_number);
		}
		else
		{
			return false;
		}
	}
	
return true;
}

int Innings::get_bowler_overs(const int bowler_num) const
{
	return bowler[bowler_num-1].get_overs();
} 
