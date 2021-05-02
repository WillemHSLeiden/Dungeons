#pragma once

#include "../Core/Component.h"
#include "../Core/TextureManager.h"

#include "SDL.h"

#include <vector>

class Renderer;

class Animator : public Component {
public:
	Animator() {}

	void Start();
	void Update();
	void SetFrames(std::vector<int> frames_) { frames = frames_; }
	void SetInbetweens(int inBetweens_) { inBetweens = inBetweens_; }
	void Pause() { paused = true; }
	void Play() { paused = false; }

private:
	std::vector<int> frames = { 0 };
	int inBetweens = 1, timer = 0, currFrame = 0, tilesetW, tilesetH, w, h;
	SDL_Rect src;
	bool paused = false;
	Renderer* renderer;
};

namespace ComponentFactoryRegistrations {
	__declspec(selectany) ComponentFactoryRegistration<Animator> _Animator("animator");
}