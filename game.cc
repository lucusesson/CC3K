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
	bool enemyFrozen = false;
	std::cin >> input;

	do {
		g->displayGrid();
		std::cout << "Race: " << g->player->getRace() << " Gold: " << g.player->getGold() << std::endl;
		std::cout << "HP: " << g->player->getHealth() << std::endl;
		std::cout << "Atk: " << g->player->getAtk() << std::endl;
		std::cout << "Def: " << g->player->getDef() << std::endl;
		std::cout << "Action: " << std::endl;

		if (input == "q") {
			std::cout << "You have been defeated" << std::endl;
			break;
		} else if (input == "r") {
			break;
		} else if (input == "f") {
			if (enemyFrozen) enemyFrozen = false;
			else enemyFrozen = true;
		} else if (input == "a" || input == "u") {
			int ns,ew;
			std::cin >> ns;
			std::cin >> ew; 
			if (input == "a") g->playerAttack(ns, ew);
			else g->playerUsePotion(ns, ew);
		} else if (input == "no") {
			if (!g->playerMove(-1, 0)) continue;
		} else if (input == "so") {
			if (!g->playerMove(1, 0)) continue;
		} else if (input == "ea") {
			if (!g->playerMove(0, 1)) continue;
		} else if (input == "we") {
			if (!g->playerMove(0, -1)) continue;
		} else if (input == "ne") {
			if (!g->playerMove(-1, 1)) continue; 
		} else if (input == "nw") {
			if (!g->playerMove(-1, -1)) continue;
		} else if (input == "se") {
			if (!g->playerMove(1, 1)) continue;
		} else if (input == "sw") {
			if (!g->playerMove(1, -1)) continue;
		} else {
			std::cout << "Invalid Command";
			continue;
		}

		if (!enemyFrozen) { g->enemyMove(); }
		else { g->enemyAttack(); }

	} while (g->player->getHealth() > 0 && std::cin >> input);
	delete g;
}