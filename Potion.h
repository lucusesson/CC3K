#include "Item.h"
class Character;

class atkBoost : public Item {
	atkBoost();
	~atkBoost();
	void alterPlayer(Character &c) override;
};

class atkWound : public Item {
	atkWound();
	~atkWound();
	void alterPlayer(Character &c) override;
};

class defBoost : public Item {
	defBoost();
	~defBoost();
	void alterPlayer(Character &c) override;
};

class defWound : public Item {
	defWound();
	~defWound();
	void alterPlayer(Character &c) override;
};