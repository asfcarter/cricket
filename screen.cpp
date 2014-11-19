#include <stdexcept>
#include <string>
#include <iostream>
#include <string>
#include "screen.h"

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
		ApplySurface(20,40,WHITE,team[0].getteamname(),renderer,text_size);
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
		ApplySurface(20,70,WHITE,team[0].getteamname(),renderer,text_size);
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
		ApplySurface(20,70,WHITE,team[1].getteamname(),renderer,text_size);
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
	
	cout << tosschange;
	return tosschange;
}

void Screen::display_scoreboard(Team batting, Team bowling)
{
int batsman_num, bowler_num, player_num;
char change_str[20];
int text_size=15;

		SetRenderDrawColor(renderer,BLACK);
		SDL_RenderClear(renderer);
		ApplySurface(10, 10, BLUE,batting.getteamname(), renderer,text_size);
		ApplySurface(500, 10, WHITE,"Overs", renderer,text_size);
		ApplySurface(550, 10, WHITE,"No overs", renderer,text_size);
		ApplySurface(20, 25, WHITE,"Batsman", renderer,text_size);
		ApplySurface(80, 25, WHITE,"Name", renderer,text_size);
		ApplySurface(160, 25, WHITE,"Status", renderer,text_size);
		ApplySurface(580, 25, WHITE,"Runs", renderer,text_size);

	for(batsman_num=0;batsman_num<11;batsman_num++)
	{
		sprintf(change_str,"%i",batsman_num+1);
		ApplySurface(20, 40+(15*batsman_num), WHITE,change_str, renderer,text_size);	
	}
	
ApplySurface(20,205, WHITE,"EXTRAS", renderer,text_size);
//ApplySurface(80,205, WHITE,itoa(team[teamnumber].innings[inningsnumber].getextras(),change,10), renderer,text_size);
ApplySurface(440,205, WHITE,"TOTAL", renderer,text_size);
//ApplySurface(490,205, WHITE,itoa(team[teamnumber].innings[inningsnumber].getinningsruns(),change,10), renderer,text_size);
ApplySurface(520,205, WHITE,"FOR", renderer,text_size);
//if(team[teamnumber].innings[inningsnumber].getwickets()!=10)
//ApplySurface(560,205, WHITE,itoa(team[teamnumber].innings[inningsnumber].getwickets(),change,10), renderer,text_size);
//else
ApplySurface(560,205, WHITE,"ALL OUT", renderer,text_size);
ApplySurface(20,225, WHITE,"========================================================================", renderer,text_size);

ApplySurface(20,240, WHITE,"Fall:", renderer,text_size);
//a=0;
//while((a<team[teamnumber].innings[inningsnumber].getwickets())&&(a!=9))
//{
//ApplySurface(70+(a*50),255, WHITE,itoa(a+1,change,10), renderer,text_size);
//ApplySurface(80+(a*50),255, WHITE,"-", renderer,text_size);
//ApplySurface(90+(a*50),255, WHITE,itoa(team[teamnumber].innings[inningsnumber].getwickfall(a),change,10), renderer,text_size);
//a++;
//};	

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

for(bowler_num=0;bowler_num<6;bowler_num++)
{
	sprintf(change_str,"%i",bowler_num+1);
	ApplySurface(20,315+(15*bowler_num), WHITE,change_str, renderer,text_size);

//	for(player_num=0;p<11;p++)
//	{
//	if(team[!teamnumber].innings[inningsnumber].player[p].getbowlernum()==bowler_num+1)
//		{
//		ApplySurface(70,300+(15*m), WHITE,team[!teamnumber].innings[inningsnumber].player[p].getname(), renderer,text_size);
//		ApplySurface(140,300+(15*m), WHITE,itoa(team[!teamnumber].innings[inningsnumber].player[p].getovers(),change,10), renderer,text_size);
//		ApplySurface(170,300+(15*m), WHITE,itoa(team[!teamnumber].innings[inningsnumber].player[p].getmaidens(),change,10), renderer,text_size);
//		ApplySurface(200,300+(15*m), WHITE,itoa(team[!teamnumber].innings[inningsnumber].player[p].getrunsconceeded(),change,10), renderer,text_size);
//		ApplySurface(230,300+(15*m), WHITE,itoa(team[!teamnumber].innings[inningsnumber].player[p].getwickets(),change,10), renderer,text_size);
//		}
//	}
}
	

		//Update the screen
		SDL_RenderPresent(renderer);

	
        SDL_Delay(5500);  // Pause execution for 3000 milliseconds, for example
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
	window = SDL_CreateWindow("Lesson 6", SDL_WINDOWPOS_CENTERED, 
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
	//Our event type
	SDL_Event e;	
	//For tracking if we want to quit
	bool quit = false;

		SetRenderDrawColor(renderer,BLACK);
		SDL_RenderClear(renderer);
		ApplySurface(10, -60, CYAN,"TEST", renderer,290);
		ApplySurface(10, 180, CYAN,"MATCH", renderer,210);
		ApplySurface(510, 390, CYAN,"Version 2.1", renderer,25);
		ApplySurface(135, 420, WHITE,"Press <space> to continue", renderer,35);

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
	
        SDL_Delay(500);  // Pause execution for 3000 milliseconds, for example

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

