//
// Created by Stephen Yang on 2017-03-26.
//

#ifndef CC3K_CHARACTER_H
#define CC3K_CHARACTER_H

#include "Entity.h"

class Character : public Entity {
    int health, maxHealth, atk, def, gold;
    int getHealth();
    int getAtk();
    int getDef();
    int getGold();
    void alterHealth();
    void alterAtk();
    void alterDef();
    void alterGold();
    void move(int direction);
};

#endif //CC3K_CHARACTER_H
