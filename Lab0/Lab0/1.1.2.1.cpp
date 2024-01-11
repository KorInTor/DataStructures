#include <iostream>

using namespace std;

void Print(int* array, int sizeArray)
{
	for (int i = 0; i < sizeArray; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

void Sort(int* array, int sizeArray)
{
	for (int i = 0; i < sizeArray; i++)
	{
		for (int j = 0; j < sizeArray; j++)
		{
			if (array[j] > array[i])
			{
				int temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
}

int main()
{
	int array[] = { 12, 21, 119, -80, 300, 75, 81, -8, 47, 31 };
	int sizeArray = sizeof(array) / sizeof(array[0]);
	cout << "Source array is:\n";
	Print(array, sizeArray);
	Sort(array, sizeArray);
	cout << "Sorted array is:\n";
	Print(array, sizeArray);
}