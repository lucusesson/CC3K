//
// Created by Stephen Yang on 2017-03-26.
//

#include "Enemy.h"
#include <iostream>

int Merchant::threat = 0;

Enemy::Enemy() {}

void Enemy::addPotion(Item *p) {
    return;
}

bool Enemy::containPotion(Item *p) {
    return false;
}

Human::Human() {
    this->race = "Human";
    this->health = 140;
    this->atk = 20;
    this->def = 20;
}

Halfling::Halfling() {
    this->race = "Halfling";
    this->health = 100;
    this->atk = 15;
    this->def = 20;
}

int Halfling::receiveAttack(Character *c) {
    int a = this->miss();
    if (a == 0){
        std::cout << "miss";
        return -1;
    }
    void attack(Character* c);
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    this->getSummary();
    if (this->health <= 0){
        std:: cout << 'Dead';
        return 0;
    }
    return 1;
}

void Halfling::attack(Character *c) {
    c->receiveAttack(this);
}

void Human::attack(Character *c) {
    c->receiveAttack(this);
}

int Human::receiveAttack(Character *c) {
    void attack(Character* c);
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    this->getSummary();
    if (this->health <= 0){
        std:: cout << 'Dead';
        return 0;
    }
    return 1;
}

Dwarf::Dwarf() {
    this->health = 100;
    this->atk = 20;
    this->def = 10;
}

void Dwarf::attack(Character *c) {
    c->receiveAttack(this);
}

int Dwarf::receiveAttack(Character *c) {
    void attack(Character* c);
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    this->getSummary();
    if (this->health <= 0){
        std:: cout << 'Dead';
        return 0;
    }
    return 1;
}

Elf::Elf() {
    this->health = 140;
    this->atk = 30;
    this->def = 10;
}

void Elf::attack(Character *c) {
    c->receiveAttack(this);
    if (c->race != "Drow"){
        c->receiveAttack(this);
    }
}

int Elf::receiveAttack(Character *c) {
    void attack(Character* c);
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    this->getSummary();
    if (this->health <= 0){
        std:: cout << 'Dead';
        return 0;
    }
    return 1;
}

Orc::Orc() {
    this->health = 180;
    this->atk = 30;
    this->def = 25;
}

void Orc::attack(Character *c) {
    c->receiveAttack(this);
}

int Orc::receiveAttack(Character *c) {
    void attack(Character* c);
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    this->getSummary();
    if (this->health <= 0){
        std:: cout << 'Dead';
        return 0;
    }
    return 1;
}

Merchant::Merchant() {
    this->race = "Merchant";
    this->health = 30;
    this->atk = 70;
    this->def = 5;
}

void Merchant::attack(Character *c) {
    if (this->getThreat() == 0){
        return;
    } else {
        c->receiveAttack(this);
    }
}

int Merchant::receiveAttack(Character *c) {
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    this->getSummary();
    if (this->health <= 0){
        std:: cout << 'Dead';
        return 0;
    }
    return 1;
}

int Merchant::getThreat() {
    return threat;
}

void Merchant::setThreat() {
    Merchant::threat = 1;
}

