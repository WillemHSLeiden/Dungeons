#include "GameObject.h"

void GameObject::AddComponent(Component* component) {
	component->setGameObject(this);
	components.push_back(component);
}

void GameObject::RemoveComponent() {}

void GameObject::InitJson(const char* jsonFileName) {
	const char* jsonFolder = "assets/Prefabs/Json/";
	char jsonFile[100] = "";
	strcat_s(jsonFile, sizeof(jsonFile), jsonFolder);
	strcat_s(jsonFile, sizeof(jsonFile), jsonFileName);
	strcat_s(jsonFile, sizeof(jsonFile), ".json");

	json gameObjectJson = JsonManager::LoadJson(jsonFile);

	for (auto _componentItems : gameObjectJson["components"].items()) {
		Component* _component = ComponentFactory::get().getPrefab(_componentItems.key());
		json _componentJson = _componentItems;
		_component->Init(_componentJson[_componentItems.key()]);
		AddComponent(_component);
	}
}
