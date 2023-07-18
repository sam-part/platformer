#pragma once

#include <SDL.h>
#include <string>

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

	void Destroy();

	void PollEvents();
	void Clear();
	void Refresh();

	void Draw();
};