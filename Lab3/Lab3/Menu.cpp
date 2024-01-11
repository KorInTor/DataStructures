#include "Menu.h"
#include <iostream>

using namespace std;

const string errorValue = "Incorrect value returning to menu";

void Menu::PrintMenu(string option)
{
	if (option == "main")
	{
		cout << endl << "Welcome to Lab3!" << endl;
		cout << "1) Create and work with Stack" << endl;
		cout << "2) Create and work with Ring Buffer" << endl;
		cout << "3) Create and work with Queue Stack" << endl;
		cout << "4) Create and work with Queue Ring Buffer" << endl;
		cout << "5) Shut Down" << endl;
		cout << "Choose where you want to go to: ";
	}
	else if (option == "stack")
	{
		cout << endl << "Welcome to Stack SubMenu!" << endl;
		cout << "1) Push" << endl;
		cout << "2) Pop" << endl;
		cout << "3) Delete and Exit to Main" << endl;
		cout << "Choose option: ";
	}
	else if (option == "ringBuffer")
	{
		cout << endl << "Welcome to Ring Buffer SubMenu!" << endl;
		cout << "1) Add" << endl;
		cout << "2) Remove" << endl;
		cout << "3) CountFreeSpace" << endl;
		cout << "4) CountOccupiedSpace" << endl;
		cout << "5) Delete and Exit to Main" << endl;
		cout << "Choose option: ";
	}
	else if (option == "queue")
	{
		cout << endl << "Welcome to Queue SubMenu!" << endl;
		cout << "1) Enqueue" << endl;
		cout << "2) Dequeue" << endl;
		cout << "3) Delete and Exit to Main" << endl;
		cout << "Choose option: ";
	}
}

void Menu::PrintStack(int size,Stack* stack)
{
	for (int i = size-1;i >= 0;i--)
	{
		cout << "|" << stack->Buffer[i] << "|" << endl;
	}
}


void Menu::PrintStackQueue(StackQueue* queue)
{
	for (int i = queue->firstStack->Top;i >= 0;i--)
	{
		cout << " | " << queue->firstStack->Buffer[i] << " | ";
	}
	cout << " -> ";
	for (int i = 0;i < queue->secondStack->Top+1;i++)
	{
		cout << " | " << queue->secondStack->Buffer[i] << " | ";
	}
	cout << " / firstStack Top: " << queue->firstStack->Top << " / secondStack->Top: " << queue->secondStack->Top;
}


void Menu::PrintRingBuffer(RingBuffer* buffer)
{
	for (int i = 0; i < buffer->BufferSize; i++)
	{
		if (buffer->Buffer[i] == ' ')
		{
			cout << "X" << " ";
		}
		else
		{
			cout << buffer->Buffer[i] << " ";
		}
	}
	cout << endl << "Current BufferSize is " << buffer->BufferSize;
	cout << endl << "Current Head is " << buffer->Head << " Current Tail is " << buffer->Tail;
	cout << endl;
}

void Menu::MenuApp()
{
	int selectedOption = -1;
	int size = 1;
	while (selectedOption != 5)
	{
		PrintMenu("main");
		if (!Common::AssertInputValue(selectedOption) || !Common::AssertValueInRange(selectedOption,5,1))
		{
			cout << errorValue << endl;
		}
		switch (selectedOption)
		{
		case 1:
		{
			Stack* stack = new Stack();
			StackMenu(stack);
			break;
		}
		case 2:
		{
			RingBufferMenu();
			break;
		}
		case 3:
		{
			QueueStackMenu();
			break;
		}
		case 4:
		{
			QueueRingBufferMenu();
			break;
		}
		case 5:
		{
			cout << "Insert Shuting Down";
			break;
		}
		}
	}
}

void Menu::StackMenu(Stack* stack)
{
	int size = 1;

	Menu::CreateStack(stack, size);

	int data;

	int selectedOption = -1;
	while (selectedOption != 3)
	{
		PrintMenu("stack");
		if (!Common::AssertInputValue(selectedOption) || !Common::AssertValueInRange(selectedOption, 6, 1))
		{
			cout << errorValue << endl;
		}
		switch (selectedOption)
		{
		case 1:
		{
			cout << endl << "Enter item to Push: ";
			if (!Common::AssertInputValue(data))
			{
				cout << errorValue << endl;
			}
			StackItem::Push(stack, data);
			PrintStack(stack->Top+1, stack);
			break;
		}
		case 2:
		{
			if (stack->Top == -1)
			{
				cout << "Stack is empty" << endl;
				break;
			}
			cout <<"Poped this item - " << StackItem::Pop(stack) << endl;
			PrintStack(stack->Top + 1, stack);
			break;
		}
		case 3:
		{
			delete[] stack->Buffer;
			delete[] stack;
			cout << "Insert Shuting Down" << endl;
			return;
		}
		}
	}
}

void Menu::CreateStack(struct Stack* stack, int size)
{
	stack->Buffer = new int[size];
	stack->BufferSize = size;
	stack->Top = -1;
}

