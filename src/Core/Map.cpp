#include "Map.h"
#include "TextureManager.h"
#include <iostream>

vector<vector<int>> Map::LoadMap(string mapName) {
	fstream fin;

	fin.open("assets/Maps/" + mapName + ".csv", ios::in);

	vector<vector<int>> map;

	vector<int> row;
	string line, num, temp;

	while (getline(fin, line)) {
		row.clear();

		stringstream s(line);

		while (getline(s, num, ',')) {
			row.push_back(stoi(num));
		}

		map.push_back(row);
	}

	return map;
}

void Map::DrawLayer(vector<vector<int>> layer, SDL_Texture* tileset, int tilesetW, int tilesetH) {
	int tile = 0;

	SDL_Rect src, dest;

	src.x = src.y = 0;
	src.w = dest.w = 16;
	src.h = dest.h = 16;
	dest.x = dest.y = 0;

	for (int row = 0; row < layer.size(); row++) {
		for (int column = 0; column < layer[0].size(); column++) {
			tile = layer[row][column];

			dest.x = column * 16;
			dest.y = row * 16;

			src.x = (tile % (tilesetW / 16)) * 16;
			src.y = roundf(tile / (tilesetH / 16)) * 16;

			TextureManager::RenderTexture(tileset, src, dest);
		}
	}
}

