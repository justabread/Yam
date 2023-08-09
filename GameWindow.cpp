#include "GameWindow.h"
#include "Utility.h"
#include <glad/glad.h>

GameWindow::GameWindow(int width, int height)
{
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    if (!(SDL_Init(SDL_INIT_VIDEO) < 0)) {
        window = SDL_CreateWindow("Torque", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
        if (window != NULL) {
            surface = SDL_GetWindowSurface(window);
            std::cout << "Window created: " << std::endl;
            Utility::ShowWindowDetails(this);

            SDL_GL_CreateContext(this->GetSDLWindow());
            if (gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
                std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
                std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
                std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
            }
        }
        else {
            Utility::ThrowSDLError("Window could not be created: ");
            exit(1);
        }
    }
    else {
        Utility::ThrowSDLError("SDL could not be initialized: ");
        exit(1);
    }
}

GameWindow::~GameWindow()
{
    std::cout << "Window " << SDL_GetWindowID(window) << " closed." << std::endl;

    SDL_DestroyWindow(window);
    SDL_Quit();
}

void GameWindow::LoopWindow()
{
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

    SDL_Event e;
    bool quit = false;

    while (quit == false) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                break;
            }
        }
    }
}

int GameWindow::GetScreenWidth()
{
    return SCREEN_WIDTH;
}

int GameWindow::GetScreenHeight()
{
    return SCREEN_HEIGHT;
}

SDL_Window* GameWindow::GetSDLWindow()
{
    return window;
}
