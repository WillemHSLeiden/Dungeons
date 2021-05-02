#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(std::string _textureName) {
	const char* textureName = _textureName.c_str();
	SDL_Surface* tempSurface = IMG_Load(textureName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(WindowManager::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::RenderTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(WindowManager::renderer, texture, &src, &dest);
}

// Move this to a new class to encapsulate
SDL_Rect TextureManager::CreateRect(int h, int w, int x, int y) {
	SDL_Rect src;

	src.h = h;
	src.w = w;
	src.x = x;
	src.y = y;

	return src;
}
