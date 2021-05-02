#include "GameObjectManager.h"
#include <iostream>

void GameObjectManager::AddGameObject(GameObject* gameObject) {
	gameObject->m_uniqueId = idCount;
	idCount++;
	gameObject->setGameObjectManager(this);
	g_aAllGameObjects.push_back(gameObject);
}
void GameObjectManager::AddGameObject() {
	GameObject* gameObject = new GameObject();
	gameObject->m_uniqueId = idCount;
	idCount++;
	gameObject->setGameObjectManager(this);
	g_aAllGameObjects.push_back(gameObject);
}

GameObject* GameObjectManager::GetGameObject(int objectId) {
	return g_aAllGameObjects.at(objectId);
}
void GameObjectManager::InitializeGameObjects(json gameObjectsMap) {
	for (auto gameObjectJson : gameObjectsMap["gameObjects"]) {
		//GameObject* _gameObject = GameObjectFactory::get().getPrefab(gameObjectJson["name"]);
		GameObject* _gameObject = new GameObject();

		// Check if _gameObject != nullptr
		if (_gameObject) {

			_gameObject->InitJson(gameObjectJson["name"].get<std::string>().c_str());

			//_gameObject->GetComponent<Transform>()->position = { gameObjectJson["x"], gameObjectJson["y"] };

			AddGameObject(_gameObject);
		}
		else {
			std::cout << "Gameobject " << gameObjectJson["name"] << " is nullptr!" << std::endl;
			// Possible causes:
			//	- Prefab.h not included in PrefabCompiler.cpp
			//	- Wrong string name in .json
		}
	}
}