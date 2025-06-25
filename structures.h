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
	int countMove = 0;
	Point point;

	int row = 7;
	int col = 7;
	bool** cells = new bool* [col];
};

struct Item {
	bool full = false;
	int id = 0;
	string name;
	TypeItem type = None;
	int parametr = 0;
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

	int quantItems = 0;
	int sizeInv = 8;
	Item* inventory = new Item[sizeInv];
};

struct Enemy {
	string name;

	int health = 0;
	int damage = 0;
	int speed = 0;

	Item item;
};

struct Parametr {
	Level level = easy;

	int boostHpEnemy = 0;
	int boostDmgEnemy = 0;
	int boostSpEnemy = 0;

	int row = 7;
	int col = 7;
};

#endif