#include <iostream>
using namespace std;

#include <cstdlib>
#include <vector>

#include "show.h"
#include "saves.h"
#include "structures.h"

#include "functions.h"

Player player;
Map map;
Parametr parametr;
BoostEnemy boostEnemy;

vector<Item> items;
vector<Enemy> enemies;

bool win = false;
bool lose = false;

bool UpCharact(const Item& item) {
	switch (item.type)
	{
	case Heal:
		if (player.health < player.maxHealth) {
			player.health += item.parametr;
			if (player.health > player.maxHealth) {
				player.health = player.maxHealth;
			}

			cout << "Healing" << endl << endl;
			return true;
		}
		else {
			cout << "Health full" << endl << endl;
		}
		break;
	case UpHp:
		if (player.levelHp < player.maxLevel) {
			player.maxHealth += item.parametr;
			player.health += item.parametr;
			player.levelHp++;

			cout << "Up health" << endl << endl;
			return true;
		}
		else {
			cout << "Lvl health max" << endl << endl;
		}
		break;
	case UpDmg:
		if (player.levelDmg < player.maxLevel) {
			player.damage += item.parametr;
			player.levelDmg++;

			cout << "Up damage" << endl << endl;
			return true;
		}
		else {
			cout << "Lvl damage max" << endl << endl;
		}
		break;
	case UpSp:
		if (player.levelSp < player.maxLevel) {
			player.speed += item.parametr;
			player.levelSp++;

			cout << "Up speed" << endl << endl;
			return true;
		}
		else {
			cout << "Lvl speed max" << endl << endl;
		}
		break;
	default:
		return false;
		break;
	}

	return false;
}

void AddItem() {
	Item item;

	cout << "Name" << endl;
	cout << " : ";
	cin >> item.name;
	cout << endl;

	int typeNumb;
	cout << "Type:" << endl;
	ShowTypeItem();
	cout << " : ";
	cin >> typeNumb;
	cout << endl;

	if (typeNumb >= 1 && typeNumb <= 4) {
		item.type = (TypeItem)typeNumb;
	}
	else {
		item.type = Heal;
	}

	cout << "Parametr" << endl;
	cout << " : ";
	cin >> item.parametr;
	cout << endl;

	items.push_back(item);

	SaveItems(items);
}

void EditItem() {
	bool edit = true;
	while (true) {
		if (edit) {
			cout << "0. Back" << endl;
			ShowAllItems(items);
			edit = false;
		}

		int choice;
		cout << " : ";
		cin >> choice;

		if (choice == 0) {
			cout << endl;
			return;
		}

		if (choice >= 1 && choice <= items.size() - 1) {
			cout << endl;

			Item item;

			cout << "Name" << endl;
			cout << " : ";
			cin >> item.name;
			cout << endl;

			int typeNumb;
			cout << "Type:" << endl;
			ShowTypeItem();
			cout << " : ";
			cin >> typeNumb;
			cout << endl;

			if (typeNumb >= 1 && typeNumb <= 4) {
				item.type = (TypeItem)typeNumb;
			}
			else {
				item.type = Heal;
			}

			cout << "Parametr" << endl;
			cout << " : ";
			cin >> item.parametr;
			cout << endl;

			items[choice] = item;

			SaveItems(items);

			edit = true;
		}
		else {
			cout << "!";
		}
	}
}

void DeleteItem() {
	if (items.size() > 1) {
		bool del = true;
		while (true) {
			if (del) {
				cout << "0. Back" << endl;
				ShowAllItems(items);
				del = false;
			}

			int choice;
			cout << " : ";
			cin >> choice;

			if (choice == 0) {
				cout << endl;
				return;
			}

			if (choice >= 1 && choice <= items.size() - 1) {
				cout << endl;

				items.erase(items.begin() + choice);

				SaveItems(items);

				del = true;
			}
			else {
				cout << "!";
			}
		}
	}
	else {
		cout << "Items must be more than 1" << endl << endl;
	}
}

