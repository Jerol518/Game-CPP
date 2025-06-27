#ifndef saves_h
#define saves_h

#include "structures.h"

Item LoadItems(const int id);

Enemy LoadEnemies(const int id, vector<Item>& items);

void SavePlayer(Player& player);

void SaveMap(Map& map);

void SaveParametr(Parametr& parametr);

void SaveBoostEnemy(BoostEnemy& boostEnemy);

void SaveItems(vector<Item>& items);

void SaveEnemies(vector<Enemy>& enemies);

bool Load(vector<Item>& items, vector<Enemy>& enemies, Player& player, Map& map, Parametr& parametr, BoostEnemy& boostEnemy);

void Delete(Player& player, Map& map);

#endif