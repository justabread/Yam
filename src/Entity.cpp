#include "Entity.hpp"

Entity::Entity(float _x, float _y, int _scale, SDL_Texture* _tex) : x(_x), y(_y), scale(_scale), tex(_tex) {
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

SDL_Texture* Entity::GetTex() {
    return tex;
}

SDL_Rect Entity::GetCurrentFrame() {
    return currentFrame;
}

float Entity::GetX() {
    return x;
}

float Entity::GetY() {
    return y;
}

int Entity::GetScale() {
    return scale;
}