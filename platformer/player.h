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
	Dimensions dimensions;
	AnimationData animation_data;
	Direction direction;
	SDL_Rect Destination();
	SDL_Rect Source();

public:
	Player(Window* window, SDL_Texture* texture, double x, double y, double width, double height, double speed);

	void Update(double dt);
	void Draw();
	void Move(Direction direction, double speed);
};