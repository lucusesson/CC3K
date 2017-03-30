//
// Created by Stephen Yang on 2017-03-26.
//

#ifndef CC3K_PLAYER_H
#define CC3K_PLAYER_H

#include "Character.h"
#include <iostream>
#include <vector>

class Enemy;

class Player: public Character{
public:
    Player();
    void addPotion(Item *p) override;
    bool containPotion(Item *p) override;
};

class Drow: public Player{
public:
    Drow();
    void attack(Character* c);
    int receiveAttack(Character* c);
};

class Vampire: public Player{
    Vampire();
    void attack(Character* c);
    int receiveAttack(Character* c);
};

class Troll: public Player{
    Troll();
    void attack(Character* c);
    int receiveAttack(Character* c);
};

class Shade: public Player{
    Shade();
    void attack(Character* c);
    int receiveAttack(Character* c);
};

class Goblin: public Player{
    Goblin();
    void attack(Character* c);
    int receiveAttack(Character* c);
};

#endif //CC3K_PLAYER_H
