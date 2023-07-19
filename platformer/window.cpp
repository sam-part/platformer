#include "window.h"

Window::Window(unsigned int width, unsigned int height, const std::string& window_name)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize, SDL_Error: " << SDL_GetError() << "\n";
        return;
    }

    // Create window
    Uint32 window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;

    window = SDL_CreateWindow(window_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, window_flags);
    if (window == NULL)
    {
        std::cout << "SDL could not create window, SDL_Error: " << SDL_GetError() << "\n";
        return;
    }

    // Create renderer
    Uint32 renderer_flags = SDL_RENDERER_ACCELERATED;
    
    renderer = SDL_CreateRenderer(window, -1, renderer_flags);
    if (renderer == NULL)
    {
        std::cout << "SDL could not create renderer, SDL_Error: " << SDL_GetError() << "\n";
        return;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    window = nullptr;
    renderer = nullptr;
}
