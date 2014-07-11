#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <fstream.h>
#include <string.h>
#include <graphics.h>
#include <fstream.h>
#include <math.h>
#include "game.h"

game::game(){

int bowler,i,j;
char input,bo[2];
int declared;


  createshotarray();



do{
outtextxy(30,30,"Please Enter Computer Processor Speed");
gotoxy(5,4);
	cin >> gamespeed;
if((gamespeed<1)||(gamespeed>10000))
outtextxy(30,45,"Please RE-ENTER");
}while((gamespeed<1)||(gamespeed>10000));

viewplayer=1;
do{       //loop for end game to play again

firstscreen();

declared=tosschange=followon=inningsnumber=0;
do{
		secondscreen();
	   input=getch();
	  }while((input!='Y')&&(input!='y')&&(input!='N')&&(input!='n'));
//cout << "hello";getch();/*
if((input=='y')||(input=='Y'))
{
team[0].setteamcomputer1();     //use computer names
team[1].setteamcomputer2();
}
else
{
team[0].setteammanual();    //use manual names
team[1].setteammanual();
}

scoreboard(0,0);     //Show first team
outtextxy(30,420,"Press <SPACEBAR TO CONTINUE>");
do{
input=getch();
}while(input!=' ');

scoreboard(1,0);     //Show second team

outtextxy(30,420,"Press <SPACEBAR TO CONTINUE>");
do{
input=getch();
}while(input!=' ');
//getch();

toss();

do{
   declared=0;
	do{     //checks for 2 not out batsmen
	i=0;
	for(j=0;j<11;j++)
	{
	if(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[j].gethowout()==9)
	i++;
	}
		if(i<2)
		{
			if(i==0)team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setbatsmanfacing(wicket(9,0));
			else team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setnonstriker(wicket(9,0));
			i++;
		}
	 if(((viewplayer=team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing())==99)||(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getnonstriker()==99))
	 {
         declared=1;
	 break;
	 }
	}while(i!=2);



        scoreboard((inningsnumber+tosschange+followon)%2,inningsnumber/2);

        //single innings
	while((declared!=1)&&(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getwickets()!=10)){  //single innings
		
	scoreboard((inningsnumber+tosschange+followon)%2,inningsnumber/2);
                setcolor(6);
		outtextxy(10,40+15*(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()-1),"*");
		if(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getlastbowler()!=0)outtextxy(10,300+15*team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getlastbowler(),"*");
		setcolor(63);

                outtextxy(30,420,"Please enter next bowler (or U/D to see batsmans statistics)");
		bo[0]=getche();

                if(((bo[0]=='u')||(bo[0]=='U'))&&(viewplayer!=1))
		{viewplayer--;
		continue;
		}
		if(((bo[0]=='d')||(bo[0]=='D'))&&(viewplayer!=11))
		{viewplayer++;
		continue;
		}

		bowler=atoi(bo);
		if(bowler==9){
                declared=1;
		continue;
		}

		if((bowler==team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getlastbowler())||(bowler<1)||(bowler>6))
		{
		outtextxy(30,435,"Bowler = Previous bowler please re-enter");
		continue;
		}

                for(i=0;i<11;i++)
		{
		if(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].getbowlernum()==bowler)
		break;
                }

		over(i);

		team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setlastbowler(bowler);
	 
        }; //single innings

        do{
	scoreboard((inningsnumber+tosschange+followon)%2,inningsnumber/2);
        outtextxy(30,420,"UP/Down(U/D). Press any other key to continue");
	bo[0]=getche();
	if(((bo[0]=='u')||(bo[0]=='U'))&&(viewplayer!=0))
	{viewplayer--;
	continue;
	}
	if(((bo[0]=='d')||(bo[0]=='D'))&&(viewplayer!=10))
	{viewplayer++;
	continue;
	}
}while((bo[0]=='d')||(bo[0]=='u')||(bo[0]=='D')||(bo[0]=='U'));

inningsoverscreen();
inningsnumber++;
}while((inningsnumber!=4)||((inningsnumber==3)&&((team[(inningsnumber+tosschange)%2].innings[0].getinningsruns()+team[(inningsnumber+tosschange)%2].innings[1].getinningsruns()-team[(1+inningsnumber+tosschange)%2].innings[0].getinningsruns()-team[(1+inningsnumber+tosschange)%2].innings[1].getinningsruns())>0)));

clearviewport();
outtextxy(20,20,"Do you want to play again? (Y/N)");

	do{
		input=getch();
		if((input!='y')||(input!='Y')||(input!='n')||(input!='N'))
		outtextxy(20,50,"BAD KEY!!!TRY AGAIN");
	  }while((input!='y')&&(input!='Y')&&(input!='n')&&(input!='N'));
}while((input=='y')||(input=='Y'));

