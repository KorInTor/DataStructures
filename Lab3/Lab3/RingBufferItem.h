#pragma once
#include "Main.h"

class RingBufferItem
{
public:
	static void CreateRandomRingBuffer(struct RingBuffer* ringBuffer, int size);
	static struct RingBuffer* CreateCustomRingBuffer(int size);
	static void AssertRingEffect(struct RingBuffer* ringBuffer, int headModif, int tailModif);
	static void AddFirstItem(struct RingBuffer* ringBuffer, int data);
	static void AddItem(struct RingBuffer* ringBuffer, int data);
	static void RemoveItem(struct RingBuffer* ringBuffer);
	static void Delete(struct RingBuffer* ringBuffer);
	static int CountFreeSpace(struct RingBuffer* ringBuffer);
	static int CountOccupiedSpace(struct RingBuffer* ringBuffer);
	static bool IsEmpty(struct RingBuffer* ringBuffer);
};

