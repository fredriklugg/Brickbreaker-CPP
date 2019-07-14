#pragma once
#include <SDL.h>


class inputManager {

private:
	static inputManager* sInstance;

	const Uint8* keys;

public:
	static inputManager* Instance();
	static void Release();

	bool KeyDown(int keyIndex) const;

	void update();

private:
	inputManager();
	~inputManager();
};