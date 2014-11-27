#include <stdexcept>
#include <string>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "screen.h"
#include "global.h"
#include "shot.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

void SetRenderDrawColor(SDL_Renderer *rend, SDL_Color color);


/*
*  Lesson 6: True Type Fonts with SDL_ttf
*/
//TODO: Write the lesson code
//Screen attributes
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;



void SetRenderDrawColor(SDL_Renderer *rend, SDL_Color color)
{
	SDL_SetRenderDrawColor(rend,color.r,color.g,color.b,color.a);
}


/*
*  Generate a texture containing the message we want to display
*  @param message The message we want to display
*  @param fontFile The font we want to use to render the text
*  @param color The color we want the text to be
*  @param fontSize The size we want the font to be
*  @return An SDL_Texture containing the rendered message
*/
SDL_Texture* RenderText(std::string message, std::string fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer){
	//Open the font
	TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (font == NULL){
		std::cout << "TTF_OpenFont";
		return NULL;
	}	
	//We need to first render to a surface as that's what TTF_RenderText
	//returns, then load that surface into a texture
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	if (surf == NULL){
		TTF_CloseFont(font);
		std::cout << "TTF_RenderText";
		return NULL;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == NULL){
		std::cout << "CreateTexture";	}
	//Clean up the surface and font
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}
/*
*  Draw an SDL_exture to an SDL_Renderer at position x, y
*  @param x: x coordinate to draw too
*  @param y: y coordinate to draw too
*  @param tex: the source texture we want to draw
*  @param rend: the renderer we want to draw too
*/
void ApplySurface(int x, int y, SDL_Color color, const char *text, SDL_Renderer *rend, int size){
	//First we must create an SDL_Rect for the position of the image, as SDL
	//won't accept raw coordinates as the image's position
	SDL_Rect pos;
	SDL_Texture*  image;
	
//	try {
		image = RenderText(text, "./SourceSansPro-Regular.ttf", color, size, rend);
//	}
//	catch (const std::runtime_error &e){
//		std::cout << e.what() << std::endl;
//		return 4;
//	}	
	pos.x = x;
	pos.y = y;

/*	if(image == NULL) 
	{
	SDL_SetRenderDrawColor(rend,55,255,255,0);
	}
	else
	{
*/	SDL_SetRenderDrawColor(rend,color.r,color.g,color.b,color.a);
	
/*	SDL_RenderDrawPoint(rend,100,y+100);
	SDL_RenderDrawPoint(rend,100,y+101);
	SDL_RenderDrawPoint(rend,101,y+100);
	SDL_RenderDrawPoint(rend,100,y+102);
	SDL_RenderDrawPoint(rend,102,y+100);
	SDL_RenderDrawPoint(rend,100,y+103);
	SDL_RenderDrawPoint(rend,103,y+100);
	SDL_RenderDrawPoint(rend,100,y+104);
	SDL_RenderDrawPoint(rend,104,y+100);
*/



	//We also need to query the texture to get its width and height to use
	SDL_QueryTexture(image, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(rend, image, NULL, &pos);

	SDL_DestroyTexture(image);

}

bool Screen::toss_screen(Team team[2])
{
SDL_Keycode call;
int coin;
//Our event type
SDL_Event e;	
//For tracking if we want to quit
bool quit = false;
bool tosschange;
int text_size = 15;

	srand(time(NULL));
	
	SetRenderDrawColor(renderer, RED);
	SDL_RenderClear(renderer);
	
	ApplySurface(20,20,WHITE,"TIME FOR THE TOSS",renderer,text_size);

	do{
		ApplySurface(20,40,WHITE,team[0].get_team_name(),renderer,text_size);
		ApplySurface(120,40,WHITE,"Call (H)ead or (T)ails",renderer,text_size);
		//Update the screen
		SDL_RenderPresent(renderer);

		while (!quit){
			//Event Polling
			while (SDL_PollEvent(&e)){
				//If user presses any key
				if (e.type == SDL_KEYDOWN && ((e.key.keysym.sym == SDLK_h)||(e.key.keysym.sym == SDLK_t)))
				{
					quit = true;
					call=e.key.keysym.sym;
				}
			}
		}

	}while((call!='H')&&(call!='h')&&(call!='t')&&(call!='T'));

	coin=rand()+rand()+rand()+rand()+rand();
	coin=coin%2;

	if(coin==0)
	{
		ApplySurface(20,55,WHITE,"The coin has come down HEAD",renderer,text_size);
	}
	else
	{
		ApplySurface(20,55,WHITE,"The coin has come down TAIL",renderer,text_size);
	}
	
	if(((coin==0)&&((call=='h')||(call=='H')))||((coin==1)&&((call=='t')||(call=='T'))))
	{
		ApplySurface(20,70,WHITE,team[0].get_team_name(),renderer,text_size);
		ApplySurface(120,70,WHITE,"you won the toss choose bat 'Y' or bowl 'N'",renderer,text_size);
		//Update the screen
		SDL_RenderPresent(renderer);

		quit=false;
		while (!quit){
			//Event Polling
			while (SDL_PollEvent(&e)){
				//If user presses any key
				if (e.type == SDL_KEYDOWN && ((e.key.keysym.sym == SDLK_y)||(e.key.keysym.sym == SDLK_n)))
				{
					quit = true;
					call=e.key.keysym.sym;
				}
			}
		}

		if((call=='Y')||(call=='y'))
		{
			tosschange=0;
		}
		else
		{
			tosschange=1;
		}
	}
	else
	{
		ApplySurface(20,70,WHITE,team[1].get_team_name(),renderer,text_size);
		ApplySurface(120,70,WHITE,"you won the toss choose bat 'Y' or bowl 'N'",renderer,text_size);
		//Update the screen
		SDL_RenderPresent(renderer);

		quit=false;
		while (!quit){
			//Event Polling
			while (SDL_PollEvent(&e)){
				//If user presses any key
				if (e.type == SDL_KEYDOWN && ((e.key.keysym.sym == SDLK_y)||(e.key.keysym.sym == SDLK_n)))
				{
					quit = true;
					call=e.key.keysym.sym;
				}
			}
		}
		

		if((call=='Y')||(call=='y'))
		{
			tosschange=1;
		}
		else
		{
			tosschange=0;
		}
	}
	
return tosschange;
}

void Screen::display_scoreboard(Team *batting, Team *bowling, int innings_number)
{
int batsman_num, bowler_num, player_num;
char change_str[20];
int text_size=15;
bowler_info bowler_info;
int fall_count=1;

	SetRenderDrawColor(renderer,BLACK);
	SDL_RenderClear(renderer);
	ApplySurface(10, 10, BLUE,batting->get_team_name(), renderer,text_size);
	ApplySurface(500, 10, WHITE,"Overs", renderer,text_size);
	
	sprintf(change_str,"%i",batting->innings[innings_number].get_overs());
	ApplySurface(550, 10, WHITE,change_str, renderer,text_size);
	ApplySurface(20, 25, WHITE,"Batsman", renderer,text_size);
	ApplySurface(80, 25, WHITE,"Name", renderer,text_size);
	ApplySurface(160, 25, WHITE,"Status", renderer,text_size);
	ApplySurface(580, 25, WHITE,"Runs", renderer,text_size);

	if(batting->innings[innings_number].get_batsman_facing()!=0)
	{
		ApplySurface(10,25+(15*batting->innings[innings_number].get_batsman_facing()), RED,"*", renderer,1.5*text_size);
	}

	for(batsman_num=1;batsman_num<12;batsman_num++)
	{
		player_num=batting->innings[innings_number].get_player_number(batsman_num);
		
		sprintf(change_str,"%i",batsman_num);
		ApplySurface(20, 25+(15*batsman_num), WHITE,change_str, renderer,text_size);	
		ApplySurface(80, 25+(15*batsman_num), WHITE,batting->player[player_num-1].get_name(), renderer,text_size);		
		
			switch((batting->innings[innings_number].get_batsman_how_out(batsman_num))%10)
			{
			 case DNB:
			 	{
					  break;
				}
			 case CAUGHT:
			 	{
					  ApplySurface(160,25+(15*batsman_num), WHITE,"CAUGHT", renderer,text_size);
					  break;
				}
			 case BOWLED:
			 	{
					  ApplySurface(160,25+(15*batsman_num), WHITE,"BOWLED", renderer,text_size);
					  break;
				}
			 case STUMPED:
			 	{
					  ApplySurface(160,25+(15*batsman_num), WHITE,"STUMPED", renderer,text_size);
					  break;
				}
			 case RUN_OUT:
			 	{
					  ApplySurface(160,25+(15*batsman_num), WHITE,"RUN OUT", renderer,text_size);
					  break;
				}
			 case LBW:
			 	{
					  ApplySurface(160,25+(15*batsman_num), WHITE,"L.B.W.", renderer,text_size);
					  break;
				}
			 case NOT_OUT:
			 	{
					  ApplySurface(160,25+(15*batsman_num), WHITE,"NOT OUT", renderer,text_size);
					  break;
				}
			}

			if((batting->innings[innings_number].get_batsman_how_out(batsman_num)/10!=0) && (batting->innings[innings_number].get_batsman_how_out(batsman_num)/10<7))
			{
			ApplySurface(230,25+(15*batsman_num),WHITE,bowling->player[bowling->get_bowler_player_number(batting->innings[innings_number].get_batsman_how_out(batsman_num)/10)-1].get_name(), renderer,text_size);
			}
						
			if(batting->innings[innings_number].get_batsman_how_out(batsman_num) != DNB)
			{
				sprintf(change_str,"%i",batting->innings[innings_number].get_batsman_runs(batsman_num));
				ApplySurface(580,25+(15*batsman_num), WHITE,change_str, renderer,text_size);
			}		
	}
	
	ApplySurface(20,205, WHITE,"EXTRAS", renderer,text_size);
	sprintf(change_str,"%i",batting->innings[innings_number].get_extras());
	ApplySurface(80,205, WHITE,change_str, renderer,text_size);
	ApplySurface(440,205, WHITE,"TOTAL", renderer,text_size);
	sprintf(change_str,"%i",batting->innings[innings_number].get_innings_total());
	ApplySurface(490,205, WHITE,change_str, renderer,text_size);
	ApplySurface(520,205, WHITE,"FOR", renderer,text_size);
	if(batting->innings[innings_number].get_wickets()!=10)
	{
		sprintf(change_str,"%i",batting->innings[innings_number].get_wickets());
		ApplySurface(560,205, WHITE,change_str, renderer,text_size);
	}
	else
	{
		ApplySurface(560,205, WHITE,"ALL OUT", renderer,text_size);
	}
	
	ApplySurface(20,225, WHITE,"========================================================================", renderer,text_size);

	ApplySurface(20,240, WHITE,"Fall:", renderer,text_size);
	while((fall_count<=batting->innings[innings_number].get_wickets())&&(fall_count!=10))
	{
		sprintf(change_str,"%i",fall_count);
		ApplySurface(20+(fall_count*50),255, WHITE,change_str, renderer,text_size);
		ApplySurface(30+(fall_count*50),255, WHITE,"-", renderer,text_size);
		sprintf(change_str,"%i",batting->innings[innings_number].get_wicket_fall(fall_count));
		ApplySurface(40+(fall_count*50),255, WHITE,change_str, renderer,text_size);
		fall_count++;
	};	

ApplySurface(20,270, WHITE,"Batsman:", renderer,text_size);
//ApplySurface(130,270, WHITE,team[teamnumber].innings[inningsnumber].player[viewplayer-1].getname(), renderer,text_size);
ApplySurface(20,285, WHITE,"Balls:", renderer,text_size);
//ApplySurface(90,285,itoa(team[teamnumber].innings[inningsnumber].player[viewplayer-1].getballs(),change,10), renderer,text_size);
ApplySurface(120,285, WHITE,"Runs:", renderer,text_size);
//ApplySurface(190,285,itoa(team[teamnumber].innings[inningsnumber].player[viewplayer-1].getrunsscored(),change,10), renderer,text_size);
ApplySurface(220,285, WHITE,"fours:", renderer,text_size);
//ApplySurface(290,285,itoa(team[teamnumber].innings[inningsnumber].player[viewplayer-1].getfours(),change,10), renderer,text_size);
ApplySurface(320,285, WHITE,"sixes:", renderer,text_size);
//ApplySurface(390,285,itoa(team[teamnumber].innings[inningsnumber].player[viewplayer-1].getsixes(),change,10), renderer,text_size);
ApplySurface(420,285, WHITE,"S/R:", renderer,text_size);
//if(team[teamnumber].innings[inningsnumber].player[viewplayer-1].getballs()==0)
//ApplySurface(490,285, WHITE,"0", renderer,text_size);
//else
//ApplySurface(490,285, WHITE,gcvt(100*team[teamnumber].innings[inningsnumber].player[viewplayer-1].getrunsscored()/team[teamnumber].innings[inningsnumber].player[viewplayer-1].getballs(),3,str), renderer,text_size);

	ApplySurface(20,300, WHITE,"Bowler", renderer,text_size);
	ApplySurface(70,300, WHITE,"Name", renderer,text_size);
	ApplySurface(140,300, WHITE,"O", renderer,text_size);
	ApplySurface(170,300, WHITE,"M", renderer,text_size);
	ApplySurface(200,300, WHITE,"R", renderer,text_size);
	ApplySurface(230,300, WHITE,"W", renderer,text_size);

	if(batting->innings[innings_number].get_last_bowler()!=0)
	{
		ApplySurface(10,300+(15*batting->innings[innings_number].get_last_bowler()), RED,"*", renderer,1.5*text_size);
	}
	
	for(bowler_num=1;bowler_num<7;bowler_num++)
	{
		sprintf(change_str,"%i",bowler_num);
		ApplySurface(20,300+(15*bowler_num), WHITE,change_str, renderer,text_size);
	
		for(player_num=1;player_num<12;player_num++)
		{				
			if(bowling->player[player_num-1].get_bowler_number()==bowler_num)
			{
				bowler_info=batting->innings[innings_number].get_bowler_info(bowler_num);
				ApplySurface(70,300+(15*bowler_num), WHITE,bowling->player[player_num-1].get_name(), renderer,text_size);

				sprintf(change_str,"%i",bowler_info.overs);
				ApplySurface(140,300+(15*bowler_num), WHITE, change_str, renderer,text_size);
				sprintf(change_str,"%i",bowler_info.maidens);
				ApplySurface(170,300+(15*bowler_num), WHITE, change_str, renderer,text_size);
				sprintf(change_str,"%i",bowler_info.runs_conceeded);
				ApplySurface(200,300+(15*bowler_num), WHITE, change_str, renderer,text_size);
				sprintf(change_str,"%i",bowler_info.wickets);
				ApplySurface(230,300+(15*bowler_num), WHITE, change_str, renderer,text_size);
			}
		}
	}
}

int Screen::init_screen()
{
	//Start up SDL and make sure it went ok
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	if (TTF_Init() == -1){
		std::cout << TTF_GetError() << std::endl;
		return 2;
	}

	//Setup our window and renderer
	window = SDL_CreateWindow("Test Match", SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL){
		std::cout << SDL_GetError() << std::endl;
		return 2;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED 
		| SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL){
		std::cout << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		return 3;
	}


	return 0;
}

int Screen::firstscreen()
{
	SetRenderDrawColor(renderer,BLACK);
	SDL_RenderClear(renderer);
	ApplySurface(10, -60, CYAN,"TEST", renderer,290);
	ApplySurface(10, 180, CYAN,"MATCH", renderer,210);
	ApplySurface(510, 390, CYAN,"Version 2.1", renderer,25);

	spacebar_to_continue(75,420,WHITE,35);
	return 0;
}

SDL_Keycode Screen::secondscreen()
{
	//Our event type
	SDL_Event e;	
	//For tracking if we want to quit
	bool quit = false;
	SDL_Keycode key = SDLK_h;

		SetRenderDrawColor(renderer,RED);
		SDL_RenderClear(renderer);
		ApplySurface(265, 10, WHITE,"TEST MATCH", renderer,20);
		ApplySurface(40, 30, WHITE,"Test match is based on the Amstrad CPC464 game", renderer,20);
		ApplySurface(40, 50, WHITE,"Test match is a game produced solely by Andrew Carter", renderer,20);
		ApplySurface(180, 70, WHITE,"Press 'Y' to use computer names", renderer,20);
		ApplySurface(180, 90, WHITE,"Press 'N' to use your names", renderer,20);

		//Update the screen
		SDL_RenderPresent(renderer);

	while (!quit){
		//Event Polling
		while (SDL_PollEvent(&e)){
			//If user closes he window
			if (e.type == SDL_QUIT)
				quit = true;
			//If user presses any key
			//If user presses any key
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_y)
			{
				key = (SDL_Keycode) e.key.keysym.sym;
				quit = true;
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_n)
			{
				key = (SDL_Keycode) e.key.keysym.sym;
				quit = true;
			}
		}


	}
	
        SDL_Delay(500);  // Pause execution for 3000 milliseconds, for example

	return key;
}


