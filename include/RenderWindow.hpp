#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class RenderWindow
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    RenderWindow(const char* p_title, uint16_t p_w, uint16_t p_h);
    void cleanUp();
    void clear();
    void render(Entity &entity);
    void display();
    SDL_Texture* loadTexture(const char* p_filePath);
};