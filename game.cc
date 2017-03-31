#include "game.h"

Game::Game() { g = nullptr; }

void Game::startGame(std::ifstream &ifs) {
	g = new Grid(ifs);
}

bool Game::running() { }