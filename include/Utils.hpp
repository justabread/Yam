#pragma once
#include <iostream>
#include <SDL2/SDL.h>

namespace Utils {
    const uint16_t SCREEN_WIDTH = 1280;
    const uint16_t SCREEN_HEIGHT = 720;
    const uint16_t TEXTURE_SIZE = 32;

    inline float TimeInSeconds () {
        float t = SDL_GetTicks64();

        t *= 0.001f;
        return t;
    }

    inline void ThrowErrorMessage(const char* errorMsg) {
        std::cout << errorMsg << SDL_GetError() << std::endl;
    };
}
