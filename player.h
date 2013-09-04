#include <cstring>

class Player
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
    int getballs();
    int getones();
    int gettwos();
    int getfours();
    int getthrees();
    int getsixes();
    inline int getrunsscored();
    void changebatsmannum(int num);
    int getbatsmannum();
    void changehowout(int out);
    int gethowout();


};
