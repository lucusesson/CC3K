//
// Created by Stephen Yang on 2017-03-26.
//

#include "Enemy.h"
#include <iostream>

Enemy::Enemy() {}

int Enemy::miss() {
    srand(time(0));
    int a = rand() % 2;
    return a;
}
/*
Human::Human() {
    this->health = 140;
    this->atk = 20;
    this->def = 20;
}

Dwarf::Dwarf() {
    this->health = 100;
    this->atk = 20;
    this->def = 10;
}

Elf::Elf() {
    this->health = 140;
    this->atk = 30;
    this->def = 10;
}

Orc::Orc() {
    this->health = 180;
    this->atk = 30;
    this->def = 25;
}
*/
Merchant::Merchant() {
    this->race = "Merchant";
    this->health = 30;
    this->atk = 70;
    this->def = 5;
}

int Merchant::receiveAttack(Character *c) {
    int a = this->miss();
    if (a == 0){
        std::cout << "miss";
        return -1;
    }
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    if (this->health < 0){
        std:: cout << 'Dead';
        return 0;
    }
    return 1;
}



