#include "pipe.hpp"

// TODO: This is a comment
PipeManager::PipeManager(){
    srand(time(NULL));
}

void PipeManager::SpawnPipe(Renderer &renderer, int x, int y, int upside){
    this->pipe_list.push_back(Pipe(renderer, x, y, upside));
}

void PipeManager::Update(Renderer &renderer, double delta_time){
    for(int i = 0; i < this->pipe_list.size(); i++){
        this->pipe_list[i].Update();
        if(this->pipe_list[i].GetX() <= -64){
            this->pipe_list.erase(this->pipe_list.begin() + i);
        }
    }

    timer -= delta_time;

    if(timer < 0.0){
        int spawn_height = 64 + rand() % (180 - 64);

        char temp = delta_time - (-timer);

        SpawnPipe(renderer, 320 + 64, spawn_height + 48, 0);
        SpawnPipe(renderer, 320 + 64, spawn_height - (180 + 48), 1);
        timer = 3000.0 - temp;
    }
}

void PipeManager::Draw(Renderer &renderer){
    for(int i = 0; i < this->pipe_list.size(); i++){
        this->pipe_list[i].Draw(renderer);
    }
}

std::vector<Pipe> PipeManager::GetPipeList(){
    return this->pipe_list;
}

int PipeManager::GetPipeListSize(){
    return this->pipe_list.size();
}

Pipe::Pipe(Renderer &renderer, int x, int y, bool downside){
    this->position.x = x;
    this->position.y = y;

    this->dst_rect = (SDL_Rect) {
        .x = this->position.x,
        .y = this->position.y,
        .w = 32,
        .h = 192,
    };

    this->texture = renderer.LoadTexture((downside == true) ? "res/pipe_downside.png" : "res/pipe_upside.png");
}

void Pipe::Update(){
    this->position.x -= 5;
    this->dst_rect.x = this->position.x;
}

void Pipe::Draw(Renderer &renderer){
    renderer.Copy(this->texture, NULL, &this->dst_rect);
}

int Pipe::GetX(){
    return this->position.x;
}

SDL_Rect *Pipe::GetDstRect(){
    return &this->dst_rect;
}
