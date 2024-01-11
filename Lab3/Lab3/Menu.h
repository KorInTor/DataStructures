#pragma once
#include "Main.h"
#include "Common.h"
#include "StackItem.h"
#include "RingBufferItem.h"
#include "QueueRingBuffer.h"
#include "QueueStack.h"
#include <string>

class Menu
{
public:
	static void MenuApp();
private:
	static void PrintMenu(std::string option);
	static void PrintStack(int size,struct Stack* stack);
	static void PrintRingBuffer(struct RingBuffer* buffer);
	static void PrintStackQueue(struct StackQueue* queue);
	static void StackMenu(struct Stack* stack);
	static void CreateStack(struct Stack* stack, int size);
	static void RingBufferMenu();
	static void QueueStackMenu();
	static void QueueRingBufferMenu();
};

