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
    if (low == 0 && high == 3){
        high = 4;
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
		while(true) {
			whichPotion = randomNum(1,6);
			whichChamber = randomNum(0,4);
			WhereinChamber = randomChamber(whichChamber);
			if(!theChamber[whichChamber][WhereinChamber]->isOccupied()) break;
		}
		if(whichPotion == 1) {
			p = new atkBoost();
			p->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(p);
			items.push_back(p);
		}
		else if(whichPotion == 2) {
			p = new atkWound();
			p->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(p);
			items.push_back(p);
		}
		else if(whichPotion == 3) {
			p = new defBoost();
			p->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(p);
			items.push_back(p);
		}
		else if(whichPotion == 4) {
			p = new defWound();
			p->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(p);
			items.push_back(p);
		}
		else if(whichPotion == 5) {
			p = new healthBoost();
			p->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(p);
			items.push_back(p);
		}
		else {
			p = new healthWound();
			p->setXY(whichChamber,WhereinChamber);
			theChamber[whichChamber][WhereinChamber]->setItem(p);
			items.push_back(p);
		}
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
	theChamber[whichChamber][WhereinChamber]->setSymbol('\\');
    stairsChamber = whichChamber;
}
void Grid::setPlayer() {
    int whichChamber = randomNum(0,3);
    if (whichChamber >= stairsChamber){
        whichChamber += 1;
    }
    int WhereinChamber = randomChamber(whichChamber);
    theChamber[whichChamber][WhereinChamber]->setCharacter(this->player);
    //theChamber[whichChamber][WhereinChamber]->setSymbol('@');
}

void Grid::setGrid() {
	//set stairway
	//cout << "0" << endl;
	setStairs();
	//potions
	//cout << "1" << endl;
    setPlayer();
    //cout << "2" << endl;
	setPotions();
	//cout << "3" << endl;
	// gold
	setGold();
	// enemies
	//cout << "4" << endl;
	setEnemies();
	//cout << "5" << endl;
}

//Lucus Start 

