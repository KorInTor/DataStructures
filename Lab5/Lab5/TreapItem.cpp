#include "TreapItem.h"
#include <time.h>
#include <stdlib.h>

void TreapItem::Split(TreapNode* tree, int key, TreapNode*& left, TreapNode*& right)
{
	if (tree == nullptr)
	{
		left = right = nullptr;
		return;
	}

	if (tree->Data > key)
	{
		Split(tree->Left, key, left, tree->Left);
		right = tree;
	}
	else if (tree->Data <= key)
	{
		Split(tree->Right, key, tree->Right, right);
		left = tree;
	}
}

void TreapItem::Merge(TreapNode*& tree, TreapNode* left, TreapNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		tree = left ? left : right;
	}
	else if (left->Priority > right->Priority)
	{
		Merge(left->Right, left->Right, right);
		tree = left;
	}
	else
	{
		Merge(right->Left, left, right->Left);
		tree = right;
	}
}

void TreapItem::InsertNotOptimal(TreapNode*& root, int value, int priority)
{
	TreapNode* left;
	TreapNode* right;
	Split(root, value, left, right);
	TreapNode* newElement = new TreapNode;
	newElement->Left = nullptr;
	newElement->Right = nullptr;
	newElement->Data = value;
	newElement->Priority = priority;
	Merge(root, left, newElement);
	Merge(root, root, right);
}

void TreapItem::InsertOptimal(int value, int priority, TreapNode*& current)
{
	if (current == nullptr)
	{
		current = new TreapNode;
		current->Left = nullptr;
		current->Right = nullptr;
		current->Data = value;
		current->Priority = priority;
		return;
	}

	if (priority >= current->Priority)
	{
		TreapNode* left;
		TreapNode* right;
		Split(current, value, left, right);
		TreapNode* newElement = new TreapNode;
		newElement->Left = left;
		newElement->Right = right;
		newElement->Data = value;
		newElement->Priority = priority;
		current = newElement;
	}
	else if (value < current->Data)
	{
		InsertOptimal(value, priority, current->Left);
	}
	else
	{
		InsertOptimal(value, priority, current->Right);
	}
}

void TreapItem::DeleteNotOptimal(TreapNode*& root, int value)
{
	TreapNode* left;
	TreapNode* right;
	TreapNode* foundElement;
	Split(root, value - 1, left, right);
	Split(right, value, foundElement, right);
	Merge(root, left, right);
	delete foundElement;
}

void TreapItem::DeleteOptimal(int value, TreapNode*& current)
{
	if (current == nullptr)
	{
		return;
	}

	if (value == current->Data)
	{
		TreapNode* element = current;
		Merge(current, current->Left, current->Right);
		delete element;
	}
	else if (value < current->Data)
	{
		DeleteOptimal(value, current->Left);
	}
	else
	{
		DeleteOptimal(value, current->Right);
	}
}

TreapNode* TreapItem::SearchElementByValue(TreapNode* current, int value)
{
	if (current->Data == value)
	{
		return current;
	}

	if ((current->Data < value) && (current->Right != nullptr))
	{
		SearchElementByValue(current->Right, value);
	}
	else if ((current->Data > value) && (current->Left != nullptr))
	{
		SearchElementByValue(current->Left, value);
	}
	else
	{
		return nullptr;
	}
}

void TreapItem::DeleteTreap(TreapNode* current)
{
	if (current == nullptr)
	{
		return;
	}

	DeleteTreap(current->Left);
	DeleteTreap(current->Right);
	delete current;
}