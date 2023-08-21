#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Utilities/Math.hpp"
#include "Utilities/Utils.hpp"

class Entity {
protected:
    SDL_Rect pos;
    int scale;
    SDL_Texture* tex;
    SDL_Rect currentFrame;
public:
    Entity(SDL_Rect _pos, int _scale, SDL_Texture* _tex) : pos(_pos), scale(_scale), tex(_tex) {
        currentFrame.x = 0;
        currentFrame.y = 0;
        currentFrame.w = Utils::ENTITY_SIZE;
        currentFrame.h = Utils::ENTITY_SIZE;
    }
    
    virtual ~Entity() {
        std::cout << "Entity deleted" << std::endl;
    }

    SDL_Rect* GetPos() {
        return &pos;
    };

    int GetScale() {
        return scale;
    };

    SDL_Texture* GetTex() {
        return tex;
    }
    
    SDL_Rect* GetCurrentFrame() {
        return &currentFrame;
    }
};