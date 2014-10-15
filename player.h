#include <cstring>
#include "batsman.h"
#include "bowler.h"
#include "fielder.h"

class Player : public Batsman, public Bowler, public Fielder
{
private:
   char name[12];
public:
    Player & operator=(const Player & p);
    Player():Batsman(),Bowler(),Fielder(){
	       set_name("");
            }
    
    Player(const Player & p);
    	    
    void set_name(const char *n);
    char *get_name();
};
