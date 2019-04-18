#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>


/**
 * Project:    P4
 * Authors:    Ajmain Naqib
 *
 * Semester:   Spring 2019
 * Course:     CS368
 *
 * Due Date:   April 18th 2019
 * Version:    1.0
 *
 */

using namespace std;


/**
 * Driver method for the application
 */
int main(int argc, char* argv[]) {


	bool quit = false;
	SDL_Event event;

	// Initializes SDL
	if(!SDL_Init(SDL_INIT_VIDEO)){
		cout << "ERROR: SDL could not initialize" << endl;
	}

	// creates a window with parameters
	SDL_Window * window = SDL_CreateWindow("AJ's first C++ GUI",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, 0);

	// creates a renderer
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

	// loads image
	SDL_Surface * image = IMG_Load("background.png");

	// creates a texture object from surface
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

	// loop so that program runs
	while (!quit) {
		SDL_WaitEvent(&event);

		switch (event.type) {
		case SDL_QUIT: // X out
			quit = true;
			break;
		case SDL_KEYDOWN: // if key pressed
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

	// cleans up
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
