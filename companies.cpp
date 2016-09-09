#include "copanies.h"
#include "CompException.h"

map<string, company*> companies::comps = map<string, company*>();

company& operator+(company& a, company& b);


void companies::menu() {
	startMenu();
	enum Comand { EXIT, ADD, MESH, DELETE, PRINT, PRINT_LIST }; // 2copms+ 
	Comand cmd;
	int tmp;
	cout + "to add a company    " << TAB3 << "press " << ADD << endl;
	cout + "to integrat two companies " << TAB2 << "press " << MESH << endl;
	cout + "to delete a company " << TAB3 << "press " << DELETE << endl;
	cout + "to print a company  " << TAB3 << "press " << PRINT << endl;
	cout + "to print a list of all the companies" << TAB << "press " << PRINT_LIST << endl;
	cout << endl;
	cout + "to Exit " << TAB4 << "press " << EXIT << endl << TAB;
	cin >> tmp;
	cmd = static_cast<Comand>(tmp);

	bool Error;
	switch (cmd) {
	case ADD:
		do {
			Error = false;
			try {
				create();
			}
			catch (exception& e) {
				cout << e.what() << endl;
				char a;
				Error = true;
				cout << "if you like to try another name press y";
				cin >> a;
				if (!(a == 'y' || a == 'Y')) Error = false;
			}
		} while (Error);
		break;
	case MESH:
		mesh();
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
	menu();
}

void companies::create(string name ) {
	string dep;
	int val, amo;
	company::Type typ;
	if (name == "") {
		cout + "enter commpany name please: ";
		cin >> name;
	}
	if (comps.find(name) != comps.end()) throw alreadyExist();
	cout + "enter company departament please: ";
	cin >> dep;
	cout + "how many securities are there of the company?  ";
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
void companies::mesh() {
	string nam1,nam2;
	cout + "please enter first company name: ";
	cin >> nam1;
	if (comps.find(nam1) == comps.end()) throw NotExistComp("marge", nam1);
	company* a = comps.find(nam1)->second;
	cout + "please enter first company name: ";
	cin >> nam2;
	if (comps.find(nam2) == comps.end()) throw NotExistComp("marge", nam2);
	company* b = comps.find(nam2)->second;
	comps.insert(pair<string, company*>( (*a + *b).getName() , &(*a+*b)) );
	cout + "thank you!" << endl << TAB << "!companies are one now!" << endl;
}
void companies::printCompany() {
	string nam;
	cout + "please enter company name to print: ";
	cin >> nam;
	map<string, company*>::iterator it = comps.find(nam);
	if (it == comps.end()) throw NotExistComp("print",nam);
	else {
		cout << *(it->second);
		//it->second->printExtra();
	}
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

company& operator+(company& a, company& b) {
	if (a.getType() != b.getType())	throw differrntCompException();
	company* tmp = new company(a);
	cout << "temp \n";
	tmp->setAmount(a.getAmount() + b.getAmount());
	tmp->setValue((a.getValue() + b.getValue()) / 2);
	tmp->setName(a.getName() + "&" + b.getName());
	tmp->setDepartament(a.getDepartament() + "&" + b.getDepartament());
	//if (securities::Secu.find(a.getName()) != securities::Secu.end()) {}
	companies::comps.erase(a.getName());
	companies::comps.erase(b.getName());
	//securities::Secu.erase(a.getName());
	//	securities::Secu.erase(b.getName());
	return *tmp;
}