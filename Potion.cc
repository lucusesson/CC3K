#include "Potion.h"

using namespace std;

atkBoost::atkBoost() {
    this->symbol = 'P';
	this->value = 5;
	this->whatKind = "atkBoost";
}

atkBoost::~atkBoost() {}

void atkBoost::alterPlayer(Character &c) {
	c.alterAttack(value);
	c.update += "PC consumed an attack boost potion";
}


atkWound::atkWound() {
    this->symbol = 'P';
	this->value = -5;
	this->whatKind = "atkWound";
}

atkWound::~atkWound() {}

void atkWound::alterPlayer(Character &c) {
	c.alterAttack(value);
	c.update += "PC consumed a attack wound potion";
}

defBoost::defBoost() {
    this->symbol = 'P';
	this->value = 5;
	this->whatKind = "defBoost";
}

defBoost::~defBoost() {}

void defBoost::alterPlayer(Character &c) {
	c.alterDefence(value);
	c.update += "PC consumed a defence boost potion";
}

defWound::defWound() {
    this->symbol = 'P';
	this->value = -5;
	this->whatKind = "defWound";
}

void defWound::alterPlayer(Character &c) {
	c.alterDefence(value);
	c.update += "PC consumed a defence wound potion";
}


defWound::~defWound() {

}
healthWound::healthWound() {
    this->symbol = 'P';
	this->value = -5;
	this->whatKind = "healthWound";
}

healthWound::~healthWound() {}

void healthWound::alterPlayer(Character &c) {
	c.alterHealth(value);
	c.update += "PC consumed a health wound potion";
}

healthBoost::healthBoost() {
    this->symbol = 'P';
	this->value = 5;
	this->whatKind = "healthBoost";
}

healthBoost::~healthBoost() {}

void healthBoost::alterPlayer(Character &c) {
	c.alterHealth(value);
	c.update += "PC consumed a health boost potion";
}


















