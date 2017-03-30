#include "Gold.h"



using namespace std;

smallGold::smallGold() {
	this->value = 1;
	this->whatKind="small";
}

smallGold::~smallGold() {}

void smallGold::alterPlayer(Character &c) {
	c.alterGold(1);
}