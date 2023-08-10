#include "Utils.hpp"

void Utils::ThrowErrorMessage(const char* errorMsg) {
        std::cout << errorMsg << SDL_GetError() << std::endl;
}