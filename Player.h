//
// Created by Stephen Yang on 2017-03-26.
//

#ifndef CC3K_PLAYER_H
#define CC3K_PLAYER_H

#include "Character.h"

class Player: public Character{
    virtual void attack(Enemy& c);
    virtual int recieveAttack(Player& c);
};

class Drow: public Player{
    void attack(Enemy& c);
    int recieveAttack(Player& c);
};

class Vampire: public Player{
    void attack(Enemy& c);
    int recieveAttack(Player& c);
};

class Troll: public Player{
    void attack(Enemy& c);
    int recieveAttack(Player& c);
};

class Shade: public Player{
    void attack(Enemy& c);
    int recieveAttack(Player& c);
};

#endif //CC3K_PLAYER_H
