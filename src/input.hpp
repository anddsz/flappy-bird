#pragma once
#include <SDL2/SDL.h>
#include <cstring>

class Keyboard {
public:
    Keyboard();
    void Clear();

    void EventKeyDown(SDL_Event *event);
    void EventKeyUp(SDL_Event *event);

    bool IsKeyPressed(SDL_Scancode scancode);
    bool IsKeyHeld(SDL_Scancode scancode);
    bool IsKeyReleased(SDL_Scancode scancode);
private:
    bool *pressed;
    bool *held;
    bool *released;
};
