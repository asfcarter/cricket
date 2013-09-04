#include <conio.h>
#include <iostream.h>
#include <graphics.h>
#include "screen.h"

void screen::firstscreen()
{
setcolor(53);
setbkcolor(0);
clearviewport();
setcolor(3);
setfillstyle(1,3);
rectangle(10,10,50,30);                      //T
rectangle(20,30,40,90);
floodfill(20,20,3);
floodfill(30,60,3);

rectangle(70,10,90,90);                     //E
rectangle(90,10,110,30);
rectangle(90,40,110,60);
rectangle(90,70,110,90);
floodfill(80,50,3);
floodfill(100,20,3);
floodfill(100,50,3);
floodfill(100,80,3);

rectangle(130,10,170,30);                  //S
rectangle(130,30,150,40);
rectangle(130,40,170,60);
rectangle(150,60,170,70);
rectangle(130,70,170,90);
floodfill(150,20,3);
floodfill(150,50,3);
floodfill(150,80,3);
floodfill(140,35,3);
floodfill(160,65,3);

rectangle(190,10,230,30);                  //T
rectangle(200,30,220,90);
floodfill(200,20,3);
floodfill(210,60,3);

rectangle(10,210,90,230);                  //M
rectangle(10,230,30,290);
rectangle(40,230,60,290);
rectangle(70,230,90,290);
floodfill(20,220,3);
floodfill(20,260,3);
floodfill(50,260,3);
floodfill(80,260,3);

rectangle(110,210,130,290);               //A
rectangle(130,210,150,230);
rectangle(150,210,170,290);
rectangle(130,250,150,270);
floodfill(120,220,3);
floodfill(140,220,3);
floodfill(160,220,3);
floodfill(140,260,3);

rectangle(190,210,230,230);                  //T
rectangle(200,230,220,290);
floodfill(200,220,3);
floodfill(210,260,3);

rectangle(250,210,290,230);                  //C
rectangle(250,230,270,270);
rectangle(250,270,290,290);
floodfill(270,220,3);
floodfill(260,260,3);
floodfill(260,280,3);

rectangle(310,210,330,290);                  //H
rectangle(330,240,350,260);
rectangle(350,210,370,290);
floodfill(320,250,3);
floodfill(340,250,3);
floodfill(360,250,3);

outtextxy(280,310,"Version 1.1");
outtextxy(20,450,"Press any key to enter game");
getch();
setfillstyle(1,63);
}


void screen::secondscreen()
{

	setbkcolor(6);
	clearviewport();
	setcolor(63);
	outtextxy(300,10,"TEST MATCH");
	outtextxy(50,40,"Test match is a game produced solely by Andrew Carter");
	outtextxy(50,60,"to emulate the old test match game on the Amstrad CPC464");
	outtextxy(30,150,"Press 'Y' to use computer names");
	outtextxy(30,170,"Press 'N' to use your names");

}

void screen::wickets(int i,int j)
{
line(i+1,j+9,i+1,j+1);
line(i+2,j+9,i+2,j+1);
line(i+5,j+9,i+5,j+1);
line(i+6,j+9,i+6,j+1);
line(i+9,j+9,i+9,j+1);
line(i+10,j+9,i+10,j+1);
line(i+2,j+1,i+9,j+1);
line(i+2,j,i+9,j);
}

void screen::brokenwicket(int i,int j)
{
line(i+1,j+9,i+1,j+1);
line(i+2,j+9,i+2,j+1);
line(i+5,j+9,i+5,j+1);
line(i+6,j+9,i+6,j+1);
line(i+9,j+9,i+9,j+1);
line(i+10,j+9,i+10,j+1);
line(i+2,j-2,i+4,j);
line(i+6,j,i+9,j-2);
}


void screen::batsmanready()
{
//Batsman in start position
	line(262,300,263,300);
	line(262,301,265,301);
	line(264,302,266,302);
	line(266,303,266,303);
	line(267,300,267,309);
	line(268,299,268,309);
	line(269,296,269,305);
	line(270,296,270,306);
	line(270,307,270,309);
	line(271,296,271,309);
	line(272,301,272,302);
	line(272,309,272,309);
}


void screen::batsmannonstrike(int i,int j)
{
line(i-1,j-1,i-1,j-6);
line(i,j-1,i,j-9);
line(i+1,j-1,i+1,j-9);
line(i+2,j-8,i+2,j-9);
line(i+3,j,i+3,j-10);
line(i+4,j,i+4,j-13);
line(i+5,j-4,i+5,j-13);
line(i+6,j,i+6,j-13);
line(i+7,j,i+7,j-10);
line(i+8,j,i+8,j);
line(i+8,j-7,i+8,j-9);
}


