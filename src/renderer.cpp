#include "renderer.hpp"

Renderer::Renderer(Window &window): renderer(NULL){
    this->renderer = SDL_CreateRenderer(window.GetWindow(), -1, SDL_RENDERER_PRESENTVSYNC);

    if(renderer == NULL){
        printf("Couldn't create renderer. SDL error: %s\n", SDL_GetError());
    }
}

SDL_Texture *Renderer::LoadTexture(const char *file_path){
    if(this->texture_list.count(file_path) == 0){
        this->texture_list[file_path] = IMG_LoadTexture(this->renderer, file_path);
    }
    return this->texture_list[file_path];
}

void Renderer::Clear(){
    SDL_RenderClear(this->renderer);
}

void Renderer::Copy(SDL_Texture *texture, SDL_Rect *srcrect, SDL_Rect *dstrect){
    SDL_RenderCopy(this->renderer, texture, srcrect, dstrect);
}

void Renderer::Present(){
    SDL_RenderPresent(this->renderer);
}

SDL_Renderer *Renderer::GetRenderer(){
    return this->renderer;
}
