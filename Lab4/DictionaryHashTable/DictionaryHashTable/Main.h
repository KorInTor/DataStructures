#pragma once
#include "Menu.h"

struct Item
{
	char* Key;
	char* Value;
	Item* Next;
};

struct HashTable
{
	Item** Items;
	int Size;
	int Count;
	double LoadFactor = 0;
};