#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity {
protected:
    Vector2f pos;
    int scale;
    SDL_Texture* tex;
    SDL_Rect currentFrame;
public:
    Entity(Vector2f _pos, int _scale, SDL_Texture* _tex); 

    virtual void HandleEvent(SDL_Event &e) {};
    virtual void Move() {};

    Vector2f GetPos() {
        return pos;
    };

    int GetScale() {
        return scale;
    };

    SDL_Texture* GetTex() {
        return tex;
    }
    
    SDL_Rect GetCurrentFrame() {
        return currentFrame;
    }
};