#ifndef BOWLER_H
#define BOWLER_H

#include <cstring>

struct bowler_info{
int overs;
int maidens;
int runs_conceeded;
int wickets;
};


class Bowler
{
private:
    int overs, overs_ball, runs_conceeded, wickets, maidens, is_maiden;
public:
    Bowler(){
	       is_maiden=overs=runs_conceeded=wickets=maidens=0;
	       overs_ball=1;
            }
    Bowler(const Bowler &b);
    int change_overs_ball(int r, int wicket);
    int get_overs() const;
    int get_overs_ball() const;
    int get_maidens() const;
    int get_runs_conceeded() const;
    int get_wickets() const;
    bowler_info get_info() const;
    Bowler & operator=(const Bowler &b);
};

#endif
