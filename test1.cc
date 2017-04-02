#include <iostream>
#include <random>

using namespace std;

int randomNum(int low, int high) {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(low,high);
	int rnum = distribution(generator);
	return rnum;
}

int main () {
	for(int j = 0; j < 5; ++j) {
	int i = randomNum(1, 10);
	cout << i << endl;
}
}