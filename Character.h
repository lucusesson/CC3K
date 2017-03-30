//
// Created by Stephen Yang on 2017-03-26.
//

#ifndef CC3K_CHARACTER_H
#define CC3K_CHARACTER_H

#include <string>
#include <stdio.h>
#include <iostream>

class Character {
protected:
    int health, maxHealth, atk, def, gold, x, y;
    int damage(int def, int atk);

    /*
    void alterHealth();
    void alterAtk();
    void alterDef();
    void alterGold();
    void move(int direction);
    void setXY(int x, int y)*/
public:
    std::string race;
    int miss();
    int getHealth();
    int getAtk();
    int getDef();
    int getGold();
    void getSummary();
    //virtual void addPotion(Item *p) = 0;
    //virtual bool containPotion(Item *p) = 0;
    virtual void attack(Character* c) = 0;
    virtual int receiveAttack(Character* c) = 0;
};

#endif //CC3K_CHARACTER_H
