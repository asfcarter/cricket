#include <cstring>
#include "batsman.h"


void Batsman::change_balls_faced(int r){
balls_faced++;
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

int Batsman::get_balls_faced() const{
return balls_faced;
}

int Batsman::get_ones() const{
return ones;
}

int Batsman::get_twos() const{
return twos;
}

int Batsman::get_fours() const{
return fours;
}

int Batsman::get_threes() const{
return threes;
}

int Batsman::get_sixes() const{
return sixes;
}

int Batsman::get_runs_scored() const{
return runs_scored;
}


void Batsman::set_batsman_number(int num){
batsman_number=num;
}

int Batsman::get_batsman_number() const{
return batsman_number;
}

void Batsman::set_how_out(int out){
how_out=out;
}

int Batsman::get_how_out() const{
return how_out;
}
