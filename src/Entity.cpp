#include "Entity.hpp"

Entity::Entity(Vector2f _pos, SDL_Texture* _tex) : pos(_pos), tex(_tex) {
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}