void AddEnemy() {
	Enemy enemy;

	cout << "Name" << endl;
	cout << " : ";
	cin >> enemy.name;
	cout << endl;

	cout << "Health" << endl;
	cout << " : ";
	cin >> enemy.health;
	cout << endl;

	cout << "Damage" << endl;
	cout << " : ";
	cin >> enemy.damage;
	cout << endl;

	cout << "Speed" << endl;
	cout << " : ";
	cin >> enemy.speed;
	cout << endl;

	int indexItem;
	cout << "Drop-down item:" << endl;
	ShowAllItems(items);
	cout << " : ";
	cin >> indexItem;
	cout << endl;

	if (indexItem >= 1 && indexItem <= items.size() - 1) {
		enemy.item = items[indexItem];
	}
	else {
		enemy.item = items[1];
	}

	enemies.push_back(enemy);

	SaveEnemies(enemies);
}

void EditEnemy() {
	bool edit = true;
	while (true) {
		if (edit) {
			cout << "0. Back" << endl;
			ShowAllEnemies(enemies);
			edit = false;
		}

		int choice;
		cout << " : ";
		cin >> choice;

		if (choice == 0) {
			cout << endl;
			return;
		}

		if (choice >= 1 && choice <= enemies.size() - 1) {
			cout << endl;

			Enemy enemy;

			cout << "Name" << endl;
			cout << " : ";
			cin >> enemy.name;
			cout << endl;

			cout << "Health" << endl;
			cout << " : ";
			cin >> enemy.health;
			cout << endl;

			cout << "Damage" << endl;
			cout << " : ";
			cin >> enemy.damage;
			cout << endl;

			cout << "Speed" << endl;
			cout << " : ";
			cin >> enemy.speed;
			cout << endl;

			int indexItem;
			cout << "Drop-down item:" << endl;
			ShowAllItems(items);
			cout << " : ";
			cin >> indexItem;
			cout << endl;

			if (indexItem >= 1 && indexItem <= items.size() - 1) {
				enemy.item = items[indexItem];
			}
			else {
				enemy.item = items[1];
			}

			enemies[choice] = enemy;

			SaveEnemies(enemies);

			edit = true;
		}
		else {
			cout << "!";
		}
	}
}

void DeleteEnemy() {
	if (enemies.size() > 1) {
		bool del = true;
		while (true) {
			if (del) {
				cout << "0. Back" << endl;
				ShowAllEnemies(enemies);
				del = false;
			}

			int choice;
			cout << " : ";
			cin >> choice;

			if (choice == 0) {
				cout << endl;
				return;
			}

			if (choice >= 1 && choice <= enemies.size() - 1) {
				cout << endl;

				enemies.erase(enemies.begin() + choice);

				SaveEnemies(enemies);

				del = true;
			}
			else {
				cout << "!";
			}
		}
	}
	else {
		cout << "Enemies must be more than 1" << endl << endl;
	}
}

void EditPlayer() {
	bool edit = true;
	while (true) {
		if (edit) {
			cout << "0. Back\n1. Edit a player\n2. Reset a player" << endl;
			edit = false;
		}

		int choice;
		cout << " : ";
		cin >> choice;

		if (choice == 0) {
			cout << endl;
			return;
		}

		switch (choice)
		{
		case 1:
			cout << endl;

			cout << "Health" << endl;
			cout << " : ";
			cin >> parametr.health;
			cout << endl;
			cout << "Max health" << endl;
			cout << " : ";
			cin >> parametr.maxHealth;
			cout << endl;

			cout << "Damage" << endl;
			cout << " : ";
			cin >> parametr.damage;
			cout << endl;
			cout << "Max damage" << endl;
			cout << " : ";
			cin >> parametr.maxDamage;
			cout << endl;

			cout << "Speed" << endl;
			cout << " : ";
			cin >> parametr.speed;
			cout << endl;
			cout << "Max speed" << endl;
			cout << " : ";
			cin >> parametr.maxSpeed;
			cout << endl;

			cout << "Level healht" << endl;
			cout << " : ";
			cin >> parametr.levelHp;
			cout << endl;
			cout << "Level damage" << endl;
			cout << " : ";
			cin >> parametr.levelDmg;
			cout << endl;
			cout << "Level speed" << endl;
			cout << " : ";
			cin >> parametr.levelSp;
			cout << endl;
			cout << "Max level" << endl;
			cout << " : ";
			cin >> parametr.maxLevel;
			cout << endl;

			cout << "Size inventory" << endl;
			cout << " : ";
			cin >> parametr.sizeInv;
			cout << endl;

			edit = true;
			break;
		case 2:
			cout << endl;

			parametr.health = 3;
			parametr.maxHealth = 3;

			parametr.damage = 1;
			parametr.maxDamage = 4;

			parametr.speed = 1;
			parametr.maxSpeed = 4;

			parametr.levelHp = 1;
			parametr.levelDmg = 1;
			parametr.levelSp = 1;
			parametr.maxLevel = 4;

			parametr.sizeInv = 8;

			edit = true;
			break;
		default:
			cout << "!";
			break;
		}
	}

	SaveParametr(parametr);
}

