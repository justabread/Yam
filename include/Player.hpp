#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class Player : public Entity {
private:
    Vector2f vel;
public:
    Player(Vector2f _pos, int _scale, Vector2f _vel, SDL_Texture* _tex): Entity(_pos, _scale, _tex), vel(Vector2f{0,0}) {};
    void HandleEvent(SDL_Event &e);
    void Move();

    static const int MAX_VELOCITY = 2;
};