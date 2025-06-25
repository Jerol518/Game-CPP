#include "functions.h"
#include "structures.h"

#include <cstdlib>
#include <ctime>

int main() {	
	srand(time(0));

	Player player;
	Map map;

	map.row = 6;
	map.col = 5;

	for (int i = 0; i < map.col; i++) {
		map.cells[i] = new bool[map.row];
		for (int j = 0; j < map.row; j++) {
			map.cells[i][j] = true;
		}
	}

	map.cells[player.point.x][player.point.y] = false;


	Start(player, map);
}