#pragma once

#include "../Core/Component.h"
#include "../Math/Shapes.h"

class Transform;

class Collider : public Component {
public:
	Collider();
	Collider(int x1, int y1, int x2, int y2) { colliderRect.x1 = x1; colliderRect.y1 = y1; colliderRect.x2 = x2; colliderRect.y2 = y2; }
	~Collider() {}

	void Start();
	void Update();

	bool Colliding();
	void PositionCollider();

	//std::vector<GameObject*> CollisionPointObjects(Vec2 point);

	void DrawRect();

	Rect colliderRect, collider;
private:
	Transform* transform;
};

namespace ComponentFactoryRegistrations {
	__declspec(selectany) ComponentFactoryRegistration<Collider> _Collider("collider");
}