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

void GameLoop(EntityStorage* entityStorage) {
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
                for(Entity* entity : entityStorage->GetRenderBuffer()) {
                    if(dynamic_cast<Player*>(entity) != NULL){
                        dynamic_cast<Player*>(entity)->HandleEvent(event, entityStorage);
                    }
                }
            }

            accumulator -= deltaTime;
            time += deltaTime;
        }
        
        entityStorage->GetRenderWindow().clear();

        //Render entities
        for(Entity* entity : entityStorage->GetRenderBuffer()) {
            if(dynamic_cast<Player*>(entity) != NULL){
                dynamic_cast<Player*>(entity)->Move();
            }

            entityStorage->GetRenderWindow().render(entity);
        }
        entityStorage->GetRenderWindow().display();
    }   
}

int main(int argc, char *args[])
{
    //Create the entity storage object and pointer
    EntityStorage entityStorage = EntityStorage();
    EntityStorage* p_entityStorage = &entityStorage;

    //Create the player object and pointer
    Player* player = new Player(Vector2f{0,0},2, 1, p_entityStorage->GetTexture(Utils::ActorType::PLAYER));
    //Push grass tiles to render buffer
    p_entityStorage->PushToRenderBuffer({
        player,
        new Tile(Vector2f{0,32}, 1, p_entityStorage->GetTexture(Utils::ActorType::GRASS))
    });

    GameLoop(p_entityStorage);

    p_entityStorage->CleanUp();
    SDL_Quit();
    return 0;
}