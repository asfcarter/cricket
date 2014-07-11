#include "innings.h"

class Team
{
private:
    char teamname[12];


public:
    Innings innings[2];
    Team();
    void setteamcomputer1();
    void setteamcomputer2();
    void setteammanual();
    char* getteamname();


};
