#include "Potion.h"

using namespace std;

atkBoost::atkBoost() : value{5} {}

atkBoost::~atkBoost() {}

atkBoost::alterPlayer(Character &c) {
	c.alterHealth(value);
}