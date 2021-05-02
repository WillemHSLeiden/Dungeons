#include "Scene.h"

void Scene::Start() {
	InitLayers();

	SDL_QueryTexture(tileset, NULL, NULL, &tilesetW, &tilesetH);

	gameObjectManager->InitializeGameObjects(gameObjectLayer);
	gameObjectManager->Start();
}

void Scene::Update() {
	map->DrawLayer(backgroundLayer, tileset, tilesetW, tilesetH);
	map->DrawLayer(staticObjectLayer, tileset, tilesetW, tilesetH);
	gameObjectManager->Update();
	map->DrawLayer(foregroundLayer, tileset, tilesetW, tilesetH);
}

void Scene::InitLayers() {
	backgroundLayer = Map::LoadMap("Level_Background");
	gameObjectLayer = JsonManager::LoadJson("assets/Maps/Level_GameObjects.json");
	staticObjectLayer = Map::LoadMap("Level_StaticObjects");
	foregroundLayer = Map::LoadMap("Level_Foreground");
}
