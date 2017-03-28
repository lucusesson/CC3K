//
// Created by Stephen Yang on 2017-03-26.
//

#include "Character.h"
#include <math.h>

int Character::damage(int def, int atk) {
    ceil((100/(100+def))*atk);
}