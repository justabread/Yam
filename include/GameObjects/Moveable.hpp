#pragma once

#include "Entity.hpp"
#include "Utilities/Utils.hpp"

class Moveable : public Entity {
public:
    Vector2f vel;
    const int MAX_VELOCITY;
    SDL_Rect collider;

    Moveable(Vector2f _vel, const int _max_vel, SDL_Rect _pos, int _scale, SDL_Texture* _tex) : Entity(_pos, _scale, _tex), vel(_vel), MAX_VELOCITY(_max_vel) {
        collider.w = Utils::ENTITY_SIZE;
        collider.h = Utils::ENTITY_SIZE;
    };
    virtual void HandleEvent(SDL_Event &e) {};
    virtual void Move() {};
};