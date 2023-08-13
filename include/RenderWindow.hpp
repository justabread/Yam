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
    RenderWindow(std::string p_title, uint16_t p_w, uint16_t p_h);
    ~RenderWindow();
    void clear();
    void render(Entity &entity);
    void display();
    SDL_Texture* loadTexture(std::string p_filePath);
};