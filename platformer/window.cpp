#include "window.h"

Window::Window(unsigned int width, unsigned int height, const std::string& window_name)
    : width(width), height(height), window_name(window_name)
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

    open = true;
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    window = nullptr;
    renderer = nullptr;
}

void Window::Resize(unsigned int new_width, unsigned int new_height)
{
    SDL_SetWindowSize(window, new_width, new_height);
}

void Window::SetFullscreen(bool fullscreen)
{
    Uint32 flags = 0;
    if (fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    SDL_SetWindowFullscreen(window, flags);
}

int Window::GetWidth()
{
    return width;
}

int Window::GetHeight()
{
    return height;
}

void Window::SetIcon(const std::string& icon_path)
{
    SDL_Surface* icon_surface = IMG_Load(icon_path.c_str());
    if (icon_surface == NULL)
    {
        std::cout << "IMG_Error: " << IMG_GetError() << "\n";
        return;
    }

    SDL_SetWindowIcon(window, icon_surface);

    SDL_FreeSurface(icon_surface);
    icon_surface = nullptr;
}

void Window::PollEvents()
{
    keypresses.clear();

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            CloseWindow();
            break;

        case SDL_KEYDOWN:
            keypresses.insert(event.key.keysym.sym);
            break;

        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
            {
                width = event.window.data1;
                height = event.window.data2;
            }

            break;

        default:
            break;
        }
    }
}

void Window::Clear()
{
    SDL_RenderClear(renderer);
}

void Window::Refresh()
{
    SDL_RenderPresent(renderer);
}

bool Window::IsKeyDown(int key)
{
    return keypresses.contains(key);
}

bool Window::IsOpen()
{
    return open;
}

void Window::CloseWindow()
{
    open = false;
}

void Window::Draw(SDL_Texture* texture, const SDL_Rect& source, const SDL_Rect& destination)
{
    SDL_RenderCopy(renderer, texture, &source, &destination);
}

void Window::Draw(SDL_Texture* texture, const SDL_Rect& source, const SDL_Rect& destination, double angle, const SDL_Point& center, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(renderer, texture, &source, &destination, angle, &center, flip);
}

void Window::DrawRect(int x, int y, int width, int height, SDL_Color color)
{
    SDL_Rect rect(x, y, width, height);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

/*
SDL_Renderer* Window::GetRenderer()
{
    return renderer;
}
*/