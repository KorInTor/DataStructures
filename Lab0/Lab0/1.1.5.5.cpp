#include <iostream>

using namespace std;

int FindMaxValueIndex(int value,int array[],int size)
{
	for (int i = 0;i < size;i++)
	{
		if (array[i] == value)
			return i;
	}
	return -1;
}
void Print(int* array, int sizeArray)
{
	for (int i = 0; i < sizeArray; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}
int main()
{
	int size = 10;
	int* array = new int[size] {1, 15, -8, -3, 12, 38, 0, 4, 16, 4};

	cout << "Int array:" << endl;

	Print(array, size);

	int value;
	cout << "\nEnter searching value: ";
	cin >> value;
	cout << "\nIndex of searching value " << value
		<< " is: " << FindMaxValueIndex(value, array, size);

	delete[] array;
}