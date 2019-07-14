#include "Board.h"
#include <iostream>


Board::Board(const Window& window):
	Window(window)
{
	gameWon = false;
	brickHitCount = 0;

	brickoffsetx = 0;
	brickoffsety = 16;

	x = 10;
	y = 0;
}

Board::~Board() {

}

void Board::renderBoard() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			Brick brick = bricks[i][j];

			if (!brick.state)
				continue;

			SDL_Rect brickRect;
			brickRect.x = brickoffsetx + x + i * 65;
			brickRect.y = brickoffsety + y + j * 20;
			brickRect.w = 65;
			brickRect.h = 20;

			SDL_SetRenderDrawColor(_renderer, brick.r, brick.g, brick.b, 255);
			SDL_RenderFillRect(_renderer, &brickRect);
		}
	}
}

void Board::createBoard(){

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			Brick brick;

			//Gives each block a random color
			brick.r = rand() % 255;
			brick.g = rand() % 255;
			brick.b = rand() % 255;

			//4 Standard colors to be chosen at randomly
			/*
			int randomColor = rand() % 4 + 1;

			if (randomColor == 1) { //Blue
				brick.r = 15;
				brick.g = 107;
				brick.b = 255;
			}
			else if (randomColor == 2) { //Green
				brick.r = 0;
				brick.g = 183;
				brick.b = 39;
			}
			else if (randomColor == 3) { //Red
				brick.r = 183;
				brick.g = 6;
				brick.b = 0;
			}
			else if (randomColor == 4) { //Yellow
				brick.r = 234;
				brick.g = 200;
				brick.b = 32;
			}
			*/

			brick.state = true;
			bricks[i][j] = brick;
		}
	}
}

void Board::update(Ball* ball) {
	brickCollision(ball);
	if (brickHitCount == 144) {
		gameWon = true;
	}
}

void Board::brickCollision(Ball* ball) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			Brick brick = bricks[i][j];

			if (brick.state) {
				float brickPos_x = brickoffsetx + x + i * 65;
				float brickPos_y = brickoffsety + y + j * 20;

				if (ball->pos_x <= brickPos_x + 65 && ball->pos_x + ball->width >= brickPos_x && ball->pos_y <= brickPos_y + 20 && ball->pos_y + ball->height >= brickPos_y) {
					bricks[i][j].state = false;
					brickHitCount++;

					//Calculate x_Size and y_Size to check if ball hits wide or long side
					float y_min = 0;
					if (brickPos_y > ball->pos_y) {
						y_min = brickPos_y;
					}
					else {
						y_min = ball->pos_y;
					}
					float y_max = 0;
					if (brickPos_y + 20 < ball->pos_y + ball->height) {
						y_max = brickPos_y + 20;
					}
					else {
						y_max = ball->pos_y + ball->height;
					}
					float y_size = y_max - y_min;
					float x_min = 0;
					if (brickPos_x > ball->pos_x) {
						x_min = brickPos_x;
					}
					else {
						x_min = ball->pos_x;
					}
					float x_max = 0;
					if (brickPos_x + 60 < ball->pos_x + ball->width) {
						x_max = brickPos_x + 60;
					}
					else {
						x_max = ball->pos_x + ball->width;
					}
					float x_size = x_max - x_min;

					//Check if the ball hits wide or long side, and deflect ball based on hit and direction of the ball
					if (x_size > y_size) {
						if (ball->lastDir_y == -1 && ball->lastDir_x == 1) {
							ball->direction(1, 1);
						}
						else if (ball->lastDir_y == 1 && ball->lastDir_x == -1) {
							ball->direction(-1, 1);
						}
						else if (ball->lastDir_y == 1 && ball->lastDir_x == 1) {
							ball->direction(1, -1);
}
						else if (ball->lastDir_y == -1 && ball->lastDir_x == -1) {
							ball->direction(-1, 1);
						}
					}
					else {
						if (ball->lastDir_y == -1 && ball->lastDir_x == 1) {
							ball->direction(-1, 1);
						}
						else if (ball->lastDir_y == 1 && ball->lastDir_x == -1) {
							ball->direction(1, 1);
						}
						else if (ball->lastDir_y == 1 && ball->lastDir_x == 1) {
							ball->direction(-1, 1);
						}
						else if (ball->lastDir_y == -1 && ball->lastDir_x == -1) {
							ball->direction(1, -1);
						}
					}
				}
			}
		}
	}
}
