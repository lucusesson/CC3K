#include "grid.h"
#include <random>
#include "Player.h"
#include "Enemy.h"
#include "Gold.h"
#include "Potion.h"

// helper function for generating a random number between low and high 
//												(inclusive)
int randomNum(int low, int high) {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(low,high);
	int rnum = distribution(generator);
	return rnum;
}

// picks random spot in chamber
int Grid::randomChamber(int whichChamber) {
	int chamberSize = theGrid[whichChamber].size();
	int WhereinChamber = randomNum(0, chamberSize-1);
	return WhereinChamber;
}

void Grid::setPotions() {
	int whichPotion, WhereinChamber, whichChamber;
	Item *p;
	for(int i = 1; i <= 10; ++i) {
		while(true) {
			whichPotion = randomNum(1,6);
			whichChamber = randomNum(0,4);
			WhereinChamber = randomChamber(whichChamber);
			if(theChamber[whichChamber][WhereinChamber]->isOccupied()) break;
		}
		if(whichPotion == 1) {
			p = new atkBoost();
			theChamber[whichChamber][WhereinChamber]->setItem(p);
		}
		else if(whichPotion == 2) {
			p = new atkWound();
			theChamber[whichChamber][WhereinChamber]->setItem(p);
		}
		else if(whichPotion == 3) {
			p = new defBoost();
			theChamber[whichChamber][WhereinChamber]->setItem(p);
		}
		else if(whichPotion == 4) {
			p = new defWound();
			theChamber[whichChamber][WhereinChamber]->setItem(p);
		}
		else if(whichPotion == 5) {
			p = new healthBoost();
			theChamber[whichChamber][WhereinChamber]->setItem(p);
		}
		else {
			p = new healthWound();
			theChamber[whichChamber][WhereinChamber]->setItem(p);
		}
	}
}

void Grid::setGold() {
	Item *g;
	int whichGold, whichChamber, WhereinChamber;
	for(int i = 1; i <= 10; ++i) {
		while(true) {
			whichGold = randomNum(1,8);
			whichChamber = randomNum(0,4);
			WhereinChamber = randomChamber(whichChamber);
			if(theChamber[whichChamber][WhereinChamber]->isOccupied()) break;
		}
		if(whichGold <= 5) {
			g = new normalGold();
			theChamber[whichChamber][WhereinChamber]->setItem(g);
		}
		else if(whichGold > 5 && whichGold <= 6) {
			g = new dragonHoard();
			theChamber[whichChamber][WhereinChamber]->setItem(g);
		}
		else if(whichGold > 6) {
			g = new smallGold();
			theChamber[whichChamber][WhereinChamber]->setItem(g);
		}
	}
}

void Grid::setEnemies() {
	Character *e;
	int whichEnemy, whichChamber, WhereinChamber;
	for(int i = 1; i <= 20; ++i) {
		while(true) {
			whichEnemy = randomNum(1,18);
			whichChamber = randomNum(0,4);
			WhereinChamber = randomChamber(whichChamber);
			if(theChamber[whichChamber][WhereinChamber]->isOccupied()) break;
		}
		if(whichEnemy <= 4) {
			e = new Human();
			theChamber[whichChamber][WhereinChamber]->setCharacter(e);
		}
		else if(whichEnemy > 4 && whichEnemy <= 7) {
			e = new Dwarf();
			theChamber[whichChamber][WhereinChamber]->setCharacter(e);
		}
		else if(whichEnemy > 7 && whichEnemy <= 12) {
			e = new Halfling();
			theChamber[whichChamber][WhereinChamber]->setCharacter(e);
		}
		else if(whichEnemy > 12 && whichEnemy <= 14) {
			e = new Elf();
			theChamber[whichChamber][WhereinChamber]->setCharacter(e);
		}
		else if(whichEnemy > 14 && whichEnemy <= 16) {
			e = new Orc();
			theChamber[whichChamber][WhereinChamber]->setCharacter(e);
		}
		else {
			e = new Merchant();
			theChamber[whichChamber][WhereinChamber]->setCharacter(e);
		}
	}
}


