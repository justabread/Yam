#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity {
private:
    Vector2f pos;
    SDL_Texture* tex;
    SDL_Rect currentFrame;
public:
    Entity(Vector2f _pos, SDL_Texture* _tex); 

    Vector2f& GetPos() {
        return pos;
    };
    SDL_Texture* GetTex() {
        return tex;
    }
    SDL_Rect GetCurrentFrame() {
        return currentFrame;
    }
};