int Screen::destroy_screen()
{
	//Destroy the various items
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	
	return 0;
}



void Screen::wickets(int i,int j)
{
	SDL_RenderDrawLine(renderer,i+1,j+9,i+1,j+1);
	SDL_RenderDrawLine(renderer,i+2,j+9,i+2,j+1);
	SDL_RenderDrawLine(renderer,i+5,j+9,i+5,j+1);
	SDL_RenderDrawLine(renderer,i+6,j+9,i+6,j+1);
	SDL_RenderDrawLine(renderer,i+9,j+9,i+9,j+1);
	SDL_RenderDrawLine(renderer,i+10,j+9,i+10,j+1);
	SDL_RenderDrawLine(renderer,i+2,j+1,i+9,j+1);
	SDL_RenderDrawLine(renderer,i+2,j,i+9,j);
}

void Screen::brokenwicket(int i,int j)
{
	SDL_RenderDrawLine(renderer,i+1,j+9,i+1,j+1);
	SDL_RenderDrawLine(renderer,i+2,j+9,i+2,j+1);
	SDL_RenderDrawLine(renderer,i+5,j+9,i+5,j+1);
	SDL_RenderDrawLine(renderer,i+6,j+9,i+6,j+1);
	SDL_RenderDrawLine(renderer,i+9,j+9,i+9,j+1);
	SDL_RenderDrawLine(renderer,i+10,j+9,i+10,j+1);
	SDL_RenderDrawLine(renderer,i+2,j-2,i+4,j);
	SDL_RenderDrawLine(renderer,i+6,j,i+9,j-2);
}


