#include "player.h"

class Innings
{
private:
  int innings_total;
  int wickets, wicket_fall[10], extras;
  int overs;
  int batsman_facing;
  int non_striker;
  int last_bowler;
  int declared;

public:
  Player player[11];

public:
  Innings();
  Innings& operator=(const Innings &i);
  void change_innings_runs(int run, int is_extra);
  int get_innings_total();
  int get_extras();
  int get_wickets();
  void set_wicket_fall();
  int get_wicket_fall(int wicket_number);
  int get_overs();
  void change_overs();
  int get_batsman_facing();
  int get_non_striker();
  void set_batsman_facing(int);
  void set_non_striker(int);
  void set_last_bowler(int);
  int get_last_bowler();
  void set_declared();
  int get_declared();
};
