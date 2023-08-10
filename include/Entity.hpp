#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity {
private:
    float x, y;
    int scale;
    SDL_Texture* tex;
    SDL_Rect currentFrame;
public:
    Entity(float _x, float _y, int _scale, SDL_Texture* _tex); 

    float GetX();
    float GetY();
    int GetScale();
    SDL_Texture* GetTex();
    SDL_Rect GetCurrentFrame();
};