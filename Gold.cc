#include "Gold.h"


using namespace std;

smallGold::smallGold() : value{1}, whatKind("small") {}

smallGold::~smallGold() {}

smallGold::alterPlayer(Character &c) {
	c.alterGold(1);
}

