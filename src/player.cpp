#include "player.hpp"

Player::Player(Renderer &renderer): collided(false){
    this->position.x = 32;
    this->position.y = 82;
    this->velocity.y = 0;
    this->gravity = 6;
    this->texture = renderer.LoadTexture("res/player.png");

    this->bounding_box = (SDL_Rect) {
        .x = (int) this->position.x,
        .y = (int) this->position.y,
        .w = 16,
        .h = 16,
    };
}

void Player::Update(Renderer &renderer, PipeManager &pipe_manager, Keyboard &keyboard, double delta_time){
    this->velocity.y += this->gravity / delta_time;

    if(keyboard.IsKeyPressed(SDL_SCANCODE_SPACE)) this->velocity.y = -4.0;

    this->velocity.y = clamp(this->velocity.y, -8.0, 8.0);

    this->position.y += this->velocity.y;

    for(int i = 0; i < pipe_manager.GetPipeListSize(); i++){
        GetPipeColision(renderer, pipe_manager.GetPipeList()[i]);
    }

    this->bounding_box.x = this->position.x;
    this->bounding_box.y = this->position.y;
}

void Player::Draw(Renderer &renderer){
    renderer.Copy(this->texture, NULL, &this->bounding_box);
}

void Player::GetPipeColision(Renderer &renderer, Pipe &pipe){
    if(this->collided == false && SDL_HasIntersection(&this->bounding_box, pipe.GetDstRect())){
        this->texture = renderer.LoadTexture("res/pipe_upside.png");
        this->collided = true;
    }
}
