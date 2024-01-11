#ifndef ARRAY_H
#define ARRAY_H
#include "main.h"
class Array
{
public:
	static void CreateBlankArray(struct DynamicArray* array,int size);
	static void RandomCreatingArrayFields(struct DynamicArray* array);
	static void Sort(struct DynamicArray* array);
	static void AddAtIndex(struct DynamicArray* array, int element,int index);
	static void Resize(struct DynamicArray* array);
	static void DeleteAtIndex(struct DynamicArray* array, int index);
	static int LinearSearch(struct DynamicArray* array, int element);
	static int BinarySearch(struct DynamicArray* array, int element);

};
#endif
