#include "innings.h"
#include <iostream>

Innings::Innings(){
int i;
declared=inningsruns=wickets=extras=overs=0;
  for(i=0;i<11;i++){
  player[i].changebatsmannum(i+1);
  wickfall[i]=0;
  }

batsmanfacing=nonstriker=lastbowler=0;
}

void Innings::changeinningsruns(int run,int isextra){
inningsruns+=run;
  if(isextra==0){
  extras+=run;
  }
  else{
  player[isextra-1].changeballsfaced(run);
  }
//cout << "|||" << run <<"|||"<< isextra;
}

int Innings::getinningsruns(){
return inningsruns;
}

int Innings::getextras(){
return extras;
}

int Innings::getwickets(){
return wickets;
}

int Innings::getwickfall(int wicketnumber){
return wickfall[wicketnumber-1];
}

void Innings::setwickfall(){
wickfall[wickets]=inningsruns;
wickets++;
}

Innings& Innings::operator=(const Innings &i)
{
int j;
inningsruns=i.inningsruns;
wickets=i.wickets;
  for(j=0;j<11;j++){
  wickfall[j]=i.wickfall[j];
  player[j]=i.player[j];
  }

extras=i.extras;
overs=i.overs;
batsmanfacing=i.batsmanfacing;
nonstriker=i.nonstriker;
lastbowler=i.lastbowler;
declared=i.declared;

 return *this; 
}

int Innings::getovers()
{
return overs;
}

void Innings::changeovers()
{
overs++;
}

int Innings::getbatsmanfacing()
{
return batsmanfacing;
}

int Innings::getnonstriker()
{
return nonstriker;
}

void Innings::setbatsmanfacing(int n)
{
batsmanfacing=n;
}

void Innings::setnonstriker(int n)
{
nonstriker=n;
}

void Innings::setlastbowler(int n)
{
lastbowler=n;
}

int Innings::getlastbowler()
{
return lastbowler;
}

void Innings::setdeclared()
{
declared=1;
}

int Innings::getdeclared()
{
return declared;
}
