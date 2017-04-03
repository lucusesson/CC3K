#include "tile.h"


using namespace std;

Tile::Tile(char symbol, int x, int y, bool walkable): symbol(symbol), x(x), y(y), walkable(walkable) {
	this->character = nullptr;
	this->item=nullptr;
}

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
		return false;
	}
	else return true;
}

bool Tile::isWalkable() { return walkable; }

//Any notification to subscription type ALL is passed a nullptr as info,
//given that no actual data is stored within the grid class. The grid class
//is merely notified and reprints the game screen
void Tile::setCharacter(Character* c) {
	character = c;
	c->setXY(x,y);
}

int Tile::getX() {
    return x;
}

int Tile::getY() {
    return y;
}

bool Tile::charSet(){
	if (character != nullptr){
		return true;
	} else{
		return false;
		}
}

Character* Tile::getCharacter(){
		return this->character;
}

Item* Tile::getItem() {
	return item;
}

void Tile::setItem(Item * i) {
	item = i;
	i->setXY(x,y);

}

void Tile::despawnCharacter() {
	character = nullptr;

}

void Tile::despawnItem() {
	item = nullptr;
}

void Tile::move(int ns, int ew) {
	Info i {character, x, y, ew, ns};
	character = nullptr;
	notifyObservers(SubscriptionType::SwitchOnly, i);
}

//If a character is moved, all surrounding within one block radius are notified
void Tile::notify(Info &i) {
	//cout << "X: " << x << " Y: " << y << " DX:" << i.x + i.displacedX << " DY: " << i.y + i.displacedY << endl;
	if ((i.x + i.displacedX == x) && (i.y + i.displacedY == y)) {
		setCharacter(i.ch);
	}
}

SubscriptionType Tile::subType() const {
	return SubscriptionType::SwitchOnly;
}

Tile::~Tile() {
	if (character != nullptr)
		delete character;
	if (item != nullptr)
		delete item;
}

