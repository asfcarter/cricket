#include <cstring>

class Batsman
{
private:
   int balls, ones, twos, threes, fours, sixes, runs_scored, batsman_number, how_out;
public:
    Batsman(){
	       balls=ones=twos=threes=fours=sixes=runs_scored=batsman_number=how_out=0;
            }
    void change_balls_faced(int r);
    int get_balls_faced();
    int get_ones();
    int get_twos();
    int get_fours();
    int get_threes();
    int get_sixes();
    int get_runs_scored();
    void set_batsman_num(int num);
    int get_batsman_num();
    void set_how_out(int out);
    int get_how_out();
};
