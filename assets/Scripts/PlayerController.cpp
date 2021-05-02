#include "PlayerController.h"

#include "../../src/Core/GameObject.h"
#include "../../src/Core/EventManager.h"

void PlayerController::Start() {
	transform = gameObject->GetComponent<Transform>();
	animator = gameObject->GetComponent<Animator>();
	animator->SetInbetweens(7);
}

void PlayerController::Update() {
	const Uint8* state = SDL_GetKeyboardState(NULL);
	hm = state[SDL_SCANCODE_RIGHT] - state[SDL_SCANCODE_LEFT];
	vm = state[SDL_SCANCODE_DOWN] - state[SDL_SCANCODE_UP];

	transform->position.x += hm * speed;
	transform->position.y += vm * speed;

	for (const SDL_Event event : EventManager::GetFrameEvents()) {
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_RIGHT && hm > 0) { animator->SetFrames({ 3, 7 }); }
			if (event.key.keysym.sym == SDLK_LEFT && hm < 0) { animator->SetFrames({ 1, 5 }); }
			if (event.key.keysym.sym == SDLK_DOWN && vm > 0) { animator->SetFrames({ 0, 4 }); }
			if (event.key.keysym.sym == SDLK_UP && vm < 0) { animator->SetFrames({ 2, 6 }); }
		}
	}
	
	if (abs(vm) + abs(hm) != 0) { animator->Play(); } else { animator->Pause(); }

}

void PlayerController::Move(Direction dir) {
	switch (dir) {
	case UP:
		for (int i = 0; i < 16; i++) {
			transform->position.y--;
		}
		break;
	case LEFT:
		for (int i = 0; i < 16; i++) {
			transform->position.x--;
		}
		break;
	case RIGHT:
		transform->position.x++;
		break;
	case DOWN:
		for (int i = 0; i < 16; i++) {
			transform->position.y++;
		}
		break;
	default:
		break;
	}
}