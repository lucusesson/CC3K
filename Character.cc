//
// Created by Stephen Yang on 2017-03-26.
//

#include "Character.h"
#include <math.h>
using namespace std;

Character::~Character() {}

std::string Character::update = "";

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

void Character::alterAttack(int a) {
    atk += a;
}

void Character::alterDefence(int a) {
    def += a;
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
    if(a == 1) {
    update += "PC picked-up a small pile of gold. PC gold has increased by 1. ";
    }
    else if(a == 2) {
        update += "PC picked-up a normal pile of gold. PC gold has increased by 2. ";
    }
    else if(a == 4) {
        update += "PC picked-up a Merchant Hoard. PC gold has increase by 4. ";
    }
    else if(a == 6) {
        update += "PC picked-up a Dragon Hoard. PC gold has increased by 6. ";
    }
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
    std::cout << "Atk: " << atk << std::endl;
    std::cout << "Def: " << def << std::endl;
    std::cout << "Gold: " << gold << std::endl;
}

char Character::getSymbol() {
    return this->symbol;
}

