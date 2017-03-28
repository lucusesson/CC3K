#ifndef __GH__
#define __GH__

#include "Entity.h"
#include <string>



class smallGold : public Item {
	smallGold();
	~smallGold();
	void alterPlayer(Character &c) override;
}

class normalGold : public Item {
	normalGold();
	~normalGold();
	void alterPlayer(Character &c) override;
}

class merchantHoard : public Item {
	merchantHoard();
	~merchantHoard();
	void alterPlayer(Character &c) override;
}

class dragonHoard : public Item {
	dragonHoard();
	~dragonHoard();
	void alterPlayer(Character &c) override;
}