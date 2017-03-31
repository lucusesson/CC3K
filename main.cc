//
// Created by Stephen Yang on 2017-03-26.
//

#include <stdio.h>
#include <iostream>
#include "Enemy.h"
#include "Player.h"

int main(){
    Character *p = new Shade();
    Character *h = new Halfling();
    p->getSummary();
    p->attack(h);
    h->attack(p);
    p->getSummary();
}