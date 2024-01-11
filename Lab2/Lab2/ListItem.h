#pragma once
#include "Main.h"

class ListItem
{
public:
	static void CreateRandomListItems(struct List* list, int size);
	static void CreateCustomListItems(List* list, int data);
	static struct Node* AddAtHead(struct List* list, int data);
	static struct Node* AddAtTail(struct List* list, int data);
	static struct Node* LinearSearch(struct List* list, int data);
	static void Remove(struct List* list, struct Node* node);
	static void AddAfter(struct List* list, struct Node* node, int data);
	static void AddBefore(struct List* list, struct Node* node, int data);
	static void Sort(struct List* list);
	static struct Node* SearchElement(struct List* list, int index);
	static void Delete(List* list);
};

