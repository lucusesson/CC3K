#ifndef __PH__
#define __PH__

#include "Item.h"
class Character;

class atkBoost : public Item {
	void alterPlayer(Character &c) override;
public:
	atkBoost();
	~atkBoost();
};

class atkWound : public Item {
	void alterPlayer(Character &c) override;
public:
	atkWound();
	~atkWound();
};

class defBoost : public Item {
	void alterPlayer(Character &c) override;
public:
	defBoost();
	~defBoost();
};

class defWound : public Item {
	void alterPlayer(Character &c) override;
public:
	defWound();
	~defWound();
};

class healthBoost : public Item {
	void alterPlayer(Character &c) override;
public:
	healthBoost();
	~healthBoost();
};

class healthWound : public Item {
	void alterPlayer(Character &c) override;
public:
	healthWound();
	~healthWound();
};

#endif

