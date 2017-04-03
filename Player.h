//
// Created by Stephen Yang on 2017-03-26.
//

#ifndef CC3K_PLAYER_H
#define CC3K_PLAYER_H

#include "Character.h"
#include <iostream>
#include <vector>
#include "Item.h"
#include "Potion.h"

class Enemy;

class Player: public Character{
    std::vector<Item*> potions;
public:
    Player();
    ~Player() override;
    //void addPotion(Item *p) override;
    //bool containPotion(Item *p) override;
};

class Drow: public Player{
public:
    Drow();
    int attack(Character* c);
    int receiveAttack(Character* c);
};

class Vampire: public Player{
public:
    Vampire();
    int attack(Character* c);
    int receiveAttack(Character* c);
};

class Troll: public Player{
public:
    Troll();
    int attack(Character* c);
    int receiveAttack(Character* c);
};

class Shade: public Player{
public:
    Shade();
    int attack(Character* c);
    int receiveAttack(Character* c);
};

class Goblin: public Player{
public:
    Goblin();
    int attack(Character* c);
    int receiveAttack(Character* c);
};

#endif //CC3K_PLAYER_H
