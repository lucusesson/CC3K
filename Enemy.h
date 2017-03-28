//
// Created by Stephen Yang on 2017-03-26.
//

#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include "Character.h"

#include "Player.h"
#include <stdio.h>

class Enemy: public Character{
public:
    Enemy();
    int miss();
};

class Merchant: public Enemy{
public:
    Merchant();
    void attack(Character* c);

    int receiveAttack(Character* c);
};
/*
class Human: public Enemy{
    Human();
    void attack(Character* c);
    int receiveAttack(Character* c);
};

class Dwarf: public Enemy{
    Dwarf();
    void attack(Player& c);
    int receiveAttack(Character* c);
};

class Halfling: public Enemy{
    Halfling();
    void attack(Player& c);
    int receiveAttack(Character* c);
};

class Elf: public Enemy{
    Elf();
    void attack(Player& c);
    int receiveAttack(Character* c);
};

class Orc: public Enemy{
    Orc();
    void attack(Player& c);
    int receiveAttack(Character* c);
};

class Dragon: public Enemy{
    Dragon();
    void attack(Player& c);
    int receiveAttack(Character* c);
};
*/



#endif //PROJECT_ENEMY_H
