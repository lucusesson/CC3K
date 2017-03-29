#include "Potion.h"

using namespace std;

atkBoost::atkBoost() : value{5}, whatKind{"atkBoost"} {}

atkBoost::~atkBoost() {}

atkBoost::alterPlayer(Character &c) {
	c.alterHealth(value);
}