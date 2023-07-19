#pragma once

#include "game_object.h"

class Block : public GameObject
{
private:
	Window* window;
	SDL_Point position;

public:
	Block(Window* window, int x, int y);
	
	void Update(double dt);
	void Draw();
};