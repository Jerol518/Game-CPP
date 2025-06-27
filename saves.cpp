#include <iostream>
using namespace std;

#include <fstream>
#include <string>
#include <vector>

#include "structures.h"

Item ListItems(const int id) {
	Item item;

	if (id != 0) {
		string name = "Item";
		TypeItem type = None;
		int parametr = 0;

		switch (id)
		{
		case 1:
			name = "Apple"; type = Heal; parametr = 1;
			break;
		case 2:
			name = "Pear"; type = Heal; parametr = 1;
			break;
		case 3:
			name = "Mushroom"; type = Heal; parametr = 1;
			break;
		case 4:
			name = "PieceOfPie"; type = Heal; parametr = 2;
			break;
		case 5:
			name = "Meat"; type = Heal; parametr = 2;
			break;
		case 6:
			name = "BoxOfFood"; type = Heal; parametr = 3;
			break;
		case 7:
			name = "Flower"; type = UpHp; parametr = 1;
			break;
		case 8:
			name = "Water"; type = UpHp; parametr = 1;
			break;
		case 9:
			name = "Stone"; type = UpDmg; parametr = 1;
			break;
		case 10:
			name = "Branch"; type = UpDmg; parametr = 1;
			break;
		case 11:
			name = "Leaf"; type = UpSp; parametr = 1;
			break;
		case 12:
			name = "Feather"; type = UpSp; parametr = 1;
			break;
		default:
			break;
		}

		item.id = id;
		item.name = name;
		item.type = type;
		item.parametr = parametr;
	}

	return item;
}

Enemy ListEnemies(const int id, vector<Item>& items) {
	Enemy enemy;

	string name = "Enemy";

	int health = 0;
	int damage = 0;
	int speed = 0;

	Item item;

	switch (id)
	{
	case 1:
		name = "Cobra"; health = 2; damage = 4; speed = 4; item = items[10];
		break;
	case 2:
		name = "Boar"; health = 4; damage = 2; speed = 2; item = items[5];
		break;
	case 3:
		name = "Wolf"; health = 3; damage = 3; speed = 3; item = items[11];
		break;
	case 4:
		name = "Tiger"; health = 4; damage = 2; speed = 4; item = items[6];
		break;
	case 5:
		name = "Bear"; health = 4; damage = 4; speed = 1; item = items[5];
		break;
	case 6:
		name = "Hippo"; health = 6; damage = 1; speed = 2; item = items[8];
		break;
	default:
		break;
	}

	enemy.name = name;
	enemy.health = health;
	enemy.damage = damage;
	enemy.speed = speed;
	enemy.item = item;

	return enemy;
}

void SaveItems(vector<Item>& items) {
	ofstream fileItems("Items.txt");

	if (!fileItems) {
		cout << "No open file (1.6)\nNo save items" << endl << endl;
		return;
	}

	string textSave;

	textSave += to_string(items.size()) + '\n';
	for (int i = 0; i < items.size(); i++) {
		textSave += items[i].name + ' ';
		textSave += to_string(items[i].type) + ' ';
		textSave += to_string(items[i].parametr) + ' ';
		textSave += '\n';
	}


	fileItems << textSave;
}

void SaveEnemies(vector<Enemy>& enemies) {
	ofstream fileEnemies("Enemies.txt");

	if (!fileEnemies) {
		cout << "No open file (1.7)\nNo save enemies" << endl << endl;
		return;
	}

	string textSave;

	textSave += to_string(enemies.size()) + '\n';
	for (int i = 0; i < enemies.size(); i++) {
		textSave += enemies[i].name + ' ';
		textSave += to_string(enemies[i].health) + ' ';
		textSave += to_string(enemies[i].damage) + ' ';
		textSave += to_string(enemies[i].speed) + ' ';
		textSave += to_string(enemies[i].item.id) + ' ';
		textSave += '\n';
	}


	fileEnemies << textSave;
}

void SavePlayer(Player& player) {
	ofstream filePlayer("Player.txt");

	if (!filePlayer) {
		cout << "No open file (1.1)\nNo save player" << endl << endl;
		return;
	}

	string textSave;

	textSave += to_string(player.health) + '\n';
	textSave += to_string(player.maxHealth) + '\n';

	textSave += to_string(player.damage) + '\n';
	textSave += to_string(player.maxDamage) + '\n';

	textSave += to_string(player.speed) + '\n';
	textSave += to_string(player.maxSpeed) + '\n';

	textSave += to_string(player.levelHp) + '\n';
	textSave += to_string(player.levelDmg) + '\n';
	textSave += to_string(player.levelSp) + '\n';
	textSave += to_string(player.maxHealth) + '\n';

	textSave += to_string(player.sizeInv) + '\n';
	for (int i = 0; i < player.sizeInv; i++) {
		textSave += to_string(player.inventory[i].item.id) + ' ';
	}
	textSave += '\n';


	filePlayer << textSave;
}

