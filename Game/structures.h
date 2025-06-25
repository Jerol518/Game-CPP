#ifndef structures_h
#define structures_h

#include <iostream>
using namespace std;

struct Point {
	int x = 0;
	int y = 0;
};

struct Map {
	int row = 0;
	int col = 0;
	bool** cells = new bool* [col];
};

enum TypeItem {
	None,
	Heal,
	UpHp,
	UpDmg,
	UpSp,
};

struct Item {
	bool full = false;
	string name;
	TypeItem type = None;
	int parametr = 0;
};

struct Player {
	int health = 3;
	int maxHealth = 3;

	int damage = 1;
	int speed = 1;

	int levelHp = 1;
	int levelDmg = 1;
	int levelSp = 1;
	int maxLevel = 4;

	int quantItems = 0;
	int sizeInv = 8;
	Item* inventory = new Item[sizeInv];

	int countMove = 0;

	Point point;
};

struct Enemy {
	string name;

	int health = 0;
	int damage = 0;
	int speed = 0;

	Item item;
};

#endif