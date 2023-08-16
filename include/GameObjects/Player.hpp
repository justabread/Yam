#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Moveable.hpp"
#include "Utilities/Utils.hpp"
#include "EntityStorage.hpp"

class Player : public Moveable {
public:
    Player(Vector2f _pos, const int _max_vel, int _scale, SDL_Texture* _tex): Moveable(Vector2f{0,0}, _max_vel, _pos, _scale, _tex) {};
    ~Player(){};
    void HandleEvent(SDL_Event &e, EntityStorage* entityStorage);
    void Move();
};