closegraph();
};


void game::scoreboard(int teamnumber,int inningsnumber){

int m,n,p,a;
char change[20],str[25];

setcolor(53);

clearviewport();
setbkcolor(0);
setcolor(3);
outtextxy(30,10,team[teamnumber].getteamname());
outtextxy(500,10,"Overs");
outtextxy(550,10,itoa(team[teamnumber].innings[inningsnumber].getovers(),change,10));

setcolor(6);
outtextxy(20,25,"Batsman");
outtextxy(80,25,"Name");
outtextxy(160,25,"Status");
outtextxy(580,25,"Runs");
setcolor(63);

for(m=0;m<11;m++)
{
	for(n=0;n<11;n++)
	{
		if((m+1)==team[teamnumber].innings[inningsnumber].player[n].getbatsmannum())
		{
		outtextxy(20,40+(15*m),itoa(team[teamnumber].innings[inningsnumber].player[n].getbatsmannum(),change,10));
		if((team[teamnumber].innings[inningsnumber].player[n].getbatsmannum())==viewplayer)
		setcolor(6);
		outtextxy(80,40+(15*m),team[teamnumber].innings[inningsnumber].player[n].getname());
		setcolor(63);
			switch((team[teamnumber].innings[inningsnumber].player[n].gethowout())%10)
			{
			 case 0:
					  break;
			 case 1:
					  outtextxy(160,40+(15*m),"CAUGHT");
					  break;
			 case 2:
					  outtextxy(160,40+(15*m),"BOWLED");
					  break;
			 case 3:
					  outtextxy(160,40+(15*m),"STUMPED");
					  break;
			 case 4:
					  outtextxy(160,40+(15*m),"RUN OUT");
					  break;
			 case 5:
					  outtextxy(160,40+(15*m),"L.B.W.");
					  break;
			 case 9:
					  outtextxy(160,40+(15*m),"NOT OUT");
					  break;
			}


			if(team[teamnumber].innings[inningsnumber].player[n].gethowout()/10!=0)
			outtextxy(220,40+(15*m),team[!teamnumber].innings[inningsnumber].player[team[teamnumber].innings[inningsnumber].player[n].gethowout()/10].getname());


		outtextxy(580,40+(15*m),itoa(team[teamnumber].innings[inningsnumber].player[n].getrunsscored(),change,10));
		}
	}
}

outtextxy(20,205,"EXTRAS");
outtextxy(80,205,itoa(team[teamnumber].innings[inningsnumber].getextras(),change,10));
outtextxy(440,205,"TOTAL");
outtextxy(490,205,itoa(team[teamnumber].innings[inningsnumber].getinningsruns(),change,10));
outtextxy(520,205,"FOR");
if(team[teamnumber].innings[inningsnumber].getwickets()!=10)
outtextxy(560,205,itoa(team[teamnumber].innings[inningsnumber].getwickets(),change,10));
else
outtextxy(560,205,"ALL OUT");
outtextxy(20,225,"========================================================================");

outtextxy(20,240,"Fall:");
a=0;
while((a<team[teamnumber].innings[inningsnumber].getwickets())&&(a!=9))
{
outtextxy(70+(a*50),255,itoa(a+1,change,10));
outtextxy(80+(a*50),255,"-");
outtextxy(90+(a*50),255,itoa(team[teamnumber].innings[inningsnumber].getwickfall(a),change,10));
a++;
};

outtextxy(20,270,"Batsman:");
outtextxy(130,270,team[teamnumber].innings[inningsnumber].player[viewplayer-1].getname());
outtextxy(20,285,"Balls:");
outtextxy(90,285,itoa(team[teamnumber].innings[inningsnumber].player[viewplayer-1].getballs(),change,10));
outtextxy(120,285,"Runs:");
outtextxy(190,285,itoa(team[teamnumber].innings[inningsnumber].player[viewplayer-1].getrunsscored(),change,10));
outtextxy(220,285,"fours:");
outtextxy(290,285,itoa(team[teamnumber].innings[inningsnumber].player[viewplayer-1].getfours(),change,10));
outtextxy(320,285,"sixes:");
outtextxy(390,285,itoa(team[teamnumber].innings[inningsnumber].player[viewplayer-1].getsixes(),change,10));
outtextxy(420,285,"S/R:");
if(team[teamnumber].innings[inningsnumber].player[viewplayer-1].getballs()==0)
outtextxy(490,285,"0");
else
outtextxy(490,285,gcvt(100*team[teamnumber].innings[inningsnumber].player[viewplayer-1].getrunsscored()/team[teamnumber].innings[inningsnumber].player[viewplayer-1].getballs(),3,str));



outtextxy(20,300,"Bowler");
outtextxy(70,300,"Name");
outtextxy(140,300,"O");
outtextxy(170,300,"M");
outtextxy(200,300,"R");
outtextxy(230,300,"W");

for(m=1;m<7;m++)
{
	for(p=0;p<11;p++)
	{
	if(team[!teamnumber].innings[inningsnumber].player[p].getbowlernum()==m)
		{
		outtextxy(20,300+(15*m),itoa(team[!teamnumber].innings[inningsnumber].player[p].getbowlernum(),change,10));
		outtextxy(70,300+(15*m),team[!teamnumber].innings[inningsnumber].player[p].getname());
		outtextxy(140,300+(15*m),itoa(team[!teamnumber].innings[inningsnumber].player[p].getovers(),change,10));
		outtextxy(170,300+(15*m),itoa(team[!teamnumber].innings[inningsnumber].player[p].getmaidens(),change,10));
		outtextxy(200,300+(15*m),itoa(team[!teamnumber].innings[inningsnumber].player[p].getrunsconceeded(),change,10));
		outtextxy(230,300+(15*m),itoa(team[!teamnumber].innings[inningsnumber].player[p].getwickets(),change,10));
		}
	}
}

 
};



