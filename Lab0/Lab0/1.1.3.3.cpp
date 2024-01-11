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
void DemoGetPower(double base, int exponent)
{
	cout << base <<" ^ "<< exponent <<"  = " << GetPower(base, exponent) << endl;
}

int main()
{
	DemoGetPower(2, 5);
	DemoGetPower(3, 4);
	DemoGetPower(-2, 5);
}