#pragma once
#include <map>
#include <string>
#include "company.h"
#include "help.h"
using namespace help;

class companies {
public:
	static map<string, company*> comps;
	
	static void menu();
	static void create(string name ="");
	static void erase();
	static void printCompany();
	static void printList();

	//helper functions:
	static company::Type choseType();

};