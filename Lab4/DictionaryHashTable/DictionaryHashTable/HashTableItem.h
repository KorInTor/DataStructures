#pragma once
#include "Main.h"

class HashTableItem
{
public:
	static int Hash(const char* key, struct HashTable* hashTable);
	static void CreateHashTable(int size, struct HashTable* hashTable);
	static void AddRandom(HashTable* hashTable);
	static void Add(const char* key, const char* value, struct HashTable* hashTable);
	static void Rehash(struct HashTable* hashTable);
	static void Remove(const char* key, struct HashTable* hashTable);
	static const char* Find(const char* key, struct HashTable* hashTable);
	static void Delete(struct HashTable* hashTable);
private:
	static void CollisionManager(HashTable* hashTable,int index, const char* key, const char* value);
};