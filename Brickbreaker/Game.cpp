#include "Game.h"

Game::Game(){
	
}

void Game::events(Window& window, Pad& pad) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		pad.events(event);
		window.events(event);
	}
}

void Game::startGame()
{
	std::cout << "PRESS SPACE TO BEGIN!" << std::endl;
	Window window("Brick Breaker 6000", 800, 650);
	Pad pad(window, 100, 10, 330, 600);
	Ball ball(window, 12, 12, 370, 570);
	Board board(window);

	lastFrame = 0;

	board.createBoard();
	
	while (!window.isClosed()) {
		currentFrame = SDL_GetTicks();
		deltaTime = (currentFrame - lastFrame) / 1000.0f;

		events(window, pad);
		//Press space to start the game
		if (window.startGame) {
			currentFrame = SDL_GetTicks();
			deltaTime = (currentFrame - lastFrame) / 1000.0f;
			ball.update(deltaTime);
			pad.update(deltaTime, &ball);
			board.update(&ball);

		}
		pad.render();
		ball.render();
		board.renderBoard();
		window.update();

		lastFrame = currentFrame;

		if (ball.gameOver) {
			std::cout << "YOU LOST! GAME OVER!" << std::endl;
			ball.gameOver = false;
			newGame();
			break;
		}
		else if (board.gameWon) {
			std::cout << "YOU WON!" << std::endl;
			board.gameWon = false;
			newGame();
			break;
		}
	}
}
void Game::newGame() {
	startGame();
}
