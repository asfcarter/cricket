#ifndef TEAM_H
#define TEAM_H

//#include "innings.h"
#include "player.h"

class Team
{
private:
    char teamname[12];
//    Innings innings[2];

public:
  //  Player player[11];

    Team();
    void setteamcomputer1();
    void setteamcomputer2();
    void setteammanual();
    char* getteamname();


};

#endif