void SaveMap(Map& map) {
	ofstream fileMap("Map.txt");

	if (!fileMap) {
		cout << "No open file (1.2)\nNo save map" << endl << endl;
		return;
	}

	string textSave;

	textSave += to_string(map.row) + '\n';
	textSave += to_string(map.col) + '\n';
	textSave += to_string(map.quantCells) + '\n';
	for (int i = 0; i < map.col; i++) {
		for (int j = 0; j < map.row; j++) {
			textSave += to_string(map.cells[i][j]) + ' ';
		}
		textSave += '\n';
	}

	textSave += to_string(map.countMove) + '\n';
	textSave += to_string(map.point.x) + ' ' + to_string(map.point.y) + '\n';

	fileMap << textSave;
}

void SaveParametr(Parametr& parametr) {
	ofstream fileParametr("Parametr.txt");

	if (!fileParametr) {
		cout << "No open file (1.3)\nNo save parametr" << endl << endl;
		return;
	}

	string textSave;

	textSave += to_string(parametr.saveGame) + '\n';

	textSave += to_string(parametr.level) + '\n';

	textSave += to_string(parametr.boostHpEnemy) + '\n';
	textSave += to_string(parametr.boostDmgEnemy) + '\n';
	textSave += to_string(parametr.boostSpEnemy) + '\n';

	textSave += to_string(parametr.row) + '\n';
	textSave += to_string(parametr.col) + '\n';

	textSave += to_string(parametr.health) + '\n';
	textSave += to_string(parametr.maxHealth) + '\n';

	textSave += to_string(parametr.damage) + '\n';
	textSave += to_string(parametr.maxDamage) + '\n';

	textSave += to_string(parametr.speed) + '\n';
	textSave += to_string(parametr.maxSpeed) + '\n';

	textSave += to_string(parametr.levelHp) + '\n';
	textSave += to_string(parametr.levelDmg) + '\n';
	textSave += to_string(parametr.levelSp) + '\n';
	textSave += to_string(parametr.maxLevel) + '\n';

	textSave += to_string(parametr.sizeInv) + '\n';

	fileParametr << textSave;
}

void SaveStats(Stats& stats) {
	ofstream fileStats("Stats.txt");

	if (!fileStats) {
		cout << "No open file (1.4)\nNo save stats" << endl << endl;
		return;
	}

	string textSave;

	textSave += to_string(stats.countPlay) + '\n';
	textSave += to_string(stats.countWin) + '\n';
	textSave += to_string(stats.countLose) + '\n';

	textSave += to_string(stats.countKillEnemy) + '\n';

	textSave += to_string(stats.countCollectItem) + '\n';
	textSave += to_string(stats.countUseItem) + '\n';

	textSave += to_string(stats.countPassCell) + '\n';
	textSave += to_string(stats.countOpenCell) + '\n';

	textSave += to_string(stats.GamePlayed.size()) + '\n';
	for (int i = 0; i < stats.GamePlayed.size(); i++) {
		textSave += to_string(stats.GamePlayed[i]) + '\n';
	}

	textSave += to_string(stats.EnemyKillCount.size()) + '\n';
	for (int i = 0; i < stats.EnemyKillCount.size(); i++) {
		textSave += to_string(stats.EnemyKillCount[i]) + '\n';
	}

	textSave += to_string(stats.ItemCollectCount.size()) + '\n';
	for (int i = 0; i < stats.ItemCollectCount.size(); i++) {
		textSave += to_string(stats.ItemCollectCount[i]) + '\n';
	}

	textSave += to_string(stats.ItemUseCount.size()) + '\n';
	for (int i = 0; i < stats.ItemUseCount.size(); i++) {
		textSave += to_string(stats.ItemUseCount[i]) + '\n';
	}

	fileStats << textSave;
}

void SaveBoostEnemy(BoostEnemy& boostEnemy) {
	ofstream fileBoostEnemy("BoostEnemy.txt");

	if (!fileBoostEnemy) {
		cout << "No open file (1.5)\nNo save boost enemy" << endl << endl;
		return;
	}

	string textSave;

	textSave += to_string(boostEnemy.boostHp) + '\n';
	textSave += to_string(boostEnemy.boostDmg) + '\n';
	textSave += to_string(boostEnemy.boostSp) + '\n';

	fileBoostEnemy << textSave;
}

