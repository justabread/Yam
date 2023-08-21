#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "Moveable.hpp"
#include "Utilities/Utils.hpp"
#include "EntityStorage.hpp"

class Player : public Moveable {
private:
    bool isJumping = false;
    float jumpStart;
    bool isColliding = false;
    std::unordered_map<int, bool> collidingInDirection = {
        {Utils::Direction::NORTH, false},
        {Utils::Direction::EAST, false},
        {Utils::Direction::SOUTH, false},
        {Utils::Direction::WEST, false}
    };

public:
    Player(SDL_Rect _pos, const int _max_vel, int _scale, SDL_Texture* _tex): Moveable(Vector2f{0,0}, _max_vel, _pos, _scale, _tex) {};
    ~Player(){};
    void HandleEvent(SDL_Event &e);
    void Move();
    void ApplyGravity();
    bool CheckCollision(SDL_Rect* a, SDL_Rect* b);
    std::vector<Entity*> ObjectsColliding(std::vector<Entity*> renderBuffer);

    // std::string PrintCollidingInDirection() {
    //     return "ss";
    //     // "NORTH: " + collidingInDirection[Utils:Direction::NORTH] + "\n" +
    //     // "EAST: " + collidingInDirection[Utils::Direction::EAST] + "\n" +
    //     // "SOUTH: " + collidingInDirection[Utils::Direction::SOUTH] + "\n" +
    //     // "WEST: " + collidingInDirection[Utils::Direction::WEST];
    // }

    bool GetIsColliding() {
        return isColliding;
    }
};