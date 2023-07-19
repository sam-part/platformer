#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <unordered_set>

class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	unsigned int width, height;
	std::string window_name;
	bool open = false;

	std::unordered_set<int> keypresses;

public:
	Window(unsigned int width, unsigned int height, const std::string& window_name);
	~Window();

	void Resize(unsigned int new_width, unsigned int new_height);
	void SetFullscreen(bool fullscreen);

	int GetWidth();
	int GetHeight();

	void SetIcon(const std::string& icon_path);

	void PollEvents();
	void Clear();
	void Refresh();

	bool IsKeyDown(int key);

	bool IsOpen();
	void CloseWindow();

	void Draw(SDL_Texture* texture, const SDL_Rect& source, const SDL_Rect& destination); 
	void Draw(SDL_Texture* texture, const SDL_Rect& source, const SDL_Rect& destination, double angle, const SDL_Point& center, SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE); 

	SDL_Renderer* GetRenderer();
};