void game::toss()
{
char call;
int coin;
randomize();
clearviewport();
setbkcolor(6);
outtextxy(20,20,"TIME FOR THE TOSS");
do{
outtextxy(20,40,team[0].getteamname());
outtextxy(120,40,"Call (H)ead or (T)ails");
call=getche();
}while((call!='H')&&(call!='h')&&(call!='t')&&(call!='T'));

coin=random(6)+random(6)+random(6)+random(6)+random(6);
coin=coin%2;
if(coin==0)
outtextxy(20,55,"The coin has come down HEAD");
else
outtextxy(20,55,"The coin has come down TAIL");

if(((coin==0)&&((call=='h')||(call=='H')))||((coin==1)&&((call=='t')||(call=='T'))))
{
outtextxy(20,70,team[0].getteamname());
outtextxy(120,70,"you won the toss choose bat 'Y' or bowl 'N'");
call=getche();
if((call=='Y')||(call=='y'))
tosschange=0;
else
tosschange=1;
}
else
{
outtextxy(20,70,team[1].getteamname());
outtextxy(120,70,"you won the toss choose bat 'Y' or bowl 'N'");
call=getche();
if((call=='Y')||(call=='y'))
tosschange=1;
else
tosschange=0;

}


};





void game::inningsoverscreen()
{

int i;
char temper[5];
clearviewport();
setbkcolor(6);


	for(i=0;i<inningsnumber+followon+tosschange+1;i++)
	{
         if((tosschange==1)&&(i==0))continue;
	 if((i==2)&&(followon))continue;

	
	 outtextxy(30,0+((i+1-tosschange)*50),team[(i+followon-tosschange)%2].getteamname());
	 outtextxy(150,0+((i+1-tosschange)*50),itoa((i+2-tosschange)/2,temper,10));
	 outtextxy(180,0+((i+1-tosschange)*50),"INNINGS");
	 outtextxy(30,15+((i+1-tosschange)*50),itoa(team[i%2].innings[(i-tosschange)/2].getinningsruns(),temper,10));
	 if(team[i+tosschange].innings[(i-tosschange)/2].getwickets()==10)
	 outtextxy(70,15+((i+1-tosschange)*50),"All Out");
	 
	 outtextxy(70,15+((i+1-tosschange)*50),"For");
	 outtextxy(100,15+((i+1-tosschange)*50),itoa(team[(i+tosschange)%2].innings[(i-tosschange)/2].getwickets(),temper,10));
	 outtextxy(130,15+((i+1-tosschange)*50),"Declared");
	}					
				  
				  



if((inningsnumber==1)&&(abs(team[0].innings[0].getinningsruns()-team[1].innings[0].getinningsruns())>200))
{
outtextxy(50,30+((i-2)*50),team[!tosschange].getteamname());
outtextxy(140,30+((i-2)*50),"You Lead by");
outtextxy(260,30+((i-2)*50),itoa((abs(team[0].innings[0].getinningsruns()-team[1].innings[0].getinningsruns())),temper,10));
outtextxy(50,60+((i-2)*50),"Press 'Y'to enforce the followon 'N' to batt");
	do{
	temper[0]=getch();
	}while((temper[0]!='Y')&&(temper[0]!='y')&&(temper[0]!='N')&&(temper[0]!='n'));
}


if((temper[0]=='Y')||(temper[0]=='y'))
{
followon=1;

}

//if(inningsnumber==1)followon==1;     //testing line

if((inningsnumber==3)&&(team[(inningsnumber+tosschange)%2].innings[1].getinningsruns()+team[(inningsnumber+tosschange)%2].innings[0].getinningsruns()-team[(1+inningsnumber+tosschange)%2].innings[0].getinningsruns()<0))
{
outtextxy(50,30+((i-2)*50),team[(1+inningsnumber+tosschange+followon)%2].getteamname());
outtextxy(140,30+((i-2)*50),"Won by an Innings and");
outtextxy(340,30+((i-2)*50),itoa((team[(1+inningsnumber+tosschange+followon)%2].innings[0].getinningsruns()-team[(inningsnumber+tosschange)%2].innings[1].getinningsruns()-team[(inningsnumber+tosschange)%2].innings[0].getinningsruns()),temper,10));
outtextxy(370,30+((i-2)*50),"Runs");
}
//cout << inningsnumber;
if(inningsnumber==3)
{
	if((team[(inningsnumber+tosschange)%2].innings[0].getinningsruns()+team[(inningsnumber+tosschange)%2].innings[1].getinningsruns()-team[(1+inningsnumber+tosschange)%2].innings[0].getinningsruns()-team[(1+inningsnumber+tosschange)%2].innings[1].getinningsruns())>0)
	{
	outtextxy(50,30+((i-2)*50),team[(inningsnumber+tosschange)%2].getteamname());
	outtextxy(140,30+((i-2)*50),"Won by");
	outtextxy(200,30+((i-2)*50),itoa(10-team[(inningsnumber+tosschange)%2].innings[1].getwickets(),temper,10));
	outtextxy(230,30+((i-2)*50),"Wickets");
	}
	else if(team[(inningsnumber+tosschange)%2].innings[1].getwickets()==10)
	{
	outtextxy(50,30+((i-2)*50),team[(1+inningsnumber+tosschange)%2].getteamname());
	outtextxy(140,30+((i-2)*50),"Won by");
	outtextxy(200,30+((i-2)*50),itoa((team[(1+inningsnumber+tosschange)%2].innings[0].getinningsruns()+team[(1+inningsnumber+tosschange)%2].innings[1].getinningsruns()-team[(inningsnumber+tosschange)%2].innings[0].getinningsruns()-team[(inningsnumber+tosschange)%2].innings[1].getinningsruns()),temper,10));
	outtextxy(230,30+((i-2)*50),"Runs");
	}
	else
	outtextxy(50,30+((inningsnumber+followon+tosschange)*50),"MATCH DRAWN");
}


outtextxy(30,420,"Press any key to continue");
getch();


}


