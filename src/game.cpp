#include "game.hpp"

Game::Game(): looping(true), window("Title", 1280, 720), renderer(window), player(renderer), pipe_manager() {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "Couldn't start SDL. SDL error: " << SDL_GetError() << std::endl;
    }

    SDL_RenderSetLogicalSize(this->renderer.GetRenderer(), 320, 180);

    Loop();
}

void Game::Loop(){
    unsigned long long current_frame_time; 
    unsigned long long previous_frame_time; 
    double delta_time;

    while(this->looping){
        previous_frame_time = current_frame_time;
        keyboard.Clear();
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_KEYDOWN:
                    if(!event.key.repeat){
                        keyboard.EventKeyDown(&event);
                    }
                    break;
                case SDL_KEYUP:
                    keyboard.EventKeyUp(&event);
                    break;
                case SDL_QUIT:
                    this->looping = false;
                    break;
                default:
                    break;
            }
        }
        Update(this->keyboard, delta_time);

        Render();

        current_frame_time = SDL_GetPerformanceCounter();
        delta_time = (double)(current_frame_time - previous_frame_time) * 1000.0 / (double)SDL_GetPerformanceFrequency();
    }
}

void Game::Update(Keyboard &keyboard, double delta_time){
    this->player.Update(this->renderer, this->pipe_manager, this->keyboard, delta_time);
    this->pipe_manager.Update(this->renderer, delta_time);
}

void Game::Render(){
    this->renderer.Clear();

    this->player.Draw(this->renderer);
    this->pipe_manager.Draw(this->renderer);

    this->renderer.Present();
}
