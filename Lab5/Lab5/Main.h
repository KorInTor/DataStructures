#pragma once
#include "Menu.h"

struct BinaryTreeNode
{
	int Data;
	BinaryTreeNode* Left = nullptr;
	BinaryTreeNode* Right = nullptr;
	BinaryTreeNode() {};

	BinaryTreeNode(int data)
	{
		Data = data;
	};
};

struct BinaryTree
{
	BinaryTreeNode* Root;

	BinaryTree()
	{
		Root = nullptr;
	}
};

struct TreapNode
{
	int Data;
	int Priority;
	TreapNode* Left;
	TreapNode* Right;
};

struct Treap
{
	TreapNode* Root;
};