void Screen::batsmanready()
{
//Batsman in start position
	SDL_RenderDrawLine(renderer,262,300,263,300);
	SDL_RenderDrawLine(renderer,262,301,265,301);
	SDL_RenderDrawLine(renderer,264,302,266,302);
	SDL_RenderDrawLine(renderer,266,303,266,303);
	SDL_RenderDrawLine(renderer,267,300,267,309);
	SDL_RenderDrawLine(renderer,268,299,268,309);
	SDL_RenderDrawLine(renderer,269,296,269,305);
	SDL_RenderDrawLine(renderer,270,296,270,306);
	SDL_RenderDrawLine(renderer,270,307,270,309);
	SDL_RenderDrawLine(renderer,271,296,271,309);
	SDL_RenderDrawLine(renderer,272,301,272,302);
	SDL_RenderDrawLine(renderer,272,309,272,309);
}


void Screen::batsmannonstrike(int i,int j)
{
	SDL_RenderDrawLine(renderer,i-1,j-1,i-1,j-6);
	SDL_RenderDrawLine(renderer,i,j-1,i,j-9);
	SDL_RenderDrawLine(renderer,i+1,j-1,i+1,j-9);
	SDL_RenderDrawLine(renderer,i+2,j-8,i+2,j-9);
	SDL_RenderDrawLine(renderer,i+3,j,i+3,j-10);
	SDL_RenderDrawLine(renderer,i+4,j,i+4,j-13);
	SDL_RenderDrawLine(renderer,i+5,j-4,i+5,j-13);
	SDL_RenderDrawLine(renderer,i+6,j,i+6,j-13);
	SDL_RenderDrawLine(renderer,i+7,j,i+7,j-10);
	SDL_RenderDrawLine(renderer,i+8,j,i+8,j);
	SDL_RenderDrawLine(renderer,i+8,j-7,i+8,j-9);
}


void Screen::batsmanshot(int stumped)
{
int i=0;
	if(!stumped)
	{
		i=10;
	}
	SDL_RenderDrawLine(renderer,274-i,300,274-i,309);
	SDL_RenderDrawLine(renderer,275-i,299,275-i,309);
	SDL_RenderDrawLine(renderer,276-i,296,276-i,305);
	SDL_RenderDrawLine(renderer,277-i,296,277-i,306);
	SDL_RenderDrawLine(renderer,277-i,307,277-i,309);
	SDL_RenderDrawLine(renderer,278-i,296,278-i,309);
	SDL_RenderDrawLine(renderer,279-i,301,279-i,302);
	SDL_RenderDrawLine(renderer,279-i,309,279-i,309);
	SDL_RenderDrawLine(renderer,279-i,303,281-i,303);
	SDL_RenderDrawLine(renderer,280-i,302,282-i,302);
	SDL_RenderDrawLine(renderer,281-i,301,283-i,301);
	SDL_RenderDrawLine(renderer,282-i,300,283-i,300);
}



void Screen::fielderready(int i,int j,int selected)
{
	if(selected)
	{
		SetRenderDrawColor(renderer,RED);  //setcolor(2);
	}
	
	SDL_RenderDrawLine(renderer,i,j,i,j);
	SDL_RenderDrawLine(renderer,i,j-6,i,j-9);
	SDL_RenderDrawLine(renderer,i-1,j,i-1,j-9);
	SDL_RenderDrawLine(renderer,i-2,j,i-2,j-13);
	SDL_RenderDrawLine(renderer,i-2,j-11,i-2,j-13);
	SDL_RenderDrawLine(renderer,i-3,j-5,i-3,j-13);
	SDL_RenderDrawLine(renderer,i-4,j,i-4,j-13);
	SDL_RenderDrawLine(renderer,i-4,j-11,i-4,j-13);
	SDL_RenderDrawLine(renderer,i-5,j,i-5,j-9);
	SDL_RenderDrawLine(renderer,i-6,j,i-6,j);
	SDL_RenderDrawLine(renderer,i-6,j-6,i-6,j-9);
	SetRenderDrawColor(renderer,WHITE);  //setcolor(63);            //make colour go back to default white
}

