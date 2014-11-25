#ifndef PLAYER_H 
#define PLAYER_H

#include <cstring>
#include "fielder.h"

class Player : public Fielder
{
private:
   char name[20];
   int bowler_number;
public:
    Player & operator=(const Player & p);
    Player():Fielder(){
	       set_name("");
	       bowler_number=0;
            }
    
    Player(const Player & p):Fielder(p){
		strcpy(name,p.name);
    }
	    
    void set_name(const char *n);
    char *get_name();
    void set_bowler_number(const int n);
    int get_bowler_number() const;
};

#endif
