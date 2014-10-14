#include <cstring>

class Bowler
{
private:
   int overs, oversball, runsconceeded, wickets, maidens, ismaiden, bowlernumber;
public:
    Bowler(){
	       ismaiden=overs=runsconceeded=wickets=maidens=bowlernumber=oversball=0;
            }
    void change_overs_ball(int r);
    int get_overs();
    int get_overs_ball();
    int get_maidens();
    int get_runs_conceeded();
    void change_wickets();
    int get_wickets();
    void set_bowler_num(int num);
    int get_bowler_num();
};
