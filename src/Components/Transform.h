#pragma once

#include "../Core/Component.h"
#include "../Math/Vec2.h"

class Transform : public Component {
public:
	Transform() {}
	Transform(Vec2 _position) { _position = position; }
	Transform(Vec2 _position, float _rotation) { _position = position; _rotation = rotation; }
	Transform(Vec2 _position, float _rotation, Vec2 _scale) { _position = position; _rotation = rotation; _scale = scale; }

	Vec2 position = { 0, 0 };
	float rotation = 0;
	Vec2 scale = { 1, 1 };
};

namespace ComponentFactoryRegistrations {
	__declspec(selectany) ComponentFactoryRegistration<Transform> _Transform("transform");
}