void Settings() {
	int select = true;
	while (true) {
		if (select) {
			cout << "0. Back" << endl;
			cout << "1. Difficulty level (" << SetStringLevel(parametr.level) << ") (Only works in a new game)" << endl;
			cout << "2. Board size (" << parametr.row << "x" << parametr.col << ") (Only works in a new game)" << endl;
			cout << "3. Statistics" << endl;
			cout << "4. Edit game" << endl;

			select = false;
		}

		int choice;
		cout << " : ";
		cin >> choice;

		if (choice == 0) {
			cout << endl;
			break;
		}

		switch (choice)
		{
		case 1:
			cout << endl;

			cout << "0. Back\n1. Easy\n2. Normal\n3. Hard" << endl;

			while (true) {
				cout << " : ";
				cin >> choice;

				if (choice == 0) {
					cout << endl;
					break;
				}

				bool selectLevel = false;
				switch (choice)
				{
				case 1:
					cout << endl;

					parametr.level = easy;
					parametr.boostHpEnemy = 0;
					parametr.boostDmgEnemy = 0;
					parametr.boostSpEnemy = 0;

					selectLevel = true;
					break;
				case 2:
					cout << endl;

					parametr.level = norm;
					parametr.boostHpEnemy = 2;
					parametr.boostDmgEnemy = 1;
					parametr.boostSpEnemy = 1;

					selectLevel = true;
					break;
				case 3:
					cout << endl;

					parametr.level = hard;
					parametr.boostHpEnemy = 6;
					parametr.boostDmgEnemy = 3;
					parametr.boostSpEnemy = 3;

					selectLevel = true;
					break;
				default:
					cout << "!";
					break;
				}

				if (selectLevel) {
					break;
				}
			}

			SaveParametr(parametr);

			select = true;
			break;
		case 2:
			cout << endl;

			int row;
			cout << "Enter row size (max 15)" << endl;
			cout << " : ";
			cin >> row;

			if (row > 15) {
				row = 15;
			}
			else if (row < 1) {
				row = 1;
			}

			int col;
			cout << "Enter col size (max 15)" << endl;
			cout << " : ";
			cin >> col;
			cout << endl;

			if (col > 15) {
				col = 15;
			}
			else if (col < 1) {
				col = 1;
			}

			parametr.row = row;
			parametr.col = col;

			SaveParametr(parametr);

			select = true;
			break;
		case 3:
			cout << endl;

			cout << "Number of games played : " << endl;
			cout << "Number of wins : " << endl;
			cout << "Number of lesions : " << endl;
			cout << "Number of enemies defeated : " << endl;
			cout << "Number of items collected : " << endl;
			cout << "Number of items used : " << endl;
			cout << "Number of open cells : " << endl;
			cout << "Number of cells passed : " << endl;
			cout << endl;

			{
				bool showStats = true;
				while (true) {
					if (showStats) {
						cout << "0. Back\n1. Games played\n2. Defeated enemies\n3. Collected items\n4. Items used" << endl;
						showStats = false;
					}

					cout << " : ";
					cin >> choice;

					if (choice == 0) {
						cout << endl;
						break;
					}

					switch (choice)
					{
					case 1:
						cout << endl;

						showStats = true;
						break;
					case 2:
						cout << endl;

						showStats = true;
						break;
					case 3:
						cout << endl;

						showStats = true;
						break;
					case 4:
						cout << endl;

						showStats = true;
						break;
					default:
						cout << "!";
						break;
					}
				}
			}

			select = true;
			break;
		case 4:
			cout << endl;

			{
				bool edit = true;
				while (true) {
					if (edit) {
						cout << "0. Back\n1. Add an item\n2. Edit item\n3. Delete an item\n4. Add an enemy\n5. Edit the enemy\n6. Delete an enemy\n7. Edit a player (Only works in a new game)" << endl;
						edit = false;
					}

					cout << " : ";
					cin >> choice;

					if (choice == 0) {
						cout << endl;
						break;
					}

					switch (choice)
					{
					case 1:
						cout << endl;

						AddItem();

						edit = true;
						break;
					case 2:
						cout << endl;

						EditItem();

						edit = true;
						break;
					case 3:
						cout << endl;

						DeleteItem();

						edit = true;
						break;
					case 4:
						cout << endl;

						AddEnemy();

						edit = true;
						break;
					case 5:
						cout << endl;

						EditEnemy();

						edit = true;
						break;
					case 6:
						cout << endl;

						DeleteEnemy();

						edit = true;
						break;
					case 7:
						cout << endl;

						EditPlayer();

						edit = true;
						break;
					default:
						cout << "!";
						break;
					}
				}
			}

			select = true;
			break;
		default:
			cout << "!";
			break;
		}
	}
}

