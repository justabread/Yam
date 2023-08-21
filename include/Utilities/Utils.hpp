#pragma once
#include <iostream>
#include <SDL2/SDL.h>

namespace Utils {
    const uint16_t SCREEN_WIDTH = 1280;
    const uint16_t SCREEN_HEIGHT = 720;
    const uint16_t ENTITY_SIZE = 32;
    const uint8_t GRAVITY = 1;
    const uint8_t JUMP_HEIGHT = ENTITY_SIZE + 12;

    enum ActorType {
        GRASS,
        PLAYER
    };

    enum Direction {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    inline float TimeInSeconds () {
        float t = SDL_GetTicks64();

        t *= 0.001f;
        return t;
    }

    inline void ThrowErrorMessage(const char* errorMsg) {
        std::cout << errorMsg << SDL_GetError() << std::endl;
    };
}