bool Grid::enemyAttack(Character &c) {
	int status;
	int px = player->getX();
	int py = player->getY();
	int cx = c.getX();
	int cy = c.getY();
	if(px - cx <= 1 && px - cx >= -1 && py - cy <=1 && py - cy >= -1) {
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
	int ns, ew, x, y;
	for(auto &c : characters) {
			// TODO FIX ENEMY ATTACK
		
		if (!enemyAttack(*c) && b) {
			for (int i = 0; i < 6; i++) {
				int randomA = randomNum(1,9);
				ns = 0;
				ew = 0;
				if (randomA == 1){
					ns = 0;
					ew = 1;
				}
				if (randomA == 2){
					ns = 0;
					ew = -1;
				}
				if (randomA == 3){
					ns = 1;
					ew = 0;
				}
				if (randomA == 4){
					ns = 1;
					ew = 1;
				}
				if (randomA == 5){
					ns = 1;
					ew = -1;
				}
				if (randomA == 6){
					ns = -1;
					ew = -1;
				}
				if (randomA== 7){
					ns = -1;
					ew = 0;
				}
				if (randomA == 8){
					ns = -1;
					ew = -1;
				}
				x = c->getX();
				y = c->getY();
					//cout << c->getRace() << endl;
				if(!(theGrid[x+ew][y+ns]->isOccupied()) 
					&& theGrid[x+ew][y+ns]->isWalkable()) break;
					if(i==5) return;	
			}
				// now need to move tile that has corresponding enemy pointer
			theGrid[x][y]->move(ns, ew);

		}
	}
}
		// false means just attack



bool Grid::playerMove(int ew, int ns) {
	if(theGrid[player->getX()+ew][player->getY()+ns]->getSymbol() == 'G') {
		Item* it = theGrid[player->getX()+ew][player->getY()+ns]->getItem();
		Character& c = *player;
		it->alterPlayer(c);
		theGrid[player->getX()+ew][player->getY()+ns]->despawnItem();
		eraseItem(it);
		delete it;
	}
	if(theGrid[player->getX()+ew][player->getY()+ns]->getSymbol() == '\\'){
		theGrid[player->getX()+ew][player->getY()+ns]->setSymbol('.');
		newLevel();
		++level;
		return false;
	}
	if (!theGrid[player->getX()+ew][player->getY()+ns]->isOccupied() 
			&& theGrid[player->getX()+ew][player->getY()+ns]->isWalkable()) {
		theGrid[player->getX()][player->getY()]->move(ns,ew);
		return true;
	} else {
		return false;
	}
}

void Grid::newLevel() {
	for(unsigned int i = 0; i < characters.size(); ++i) {
		theGrid[characters[i]->getX()][characters[i]->getY()]->despawnCharacter();
		delete characters[i];
	}
	characters.clear();
	for(unsigned int i = 0; i < items.size(); ++i) {
		theGrid[items[i]->getX()][items[i]->getY()]->despawnItem();
		delete items[i];
	}
	items.clear();
	theGrid[player->getX()][player->getY()]->despawnCharacter();

	setGrid();
}


//Lucus End
void Grid::eraseItem(Item *it) {
	for (unsigned int i = 0; i < items.size(); i++) {
				if (items[i] == it) {
					items.erase(items.begin() + i);
				}
			}
}

void Grid::playerUsePotion(int ew, int ns) {
	Item* it = theGrid[player->getX()+ew][player->getY()+ns]->getItem();
	if(it == nullptr) {
		return;
	}
	Character &c = *player;
	it->alterPlayer(c);
	//player->addPotion(it);
	//cout << "2";
	theGrid[player->getX()+ew][player->getY()+ns]->despawnItem();
	theGrid[player->getX()+ew][player->getY()+ns]->despawnItem();
	eraseItem(it);
}

char Grid::getSymbol(int ew, int ns) {
	return theGrid[ew][ns]->getSymbol();
}


void Grid::playerAttack(int ns, int ew) {
	if (theGrid[player->getX()+ew][player->getY()+ns]->charSet()){
		Character* c = theGrid[player->getX()+ew][player->getY()+ns]->getCharacter();
		player->attack(c);
		if (c->getHealth() <= 0){
			for (unsigned int i = 0; i < characters.size(); i++) {
				if (characters[i] == c) {
					characters.erase(characters.begin() + i);
				}
			}
			theGrid[player->getX()+ew][player->getY()+ns]->despawnCharacter();
		}
	} else {
		cout << "FAILED" << endl;
		return;
	}
}

Grid::Grid(std::ifstream &i, Player* p) {
    player = p;
	initGrid(i);
}

void Grid::initGrid(std::ifstream &i) {
	char tile;
	int x = 0;
	int y = 0;
	std::vector<Tile *> col;
	theGrid.resize(79, col);

	while (i >> std::noskipws >> tile && x < 80 && y< 25) {
		if (tile == '\n') { 
			x = 0;
			++y;
			continue;
		} else {
			Tile *t;
			if (tile == '.' || tile == '+' || tile == '#') 
				t = new Tile(tile, x, y, true);
			else if (tile == ' ' || tile == '|' || tile == '-'){
				t = new Tile(tile, x, y, false);}
			else {
				std::cout << "Invalid Character -> " << tile << std::endl;
				return;
			}
			t->attach(this);
			theGrid[x].push_back(t);
			++x;

		}
	}
	width = theGrid.size();
	height = theGrid[0].size();
	setObservers();
	setGrid();
}

bool Grid::inGrid(int r, int c) {
	return r >= 0 && c < height && c >= 0 && r < width ; 
}

void Grid::setObservers() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			//If tile is walkable, check each neighbour and if it exists, add to cell Observer list
			if (theGrid[i][j]->getSymbol() == '.' || theGrid[i][j]->getSymbol() == '#' || theGrid[i][j]->getSymbol() == '+') {
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

				if (theGrid[i][j]->getSymbol() == '.')
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
            std::cout << theGrid[j][i]->getSymbol();

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
}

//Start Stephen
void Grid::spawnGold(Character& c) {
	if (c.getRace() == "Merchant"){
		//TODO SPAWN GOLD
	}
}
//End Stephen


