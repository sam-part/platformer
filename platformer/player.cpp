#include "player.h"

Player::Player(Window* window, SDL_Texture* texture, double x, double y, double width, double height, double base_speed) :
	window(window),
	texture(texture),
	base_speed(base_speed)
{
	position.x = x;
	position.y = y;
	dimensions.x = width;
	dimensions.y = height;

	destination.x = position.x;
	destination.y = position.y;
	destination.w = dimensions.x;
	destination.h = dimensions.y;


	// calculates dimensions of the players texture
	SDL_Point texture_dimensions{0, 0};
	SDL_QueryTexture(texture, NULL, NULL, &texture_dimensions.x, &texture_dimensions.y);

	source.x = position.x;
	source.y = 0;
	source.w = texture_dimensions.x;
	source.h = texture_dimensions.y;

	animation_data = {
		{double(texture_dimensions.x), double(texture_dimensions.y)},
		{dimensions.x, dimensions.y},
		0,
		0,
		1.0 / 6.0
	};
	direction = {
		0.0,
		0.0
	};
}

SDL_Rect Player::Destination()
{
	SDL_Rect destination{
		position.x,
		position.y,
		dimensions.x,
		dimensions.y
	};

	return destination;
}

SDL_Rect Player::Source()
{
	SDL_Rect source{
		0 + animation_data.player_dimensions.width * animation_data.frame,
		0,
		animation_data.player_dimensions.width,
		animation_data.player_dimensions.height
	};

	return source;
}

void Player::Move(Point direction, double speed)
{
	Point movement_direction = GetUnitDirection(direction);
	position += (movement_direction * speed);
}

void Player::Update(double dt)
{
	// update position
	if (window->IsKeyDown(SDLK_a))
	{
		Move(Directions::Left, base_speed);
	}
	if (window->IsKeyDown(SDLK_d))
	{
		Move(Directions::Right, base_speed);
	}

	destination.x = position.x;
	destination.y = position.y;

	// animate
	animation_data.running_time += dt;
	if (animation_data.running_time >= animation_data.update_time)
	{
		animation_data.running_time = 0;
		animation_data.frame++;

		if (animation_data.frame >= animation_data.texture_dimensions.width / animation_data.player_dimensions.width)
		{
			animation_data.frame = 0;
		}
	}

	source.x = 0 + animation_data.player_dimensions.width * animation_data.frame;
	source.y = position.y;
}

void Player::Draw()
{
	window->Draw(texture, source, destination);
}
