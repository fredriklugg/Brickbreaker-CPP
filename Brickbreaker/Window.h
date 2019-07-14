#pragma once

#include <string>
#include <SDL.h>

class Window {
public:
	Window(const std::string& title, int width, int height);
	~Window();

	void events(SDL_Event& event);
	void update() const;
	inline bool isClosed() const { return _closed; };

	bool startGame = false;

private:
	bool init();

private:
	std::string _title;
	int _width = 800, _height = 650;
	bool _closed = false;
	SDL_Window* _window = nullptr;

protected:
	SDL_Renderer* _renderer = nullptr;
};