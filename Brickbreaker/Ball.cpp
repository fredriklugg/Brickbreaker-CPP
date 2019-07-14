#include "Ball.h"
#include <iostream>

Ball::Ball(const Window& window, int w, int h, float x, float y) :
	Window(window), width(w), height(h), pos_x(x), pos_y(y)
{
	lastDir_x = 0;
	lastDir_y = 0;
	dir_x = 0;
	dir_y = 0;
	direction(1, -1);
}

Ball::~Ball() {

}

void Ball::update(float delta) {

	wallCollision(delta);

}

void Ball::render() const {
	SDL_Rect rect = { pos_x, pos_y, width, height };
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(_renderer, &rect);
}

void Ball::direction(float dir_x, float dir_y) {
	lastDir_x = dir_x;
	lastDir_y = dir_y;

	float length = sqrt(dir_x * dir_x + dir_y * dir_y);
	this->dir_x = ballSpeed * (dir_x / length);
	this->dir_y = ballSpeed * (dir_y / length);
}

void Ball::move(float delta) {
	pos_x += dir_x * delta;
	pos_y += dir_y * delta;
}

void Ball::wallCollision(float delta) {
	if (pos_x <= 0) {
		if (lastDir_y == -1) {
			direction(1, -1);
		}
		else if (lastDir_y == 1) {
			direction(1, 1);
		}
	}
	else if (pos_x >= 780) {
		if (lastDir_y == -1) {
			direction(-1, -1);
		}
		else if (lastDir_y == 1) {
			direction(-1, 1);
		}
	}
	else if (pos_y <= 0) {
		if (lastDir_x == -1) {
			direction(-1, 1);
		}
		else if (lastDir_x == 1) {
			direction(1, 1);
		}
	}
	else if (pos_y >= 650) {
		gameOver = true;
	}
	move(delta);
}
