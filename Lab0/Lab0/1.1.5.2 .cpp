#include <iostream>

using namespace std;

int main()
{
	bool* array = new bool[8]{ true, false,
		true, true, false, true, false, false };
	cout << "Array of bool:" << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << boolalpha << array[i] << " ";
	}

	delete[] array;
}