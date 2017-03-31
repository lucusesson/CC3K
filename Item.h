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
	virtual char getSymbol() = 0;
	std::string getKind();
	void setXY(int x, int y);
};

#endif
