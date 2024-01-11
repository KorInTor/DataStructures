#include "QueueStack.h"


StackQueue* QueueStack::CreateQueue(int size)
{	
	StackQueue* stack = new StackQueue();
	stack->firstStack = StackItem::CreateStack(size);
	stack->secondStack = StackItem::CreateStack(size);
	return stack;
}

void QueueStack::Enqueue(StackQueue* queue, int data)
{
	StackItem::Push(queue->firstStack, data);
}

int QueueStack::Dequeue(StackQueue* queue)
{
	if (StackItem::IsEmpty(queue->secondStack))
		MoveItems(queue->firstStack,queue->secondStack);
	return StackItem::Pop(queue->secondStack);
}

void QueueStack::MoveItems(Stack* source, Stack* target)
{
	int data;
	int top = source->Top;
	for (int i = 0;i <= top;i++)
	{
		data = StackItem::Pop(source);
		StackItem::Push(target, data);
	}
}

void QueueStack::Delete(StackQueue* queue)
{
	delete[] queue->firstStack->Buffer;
	delete[] queue->secondStack->Buffer;

	delete queue;
}
