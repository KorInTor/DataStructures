#pragma once
#include "Main.h"
struct StackQueue
{
	struct Stack* firstStack;
	struct Stack* secondStack;
};

class QueueStack
{
public:
	static StackQueue* CreateQueue(int size);
	static void Enqueue(StackQueue* queue, int data);
	static int Dequeue(StackQueue* queue);
	static void MoveItems(Stack* source, Stack* target);
	static void Delete(StackQueue* queue);

};