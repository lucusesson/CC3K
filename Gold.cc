#include "Gold.h"
using namespace std;

smallGold::smallGold() {
	this->value = 1;
	this->whatKind = "small";
}

smallGold::~smallGold() {}

void smallGold::alterPlayer(Character &c) {
	c.alterGold(1);
}

normalGold::normalGold() {
 	this->value = 2;
 	this->whatKind = "normal";
}

normalGold::~normalGold() {}

void normalGold::alterPlayer(Character &c) {
	c.alterGold(2);
}

merchantHoard::merchantHoard() {
	this->value = 4;
	whatKind = "merchantHoard";
}

merchantHoard::~merchantHoard() {}

void merchantHoard::alterPlayer(Character &c) {
	c.alterGold(4);
}

dragonHoard::dragonHoard() {
	value = 6;
	whatKind = "dragonHoard";
}

dragonHoard::~dragonHoard() {}

void dragonHoard::alterPlayer(Character &c) {
	c.alterGold(6);
}