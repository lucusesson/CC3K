#include "grid.h"

Grid::Grid(std::ifstream &i) {
	initGrid(i);
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
			}
			setChamber(theGrid[i][j], i, j);
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
}

void Grid::setChamber(Tile * t, int r, int c) {
	int chamber = inChamber(r,c);
	theChamber[chamber].push_back(t);
}

SubscriptionType Grid::subType() const {
	return SubscriptionType::All;
}

void Grid::displayGrid() {

	int spacing = 500 / width; //spacing between cells
	int border = spacing / 2;

	xw.fillRectangle(0, 0, 500, 500, 0);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			std::string s (1, theGrid[i][j]->getSymbol());
			xw.drawBigString(i * spacing + border, j * spacing + border, s, 1);
		}
	}
}

void Grid::notify(Info &i) {
	displayGrid();
}
