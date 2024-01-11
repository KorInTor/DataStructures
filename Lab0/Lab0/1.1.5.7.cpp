#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int* MakeRandomArray(int arraySize)
{
	int* array = new int[arraySize];
	for (int i = 0;i < arraySize;i++)
	{
		array[i] = rand() % 100;
	}
	return array;
}

void Print(int* array, int sizeArray)
{
	cout << "Random array of " << sizeArray << " :" << endl;

	for (int i = 0; i < sizeArray; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl << endl;
}

int main()
{
	srand(time(0));

	int* array1 = MakeRandomArray(5);
	Print(array1, 5);

	int* array2 = MakeRandomArray(8);
	Print(array2, 8);

	int* array3 = MakeRandomArray(13);
	Print(array3, 13);

	delete[] array1;
	delete[] array2;
	delete[] array3;
}