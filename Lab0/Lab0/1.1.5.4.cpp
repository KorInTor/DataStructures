#include <iostream>

using namespace std;
void Sort(double* array, int sizeArray)
{
	for (int i = 0; i < sizeArray; i++)
	{
		for (int j = 0; j < sizeArray; j++)
		{
			if (array[j] > array[i])
			{
				double temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
}

void Print(double* array, int sizeArray)
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
	double* array = new double[size] {1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5, 16.7, 4.5};
	cout << "Array of double:" << endl;

	Print(array, size);
	Sort(array, size);

	cout << "Sorted array of double:" << endl;

	Print(array, size);

	delete[] array;
}