#ifndef functions_h
#define functions_h

#include <iostream>
using namespace std;

#include "structures.h"

bool UpParametr(const Item& item);

Item ListItems(const int id);

Enemy ListEnemies(const int id);

void SetItem(Item& item, const string& name, const TypeItem& type, const int& param);

void RemoveItem(Item& item);

void AddItem(const Item& item);

void Start(Player& getPlayer, Map& getMap);

void StartGame();

#endif