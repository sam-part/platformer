#pragma once

#include "game_object.h"
#include "animation_data.h"

class Player : public GameObject
{
private:
	double base_speed;

	Window* window;
	SDL_Texture* texture;
	Point position;
	Point direction;
	Dimensions dimensions;
	AnimationData animation_data;
	SDL_Rect Destination();
	SDL_Rect Source();

public:
	Player(Window* window, SDL_Texture* texture, double x, double y, double width, double height, double speed);

	void Update(double dt);
	void Draw();
	void Move(Point direction, double speed);
};