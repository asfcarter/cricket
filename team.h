#ifndef TEAM_H
#define TEAM_H

#include "innings.h"
#include "player.h"

class Team
{
private:
    char teamname[20];

public:
    Player player[11];
    Innings innings[2];

    Team();
    void setteamcomputer1();
    void setteamcomputer2();
    void setteammanual();
    char* get_team_name();

    int get_bowler_player_number(const int bowler_number) const;
};

#endif
