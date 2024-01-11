#include "Menu.h"
#include <iostream>

using namespace std;

const string incorrectInputStr = "Incorrect input, return to menu!";
const string tryAgainText = "Incorrect value entered, please try again!";

void Menu::PrintMenu(string option)
{
	if (option == "main")
	{
		cout << endl << "Menu:" << endl;
		cout << "1) Binary tree" << endl;
		cout << "2) Cartesian tree" << endl;
		cout << "3) Exit" << endl;
	}
	else if(option == "binaryTree")
	{
		cout << endl << "Menu:" << endl;
		cout << "1) Add" << endl;
		cout << "2) Remove" << endl;
		cout << "3) Element Search" << endl;
		cout << "4) Search for the maximum of the tree" << endl;
		cout << "5) Search for the minimum of the tree" << endl;
		cout << "6) Back to main menu" << endl;
	}
	else if (option == "treapTree")
	{
		cout << endl << "Menu:" << endl;
		cout << "1) Insert an element using an optimized algorithm" << endl;
		cout << "2) Insert an element with an unoptimized algorithm" << endl;
		cout << "3) Remove an element from the tree by an optimized algorithm" << endl;
		cout << "4) Remove an element from the tree by an unoptimized algorithm" << endl;
		cout << "5) Element Search" << endl;
		cout << "6) Back to main menu" << endl;
	}
	else 
	{
		cout << "Incorrect menu type contact developer";
	}
}

void Menu::PrintBinaryTree(BinaryTreeNode* root, int space = 0)
{
	int height = 10;
	if (root == nullptr)
	{
		return;
	}
	
	space += height;

	PrintBinaryTree(root->Right, space);
	cout << endl;

	for (int i = height; i < space; i++)
		cout << " ";

	cout << root->Data << "\n";

	PrintBinaryTree(root->Left, space);
}

void Menu::PrintTreap(TreapNode* current, int level)
{
	if (current)
	{
		PrintTreap(current->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}

		cout << current->Data << " : " << current->Priority << endl;
		PrintTreap(current->Left, level + 1);
	}
}

void Menu::MenuBinaryTree(BinaryTree* binaryTree)
{
	bool signTree = false;
	int value = 0;

	binaryTree->Root = nullptr;

	while (value != 6)
	{
		PrintMenu("binaryTree");
		cout << endl << "Enter menu item number: ";

		if (Common::AssertInputValue(value))
		{
			switch (value)
			{
			case 1:
			{
				int data;
				cout << "Enter a value: " << endl;

				if (!Common::AssertInputValue(data))
				{
					cout << endl << incorrectInputStr << endl;
					break;
				}
				BinaryTreeItem::Insert(binaryTree->Root, data);
				cout << endl << binaryTree->Root->Data << "<-Root" << endl;
				cout << endl << "Tree:" << endl;
				PrintBinaryTree(binaryTree->Root, 0);

				break;
			}
			case 2:
			{
				int data;
				cout << "Enter a value: " << endl;

				if (!Common::AssertInputValue(data))
				{
					cout << endl << incorrectInputStr << endl;
					break;
				}
				if (binaryTree->Root->Left != nullptr, binaryTree)
				BinaryTreeItem::RemoveNode(binaryTree->Root, data);
				cout << endl << "Tree:" << endl;
				PrintBinaryTree(binaryTree->Root, 0);

				break;
			}
			case 3:
			{
				int data;
				cout << "Enter a value: " << endl;

				if (!Common::AssertInputValue(data))
				{
					cout << endl << incorrectInputStr << endl;
					break;
				}
				BinaryTreeNode* node =
					BinaryTreeItem::SearchNodeByValue(binaryTree->Root, data);

				if (!node)
				{
					cout << "There is no such element" << endl;
				}
				else
				{
					cout << "Element found" << endl;
				}
				cout << endl << "Tree:" << endl;
				PrintBinaryTree(binaryTree->Root, 0);

				break;
			}
			case 4:
			{
				if (!binaryTree->Root)
				{
					cout << "The tree is empty" << endl;
					break;
				}

				BinaryTreeNode* maxNode =
					BinaryTreeItem::SearchMaxNode(binaryTree->Root);
				cout << "Max: " << maxNode->Data << endl;
				cout << endl << "Tree:" << endl;
				PrintBinaryTree(binaryTree->Root, 0);

				break;
			}
			case 5:
			{
				if (!binaryTree->Root)
				{
					cout << "The tree is empty" << endl;
					break;
				}

				BinaryTreeNode* minNode =
					BinaryTreeItem::SearchMinNode(binaryTree->Root);
				cout << "Min: " << minNode->Data << endl;
				cout << endl << "Tree:" << endl;
				PrintBinaryTree(binaryTree->Root, 0);

				break;
			}
			case 6:
			{
				BinaryTreeItem::DeleteBinaryTree(binaryTree->Root);
				return;
			}
			default:
			{
				cout << endl << tryAgainText << endl;
			}
			}
		}
		else
		{
			cout << endl << tryAgainText << endl;
		}
	}
}

