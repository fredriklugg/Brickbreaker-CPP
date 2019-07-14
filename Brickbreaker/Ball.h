#pragma once
#include "Window.h"
#include <math.h>


const float ballSpeed = 500;

class Ball : public Window {
public:
	Ball(const Window& window, int w, int h, float x, float y);
	~Ball();

	void update(float delta);
	void render() const;
	void direction(float dir_x, float dir_y);
	void wallCollision(float delta);
	void move(float delta);

	float pos_x, pos_y, lastDir_y, lastDir_x;;
	int width, height;
	bool gameOver = false;

private:
	float dir_x, dir_y;
};