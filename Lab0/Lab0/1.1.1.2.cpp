﻿#include <iostream>

using namespace std;

void Breackpoints()
{
    double add = 1.0;
    double sum = 0.0;
    for (int i = 0; i < 1000; i++)
    {
        sum += add * i;
        if (i % 3 == 0)
        {
            add *= 1.1;
        }
        else 
        {
            add /= 3.0;
        }
    }
    cout << "Total sum is" << sum << endl;
}

int main()
{
    Breackpoints();
}
