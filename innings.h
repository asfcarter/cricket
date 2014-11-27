#ifndef INNINGS_H
#define INNINGS_H

#include "batsman.h"
#include "bowler.h"

class Innings
{
private:
  int innings_total;
  int wickets, wicket_fall[10], extras;
  int overs;
  int batsman_facing;
  int non_striker;
  int current_bowler;
  int last_bowler;
  int declared;
  Batsman batsman[11];
  Bowler bowler[6];
  int ball;
  int num_batsman_selected;

  void set_wicket_fall();

  void set_declared();
  void set_batsman_facing(int player_number);
  void set_non_striker(int player_number);
  void set_last_bowler(int bowler_number);
  void set_current_bowler(int bowler_number);
  
public:
  Innings();
  Innings& operator=(const Innings &i);
  void change_innings_runs(int run, bool is_extra, int wicket);
  int get_innings_total();
  int get_extras();
  int get_wickets();
  int get_wicket_fall(int wicket_number);
  int get_overs();
  int get_balls() const;
  int get_batsman_facing() const;  
  int get_non_striker() const;
  int get_last_bowler();
  int get_current_bowler() const;
  int get_declared();
  int get_player_number(const int batsman_number) const;
  int get_batsman_how_out(const int batsman_number) const;
  int get_batsman_runs(const int batsman_num) const;
  bowler_info get_bowler_info(const int bowler_num) const;
  int get_bowler_overs(const int bowler_num) const; 
  bool set_new_batsman(const int player_number);
  bool set_new_bowler(const int bowler_number);
};

#endif
