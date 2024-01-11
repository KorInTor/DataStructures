#include <iostream>

using namespace std;

void RoundToTens(int& value)
{
	if (value % 10 < 5)
	{
		value = (value / 10) * 10;
	}
	else
	{
		value = ((value / 10) * 10) + 10;
	}
}

int main()
{
	int value = 14;
	RoundToTens(value);
	cout << "For 14 rounded value is " << value << endl;
	value = 191;
	RoundToTens(value);
	cout << "For 191 rounded value is " << value << endl;
	value = 27;
	RoundToTens(value);
	cout << "For 27 rounded value is " << value << endl;
}