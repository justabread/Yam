#pragma once
#include <vector>
#include <unordered_map>
#include <SDL2/SDL.h>

#include "GameObjects/Entity.hpp"
#include "RenderWindow.hpp"
#include "Utilities/Utils.hpp"

const std::string APP_NAME = "Yam";
const std::string VERSION = "v0.0.1";

class EntityStorage {
protected:
    RenderWindow renderWindow;
    std::unordered_map<int, SDL_Texture*> textureStore;
    std::vector<Entity*> renderBuffer;
    
public:
    EntityStorage();

    void PushToRenderBuffer(std::vector<Entity*> entities);
    void DeleteFromEntityBuffer(Entity* entity);
    
    void CleanUp();

    SDL_Texture* GetTexture(int key) {
        return textureStore.at(key);
    }

    std::vector<Entity*> &GetRenderBuffer() {
        return renderBuffer;
    }

    RenderWindow &GetRenderWindow() {
        return renderWindow;
    }

    Entity* GetFromEntityBuffer(int key) {
        return renderBuffer.at(key);
    };
};