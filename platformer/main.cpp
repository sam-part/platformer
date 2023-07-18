#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* args[])
{
	SDL_Window* window = nullptr;
	SDL_Surface* surface = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Could not initialize SDL. SDL_Error: " << SDL_GetError() << "\n";
		return 0;
	}

	window = SDL_CreateWindow("Platformer Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "Could not create window. SDL_Error: " << SDL_GetError() << "\n";
		return 0;
	}

	surface = SDL_GetWindowSurface(window);

	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 0, 0));

	//Update the surface
	SDL_UpdateWindowSurface(window);

	//Hack to get window to stay up
	SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
	it has errors
}