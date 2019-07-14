#pragma once
#include "Window.h"
#include "Ball.h"
#include <stdlib.h> 


class Brick {
public:
	bool state;
	int r, g, b;
};

class Board : public Window {
public:
	Board(const Window& window);
	~Board();

	void createBoard();
	void renderBoard();
	void update(Ball* ball);
	void brickCollision(Ball* ball);

	Brick bricks[12][12];

	bool gameWon;

private:
	float brickoffsetx, brickoffsety;
	int x, y, brickHitCount;

};