void game::pause(int i)
{
double j,k,l;

 for(l=0;l<i;l++)
 {
	for(j=0;j<55*gamespeed;j++)
	{
		for(k=0;k<2;k++){k=k+1;k=k-1;}
	}
 }
}


void game::createshotarray()
{
int s=ARRAYSIZE,i,x,y;
char trace_file[25];
FILE *ftrc;

strcpy(trace_file,"shot.dat");
if ((ftrc = fopen(trace_file,"r")) == NULL){
		strcpy (trace_file, "Cannot open trace file ");
		printf("\n%s", trace_file);
		fcloseall();
		exit(1);
	}

for(i=0;i<s;i++)
{
fscanf(ftrc,"%i %i %s\n",&x,&y);
shotarray[i][0]=x;
shotarray[i][1]=y;
}
//cout << "\n" << x <<" " << y;

fclose(ftrc);


}


int game::wicket(int howout,int playernumber)
{
int newbat,r;
char newbattemp[4];

team[(inningsnumber+tosschange+followon+1)%2].innings[inningsnumber/2].player[howout/10].changewickets();

if(howout!=9)
{
team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[playernumber-1].changehowout(howout);
team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setwickfall();
}
if(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getwickets()==10)
{
return 99;
}

scoreboard((inningsnumber+tosschange+followon)%2,inningsnumber/2);
r=0;

	do{
	outtextxy(30,420+(r*15),"Please enter new batsman value (0 to declare) :");
	gotoxy(55,25);
	cout << "\n\n                                                     ";
	outtextxy(30,420+(r*15),"Please enter new batsman value (0 to declare) :");
//	scanf("%i",&newbat);

	cin >> newbattemp;
	newbat=atoi(newbattemp);
	if(!strcmp(newbattemp,"0"))
	newbat=15;
	else  newbat=atoi(newbattemp);

	r++;
		if(newbat==15)
		{
		team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setdeclared();
		return 99;
		}
	}while((team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[newbat-1].gethowout()!=0)||(newbat<1)||(newbat>11));


team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[newbat-1].changehowout(9);
	if((howout!=0)&&(howout!=4)&&(howout!=9))
	{
	team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setbatsmanfacing(newbat-1);
	}
return newbat;
}



