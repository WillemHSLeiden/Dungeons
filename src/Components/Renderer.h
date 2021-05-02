#pragma once

#include "../Core/Component.h"
#include "SDL.h"
#include <string>
#include <iostream>

class Transform;

class Renderer : public Component {
public:
	Renderer();

	void Init(json componentJson);
	void Start();
	void Update();

	SDL_Texture* texture;
	SDL_Rect src;
	SDL_Rect dest;
private:
	Transform* transform;
};

namespace ComponentFactoryRegistrations {
	__declspec(selectany) ComponentFactoryRegistration<Renderer> _Renderer("renderer");
}