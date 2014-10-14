#include <cstring>
#include "batsman.h"


void Batsman::change_balls_faced(int r){
balls++;
runs_scored+=r;
   if(r==1){
   	ones++;
   }
   else if(r==2){
   	twos++;
   }
   else if(r==3){
   	threes++;
   }
   else if(r==4){
   	fours++;
   }
   else if(r==6){
   	sixes++;
   }
}

int Batsman::get_balls_faced(){
return balls;
}

int Batsman::get_ones(){
return ones;
}

int Batsman::get_twos(){
return twos;
}

int Batsman::get_fours(){
return fours;
}

int Batsman::get_threes(){
return threes;
}

int Batsman::get_sixes(){
return sixes;
}

int Batsman::get_runs_scored(){
return runs_scored;
}

void Batsman::set_batsman_num(int num){
batsman_number=num;
}

int Batsman::get_batsman_num(){
return batsman_number;
}

void Batsman::set_how_out(int out){
how_out=out;
}

int Batsman::get_how_out(){
return how_out;
}
