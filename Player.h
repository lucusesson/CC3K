//
// Created by Stephen Yang on 2017-03-26.
//

#ifndef CC3K_PLAYER_H
#define CC3K_PLAYER_H

#include "Character.h"
#include <iostream>

class Enemy;

class Player: public Character{
public:
    Player();
    //void attack(Character& c) = 0;
    //int recieveAttack(Character& c)= 0;
};

class Drow: public Player{
public:
    Drow();
    void attack(Character* c);
    int receiveAttack(Character* c);
};

class Vampire: public Player{
    void attack(Character* c);
    int receiveAttack(Character* c);
};

class Troll: public Player{
    void attack(Character* c);
    int receiveAttack(Character* c);
};

class Shade: public Player{
    void attack(Character* c);
    int receiveAttack(Character* c);
};

#endif //CC3K_PLAYER_H