void Menu() {
	bool select = true;
	while (true) {
		if (select) {
			cout << "1. New game" << endl;
			cout << "2. Continue " << (parametr.saveGame ? "+" : "-") << endl;
			cout << "3. Settings" << endl;
			cout << "4. Quit" << endl;

			select = false;
		}

		int choice;
		cout << " : ";
		cin >> choice;

		if (choice == 4) {
			break;
		}

		switch (choice)
		{
		case 1:
			cout << endl;
			NewGame();
			select = true;
			break;
		case 2:
			cout << endl;
			if (parametr.saveGame) {
				StartGame();
			}
			else {
				cout << "No save game" << endl << endl;
			}
			select = true;
			break;
		case 3:
			cout << endl;
			Settings();
			select = true;
			break;
		default:
			cout << "!";
			break;
		}
	}
}

void SteppedCell() {
	map.countMove++;

	int randNumb = 1 + rand() % 4;

	if (randNumb == 1 || randNumb == 2) {
		Item item = items[1 + rand() % (items.size() - 1)];
		
		cout << "You found the " << item.name << " (" << SetStringTypeItem(item.type) << " +" << item.parametr << ")" << endl << endl;;
		cout << "1. Collect\n2. Use\n3. Drop" << endl;

		while (true) {
			int choice;
			cout << " : ";
			cin >> choice;

			bool back = false;

			switch (choice)
			{
			case 1:
				if (AddInventoryItem(item)) {
					SavePlayer(player);

					cout << endl << "Collected" << endl << endl;

					ShowInventoryItems(player);
					
					back = true;
				}
				else {
					cout << endl << "Inventory full" << endl << endl;
				}
				break;
			case 2:
				cout << endl;
				if (UpCharact(item)) {
					SavePlayer(player);

					ShowCharactPlayer(player);

					back = true;
				}
				break;
			case 3:
				cout << endl << "Dropped" << endl << endl;
				back = true;
				break;
			default:
				cout << "!";
				break;
			}

			if (back == true) {
				break;
			}
		}
	}
	else if (randNumb == 3) {
		if (map.countMove > 10) {
			Enemy enemy = enemies[1 + rand() % (enemies.size() - 1)];

			enemy.health += boostEnemy.boostHp;
			enemy.damage += boostEnemy.boostDmg;
			enemy.speed+= boostEnemy.boostSp;

			cout << "You are under attack " << enemy.name << "!" << endl << endl;

			while (true) {
				cout << "- Enemy" << endl;
				cout << "Health : " << enemy.health << endl;
				cout << "Damage : " << enemy.damage << endl;
				cout << "Speed : " << enemy.speed << endl << endl;

				cout << "- Player" << endl;
				cout << "Health : " << player.health << "/" << player.maxHealth << endl;
				cout << "Damage : " << player.damage << endl;
				cout << "Speed : " << player.speed << endl << endl;

				int choice;
				cout << "1. Attack " << ((float) player.damage / player.maxDamage) * 100 << "%" << endl;
				cout << "2. Run " << ((float) (player.speed - (enemy.speed - 1) > 0 ? player.speed - (enemy.speed - 1) : 0) / player.maxSpeed) * 100 << "%" << endl;
				cout << "3. Use item" << endl;
				cout << " : ";
				cin >> choice;

				bool back = false;
				bool cont = false;

				int randAction = 1 + rand() % 4;
				switch (choice)
				{
				case 1:
					if (randAction <= player.damage) {
						enemy.health--;

						cout << endl << "You attacked!" << endl << endl;

						if (enemy.health <= 0) {
							AddInventoryItem(enemy.item);

							cout << "The enemy was defeated!" << endl << endl;

							back = true;
						}
					}
					else {
						cout << endl << "You missed!" << endl << endl;
					}

					break;
				case 2:
					if (randAction <= player.speed - (enemy.speed - 1)) {
						cout << endl << "You ran away!" << endl << endl;

						back = true;
					}
					else {
						cout << endl << "Failure!" << endl << endl;
					}

					break;
				case 3:
					ShowInventory(player);

					while (true) {
						int choice;
						cout << " : ";
						cin >> choice;

						if (choice == 0) {
							cout << endl;
							cont = true;
							break;
						}

						bool backInv = false;
						if (choice >= 1 && choice <= player.sizeInv) {
							cout << endl;
							if (player.inventory[choice - 1].full && UpCharact(player.inventory[choice - 1].item)) {
								RemoveInventoryItem(player.inventory[choice - 1]);

								SavePlayer(player);

								ShowCharactPlayer(player);

								backInv = true;
							}
							else {
								cout << "Cell is empty" << endl << endl;
							}
						}
						else {
							cout << "!";
						}

						if (backInv) {
							break;
						}
					}

					break;
				default:
					cout << "!";
					break;
				}

				if (cont) {
					continue;
				}

				if (back) {
					break;
				}

				int randActionEnemy = 1 + rand() % 4;

				if (randActionEnemy <= enemy.damage) {
					player.health--;

					cout << "The enemy attacked!" << endl << endl;

					if (player.health <= 0) {
						cout << "You were defeated!" << endl << endl;

						lose = true;
						back = true;
					}
				}
				else {
					cout << "The enemy missed!" << endl << endl;
				}

				if (back) {
					break;
				}
			}

			SavePlayer(player);
		}
		else {
			cout << "Nothing found" << endl << endl;
		}
	}
	else {
		cout << "Nothing found" << endl << endl;
	}
}


