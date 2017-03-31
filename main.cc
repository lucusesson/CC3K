//
// Created by Stephen Yang on 2017-03-26.
//

#include <stdio.h>
#include <iostream>
#include "grid.h"
#include "game.h"

int main(){
    std::ifstream ifs("cc3kfloor.txt");
    Game g {};
    g.startGame(ifs);
}