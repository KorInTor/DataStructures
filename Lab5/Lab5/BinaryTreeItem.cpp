#include "BinaryTreeItem.h"
#include <iostream>


BinaryTreeNode* BinaryTreeItem::CreateNode(int data)
{
	BinaryTreeNode* newElement = new BinaryTreeNode();
	newElement->Data = data;
	newElement->Left = nullptr;
	newElement->Right = nullptr;
	return newElement;
}

void BinaryTreeItem::Insert(BinaryTreeNode*& node, int value)
{
	if (node == nullptr)
	{
		node = new BinaryTreeNode(value);
		return;
	}
	if (node->Data > value)
	{
		return Insert(node->Left, value);
	}
	else
	{
		return Insert(node->Right, value);
	}
}

BinaryTreeNode* BinaryTreeItem::RemoveNode(
	BinaryTreeNode* currentNode, int value)
{
	if (currentNode == nullptr)
	{
		return currentNode;
	}

	if (value < currentNode->Data)
	{
		currentNode->Left = RemoveNode(currentNode->Left, value);
	}
	else if (value > currentNode->Data)
	{
		currentNode->Right = RemoveNode(currentNode->Right, value);
	}
	else
	{
		if (currentNode->Left == nullptr)
		{
			BinaryTreeNode* tempNode = currentNode->Right;
			delete currentNode;
			return tempNode;
		}

		if (currentNode->Right == nullptr)
		{
			BinaryTreeNode* tempNode = currentNode->Left;
			delete currentNode;
			return tempNode;
		}

		BinaryTreeNode* tempNode = SearchMinNode(currentNode->Right);
		currentNode->Data = tempNode->Data;
		currentNode->Right = RemoveNode(currentNode->Right, tempNode->Data);
		
	}
	
	return currentNode;
}

BinaryTreeNode* BinaryTreeItem::SearchMinNode(BinaryTreeNode* current)
{
	if (current->Left != nullptr)
	{
		current = SearchMinNode(current->Left);
	}
	else
	{
		return current;
	}
}

BinaryTreeNode* BinaryTreeItem::SearchMaxNode(BinaryTreeNode* current)
{
	if (current->Right != nullptr)
	{
		current = SearchMaxNode(current->Right);
	}
	else
	{
		return current;
	}
}


BinaryTreeNode* BinaryTreeItem::SearchNodeByValue(
	BinaryTreeNode* current, int value)
{
	if (current->Data == value)
	{
		return current;
	}
	if ((current->Data < value) && (current->Right != nullptr))
	{
		SearchNodeByValue(current->Right, value);
	}
	else
	{
		if ((current->Data > value) && (current->Left != nullptr))
		{
			SearchNodeByValue(current->Left, value);
		}
		else
		{
			return nullptr;
		}
	}
}

void BinaryTreeItem::DeleteBinaryTree(BinaryTreeNode* current)
{
	if (current == nullptr)
	{
		return;
	}

	DeleteBinaryTree(current->Left);
	DeleteBinaryTree(current->Right);
	delete current;
}