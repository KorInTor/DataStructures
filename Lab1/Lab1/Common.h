#ifndef COMMON_H
#define COMMON_H
class Common
{
public:
	static bool AssertValueInRange(int& value, int max, int min);
	static bool AssertInputValue(int& value);
};
#endif
