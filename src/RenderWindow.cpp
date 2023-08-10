#include "RenderWindow.hpp"
#include "Utils.hpp"

RenderWindow::RenderWindow(const char* p_title, uint16_t p_w, uint16_t p_h) : window(NULL), renderer(NULL) {
    
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        Utils::ThrowErrorMessage("Window failed to initialize: ");
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
    SDL_Texture* texture = NULL;

    texture = IMG_LoadTexture(renderer, p_filePath);

    if(texture == NULL){
        Utils::ThrowErrorMessage("Failed to load texture: ");
    }

    return texture;
}

void RenderWindow::cleanUp(){
    SDL_DestroyWindow(window);
}

void RenderWindow::clear() {
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity &entity) {
    SDL_Rect src;
    src.x = entity.GetCurrentFrame().x;
    src.y = entity.GetCurrentFrame().y;
    src.w = entity.GetCurrentFrame().w;
    src.h = entity.GetCurrentFrame().h;

    SDL_Rect dst;
    dst.x = entity.GetX() * entity.GetScale();
    dst.y = entity.GetY() * entity.GetScale();
    dst.w = entity.GetCurrentFrame().w * entity.GetScale();
    dst.h = entity.GetCurrentFrame().h * entity.GetScale();

    SDL_RenderCopy(renderer, entity.GetTex(), &src, &dst);
}

void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}
