#include <cstring>
#include "batsman.h"


Batsman::Batsman(const Batsman &b){
balls_faced=b.balls_faced;
ones=b.ones;
twos=b.twos;
threes=b.threes;
fours=b.fours;
sixes=b.sixes;
runs_scored=b.runs_scored;
batsman_number=b.batsman_number;
how_out=b.how_out;
}


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
   else if(r>6){
        how_out=r;
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

int Batsman::get_how_out() const{
return how_out;
}

Batsman & Batsman::operator=(const Batsman &b){
balls_faced=b.balls_faced;
ones=b.ones;
twos=b.twos;
threes=b.threes;
fours=b.fours;
sixes=b.sixes;
runs_scored=b.runs_scored;
batsman_number=b.batsman_number;
how_out=b.how_out;
return *this;
}
