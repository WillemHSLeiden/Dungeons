#pragma once

#include "Component.h"

#include "../Tools/JsonManager.h"
#include "../Tools/json.hpp"

#include <cstdint>
#include <vector>
#include <map>
#include <string>

#include <iostream>

class GameObjectManager;

class GameObject {
public:
	//GameObject() {};
	//~GameObject() {};

	uint32_t m_uniqueId;

	virtual void Init() { }

	void AddComponent(Component* component);

	template <class T> 
	T* GetComponent();

	std::vector<Component*> GetComponents() { return components; };

	void RemoveComponent();

	void InitJson(const char* jsonFileName);

	void Start() {
		for (Component* component : GetComponents()) {
			component->Start();
		}
	};

	void Update() {
		for (Component* component : GetComponents()) {
			component->Update();
		}
	};

	void setGameObjectManager(GameObjectManager* _gameObjectManager) { gameObjectManager = _gameObjectManager; }

	GameObjectManager* gameObjectManager;
private:
	std::vector<Component*> components;
};

template<class T>
inline T* GameObject::GetComponent() {
	for (auto component : GetComponents()) {
		T* isT = dynamic_cast<T*> (component);
		if (!isT) continue;
		return isT;
	}
	return NULL;
};