#include "copanies.h"
#include "CompException.h"

map<string, company*> companies::comps = map<string, company*>();

void companies::menu() {
	startMenu();
	enum Comand { EXIT, ADD, DELETE, PRINT, PRINT_LIST };
	Comand cmd;
	int tmp;
	cout + "to add a company    " << TAB3 << "press " << ADD << endl;
	cout + "to delete a company " << TAB3 << "press " << DELETE << endl;
	cout + "to print a company  " << TAB3 << "press " << PRINT << endl;
	cout + "to print a list of all the companies" << TAB << "press " << PRINT_LIST << endl;
	cout << endl;
	cout + "to Exit " << TAB4 << "press " << EXIT << endl << TAB;
	cin >> tmp;
	cmd = static_cast<Comand>(tmp);

	switch (cmd) {
	case ADD:
		create();
		break;
	case DELETE:
		try {
			erase();
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
		break;
	case PRINT:
		try {
			printCompany();
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
		break;
	case PRINT_LIST:
		try {
			printList();
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
		break;
	case EXIT:
		return;
	default:
		break;
	}
	cout << endl << TAB << "continue, Mr. Wong?";
	cin.get();
	cin.get();
	menu();
}
void companies::create(string name = "") {
	string dep;
	int val, amo;
	company::Type typ;
	if (name == "") {
		cout + "enter commpany name please: ";
		cin >> name;
	}
	cout + "enter company departament please: ";
	cin >> dep;
	cout + "how many securities you want to this company?  ";
	cin >> amo;
	cout + "please, enter the price of each security: ";
	cin >> val;
	typ = choseType();
	cout + "thank you!" << endl << TAB << "!company added successfully!" << endl;
	comps.insert(pair<string, company*>(name, new company(name, dep, typ, val, amo)));
}
void companies::erase() {
	string nam;
	cout + "please enter company name to delete: ";
	cin >> nam;
	if (comps.erase(nam) == 0)
		throw NotExistComp("erase",nam);
	cout + "the company " << nam << " successfuly deleted!" << endl;
}

void companies::printCompany() {
	string nam;
	cout + "please enter company name to print: ";
	cin >> nam;
	map<string, company*>::iterator it = comps.find(nam);
	if (it == comps.end()) throw NotExistComp("print",nam);
	else cout << *(it->second);
}
void companies::printList() {
	if (comps.empty()) {
		throw NoComps();
	}
	cout + "all the exists copanies: " << endl;
	int i = 1;
	for (map<string, company*>::iterator it = comps.begin(); it != comps.end(); it++, i++)
		cout + "(" << i << ") " << it->second->getName() << " - " << it->second->getStringType() << endl;
}
company::Type companies::choseType() {
	int tmp;
	cout + "good, now chose the company type: " << endl;
	cout + "private company -" << TAB3 << "press " << company::PRIVATE << endl;
	cout + "govermental body -" << TAB3 << "press " << company::GOVERMENTAL << endl;
	cout + "or govermental company -" << TAB2 << "press " << company::GOVERMENTAL_COMPANY << endl << TAB;
	cin >> tmp;
	return static_cast<company::Type>(tmp);
}