void game::over(int bowlernum)
{
int closefielder,overball,shotnumber,runshot=0;
char overballs[5];
char runs[5];		 
int extratag=1;
randomize();
	
int i;



do{

setbkcolor(GREEN);
clearviewport();
extratag=1;
runshot=0;

itoa(overball,overballs,7);
setcolor(56);
outtextxy(230,5,"TEST MATCH");
outtextxy(10,30,"BATSMAN");
//cout << team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[bowlernum].getoversball();
//cout << team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[bowlernum].getname();
//cout << team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[bowlernum].getovers();

outtextxy(10,55,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()-1].getname());
itoa(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()-1].getrunsscored(),runs,10);
outtextxy(100,55,runs);

outtextxy(10,80,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getnonstriker()-1].getname());
itoa(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getnonstriker()-1].getrunsscored(),runs,10);
outtextxy(100,80,runs);
outtextxy(220,30,itoa(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getinningsruns(),runs,10));
outtextxy(250,30,"ARE"  "   FOR");

outtextxy(350,30,itoa(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getwickets(),runs,10));


	outtextxy(230,55,team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[bowlernum].getname());
	

outtextxy(300,55,"BOWLING TO ");
outtextxy(390,55,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()-1].getname());

if(inningsnumber==3)
{
outtextxy(10,120,itoa(1+team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getinningsruns()+team[(inningsnumber+tosschange+followon)%2].innings[(inningsnumber-2)/2].getinningsruns()-team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getinningsruns()-team[(1+inningsnumber+tosschange+followon)%2].innings[(inningsnumber-2)/2].getinningsruns(),runs,10));
outtextxy(30,120,"Needed to win");
}

outtextxy(580,160,itoa(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[bowlernum].getoversball(),runs,10));
setcolor(63);

//Field Outline and stumps
	setlinestyle(0,0,1);
	wickets(250,300);
	wickets(350,300);
boundary();


pause(100);

batsmanready();
for(i=0;i<10;i++)
{
fielderready(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].getx(),team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].gety(),0);
}
batsmannonstrike(340,320);

for(i=420;i>350;i--)
{
pause(1);
setcolor(2);
bowler((i+1),298);
setcolor(63);
bowler(i,298);
}
setcolor(2);
bowler(351,298);
setcolor(63);
bowlerbowled(350,298);
setcolor(6);
for(i=345;i>280;i--)
{
pause(1);
setcolor(2);
rectangle(i+1,305-((abs(i-294))*3/9),i+2,306-((abs(i-294))*3/9));
setcolor(6);
rectangle(i,305-((abs(i-295))*3/9),i+1,306-((abs(i-295))*3/9));
}

setcolor(2);
rectangle(i+1,305-((abs(i-294))*3/9),i+2,306-((abs(i-294))*3/9));
gotoxy(20,20);

