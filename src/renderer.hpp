#pragma once
#include "window.hpp"
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Renderer {
public:
    Renderer(Window &window);
	SDL_Texture *LoadTexture(const char *file_path);
    void Clear();
    void Copy(SDL_Texture *texture, SDL_Rect *srcrect, SDL_Rect *dstrect);
    void Present();
    SDL_Renderer *GetRenderer();
private:
    SDL_Renderer *renderer;
    std::map<std::string, SDL_Texture *> texture_list;
};
