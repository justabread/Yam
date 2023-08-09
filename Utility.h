#ifndef UTILITY_H
#define UTILITY_H

#include <SDL.h>
#include <string>
#include <iostream>

namespace Utility {
	void ThrowSDLError(std::string errorMsg) {
		std::cout << errorMsg << SDL_GetError() << std::endl;
	}

	void ShowWindowDetails(GameWindow* window) {
		std::cout << "  ID: " << SDL_GetWindowID(window->GetSDLWindow()) << std::endl;
		std::cout << "  Width: " << window->GetScreenWidth() << std::endl;
		std::cout << "  Height: " << window->GetScreenHeight() << std::endl;
	}
}

#endif
