#include "tile.h"

Tile::Tile(char symbol, int x, int y, bool walkable): symbol(symbol), x(x), y(y), walkable(walkable) {}

void Tile::setSymbol(char c) {
	symbol = c;
}

char Tile::getSymbol() { 
	if (item) 
		return item->getSymbol();
	else if (character)
		return character->getSymbol();
	else 
		return symbol;
}

bool Tile::isOccupied() {
	if(character == nullptr && item == nullptr) {
		return true;
	}
	else return false;
}

bool Tile::isWalkable() { return walkable; }

//Any notification to subscription type ALL is passed a nullptr as info,
//given that no actual data is stored within the grid class. The grid class
//is merely notified and reprints the game screen
void Tile::setCharacter(Character * c) {
	character = c;
	c->setXY(x,y);
	notifyObservers(SubscriptionType::All);
}

void Tile::setItem(Item * i) {
	item = i;
	i->setXY(x,y);
	notifyObservers(SubscriptionType::All);
}

void Tile::despawnCharacter() {
	character = nullptr;
	notifyObservers(SubscriptionType::All);
}

void Tile::despawnItem() {
	item = nullptr;
	notifyObservers(SubscriptionType::All);
}

void Tile::move(int ns, int ew) {
	Info i {character, x, y, ns, ew};
	character = nullptr;
	notifyObservers(SubscriptionType::SwitchOnly, i);
}

//If a character is moved, all surrounding within one block radius are notified
void Tile::notify(Info &i) {
	if ((i.x + i.displacedX == x) && (i.y + i.displacedY == y)) {
		setCharacter(i.ch);
	}
}

SubscriptionType Tile::subType() const {
	return SubscriptionType::SwitchOnly;
}

Tile::~Tile() {
	delete character;
	delete item;
}