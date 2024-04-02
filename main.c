#include <SDL2/SDL_main.h>
#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL_video.h"
#include "SDL2/SDL.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


int main(int argc, char **argv)
{
	//window to render too
	SDL_Window* window = NULL;

	//the surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
	} else
	{
		//Create the window
		window = SDL_CreateWindow("Lazy Foo Tutorial Window Baby", 100,100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error %s\n", SDL_GetError());
		} else
		{
			//Get the window surface
			screenSurface = SDL_GetWindowSurface(window);

			//fill the surface with a color
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Hack to get window to stay up
			SDL_Event e;
			bool quit = false;
			while (quit == false)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT) quit = true;
				}
			}
		}
	}
	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}