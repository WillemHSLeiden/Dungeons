#pragma once

#include "SDL_Image.h"
#include "WindowManager.h"

#include <string>

class TextureManager {
public:
	static SDL_Texture* LoadTexture(std::string textureName);
	static void RenderTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
	static SDL_Rect CreateRect(int h, int w, int x, int y);
};

