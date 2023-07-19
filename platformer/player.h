#pragma once
#include "game_object.h"
#include "animation_data.h"

class Player : public GameObject
{
private:
	Window* window;
	SDL_Texture* texture;
	Point position;
	Dimensions dimensions;
	AnimationData animation_data;
	SDL_Rect Destination();
	SDL_Rect Source();

public:
	Player(Window* window, SDL_Texture* texture, double x, double y, double width, double height);

	void Update(double dt);
	void Draw();
};