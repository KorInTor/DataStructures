#include <iostream>

using namespace std;

double GetPower(double base, int exponent) 
{
	double result = base;
	for (int i = 1;i < exponent;i++)
	{
		result = result * base;
	}
	return result;
}

int main()
{
	double base;
	int exponent;
	cout << "2.0 ^ 5 = " << GetPower(base = 2, exponent = 5) << endl;
	cout << "3.0 ^ 4 = " << GetPower(base = 3, exponent = 4) << endl;
	cout << "-2.0 ^ 5 = " << GetPower(base = -2, exponent = 5) << endl;
}