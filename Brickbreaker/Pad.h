#pragma once
#include "input-manager.h"
#include "Window.h"
#include "Ball.h"

const float padSpeed = 600;

class Pad : public Window {
public:
	Pad(const Window& window, int w, int h, int x, int y);
	~Pad();

	void update(float delta, Ball* ball);
	void render() const;
	void padCollision(Ball* ball);

	void events(SDL_Event& event);

private:
	int width, height, changePos;
	float pos_x, pos_y;
	inputManager* inputManager;
};