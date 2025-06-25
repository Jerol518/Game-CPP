#include <iostream>
using namespace std;

#include <cstdlib>
#include <fstream>
#include <string>

#include "functions.h"
#include "structures.h"


Player player;
Map map;
Parametr parametr;

bool saveGame = false;

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

bool UpCharact(const Item& item) {
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

	if (id != 0) {
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
		item.id = id;
		item.name = name;
		item.type = type;
		item.parametr = parametr;
	}

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

void ShowSettings() {
	int select = true;
	while (true) {
		if (select) {
			cout << "0. Back" << endl;
			cout << "1. Difficulty level (" << SetStringLevel(parametr.level) << ")" << endl;
			cout << "2. Board size (" << map.row << "x" << map.col << ")" << endl;

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

			select = true;
			break;
		default:
			cout << "!";
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

void ShowCharactPlayer() {
	cout << "Hp  : " << player.health << "/" << player.maxHealth << "    Lvl : " << player.levelHp << "/" << player.maxLevel << endl;
	cout << "Dmg : " << player.damage << "/" << player.maxDamage << "    Lvl : " << player.levelDmg << "/" << player.maxLevel << endl;
	cout << "Sp  : " << player.speed << "/" << player.maxSpeed << "    Lvl : " << player.levelSp << "/" << player.maxLevel << endl;
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

void Menu() {
	bool select = true;
	while (true) {
		if (select) {
			cout << "1. New game\n2. Continue\n3. Settings\n4. Quit" << endl;

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
			if (saveGame) {
				StartGame();
			}
			else {
				cout << "No save game" << endl << endl;
			}
			select = true;
			break;
		case 3:
			cout << endl;
			ShowSettings();
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

					SavePlayer();

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
				if (UpCharact(item)) {
					SavePlayer();

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
		if (map.countMove > 10) {
			Enemy enemy = ListEnemies(randNumb - 12);

			enemy.health += parametr.boostHpEnemy;
			enemy.damage += parametr.boostDmgEnemy;
			enemy.speed+= parametr.boostSpEnemy;

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
							if (UpCharact(player.inventory[choice - 1])) {
								RemoveItem(player.inventory[choice - 1]);
								player.quantItems--;

								SavePlayer();

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

			SavePlayer();
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
			ShowBoard();
		}

		if (map.cells[map.point.y][map.point.x]) {
			map.cells[map.point.y][map.point.x] = false;

			SteppedCell();
		
			SaveMap();
			
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
			if (UpCharact(player.inventory[choice - 1])) {
				RemoveItem(player.inventory[choice - 1]);
				player.quantItems--;

				SavePlayer();

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

void NewGame() {
	player.health = 3;
	player.maxHealth = 3;

	player.damage = 1;
	player.maxDamage = 4;

	player.speed = 1;
	player.maxSpeed = 4;

	player.levelHp = 1;
	player.levelDmg = 1;
	player.levelSp = 1;
	player.maxLevel = 4;

	player.quantItems = 0;
	player.sizeInv = 8;
	player.inventory = new Item[player.sizeInv];


	map.countMove = 0;
	map.point.x = rand() % map.row;
	map.point.y = rand() % map.col;

	map.row = parametr.row;
	map.col = parametr.col;
	for (int i = 0; i < map.col; i++) {
		map.cells[i] = new bool[map.row];
		for (int j = 0; j < map.row; j++) {
			map.cells[i][j] = true;
		}
	}

	map.cells[map.point.y][map.point.x] = false;

	SavePlayer();
	SaveMap();
	SaveParametr();

	saveGame = true;

	StartGame();
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

void SavePlayer() {
	ofstream filePlayer("Player.txt");

	if (!filePlayer) {
		cout << "No open file (1.0)\nNo save player" << endl << endl;
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

	textSave += to_string(player.quantItems) + '\n';
	textSave += to_string(player.sizeInv) + '\n';
	for (int i = 0; i < player.sizeInv; i++) {
		textSave += to_string(player.inventory[i].id) + ' ';
	}
	textSave += '\n';


	filePlayer << textSave;
}

void SaveMap() {
	ofstream fileMap("Map.txt");

	if (!fileMap) {
		cout << "No open file (1.1)\nNo save map" << endl << endl;
		return;
	}

	string textSave;

	textSave += to_string(map.countMove) + '\n';
	textSave += to_string(map.point.x) + ' ' + to_string(map.point.y) + '\n';

	textSave += to_string(map.row) + '\n';
	textSave += to_string(map.col) + '\n';
	for (int i = 0; i < map.col; i++) {
		for (int j = 0; j < map.row; j++) {
			textSave += to_string(map.cells[i][j]) + ' ';
		}
		textSave += '\n';
	}

	fileMap << textSave;
}

void SaveParametr() {
	ofstream fileParametr("Parametr.txt");

	if (!fileParametr) {
		cout << "No open file (1.2)\nNo save parametr" << endl << endl;
		return;
	}

	string textSave;

	textSave += to_string(parametr.level) + '\n';

	textSave += to_string(parametr.boostHpEnemy) + '\n';
	textSave += to_string(parametr.boostDmgEnemy) + '\n';
	textSave += to_string(parametr.boostSpEnemy) + '\n';

	textSave += to_string(parametr.row) + '\n';
	textSave += to_string(parametr.col) + '\n';

	fileParametr << textSave;
}

void Load() {
	bool load = true;
	{
		ifstream filePlayer("Player.txt");

		if (!filePlayer) {
			load = false;
		}
		else {
			string textLoad;

			getline(filePlayer, textLoad);
			player.health = stoi(textLoad);
			getline(filePlayer, textLoad);
			player.maxHealth = stoi(textLoad);

			getline(filePlayer, textLoad);
			player.damage = stoi(textLoad);
			getline(filePlayer, textLoad);
			player.maxDamage = stoi(textLoad);

			getline(filePlayer, textLoad);
			player.speed = stoi(textLoad);
			getline(filePlayer, textLoad);
			player.maxSpeed = stoi(textLoad);

			getline(filePlayer, textLoad);
			player.levelHp = stoi(textLoad);
			getline(filePlayer, textLoad);
			player.levelDmg = stoi(textLoad);
			getline(filePlayer, textLoad);
			player.levelSp = stoi(textLoad);
			getline(filePlayer, textLoad);
			player.maxLevel = stoi(textLoad);

			getline(filePlayer, textLoad);
			player.quantItems = stoi(textLoad);
			getline(filePlayer, textLoad);
			player.sizeInv = stoi(textLoad);
			for (int i = 0; i < player.sizeInv; i++) {
				filePlayer >> textLoad;
				player.inventory[i] = ListItems(stoi(textLoad));
			}
		}
	}

	{
		ifstream fileMap("Map.txt");

		if (!fileMap) {
			load = false;
		}
		else {
			string textLoad;

			getline(fileMap, textLoad);
			map.countMove = stoi(textLoad);
			fileMap >> textLoad;
			fileMap.seekg(ios::cur, 1);
			map.point.x = stoi(textLoad);
			getline(fileMap, textLoad);
			map.point.y = stoi(textLoad);

			getline(fileMap, textLoad);
			map.row = stoi(textLoad);
			getline(fileMap, textLoad);
			map.col = stoi(textLoad);
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
		}
	}

	{
		ifstream fileParametr("Parametr.txt");

		if (!fileParametr) {
			load = false;
		}
		else {
			string textLoad;

			getline(fileParametr, textLoad);
			parametr.level = (Level) stoi(textLoad);

			getline(fileParametr, textLoad);
			parametr.boostHpEnemy = stoi(textLoad);
			getline(fileParametr, textLoad);
			parametr.boostDmgEnemy = stoi(textLoad);
			getline(fileParametr, textLoad);
			parametr.boostSpEnemy = stoi(textLoad);

			getline(fileParametr, textLoad);
			parametr.row = stoi(textLoad);
			getline(fileParametr, textLoad);
			parametr.col = stoi(textLoad);
		}
	}

	if (load) {
		saveGame = true;
	}
}

void Delete() {
	delete[] player.inventory;

	for (int i = 0; i < map.col; i++) {
		delete[] map.cells[i];
	}
	delete[] map.cells;
}

void Start() {
	Load();

	Menu();

	Delete();
}

