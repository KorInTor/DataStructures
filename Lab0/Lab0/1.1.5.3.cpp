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
	int n;
	cout << "Enter char array size: ";
	cin >> n;
	char* a = new char[n];
	for (int i = 0; i < n;i++)
	{
		cout << "Enter a[" << i <<"]: ";
		cin >> a[i];
	}
	Print(a, n);
	delete[] a;
}