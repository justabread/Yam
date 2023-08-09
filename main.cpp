#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include <string>

#include "GameWindow.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, const char **argv)
{
    GameWindow* window = new GameWindow(WIDTH, HEIGHT);
    window->LoopWindow();

    delete window;
    return 0;
}
