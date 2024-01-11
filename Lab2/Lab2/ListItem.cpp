#include "ListItem.h"
#include <random>
#include <time.h>
#include <iostream>

void ListItem::CreateRandomListItems(List* list, int size)
{
	srand(time(NULL));

	Node* currentNode = new Node();
	list->Head = currentNode;
	list->Tail = currentNode;
	currentNode->Data = rand();

	if (size > 1)
	{
		for (int i = 0;i < size - 1;i++)
		{
			Node* newNode = new Node();
			newNode->Data = rand();
			currentNode->Next = newNode;
			newNode->Prev = currentNode;
			list->Tail = newNode;
			currentNode = newNode;
		}
	}
}

void ListItem::CreateCustomListItems(List* list, int data)
{
	Node* newNode = new Node();
	list->Head = newNode;
	list->Tail = newNode;
	newNode->Data = data;
}

Node* ListItem::AddAtHead(List* list,int data)
{
	Node* newNode = new Node();
	newNode->Data = data;
	list->Head->Prev = newNode;
	newNode->Next = list->Head;
	list->Head = newNode;
	return newNode;
}

Node* ListItem::AddAtTail(List* list, int data)
{
	Node* newNode = new Node();
	newNode->Data = data;
	list->Tail->Next = newNode;
	newNode->Prev = list->Tail;
	list->Tail = newNode;
	return newNode;
}

Node* ListItem::LinearSearch(List* list, int data)
{
	Node* currentNode = list->Head;
	do 
	{
		if (currentNode->Data == data)
			return currentNode;
		currentNode = currentNode->Next;
	} while (currentNode!=nullptr);
	return nullptr;
}

void ListItem::Remove(List* list, Node* node)
{
	if (list->Head == node && list->Tail == node)
	{
		list->Head = nullptr;
		list->Tail = nullptr;
		delete node;
		return;
	}
	if (list->Head == node)
	{
		list->Head = node->Next;
		node->Next->Prev = node->Prev;
		delete node;
		return;
	}
	if (list->Tail == node)
	{
		list->Tail = node->Prev;
		node->Prev->Next = node->Next;
		delete node;
		return;
	}
	node->Next->Prev = node->Prev;
	node->Prev->Next = node->Next;
	delete node;
}

void ListItem::AddAfter(List* list,Node* node, int data)
{
	if (list->Tail == node)
	{
		Node* newNode = AddAtTail(list,data);
		return;
	}
	Node* newNode = new Node();
	newNode->Data = data;
	newNode->Next = node->Next;
	newNode->Prev = node;
	node->Next->Prev = newNode;
	node->Next = newNode;
}

void ListItem::AddBefore(List* list,Node* node, int data)
{
	if (list->Head == node)
	{
		Node* newNode = AddAtHead(list, data);
		return;
	}
	Node* newNode = new Node();
	newNode->Data = data;
	newNode->Next = node;
	newNode->Prev = node->Prev;
	node->Prev->Next = newNode;
	node->Prev = newNode;
}

void ListItem::Sort(List* list)
{
	Node* nodeI = list->Head;
	Node* nodeJ = list->Head;
	Node* current = list->Head;
	int size = 0;

	do
	{
		size++;
		current = current->Next;
	} while (current != nullptr);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (nodeJ->Data > nodeI->Data)
			{
				int temp = nodeJ->Data;
				nodeJ->Data = nodeI->Data;
				nodeI->Data = temp;
			}

			nodeJ = nodeJ->Next;
		}

		nodeJ = list->Head;
		nodeI = nodeI->Next;
	}
}

Node* ListItem::SearchElement(List* list, int index)
{
	Node* temp = list->Head;
	int count = 1;

	do
	{
		if (count == index + 1)
		{
			return temp;
		}

		temp = temp->Next;
		count++;
	} while (temp != nullptr);

	return nullptr;
}

void ListItem::Delete(List* list)
{
	Node* curretNode = list->Head;
	Node* temp = curretNode;
	while (curretNode != nullptr)
	{
		temp = curretNode;
		curretNode = curretNode->Next;
		delete temp;
	}
}