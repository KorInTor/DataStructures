#define  _CRT_SECURE_NO_WARNINGS
#include "HashTableItem.h"
#include <cstring>
#include <iostream>

using namespace std;


void HashTableItem::CreateHashTable(int size, HashTable* hashTable)
{
    hashTable->Size = size;
    hashTable->Count = 0;
    hashTable->Items = new Item * [hashTable->Size];

    for (int i = 0; i < hashTable->Size; i++)
    {
        hashTable->Items[i] = nullptr;
    }
}

void HashTableItem::AddRandom(HashTable* hashTable)
{
    int key = rand() % 101;
    int value = rand() % 1001;

    // Преобразование чисел в строки
    string keyStr = to_string(key);
    string valueStr = to_string(value);

    // Генерация случайных строк
    string randomKey = keyStr + static_cast<char>(rand() % 26 + 97);
    string randomValue = valueStr + static_cast<char>(rand() % 26 + 97);

    if (HashTableItem::Find(randomKey.data(), hashTable) == nullptr)
    {
        Add(randomKey.data(), randomValue.data(), hashTable);
    }
}

int HashTableItem::Hash(const char* key, HashTable* hashTable)
{
    int hash = 0;

    static const unsigned char permutation[256] = {
        // 0-255 shuffled in any (random) order suffices
         98,  6, 85,150, 36, 23,112,164,135,207,169,  5, 26, 64,165,219, //  1
         61, 20, 68, 89,130, 63, 52,102, 24,229,132,245, 80,216,195,115, //  2
         90,168,156,203,177,120,  2,190,188,  7,100,185,174,243,162, 10, //  3
        237, 18,253,225,  8,208,172,244,255,126,101, 79,145,235,228,121, //  4
        123,251, 67,250,161,  0,107, 97,241,111,181, 82,249, 33, 69, 55, //  5
         59,153, 29,  9,213,167, 84, 93, 30, 46, 94, 75,151,114, 73,222, //  6
        197, 96,210, 45, 16,227,248,202, 51,152,252,125, 81,206,215,186, //  7
         39,158,178,187,131,136,  1, 49, 50, 17,141, 91, 47,129, 60, 99, //  8
        154, 35, 86,171,105, 34, 38,200,147, 58, 77,118,173,246, 76,254, //  9
        133,232,196,144,198,124, 53,  4,108, 74,223,234,134,230,157,139, // 10
        189,205,199,128,176, 19,211,236,127,192,231, 70,233, 88,146, 44, // 11
        183,201, 22, 83, 13,214,116,109,159, 32, 95,226,140,220, 57, 12, // 12
        221, 31,209,182,143, 92,149,184,148, 62,113, 65, 37, 27,106,166, // 13
          3, 14,204, 72, 21, 41, 56, 66, 28,193, 40,217, 25, 54,179,117, // 14
        238, 87,240,155,180,170,242,212,191,163, 78,218,137,194,175,110, // 15
         43,119,224, 71,122,142, 42,160,104, 48,247,103, 15, 11,138,239  // 16
    };

    for (int i = 0; key[i] != '\0'; ++i) 
    {
        hash = permutation[(hash ^ key[i]) % 256];
    }

    return hash % hashTable->Size;
}

void HashTableItem::Rehash(HashTable* hashTable)
{
    double growthFactor = 1.5;
    int oldSize = hashTable->Size;
    Item** oldItems = hashTable->Items;
    hashTable->Size = (int)(hashTable->Size*growthFactor);
    hashTable->Count = 0;
    hashTable->Items = new Item * [hashTable->Size];

    for (int i = 0; i < hashTable->Size; i++)
    {
        hashTable->Items[i] = nullptr;
    }

    for (int i = 0; i < oldSize; i++)
    {
        if (oldItems[i] != nullptr)
        {
            Item* item = oldItems[i];

            while (item != nullptr)
            {
                HashTableItem::Add(item->Key, item->Value, hashTable);
                item = item->Next;
            }

            delete oldItems[i];
        }
    }

    delete[] oldItems;
}