void LoadItems(vector<Item>& items) {
	ifstream fileItems("Items.txt");

	if (!fileItems) {
		ofstream fileAddItems("Items.txt");

		if (!fileAddItems) {
			cout << "No open file (2.1)\nNo load items" << endl << endl;
		}

		for (int i = 0; i <= 12; i++) {
			items.push_back(ListItems(i));
		}

		SaveItems(items);
	}
	else {
		string textLoad;

		fileItems >> textLoad;
		const int size = stoi(textLoad);
		for (int i = 0; i < size; i++) {
			Item item;

			item.id = i;
			fileItems >> textLoad;
			item.name = textLoad;
			fileItems >> textLoad;
			item.type = (TypeItem)stoi(textLoad);
			fileItems >> textLoad;
			item.parametr = stoi(textLoad);

			items.push_back(item);
		}
	}
}

void LoadEnemies(vector<Enemy>& enemies, vector<Item>& items) {
	ifstream fileEnemies("Enemies.txt");

	if (!fileEnemies) {
		ofstream fileAddEnemies("Enemies.txt");

		if (!fileAddEnemies) {
			cout << "No open file (2.2)\nNo load enemies" << endl << endl;
		}

		for (int i = 0; i <= 6; i++) {
			enemies.push_back(ListEnemies(i, items));
		}

		SaveEnemies(enemies);
	}
	else {
		string textLoad;

		fileEnemies >> textLoad;
		const int size = stoi(textLoad);
		for (int i = 0; i < size; i++) {
			Enemy enemy;

			enemy.id = i;
			fileEnemies >> textLoad;
			enemy.name = textLoad;
			fileEnemies >> textLoad;
			enemy.health = stoi(textLoad);
			fileEnemies >> textLoad;
			enemy.damage = stoi(textLoad);
			fileEnemies >> textLoad;
			enemy.speed = stoi(textLoad);
			fileEnemies >> textLoad;
			enemy.item = items[stoi(textLoad)];

			enemies.push_back(enemy);
		}
	}
}

void LoadPlayer(Player& player, vector<Item>& items) {
	ifstream filePlayer("Player.txt");

	if (filePlayer) {
		string textLoad;

		filePlayer >> textLoad;
		player.health = stoi(textLoad);
		filePlayer >> textLoad;
		player.maxHealth = stoi(textLoad);

		filePlayer >> textLoad;
		player.damage = stoi(textLoad);
		filePlayer >> textLoad;
		player.maxDamage = stoi(textLoad);

		filePlayer >> textLoad;
		player.speed = stoi(textLoad);
		filePlayer >> textLoad;
		player.maxSpeed = stoi(textLoad);

		filePlayer >> textLoad;
		player.levelHp = stoi(textLoad);
		filePlayer >> textLoad;
		player.levelDmg = stoi(textLoad);
		filePlayer >> textLoad;
		player.levelSp = stoi(textLoad);
		filePlayer >> textLoad;
		player.maxLevel = stoi(textLoad);

		filePlayer >> textLoad;
		player.sizeInv = stoi(textLoad);
		for (int i = 0; i < player.sizeInv; i++) {
			filePlayer >> textLoad;
			if (textLoad != "0") {
				player.inventory[i].full = true;
				player.inventory[i].item = items[stoi(textLoad)];
			}
		}
	}
}

void LoadMap(Map& map) {
	ifstream fileMap("Map.txt");

	if (!fileMap) {
		for (int i = 0; i < map.col; i++) {
			map.cells[i] = new bool[map.row];
			for (int j = 0; j < map.row; j++) {
				map.cells[i][j] = true;
			}
		}

		map.point.x = rand() % map.row;
		map.point.y = rand() % map.col;
		map.cells[map.point.y][map.point.x] = false;
	}
	else {
		string textLoad;

		fileMap >> textLoad;
		map.row = stoi(textLoad);
		fileMap >> textLoad;
		map.col = stoi(textLoad);
		fileMap >> textLoad;
		map.quantCells = stoi(textLoad);
		for (int i = 0; i < map.col; i++) {
			map.cells[i] = new bool[map.row];
			for (int j = 0; j < map.row; j++) {
				fileMap >> textLoad;
				if (textLoad == "1") {
					map.cells[i][j] = true;
				}
				else {
					map.cells[i][j] = false;
				}
			}
		}

		fileMap >> textLoad;
		map.countMove = stoi(textLoad);
		fileMap >> textLoad;
		map.point.x = stoi(textLoad);
		fileMap >> textLoad;
		map.point.y = stoi(textLoad);
	}
}

