#ifndef saves_h
#define saves_h

#include "structures.h"

Item ListItems(const int id);

Enemy ListEnemies(const int id, vector<Item>& items);

void SaveItems(vector<Item>& items);

void SaveEnemies(vector<Enemy>& enemies);

void SavePlayer(Player& player);

void SaveMap(Map& map);

void SaveParametr(Parametr& parametr);

void SaveStats(Stats& stats);

void SaveBoostEnemy(BoostEnemy& boostEnemy);

void LoadItems(vector<Item>& items);

void LoadEnemies(vector<Enemy>& enemies, vector<Item>& items);

void LoadPlayer(Player& player, vector<Item>& items);

void LoadMap(Map& map);

void LoadParametr(Parametr& parametr);

void LoadStats(Stats& stats, vector<Item>& items, vector<Enemy>& enemies);

void LoadBoostEnemy(BoostEnemy& boostEnemy);

void Load(vector<Item>& items, vector<Enemy>& enemies, Player& player, Map& map, Parametr& parametr, Stats& stats, BoostEnemy& boostEnemy);

void Delete(Player& player, Map& map);

#endif