#include "Menu.h"
#include <iostream>

using namespace std;

const string errorValueText = "Inccorect value, return to menu";
const string arrayNotExistText = "Array doesnt exists, you need to create one, return to menu";
const string outOfRangeText = "Index is out of range, return to menu";
const string noElementText = "No such element in array, return to menu";
const string arrayNotSorted = "Array not sorted, return to menu";
const string tryAgainText = "Incorected value, try again";

void Menu::PrintMenu()
{
	cout << endl << "Menu:" << endl;
	cout << "1) Add elemnt to array" << endl;
	cout << "2) Add elemnt to array after choosen element" << endl;
	cout << "3) Remove element from array" << endl;
	cout << "4) Array sort" << endl;
	cout << "5) Linear search for element in array" << endl;
	cout << "6) Binary search for element in array" << endl;
	cout << "7) Custom array creation (this will clear an existing one)" << endl;
	cout << "8) Random array creation (this will clear an existing one)" << endl;
	cout << "9) Exit" << endl;
	cout << "Enter menu item number: ";
}

void Menu::PrintArray(DynamicArray* array)
{
	cout << "Array:" << endl;

	for (int i = 0; i < array->Length; i++)
	{
		cout << array->InternalArray[i] << " ";
	}

	cout << endl;
}

void Menu::CaseAdd(DynamicArray* array)
{
	int index;
	int element;
	PrintArray(array);
	cout << endl << "Enter index where you want to add element" << endl
		<< "(tips: " << endl << "to add at the beginning type: 0" << endl
		<< "to add new at the end type: " << array->Length << "): " << endl;
	if (!Common::AssertInputValue(index))
	{
		cout << endl << errorValueText << endl;
		return;
	}
	if (!Common::AssertValueInRange(index, 0, array->Length))
	{
		cout << endl << outOfRangeText << endl;
		return;
	}
	cout << endl << "Enter element" << endl;
	if (!Common::AssertInputValue(element))
	{
		cout << endl << errorValueText << endl;
			return;
	}
	cout << endl << "Old Array:" << endl;
	PrintArray(array);
	Array::AddAtIndex(array, element,index);
	cout << endl << "New Array:" << endl;
	PrintArray(array);
}

void Menu::CaseAddAfterElement(DynamicArray* array)
{
	int keyElementIndex;
	int keyElement;
	int element;
	PrintArray(array);
	cout << endl << "Enter which element you want to add new element" << endl
		<< "(tips: " << endl << "only first encounter counts): ";
	if (!Common::AssertInputValue(keyElement))
	{
		cout << endl << errorValueText << endl;
		return;
	}
	keyElementIndex = Array::LinearSearch(array, keyElement);
	if (keyElementIndex == -1)
	{
		cout << endl << noElementText << endl;
		return;
	}
	cout << endl << "Enter element: " << endl;
	if (!Common::AssertInputValue(element))
	{
		cout << endl << errorValueText << endl;
		return;
	}
	cout << endl << "Old Array:" << endl;
	PrintArray(array);
	Array::AddAtIndex(array, element, keyElementIndex+1);
	cout << endl << "New Array:" << endl;
	PrintArray(array);
}

void Menu::CaseDelete(DynamicArray* array)
{
	int index;
	PrintArray(array);
	cout << endl << "Enter index where you want to delete element" << endl
		<< "(tips: " << endl << "to delete at the beginning type: 0)" << endl
		<< "to delete last type: " << array->Length <<"): " << endl;
	if (!Common::AssertInputValue(index))
	{
		cout << endl << errorValueText << endl;
		return;
	}
	if (!Common::AssertValueInRange(index, 0, array->Length))
	{
		cout << endl << outOfRangeText << endl;
		return;
	}
	cout << endl << "Old Array:" << endl;
	PrintArray(array);
	Array::DeleteAtIndex(array, index);
	cout << endl << "New Array:" << endl;
	PrintArray(array);
}

void Menu::CaseSort(DynamicArray* array)
{
	cout << endl << "Old Array:" << endl;
	PrintArray(array);
	Array::Sort(array);
	cout << endl << "New Array:" << endl;
	PrintArray(array);
}

void Menu::CaseLinerSearch(DynamicArray* array)
{
	int element;
	int index;
	PrintArray(array);
	cout << endl << "Enter which element index do you want to find: ";
	if (!Common::AssertInputValue(element))
	{
		cout << endl << errorValueText << endl;
		return;
	}
	index = Array::LinearSearch(array, element);
	if (index == -1)
	{
		cout << endl << noElementText << endl;
		return;
	}
	cout << endl << "Element found at "<< index <<" index" << endl;
}

void Menu::CaseBinarySearch(DynamicArray* array)
{
	int element;
	int index;
	PrintArray(array);
	cout << endl << "Enter which element index do you want to find: ";
	if (!Common::AssertInputValue(element))
	{
		cout << endl << errorValueText << endl;
		return;
	}
	index = Array::BinarySearch(array, element);
	if (index == -1)
	{
		cout << endl << noElementText << endl;
		return;
	}
	cout << endl << "Element found at " << index << " index" << endl;
}

void Menu::CaseCustomCreate(DynamicArray* array)
{
	int size;
	int count = 0;
	int element;
	cout << endl << "Enter array lenght: ";
	if (!Common::AssertInputValue(size))
	{
		cout << endl << errorValueText << endl;
		return;
	}
	Array::CreateBlankArray(array, size);
	while (count != array->Length)
	{
		cout << endl << "Enter value for " << count << " element:" << endl;
		if (!Common::AssertInputValue(element))
		{
			cout << endl << tryAgainText << endl;
			break;
		}
		array->InternalArray[count] = element;
		PrintArray(array);
		count++;
	}
}

void Menu::MenuApp(DynamicArray* array)
{
	bool arrayExists = false;
	bool arraySorted = false;
	int selectedOption = 0;
	while (selectedOption != 9)
	{
		PrintMenu();
		if (Common::AssertInputValue(selectedOption))
		{
			switch (selectedOption)
			{
			case 1:
			{
				if (arrayExists)
					CaseAdd(array);
				else
					cout << endl << arrayNotExistText << endl;
				break;
			}
			case 2:
			{
				if (arrayExists)
					CaseAddAfterElement(array);
				else
					cout << endl << arrayNotExistText << endl;
				break;
			}
			case 3:
			{
				if (arrayExists)
					CaseDelete(array);
				else
					cout << endl << arrayNotExistText << endl;
				break;
			}
			case 4:
			{
				if (arrayExists)
				{
					CaseSort(array);
					arraySorted = true;
				}
				else
					cout << endl << arrayNotExistText << endl;
				break;
			}
			case 5:
			{
				if (arrayExists)
					CaseLinerSearch(array);
				else
					cout << endl << arrayNotExistText << endl;
				break;
			}
			case 6:
			{
				if (!arrayExists)
				{
					cout << endl << arrayNotExistText << endl;
					break;
				}
				if (arraySorted)
				{
					CaseBinarySearch(array);
				}
				else
					cout << endl << arrayNotSorted << endl;
				break;
			}
			case 7:
			{
				CaseCustomCreate(array);
				arrayExists = true;
				break;
			}
			case 8:
			{
				Array::RandomCreatingArrayFields(array);
				Menu::PrintArray(array);
				arraySorted = false;
				arrayExists = true;
				break;
			}
			case 9:
			{
				delete[] array->InternalArray;
				delete[] array;
				return;
			}
			}
		}
	}
}
