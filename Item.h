#include <string>



class Item {
	int value;
	string whatKind;
public:
	virtual void alterPlayer(Character &c);
}