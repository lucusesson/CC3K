#include "Potion.h"

using namespace std;

atkBoost::atkBoost() {
    this->symbol = 'P';
	this->value = 5;
	this->whatKind = "atkBoost";
}

atkBoost::~atkBoost() {}

void atkBoost::alterPlayer(Character &c) {
	c.alterHealth(value);
}


atkWound::atkWound() {
    this->symbol = 'P';
	this->value = -5;
	this->whatKind = "atkWound";
}

atkWound::~atkWound() {}

void atkWound::alterPlayer(Character &c) {
	c.alterHealth(value);
}

defBoost::defBoost() {
    this->symbol = 'P';
	this->value = 5;
	this->whatKind = "defBoost";
}

defBoost::~defBoost() {}

void defBoost::alterPlayer(Character &c) {
	c.alterHealth(value);
}

defWound::defWound() {
    this->symbol = 'P';
	this->value = -5;
	this->whatKind = "defWound";
}

void defWound::alterPlayer(Character &c) {
	c.alterHealth(value);
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
}

healthBoost::healthBoost() {
    this->symbol = 'P';
	this->value = 5;
	this->whatKind = "healthBoost";
}

healthBoost::~healthBoost() {}

void healthBoost::alterPlayer(Character &c) {
	c.alterHealth(value);
}


















