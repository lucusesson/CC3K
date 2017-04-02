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
    ~Enemy() override;
    void addPotion(Item *p) override;
    bool containPotion(Item *p) override;
};

class Merchant: public Enemy{
    static int threat;
private:
    void setThreat();
public:
    Merchant();
    int attack(Character* c);
    int receiveAttack(Character* c);
    int getThreat();
};

class Human: public Enemy{
public:
    Human();
    int attack(Character* c);
    int receiveAttack(Character* c);
};

class Dwarf: public Enemy{
public:
    Dwarf();
    int attack(Character* c);
    int receiveAttack(Character* c);
};

class Halfling: public Enemy{
public:
    Halfling();
    int attack(Character* c);
    int receiveAttack(Character* c);
};

class Elf: public Enemy{
public:
    Elf();
    int attack(Character* c);
    int receiveAttack(Character* c);
};

class Orc: public Enemy{
public:
    Orc();
    int attack(Character* c);
    int receiveAttack(Character* c);
};

class Dragon: public Enemy{
public:
    Dragon();
    int attack(Character* c);
    int receiveAttack(Character* c);
};



#endif //PROJECT_ENEMY_H
