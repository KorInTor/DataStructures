#pragma once
#include "Main.h"

class StackItem
{
public:
	static void StackFillRandom(struct Stack* stack);
	static Stack* CreateStack(int size);
	static bool IsEmpty(Stack* stack);
	static void Resize(struct Stack* stack);
	static void Push(struct Stack* stack, int data);
	static int Pop(Stack* stack);
	static void Delete(Stack* stack);
};

