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
void LettersCout(char* array, int size)
{
	int count = 0;
	cout << "All letters in your array:\n";

	for (int i = 0; i < size; i++)
	{
		if (array[i] >= 'a' && array[i] <= 'z')
		{
			cout << array[i] << " ";
			count++;
		}
	}

	cout << endl << "Number of letters in the array: " << count <<endl;
}
int main()
{
	int size = 15;
	char* array = new char[size] {'a', '5', 'm', 'i', '%', '!', 's', 'p', '*', '9', 'f', '^', ';', 'q', 'k'};

	cout << "Char array is:" << endl;
	Print(array, size);

	LettersCout(array, size);

	delete[] array;
}