void Screen::wicketkeeper(int i,int j)
{
	fielderready(245,310,0);
	SDL_RenderDrawLine(renderer,i,j,i,j);
	SDL_RenderDrawLine(renderer,i,j-12,i,j-9);
	SDL_RenderDrawLine(renderer,i-1,j,i-1,j-9);
	SDL_RenderDrawLine(renderer,i-2,j,i-2,j-13);
	SDL_RenderDrawLine(renderer,i-2,j-11,i-2,j-13);
	SDL_RenderDrawLine(renderer,i-3,j-5,i-3,j-13);
	SDL_RenderDrawLine(renderer,i-4,j,i-4,j-13);
	SDL_RenderDrawLine(renderer,i-4,j-11,i-4,j-13);
	SDL_RenderDrawLine(renderer,i-5,j,i-5,j-9);
	SDL_RenderDrawLine(renderer,i-6,j,i-6,j);
	SDL_RenderDrawLine(renderer,i-6,j-12,i-6,j-9);
}


void Screen::fieldergo(int i,int j)
{
	SDL_RenderDrawLine(renderer,i,j,i,j);
	SDL_RenderDrawLine(renderer,i,j-5,i,j-8);
	SDL_RenderDrawLine(renderer,i-1,j,i-1,j-1);
	SDL_RenderDrawLine(renderer,i-1,j-5,i-1,j-8);
	SDL_RenderDrawLine(renderer,i-2,j-1,i-2,j-8);
	SDL_RenderDrawLine(renderer,i-3,j-2,i-3,j-6);
	SDL_RenderDrawLine(renderer,i-4,j,i-4,j-6);
	SDL_RenderDrawLine(renderer,i-5,j,i-5,j-5);
	SDL_RenderDrawLine(renderer,i-6,j-1,i-6,j-4);
	SDL_RenderDrawLine(renderer,i-7,j,i-7,j-3);
	SDL_RenderDrawLine(renderer,i-8,j,i-9,j);
}



void Screen::fielderrun(int i,int j)
{
	if(((i+j)%18)>9)
	{
		SDL_RenderDrawLine(renderer,i,j,i,j-2);
		SDL_RenderDrawLine(renderer,i,j-7,i,j-7);
		SDL_RenderDrawLine(renderer,i-1,j-2,i-1,j-13);
		SDL_RenderDrawLine(renderer,i-2,j-4,i-2,j-13);
		SDL_RenderDrawLine(renderer,i-3,j-3,i-3,j-4);
		SDL_RenderDrawLine(renderer,i-3,j-6,i-3,j-6);
		SDL_RenderDrawLine(renderer,i-3,j-10,i-3,j-13);
		SDL_RenderDrawLine(renderer,i-3,j-8,i-5,j-8);
		SDL_RenderDrawLine(renderer,i-4,j-3,i-5,j-3);
		SDL_RenderDrawLine(renderer,i-5,j-9,i-6,j-9);
		SDL_RenderDrawLine(renderer,i-6,j-1,i-6,j-3);
	}
	else
	{
		SDL_RenderDrawLine(renderer,i,j-7,i+1,j-7);
		SDL_RenderDrawLine(renderer,i,j-2,i+2,j-2);
		SDL_RenderDrawLine(renderer,i-1,j-2,i-1,j-13);
		SDL_RenderDrawLine(renderer,i-2,j-4,i-2,j-13);
		SDL_RenderDrawLine(renderer,i-3,j,i-3,j-3);
		SDL_RenderDrawLine(renderer,i-3,j-8,i-3,j-8);
		SDL_RenderDrawLine(renderer,i-3,j-10,i-3,j-13);
	}
}




void Screen::bowler(int i,int j)
{
	SDL_RenderDrawLine(renderer,i-1,j-9,i-1,j-9);
	SDL_RenderDrawLine(renderer,i,j,i,j);
	SDL_RenderDrawLine(renderer,i,j-9,i,j-9);
	SDL_RenderDrawLine(renderer,i+1,j,i+1,j-2);
	SDL_RenderDrawLine(renderer,i+1,j-9,i+1,j-10);
	SDL_RenderDrawLine(renderer,i+2,j,i+2,j-13);
	SDL_RenderDrawLine(renderer,i+3,j-2,i+3,j-13);
	SDL_RenderDrawLine(renderer,i+4,j-4,i+4,j-13);
	SDL_RenderDrawLine(renderer,i+5,j,i+5,j-10);
	SDL_RenderDrawLine(renderer,i+6,j,i+6,j-3);
	SDL_RenderDrawLine(renderer,i+6,j-9,i+6,j-10);
	SDL_RenderDrawLine(renderer,i+7,j-9,i+7,j-10);
	SDL_RenderDrawLine(renderer,i+8,j-10,i+8,j-11);
}


void Screen::bowlerbowled(int i,int j)
{
	SDL_RenderDrawLine(renderer,i,j-9,i,j-11);
	SDL_RenderDrawLine(renderer,i+1,j-12,i+1,j-12);
	SDL_RenderDrawLine(renderer,i+1,j-8,i+1,j-10);
	SDL_RenderDrawLine(renderer,i+2,j,i+2,j-10);
	SDL_RenderDrawLine(renderer,i+3,j,i+3,j-13);
	SDL_RenderDrawLine(renderer,i+4,j-4,i+4,j-13);
	SDL_RenderDrawLine(renderer,i+5,j,i+5,j-13);
	SDL_RenderDrawLine(renderer,i+6,j,i+6,j-10);
	SDL_RenderDrawLine(renderer,i+7,j-9,i+7,j-10);
	SDL_RenderDrawLine(renderer,i+7,j-12,i+7,j-12);
	SDL_RenderDrawLine(renderer,i+8,j-9,i+8,j-11);
}


void Screen::arc(int x,int y,int start_angle,int end_angle,int radius)
{
int i;
float j;
	for(i=start_angle;i<end_angle;i++)
	{ 
                    j=(3.141592654*i)/180;
		    SDL_RenderDrawPoint(renderer, x + radius * cos(j), y - radius * sin(j));
	}
}

void Screen::boundary()
{	
	SDL_RenderDrawLine(renderer,100,160,510,160);  //top
	SDL_RenderDrawLine(renderer,100,450,510,450);  //bottom
	SDL_RenderDrawLine(renderer,30,230,30,380);    //left
	SDL_RenderDrawLine(renderer,580,230,580,380);  //right
        arc(100,230,90,180,70);
        arc(510,230,0,90,70);
        arc(100,380,180,270,70);
        arc(510,380,270,360,70);


}


