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
	void setStairs();
	void moveEnemies();
	void test();
	void test1();
public:
	Grid(std::ifstream &i);
	~Grid();
	void displayGrid();
	
	//start Michael
	Character * Player;
	void enemyMove(bool b);
	bool enemyAttack(Character &c);
	bool playerMove(int ns, int ew);
	void playerAttack(int ns, int ew);
	void playerUsePotion(int ns, int ew);
	//end Michael

	void notify(Info &i) override;
	SubscriptionType subType() const override;

};

#endif