#include <cstring>

class Player : Batsman, Bowler
{
private:
   int x,y;
   int overs,oversball,runsconceeded,wickets,maidens,ismaiden,bowlernumber;
   int balls,ones,twos,threes,fours,sixes,runsscored,batsmannumber,howout;
   char name[12];
public:
    Player &operator=(const Player &p);
    Player(){
	       ismaiden=overs=runsconceeded=wickets=maidens=bowlernumber=0;
	       balls=ones=twos=threes=fours=sixes=runsscored=batsmannumber=howout=0;
	       oversball=1;
	       setname("");
            }
    void setname(const char *n){
	   strcpy(name,n);
	   }
    char *getname();
    void setposition(int x1,int y1);
    void setx(int);
    void sety(int);
    int getx();
    int gety();
    int changeoversball(int r);
    int getovers();
    int getoversball();
    int getmaidens();
    int getrunsconceeded();
    void changewickets();
    int getwickets();
    void changebowlernum(int num);
    int getbowlernum();
    void changeballsfaced(int r);
    int get_balls_faced();
    int getones();
    int gettwos();
    int getfours();
    int getthrees();
    int getsixes();
    int getrunsscored();
    void setbatsmannum(int num);
    int get_batsmannum();
    void set_how_out(int out);
    int get_how_out();


};
