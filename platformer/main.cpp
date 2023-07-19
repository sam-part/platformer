#include <iostream>

#define SDL_MAIN_HANDLED

#include "window.h"
#include "block.h"

int main(int argc, char* args[])
{
	Window window(800, 600, "Game");

	std::vector<std::unique_ptr<GameObject>> game_objects;

	game_objects.push_back(std::make_unique<Block>(&window, 100, 100));

	while (window.IsOpen())
	{
		window.PollEvents();
		window.Clear();
		window.Refresh();
	}
}