void Move() {
	ShowBoard(map);
	
	bool move = true;
	while (true) {
		if (move) {
			cout << "0. Back\n1. Left\n2. Up\n3. Right\n4. Down" << endl;
			move = false;
		}

		int choice;
		cout << " : ";
		cin >> choice;

		if (choice == 0) {
			cout << endl;

			break;
		}

		switch (choice)
		{
		case 1:
			if (map.point.x - 1 >= 0) {
				map.point.x -= 1;
				move = true;

				cout << endl;
			}
			else {
				cout << "?";
			}
			break;
		case 2:
			if (map.point.y - 1 >= 0) {
				map.point.y -= 1;
				move = true;

				cout << endl;
			}
			else {
				cout << "?";
			}
			break;
		case 3:
			if (map.point.x + 1 < map.row) {
				map.point.x += 1;
				move = true;

				cout << endl;
			}
			else {
				cout << "?";
			}
			break;
		case 4:
			if (map.point.y + 1 < map.col) {
				map.point.y += 1;
				move = true;

				cout << endl;
			}
			else {
				cout << "?";
			}
			break;
		default:
			cout << "!";
			break;
		}

		if (move) {
			ShowBoard(map);
		}

		if (map.cells[map.point.y][map.point.x]) {
			SteppedCell();
		
			if (!lose) { 
				map.cells[map.point.y][map.point.x] = false;
				map.quantCells--;

				ShowBoard(map); 
			}
			
			SaveMap(map);

			if (map.quantCells <= 0 && !lose) {
				win = true;
			}

			if (win || lose) {
				break;
			}
		}
	}
}

