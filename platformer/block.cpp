#include "block.h"

Block::Block(Window* window, int x, int y)
	: window(window)
{
	position.x = x;
	position.y = y;
}

void Block::Update(double dt) {}

void Block::Draw()
{
	window->DrawRect(position.x, position.y, 20, 20, SDL_Color {255, 0, 0});
}
