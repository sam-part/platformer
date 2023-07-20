#include "block.h"

Block::Block(Window* window, int x, int y)
	: window(window)
{
	position.x = x;
	position.y = y;
}

void Block::Update(double dt)
{
	//if(window->IsKeyDown())
	//position.x += 10.0 * dt;
}

void Block::Draw()
{
	window->DrawRect(position.x, position.y, 20, 20, SDL_Color {255, 0, 0});
}
