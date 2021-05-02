#pragma once

#include "SDL.h"
#include <vector>

class EventManager {
public:
	static std::vector<SDL_Event>& GetFrameEvents();
	static void FillFrameEvents();
	static void ClearFrameEvents();
};

