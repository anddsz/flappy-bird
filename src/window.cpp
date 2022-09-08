#include "window.hpp"

Window::Window(const char *window_title, unsigned int window_width, unsigned int window_height):
    window(NULL){
    this->window = SDL_CreateWindow(window_title, 
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              window_width, window_height,
                              0);

    if(this->window == NULL){
        printf("Couldn't create window. SDL error: %s\n", SDL_GetError());
    }
}

SDL_Window *Window::GetWindow(){
    return this->window;
}
