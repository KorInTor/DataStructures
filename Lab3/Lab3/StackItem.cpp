#include "StackItem.h"
#include <random>
#include <time.h>

void StackItem::StackFillRandom(Stack* stack)
{
	srand(time(NULL));

	int defaultSize = 8;

	stack->BufferSize = defaultSize;
	stack->Buffer = new int[defaultSize];

	for (int i = 0; i < stack->BufferSize;i++)
	{
		stack->Buffer[i] = rand() % 101;
		stack->Top = i;
	}
}

Stack* StackItem::CreateStack(int size)
{
	Stack* stack = new Stack();
	stack->Buffer = new int[size];
	stack->BufferSize = size;
	stack->Top = -1;
	return stack;
}

bool StackItem::IsEmpty(Stack* stack)
{
	if (stack->Top == -1)
		return true;
	return false;
}

void StackItem::Resize(Stack* stack)
{
	int newBufferSize;

	if (stack->BufferSize % 2 == 1)
	{
		newBufferSize = stack->BufferSize * 1.5 + 0.5;
	}
	else
	{
		newBufferSize = stack->BufferSize * 1.5;
	}

	int* newBuffer = new int[newBufferSize];

	for (int i = 0; i < stack->BufferSize; i++)
	{
		newBuffer[i] = stack->Buffer[i];
	}

	delete[] stack->Buffer;

	stack->BufferSize = newBufferSize;
	stack->Buffer = newBuffer;
}

void StackItem::Push(Stack* stack, int data)
{
	if (stack->BufferSize == stack->Top + 1)
		Resize(stack);
	stack->Top++;
	stack->Buffer[stack->Top] = data;
}

int StackItem::Pop(Stack* stack)
{
	int data = stack->Buffer[stack->Top];
	stack->Buffer[stack->Top] = ' ';
	stack->Top--;
	return data;
}

void StackItem::Delete(Stack* stack)
{
	delete[] stack->Buffer;
}