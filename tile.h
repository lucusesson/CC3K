#ifndef _TILE_H_
#define _TILE_H_
#include "subject.h"
#include "observer.h"
#include "Item.h"
#include "Character.h"

class Tile : public Subject, public Observer {

private:
	Character * character;
	Item * item;
	char symbol;
	int x,y;
	bool walkable;


public:
	Tile(char symbol, int x, int y, bool walkable);
	~Tile();
	
	SubscriptionType subType() const override;
	Character* getCharacter();
	bool charSet();
	Item* getItem();
	void setCharacter(Character * c);
	void setItem(Item * i);
	void despawnCharacter();
	void despawnItem();
	bool isOccupied();
	void setSymbol(char c);
	char getSymbol();
	bool isWalkable();
	void move(int ns, int ew);
	void notify(Info &i) override;
	int getX();
	int getY();
};

#endif