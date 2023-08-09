#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"

int main(int argc, char *args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL failed to initialize: " << SDL_GetError() << std::endl;}

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "SDL image failed to initialize: " << SDL_GetError() << std::endl;

    RenderWindow window("Torque v0.0.1", 1280, 720);

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
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}