void Screen::display_ball_field(Team *batting, Team *bowling, int innings_num)
{
int text_size=15;
char change_str[20];
SDL_Rect rect;
int shotnumber;
int ballx,bally;
bool extratag=0;
int closefielder;

	SetRenderDrawColor(renderer,GREEN);
	SDL_RenderClear(renderer);

	SetRenderDrawColor(renderer,WHITE);
	boundary();


	ApplySurface(230,5, BLACK,"TEST MATCH",renderer,text_size);
	ApplySurface(10,30, BLACK,"BATSMAN",renderer,text_size);

	ApplySurface(10,55, BLACK,batting->player[batting->innings[innings_num].get_player_number(batting->innings[innings_num].get_batsman_facing())-1].get_name(),renderer,text_size);
	sprintf(change_str,"%i",batting->innings[innings_num].get_batsman_runs(batting->innings[innings_num].get_batsman_facing()));
	ApplySurface(100,55,BLACK,change_str,renderer,text_size);


	ApplySurface(10,80, BLACK,batting->player[batting->innings[innings_num].get_player_number(batting->innings[innings_num].get_non_striker())-1].get_name(),renderer,text_size);
	sprintf(change_str,"%i",batting->innings[innings_num].get_batsman_runs(batting->innings[innings_num].get_non_striker()));
	ApplySurface(100,80,BLACK,change_str,renderer,text_size);

	ApplySurface(160,30, BLACK,batting->get_team_name(),renderer,text_size);
	ApplySurface(250,30, BLACK,"ARE"  "          FOR",renderer,text_size);

	sprintf(change_str,"%i",batting->innings[innings_num].get_innings_total());
	ApplySurface(280,30,BLACK,change_str,renderer,text_size);

	sprintf(change_str,"%i",batting->innings[innings_num].get_wickets());
	ApplySurface(370,30,BLACK,change_str,renderer,text_size);

	ApplySurface(230,55, BLACK,bowling->player[bowling->get_bowler_player_number(batting->innings[innings_num].get_current_bowler())-1].get_name(),renderer,text_size);
	
	ApplySurface(300,55, BLACK,"BOWLING TO ",renderer,text_size);

	ApplySurface(390,55, BLACK,batting->player[batting->innings[innings_num].get_player_number(batting->innings[innings_num].get_batsman_facing())-1].get_name(),renderer,text_size);


/*
if(inningsnumber==3)
{
outtextxy(10,120,itoa(1+team[(inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getinningsruns()+team[(inningsnumber+tosschange+followon)%2].innings[(inningsnumber-2)/2].getinningsruns()-team[(1+inningsnumber+tosschange+followon)%2].innings[inningsnumber/2].getinningsruns()-team[(1+inningsnumber+tosschange+followon)%2].innings[(inningsnumber-2)/2].getinningsruns(),runs,10));
outtextxy(30,120,"Needed to win");
}
*/
	sprintf(change_str,"%i",batting->innings[innings_num].get_balls());
	ApplySurface(580,160,BLACK,change_str,renderer,text_size);

	SetRenderDrawColor(renderer,WHITE);
	wickets(250,300);
	wickets(350,300);


	batsmanready();
	for(int i=0;i<10;i++)
	{
		fielderready(bowling->player[i].get_x(),bowling->player[i].get_y(),0);
	}
	
	batsmannonstrike(340,320);

	for(int i=420;i>350;i--)
	{
		SetRenderDrawColor(renderer,WHITE);
		bowler(i,298);
		SDL_Delay(1);  // Pause execution for 3000 milliseconds, for example

		//Update the screen
		SDL_RenderPresent(renderer);

		SetRenderDrawColor(renderer,GREEN);
		bowler((i+1),298);
	}

	SetRenderDrawColor(renderer,WHITE);
	bowlerbowled(350,298);

	for(int i=345;i>280;i--)
	{
		rect.x = i;
		rect.y = 305-((abs(i-295))*3/9);
		rect.w = 2;
		rect.h = 2;
		
		SDL_Delay(1);  // Pause execution for 3000 milliseconds, for example
		SetRenderDrawColor(renderer,RED);
		SDL_RenderDrawRect(renderer,&rect);
		//Update the screen
		SDL_RenderPresent(renderer);

		SetRenderDrawColor(renderer,GREEN);
		SDL_RenderDrawRect(renderer,&rect);

	}




if(batting->innings[innings_num].get_current_bowler()==6)
	shotnumber=2-batting->innings[innings_num].get_bowler_overs(6)/8;
else if(batting->innings[innings_num].get_current_bowler()==5)
	shotnumber=0;
else if(batting->innings[innings_num].get_current_bowler()==4)
	shotnumber=(batting->innings[innings_num].get_bowler_overs(4)/10)-1;
else if(batting->innings[innings_num].get_current_bowler()==3)
	shotnumber=abs(1-(batting->innings[innings_num].get_bowler_overs(3)/5))-1;
else if(batting->innings[innings_num].get_current_bowler()==2)
	shotnumber=abs(1-(batting->innings[innings_num].get_bowler_overs(2)/4))-1;
else
	shotnumber=batting->innings[innings_num].get_bowler_overs(1)/6;

shotnumber=shotnumber+batting->innings[innings_num].get_current_bowler()-2-abs(batting->innings[innings_num].get_player_number(batting->innings[innings_num].get_batsman_facing())-1-2)-abs(2-((batting->innings[innings_num].get_batsman_runs(batting->innings[innings_num].get_batsman_facing())+7)/17));
//printf("%i\n",shotnumber);


	SetRenderDrawColor(renderer,GREEN);
	batsmanready();
	SetRenderDrawColor(renderer,WHITE);
	batsmanshot(0);

	shot(shotnumber,&ballx,&bally);

	closefielder=closestfielder(batting,ballx,bally);

//cout << closefielder << " " << ballx << " " << bally << "\n";

	if((ballx<200)&&(bally<360)&&(bally>290)&&((rand() % 3)==0))
	{
		SetRenderDrawColor(renderer,WHITE);
		extratag=1;
		rect.x = 260;
		rect.y = 110;
		rect.w = 50;
		rect.h = 15;
		SDL_RenderFillRect(renderer,&rect);
		
		ApplySurface(260,108,BLACK,"EXTRAS",renderer,text_size);
	}	

	if((bally>450)||(bally<160)||(ballx<30)||(ballx>580)||((100-ballx)+(230-bally)>70)||((100-ballx)+(bally-380)>70)||((ballx-510)+(230-bally)>70)||((ballx-510)+(bally-380)>70))
	{
		SetRenderDrawColor(renderer,WHITE);  //setcolor(63);            //make colour go back to default white
		rect.x = 260;
		rect.y = 110;
		rect.w = 50;
		rect.h = 15;
		SDL_RenderFillRect(renderer,&rect);
	
		if((rand() % 11)==0)
		{
			ApplySurface(260,108,BLACK,"6-RUNS",renderer,text_size);

			batting->innings[innings_num].change_innings_runs(6,extratag,NOT_OUT);
		}
		else
		{
			ApplySurface(260,108,BLACK,"4-RUNS",renderer,text_size);
			batting->innings[innings_num].change_innings_runs(4,extratag,NOT_OUT);
		}
//pause(200);
//continue;
	//Update the screen
	SDL_RenderPresent(renderer);

        SDL_Delay(1000);  // Pause execution for 3000 milliseconds, for example

	}
	else if((ballx==245)&&(bally==310))       //If wicketkeeper takes ball
	{
                		if((rand()%(160-(6*(abs(batting->innings[innings_num].get_player_number(batting->innings[innings_num].get_batsman_facing())-3)))))==0)  //should be 140
		{
			batting->innings[innings_num].change_innings_runs(0,0,STUMPED);
			SetRenderDrawColor(renderer,GREEN);
			wickets(250,300);
			batsmanshot(0);
			SetRenderDrawColor(renderer,WHITE);
			batsmanshot(1);
			brokenwicket(250,300);
			for(int i=0;i<10;i++)
			{			
				wicketkeeper(bowling->player[i].get_x(),bowling->player[i].get_y());
			}

			rect.x = 260;
			rect.y = 110;
			rect.w = 147;
			rect.h = 15;
			SDL_RenderFillRect(renderer,&rect);
		
			ApplySurface(260,108,BLACK,"PLAYER OUT STUMPED",renderer,text_size);

			//Update the screen
			SDL_RenderPresent(renderer);

		        SDL_Delay(1000);  // Pause execution for 3000 milliseconds, for example
		}
		else if(rand()%(85-(4*(abs(batting->innings[innings_num].get_player_number(batting->innings[innings_num].get_batsman_facing())-3))))==0)
		{
			batting->innings[innings_num].change_innings_runs(0,0,CAUGHT);
			for(int i=0;i<10;i++)
			{
				wicketkeeper(bowling->player[i].get_x(),bowling->player[i].get_y());
			}

			rect.x = 260;
			rect.y = 110;
			rect.w = 147;
			rect.h = 15;
			SDL_RenderFillRect(renderer,&rect);
		
			ApplySurface(260,108,BLACK,"PLAYER OUT CAUGHT KEEPER",renderer,text_size);

			//Update the screen
			SDL_RenderPresent(renderer);

		        SDL_Delay(1000);  // Pause execution for 3000 milliseconds, for example
		}
		else
		{
			batting->innings[innings_num].change_innings_runs(0,0,NOT_OUT);
	 		wicketkeeper(245,310);
			rect.x = 260;
			rect.y = 110;
			rect.w = 104;
			rect.h = 15;
			SDL_RenderFillRect(renderer,&rect);
		
			ApplySurface(260,108,BLACK,"WICKET KEEPER",renderer,text_size);

			//Update the screen
			SDL_RenderPresent(renderer);

		        SDL_Delay(1000);  // Pause execution for 3000 milliseconds, for example
		}
	}
	else if((ballx==250)&&(bally==310))
	{
		batting->innings[innings_num].change_innings_runs(0,0,BOWLED);
		for(int i=0;i<10;i++)
		{
			wicketkeeper(bowling->player[i].get_x(),bowling->player[i].get_y());
		}

		SetRenderDrawColor(renderer,GREEN);
		wickets(250,300);
		SetRenderDrawColor(renderer,WHITE);
		brokenwicket(250,300);

		rect.x = 260;
		rect.y = 110;
		rect.w = 116;
		rect.h = 15;
		SDL_RenderFillRect(renderer,&rect);
		
		ApplySurface(260,108,BLACK,"WICKET - BOWLED",renderer,text_size);

		//Update the screen
		SDL_RenderPresent(renderer);
	        SDL_Delay(1000);  // Pause execution for 3000 milliseconds, for example
	}
        else if((ballx==260)&&(bally==310))
	{
		batting->innings[innings_num].change_innings_runs(0,0,LBW);
		for(int i=0;i<10;i++)
		{
			wicketkeeper(bowling->player[i].get_x(),bowling->player[i].get_y());
		}

		rect.x = 260;
		rect.y = 110;
		rect.w = 101;
		rect.h = 15;
		SDL_RenderFillRect(renderer,&rect);
		
		ApplySurface(260,108,BLACK,"WICKET - L.B.W.",renderer,text_size);

		//Update the screen
		SDL_RenderPresent(renderer);
	        SDL_Delay(1000);  // Pause execution for 3000 milliseconds, for example
	}		
	else if((rand()%(80-(9*(abs(batting->innings[innings_num].get_player_number(batting->innings[innings_num].get_batsman_facing())-3))))==0)&&(batting->player[closefielder].get_x()==ballx)&&(batting->player[closefielder].get_y()==bally))
	{
		batting->innings[innings_num].change_innings_runs(0,0,CAUGHT);
		for(int i=0;i<10;i++)
		{
			wicketkeeper(bowling->player[i].get_x(),bowling->player[i].get_y());
		}

		rect.x = 260;
		rect.y = 110;
		rect.w = 191;
		rect.h = 15;
		SDL_RenderFillRect(renderer,&rect);
		
		ApplySurface(260,108,BLACK,"WICKET - PLAYER OUT CAUGHT FIELDER",renderer,text_size);

		//Update the screen
		SDL_RenderPresent(renderer);
	        SDL_Delay(1000);  // Pause execution for 3000 milliseconds, for example
	}
	else
	{
		run(batting,innings_num,extratag,closefielder,ballx,bally);


		//Update the screen
		SDL_RenderPresent(renderer);
	        SDL_Delay(1000);  // Pause execution for 3000 milliseconds, for example
	}
}


