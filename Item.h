#include <string>
#include "Character.h"

class Item {
	int value;
	std::string whatKind;
public:
	virtual void alterPlayer(Character &c);
};