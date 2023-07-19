#include <iostream>

#define SDL_MAIN_HANDLED

#include "window.h"
#include "block.h"

int main(int argc, char* args[])
{
	Window window(800, 600, "Game");

	std::vector<std::unique_ptr<GameObject>> game_objects;

	game_objects.push_back(std::make_unique<Block>(&window, 100, 100));
	game_objects.push_back(std::make_unique<Block>(&window, 200, 100));
	game_objects.push_back(std::make_unique<Block>(&window, 300, 400));

	while (window.IsOpen())
	{
		window.Tick();
		window.PollEvents();
		window.Clear();

		double dt = window.GetFrameDelta() / 1000.0;

		for (int i = 0; i < game_objects.size(); i++)
		{
			game_objects[i]->Update(dt);
			game_objects[i]->Draw();
		}

		window.Refresh();
	}
}