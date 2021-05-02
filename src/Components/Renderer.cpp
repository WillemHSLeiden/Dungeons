#include "Renderer.h"
#include "Transform.h"

#include "../Core/GameObject.h"
#include "../Core/TextureManager.h"

#include "SDL_Image.h"

#include <iostream>

Renderer::Renderer() {}

void Renderer::Init(json componentJson) {
	texture = TextureManager::LoadTexture(componentJson["sprite"]);
	auto srcArray = componentJson["src"];
	src = TextureManager::CreateRect(srcArray[0], srcArray[1], srcArray[2], srcArray[3]);
}

void Renderer::Start() {
	transform = gameObject->GetComponent<Transform>();
}

void Renderer::Update() {
	TextureManager::RenderTexture(texture, src, dest);
	dest = TextureManager::CreateRect(src.h * transform->scale.y, src.w * transform->scale.x, transform->position.x, transform->position.y);
}