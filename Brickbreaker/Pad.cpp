#include "Pad.h"
#include <iostream>

Pad::Pad(const Window& window, int w, int h, int x, int y) :
	Window(window), width(w), height(h), pos_x(x), pos_y(y)
{
	changePos = 0;
	inputManager = inputManager::Instance();
}

Pad::~Pad() {
	inputManager::Release();
	inputManager = NULL;
}

void Pad::update(float delta, Ball* ball) {

	padCollision(ball);

	if (pos_x <= 0) {
		pos_x += 1;
		return;
	}
	else if (pos_x >= 700) {
		pos_x -= 1;
		return;
	}
	else {
		pos_x += changePos * delta;

	}
}

void Pad::render() const {
	SDL_Rect rect = { pos_x, pos_y, width, height };
	SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 255);
	SDL_RenderFillRect(_renderer, &rect);
	
}

void Pad::events(SDL_Event& event) {

	inputManager->update();


	if (inputManager->KeyDown(SDL_SCANCODE_LEFT)) {
		if (pos_x <= 0) {
			changePos = 0;
			return;
		}
		changePos = -1 * padSpeed;
	}
	else if (inputManager->KeyDown(SDL_SCANCODE_RIGHT)) {
		if (pos_x >= 700) {
			changePos = 0;
			return;
		}
		changePos = 1 * padSpeed;
	}
	else if (!inputManager->KeyDown(SDL_SCANCODE_LEFT) || !inputManager->KeyDown(SDL_SCANCODE_RIGHT)) {
		
		changePos = 0;
	}
}

void Pad::padCollision(Ball* ball) {
	if (ball->pos_x <= pos_x + 100 && ball->pos_x + ball->width >= pos_x && ball->pos_y <= pos_y + 10 && ball->pos_y + ball->height >= pos_y) {
		if (ball->lastDir_x == -1) {
			ball->direction(-1, -1);
		}
		else if (ball->lastDir_x == 1) {
			ball->direction(1, -1);
		}
	}
}