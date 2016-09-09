#pragma once
#include<iostream>
#include<string>
using namespace std;

namespace help {
	const string TAB = "\t";
	const string TAB2 = "\t\t";
	const string TAB3 = "\t\t\t";
	const string TAB4 = "\t\t\t\t";

	void startMenu();
	ostream & operator+(ostream & os, string s);
}