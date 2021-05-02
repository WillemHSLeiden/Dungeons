#pragma once

#include "GameObjectManager.h"
#include "TextureManager.h"
#include "Map.h"
#include "../Tools/JsonManager.h"

class Scene {
public:
	Scene() {
		map = new Map();
		gameObjectManager = new GameObjectManager();
		tileset = TextureManager::LoadTexture("assets/tileset.png");
	};
	~Scene();

	void Start();
	void Update();
	void InitLayers();

private:
	int tilesetW = 0;
	int tilesetH = 0;

	SDL_Texture* tileset;

	Map* map;
	GameObjectManager* gameObjectManager;

	vector<vector<int>> backgroundLayer;
	vector<vector<int>> staticObjectLayer;
	json gameObjectLayer;
	vector<vector<int>> foregroundLayer;
};