void HashTableItem::Add(
    const char* key, const char* value, HashTable* hashTable)
{
    if (key == nullptr || value == nullptr)
    {
        return;
    }

    int index = HashTableItem::Hash(key, hashTable);

    if (hashTable->Items[index] == nullptr)
    {
        hashTable->Items[index] = new Item;
        hashTable->Items[index]->Key = new char[strlen(key) + 1];
        hashTable->Items[index]->Value = new char[strlen(value) + 1];
        hashTable->Items[index]->Next = nullptr;

        strcpy(hashTable->Items[index]->Key, key);
        strcpy(hashTable->Items[index]->Value, value);
        hashTable->Count++;
    }
    else
    {
        HashTableItem::CollisionManager(hashTable,index, key, value);
    }

    double maxLoadFactor = 0.75;
    hashTable->LoadFactor = hashTable->Count / (double)hashTable->Size;

    if (hashTable->LoadFactor > maxLoadFactor && hashTable->Count < 256)
    {
        Rehash(hashTable);
    }
}

void HashTableItem::CollisionManager(HashTable* hashTable, int index,const char* key, const char* value)
{
    Item* currentItem = hashTable->Items[index];

    while (currentItem->Next != nullptr)
    {
        if (strcmp(currentItem->Key, key) == 0)
        {
            delete[] currentItem->Value;
            currentItem->Value = new char[strlen(value) + 1];
            strcpy(currentItem->Value, value);
        }

        currentItem = currentItem->Next;
    }

    if (strcmp(currentItem->Key, key) == 0)
    {
        delete[] currentItem->Value;
        currentItem->Value = new char[strlen(value) + 1];
        strcpy(currentItem->Value, value);
    }

    currentItem->Next = new Item;
    currentItem->Next->Key = new char[strlen(key) + 1];
    currentItem->Next->Value = new char[strlen(value) + 1];
    currentItem->Next->Next = nullptr;

    strcpy(currentItem->Next->Value, value);
    strcpy(currentItem->Next->Key, key);
}

void HashTableItem::Remove(const char* key, HashTable* hashTable)
{
    int index = HashTableItem::Hash(key, hashTable);

    if (hashTable->Items[index] != nullptr)
    {
        Item* currentItem = hashTable->Items[index];

        if (strcmp(currentItem->Key, key) == 0)
        {
            hashTable->Items[index] = currentItem->Next;
            delete currentItem;
        }
        else
        {
            while (currentItem->Next != nullptr)
            {
                if (strcmp(currentItem->Next->Key, key) == 0)
                {
                    Item* temp = currentItem->Next;
                    currentItem->Next = currentItem->Next->Next;
                    delete temp;
                    break;
                }

                currentItem = currentItem->Next;
            }
        }

        hashTable->Count--;
    }
}

void HashTableItem::Delete(HashTable* hashTable)
{
    for (int i = 0; i < hashTable->Size; i++)
    {
        if (hashTable->Items[i] != nullptr)
        {
            Item* currentItem = hashTable->Items[i];

            while (currentItem != nullptr)
            {
                if (currentItem->Next != nullptr)
                {
                    Item* temp = currentItem;
                    currentItem = currentItem->Next;
                    delete temp;
                }
                else
                {
                    delete currentItem;
                    delete hashTable;
                    return;
                }
            }

            delete hashTable;
        }
    }
}

const char* HashTableItem::Find(const char* key, HashTable* hashTable)
{
    int index = HashTableItem::Hash(key, hashTable);

    if (hashTable->Items[index] != nullptr)
    {
        Item* currentItem = hashTable->Items[index];

        while (currentItem != nullptr)
        {
            if (strcmp(currentItem->Key, key) == 0)
            {
                return currentItem->Value;
            }

            currentItem = currentItem->Next;
        }
    }

    return nullptr;
}