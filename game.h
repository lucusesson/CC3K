#ifndef _GAME_H_
#define _GAME_H_
#include <stdio.h>
#include <iostream>
#include "grid.h"

class Game {
private:
	bool running();
	std::ifstream ifs;
	Grid *g;

public:
	Game();
	void startGame(std::ifstream &i);
};

#endif

