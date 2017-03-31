//
// Created by Stephen Yang on 2017-03-26.
//

#include "Character.h"
#include <math.h>

int Character::miss() {
    srand(time(0));
    int a = rand() % 2;
    return a;
}

void Character::setXY(int x, int y) {
    this->x = x;
    this->y=y;
}

void Character::alterHealth(int a) {
    if (this->health + a >= this->maxHealth){
        this->health = this->maxHealth;
    }
    else {
        this->health += a;
    }
}

void Character::alterGold(int a) {
    this->gold += a;
}

int Character::damage(int def, int atk) {
    return ceil((100.0/(100.0+def))*atk);
}

int Character::getAtk() {
    return atk;
}

int Character::getHealth() {
    return health;

}

int Character::getDef() {
    return def;
}

int Character::getGold() {
    return gold;
}

void Character::getSummary() {
    std::cout << "Health: " << health << std::endl;
    std::cout << "atk: " << atk << std::endl;
    std::cout << "def: " << def << std::endl;
    std::cout << "gold: " << gold << std::endl;
}

char Character::getSymbol() {
    return this->symbol;
}