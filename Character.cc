//
// Created by Stephen Yang on 2017-03-26.
//

#include "Character.h"
#include <math.h>

int Character::damage(int def, int atk) {
    return ceil((100/(100.0+def))*atk);
}

int Character::getAtk() {
    return atk;
}

int Character::getHealth() {
    return health;

}

int Character::getDef() {
    return def;
}

int Character::getGold() {
    return gold;
}

void Character::getSummary() {
    std::cout << "Health: " << health << std::endl;
    std::cout << "atk: " << atk << std::endl;
    std::cout << "def: " << def << std::endl;
    std::cout << "gold: " << gold << std::endl;
}