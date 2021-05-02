#pragma once

#include "GameObject.h"

#include "../Tools/JsonManager.h"
#include <vector>
#include <string>

class GameObjectManager {
public:
	GameObjectManager() {};
	~GameObjectManager() {};

	std::vector<GameObject*> g_aAllGameObjects;

	void AddGameObject(GameObject* gameObject);
	void AddGameObject();
	GameObject* GetGameObject(int objectId);
	void InitializeGameObjects(json gameObjectsMap);

	void Start() {
		for (GameObject* gameObject : g_aAllGameObjects) {
			gameObject->Start();
		}
	}

	void Update() {
		for (GameObject* gameObject : g_aAllGameObjects) {
			gameObject->Update();
		}
	}

private:
	int idCount = 0;
};