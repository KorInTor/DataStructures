#pragma once
#include "BinaryTreeItem.h"
#include "Common.h"
#include "Main.h"
#include "TreapItem.h"
#include <string>

class Menu
{
public:
	static void MenuApp();
private:
	static void PrintTreap(struct TreapNode* current, int level);

	static void PrintBinaryTree(struct BinaryTreeNode* root, int space);

	static void PrintMenu(std::string option);

	static void MenuBinaryTree(struct BinaryTree* binaryTree);
	static void	MenuTreap(struct Treap* treap);
};
