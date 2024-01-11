#pragma once
#include "Main.h"

class TreapItem
{
public:
	static void Split(
		struct TreapNode* tree, int key, struct TreapNode*& left,
		struct TreapNode*& right);

	static void Merge(
		struct TreapNode*& tree, struct TreapNode* left,
		struct TreapNode* right);

	static void InsertNotOptimal(struct TreapNode*& root, int value, int priority);

	static void InsertOptimal(int value, int priority, struct TreapNode*& current);

	static void DeleteNotOptimal(struct TreapNode*& root, int value);

	static void DeleteOptimal(int value, struct TreapNode*& current);

	static struct TreapNode* SearchElementByValue(
		struct TreapNode* current, int value);

	static void DeleteTreap(struct TreapNode* current);
};
