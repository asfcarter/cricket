#include <cstring>
#include "player.h"

char *Player::get_name(){
return name;
}

void Player::set_name(const char *n){
strcpy(name,n);
}
