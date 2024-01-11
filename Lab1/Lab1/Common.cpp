#include "Common.h"
#include <iostream>

using namespace std;

bool Common::AssertValueInRange(int& value, int min, int max)
{
	if (value < min || value > max)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Common::AssertInputValue(int& value)
{
	int element;
	cin >> element;

	if (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}

	value = element;
	return true;
}