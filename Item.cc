#include "Item.h"

using namespace std;

void Item::setXY(int x, int y) {
	this->x = x;
	this->y = y;
}

std::string Item::getKind() {
	return this->whatKind;
}

char Item::getSymbol() { return symbol; }


