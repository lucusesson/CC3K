#include "game.h"
#include <string>
#include "Character.h"
#include "Player.h"

using namespace std;

Player* setPlayer() {
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

	Player* player = setPlayer();
	if (player == nullptr) return;

	g = new Grid(ifs, player);
	g->level = 0;

	std::string input;
	bool enemyMove = true; 

	do {
		g->displayGrid();
		std::cout << "Race: " << g->player->getRace() << " Gold: " << g->player->getGold() << std::endl;
		std::cout << "HP: " << g->player->getHealth() << std::endl;
		std::cout << "Atk: " << g->player->getAtk() << std::endl;
		std::cout << "Def: " << g->player->getDef() << std::endl;
		std::cout << player->update << std::endl;
		player->update = "";
		std::cout << "Action: ";
		std::cin >> input;
		if (input == "q") {
			std::cout << "You have been defeated" << std::endl;
			break;
		} else if (input == "r") {
			break;
		} else if (input == "f") {
			if (enemyMove) enemyMove = false;
			else enemyMove = true;
		} else if (input == "a" || input == "u") {
			int ns,ew;
			std::cin >> ns;
			std::cin >> ew; 
			if (input == "a") g->playerAttack(ew, ns);
			else g->playerUsePotion(ew, ns);
		} else if (input == "no") {
			if (!g->playerMove(0, -1)) continue;
		} else if (input == "so") {
			if (!g->playerMove(0, 1)) continue;
		} else if (input == "ea") {
			if (!g->playerMove(1, 0)) continue;
		} else if (input == "we") {
			if (!g->playerMove(-1, 0)) continue;
		} else if (input == "ne") {
			if (!g->playerMove(1, -1)) continue; 
		} else if (input == "nw") {
			if (!g->playerMove(-1, -1)) continue;
		} else if (input == "se") {
			if (!g->playerMove(1, 1)) continue;
		} else if (input == "sw") {
			if (!g->playerMove(-1, 1)) continue;
		} else {
			std::cout << "Invalid Command";
			continue;
		}
		g->enemyMove(enemyMove);

	} while (g->player->getHealth() > 0 && !cin.eof() && g->level < 6);
	delete g;
	if (g->level == 6) {
		cout << "Congrats on beating the Game!!" << endl;
	}
}


