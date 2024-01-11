#pragma once
#include "Main.h"

class BinaryTreeItem
{
public:
	static struct BinaryTreeNode* CreateNode(int data);
	static void Insert(BinaryTreeNode*& node, int value);
	static struct BinaryTreeNode* RemoveNode(
		struct BinaryTreeNode* binaryTree, int value);
	static struct BinaryTreeNode* SearchMinNode(
		struct BinaryTreeNode* current);
	static struct BinaryTreeNode* SearchMaxNode(
		struct BinaryTreeNode* current);
	static struct BinaryTreeNode* SearchNodeByValue(
		struct BinaryTreeNode* current, int value);
	static void DeleteBinaryTree(struct BinaryTreeNode* current);
};
