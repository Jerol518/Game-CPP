#ifndef structures_h
#define structures_h

#include <iostream>
using namespace std;

enum TypeItem {
	None,
	Heal,
	UpHp,
	UpDmg,
	UpSp,
};

enum Level {
	easy,
	norm,
	hard,
};

struct Point {
	int x = 0;
	int y = 0;
};

struct Map {
	int row = 7;
	int col = 7;
	int quantCells = row * col - 1;
	bool** cells = new bool* [col];

	int countMove = 0;
	Point point;
};

struct Item {
	int id = 0;
	string name = "Item";
	TypeItem type = None;
	int parametr = 0;
};

struct Cell {
	bool full = false;
	Item item;
};

struct Player {
	int health = 3;
	int maxHealth = 3;

	int damage = 1;
	int maxDamage = 4;

	int speed = 1;
	int maxSpeed = 4;

	int levelHp = 1;
	int levelDmg = 1;
	int levelSp = 1;
	int maxLevel = 4;

	int sizeInv = 8;
	Cell* inventory = new Cell[sizeInv];
};

struct Enemy {
	string name = "Enemy";

	int health = 0;
	int damage = 0;
	int speed = 0;

	Item item;
};

struct Parametr {
	bool saveGame = false;

	Level level = easy;

	int boostHpEnemy = 0;
	int boostDmgEnemy = 0;
	int boostSpEnemy = 0;

	int row = 7;
	int col = 7;


	int health = 3;
	int maxHealth = 3;

	int damage = 1;
	int maxDamage = 4;

	int speed = 1;
	int maxSpeed = 4;

	int levelHp = 1;
	int levelDmg = 1;
	int levelSp = 1;
	int maxLevel = 4;

	int sizeInv = 8;
};

struct BoostEnemy {
	int boostHp = 0;
	int boostDmg = 0;
	int boostSp = 0;
};

#endif