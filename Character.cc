//
// Created by Stephen Yang on 2017-03-26.
//

#include "Character.h"
#include <math.h>
Character::~Character() {}

bool Character::isDead() {
    if (this->health <= 0){
        return true;
    }
    return false;
}
void Character::setSymbol(char sym) {
    this->symbol = sym;
}

int Character::getX() {
    return this->xVal;
}

int Character::getY() {
    return this->yVal;
}

void Character::setRace(std::string race) {
    this->race = race;
}

std::string Character::getRace() {
    return race;
}
int Character::miss() {
    srand(time(0));
    int a = rand() % 2;
    return a;
}



void Character::setXY(int x, int y) {
        xVal = x;
        yVal = y;

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
    std::cout << "DAMAGE:" << ceil((100.0/(100.0+def))*atk) << std::endl;
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