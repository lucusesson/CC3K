#include "Potion.h"

using namespace std;

atkBoost::atkBoost() {
	this->value = 5;
	this->whatKind = "atkBoost";
}

atkBoost::~atkBoost() {}

void atkBoost::alterPlayer(Character &c) {
	c.alterHealth(value);
}