//
// Created by Stephen Yang on 2017-03-26.
//

#include <stdio.h>

#include "Character.h"
#include "Player.h"
#include "Enemy.h"

int main(){
    Character *h = new Drow();
    Character *e = new Merchant();
    h->attack(e);
}