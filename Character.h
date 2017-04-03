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
    std::string race;
    char symbol;
    int health, maxHealth, atk, def, gold, xVal = 0, yVal = 0;
    int damage(int def, int atk);
    void setRace(std::string race);
    void setSymbol(char sym);
public:
    static std::string update;
    virtual ~Character() = 0;
    std::string getRace();
    bool isDead();
    int miss();
    int getHealth();
    int getAtk();
    int getDef();
    int getGold();
    int getX();
    int getY();
    char getSymbol();
    void alterHealth(int a);
    void alterGold(int a);
    void setXY(int x, int y);
    void getSummary();
    virtual void addPotion(Item *p) = 0;
    virtual bool containPotion(Item *p) = 0;
    virtual int attack(Character* c) = 0;
    virtual int receiveAttack(Character* c) = 0;
};



#endif //CC3K_CHARACTER_H
