#include "grid.h"
#include <random>
#include "Player.h"
#include "Enemy.h"
#include "Gold.h"
#include "Potion.h"

using namespace std;

// helper function for generating a random number between low and high 
//												(inclusive)
int randomNum(int low, int high) {
	/*std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(low,high);
	int rnum = distribution(generator);
	return rnum;*/
    if (low == 0 && high == 4){
        high = 5;
    }
    int a = rand() % (high - low);
    a = a + low;
	if (a > high){
		a = high;
	}
    return a;
}



/*
 *
 */
int Grid::randomChamber(int whichChamber) {
	int chamberSize = theChamber[whichChamber].size();
	int WhereinChamber = randomNum(0, chamberSize-1);
	return WhereinChamber;
}

void Grid::setPotions() {
	int whichPotion, WhereinChamber, whichChamber;
	Item *p = nullptr;
	for(int i = 1; i <= 10; ++i) {
		cout << i << endl;
		while(true) {
			whichPotion = randomNum(1,6);
			whichChamber = randomNum(0,4);
            //cout << whichPotion << " " << whichChamber << endl;
			WhereinChamber = randomChamber(whichChamber);
			if(!theChamber[whichChamber][WhereinChamber]->isOccupied()) break;
		}
        cout << "test3" << "Potion:"<< whichPotion << endl;
		if(whichPotion == 1) {
			p = new atkBoost();
			p->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(p);
            cout << theChamber[whichChamber][WhereinChamber]->getSymbol() << endl;
			items.push_back(p);
		}
		else if(whichPotion == 2) {
			p = new atkWound();
			p->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(p);
            cout << theChamber[whichChamber][WhereinChamber]->getSymbol() << endl;
			items.push_back(p);
		}
		else if(whichPotion == 3) {
			p = new defBoost();
			p->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(p);
            cout << theChamber[whichChamber][WhereinChamber]->getSymbol() << endl;
			items.push_back(p);
		}
		else if(whichPotion == 4) {
			p = new defWound();
			p->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(p);
            cout << theChamber[whichChamber][WhereinChamber]->getSymbol() << endl;
			items.push_back(p);
		}
		else if(whichPotion == 5) {
			p = new healthBoost();
			p->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(p);
            cout << theChamber[whichChamber][WhereinChamber]->getSymbol() << endl;
			items.push_back(p);
		}
		else {
			p = new healthWound();
			p->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(p);
            cout << theChamber[whichChamber][WhereinChamber]->getSymbol() << endl;
			items.push_back(p);
		}
		cout << "Access Chamber:" << whichChamber << "Spot:" << WhereinChamber << endl;
		p = nullptr;
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
			if(!theChamber[whichChamber][WhereinChamber]->isOccupied()) break;
		}
		if(whichGold <= 5) {
			g = new normalGold();
			g->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(g);
			items.push_back(g);
		}
		else if(whichGold > 5 && whichGold <= 6) {
			g = new dragonHoard();
			g->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(g);
			items.push_back(g);
		}
		else if(whichGold > 6) {
			g = new smallGold();
			g->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(g);
			items.push_back(g);
		}
		cout << "Access Chamber:" << whichChamber << "Spot:" << WhereinChamber << endl;
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
			if(!theChamber[whichChamber][WhereinChamber]->isOccupied()) break;
		}
		if(whichEnemy <= 4) {
			e = new Human();
			e->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setCharacter(e);
			characters.push_back(e);
		}
		else if(whichEnemy > 4 && whichEnemy <= 7) {
			e = new Dwarf();
			e->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setCharacter(e);
			characters.push_back(e);
		}
		else if(whichEnemy > 7 && whichEnemy <= 12) {
			e = new Halfling();
			e->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setCharacter(e);
			characters.push_back(e);
		}
		else if(whichEnemy > 12 && whichEnemy <= 14) {
			e = new Elf();
			e->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setCharacter(e);
			characters.push_back(e);
		}
		else if(whichEnemy > 14 && whichEnemy <= 16) {
			e = new Orc();
			e->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setCharacter(e);
			characters.push_back(e);
		}
		else {
			e = new Merchant();
			e->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setCharacter(e);
			characters.push_back(e);
		}
	}
}

