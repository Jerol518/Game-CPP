#include <iostream>
using namespace std;

#include <cstdlib>

#include "functions.h"
#include "structures.h"


Player player;
Map map;

string SetStringTypeItem(const TypeItem& type) {
	switch (type)
	{
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

bool UpParametr(const Item& item) {
	if (item.full) {
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
	}

	return false;
}

Item ListItems(const int id) {
	Item item;

	string name;
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
		name = "Piece of pie"; type = Heal; parametr = 2;
		break;
	case 5:
		name = "Meat"; type = Heal; parametr = 2;
		break;
	case 6:
		name = "Box of food"; type = Heal; parametr = 3;
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

	item.full = true;
	item.name = name;
	item.type = type;
	item.parametr = parametr;

	return item;
}

Enemy ListEnemies(const int id) {
	Enemy enemy;

	string name;

	int health = 0;
	int damage = 0;
	int speed = 0;

	Item item;

	switch (id)
	{
	case 1:
		name = "Cobra"; health = 2; damage = 4; speed = 4; item = ListItems(10);
		break;
	case 2:
		name = "Boar"; health = 4; damage = 2; speed = 2; item = ListItems(5);
		break;
	case 3:
		name = "Wolf"; health = 3; damage = 3; speed = 3; item = ListItems(11);
		break;
	case 4:
		name = "Tiger"; health = 4; damage = 2; speed = 4; item = ListItems(6);
		break;
	case 5:
		name = "Bear"; health = 4; damage = 4; speed = 1; item = ListItems(5);
		break;
	case 6:
		name = "Hippo"; health = 6; damage = 1; speed = 2; item = ListItems(8);
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

void SetItem(Item& item, const string& name, const TypeItem& type, const int& param) {
	item.full = true;
	item.name = name;
	item.type = type;
	item.parametr = param;
}

void RemoveItem(Item& item) {
	item.full = false;
	item.name = "";
	item.type = None;
	item.parametr = 0;
}

void AddItem(const Item& item) {
	for (int i = 0; i < player.sizeInv; i++) {
		if (player.inventory[i].full == false) {
			SetItem(player.inventory[i], item.name, item.type, item.parametr);
			break;
		}
	}
}

void ShowMenu() {
	cout << "1. New game\n2. Continue\n3. Settings\n4. Quit" << endl;

	while (true) {
		int choice;
		cout << " : ";
		cin >> choice;

		if (choice == 4) {
			break;
		}

		bool select = false;
		switch (choice)
		{
		case 1:
			cout << endl;
			StartGame();
			select = true;
			break;
		case 2:
			cout << endl;
			break;
		case 3:
			cout << endl;
			break;
		default:
			cout << "!";
			break;
		}

		if (select) {
			break;
		}
	}
}

void ShowBoard() {
	for (int i = 0; i < map.col; i++) {
		for (int j = 0; j < map.row; j++) {
			cout << "----";
		}
		cout << "-" << endl;

		for (int j = 0; j < map.row; j++) {
			if (player.point.x == j && player.point.y == i) {
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

void ShowCharactPlayer() {
	cout << "Hp  : " << player.health << "/" << player.maxHealth << "    Lvl : " << player.levelHp << "/" << player.maxLevel << endl;
	cout << "Dmg : " << player.damage << "      Lvl : " << player.levelDmg << "/" << player.maxLevel << endl;
	cout << "Sp  : " << player.speed << "      Lvl : " << player.levelSp << "/" << player.maxLevel << endl;
	cout << endl;
}

void ShowInventory() {
	ShowCharactPlayer();

	cout << "0. Back" << endl;
	for (int i = 0; i < player.sizeInv; i++) {
		if (player.inventory[i].full) {
			cout << i + 1 << " - " << player.inventory[i].name << " (" << SetStringTypeItem(player.inventory[i].type) << " +" << player.inventory[i].parametr << ")" << endl;
		}
		else {
			cout << i + 1 << endl;
		}
	}
}

void ShowItems() {
	for (int i = 0; i < player.sizeInv; i++) {
		if (player.inventory[i].full) {
			cout << i + 1 << " - " << player.inventory[i].name << " (" << SetStringTypeItem(player.inventory[i].type) << " +" << player.inventory[i].parametr << ")" << endl;
		}
		else {
			cout << i + 1 << endl;
		}
	}
	cout << endl;
}

void SteppedCell() {
	player.countMove++;

	int randNumb = 1 + rand() % 24;

	if (randNumb >= 1 && randNumb <= 12) {
		Item item = ListItems(randNumb);
		
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
				if (player.quantItems < player.sizeInv) {
					AddItem(item);

					player.quantItems++;

					cout << endl << "Collected" << endl << endl;

					ShowItems();
					
					back = true;
				}
				else {
					cout << endl << "Inventory full" << endl << endl;
				}
				break;
			case 2:
				cout << endl;
				if (UpParametr(item)) {
					ShowCharactPlayer();

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
	else if (randNumb >= 13 && randNumb <= 18) {
		if (player.countMove > 10) {
			Enemy enemy = ListEnemies(randNumb - 12);

			cout << "You are under attack " << enemy.name << "!" << endl << endl;

			while (true) {
				cout << "- Enemy" << endl;
				cout << "Health : " << enemy.health << endl;
				cout << "Damage : " << enemy.damage << endl;
				cout << "Speed : " << enemy.speed << endl << endl;

				cout << "- Player" << endl;
				cout << "Health : " << player.health << endl;
				cout << "Damage : " << player.damage << endl;
				cout << "Speed : " << player.speed << endl << endl;

				int choice;
				cout << "1. Attack " << player.damage * 25 << "%" << endl;
				cout << "2. Run " << (player.speed - (enemy.speed - 1) > 0 ? player.speed - (enemy.speed - 1) : 0) * 25 << "%" << endl;
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
							AddItem(enemy.item);

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
					ShowInventory();

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
						if (choice >= 1 && choice <= 8) {
							cout << endl;
							if (UpParametr(player.inventory[choice - 1])) {
								RemoveItem(player.inventory[choice - 1]);

								player.quantItems--;

								ShowCharactPlayer();

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
	ShowBoard();
	
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
			if (player.point.x - 1 >= 0) {
				player.point.x -= 1;
				move = true;

				cout << endl;
			}
			else {
				cout << "?";
			}
			break;
		case 2:
			if (player.point.y - 1 >= 0) {
				player.point.y -= 1;
				move = true;

				cout << endl;
			}
			else {
				cout << "?";
			}
			break;
		case 3:
			if (player.point.x + 1 < map.row) {
				player.point.x += 1;
				move = true;

				cout << endl;
			}
			else {
				cout << "?";
			}
			break;
		case 4:
			if (player.point.y + 1 < map.col) {
				player.point.y += 1;
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
			ShowBoard();
		}

		if (map.cells[player.point.y][player.point.x]) {
			map.cells[player.point.y][player.point.x] = false;

			SteppedCell();
			ShowBoard();
		}
	}
}

void Inventory() {
	ShowInventory();
	
	while (true) {
		int choice;
		cout << " : ";
		cin >> choice;

		if (choice == 0) {
			cout << endl;
			break;
		}

		if (choice >= 1 && choice <= 8) {
			cout << endl;
			if (UpParametr(player.inventory[choice - 1])) {
				RemoveItem(player.inventory[choice - 1]);

				player.quantItems--;

				ShowInventory();
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

void Start(Player& getPlayer, Map& getMap) {	
	player = getPlayer;
	map = getMap;

	ShowMenu();
}

void StartGame() {
	bool select = true;
	while (true) {
		if (select) {
			ShowBoard();
			
			cout << "1. Move\n2. Inventory\n3. Exit" << endl;
			select = false;
		}
		
		int choice;
		cout << " : ";
		cin >> choice;

		if (choice == 3) {
			cout << endl;
			ShowMenu();
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
	}
}

