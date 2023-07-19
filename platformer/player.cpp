#include "player.h"

Player::Player(Window* window, double x, double y)
	:window(window), position(position)
{
	position.x = x;
	position.y = y;
}

void Player::Update(double dt)
{
}

void Player::Draw()
{
	window->DrawRect(position.x, position.y, )
}
