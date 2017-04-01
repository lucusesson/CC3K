//
// Created by Stephen Yang on 2017-03-26.
//

#include <stdio.h>
#include <iostream>
#include "Enemy.h"
#include "Player.h"

int main(){
	Game g;
    ifstream ifs ("cc3kfloor.txt");
    g.startGame(ifs)
    
    while(true) {
    	string s;
    	std::cout << "Restart Game? (Y/y)" << std::endl;
    	std::cin >> s;
    	if (s == "Y" || s == "y") {
    		g.startGame(ifs)
    	} else {
    		break;
    	}
    }
}