void LoadParametr(Parametr& parametr) {
	ifstream fileParametr("Parametr.txt");

	if (fileParametr) {
		string textLoad;

		fileParametr >> textLoad;
		parametr.saveGame = stoi(textLoad);

		fileParametr >> textLoad;
		parametr.level = (Level)stoi(textLoad);

		fileParametr >> textLoad;
		parametr.boostHpEnemy = stoi(textLoad);
		fileParametr >> textLoad;
		parametr.boostDmgEnemy = stoi(textLoad);
		fileParametr >> textLoad;
		parametr.boostSpEnemy = stoi(textLoad);

		fileParametr >> textLoad;
		parametr.row = stoi(textLoad);
		fileParametr >> textLoad;
		parametr.col = stoi(textLoad);


		fileParametr >> textLoad;
		parametr.health = stoi(textLoad);
		fileParametr >> textLoad;
		parametr.maxHealth = stoi(textLoad);

		fileParametr >> textLoad;
		parametr.damage = stoi(textLoad);
		fileParametr >> textLoad;
		parametr.maxDamage = stoi(textLoad);

		fileParametr >> textLoad;
		parametr.speed = stoi(textLoad);
		fileParametr >> textLoad;
		parametr.maxSpeed = stoi(textLoad);

		fileParametr >> textLoad;
		parametr.levelHp = stoi(textLoad);
		fileParametr >> textLoad;
		parametr.levelDmg = stoi(textLoad);
		fileParametr >> textLoad;
		parametr.levelSp = stoi(textLoad);
		fileParametr >> textLoad;
		parametr.maxLevel = stoi(textLoad);

		fileParametr >> textLoad;
		parametr.sizeInv = stoi(textLoad);
	}
}

void LoadStats(Stats& stats, vector<Item>& items, vector<Enemy>& enemies) {
	ifstream fileStats("Stats.txt");

	if (!fileStats) {
		ofstream fileAddStats("Stats.txt");

		if (!fileAddStats) {
			cout << "No open file (2.3)\nNo load stats" << endl << endl;
		}

		stats.GamePlayed.push_back(0);

		for (int i = 0; i < enemies.size(); i++) {
			stats.EnemyKillCount.push_back(0);
		}

		for (int i = 0; i < items.size(); i++) {
			stats.ItemCollectCount.push_back(0);
		}

		for (int i = 0; i < items.size(); i++) {
			stats.ItemUseCount.push_back(0);
		}

		SaveStats(stats);
	}
	else {
		string textLoad;

		fileStats >> textLoad;
		stats.countPlay = stoi(textLoad);
		fileStats >> textLoad;
		stats.countWin = stoi(textLoad);
		fileStats >> textLoad;
		stats.countLose = stoi(textLoad);

		fileStats >> textLoad;
		stats.countKillEnemy = stoi(textLoad);

		fileStats >> textLoad;
		stats.countCollectItem = stoi(textLoad);
		fileStats >> textLoad;
		stats.countUseItem = stoi(textLoad);

		fileStats >> textLoad;
		stats.countPassCell = stoi(textLoad);
		fileStats >> textLoad;
		stats.countOpenCell = stoi(textLoad);

		fileStats >> textLoad;
		int sizeGamePlayed = stoi(textLoad);
		stats.GamePlayed.push_back(0);
		for (int i = 0; i < sizeGamePlayed; i++) {
			fileStats >> textLoad;
			stats.GamePlayed.push_back(stoi(textLoad));
		}

		fileStats >> textLoad;
		int sizeEnemyKillCount = stoi(textLoad);
		for (int i = 0; i < sizeEnemyKillCount; i++) {
			fileStats >> textLoad;
			stats.EnemyKillCount.push_back(stoi(textLoad));
		}

		fileStats >> textLoad;
		int sizeItemCollectCount = stoi(textLoad);
		for (int i = 0; i < sizeItemCollectCount; i++) {
			fileStats >> textLoad;
			stats.ItemCollectCount.push_back(stoi(textLoad));
		}

		fileStats >> textLoad;
		int sizeItemUseCount = stoi(textLoad);
		for (int i = 0; i < sizeItemUseCount; i++) {
			fileStats >> textLoad;
			stats.ItemUseCount.push_back(stoi(textLoad));
		}
	}
}

void LoadBoostEnemy(BoostEnemy& boostEnemy) {
	ifstream fileBoostEnemy("BoostEnemy.txt");

	if (fileBoostEnemy) {
		string textLoad;

		fileBoostEnemy >> textLoad;
		boostEnemy.boostHp = stoi(textLoad);
		fileBoostEnemy >> textLoad;
		boostEnemy.boostDmg = stoi(textLoad);
		fileBoostEnemy >> textLoad;
		boostEnemy.boostSp = stoi(textLoad);
	}
}

void Load(vector<Item>& items, vector<Enemy>& enemies, Player& player, Map& map, Parametr& parametr, Stats& stats, BoostEnemy& boostEnemy) {
	LoadItems(items);

	LoadEnemies(enemies, items);

	LoadPlayer(player, items);

	LoadMap(map);

	LoadParametr(parametr);

	LoadStats(stats, items, enemies);

	LoadBoostEnemy(boostEnemy);
}

void Delete(Player& player, Map& map) {
	delete[] player.inventory;

	for (int i = 0; i < map.col; i++) {
		delete[] map.cells[i];
	}
	delete[] map.cells;
}