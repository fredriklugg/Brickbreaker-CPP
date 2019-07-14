#pragma once

#include <iostream>
#include <SDL.h>

#include "Window.h"
#include "Pad.h"
#include "Ball.h"
#include "Board.h"

class Game
{
public:
	Game();
	void events(Window& window, Pad& pad);
	void startGame();
	void newGame();

private:
	unsigned int lastFrame, currentFrame;
	float deltaTime;


};
