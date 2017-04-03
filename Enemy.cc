//
// Created by Stephen Yang on 2017-03-26.
//

#include "Enemy.h"
#include <iostream>

using namespace std;

int Merchant::threat = 0;

Enemy::Enemy() {}

/*
void Enemy::addPotion(Item *p) {
    return;
}

bool Enemy::containPotion(Item *p) {
    return false;
}*/

Enemy::~Enemy(){}

Human::Human() {
    this->setSymbol('H');
    this->setRace("Human");
    this->health = 140;
    this->atk = 20;
    this->def = 20;
}

Halfling::Halfling() {
    this->setSymbol('L');
    this->setRace("Halfling");
    this->health = 100;
    this->atk = 15;
    this->def = 20;
}

int Halfling::receiveAttack(Character *c) {
    int a = this->miss();
    if (a == 0){
        update += c->getSymbol();
        update += " missed their attack. ";

    }
    if (a != 0) {
        int damage = this->damage(this->def, c->getAtk());
        this->health -= damage;
        if (c->getSymbol() == '@'){
            update += "PC";
        } else{
            update += c->getSymbol();
        }
        update += " dealt " ;
        update += to_string(damage);
        update += " damage to ";
        update += this->getSymbol();
        update += " with their attack.\n";
        //this->getSummary();
        if (this->health <= 0) {
            update += this->getSymbol();
            update += " has died\n";
            int gold = this->miss();
            c->alterGold(gold + 1);
            return 0;
        } else {
            this->attack(c);
        }
        //this->getSummary();
        //c->getSummary();
        return 1;
    } else {
        return -1;
    }
}

int Halfling::attack(Character *c) {
    return c->receiveAttack(this);
}

int Human::attack(Character *c) {
    return c->receiveAttack(this);
}

int Human::receiveAttack(Character *c) {
    void attack(Character* c);
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    if (c->getSymbol() == '@'){
        update += "PC";
    } else{
        update += c->getSymbol();
    }
    update += " dealt " ;
    update += to_string(damage);
    update += " damage to ";
    update += this->getSymbol();
    update += " with their attack.\n";
    if (this->health <= 0){
        update += this->getSymbol();
        update += " has died\n";
        return 0;
    }else {
        this->attack(c);
    }
    cout << endl;
   // this->getSummary();
    return 1;
}

Dwarf::Dwarf() {
    this->setSymbol('W');
    this->setRace("Dwarf");
    this->health = 100;
    this->atk = 20;
    this->def = 30;
}

int Dwarf::attack(Character *c) {
    return c->receiveAttack(this);
}

int Dwarf::receiveAttack(Character *c) {
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    if (c->getSymbol() == '@'){
        update += "PC";
    } else{
        update += c->getSymbol();
    }
    update += " dealt " ;
    update += to_string(damage);
    update += " damage to ";
    update += this->getSymbol();
    update += " with their attack.\n";
    if (this->health <= 0){
        update += this->getSymbol();
        update += " has died\n";
        int gold = this->miss();
        c->alterGold(gold+1);
        return 0;
    }else {
        this->attack(c);
    }
    cout << endl;
    //this->getSummary();
    return 1;
}

Elf::Elf() {
    this->setRace("Elf");
    this->setSymbol('E');
    this->health = 140;
    this->atk = 30;
    this->def = 10;
}

int Elf::attack(Character *c) {
    int a = c->receiveAttack(this);
    if (c->getRace() != "Drow"){
        a = c->receiveAttack(this);
    }
    return a;
}

int Elf::receiveAttack(Character *c) {
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    if (c->getSymbol() == '@'){
        update += "PC";
    } else{
        update += c->getSymbol();
    }
    update += " dealt " ;
    update += to_string(damage);
    update += " damage to ";
    update += this->getSymbol();
    update += " with their attack.\n";
    if (this->health <= 0){
        update += this->getSymbol();
        update += " has died\n";
        int gold = this->miss();
        c->alterGold(gold+1);
        return 0;
    }else {
        this->attack(c);
    }
    cout << endl;
    //this->getSummary();
    //c->getSummary();
    return 1;
}

Orc::Orc() {
    this->setRace("Orc");
    this->setSymbol('O');
    this->health = 180;
    this->atk = 30;
    this->def = 25;
}

int Orc::attack(Character *c) {
    return c->receiveAttack(this);
}

int Orc::receiveAttack(Character *c) {
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    if (c->getSymbol() == '@'){
        update += "PC";
    } else{
        update += c->getSymbol();
    }
    update += " dealt " ;
    update += to_string(damage);
    update += " damage to ";
    update += this->getSymbol();
    update += " with their attack.\n";
    if (this->health <= 0){
        update += this->getSymbol();
        update += " has died\n";
        int gold = this->miss();
        c->alterGold(gold+1);
        return 0;
    }else {
        this->attack(c);
    }
    cout << endl;
    return 1;
}

Merchant::Merchant() {
    this->setRace("Merchant");
    this->setSymbol('M');
    this->health = 30;
    this->atk = 70;
    this->def = 5;
}

int Merchant::attack(Character *c) {
    if (this->getThreat() == 0){
        return -2;
    } else {
        return c->receiveAttack(this);
    }
}

int Merchant::receiveAttack(Character *c) {
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    if (c->getSymbol() == '@'){
        update += "PC";
    } else{
        update += c->getSymbol();
    }
    update += " dealt " ;
    update += to_string(damage);
    update += " damage to ";
    update += this->getSymbol();
    update += " with their attack.\n";
    if (this->health <= 0){
        update += this->getSymbol();
        update += " has died\n";
        return 0;
    }else {
        this->attack(c);
    }
    cout << endl;
    return 1;
}

int Merchant::getThreat() {
    return threat;
}

void Merchant::setThreat() {
    Merchant::threat = 1;
}

Dragon::Dragon() {
    this->setRace("Dragon");
    this->setSymbol('D');
    this->health = 150;
    this->atk = 20;
    this->def = 20;
}

int Dragon::attack(Character *c) {
    return c->receiveAttack(this);
}

int Dragon::receiveAttack(Character *c) {
    int damage = this->damage(this->def, c->getAtk());
    this->health -= damage;
    if (c->getSymbol() == '@'){
        update += "PC";
    } else{
        update += c->getSymbol();
    }
    update += " dealt " ;
    update += to_string(damage);
    update += " damage to ";
    update += this->getSymbol();
    update += " with their attack.\n";
    if (this->health <= 0){
        update += this->getSymbol();
        update += " has died\n";
        return 0;
    }else {
        this->attack(c);
    }
    cout << endl;
    return 1;
}

