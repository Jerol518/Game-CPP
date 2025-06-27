#include <iostream>
using namespace std;

#include <vector>

#include "structures.h"

string SetStringTypeItem(const TypeItem& type) {
	switch (type)
	{
	case None:
		return "No type";
	case Heal:
		return "Healing";
	case UpHp:
		return "Up health";
	case UpDmg:
		return "Up damage";
	case UpSp:
		return "Up speed";
	default:
		break;
	}
}

string SetStringLevel(const Level& level) {
	switch (level)
	{
	case easy:
		return "Easy";
	case norm:
		return "Normal";
	case hard:
		return "Hard";
	default:
		break;
	}
}

void ShowBoard(const Map& map) {
	for (int i = 0; i < map.col; i++) {
		for (int j = 0; j < map.row; j++) {
			cout << "----";
		}
		cout << "-" << endl;

		for (int j = 0; j < map.row; j++) {
			if (map.point.x == j && map.point.y == i) {
				cout << "| X ";
			}
			else if (map.cells[i][j]) {
				cout << "| ? ";
			}
			else {
				cout << "|   ";
			}
		}
		cout << "|" << endl;
	}

	for (int j = 0; j < map.row; j++) {
		cout << "----";
	}
	cout << "-" << endl << endl;
}

void ShowCharactPlayer(const Player& player) {
	cout << "Hp  : " << player.health << "/" << player.maxHealth << "    Lvl : " << player.levelHp << "/" << player.maxLevel << endl;
	cout << "Dmg : " << player.damage << "/" << player.maxDamage << "    Lvl : " << player.levelDmg << "/" << player.maxLevel << endl;
	cout << "Sp  : " << player.speed << "/" << player.maxSpeed << "    Lvl : " << player.levelSp << "/" << player.maxLevel << endl;
	cout << endl;
}

void ShowInventory(const Player& player) {
	ShowCharactPlayer(player);

	cout << "0. Back" << endl;
	for (int i = 0; i < player.sizeInv; i++) {
		if (player.inventory[i].full) {
			cout << i + 1 << " - " << player.inventory[i].item.name << " (" << SetStringTypeItem(player.inventory[i].item.type) << " +" << player.inventory[i].item.parametr << ")" << endl;
		}
		else {
			cout << i + 1 << endl;
		}
	}
}

void ShowInventoryItems(const Player& player) {
	for (int i = 0; i < player.sizeInv; i++) {
		if (player.inventory[i].full) {
			cout << i + 1 << " - " << player.inventory[i].item.name << " (" << SetStringTypeItem(player.inventory[i].item.type) << " +" << player.inventory[i].item.parametr << ")" << endl;
		}
		else {
			cout << i + 1 << endl;
		}
	}
	cout << endl;
}

void ShowAllItems(vector<Item> items) {
	for (int i = 1; i < items.size(); i++) {
		cout << i << " - " << items[i].name << endl;
	}
	cout << endl;
}

void ShowTypeItem() {
	cout << "1. Healing\n2. Up health\n3. Up damage\n4. Up speed" << endl;
}

void ShowAllEnemies(vector<Enemy> enemies) {
	for (int i = 1; i < enemies.size(); i++) {
		cout << i << " - " << enemies[i].name << endl;
	}
	cout << endl;
}