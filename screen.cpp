#include <stdexcept>
#include <string>
#include <iostream>
#include "screen.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


/*
*  Lesson 6: True Type Fonts with SDL_ttf
*/
//TODO: Write the lesson code
//Screen attributes
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;



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

void SetRenderDrawColor(SDL_Renderer *rend, SDL_Color color)
{
	SDL_SetRenderDrawColor(rend,color.r,color.g,color.b,color.a);
}

int Screen::firstscreen()
{
	//Our event type
	SDL_Event e;	
	//For tracking if we want to quit
	bool quit = false;

		SetRenderDrawColor(renderer,BLACK);
		SDL_RenderClear(renderer);
		ApplySurface(10, -60, GREY,"TEST", renderer,290);
		ApplySurface(10, 180, CYAN,"MATCH", renderer,210);
		ApplySurface(10, 440, WHITE,"Press <space> to continue", renderer,30);

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
		ApplySurface(10, 10, WHITE,"This is an emulated AMSTRAD CPC 464 game from the 1980's", renderer,20);
		ApplySurface(10, 30, WHITE,"Press Y to use automatic teams or N to manually set", renderer,20);

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