if(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber].player[bowlernum].getbowlernum()==6)
shotnumber=2-team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[bowlernum].getovers()/8;
else if(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber].player[bowlernum].getbowlernum()==5)
shotnumber=0;
else if(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber].player[bowlernum].getbowlernum()==4)
shotnumber=(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[bowlernum].getovers()/10)-1;
else if(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber].player[bowlernum].getbowlernum()==3)
shotnumber=abs(1-(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[bowlernum].getovers()/5))-1;
else if(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber].player[bowlernum].getbowlernum()==2)
shotnumber=abs(1-(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[bowlernum].getovers()/4))-1;
else
shotnumber=team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[bowlernum].getovers()/6;
shotnumber=shotnumber+team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber].player[bowlernum].getbowlernum()-1-abs(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()-1-2)-abs(2-((team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()].getrunsscored()+7)/17));
//printf("%i\n",shotnumber);

shot(shotnumber);
setcolor(2);
batsmanready();
setcolor(63);
batsmanshot(0);

if((ballx<200)&&(bally<360)&&(bally>290)&&(random(3)==0))
{
extratag=0;
rectangle(260,110,310,125);
floodfill(275,115,63);
setcolor(56);
outtextxy(265,115,"EXTRAS");
}
 

if((bally>450)||(bally<160)||(ballx<30)||(ballx>580)||((100-ballx)+(230-bally)>70)||((100-ballx)+(bally-380)>70)||((ballx-510)+(230-bally)>70)||((ballx-510)+(bally-380)>70))
{
rectangle(260,135,310,150);
floodfill(275,140,63);
setcolor(56);
	
	if(random(11)==0)
	{
	outtextxy(265,140,"6-RUNS");
		if(extratag)
		{
		team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(6,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing());
					 runshot=6;
		}else
		{
		team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(0,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing());
		team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(6,0);
                }
	}
	else
	{
	outtextxy(265,140,"4-RUNS");
		if(extratag)
		{
		team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(4,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing());
		runshot=4;
		}
		else
		{
		team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(0,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing());
		team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(4,0);
		}
	}
pause(200);
continue;
}
if(((team[(inningsnumber+tosschange)%2].innings[0].getinningsruns()+team[(inningsnumber+tosschange)%2].innings[1].getinningsruns()-team[(1+inningsnumber+tosschange)%2].innings[0].getinningsruns()-team[(1+inningsnumber+tosschange)%2].innings[1].getinningsruns())<0)&&(inningsnumber==3))return;



	if((ballx==245)&&(bally==310))       //If wicketkeeper takes ball
	{
                team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(0,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing());
		if(random(160-(6*(abs(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()-3))))==0)  //should be 140
		{
			setcolor(2);
			wickets(250,300);
			batsmanshot(0);
			setcolor(63);
			batsmanshot(1);
			brokenwicket(250,300);
			for(i=0;i<10;i++)
			{
				if(i==closefielder)
				continue;
			wicketkeeper(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].getx(),team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].gety());
			}
			rectangle(260,135,410,150);
			floodfill(275,140,63);
			setcolor(56);
			outtextxy(265,140,"PLAYER OUT STUMPED");
			pause(200);

			team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setbatsmanfacing(wicket((bowlernum*10)+3,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()));
			if(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()==99)
			{
			return;
			}
			continue;
		}

		if(random(85-(2*(abs(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()-3))))==0)
		{
			for(i=0;i<10;i++)
			{
				if(i==closefielder)
				continue;
			wicketkeeper(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].getx(),team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].gety());
			}
			rectangle(260,135,460,150);
			floodfill(275,140,63);
			setcolor(56);
			outtextxy(265,140,"PLAYER OUT CAUGHT KEEPER");
			pause(200);

			team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setbatsmanfacing(wicket((bowlernum*10)+1,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()));
			if(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()==99)
			{
			return;
			}
			continue;
		}
	 wicketkeeper(245,310);
	 rectangle(260,135,370,150);
	 floodfill(275,140,63);
	 setcolor(56);
	 outtextxy(265,140,"WICKET KEEPER");
	 pause(200);
	 continue;
	}

	//setcolor(4);
		//cout<< ball.x << ball.y;
		if((ballx==250)&&(bally==310))
		{
                team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(0,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing());
			for(i=0;i<10;i++)
			{
				if(i==closefielder)
				continue;
			wicketkeeper(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].getx(),team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].gety());
			}
			rectangle(260,135,387,150);
			floodfill(275,140,63);
			setcolor(56);
			outtextxy(265,140,"WICKET - BOWLED");
			setcolor(2);
			wickets(250,300);
			setcolor(63);
			brokenwicket(250,300);
			pause(200);
			team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setbatsmanfacing(wicket((bowlernum*10)+2,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()));
			if(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()==99)
			{
			return;
			}
			continue;
		}


		if((ballx==260)&&(bally==310))
		{
		 team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(0,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing());
			for(i=0;i<10;i++)
			{
				if(i==closefielder)
				continue;
			wicketkeeper(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].getx(),team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].gety());
			}
			rectangle(260,135,387,150);
			floodfill(275,140,63);
			setcolor(56);
			outtextxy(265,140,"WICKET - L.B.W.");
			pause(200);
			team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setbatsmanfacing(wicket((bowlernum*10)+5,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()));
			if(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()==99)
			{
			return;
			}
			continue;
		}


