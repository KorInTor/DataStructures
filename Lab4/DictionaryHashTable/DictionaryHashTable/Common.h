#pragma once

class Common
{
public:
	static bool AssertValueInRange(int index, int max, int min);
	static bool AssertInputValue(int& value);
};