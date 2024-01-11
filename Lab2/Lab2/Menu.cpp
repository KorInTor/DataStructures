#include "Menu.h"
#include <iostream>
#include <chrono>

using namespace std;

const string errorValueText = "Inccorect value, returning to menu";
const string listNotExistText = "List doesnt exists, you need to create one, returning to menu";
const string outOfRangeText = "Index is out of range, returning to menu";
const string noElementText = "No such element in list, returning to menu";
const string tryAgainText = "Incorected value, try again";

void Menu::PrintMenu()
{
	cout << endl << "Menu:" << endl;
	cout << "1) Create Random Two Linked List" << endl;
	cout << "2) Create Custom Two Linked List" << endl;
	cout << "3) Add Element to Head of the List" << endl;
	cout << "4) Add Element to Tail of the List" << endl;
	cout << "5) Add after a certain element" << endl;
	cout << "6) Add before a certain element" << endl;
	cout << "7) Remove Element From List" << endl;
	cout << "8) List Sort" << endl;
	cout << "9) Linear search for element in list" << endl;
	cout << "10) Exit" << endl;
	cout << "Enter menu item number: ";
}

void Menu::PrintList(List* list)
{
	cout << "List:" << endl;
	Node* currentNode = list->Head;

	do 
	{
		cout << currentNode->Data << " ";
		currentNode = currentNode->Next;
	} while (currentNode != nullptr);

	cout << endl;
}

void Menu::CaseCreate(List* list, std::string option)
{
	int size;
	cout << endl << "Enter size of List: ";
	if (!Common::AssertInputValue(size))
	{
		cout << endl << errorValueText << endl;
		return;
	}
	if (option == "random")
	{
		ListItem::CreateRandomListItems(list, size);
	}
	else if(option == "custom")
	{
		int count = 1;
		int data;
		cout << endl << "Enter element you want to add to list: ";
		if (!Common::AssertInputValue(data))
		{
			cout << endl << tryAgainText << endl;
		}
		ListItem::CreateCustomListItems(list,data);
		while (count != size)
		{
			cout << endl << "Enter element you want to add to list: ";
			if (!Common::AssertInputValue(data))
			{
				cout << endl << tryAgainText << endl;
			}
			list->Tail = ListItem::AddAtTail(list, data);
			count++;
		}
	}
	PrintList(list);
}

void Menu::CaseAdd(List* list, std::string option)
{
	cout << endl << "Old ";
	PrintList(list);
	int data;
	cout << endl << "Enter element you want to add: ";
	if (!Common::AssertInputValue(data))
	{
		cout << endl << errorValueText << endl;
		return;
	}
	if (option == "head")
	{
		list->Head = ListItem::AddAtHead(list, data);
		cout << endl << "New ";
		PrintList(list);
		return;
	}
	else if (option == "tail")
	{
		list->Tail = ListItem::AddAtTail(list, data);
		cout << endl << "New ";
		PrintList(list);
		return;
	}
	/*int index;

	cout << endl << "Enter element index "<< option <<" you want to add: ";
	if (!Common::AssertInputValue(index))
	{
		cout << endl << errorValueText << endl;
		return;
	}*/

	cout << endl << "Old ";
	PrintList(list);
	/*if (option == "before")
	{
		Node* findNode = ListItem::SearchElement(list, index);

		ListItem::AddBefore(list, findNode, data);
	}
	if (option == "after")
	{
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		Node* findNode = ListItem::SearchElement(list, index);

		ListItem::AddAfter(list, findNode, data);

		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		cout << "Time difference (sec) = " << (chrono::duration_cast<chrono::
			microseconds>(end - begin).count()) / 1000000.0 << endl;
	}*/
	// конец обращятеля по индексу
	int findData;
	cout << endl << "Enter element " << option << " you want to add: ";
	if (!Common::AssertInputValue(findData))
	{
		cout << endl << errorValueText << endl;
		return;
	}


	Node* findNode = ListItem::LinearSearch(list, findData);

	if (option == "after")
	{
		ListItem::AddAfter(list, findNode, data);
	}
	if (option == "before")
	{
		ListItem::AddBefore(list, findNode, data);
	}
	
	cout << endl << "New ";
	PrintList(list);
}

