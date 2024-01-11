#pragma once
#include "HashTableItem.h"
#include "Common.h"
#include "Main.h"
#include <string>

class Menu
{
public:
	static void MenuApp(struct HashTable* hashTable);
private:
	static void PrintDictionary(struct HashTable* hashTable);
	static void PrintMenu();
};