#include <iostream>

using namespace std;

void Print(char* array, int sizeArray)
{
	for (int i = 0; i < sizeArray; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

int main()
{
	char array[8];
	int sizeArray = sizeof(array) / sizeof(array[0]);
	cout << "Enter array of " << sizeArray << " chars" << endl;

	for (int i = 0; i < sizeArray; i++)
	{
		cout << "array[" << i << "]: ";
		cin >> array[i];
	}

	cout << "\nYour array is:\n";
	Print(array, sizeArray);
	cout << "All letters in your array:\n";

	for (int i = 0; i < sizeArray; i++)
	{
		if (array[i] >= 'a' && array[i] <= 'z')
		{
			cout << array[i] << " ";
		}
	}
}