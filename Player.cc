//
// Created by Stephen Yang on 2017-03-26.
//

#include "Player.h"
#include "Enemy.h"

Player::Player() {}

Drow::Drow() {
    this->race = "Drow";
    this->health = 150;
    this->atk = 25;
    this->def = 15;
}

void Drow::attack(Character *c) {
    c->receiveAttack(this);
}

int Drow::receiveAttack(Character *c) {
    return 1;
}

//TODO: 5HP Every Attack, No Max HP
Vampire::Vampire() {
    this->race = "Vampire";
    this->health = 50;
    this->atk = 25;
    this->def = 25;
    this->maxHealth = 50;
}

void Vampire::attack(Character *c) {
    int a = c->receiveAttack(this);
    if (a == 0 || a == 1){
        this->health += 5;
    }
}

int Vampire::receiveAttack(Character *c) {
    int a = this->miss();
    if (a == 0){
        std::cout << "miss";
        return -1;
    }
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    this->getSummary();
    if (this->health <= 0){
        std:: cout << 'Dead';
        return 0;
    }
    return 1;
}

//TODO: REGAIN 5HP EVERY TURN, HP CAPPED AT 120HP
Troll::Troll() {
    this->race = "Troll";
    this->health = 120;
    this->atk = 25;
    this->def = 15;
    this->maxHealth = 120;
}
void Troll::attack(Character *c) {
    c->receiveAttack(this);
}

int Troll::receiveAttack(Character *c) {
    int a = this->miss();
    if (a == 0){
        std::cout << "miss";
        return -1;
    }
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    this->getSummary();
    if (this->health <= 0){
        std:: cout << 'Dead';
        return 0;
    }
    return 1;
}

Goblin::Goblin() {
    this->race = "Goblin";
    this->health = 110;
    this->atk = 15;
    this->def = 20;
    this->maxHealth = 110;
}

void Goblin::attack(Character *c) {
    int res = c->receiveAttack(this);
    if (res == 0){
        this->gold += 5;
    }
}

int Goblin::receiveAttack(Character *c) {
    int a = this->miss();
    if (a == 0){
        std::cout << "miss";
        return -1;
    }
    int damage = this->damage(this->def, c->getAtk());
    damage = (c->race == "Orcs")? damage * 1.5 : damage;
    this->health -= damage;
    this->getSummary();
    if (this->health <= 0){
        std:: cout << 'Dead';
        return 0;
    }
    return 1;
}

Shade::Shade() {
    this->race = "Shade";
    this->health = 125;
    this->atk = 25;
    this->def = 25;
    this->maxHealth = 125;
}

void Shade::attack(Character *c) {
    c->receiveAttack(this);
}

int Shade::receiveAttack(Character *c) {
    int a = this->miss();
    if (a == 0){
        std::cout << "miss";
        return -1;
    }
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    this->getSummary();
    if (this->health <= 0){
        std:: cout << 'Dead';
        return 0;
    }
    return 1;
}
/*
void Player::addPotion(Item *p) {
	potions->push_back(p);
}

bool Player::containPotion(Item *p) {
	for(auto &x : potions) {
		if(x.whatKind == p->whatKind) return true;
	}
	return false;
}*/