bool Screen::play_again(){
int text_size=15;
bool ret_val;
//Our event type
SDL_Event e;	
//For tracking if we want to quit
bool quit = false;


	SetRenderDrawColor(renderer,RED);
	SDL_RenderClear(renderer);
	
	ApplySurface(20,20,WHITE,"Do you want to play again? (Y/N)",renderer,text_size);
	SDL_RenderPresent(renderer);

	while (!quit){
		//Event Polling
		while (SDL_PollEvent(&e)){
			//If user presses any key
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_y)
			{
				quit = true;
				ret_val=true;
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_n)
			{
				quit = true;
				ret_val=false;
			}
			else if(e.type == SDL_KEYDOWN)
			{
				ApplySurface(20,20,WHITE,"Do you want to play again? (Y/N)",renderer,text_size);
				ApplySurface(20,50,WHITE,"BAD KEY!!!TRY AGAIN",renderer,text_size);
				SDL_RenderPresent(renderer);
			}
		}
	}

return ret_val;
}

void Screen::spacebar_to_continue(int i, int j, SDL_Color text_colour, int text_size)
{
//Our event type
SDL_Event e;	
//For tracking if we want to quit
bool quit = false;

	ApplySurface(i,j,text_colour,"Press <SPACEBAR> TO CONTINUE",renderer,text_size);

	//Update the screen
	SDL_RenderPresent(renderer);

	while (!quit){
		//Event Polling
		while (SDL_PollEvent(&e)){
			//If user presses any key
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
			{
				quit = true;
				
			}
		}
	}
}

void Screen::display_new_batsman(Team *batting, Team *bowling, int innings_number)
{
//Our event type
SDL_Event e;	
//For tracking if we want to quit
bool quit = false;
int input=-1;
char change_str[4];
int text_size=15;
bool ret_val=false;

	display_scoreboard(batting,bowling,innings_number);
	ApplySurface(20,420,WHITE,"Please enter new batsman value (0 to declare):",renderer,text_size);
	SDL_RenderPresent(renderer);

	while (!quit){
		//Event Polling
		while (SDL_PollEvent(&e)){
			//If user presses any key
			if ((e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)&&(input>-1))
			{
				ret_val=batting->innings[innings_number].set_new_batsman(input);
				
				if(ret_val==true)
				{
					quit = true;
				}
				else
				{
					display_scoreboard(batting,bowling,innings_number);
					ApplySurface(20,420,WHITE,"Please enter new batsman value (0 to declare):",renderer,text_size);
					input=-1; 
					ApplySurface(20,440,WHITE,"Bad batsman number. Please re-enter.",renderer,text_size);
					strcpy(change_str," ");
					ApplySurface(420,420,WHITE,change_str,renderer,text_size);
					//Update the screen
					SDL_RenderPresent(renderer);
				}				
			}
			else if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE)
			{			
				display_scoreboard(batting,bowling,innings_number);

				if((input>-1)&&(input<10))
				{
					input=-1; 
					strcpy(change_str," ");
					ApplySurface(420,420,WHITE,change_str,renderer,text_size);
				}
				else if(input>9)
				{
					input=input/10; 
					sprintf(change_str,"%i",input);
					ApplySurface(420,420,WHITE,change_str,renderer,text_size);
				}
				
				ApplySurface(20,420,WHITE,"Please enter new batsman value (0 to declare):",renderer,text_size);
				//Update the screen
				SDL_RenderPresent(renderer);

			}
			else if(e.type == SDL_KEYDOWN && ((e.key.keysym.sym >= SDLK_0)&&(e.key.keysym.sym <= SDLK_9)))
			{
				if(input==-1)
				{
					input=e.key.keysym.sym - 48;
				}
				else if(input < 10)
				{
					input=(input*10)+e.key.keysym.sym - 48;				
				}
				sprintf(change_str,"%i",input);
				ApplySurface(420,420,WHITE,change_str,renderer,text_size);
				//Update the screen
				SDL_RenderPresent(renderer);
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
				
			}
		}
	}

	display_scoreboard(batting,bowling,innings_number);
	SDL_RenderPresent(renderer);
}


