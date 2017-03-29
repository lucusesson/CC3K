//
// Created by Stephen Yang on 2017-03-26.
//

#include "Player.h"
#include "Enemy.h"

Player::Player() {}

Drow::Drow() {
    this->race = "Drow";
}

void Drow::attack(Character *c) {
    c->receiveAttack(this);
}

int Drow::receiveAttack(Character *c) {
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