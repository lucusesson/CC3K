#include <string>
#include "Character.h"

class Item {
protected:
	int value;
	int x, y;
	std::string whatKind;
	char symbol;
public:
	virtual void alterPlayer(Character &c);
	virtual char getSymbol();
	virtual void setXY(int x, int y);
};