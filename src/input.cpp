#include "input.hpp"

Keyboard::Keyboard(){
	this->pressed = (bool *)malloc(sizeof(bool) * 512);
	this->held = (bool *)malloc(sizeof(bool) * 512);
	this->released = (bool *)malloc(sizeof(bool) * 512);
}

void Keyboard::Clear(){
    memset(this->pressed, 0, sizeof(bool) * 512);
    memset(this->released, 0, sizeof(bool) * 512);
}

void Keyboard::EventKeyDown(SDL_Event *event) {
    this->pressed[event->key.keysym.scancode] = true;
    this->held[event->key.keysym.scancode] = true;
}

void Keyboard::EventKeyUp(SDL_Event *event) {
    this->released[event->key.keysym.scancode] = true;
    this->held[event->key.keysym.scancode] = false;
}

bool Keyboard::IsKeyPressed(SDL_Scancode scancode){
    return this->pressed[scancode];
}

bool Keyboard::IsKeyHeld(SDL_Scancode scancode){
    return this->held[scancode];
}

bool Keyboard::IsKeyReleased(SDL_Scancode scancode){
    return this->released[scancode];
}
