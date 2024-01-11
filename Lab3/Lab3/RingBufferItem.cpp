#include "RingBufferItem.h"
#include <random>
#include <time.h>
#include <iostream>

void RingBufferItem::CreateRandomRingBuffer(RingBuffer* ringBuffer, int size)
{
	srand(time(NULL));

	ringBuffer->BufferSize = size;
	ringBuffer->Buffer = new int[size];

	for (int i = 0; i < ringBuffer->BufferSize;i++)
	{
		ringBuffer->Buffer[i] = rand() % 101;
	}

	ringBuffer->Head = ringBuffer->BufferSize - 1;
	ringBuffer->Tail = 0;
}

RingBuffer* RingBufferItem::CreateCustomRingBuffer(int size)
{
	RingBuffer* ringBuffer = new RingBuffer;
	ringBuffer->Buffer = new int[size];
	ringBuffer->BufferSize = size;
	for (int i = 0;i < size;i++)
	{
		ringBuffer->Buffer[i] = ' ';
	}
	ringBuffer->Head = 0;
	ringBuffer->Tail = 0;

	return ringBuffer;
}

void RingBufferItem::AssertRingEffect(RingBuffer* ringBuffer, int headModif, int tailModif)
{
	if (ringBuffer->Head + headModif == ringBuffer->BufferSize)
		ringBuffer->Head = 0;
	else
		ringBuffer->Head = ringBuffer->Head + headModif;
	if (ringBuffer->Tail + tailModif == ringBuffer->BufferSize)
		ringBuffer->Tail = 0;
	else
		ringBuffer->Tail = ringBuffer->Tail + tailModif;
}

void RingBufferItem::AddFirstItem(RingBuffer* ringBuffer, int data)
{
	ringBuffer->Buffer[ringBuffer->Tail] = data;
	ringBuffer->Tail++;
}

void RingBufferItem::AddItem(RingBuffer* ringBuffer, int data)
{
	ringBuffer->Buffer[ringBuffer->Tail] = data;
	if (ringBuffer->Head == ringBuffer->Tail)
		AssertRingEffect(ringBuffer, 1, 1);
	else
		AssertRingEffect(ringBuffer, 0, 1);
}

void RingBufferItem::RemoveItem(RingBuffer* ringBuffer)
{
	ringBuffer->Buffer[ringBuffer->Head] = ' ';
	AssertRingEffect(ringBuffer, 1, 0);
}

void RingBufferItem::Delete(RingBuffer* ringBuffer)
{
	delete[] ringBuffer->Buffer;
}

int RingBufferItem::CountFreeSpace(RingBuffer* ringBuffer)
{
	int count = 0;
	for (int i = 0; i < ringBuffer->BufferSize;i++)
	{
		if (ringBuffer->Buffer[i] == ' ')
		{
			count++;
		}
	}
	return count;
}

int RingBufferItem::CountOccupiedSpace(RingBuffer* ringBuffer)
{
	int count = 0;
	for (int i = 0; i < ringBuffer->BufferSize;i++)
	{
		if (ringBuffer->Buffer[i] != ' ')
		{
			count++;
		}
	}
	return count;
}

bool RingBufferItem::IsEmpty(RingBuffer* ringBuffer)
{
	for (int i = 0; i < ringBuffer->BufferSize;i++)
	{
		if (ringBuffer->Buffer[i] != ' ')
		{
			return false;
		}
	}
	return true;
}
