#include "game.h"
#include <string> 

Game::Game() { g = nullptr; }

void Game::startGame(std::ifstream &ifs) {
	g = new Grid(ifs);
	string input;
	


	while (g.player->getHealth() > 0 && cin >> input) {
		g.displayGrid();
		std::cout << "Race: " << g.player->getRace() << " Gold: " << g.player->getGold() << std::endl;
		std::cout << "HP: " << g.player->getHealth() << std::endl;
		std::cout << "Atk: " << g.player->getAtk() << std::endl;
		std::cout << "Def: " << g.player->getDef() << std::endl;
		std::cout << "Action: " << std::endl;
	}
}