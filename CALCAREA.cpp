#include <iostream>
#include <vector>
using namespace std;

int nodes;

class Coord
{
public:
	int x;
	int y;
	double tan;
};

int main() {
	cin >> nodes;
	vector<Coord> polygon;
	while (nodes) {
		Coord temp;
		cin >> temp.x;
		cin >> temp.y;
		polygon.push_back(temp);
	}
	return 0;
}