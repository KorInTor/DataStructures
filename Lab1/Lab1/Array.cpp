#include "Array.h"
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

void Array::RandomCreatingArrayFields(DynamicArray* array)
{
	srand(time(NULL));
	int defaultSize = 8;
	int maxValueArray = 101;

	delete[] array->InternalArray;

	array->Capacity = defaultSize;
	array->Length = defaultSize;
	array->InternalArray = new int[array->Capacity];

	for (int i = 0; i < array->Length; i++)
	{
		array->InternalArray[i] = rand() % maxValueArray;
	}
}

void Array::CreateBlankArray(DynamicArray* array,int size)
{
	delete[] array->InternalArray;

	array->Capacity = size;
	array->Length = size;
	array->InternalArray = new int[array->Capacity];

	for (int i = 0; i < array->Length; i++)
	{
		array->InternalArray[i] = 0;
	}
}

void Array::Sort(DynamicArray* array)
{
	for (int i = 0; i < array->Length - 1; i++)
	{
		for (int j = i + 1; j < array->Length; j++)
		{
			if (array->InternalArray[j] < array->InternalArray[i])
			{
				int temp = array->InternalArray[j];
				array->InternalArray[j] = array->InternalArray[i];
				array->InternalArray[i] = temp;
			}
		}
	}
}


void Array::AddAtIndex(DynamicArray* array, int element,int index)
{
	if (array->Length == array->Capacity)
	{
		Resize(array);
	}
	if (index <= array->Length-1)
	{
		for (int i = array->Length - 1;i >= index;i--)
		{
			array->InternalArray[i + 1] = array->InternalArray[i];
		}
		array->InternalArray[index] = element;
	}
	if (index == array->Length)
	{
		array->InternalArray[array->Length] = element;
	}
	array->Length++;
}

void Array::DeleteAtIndex(DynamicArray* array, int index)
{
	for (int i = index;i < array->Length - 1;i++)
	{
		array->InternalArray[i] = array->InternalArray[i+1];
	}
	array->InternalArray[array->Length - 1] = NULL;
	array->Length--;
}

void Array::Resize(DynamicArray* array)
{
	int newCapacity;
	
	newCapacity = array->Capacity / 2 + array->Capacity;

	int* newArray = new int[newCapacity];

	for (int i = 0; i < array->Length; i++)
	{
		newArray[i] = array->InternalArray[i];
	}

	delete[] array->InternalArray;

	array->Capacity = newCapacity;
	array->InternalArray = newArray;
}

int Array::LinearSearch(DynamicArray* array, int element)
{
	for (int i = 0;i < array->Length;i++)
	{
		if (array->InternalArray[i] == element)
		{
			return i;
		}
	}
	return -1;
}

int Array::BinarySearch(DynamicArray* array, int element)
{
	int first = 0;
	int last = array->Length-1;
	while (first < last)
	{
		int mid = (first + last) / 2;
		if (element <= array->InternalArray[mid])
			last = mid;
		else
			first = mid + 1;
	}
	if (array->InternalArray[first] == element)
	{
		return first;
	}
	if (array->InternalArray[last] == element)
	{
		return last;
	}
	return -1;
}