void Grid::setGrid() {
	int whichChamber, WhereinChamber;
	//generating which player?
	// grid have player pointer?
	// create player in main, 
	// or create player here, excepting input
	// from stdin about which player they want
	// create that character corresponding to input
	// set random tile to this pointer

	//set player	
	//Character *c = 
	whichChamber = randomNum(0,4);
	WhereinChamber = randomChamber(WhereinChamber);
	//theChamber[whichChamber][WhereinChamber]->setCharacter(c);


	//set stairway
	whichChamber = randomNum(0,4);
	// check if player is in this chamber
	WhereinChamber = randomChamber(whichChamber);
	theChamber[whichChamber][WhereinChamber]->setSymbol('\\');
	//potions
	setPotions();

	// gold
	setGold();
	// enemies
	setEnemies();
}

Grid::Grid(std::ifstream &i) {
	initGrid(i);
}

Grid::~Grid() {}

void Grid::initGrid(std::ifstream &i) {
	char tile;
	int x = 0;
	int y = 0;
	std::vector<Tile *> row;
	theGrid.resize(25, row);

	while (i >> std::noskipws >> tile && y < 25) {
		if (tile == '\n') { 
			x = 0;
			++y;
		} else {
			Tile *t;
			if (tile == '.' || tile == '+' || tile == '#') 
				t = new Tile(tile, x, y, true);
			else if (tile == ' ' || tile == '|' || tile == '-')
				t = new Tile(tile, x, y, false);
			else {
				std::cout << "Invalid Character -> " << tile << std::endl;
				return;
			}

			t->attach(this);
			theGrid[y].push_back(t);
			++x;
		}
	}
	height = theGrid.size();
	width = theGrid[0].size();
	setObservers();
}

bool Grid::inGrid(int r, int c) {
	return r >= 0 && r < height && c >= 0 && c < width ; 
}

void Grid::setObservers() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			//If tile is walkable, check each neighbour and if it exists, add to cell Observer list
			if (theGrid[i][j]->getSymbol() == '.') {
				if (inGrid(i+1,j)) 
					theGrid[i][j]->attach(theGrid[i+1][j]);
				
				if (inGrid(i,j+1)) 
					theGrid[i][j]->attach(theGrid[i][j+1]);
				
				if (inGrid(i-1,j)) 
					theGrid[i][j]->attach(theGrid[i-1][j]);
				
				if (inGrid(i,j-1)) 
					theGrid[i][j]->attach(theGrid[i][j-1]);

				if (inGrid(i+1,j+1)) 
					theGrid[i][j]->attach(theGrid[i+1][j+1]);

				if (inGrid(i-1,j-1)) 
					theGrid[i][j]->attach(theGrid[i-1][j-1]);

				if (inGrid(i+1,j-1)) 
					theGrid[i][j]->attach(theGrid[i+1][j-1]);

				if (inGrid(i-1,j+1)) 
					theGrid[i][j]->attach(theGrid[i-1][j+1]);

				setChamber(theGrid[i][j], i, j);
			}
		}
	}
}

int Grid::inChamber(int r, int c) {
	Tile * t;
	if (theGrid[r-1][c]->getSymbol() == '.')
		t = theGrid[r-1][c];
	else if (theGrid[r][c-1]->getSymbol() == '.')
		t = theGrid[r][c-1];
	else {
		std::vector<Tile *> new_row;
		theChamber.push_back(new_row);
		return theChamber.size() - 1;
	}

	for (int chamber = 0; chamber < theChamber.size(); ++chamber) {
		for (int cell = 0; cell < theChamber[chamber].size(); ++cell) {
			if (theChamber[chamber][cell] == t) return chamber; 
		}
	}
	return -1;
}

void Grid::setChamber(Tile * t, int r, int c) {
	int chamber = inChamber(r,c);
	theChamber[chamber].push_back(t);
}

SubscriptionType Grid::subType() const {
	return SubscriptionType::All;
}

void Grid::displayGrid() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << theGrid[i][j]->getSymbol();
		}
		std::cout << std::endl;
	}
}

void Grid::notify(Info &i) {
	displayGrid();
}





























