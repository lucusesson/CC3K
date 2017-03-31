//
// Created by Stephen Yang on 2017-03-26.
//

#ifndef CC3K_CHARACTER_H
#define CC3K_CHARACTER_H

#include <string>
#include <stdio.h>
#include <iostream>
class Item;

class Character {
protected:
    int health, maxHealth, atk, def, gold, x, y;
    int damage(int def, int atk);
    char symbol;

    /*
    void alterHealth();
    void alterAtk();
    void alterDef();
    void alterGold();
    void move(int direction);
    void setXY(int x, int y)*/
public:
    bool isDead();
    std::string race;
    int miss();
    int getHealth();
    int getAtk();
    int getDef();
    int getGold();
    char getSymbol();
    void alterHealth(int a);
    void alterGold(int a);
    void setXY(int x, int y);
    void getSummary();
    virtual void addPotion(Item *p) = 0;
    virtual bool containPotion(Item *p) = 0;
    virtual void attack(Character* c) = 0;
    virtual int receiveAttack(Character* c) = 0;
};

#endif //CC3K_CHARACTER_H