void Grid::setStairs() {
	int whichChamber, WhereinChamber;
    whichChamber = randomNum(0,4);
    WhereinChamber = randomChamber(whichChamber);
	cout << "Access Chamber:" << whichChamber << "Spot:" << WhereinChamber << endl;
	theChamber[whichChamber][WhereinChamber]->setSymbol('\\');
}


void Grid::setGrid() {
	//set stairway
	setStairs();
    cout << "stairs" << endl;
	//potions
	setPotions();
    cout << "potions" << endl;
	// gold
	setGold();
    cout << "gold" << endl;
	// enemies
	setEnemies();
    cout << "enemies" << endl;
}

//Lucus Start 

bool Grid::enemyAttack(Character &c) {
	int status;
	int px = player->getX();
	int py = player->getY();
	int cx = c.getX();
	int cy = c.getY();
	if(px - cx <= 1 && px - cx >= 1 && py - cy <=1 && py - cy >= 1) {
		status = c.attack(player);
		if(status == 0) {
			spawnGold(c); 
			theGrid[cx][cy]->despawnCharacter();
		}
		return true;
	}
	return false;
}

void Grid::enemyMove(bool b) {
	// true move and attack
	if(b) {
		int ns, ew, x, y;
		for(auto &c : characters) {
			if(enemyAttack(*c)) {

			}
			else {
				while(true) {
					ns = randomNum(-1, 1);
					ew = randomNum(-1, 1);
					x = c->getX();
					y = c->getY();
					if(!(theGrid[x+ns][y+ew]->isOccupied()) 
						&& theGrid[x+ns][y+ew]->isWalkable()) break;
				}
				// now need to move tile that has corresponding enemy pointer
				theGrid[x][y]->move(ns, ew);

			}
		}
	}
		// false means just attack
	else {
		for(auto &c : characters) {
			enemyAttack(*c);
		}
	}

}


bool Grid::playerMove(int ns, int ew) {
	if (!theGrid[player->getX()+ew][player->getY()+ns]->isOccupied() && theGrid[player->getX()+ew][player->getY()+ns]->isWalkable()) {
		theGrid[player->getX()][player->getY()]->move(ns,ew);
		return true;
	} else {
		return false;
	}
}

//Lucus End

void Grid::playerUsePotion(int ns, int ew) {
// TODO BITCH
}


void Grid::playerAttack(int ns, int ew) {
	for (auto &c : characters) {
		if (player->getX() + ew == c->getX() && player->getY() + ns == c->getY()) {
			if (player->attack(c) == 0) {
				theGrid[c->getX()][c->getY()]->despawnCharacter();
			} 
		}
	}
}

Grid::Grid(std::ifstream &i, Player* p) {
	initGrid(i);
    player = p;
}

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
    cout << "test1" << endl;
	setGrid();
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
    for (int i = 0; i < theChamber.size(); i++) {
        for (int j = 0; j < theChamber[i].size(); j++) {
            std::cout << theChamber[i][j]->getSymbol();

        }
        std::cout << std::endl;
    }
}

void Grid::notify(Info &i) {
	displayGrid();
}

Grid::~Grid() {
	for (int i = 0; i < theGrid.size(); i++){
        for (int j = 0; j < theGrid[0].size();j++){
            delete theGrid[i][j];
        }

	}
	for (int i = 0; i < characters.size(); i++){
		delete characters[i];
	}
	for (int i = 0; i < items.size(); i++){
		delete items[i];
	}
}

//Start Stephen
void Grid::spawnGold(Character& c) {
	if (c.getRace() == "Merchant"){
		//TODO SPAWN GOLD
	}
}
//End Stephen