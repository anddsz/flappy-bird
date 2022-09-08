#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

class Window {
public:
    Window();
    Window(const char *window_title,
           unsigned int window_width, unsigned int window_height);
    SDL_Window *GetWindow();
private:
    SDL_Window *window;
};
