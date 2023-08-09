#pragma once
#include <SDL.h>

class GameWindow
{
private:
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;

public:
	GameWindow(int width, int height);
	~GameWindow();

	void LoopWindow();

	int GetScreenWidth();
	int GetScreenHeight();
	SDL_Window* GetSDLWindow();
};

