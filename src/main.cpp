#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Utils.hpp"
#include "Entity.hpp"

int main(int argc, char *args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        Utils::ThrowErrorMessage("SDL failed to initialize: ");
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        Utils::ThrowErrorMessage("SDL image failed to initialize: ");
    }

    RenderWindow window("Yamgine v0.0.1", 1280, 720);

    SDL_Texture* grassTexture = window.loadTexture("..\\res\\sprites\\ground_grass_1.png");
    Entity platform0(100, 100, 2, grassTexture);

    bool isRunning = true;
    SDL_Event event;
    while(isRunning) {
        while(SDL_PollEvent(&event)){
            switch(event.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
                default:
                    break;
            }
        }

        window.clear();
        window.render(platform0);
        window.display();
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}