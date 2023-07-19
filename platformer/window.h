#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	unsigned int width, height;
	std::string window_name;

	bool fullscreen;

public:
	Window(unsigned int width, unsigned int height, const std::string& window_name);
	~Window();

	void Resize(unsigned int new_width, unsigned int new_height);
	void SetFullscreen(bool fullscreen);

	void SetIcon(const std::string& icon_path);

	void PollEvents();
	void Clear();
	void Refresh();

	void Draw(SDL_Texture* texture, const SDL_Rect& source, const SDL_Rect& destination); // SDL_RenderCopy
	void Draw(SDL_Texture* texture, const SDL_Rect& source, const SDL_Rect& destination, double angle, const SDL_Point& center, SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE); // SDL_RenderCopyEx
};