#ifndef _ITEM_H_
#define _ITEM_H_

#include <string>
#include "Character.h"

class Item {
protected:
	int value;
	int x, y;
	std::string whatKind;
	char symbol;
public:
	virtual ~Item() = default;
	virtual void alterPlayer(Character &c) = 0;
	char getSymbol();
	int getX();
	int getY();
	std::string getKind();
	void setXY(int x, int y);
};

#endif
