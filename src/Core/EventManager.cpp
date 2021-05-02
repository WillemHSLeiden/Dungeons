#include "EventManager.h"

#include <iostream>

std::vector<SDL_Event>& EventManager::GetFrameEvents() {
	static std::vector<SDL_Event> frame_events;
	return frame_events;
}

void EventManager::FillFrameEvents() {
	SDL_Event event;
	GetFrameEvents().push_back(event);
	while (SDL_PollEvent(&event) != 0)
	{
		GetFrameEvents().push_back(event);
	}
}

void EventManager::ClearFrameEvents() {
	GetFrameEvents().clear();
}