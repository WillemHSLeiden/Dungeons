#include "Core/GameObjectManager.h"
#include "Core/WindowManager.h"
#include "Core/EventManager.h"
#include "Core/Game.h"

int main(int argc, char* argv[]) {

	Game* game = new Game();

	game->RunGame();

	return 0;
}