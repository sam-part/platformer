#include <iostream>

#define SDL_MAIN_HANDLED

#include "window.h"
#include "game_object.h"

int main(int argc, char* args[])
{
	Window window(800, 600, "Game");

	while (window.IsOpen())
	{
		window.PollEvents();
		window.Clear();
		window.Refresh();
	}
}