void Screen::display_new_bowler(Team *batting, Team *bowling, int innings_number)
{
//Our event type
SDL_Event e;	
//For tracking if we want to quit
bool quit = false;
int input=-1;
int text_size=15;
bool ret_val;

	display_scoreboard(batting,bowling,innings_number);
	ApplySurface(20,420,WHITE,"Please enter next bowler (or U/D to see batsmans statistics)",renderer,text_size);
	SDL_RenderPresent(renderer);

	//Update the screen
	SDL_RenderPresent(renderer);

	while (!quit){
		//Event Polling
		while (SDL_PollEvent(&e)){
			if(e.type == SDL_KEYDOWN && ((e.key.keysym.sym >= SDLK_1)&&(e.key.keysym.sym <= SDLK_6)))
			{
				input=e.key.keysym.sym - SDLK_0;
			
				ret_val=batting->innings[innings_number].set_new_bowler(input);

				if(ret_val != true)
				{
					ApplySurface(20,440,WHITE,"Last bowler chosen, please re-enter!",renderer,text_size);
					//Update the screen
					SDL_RenderPresent(renderer);
				}
				else
				{
					quit = true;
				}
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_u)
			{
				quit = true;
				
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_d)
			{
				quit = true;
				
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_0)
			{
				ret_val=batting->innings[innings_number].set_new_batsman(0);
				quit = true;				
			}
		}
	}
}
 

void Screen::shot(int shot_number, int *ballx, int *bally)
{
int shot_random_number;
SDL_Rect rect;

  	/* generate secret number between 0 and 400: */
  	shot_random_number = rand() % 401;
 
	shot_random_number=shot_random_number+shot_number;
	if(shot_random_number<0)
	{
		shot_random_number=0;
	}
	
	*ballx=shot_array[shot_random_number][0];
	*bally=shot_array[shot_random_number][1];
	
	if((*ballx==245&&*bally==310)||(*ballx==250&&*bally==310)||(*ballx==260&&*bally==310))
	{
	  return;
	}
	
		SetRenderDrawColor(renderer,RED);
		SDL_RenderDrawLine(renderer,265,305,*ballx,*bally);
		SDL_RenderPresent(renderer);

		SDL_Delay(50);  // Pause execution for 3000 milliseconds, for example
		SetRenderDrawColor(renderer,GREEN);
		SDL_RenderDrawLine(renderer,265,305,*ballx,*bally);

		rect.x = *ballx;
		rect.y = *bally;
		rect.w = 2;
		rect.h = 2;
		SetRenderDrawColor(renderer,RED);
		SDL_RenderDrawRect(renderer,&rect);
		SDL_RenderPresent(renderer);
}



bool Screen::match_summary_screen(Team *batting, Team *bowling, int innings_number,int follow_on)
{
int i;
Team *team,*team2;
int text_size=15;
char change_str[4];
bool ret_val=false;

	SetRenderDrawColor(renderer,RED);
	SDL_RenderClear(renderer);
	
	for(i=0;i<innings_number+1;i++)
	{
	 if((i==0)||((i==2)&&(!follow_on))||((i==3)&&(follow_on)))
	 {
	 	team=batting;
	 }
	 else
	 {
	 	team=bowling;
	 }

	 ApplySurface(30,50+(i*50), WHITE,team->get_team_name(), renderer,text_size);
	 sprintf(change_str,"%i",(i+2)/2);
	 ApplySurface(150,50+(i*50), WHITE,change_str, renderer,text_size);
	 
	 ApplySurface(180,50+(i*50), WHITE,"INNINGS", renderer,text_size);
	 sprintf(change_str,"%i",team->innings[i/2].get_innings_total());
	 ApplySurface(30,65+(i*50), WHITE,change_str, renderer,text_size);

	 if(team->innings[i/2].get_wickets()==10)
	 {
		ApplySurface(70,65+(i*50), WHITE,"All Out", renderer,text_size);
	 }
	 else
	 {
		ApplySurface(70,65+(i*50), WHITE,"For", renderer,text_size);
		sprintf(change_str,"%i",team->innings[i/2].get_wickets());
		ApplySurface(100,65+(i*50), WHITE,change_str, renderer,text_size);
		ApplySurface(130,65+(i*50), WHITE,"Declared", renderer,text_size);
	 }
	}				

	if(innings_number==2)
	{
	 if(follow_on)
	 {
	 	team=bowling;
		team2=batting;
	 }
	 else
	 {
	 	team=batting;
		team2=bowling;
	 }

	 if((team2->innings[0].get_innings_total()-team->innings[0].get_innings_total()-team->innings[1].get_innings_total()>0))
	 {
	 	
			ApplySurface(50,190, WHITE,team2->get_team_name(), renderer,text_size);
			ApplySurface(140,190, WHITE,"win by an Innings and", renderer,text_size);
	sprintf(change_str,"%i",team2->innings[0].get_innings_total()-team->innings[0].get_innings_total()-team->innings[1].get_innings_total());
			ApplySurface(340,190, WHITE,change_str, renderer,text_size);
			ApplySurface(370,190, WHITE,"runs", renderer,text_size);
		ret_val=true;
	 }
	}


	if(innings_number==3)
	{

			if((batting->innings[0].get_innings_total()+batting->innings[1].get_innings_total()-bowling->innings[0].get_innings_total()-bowling->innings[1].get_innings_total())<0)
		{
			ApplySurface(50,280, WHITE,bowling->get_team_name(), renderer,text_size);
			ApplySurface(140,280, WHITE,"win by", renderer,text_size);
			sprintf(change_str,"%i",10-bowling->innings[1].get_wickets());
			ApplySurface(200,280, WHITE,change_str, renderer,text_size);
			ApplySurface(230,280, WHITE,"wickets", renderer,text_size);
		}
		else if(bowling->innings[1].get_wickets()==10)
		{
			ApplySurface(50,280, WHITE,batting->get_team_name(), renderer,text_size);
			ApplySurface(140,280, WHITE,"win by", renderer,text_size);
	sprintf(change_str,"%i",batting->innings[0].get_innings_total()+batting->innings[1].get_innings_total()-bowling->innings[0].get_innings_total()-bowling->innings[1].get_innings_total());
			ApplySurface(200,280, WHITE,change_str, renderer,text_size);
			ApplySurface(230,280, WHITE,"runs", renderer,text_size);
		}
		else
		{
			ApplySurface(50,280, WHITE,"MATCH DRAWN", renderer,text_size);
		}
		
		ret_val=true;
	}


return ret_val;
}