void screen::batsmanshot(int stumped)
{
int i=0;
if(!stumped)
i=10;

	line(274-i,300,274-i,309);
	line(275-i,299,275-i,309);
	line(276-i,296,276-i,305);
	line(277-i,296,277-i,306);
	line(277-i,307,277-i,309);
	line(278-i,296,278-i,309);
	line(279-i,301,279-i,302);
	line(279-i,309,279-i,309);
	line(279-i,303,281-i,303);
	line(280-i,302,282-i,302);
	line(281-i,301,283-i,301);
	line(282-i,300,283-i,300);
}



void screen::fielderready(int i,int j,int selected)
{
if(selected)
setcolor(2);
line(i,j,i,j);
line(i,j-6,i,j-9);
line(i-1,j,i-1,j-9);
line(i-2,j,i-2,j-13);
line(i-2,j-11,i-2,j-13);
line(i-3,j-5,i-3,j-13);
line(i-4,j,i-4,j-13);
line(i-4,j-11,i-4,j-13);
line(i-5,j,i-5,j-9);
line(i-6,j,i-6,j);
line(i-6,j-6,i-6,j-9);
setcolor(63);            //make colour go back to default white
}

void screen::wicketkeeper(int i,int j)
{
setcolor(2);
fielderready(245,310,0);
line(i,j,i,j);
line(i,j-12,i,j-9);
line(i-1,j,i-1,j-9);
line(i-2,j,i-2,j-13);
line(i-2,j-11,i-2,j-13);
line(i-3,j-5,i-3,j-13);
line(i-4,j,i-4,j-13);
line(i-4,j-11,i-4,j-13);
line(i-5,j,i-5,j-9);
line(i-6,j,i-6,j);
line(i-6,j-12,i-6,j-9);
}


void screen::fieldergo(int i,int j)
{
line(i,j,i,j);
line(i,j-5,i,j-8);
line(i-1,j,i-1,j-1);
line(i-1,j-5,i-1,j-8);
line(i-2,j-1,i-2,j-8);
line(i-3,j-2,i-3,j-6);
line(i-4,j,i-4,j-6);
line(i-5,j,i-5,j-5);
line(i-6,j-1,i-6,j-4);
line(i-7,j,i-7,j-3);
line(i-8,j,i-9,j);
}



void screen::fielderrun(int i,int j)
{
	if(((i+j)%18)>9)
	{
	line(i,j,i,j-2);
	line(i,j-7,i,j-7);
	line(i-1,j-2,i-1,j-13);
	line(i-2,j-4,i-2,j-13);
	line(i-3,j-3,i-3,j-4);
	line(i-3,j-6,i-3,j-6);
	line(i-3,j-10,i-3,j-13);
	line(i-3,j-8,i-5,j-8);
	line(i-4,j-3,i-5,j-3);
	line(i-5,j-9,i-6,j-9);
	line(i-6,j-1,i-6,j-3);
	}
	else
	{
	line(i,j-7,i+1,j-7);
	line(i,j-2,i+2,j-2);
	line(i-1,j-2,i-1,j-13);
	line(i-2,j-4,i-2,j-13);
	line(i-3,j,i-3,j-3);
	line(i-3,j-8,i-3,j-8);
	line(i-3,j-10,i-3,j-13);
	}
}




void screen::bowler(int i,int j)
{
line(i-1,j-9,i-1,j-9);
line(i,j,i,j);
line(i,j-9,i,j-9);
line(i+1,j,i+1,j-2);
line(i+1,j-9,i+1,j-10);
line(i+2,j,i+2,j-13);
line(i+3,j-2,i+3,j-13);
line(i+4,j-4,i+4,j-13);
line(i+5,j,i+5,j-10);
line(i+6,j,i+6,j-3);
line(i+6,j-9,i+6,j-10);
line(i+7,j-9,i+7,j-10);
line(i+8,j-10,i+8,j-11);
}



void screen::bowlerbowled(int i,int j)
{
line(i,j-9,i,j-11);
line(i+1,j-12,i+1,j-12);
line(i+1,j-8,i+1,j-10);
line(i+2,j,i+2,j-10);
line(i+3,j,i+3,j-13);
line(i+4,j-4,i+4,j-13);
line(i+5,j,i+5,j-13);
line(i+6,j,i+6,j-10);
line(i+7,j-9,i+7,j-10);
line(i+7,j-12,i+7,j-12);
line(i+8,j-9,i+8,j-11);
}


void screen::boundary()
{
	line(100,450,510,450);
	line(100,160,510,160);
	line(30,230,30,380);
	line(580,230,580,380);
	arc(100,230,90,180,70);
	arc(510,230,0,90,70);
	arc(100,380,180,270,70);
	arc(510,380,270,0,70);
}
