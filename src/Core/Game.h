#pragma once

#include "GameObjectManager.h"
#include "WindowManager.h"
#include "EventManager.h"
#include "Map.h"
#include "Scene.h"

bool quit = false;

class Game {
public:
	Game() {};

	void RunGame() {
		windowManager.Init("Dungeons", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 240, 160, false);

		Scene* scene = new Scene();

		scene->Start();

		while (!quit) {

			SDL_RenderClear(WindowManager::renderer);

			frameStart = SDL_GetTicks();

			EventManager::FillFrameEvents();

			scene->Update();

			windowManager.Update();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameDelay > frameTime) {
				SDL_Delay(frameDelay - frameTime);
			}

			EventManager::ClearFrameEvents();

			SDL_RenderPresent(WindowManager::renderer);
		}

		windowManager.Clean();
	}
private:
	const float FPS = 60;
	const float frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	WindowManager windowManager;
};