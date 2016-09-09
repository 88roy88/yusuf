#pragma once
#include "shareBond.h"
#include "copanies.h"
#include "CompException.h"
#include "help.h"
using namespace help;

class securities{
public:
	static map<string, Security*> Secu;

	static void menu();
	static void buy(string nam = "");
	static void sell();
	static void printSecurity();
	static void printList();

	static void create(string nam, int amo);
};

