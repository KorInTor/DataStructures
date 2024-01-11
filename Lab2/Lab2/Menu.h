#pragma once
#include "Common.h"
#include "ListItem.h"
#include "Main.h"
#include <string>


class Menu
{
public:
	static void PrintMenu();
	static void PrintList(struct List* list);
	static void CaseCreate(struct List* list, std::string option);
	static void CaseAdd(List* list, std::string option);
	static void CaseFind(List* list);
	static void CaseRemove(List* list);
	static void MenuApp(struct List* list);
};

