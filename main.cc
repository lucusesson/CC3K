//
// Created by Stephen Yang on 2017-03-26.
//

#include <stdio.h>
#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include "game.h"


int main(){
    srand(time(0));
	Game g;
    std::ifstream ifs ("cc3kfloor.txt");
    g.startGame(ifs);
    
    while(true) {
    	std::string s;
    	std::cout << "Restart Game? (Y/y)" << std::endl;
    	std::cin >> s;
    	if (s == "Y" || s == "y") {
            std::ifstream ifs2 ("cc3kfloor.txt");
    		g.startGame(ifs2);
    	} else {
    		break;
    	}
    }
}