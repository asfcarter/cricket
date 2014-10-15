#include <cstring>

class Batsman
{
protected:
   int balls_faced, ones, twos, threes, fours, sixes, runs_scored, batsman_number, how_out;
public:
    Batsman(){
	       balls_faced=ones=twos=threes=fours=sixes=runs_scored=batsman_number=how_out=0;
            }
    void change_balls_faced(int r);
    int get_balls_faced() const;
    
    int get_ones() const;
    int get_twos() const;
    int get_fours() const;
    int get_threes() const;
    int get_sixes() const;
    int get_runs_scored() const;
    void set_batsman_number(int num);
    int get_batsman_number() const;
    void set_how_out(int out);
    int get_how_out() const;
};
