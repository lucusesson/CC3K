#ifndef _GRID_H_ 
#define _GRID_H_
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "tile.h"
#include "Item.h"
class Character;

class Grid : public Observer {
private:
	int width,height;
	Character *Player;
	std::vector<std::vector<Tile *>> theGrid;
	std::vector<std::vector<Tile *>> theChamber;
	std::vector <Character *> characters;
	std::vector <Item *> items;
	void initGrid(std::ifstream &i);
	void setObservers();
	bool inGrid(int r, int c);
	void setChamber(Tile * t, int r, int c);
	int inChamber(int r, int c);
	void setGrid();
	int randomChamber(int whichChamber);
	void setPotions();
	void setGold();
	void setEnemies();	
	void setPlayer();

public:
	Grid(std::ifstream &i);
	~Grid();
	void displayGrid();
	
	void notify(Info &i) override;
	SubscriptionType subType() const override;

};

#endif