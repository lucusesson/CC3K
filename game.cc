#include "game.h"
#include <string>
#include "Character.h" 

Character * setPlayer() {
	char s;
	std::cout << "Enter a race: ";
	std::cin >> s;
	if (s == 's') 
		return new Shade();
	else if (s == 'd')
		return new Drow();
	else if (s == 'v')
		return new Vampire();
	else if (s == 'g')
		return new Goblin();
	else if (s == 't')
		return new Troll();
	else 
		return nullptr;

}

Game::Game() { g = nullptr; }

void Game::startGame(std::ifstream &ifs) {
	Character * player = setPlayer();
	if (player == nullptr) return;

	g = new Grid(ifs, player);
	std::string input;
	


	do {
		g->displayGrid();
		std::cout << "Race: " << g->player->getRace() << " Gold: " << g.player->getGold() << std::endl;
		std::cout << "HP: " << g->player->getHealth() << std::endl;
		std::cout << "Atk: " << g->player->getAtk() << std::endl;
		std::cout << "Def: " << g->player->getDef() << std::endl;
		std::cout << "Action: " << std::endl;

		if (input == "q") {
			std::cout << "You have been defeated" << std::endl;
			return;
		} else if (input == "no") {
			g
		}

	} while (g->player->getHealth() > 0 && std::cin >> input);
}