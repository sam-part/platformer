#pragma once
#include "game_object.h"

class Player : public GameObject
{
private:
	Window* window;
	SDL_Point position;

public:
	Player(Window* window, int x, int y);

	void Update(double dt);
	void Draw();
};