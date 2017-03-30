#ifndef _GRID_H_ 
#define _GRID_H_
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "tile.h"
#include "window.h"
#include "Item.h"

class Grid : public Observer {
private:
	int width,height;
	Xwindow xw {};
	std::vector<std::vector<Tile *>> theGrid;
	std::vector<std::vector<Tile *>> theChamber;
	std::vector <Character *> characters;
	std::vector <Item *> items;

	void initGrid(std::ifstream &i);
	void setObservers();
	bool inGrid(int r, int c);
	void setChamber(Tile * t, int r, int c);
	int inChamber(int r, int c);

	void displayGrid();	

public:
	Grid(std::ifstream &i);
	~Grid();
	
	void notify(Info &i) override;
	SubscriptionType subType() const override;

};

#endif