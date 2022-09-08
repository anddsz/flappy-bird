#pragma once

#include "player.hpp"
#include "input.hpp"
#include "renderer.hpp"
#include "util.hpp"
#include "pipe.hpp"
#include <SDL2/SDL_image.h>

class Player {
public:
    Player();
    Player(Renderer &renderer);
    void Update(Renderer &renderer, PipeManager &pipe_manager, Keyboard &keyboard, double delta_time);
    void Draw(Renderer &renderer);
    void GetPipeColision(Renderer &renderer, Pipe &pipe);
private:
    Vector2(float) position;
    Vector2(float) velocity;
    float gravity;
    SDL_Rect bounding_box;
    bool collided;

    SDL_Texture *texture;
};
