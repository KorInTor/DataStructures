#include <iostream>

using namespace std;

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
	double array[] = { 12.0,21.5,119.2,-80.7, 300.0, 75.5, 81.2, 8.1, 47.3, 31.2, 85.3, 100.1 };
	int sizeArray = sizeof(array) / sizeof(array[0]);
	double searchingValue;
	cout << "Source array is:\n";
	Print(array, sizeArray);
	cout << "Enter searching value: ";
	cin >> searchingValue;
	cout << "\nElements of array more than " << searchingValue <<" is: ";
	for (int i = 0; i < sizeArray; i++)
	{
		if (searchingValue < array[i])
		{
			cout << array[i] << " ";
		}
	}
}