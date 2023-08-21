#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>

#include "EntityStorage.hpp"
#include "GameObjects/Entity.hpp"
#include "GameObjects/Player.hpp"
#include "GameObjects/Tile.hpp"

void GameLoop() {

    bool isRunning = true;
    SDL_Event event;

    double time = 0.0;
    const double deltaTime = 0.01;
    double accumulator = 0.0;
    double currentTime = Utils::TimeInSeconds();

    while(isRunning) {
        double newTime = Utils::TimeInSeconds();
        double frameTime = newTime - currentTime;

        currentTime = newTime;
        accumulator += frameTime;

        while(accumulator >= deltaTime) {
            while(SDL_PollEvent(&event)){
                switch(event.type) {
                    case SDL_QUIT:
                        isRunning = false;
                        break;
                    default:
                        break;
                }
                for(Entity* entity :  EntityStorage::renderBuffer) {
                    if(dynamic_cast<Player*>(entity) != NULL){
                        dynamic_cast<Player*>(entity)->HandleEvent(event);
                    }
                }
            }

            for(Entity* entity :  EntityStorage::renderBuffer) {
                if(dynamic_cast<Player*>(entity) != NULL){
                    dynamic_cast<Player*>(entity)->Move();
                }
            }
            accumulator -= deltaTime;
            time += deltaTime;
        }
        
        EntityStorage::renderWindow.clear();

        //Render entities
        for(Entity* entity : EntityStorage::renderBuffer) {
            EntityStorage::renderWindow.render(entity);
        }
        EntityStorage::renderWindow.display();
    }
}

int main(int argc, char *args[])
{
    //Create the entity storage object and pointer
    EntityStorage entityStorage = EntityStorage();
    EntityStorage* p_entityStorage = &entityStorage;

    //Create the player object and pointer
    Player* player = new Player(SDL_Rect{160,680,Utils::ENTITY_SIZE,Utils::ENTITY_SIZE},2, 1, EntityStorage::textureStore.at(Utils::ActorType::PLAYER));
    //Push grass tiles to render buffer
    p_entityStorage->PushToRenderBuffer({
        player,
        new Tile(SDL_Rect{80,0,Utils::ENTITY_SIZE,Utils::ENTITY_SIZE}, 1, EntityStorage::textureStore.at(Utils::ActorType::GRASS)),
        new Tile(SDL_Rect{200,Utils::SCREEN_HEIGHT - Utils::ENTITY_SIZE,Utils::ENTITY_SIZE,Utils::ENTITY_SIZE}, 1, EntityStorage::textureStore.at(Utils::ActorType::GRASS)),
        new Tile(SDL_Rect{200,Utils::SCREEN_HEIGHT - 132,Utils::ENTITY_SIZE,Utils::ENTITY_SIZE}, 1, EntityStorage::textureStore.at(Utils::ActorType::GRASS))
    });

    GameLoop();
    p_entityStorage->CleanUp();
    SDL_Quit();
    return 0;
}