void Menu::CaseFind(List* list)
{
	int data;
	cout << endl << "Enter element you want to find: ";
	if (!Common::AssertInputValue(data))
	{
		cout << endl << errorValueText << endl;
		return;
	}

	Node* findNode = ListItem::LinearSearch(list, data);

	if (findNode == nullptr)
	{
		cout << endl << noElementText << endl;
		return;
	}
	if (findNode->Next == nullptr && findNode->Prev == nullptr)
	{
		cout << endl << "Your item is the only one in the list" << endl;
		return;
	}
	else if (findNode->Prev == nullptr)
	{
		cout << endl << "Your item is first one in the list ";
		cout << "and stands before " << findNode->Next->Data << endl;
		return;
	}
	else if (findNode->Next == nullptr)
	{
		cout << endl << "Your item is last one in the list ";
		cout << "and stands after " << findNode->Prev->Data << endl;
		return;
	}
	cout << endl << "Your item " << data << " stands between " << findNode->Prev->Data << " and " << findNode->Next->Data;
}

void Menu::CaseRemove(List* list)
{
	int data;
	cout << endl << "Enter element you want to remove: ";
	if (!Common::AssertInputValue(data))
	{
		cout << endl << errorValueText << endl;
		return;
	}
	
	/*int index;
	
	cout << endl << "Enter element index you want to remove: ";
	if (!Common::AssertInputValue(index))
	{
		cout << endl << errorValueText << endl;
		return;
	}*/

	cout << endl << "Old ";
	PrintList(list);

	/*chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	Node* findNode = ListItem::SearchElement(list, index);*/

	Node* findNode = ListItem::LinearSearch(list, data);
	if (findNode == nullptr)
	{
		cout << endl << noElementText << endl;
		return;
	}
	ListItem::Remove(list, findNode);
	if (list->Head != nullptr)
	{
		
	/*	chrono::steady_clock::time_point end = chrono::steady_clock::now();
		cout << "Time difference (sec) = " << (chrono::duration_cast<chrono::
			microseconds>(end - begin).count()) / 1000000.0 << endl;*/

		//cout << endl << "New ";
		PrintList(list);

		return;
	}
	/*chrono::steady_clock::time_point end = chrono::steady_clock::now();
	cout << "Time difference (sec) = " << (chrono::duration_cast<chrono::
		microseconds>(end - begin).count()) / 1000000.0 << endl;*/

	cout << endl << "List is empty now, create new with 1st or 2nd option";
	cout << endl;
	
}

void Menu::MenuApp(List* list)
{
	bool listExists = false;
	int selectedOption = 0;
	while (selectedOption != 10)
	{
		PrintMenu();
		if (Common::AssertInputValue(selectedOption))
		{
			switch (selectedOption)
			{
			case 1:
			{
				CaseCreate(list,"random");
				listExists = true;
				break;
			}
			case 2:
			{
				CaseCreate(list, "custom");
				listExists = true;
				break;
			}
			case 3:
			{
				if (listExists)
				{
					CaseAdd(list, "head");
				}
				else
				{
					cout << endl << listNotExistText << endl;
				}
				break;
			}
			case 4:
			{
				if (listExists)
				{
					CaseAdd(list, "tail");
				}
				else
				{
					cout << endl << listNotExistText << endl;
				}
				break;
			}
			case 5:
			{
				if (listExists)
				{
					CaseAdd(list, "after");
				}
				else
				{
					cout << endl << listNotExistText << endl;
				}
				break;
			}
			case 6:
			{
				if (listExists)
				{
					CaseAdd(list, "before");
				}
				else
				{
					cout << endl << listNotExistText << endl;
				}
				break;
			}
			case 7:
			{
				if (listExists)
				{
					CaseRemove(list);
				}
				else
				{
					cout << endl << listNotExistText << endl;
				}
				if (list->Head == list->Tail)
					listExists = false;
				break;
			}
			case 8:
			{	
				if (listExists)
				{
					cout << endl << "Old ";
					PrintList(list);
					ListItem::Sort(list);
					cout << endl << "New ";
					PrintList(list);
				}
				else
				{
					cout << endl << listNotExistText << endl;
				}
				break;
			}
			case 9:
			{
				if (listExists)
				{
					CaseFind(list);
				}
				else
				{
					cout << endl << listNotExistText << endl;
				}
				break;
			}
			case 10:
			{
				if (listExists)
				{
					ListItem::Delete(list);
					delete list;
				}
				return;
			}
			}
		}
	}
}

