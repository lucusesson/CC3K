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


atkWound::atkWound() {
	this->value = -5;
	this->whatKind = "atkWound";
}

atkWound::~atkWound() {}

void atkWound::alterPlayer(Character &c) {
	c.alterHealth(value);
}

defBoost::defBoost() {
	this->value = 5;
	this->whatKind = "defBoost";
}

defBoost::~defBoost() {}

void defBoost::alterPlayer(Character &c) {
	c.alterHealth(value);
}

healthWound::healthWound() {
	this->value = -5;
	this->whatKind = "healthWound";
}

healthWound::~healthWound() {}

void healthWound::alterPlayer(Character &c) {
	c.alterHealth(value);
}

healthBoost::healthBoost() {
	this->value = 5;
	this->whatKind = "healthBoost";
}

healthBoost::~healthBoost() {}

healthBoost::alterPlayer(Character &c) {
	c.alterHealth(value);
}


















