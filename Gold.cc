#include "Gold.h"


using namespace std;

smallGold::smallGold() : value{1} {}

smallGold::~smallGold() {}

smallGold::alterPlayer(Character &c) {
	c.alterGold(1);
}

