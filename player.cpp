#include "player.h"
#include <cstring>

char *Player::getname(){
return name;
}

void Player::setposition(int x1,int y1){
x=x1;
y=y1;
}

void Player::setx(int x1){
x=x1;
}

void Player::sety(int y1){
y=y1;
}

int Player::getx(){
return x;
}

int Player::gety(){
return y;
}

int Player::changeoversball(int r){
  oversball++;
  runsconceeded+=r;
  if(r!=0){
  ismaiden=1;
  }

    if((ismaiden==0)&&(oversball==7)){
    maidens++;
    oversball=1;
    overs++;
    }
    else if((ismaiden==1)&&(oversball==7)){
    oversball=1;
    overs++;
    ismaiden=0;
    }
return oversball;
}

int Player::getovers(){
return overs;
}

int Player::getoversball(){
return oversball;
}

int Player::getmaidens(){
return maidens;
}

int Player::getrunsconceeded(){
return runsconceeded;
}

void Player::changewickets(){
wickets++;
}

int Player::getwickets(){
return wickets;
}

void Player::changebowlernum(int num){
bowlernumber=num;
}

int Player::getbowlernum(){
return bowlernumber;
}

void Player::changeballsfaced(int r){
balls++;
runsscored+=r;
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

int Player::getballs(){
return balls;
}

int Player::getones(){
return ones;
}

int Player::gettwos(){
return twos;
}

int Player::getfours(){
return fours;
}

int Player::getthrees(){
return threes;
}

int Player::getsixes(){
return sixes;
}

int Player::getrunsscored(){
return runsscored;
}

void Player::changebatsmannum(int num){
batsmannumber=num;
}

int Player::getbatsmannum(){
return batsmannumber;
}

void Player::changehowout(int out){
howout=out;
}

int Player::gethowout(){
return howout;
}

Player& Player::operator=(const Player &p)
{
x=		p.x;
y=		p.y;
overs=		p.overs;
oversball=	p.oversball;
runsconceeded=	p.runsconceeded;
wickets=	p.wickets;
maidens=	p.maidens;
ismaiden=	p.maidens;
bowlernumber=	p.bowlernumber;
balls= 		p.balls;
ones=		p.ones;
twos=		p.twos;
threes=		p.threes;
fours=		p.fours;
sixes=		p.sixes;
runsscored=	p.runsscored;
batsmannumber=	p.batsmannumber;
howout=		p.howout;
strcpy(name,p.name);
return *this;
}