closefielder=closestfielder();
	if((random(75-(2*(abs(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()-3))))==0)&&(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[closefielder].getx()==ballx)&&(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[closefielder].gety()==bally))
	{
	 team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(0,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing());
		for(i=0;i<10;i++)
		{
			if(i==closefielder)
			continue;
		wicketkeeper(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].getx(),team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].gety());
		}
		rectangle(260,135,410,150);
		floodfill(275,140,63);
		setcolor(56);
		outtextxy(265,140,"PLAYER OUT CAUGHT FIELDER");
		pause(200);

		team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setbatsmanfacing(wicket((bowlernum*10)+1,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()));
		if(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()==99)
		{
		return;
		}
		continue;
	}
//cout <<runshot;
runshot=run(closefielder,extratag);

setcolor(6);
if(((team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getwickets()==10)||(team[(inningsnumber+tosschange)%2].innings[0].getinningsruns()+team[(inningsnumber+tosschange)%2].innings[1].getinningsruns()-team[(1+inningsnumber+tosschange)%2].innings[0].getinningsruns()-team[(1+inningsnumber+tosschange)%2].innings[1].getinningsruns())<0)&&(inningsnumber==3))return;

}while(1!=(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[bowlernum].changeoversball(runshot)));                  //End of for loop (over finished)



	i=team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing();
	team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setbatsmanfacing(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getnonstriker());
	team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setnonstriker(i);

	team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeovers();
	return;
}




void game::shot(int shotnum)
{
int s,x,y;
//char trace_file[25];

s=random(400);
//cout << s;
setcolor(6);
s=s+shotnum;
if(s<0)s=0;

x=shotarray[s][0];
y=shotarray[s][1];
			 //x=260;
			 //y=310;
			 ballx=x;
			 bally=y;
			  if(x==245&&y==310)
			  return;
			 line(265,305,x,y);
			 pause(10);
			 setcolor(2);
			 line(265,305,x,y);
			 setcolor(6);
			 rectangle(x,y,x-1,y-1);

}


int game::closestfielder()
{
unsigned long distance=500,old_distance=500;
int closefield=0,i;
	for(i=0;i<9;i++)
	{
	 distance=(sqrt((double)
				(  ((abs (team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].getx()-ballx))/10)  *  ((abs(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].getx()-ballx))/10)  )+
				(  ((abs(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].gety()-bally))/10)  *  ((abs(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[i].gety()-bally))/10)  )));
	if(distance<old_distance)
		{
		closefield=i;
		old_distance=distance;
		}
	}
fielderready(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[closefield].getx(),team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[closefield].gety(),1);
setcolor(6);
fieldergo(team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[closefield].getx(),team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[closefield].gety());
setcolor(63);
return closefield;
}


int game::closestwicket()
{
unsigned long distance,old_distance;

	 distance=(sqrt(
				(  ((abs(250-ballx))/10)  *  ((abs(250-ballx))/10)  )+
				(  ((abs(300-bally))/10)  *  ((abs(300-bally))/10)  )));

	old_distance=(sqrt(
				(  ((abs(350-ballx))/10)  *  ((abs(350-ballx))/10)  )+
				(  ((abs(300-bally))/10)  *  ((abs(300-bally))/10)  )));
//	cout <<"\n"<<distance<<" "<< old_distance;
	if(distance<old_distance)
	{return 1;
	}
	return 0;
}


