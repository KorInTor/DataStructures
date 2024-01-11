#pragma once
#include "Menu.h"

struct Stack
{
	int* Buffer;
	int BufferSize;
	int Top;
};

struct RingBuffer
{
	int* Buffer;
	int BufferSize;
	int Head;
	int Tail;
};
