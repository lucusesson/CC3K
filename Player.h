//
// Created by Stephen Yang on 2017-03-26.
//

#ifndef CC3K_PLAYER_H
#define CC3K_PLAYER_H

#include "Character.h"

class Enemy;

class Player: public Character{
    virtual void attack(Enemy& c);
    virtual int recieveAttack(Player& c);
};

class Drow: public Player{
    void attack(Enemy& c);
    int recieveAttack(Enemy& c);
};

class Vampire: public Player{
    void attack(Enemy& c);
    int recieveAttack(Enemy& c);
};

class Troll: public Player{
    void attack(Enemy& c);
    int recieveAttack(Enemy& c);
};

class Shade: public Player{
    void attack(Enemy& c);
    int recieveAttack(Enemy& c);
};

#endif //CC3K_PLAYER_H
