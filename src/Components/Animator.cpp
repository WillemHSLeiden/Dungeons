#include "Animator.h"
#include "Renderer.h"
#include "../Core/GameObject.h"

void Animator::Start() {
	renderer = gameObject->GetComponent<Renderer>();
	h = renderer->src.h;
	w = renderer->src.w;
	SDL_QueryTexture(renderer->texture, NULL, NULL, &tilesetW, &tilesetH);
}

void Animator::Update() {
	if (!paused) {
		timer++;
		renderer->src = TextureManager::CreateRect(h, w, (frames[currFrame] % (tilesetW / 16)) * 16, roundf(frames[currFrame] / (tilesetW / 16)) * 16);
		if (timer > inBetweens) {
			timer = 0;
			currFrame = (currFrame + 1) % frames.size();
		}
	}
}
