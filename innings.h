#include "player.h"

class Innings
{
private:
  int inningsruns;
  int wickets,wickfall[10],extras;
  int overs;
  int batsmanfacing;
  int nonstriker;
  int lastbowler;
  int declared;

public:
  Innings();
  Innings& operator=(const Innings &i);
  Player player[11];
  void changeinningsruns(int run,int isextra);
  int getinningsruns();
  int getextras();
  int getwickets();
  void setwickfall();
  int getwickfall(int wicketnumber);
  int getovers();
  void changeovers();
  int getbatsmanfacing();
  int getnonstriker();
  void setbatsmanfacing(int);
  void setnonstriker(int);
  void setlastbowler(int);
  int getlastbowler();
  void setdeclared();
  int getdeclared();

};
