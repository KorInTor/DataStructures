#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::PrintMenu()
{
	cout << endl << "Dictionary menu:" << endl;
	cout << "1) Create" << endl;
	cout << "2) Add" << endl;
	cout << "3) Remove" << endl;
	cout << "4) Find" << endl;
	cout << "5) Delete dictionary" << endl;
	cout << "6) Add Random" << endl;
	cout << "7) Exit" << endl;
}

void Menu::PrintDictionary(HashTable* hashTable)
{
	cout << endl << "Table:" << endl;

    for (int i = 0; i < hashTable->Size; i++)
    {
        if (hashTable->Items[i] != nullptr)
        {
            Item* currentItem = hashTable->Items[i];
            cout << "id: " << i << endl;

            while (currentItem != nullptr)
            {
                cout <<"       " << "[Key: " << currentItem->Key <<
                    "" << " Value: " << currentItem->Value << "]" << endl;
                currentItem = currentItem->Next;
            }

            cout << endl;
        }
		else
		{
			cout << "id: " << i << endl;
			cout << "       " << "[]" << endl;
		}
    }

	cout << endl << "Dictionary:" << endl;
	for (int i = 0; i < hashTable->Size; i++)
	{
		if (hashTable->Items[i] != nullptr)
		{
			Item* currentItem = hashTable->Items[i];
			while (currentItem != nullptr)
			{
				cout << "Key: " << currentItem->Key <<
					"  " << " Value: " << currentItem->Value;
				cout << endl;
				currentItem = currentItem->Next;
			}
		}
	}
}

void Menu::MenuApp(HashTable* hashTable)
{
	bool isDictionaryCreated = false;
	int value = 0;

	while (value != 7)
	{
		PrintMenu();
		cout << endl << "Enter menu item number: ";

		if (Common::AssertInputValue(value))
		{
			switch (value)
			{
			case 1:
			{
				if (isDictionaryCreated)
				{
					cout << endl << "Dictionary already created!" << endl;
					return;
				}
				int minSize = 10;
				int maxSize = 256;
				int size;
				cout << "Enter the size of the dictionary: ";

				if (Common::AssertInputValue(size) &&
					Common::AssertValueInRange(size, maxSize, minSize))
				{
					HashTableItem::CreateHashTable(size, hashTable);
					isDictionaryCreated = true;
				}	
				else
				{
					cout << endl << "Incorrect input, the size must be at least "
						<< minSize << " and not more than "
						<< maxSize << ", go back to the menu!" << endl;
				}
				break;
			}
			case 2:
			{
				if (!isDictionaryCreated)
				{
					cout << endl << "Dictionary doesnt created!" << endl;
					return;
				}
				string key;
				cout << "Enter key: ";
				cin >> key;

				string value;
				cout << "Enter value: ";
				cin >> value;

				if (HashTableItem::Find(key.data(), hashTable) == nullptr)
				{
					HashTableItem::Add(key.data(), value.data(), hashTable);
				}
				else
				{
					cout << endl << "Such an element already exists" << endl;
				}

				break;
			}
			case 3:
			{
				if (isDictionaryCreated)
				{
					string key;
					cout << "Enter key: ";
					cin >> key;

					HashTableItem::Remove(key.data(), hashTable);
				}
				else
				{
					cout << endl << "Dictionary not created!" << endl;
				}

				break;
			}
			case 4:
			{
				if (isDictionaryCreated)
				{
					string key;
					cout << "Enter key: ";
					cin >> key;
					const char* value = 
						HashTableItem::Find(key.data(), hashTable);

					if (value == nullptr)
					{
						cout << endl << "Key not found" << endl;
					}
					else
					{
						cout << "Value: " << value << endl;
					}
				}
				else
				{
					cout << endl << "Dictionary not created!" << endl;
				}

				break;
			}
			case 5:
			{
				if (isDictionaryCreated)
				{
					HashTableItem::Delete(hashTable);
					isDictionaryCreated = false;
				}
				else
				{
					cout << endl << "Dictionary not created!" << endl;
				}

				break;
			}
			case 6:
			{
				if (!isDictionaryCreated)
				{
					cout << endl << "Dictionary not created!" << endl;
					break;
				}
				cout << endl << "How many?" << endl;
				int count;
				if (!Common::AssertInputValue(count))
				{
					cout << endl << "Incorrect value entered, "
						"please try again!" << endl; 
					break;
				}
				for (int i = 0; i<count;i++)
				{
					HashTableItem::AddRandom(hashTable);
				}
				break;
			}
			case 7:
			{
				HashTableItem::Delete(hashTable);
				return;
			}
			default:
			{
				cout << endl << "Incorrect value entered, "
					"please try again!" << endl;
			}
			}
		}
		else
		{
			cout << endl << "Incorrect value entered, "
				"please try again!" << endl;
		}

		if (isDictionaryCreated && value!=1)
		{
			PrintDictionary(hashTable);
		}
	}
}