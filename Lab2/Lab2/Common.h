#pragma once
#include "Main.h"

class Common
{
public:
	static bool AssertValueInRange(int value, int max, int min);
	static bool AssertInputValue(int& value);
};

