#ifndef __GH__
#define __GH__

#include <string>
#include "Item.h"
#include "Character.h"



class smallGold : public Item {
	smallGold();
	~smallGold();
	void alterPlayer(Character &c) override;
};

class normalGold : public Item {
	normalGold();
	~normalGold();
	void alterPlayer(Character &c) override;
};

class merchantHoard : public Item {
	merchantHoard();
	~merchantHoard();
	void alterPlayer(Character &c) override;
};

class dragonHoard : public Item {
	dragonHoard();
	~dragonHoard();
	void alterPlayer(Character &c) override;
};

#endif