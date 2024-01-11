#include <iostream>

using namespace std;

int main()
{
	double* array = new double[8] { 1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5 };
	cout << "Array of double:" << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << array[i] << " ";
	}
	delete[] array;
}