#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "renderer.hpp"
#include "util.hpp"

class Pipe;

class PipeManager {
public:
    PipeManager();
    void SpawnPipe(Renderer &renderer, int x, int y, int upside = 0);
    void Update(Renderer &renderer, double delta_time);
    void Draw(Renderer &renderer);
    std::vector<Pipe> GetPipeList();
    int GetPipeListSize();
private:
    float timer;
    std::vector<Pipe> pipe_list;
};

class Pipe {
    public:
        Pipe(Renderer &renderer, int x, int y, bool downside = 0);
        void Update();
        void Draw(Renderer &renderer);
        int GetX();
        SDL_Rect *GetDstRect();
    private:
        Vector2(int) position;
        Vector2(float) velocity;
        SDL_Texture *texture;
        SDL_Rect dst_rect;
        bool downside;
};
