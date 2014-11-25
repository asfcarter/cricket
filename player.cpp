#include <cstring>
#include "player.h"

char *Player::get_name(){
return name;
}

void Player::set_name(const char *n){
	strcpy(name,n);
}

Player & Player::operator=(const Player & p)
{
	this->Fielder::operator=(p);
	strcpy(name,p.name);
return *this;
}

void Player::set_bowler_number(const int n){
	bowler_number=n;
}

int Player::get_bowler_number() const{
return bowler_number;
}


