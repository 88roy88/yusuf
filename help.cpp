#include "help.h"

void help::startMenu() { cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl; }
ostream & help::operator+(ostream & os, string s) { return os << TAB << s; }