void SetInventoryItem(Cell& cell, const Item& item) {
	cell.full = true;
	cell.item.id = item.id;
	cell.item.name = item.name;
	cell.item.type = item.type;
	cell.item.parametr = item.parametr;
}

void RemoveInventoryItem(Cell& cell) {
	cell.full = false;
	cell.item.name = "";
	cell.item.type = None;
	cell.item.parametr = 0;
}

bool AddInventoryItem(const Item& item) {
	for (int i = 0; i < player.sizeInv; i++) {
		if (player.inventory[i].full == false) {
			SetInventoryItem(player.inventory[i], item);
			return true;
		}
	}
	return false;
}

void Inventory() {
	ShowInventory(player);
	
	while (true) {
		int choice;
		cout << " : ";
		cin >> choice;

		if (choice == 0) {
			cout << endl;
			break;
		}

		if (choice >= 1 && choice <= player.sizeInv) {
			cout << endl;
			if (player.inventory[choice - 1].full && UpCharact(player.inventory[choice - 1].item)) {
				RemoveInventoryItem(player.inventory[choice - 1]);

				SavePlayer(player);

				ShowInventory(player);
			}
			else {
				cout << "Cell is empty" << endl << endl;
			}
		}
		else {
			cout << "!";
		}
	}
}

void NewGame() {
	if (parametr.saveGame) {
		cout << "Your past game will be deleted. Are you sure?" << endl;
		cout << "0. Back\n1. Create a new game" << endl;

		bool back = false;
		while (true) {
			int choice;
			cout << " : ";
			cin >> choice;

			if (choice == 0) {
				back = true;
				break;
			}
			else if (choice == 1) {
				break;
			}
			else {
				cout << "!";
			}
		}

		cout << endl;
		if (back) {
			return;
		}
	}

	player.health = parametr.health;
	player.maxHealth = parametr.maxHealth;

	player.damage = parametr.damage;
	player.maxDamage = parametr.maxDamage;

	player.speed = parametr.speed;
	player.maxSpeed = parametr.maxSpeed;

	player.levelHp = parametr.levelHp;
	player.levelDmg = parametr.levelDmg;
	player.levelSp = parametr.levelSp;
	player.maxLevel = parametr.maxLevel;

	player.sizeInv = parametr.sizeInv;
	player.inventory = new Cell[player.sizeInv];


	map.row = parametr.row;
	map.col = parametr.col;
	map.quantCells = map.row * map.col - 1;
	for (int i = 0; i < map.col; i++) {
		map.cells[i] = new bool[map.row];
		for (int j = 0; j < map.row; j++) {
			map.cells[i][j] = true;
		}
	}

	map.countMove = 0;
	map.point.x = rand() % map.row;
	map.point.y = rand() % map.col;
	map.cells[map.point.y][map.point.x] = false;

	boostEnemy.boostHp = parametr.boostHpEnemy;
	boostEnemy.boostDmg = parametr.boostDmgEnemy;
	boostEnemy.boostSp = parametr.boostSpEnemy;

	parametr.saveGame = true;

	SavePlayer(player);
	SaveMap(map);
	SaveParametr(parametr);
	SaveBoostEnemy(boostEnemy);

	StartGame();
}

void StartGame() {
	bool select = true;
	while (true) {
		if (select) {
			ShowBoard(map);
			
			cout << "1. Move\n2. Inventory\n3. Exit" << endl;
			select = false;
		}
		
		int choice;
		cout << " : ";
		cin >> choice;

		if (choice == 3) {
			cout << endl;
			break;
		}

		switch (choice)
		{
		case 1:
			cout << endl;
			Move();
			select = true;
			break;
		case 2:
			cout << endl;
			Inventory();
			select = true;
			break;
		default:
			cout << "!";
			break;
		}

		if (win) {
			cout << "You win! :)" << endl << endl;


			win = false;
			parametr.saveGame = false;

			SaveParametr(parametr);
			break;
		}
		else if (lose) {
			cout << "You lose :(" << endl << endl;

			lose = false;
			parametr.saveGame = false;

			SaveParametr(parametr);
			break;
		}
	}
}

void Start() {
	if (Load(items, enemies, player, map, parametr, boostEnemy)) {

		Menu();

		Delete(player, map);
	}
}

