#pragma once
#include "Main.h"

class QueueRingBuffer
{
public:
	static void Enqueue(struct RingBuffer* ringBuffer, int data);
	static void Dequeue(struct RingBuffer* ringBuffer);
private:
	static void Resize(struct RingBuffer* ringBuffer);
};

