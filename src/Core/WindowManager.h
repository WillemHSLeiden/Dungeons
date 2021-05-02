#pragma once

#define SDL_MAIN_HANDLED
#include "SDL.h"

class WindowManager {
public:
	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void HandleEvents();
	void Update();
	void Clean();

	static SDL_Renderer* renderer;

private:
	int cnt = 0;
	SDL_Window* window;
};