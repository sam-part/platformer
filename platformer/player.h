#pragma once
#include "game_object.h"

class Player : public GameObject
{
private:
	Window* window;
	Point position;

public:
	Player(Window* window, double x, double y, double width, double height);

	void Update(double dt);
	void Draw();
};