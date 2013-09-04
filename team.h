#include "innings.h"

class team
{
private:
    char teamname[12];


public:
    Innings innings[2];
    team();
    void setteamcomputer1();
    void setteamcomputer2();
    void setteammanual();
    char* getteamname();


};
