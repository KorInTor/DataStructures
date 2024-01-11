#pragma once
#include "Menu.h"

struct Node
{
	int Data;
	Node* Next = nullptr;
	Node* Prev = nullptr;
};

struct List
{
	Node* Head = nullptr;
	Node* Tail = nullptr;
};
