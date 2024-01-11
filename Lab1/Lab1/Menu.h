#ifndef MENU_H
#define MENU_H
#include "Array.h"
#include "Common.h"
class Menu
{
public:
	static void PrintMenu();
	static void MenuApp(struct DynamicArray* array);
	static void PrintArray(DynamicArray* array);
	static void CaseAdd(DynamicArray* array);
	static void CaseAddAfterElement(DynamicArray* array);
	static void CaseDelete(DynamicArray* array);
	static void CaseSort(DynamicArray* array);
	static void CaseLinerSearch(DynamicArray* array);
	static void CaseBinarySearch(DynamicArray* array);
	static void CaseCustomCreate(DynamicArray* array);
};
#endif
