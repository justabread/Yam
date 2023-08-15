#include "GameMaster.hpp"

std::unordered_map<int, Entity*> GameMaster::entityBuffer;

void GameMaster::PushToEntityBuffer(int key, Entity* entity) {
    entityBuffer.insert(std::pair<int, Entity*>(key, entity));
}

Entity* GameMaster::GetFromEntityBuffer(int key) {
    return entityBuffer.at(key);
}