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
//Globals for window and renderer
SDL_Renderer *renderer = nullptr;
SDL_Window *window = nullptr;

/*
*  Loads an image directly to texture using SDL_image's
*  built in function IMG_LoadTexture
*  @param file: the image file to load
*  @return SDL_Texture* to the loaded texture
*/
SDL_Texture* LoadImage(std::string file){
	SDL_Texture* tex = nullptr;
	tex = IMG_LoadTexture(renderer, file.c_str());
	if (tex == nullptr)
		throw std::runtime_error("Failed to load image: " + file + IMG_GetError());
	return tex;
}
/*
*  Generate a texture containing the message we want to display
*  @param message The message we want to display
*  @param fontFile The font we want to use to render the text
*  @param color The color we want the text to be
*  @param fontSize The size we want the font to be
*  @return An SDL_Texture containing the rendered message
*/
SDL_Texture* RenderText(std::string message, std::string fontFile, SDL_Color color, int fontSize){
	//Open the font
	TTF_Font *font = nullptr;
	font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (font == nullptr)
		throw std::runtime_error("Failed to load font: " + fontFile + TTF_GetError());
	
	//Render the message to an SDL_Surface, as that's what TTF_RenderText_X returns
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	//Clean up unneeded stuff
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);

	return texture;
}
/*
*  Draw an SDL_Texture to an SDL_Renderer at position x, y
*  @param x: x coordinate to draw too
*  @param y: y coordinate to draw too
*  @param tex: the source texture we want to draw
*  @param rend: the renderer we want to draw too
*/
void ApplySurface(int x, int y, SDL_Color color, const char *text, SDL_Renderer *rend, int size){
	//First we must create an SDL_Rect for the position of the image, as SDL
	//won't accept raw coordinates as the image's position
	SDL_Texture *image = nullptr;
	SDL_Rect pos;
	
	try {
		image = RenderText(text, "./SourceSansPro-Regular.ttf", color, size);
	}
	catch (const std::runtime_error &e){
		std::cout << e.what() << std::endl;
//		return 4;
	}	
	pos.x = x;
	pos.y = y;
	//We also need to query the texture to get its width and height to use
	SDL_QueryTexture(image, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(rend, image, NULL, &pos);

	SDL_DestroyTexture(image);
}

int Screen::firstscreen()
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
	if (window == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return 2;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED 
		| SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return 3;
	}


	//Our texture size won't change, so we can get it here
	//instead of constantly allocating/deleting ints in the loop
//	int iW, iH;
//	SDL_QueryTexture(image, NULL, NULL, &iW, &iH);

	//Our event type
	SDL_Event e;
	
	//For tracking if we want to quit
	bool quit = false;
	while (!quit){
		//Event Polling
		while (SDL_PollEvent(&e)){
			//If user closes he window
			if (e.type == SDL_QUIT)
				quit = true;
			//If user presses any key
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
				quit = true;
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
		ApplySurface(10, 40, { 255, 255, 255 },"SPACE", renderer,30);

		}
		//Rendering
//		SDL_RenderClear(renderer);
		//Draw the image
//		ApplySurface(10, 20, { 255, 255, 255 },"BLAH!!!!!!!!\nHelllo!!!!", renderer,4);
//		ApplySurface(10, 50, { 155, 155, 155 },"And another string", renderer,40);

		ApplySurface(10, -60, { 100, 155, 155 },"TEST", renderer,290);
		ApplySurface(10, 180, { 80, 155, 155 },"MATCH", renderer,210);
		ApplySurface(10, 440, { 255, 255, 255 },"Press <space> to continue", renderer,30);

		//Update the screen
		SDL_RenderPresent(renderer);
	}

	//Destroy the various items
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	
	return 0;
}


