#include <cstring>

class Bowler
{
protected:
    int overs, overs_ball, runs_conceeded, wickets, maidens, is_maiden, bowler_number;
public:
    Bowler(){
	       is_maiden=overs=runs_conceeded=wickets=maidens=bowler_number=overs_ball=0;
            }
    void change_overs_ball(int r);
    int get_overs() const;
    int get_overs_ball() const;
    int get_maidens() const;
    int get_runs_conceeded() const;
    void change_wickets();
    int get_wickets() const;
    void set_bowler_number(int num);
    int get_bowler_number() const;
};