void Menu::MenuTreap(Treap* treap)
{
	bool signTree = false;
	int value = 0;

	while (value != 6)
	{
		PrintMenu("treapTree");
		cout << endl << "Enter menu item number: ";

		if (Common::AssertInputValue(value))
		{
			switch (value)
			{
			case 1:
			{
				int data;
				cout << "Enter a value: " << endl;

				if (!Common::AssertInputValue(data))
				{
					cout << endl << incorrectInputStr << endl;
					break;
				}

				if (treap->Root)
				{
					if (TreapItem::SearchElementByValue(treap->Root, data))
					{
						cout << "An element with a value of "
							<< data << " already exists." << endl;
						break;
					}
				}

				int priority;
				cout << "Enter priority: " << endl;

				if (Common::AssertInputValue(priority))
				{
					TreapItem::InsertOptimal(
						data, priority, treap->Root);
					cout << endl << "Tree:" << endl;
					PrintTreap(treap->Root, 0);
				}
				else
				{
					cout << endl << incorrectInputStr << endl;
				}

				break;
			}
			case 2:
			{
				int data;
				cout << "Enter a value: " << endl;

				if (Common::AssertInputValue(data))
				{
					if (treap->Root)
					{
						if (TreapItem::SearchElementByValue(treap->Root, data))
						{
							cout << "An element with a value of "
								<< data << " already exists." << endl;
							break;
						}
					}

					int priority;
					cout << "Enter priority: " << endl;

					if (Common::AssertInputValue(priority))
					{
						TreapItem::InsertNotOptimal(treap->Root, data, priority);
						cout << endl << "Tree:" << endl;
						PrintTreap(treap->Root, 0);
					}
					else
					{
						cout << endl << incorrectInputStr << endl;
					}
				}
				else
				{
					cout << endl << incorrectInputStr << endl;
				}

				break;
			}
			case 3:
			{
				int data;
				cout << "Enter a value: " << endl;

				if (Common::AssertInputValue(data))
				{
					TreapItem::DeleteOptimal(data, treap->Root);
					cout << endl << "Tree:" << endl;
					PrintTreap(treap->Root, 0);
				}
				else
				{
					cout << endl << incorrectInputStr << endl;
				}

				break;
			}
			case 4:
			{
				int data;
				cout << "Enter a value: " << endl;

				if (Common::AssertInputValue(data))
				{
					TreapItem::DeleteNotOptimal(treap->Root, data);
					cout << endl << "Tree:" << endl;
					PrintTreap(treap->Root, 0);
				}
				else
				{
					cout << endl << incorrectInputStr << endl;
				}

				break;
			}
			case 5:
			{
				int data;
				cout << "Enter a value: " << endl;

				if (Common::AssertInputValue(data))
				{
					TreapNode* node =
						TreapItem::SearchElementByValue(treap->Root, data);

					if (!node)
					{
						cout << "There is no such element" << endl;
					}
					else
					{
						cout << "Element found" << endl;
					}

					cout << endl << "Tree:" << endl;
					PrintTreap(treap->Root, 0);
				}
				else
				{
					cout << endl << incorrectInputStr << endl;
				}

				break;
			}
			case 6:
			{
				TreapItem::DeleteTreap(treap->Root);
				return;
			}
			default:
			{
				cout << endl << tryAgainText << endl;
			}
			}
		}
		else
		{
			cout << endl << tryAgainText << endl;
		}
	}
}

void Menu::MenuApp()
{
	int value = 0;

	while (value != 5)
	{
		PrintMenu("main");
		cout << endl << "Enter menu item number: ";

		if (Common::AssertInputValue(value))
		{
			switch (value)
			{
			case 1:
			{
				BinaryTree* binaryTree = new BinaryTree();
				MenuBinaryTree(binaryTree);
				break;
			}
			case 2:
			{
				Treap* treap = new Treap();
				MenuTreap(treap);
				break;
			}
			case 3:
			{
				return;
			}
			default:
			{
				cout << endl << tryAgainText << endl;
			}
			}
		}
		else
		{
			cout << endl << tryAgainText << endl;
		}
	}
}