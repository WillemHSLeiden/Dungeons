#pragma once

#include "../Tools/JsonManager.h"
#include "../Tools/json.hpp"

#include "ComponentFactoryRegistration.h"
#include <iostream>

class GameObject;

class Component {
public:
	virtual void Init(json componentJson) {};
	virtual void Start() {};
	virtual void Update() {};
	void setGameObject(GameObject* _gameObject);
protected:
	GameObject* gameObject;
};