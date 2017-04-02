#ifndef _GRID_H_ 
#define _GRID_H_
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "tile.h"
#include "Item.h"
#include "Player.h"

class Grid : public Observer {
private:
	int width,height;
	int stairsChamber;

	std::vector<std::vector<Tile *>> theChamber;
	std::vector <Character *> characters;
	std::vector <Item *> items;
	std::vector<std::vector<Tile *>> theGrid;
	
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
	void spawnGold(Character& c);
	void setPlayer();
public:
	Player* player;
	Grid(std::ifstream &i, Player* p);
	~Grid();
	void displayGrid();
	
	//start Michael
	char getSymbol(int ew, int ns);
	void enemyMove(bool b);
	bool enemyAttack(Character &c);
	bool playerMove(int ew, int ns);
	void playerAttack(int ew, int ns);
	void playerUsePotion(int ns, int ew);
	//end Michael

	void notify(Info &i) override;
	SubscriptionType subType() const override;

};

#endif