bool Screen::follow_on_decision(Team *batting, Team *bowling)
{
SDL_Keycode decision;
//Our event type
SDL_Event e;	
//For tracking if we want to quit
bool quit = false;
int text_size=15;
char change_str[4];

	 ApplySurface(50,145, WHITE,batting->get_team_name(), renderer,text_size);
	 ApplySurface(140,145, WHITE,"you lead by", renderer,text_size);
	 sprintf(change_str,"%i",batting->innings[0].get_innings_total()-bowling->innings[0].get_innings_total());
	 ApplySurface(260,145, WHITE,change_str, renderer,text_size);
	 ApplySurface(50,160, WHITE,"Press 'Y'to enforce the followon 'N' to batt", renderer,text_size);

	 SDL_RenderPresent(renderer);

		quit=false;
		while (!quit){
			//Event Polling
			while (SDL_PollEvent(&e)){
				//If user presses any key
				if (e.type == SDL_KEYDOWN && ((e.key.keysym.sym == SDLK_y)||(e.key.keysym.sym == SDLK_n)))
				{
					quit = true;
					decision=e.key.keysym.sym;
				}
			}
		}

	if(decision==SDLK_y)
	{
		return 1;
	}
	else
	{
		return 0;		
	}	 
}

int Screen::closestfielder(Team *team, int ballx, int bally)
{
unsigned long distance=500,old_distance=500;
int closefield=0,i;
	for(i=0;i<9;i++)
	{
	 distance=(sqrt((double)
				(  ((abs(team->player[i].get_x()-ballx))/10) * ((abs(team->player[i].get_x()-ballx))/10)  )+
				(  ((abs(team->player[i].get_y()-bally))/10) * ((abs(team->player[i].get_y()-bally))/10)  )));
	
		if(distance<old_distance)
		{
			closefield=i;
			old_distance=distance;
		}
	}
	
return closefield;
}



int Screen::closestwicket(int ballx, int bally)
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



void Screen::run(Team *team, int innings_num, int extratag, int closest_fielder, int ballx, int bally)
{
SDL_Keycode decision;
//Our event type
SDL_Event e;	
//For tracking if we want to quit
bool quit = false;
int runshot=0;
int i,thow=0;
int wick;
float throwspeed;
int x,y;
float percentage=0;
SDL_Rect rect;
int text_size=15;

throwspeed=(rand()%45)+(rand()%55)+(rand()%70)+10;
throwspeed=throwspeed/100;

SetRenderDrawColor(renderer,GREEN);
fielderready(team->player[closest_fielder].get_x(),team->player[closest_fielder].get_y(),0);
SetRenderDrawColor(renderer,RED);
fieldergo(team->player[closest_fielder].get_x(),team->player[closest_fielder].get_y());
SetRenderDrawColor(renderer,WHITE);



x=team->player[closest_fielder].get_x();
y=team->player[closest_fielder].get_y();


	if(closestwicket(ballx,bally)==0)
	wick=1;
	else
	wick=0;


	do{
		SetRenderDrawColor(renderer,WHITE);
		rect.x = 270;
		rect.y = 130;
		rect.w = 73;
		rect.h = 17;
		SDL_RenderFillRect(renderer,&rect);
		
		ApplySurface(270,128,BLACK,"RUN (Y/N)?",renderer,text_size);

		//Update the screen
		SDL_RenderPresent(renderer);

		quit=false;
		while (!quit){
			//Event Polling
			while (SDL_PollEvent(&e)){
				//If user presses any key
				if (e.type == SDL_KEYDOWN && ((e.key.keysym.sym == SDLK_y)||(e.key.keysym.sym == SDLK_n)))
				{
					quit = true;
					decision=e.key.keysym.sym;
				}
			}
		}

		if(decision==SDLK_n)
		{
			continue;
		}
		else if(decision==SDLK_y)
		{
			SetRenderDrawColor(renderer,GREEN);
			rect.x = 270;
			rect.y = 130;
			rect.w = 73;
			rect.h = 17;
			SDL_RenderFillRect(renderer,&rect);

			SetRenderDrawColor(renderer,GREEN);
			batsmanshot(0);
			fieldergo(x,y);
			SetRenderDrawColor(renderer,WHITE);
			batsmannonstrike(264,309);
			
			for(i=0;i<131;i++)   //was87
			{
			 if((x!=ballx)&&!thow)
			 {
				SetRenderDrawColor(renderer,GREEN);
				fielderrun(x,y);
				SetRenderDrawColor(renderer,RED);
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
				SetRenderDrawColor(renderer,GREEN);
				fielderrun(x,y);
				SetRenderDrawColor(renderer,RED);
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
				SetRenderDrawColor(renderer,RED);

				SDL_RenderDrawLine(renderer,x,y,ballx,bally);
			 	ballx=x-((int)(x-(250+(100*wick)))*percentage/100);
			 	bally=y-((int)(y-300)*percentage/100);
			 	percentage+=throwspeed;

			 	if((percentage>100)&&((!(rand()%6))||((rand()%150)-i>15)))
				{
					SetRenderDrawColor(renderer,GREEN);
				 	wickets(250+100*wick,300);
					SetRenderDrawColor(renderer,WHITE);
					brokenwicket(250+100*wick,300);


					rect.x = 270;
					rect.y = 130;
					rect.w = 60;
					rect.h = 15;
					SDL_RenderFillRect(renderer,&rect);
		
					ApplySurface(270,128,BLACK,"RUNOUT",renderer,text_size);

 
					if((wick+runshot)%2==0)
					{
	 					team->innings[innings_num].change_innings_runs(runshot,extratag,RUN_OUT_NON_STRIKER);
					}
					else
					{
	 					team->innings[innings_num].change_innings_runs(runshot,extratag,RUN_OUT);
					}
				 return;
				 }
				 else if(percentage>100)
				 {
					SetRenderDrawColor(renderer,WHITE);
					rect.x = 270;
					rect.y = 130;
					rect.w = 110;
					rect.h = 15;
					SDL_RenderFillRect(renderer,&rect);
		
					ApplySurface(270,128,BLACK,"RUNOUT MISSED",renderer,text_size);
				 	runshot++;
  					team->innings[innings_num].change_innings_runs(runshot,extratag,NOT_OUT);
					//Update the screen
					SDL_RenderPresent(renderer);
	        			SDL_Delay(1000);  // Pause execution for 3000 milliseconds, for example
					return;
				 }
				
			 	}

				 if(i<114)      //was76
				 {
					SetRenderDrawColor(renderer,GREEN);
					batsmannonstrike((i/3*2)+264,309);
					batsmannonstrike(340-(i/3*2),320);
					SetRenderDrawColor(renderer,WHITE);
			 		batsmannonstrike(((i+1)/3*2)+264,309);
			 		batsmannonstrike(340-((i+1)/3*2),320);
				 }
				 else
				 {
					SetRenderDrawColor(renderer,GREEN);
					batsmannonstrike(340,309+(i*2/3)-76);
			 		batsmannonstrike(264,320-(i*2/3)+76);

					SetRenderDrawColor(renderer,WHITE);
			 		batsmannonstrike(340,309-76+((i+1)*2/3));
			 		batsmannonstrike(264,320+76-((i+1)*2/3));
			 	}
						
				//Update the screen
				SDL_RenderPresent(renderer);
	        		SDL_Delay(1);  // Pause execution for 3000 milliseconds, for example

			}//end of for loop 87
			runshot++;
		}//end of if else y

  }while(decision!=SDLK_n);

  team->innings[innings_num].change_innings_runs(runshot,extratag,NOT_OUT);
  return;
}


