#include "innings.h"
#include <iostream>

Innings::Innings(){
int i;
declared=innings_total=wickets=extras=overs=0;
  for(i=0;i<11;i++){
  player[i].set_batsman_number(i+1);
  wicket_fall[i]=0;
  }

batsman_facing=non_striker=last_bowler=0;
}

void Innings::change_innings_runs(int run,int is_extra){
innings_total+=run;
  if(is_extra==0){
  extras+=run;
  }
  else{
  player[is_extra-1].change_balls_faced(run);
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
  player[j]=i.player[j];
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

void Innings::change_overs()
{
overs++;
}

int Innings::get_batsman_facing()
{
return batsman_facing;
}

int Innings::get_non_striker()
{
return non_striker;
}

void Innings::set_batsman_facing(int n)
{
batsman_facing=n;
}

void Innings::set_non_striker(int n)
{
non_striker=n;
}

void Innings::set_last_bowler(int n)
{
last_bowler=n;
}

int Innings::get_last_bowler()
{
return last_bowler;
}

void Innings::set_declared()
{
declared=1;
}

int Innings::get_declared()
{
return declared;
}
