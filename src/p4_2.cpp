//============================================================================
// Name        : p4_2.cpp
// Author      : Ajmain
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {


	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * window = SDL_CreateWindow("AJ's first C++ GUI",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, 0);

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * image = IMG_Load("background.png");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

	while (!quit) {
		SDL_WaitEvent(&event);

		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_i:
				cout << "i was pressed" << endl;
				image = IMG_Load("aj.jpg");
				texture = SDL_CreateTextureFromSurface(renderer, image);
				break;
			case SDLK_o:
				cout << "o was pressed" << endl;
				image = IMG_Load("img2.PNG");
				texture = SDL_CreateTextureFromSurface(renderer, image);
				break;
			case SDLK_r:
				cout << "r was pressed" << endl;
				image = IMG_Load("background.PNG");
				texture = SDL_CreateTextureFromSurface(renderer, image);
				break;
			case SDLK_q:
				cout << "q was pressed" << endl;
				quit = true;
				break;

			default:
				break;
			}

		}


		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
