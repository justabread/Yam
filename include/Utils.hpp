#pragma once
#include <iostream>
#include <SDL2/SDL.h>

namespace Utils {
    inline float TimeInSeconds () {
        float t = SDL_GetTicks64();

        t *= 0.001f;
        return t;
    }

    inline void ThrowErrorMessage(const char* errorMsg) {
        std::cout << errorMsg << SDL_GetError() << std::endl;
    };
}
