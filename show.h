#ifndef show_h
#define show_h

#include "structures.h"

string SetStringTypeItem(const TypeItem& type);

string SetStringLevel(const Level& level);

void ShowBoard(const Map& map);

void ShowCharactPlayer(const Player& player);

void ShowInventory(const Player& player);

void ShowInventoryItems(const Player& player);

void ShowAllItems(vector<Item> items);

void ShowTypeItem();

void ShowAllEnemies(vector<Enemy> enemies);

#endif