int game::run(int field,int extratag)
{
char a;
int runshot=0;
int i,p,thow=0,wick;
float percentage=0,throwspeed;
int x,y;
throwspeed=random(42)+random(42)+random(42)+33;
throwspeed=throwspeed/100;

x=team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[field].getx();
y=team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].player[field].gety();

rectangle(270,130,355,145);
floodfill(275,140,63);
setcolor(56);
outtextxy(275,135,"RUN (Y/N)?");
	if(closestwicket()==0)
	wick=1;
	else
	wick=0;

do{
a=getch();
	if((a=='N')||(a=='n'))
	continue;
	else if((a=='Y')||(a=='y'))
		{
			setcolor(2);
			batsmanshot(0);
			fieldergo(x,y);
			setcolor(63);
			batsmannonstrike(264,309);
			for(i=0;i<131;i++)   //was87
			{
			 if((x!=ballx)&&!thow)
			 {
			 setcolor(2);
				fielderrun(x,y);
			 setcolor(6);
				if(ballx>x)    //player runs horizontally
				{
				fielderrun(x+1,y);
				x=1+x;
				}
				else
				{
				fielderrun(x-1,y);
				x=x-1;
				}
			 }
			 else if((y!=bally)&&!thow)      //player runs vertically
			 {
			 setcolor(2);
				fielderrun(x,y);
			 setcolor(6);
				if(bally>y)
				{
				y=y+1;
				fielderrun(x,y+1);
				}
				else
				{
				fielderrun(x,y-1);
				y=y-1;
				}
			 }
			 else                                  //player throws ball
			 {
			 thow=1;
			 setcolor(6);
			 line(x,y,ballx,bally);
			 ballx=x-((int)(x-(250+(100*wick)))*percentage/100);
			 bally=y-((int)(y-300)*percentage/100);
			 percentage+=throwspeed;
			 gotoxy(10,10);
			 //cout << throwspeed << "*"<< percentage << " ";
			 	if((percentage>100)&&(!random(4)||(random(87)-i>-15)))
				 {
				 setcolor(2);
				 wickets(250+100*wick,300);
				 setcolor(63);
				 brokenwicket(250+100*wick,300);
				 outtextxy(275,150,"RUNOUT");
				 pause(600);

						if(!extratag)
						team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(runshot,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing());
						else
						team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(runshot,0);



							if((wick+runshot)%2==0)
							{
								team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setnonstriker(wicket(4,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getnonstriker()));
								if(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getnonstriker()==99)
								{
								team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setdeclared();
								return runshot;
								}
							}
							else
							{
								team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setbatsmanfacing(wicket(4,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()));
								if(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing()==99)
								{
								team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setdeclared();
								return runshot;
								}
							if((runshot%2)==1)
							{
							p=team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing();
							team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setbatsmanfacing(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getnonstriker());
							team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setnonstriker(p);
							}
						}
				 return runshot;
				 }
				 else if(percentage>100)
				 {
				 outtextxy(275,150,"RUNOUT MISSED");
				 a='n';
				 pause(600);
				 break;
				 }

			 }

			 if(i<114)      //was76
			 {
			 setcolor(2);
			 batsmannonstrike((i/3*2)+264,309);
			 batsmannonstrike(340-(i/3*2),320);
			 setcolor(63);
			 batsmannonstrike(((i+1)/3*2)+264,309);
			 batsmannonstrike(340-((i+1)/3*2),320);
			 pause(2);
			 }
			 else
			 {
			 setcolor(2);
			 batsmannonstrike(340,309+(i*2/3)-76);
			 batsmannonstrike(264,320-(i*2/3)+76);

			 setcolor(63);
			 batsmannonstrike(340,309-76+((i+1)*2/3));
			 batsmannonstrike(264,320+76-((i+1)*2/3));
			 pause(1);


			 }

			}//end of for loop 87
			runshot++;
		}//end of if else y

  }while((a!='N')&&(a!='n'));
	if(extratag)
	{
        team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(runshot,team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing());
	}else
	team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].changeinningsruns(runshot,0);

	
	if((runshot%2)==1)
	{
	p=team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getbatsmanfacing();
	team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setbatsmanfacing(team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getnonstriker());
	team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].setnonstriker(p);
	}

	if(!extratag)
	runshot=0;

	return runshot;
}


