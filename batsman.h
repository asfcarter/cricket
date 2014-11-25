#ifndef BATSMAN_H
#define BATSMAN_H

#include <cstring>

class Batsman
{
private:
   int balls_faced, ones, twos, threes, fours, sixes, runs_scored, batsman_number, how_out;
public:
    Batsman(){
	       balls_faced=ones=twos=threes=fours=sixes=runs_scored=batsman_number=how_out=0;
            }
    Batsman(const Batsman &b);
    void change_balls_faced(int r, int wicket);
    int get_balls_faced() const;
    
    int get_ones() const;
    int get_twos() const;
    int get_fours() const;
    int get_threes() const;
    int get_sixes() const;
    int get_runs_scored() const;
    void set_batsman_number(int num);
    int get_batsman_number() const;
    void set_how_out(const int h);
    bool set_not_out();
    int get_how_out() const;
    Batsman & operator=(const Batsman &b);
};

#endif
