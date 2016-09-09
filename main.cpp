#include "Security.h"
#include "company.h"
#include "bond.h"
#include "share.h"
#include "shareBond.h"
#include "info.h"
#include "securities.h"
#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

//menues:
void mainMenu();

map<string,company*> comps;

int main() {

	cout << TAB2 << "    welcome Mr. wong" << endl;
	cout << TAB3 << " loading..." << endl;
	cout << TAB4 << "..." << endl;
	cout << TAB4 << "..." << endl;

	//Share A("private", "russ", 44, 30, 12);
	//Bond B("hey", Date(12, 2, 2020), "no dep", 40, 200, 2, 11);
	//shareBond C(true, Date(22, 2, 2020), "aa", "shita", 5, 30, 20, 2);
	/*stuck.push_back(&A);
	stuck.push_back(&B);
	stuck.push_back(&C);*/
	mainMenu();
	cout << TAB2 << "good buy, was nise work with you" << endl;
	cin.get();
	return 0;
}

void mainMenu() {
	startMenu();
	enum Comand { EXIT, COMPANY, SECURITY };
	cout << TAB3 << "main menu" << endl;
	Comand cmd; int tmp;
	cout + "to do operations with companies" << TAB2 << "press " << COMPANY << endl;
	cout + "to do operations with securities" << TAB << "press " << SECURITY << endl << endl;
	cout + "to Exit" << TAB4 << "press " << EXIT << endl << endl << TAB;
	cin >> tmp;
	cmd = static_cast<Comand>(tmp);

	switch (cmd){
	case COMPANY:
		companies::menu();
		break;
	case SECURITY:
		securities::menu();
		break;
	case EXIT:
		return;
	default:
		break;
	}
	mainMenu();
}

/*
company& operator+(company& a, company& b) {
	if (a.getType() != b.getType())	throw differrntCompException();
	company* tmp = new company(a);
	tmp->setAmount(a.getAmount() + b.getAmount());
	tmp->setValue((a.getValue() + b.getValue()) / 2);
	tmp->setName(a.getName() + "&" + b.getName());
	tmp->setDepartament(a.getDepartament() + "&" + b.getDepartament());
	if (securities::Secu.find(a.getName()) != securities::Secu.end()) {}
	
	companies::comps.erase(a.getName());
	companies::comps.erase(b.getName());
	//securities::Secu.erase(a.getName());
//	securities::Secu.erase(b.getName());
	return *tmp;
}
*/
//companies::comps
//securities::Secu
