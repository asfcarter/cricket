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
this->Bowler::operator=(p);
this->Batsman::operator=(p);
strcpy(name,p.name);
return *this;
}
