#pragma once

#include "../../src/Core/Component.h"
#include "../../src/Components/Animator.h"
#include "../../src/Components/Transform.h"
#include "SDL.h"
#include <iostream>

enum Direction { UP, RIGHT, LEFT, DOWN };

class PlayerController : public Component {
public:
	void Start();
	void Update();
private:
	void Move(Direction dir);
	
	Direction lookDir = UP;

	Animator* animator;
	
	int hm, vm, speed = 1;

	Transform* transform;
};

namespace ComponentFactoryRegistrations {
	__declspec(selectany) ComponentFactoryRegistration<PlayerController> _PlayerController("playerController");
}