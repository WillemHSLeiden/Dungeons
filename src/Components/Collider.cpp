#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "Collider.h"
#include "Renderer.h"
#include "Transform.h"

#include "../Core/GameObject.h"
#include "../Core/GameObjectManager.h"

bool Collider::Colliding() {
	std::vector<GameObject*> gameObjects = gameObject->gameObjectManager->g_aAllGameObjects;

	for (GameObject* gameObject_ : gameObjects) {
		if (gameObject_ == gameObject) continue;

		Rect collider_ = gameObject_->GetComponent<Collider>()->collider;

		if (collider_.x1 <= collider.x2 && collider_.x2 >= collider.x1 &&
			collider_.y1 <= collider.y2 && collider_.y2 >= collider.y1) { return true; }
	}
	return false;
}

void Collider::PositionCollider() {
	collider.x1 = colliderRect.x1 + transform->position.x;
	collider.y1 = colliderRect.y1 + transform->position.y;
	collider.x2 = colliderRect.x2 + transform->position.x;
	collider.y2 = colliderRect.y2 + transform->position.y;
}

//std::vector<GameObject*> Collider::CollisionPointObjects(Vec2 point) {
//	std::vector<GameObject*> gameObjects = gameObject->gameObjectManager->g_aAllGameObjects, collidedGameObjects;
//
//	for (GameObject* gameObject_ : gameObjects) {
//		if (gameObject_ == gameObject) continue;
//
//		Rect collider_ = gameObject_->GetComponent<Collider>()->collider;
//
//		if (point.x <= collider.x2 && point.x >= collider.x1 &&
//			point.y <= collider.y2 && point.y >= collider.y1) {
//			collidedGameObjects.push_back(gameObject_);
//		}
//	}
//	return collidedGameObjects;
//}

void Collider::DrawRect() {
	//SDL_RenderDrawRect(WindowManager::renderer, &TextureManager::CreateRect(collider.y2 - collider.y1, collider.x2 - collider.x1, collider.x1, collider.y1));
}

Collider::Collider()
{
}

void Collider::Start() {
	transform = gameObject->GetComponent<Transform>();
}

void Collider::Update() {
	PositionCollider();
}
#endif
