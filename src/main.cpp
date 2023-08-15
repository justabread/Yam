#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>

#include "GameMaster.hpp"
#include "RenderWindow.hpp"
#include "Utils.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Math.hpp"

const std::string APP_NAME = "Yam";
const std::string VERSION = "v0.0.1";

enum EntityTypes {
    PLAYER,
    ACTOR_ARRAY,
    STATIC_OBJECT_ARRAY
};

RenderWindow InitWindow() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        Utils::ThrowErrorMessage("SDL failed to initialize: ");
    }
    if (!(IMG_Init(IMG_INIT_PNG))) {
        Utils::ThrowErrorMessage("SDL image failed to initialize: ");
    }

    RenderWindow renderWindow(APP_NAME + " " + VERSION, Utils::SCREEN_WIDTH, Utils::SCREEN_HEIGHT);

    return renderWindow;
}

void GameLoop(RenderWindow &renderWindow) {
    // SDL_Texture* grassTexture = renderWindow.loadTexture("..\\res\\sprites\\ground_grass_1.png");

    // std::vector<Entity> entities = {
    //     Entity(Vector2f(0,0), grassTexture),
    //     Entity(Vector2f(30,0), grassTexture),
    //     Entity(Vector2f(30,30), grassTexture)
    // };

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
                for(auto &entityPair : GameMaster::entityBuffer) {
                    switch(entityPair.first) {
                        case PLAYER:
                        entityPair.second->HandleEvent(event);
                    }
                }
            }

            accumulator -= deltaTime;
            time += deltaTime;
        }
        
        renderWindow.clear();

        //Render entities
        for(auto &entityPair : GameMaster::entityBuffer) {
            switch(entityPair.first) {
                case PLAYER:
                   entityPair.second->Move();
            }

            renderWindow.render(entityPair.second);
        }
        renderWindow.display();
    }   
}

int main(int argc, char *args[])
{
    //Instantiate the Game Master
    GameMaster gameMaster = GameMaster();

    RenderWindow renderWindow = InitWindow();
    SDL_Texture* playerTexture = renderWindow.loadTexture("..\\res\\sprites\\char.png");

    //Create the player object
    Entity* player = new Player(Vector2f(0,0), 4, Vector2f(0,0), playerTexture);
    gameMaster.PushToEntityBuffer(PLAYER, player);

    GameLoop(renderWindow);

    SDL_Quit();
    return 0;
}