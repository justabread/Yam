#pragma once
#include <unordered_map>
#include <algorithm>

#include "Entity.hpp"

class GameMaster {
public:
    static std::unordered_map<int, Entity*> entityBuffer;

    GameMaster(){};

    void PushToEntityBuffer(int key, Entity* entity);

    Entity* GetFromEntityBuffer(int key);
};