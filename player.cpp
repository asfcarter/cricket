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
x=p.x;
y=p.y;
overs=p.overs;
overs_ball=p.overs_ball;
runs_conceeded=p.runs_conceeded;
wickets=p.wickets;
maidens=p.maidens;
bowler_number=p.bowler_number;
balls_faced=p.balls_faced;
ones=p.ones;
twos=p.twos;
threes=p.threes;
fours=p.fours;
sixes=p.sixes;
runs_scored=p.runs_scored;
batsman_number=p.batsman_number;
how_out=p.how_out;
strcpy(name,p.name);

return *this;
}

Player::Player(const Player & p){
}
