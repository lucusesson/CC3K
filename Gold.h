#ifndef __GH__
#define __GH__

#include <string>
#include "Item.h"
#include "Character.h"



class smallGold : public Item {
	void alterPlayer(Character &c) override;
public:
	smallGold();
	~smallGold();
	
};

class normalGold : public Item {
	void alterPlayer(Character &c) override;
public:
	normalGold();
	~normalGold();
};

class merchantHoard : public Item {
	void alterPlayer(Character &c) override;
public:
	merchantHoard();
	~merchantHoard();
	
};

class dragonHoard : public Item {
	void alterPlayer(Character &c) override;
public:
	dragonHoard();
	~dragonHoard();
};

#endif