void Menu::RingBufferMenu()
{
	int size = 0;
	cout << "Enter size :";
	if (!Common::AssertInputValue(size))
	{
		cout << errorValue << endl;
	}

	RingBuffer* buffer = RingBufferItem::CreateCustomRingBuffer(size);
	
	PrintRingBuffer(buffer);

	int data;

	bool firstValueIsAdded = false;

	int selectedOption = -1;
	while (selectedOption != 5)
	{
		PrintMenu("ringBuffer");
		if (!Common::AssertInputValue(selectedOption) || !Common::AssertValueInRange(selectedOption, 6, 1))
		{
			cout << errorValue << endl;
		}
		switch (selectedOption)
		{
		case 1:
		{
			cout << endl << "Enter item to Add: ";
			if (!Common::AssertInputValue(data))
			{
				cout << errorValue << endl;
			}
			if (!firstValueIsAdded)
			{
				RingBufferItem::AddFirstItem(buffer, data);
				firstValueIsAdded = true;
				PrintRingBuffer(buffer);
				break;
			}
			RingBufferItem::AddItem(buffer, data);
			PrintRingBuffer(buffer);
			break;
		}
		case 2:
		{
			if (RingBufferItem::IsEmpty(buffer))
			{
				cout << endl << "Buffer is empty" << endl;
				break;
			}
			RingBufferItem::RemoveItem(buffer);
			PrintRingBuffer(buffer);
			break;
		}
		case 3:
		{
			cout <<endl << "There are currently:" << RingBufferItem::CountFreeSpace(buffer) << " freespace";
			break;
		}
		case 4:
		{
			cout << endl << "There are currently:" << RingBufferItem::CountOccupiedSpace(buffer) << " occupiedspace";
			break;
		}
		case 5:
		{
			delete[] buffer->Buffer;
			delete buffer;
			cout << "Insert Shuting Down" << endl;
			break;
		}
		}
	}
}

void Menu::QueueStackMenu()
{
	int size = 0;
	cout << "Enter size :";
	if (!Common::AssertInputValue(size))
	{
		cout << errorValue << endl;
	}

	StackQueue* queue = QueueStack::CreateQueue(size);

	PrintStackQueue(queue);

	int data;

	bool firstValueIsAdded = false;

	int selectedOption = -1;
	while (selectedOption != 3)
	{
		PrintMenu("queue");
		if (!Common::AssertInputValue(selectedOption) || !Common::AssertValueInRange(selectedOption, 6, 1))
		{
			cout << errorValue << endl;
		}
		switch (selectedOption)
		{
		case 1:
		{
			cout << endl << "Enter item to Add: ";
			if (!Common::AssertInputValue(data))
			{
				cout << errorValue << endl;
			}
			QueueStack::Enqueue(queue, data);
			PrintStackQueue(queue);
			break;
		}
		case 2:
		{
			if (StackItem::IsEmpty(queue->firstStack) && StackItem::IsEmpty(queue->secondStack))
			{
				cout << endl << "Queue is empty" << endl;
				break;
			}
			QueueStack::Dequeue(queue);
			PrintStackQueue(queue);
			break;
		}
		case 3:
		{
			delete[] queue->firstStack->Buffer;
			delete[] queue->secondStack->Buffer;
			delete[] queue->firstStack;
			delete[] queue->secondStack;
			delete[] queue;
			cout << "Insert Shuting Down" << endl;
			break;
		}
		}
	}
}

void Menu::QueueRingBufferMenu()
{
	int size = 0;
	cout << "Enter size :";
	if (!Common::AssertInputValue(size))
	{
		cout << errorValue << endl;
	}

	RingBuffer* queueBuffer = RingBufferItem::CreateCustomRingBuffer(size);

	PrintRingBuffer(queueBuffer);

	int data;

	bool firstValueIsAdded = false;

	int selectedOption = -1;
	while (selectedOption != 3)
	{
		PrintMenu("queue");
		if (!Common::AssertInputValue(selectedOption) || !Common::AssertValueInRange(selectedOption, 6, 1))
		{
			cout << errorValue << endl;
		}
		switch (selectedOption)
		{
		case 1:
		{
			cout << endl << "Enter item to Add: ";
			if (!Common::AssertInputValue(data))
			{
				cout << errorValue << endl;
			}
			QueueRingBuffer::Enqueue(queueBuffer, data);
			PrintRingBuffer(queueBuffer);
			break;
		}
		case 2:
		{
			if (RingBufferItem::IsEmpty(queueBuffer))
			{
				cout << endl << "Queue is empty" << endl;
				break;
			}
			QueueRingBuffer::Dequeue(queueBuffer);
			PrintRingBuffer(queueBuffer);
			break;
		}
		case 3:
		{
			delete[] queueBuffer->Buffer;
			delete queueBuffer;
			cout << "Insert Shuting Down" << endl;
			break;
		}
		}
	}
}
