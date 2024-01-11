#include "QueueRingBuffer.h"

void QueueRingBuffer::Enqueue(RingBuffer* ringBuffer, int data)
{
	if (ringBuffer->Tail == ringBuffer->BufferSize)
		Resize(ringBuffer);
	ringBuffer->Buffer[ringBuffer->Tail] = data;
	ringBuffer->Tail++;
}

void QueueRingBuffer::Dequeue(RingBuffer* ringBuffer)
{
	ringBuffer->Buffer[ringBuffer->Head] = ' ';
	ringBuffer->Head++;
}

void QueueRingBuffer::Resize(RingBuffer* ringBuffer)
{
	int newBufferSize;

	newBufferSize = ringBuffer->BufferSize / 2 + ringBuffer->BufferSize;

	RingBuffer* newBuffer = RingBufferItem::CreateCustomRingBuffer(newBufferSize);
	int index = 0;

	for (int i = ringBuffer->Head; i <= ringBuffer->Tail; i++)
	{
		newBuffer->Buffer[index] = ringBuffer->Buffer[i];
		index++;
	}

	delete[] ringBuffer->Buffer;

	ringBuffer->BufferSize = newBufferSize;
	ringBuffer->Buffer = newBuffer->Buffer;
	ringBuffer->Head = 0;
	ringBuffer->Tail = index-1;
}
