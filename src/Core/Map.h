#pragma once
#include "SDL.h"

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Map {
public:
	static vector<vector<int>> LoadMap(string mapName);
	static void DrawLayer(vector<vector<int>> layer, SDL_Texture* tileset, int tilesetW, int tilesetH);
};