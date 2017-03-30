#include "Item.h"


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