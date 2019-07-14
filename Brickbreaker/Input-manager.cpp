#include "input-manager.h"

inputManager* inputManager::sInstance = NULL;

inputManager* inputManager::Instance() {
	if (sInstance == NULL)
	{
		sInstance = new inputManager();

		return sInstance;
	}
}

void inputManager::Release() {
	delete sInstance;
	sInstance = NULL;
}

inputManager::inputManager() {

}

inputManager::~inputManager() {

}

bool inputManager::KeyDown(int keyIndex) const{
	return keys[keyIndex];
}

void inputManager::update() {
	keys = SDL_GetKeyboardState(NULL);
}