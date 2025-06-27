#ifndef functions_h
#define functions_h

#include "structures.h"

bool UpCharact(const Item& item);

void SetInventoryItem(Cell& cell, const Item& item);

void RemoveInventoryItem(Cell& cell);

bool AddInventoryItem(const Item& item);

void AddItem();

void EditItem();

void DeleteItem();

void AddEnemy();

void EditEnemy();

void DeleteEnemy();

void EditPlayer();

void NewGame();

void StartGame();

void Start();

#endif