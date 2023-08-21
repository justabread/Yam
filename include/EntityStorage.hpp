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
    
    
    
public:
    static std::vector<Entity*> renderBuffer;
    static RenderWindow renderWindow;
    static std::unordered_map<int, SDL_Texture*> textureStore;
    EntityStorage(){};

    void PushToRenderBuffer(std::vector<Entity*> entities);
    static void DeleteFromEntityBuffer(Entity* entity);
    
    void CleanUp();
};