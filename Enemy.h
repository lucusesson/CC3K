//
// Created by Stephen Yang on 2017-03-26.
//

#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include "Character.h"

#include "Player.h"

class Enemy: public Character{
    Enemy();
    virtual void attack(Player& c);
    virtual int recieveAttack(Player& c);
};

class Merchant: public Enemy{
    Merchant();
    void attack(Player& c);
    int recieveAttack(Player& c);
};

class Human: public Enemy{
    Human();
    void attack(Player& c);
    int recieveAttack(Player& c);
};

class Dwarf: public Enemy{
    Dwarf();
    void attack(Player& c);
    int recieveAttack(Player& c);
};

class Halfling: public Enemy{
    Halfling();
    void attack(Player& c);
    int recieveAttack(Player& c);
};

class Elf: public Enemy{
    Elf();
    void attack(Player& c);
    int recieveAttack(Player& c);
};

class Orc: public Enemy{
    Orc();
    void attack(Player& c);
    int recieveAttack(Player& c);
};

class Dragon: public Enemy{
    Dragon();
    void attack(Player& c);
    int recieveAttack(Player& c);
};




#endif //PROJECT_ENEMY_H
