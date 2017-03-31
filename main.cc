//
// Created by Stephen Yang on 2017-03-26.
//

#include <stdio.h>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"

int main(){
    Character *p = new Drow();
    Character *e = new Human();
    p->attack(e);
}