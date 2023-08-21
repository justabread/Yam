#include "EntityStorage.hpp"

std::vector<Entity*> EntityStorage::renderBuffer = {};
RenderWindow EntityStorage::renderWindow = RenderWindow(APP_NAME + " " + VERSION, Utils::SCREEN_WIDTH, Utils::SCREEN_HEIGHT);
std::unordered_map<int, SDL_Texture*> EntityStorage::textureStore = {
        {Utils::ActorType::PLAYER, renderWindow.loadTexture("..\\res\\sprites\\char.png")},
        {Utils::ActorType::GRASS, renderWindow.loadTexture("..\\res\\sprites\\ground_grass_1.png")}
    };

void EntityStorage::PushToRenderBuffer(std::vector<Entity*> entities) {
    for(Entity* entityToPush : entities) {
        renderBuffer.push_back(entityToPush);
    }
}

void EntityStorage::DeleteFromEntityBuffer(Entity* entityToDelete) {
    std::vector<Entity*>::iterator it;
    for ( it = renderBuffer.begin(); it != renderBuffer.end(); ) {
        if( (*it) == entityToDelete) {
            delete * it;
            it = renderBuffer.erase(it);
        }
        else {
            ++it;
        }
    }
};

void EntityStorage::CleanUp() {
    std::vector<Entity*>::iterator it;
    for ( it = renderBuffer.begin(); it != renderBuffer.end(); ) {
        delete * it;  
        it = renderBuffer.erase(it);
    }
    renderBuffer.clear();
}