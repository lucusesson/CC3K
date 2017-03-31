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
    void addPotion(Item *p);
    bool containPotion(Item *p);
};

class Merchant: public Enemy{
    static int threat;
private:
    void setThreat();
public:
    Merchant();
    void attack(Character* c);
    int receiveAttack(Character* c);
    int getThreat();
};

class Human: public Enemy{
public:
    Human();
    void attack(Character* c);
    int receiveAttack(Character* c);
};

class Dwarf: public Enemy{
public:
    Dwarf();
    void attack(Character* c);
    int receiveAttack(Character* c);
};

class Halfling: public Enemy{
public:
    Halfling();
    void attack(Character* c);
    int receiveAttack(Character* c);
};

class Elf: public Enemy{
public:
    Elf();
    void attack(Character* c);
    int receiveAttack(Character* c);
};

class Orc: public Enemy{
public:
    Orc();
    void attack(Character* c);
    int receiveAttack(Character* c);
};

class Dragon: public Enemy{
public:
    Dragon();
    void attack(Character* c);
    int receiveAttack(Character* c);
};



#endif //PROJECT_ENEMY_H
