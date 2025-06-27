#ifndef show_h
#define show_h

#include "structures.h"

string SetStringTypeItem(const TypeItem& type);

string SetStringLevel(const Level& level);

void ShowBoard(const Map& map);

void ShowCharactPlayer(const Player& player);

void ShowInventory(const Player& player);

void ShowInventoryItems(const Player& player);

void ShowAllItems(const vector<Item>& items);

void ShowTypeItem();

void ShowAllEnemies(const vector<Enemy>& enemies);

void ShowStats(const Stats& stats);

void ShowStatsGamePlayed(const Stats& stats);

void ShowStatsEnemyKill(const Stats& stats, const vector<Enemy>& enemies);

void ShowStatsItemCollect(const Stats& stats, const vector<Item>& items);

void ShowStatsItemUse(const Stats& stats, const vector<Item>& items);

#endif