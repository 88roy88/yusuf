#include "securities.h"

map<string, Security*> securities::Secu = map<string, Security*>();

void securities::menu() {
	startMenu();
	enum Comand { EXIT, BUY, SELL, PRINT, PRINT_LIST }; // i think we need option of Create
	Comand cmd;
	int tmp;
	cout + "to buy a security    " << TAB3 << "press " << BUY << endl;
	cout + "to sell a security   " << TAB3 << "press " << SELL << endl;
	cout + "to print a security  " << TAB3 << "press " << PRINT << endl;
	cout + "to print a list of all the security" << TAB << "press " << PRINT_LIST << endl;
	cout << endl;
	cout + "to Exit " << TAB4 << "press " << EXIT << endl << TAB;
	cin >> tmp;
	cmd = static_cast<Comand>(tmp);

	switch (cmd) {
	case BUY:
		try {
			buy();
		}
		catch (NotExistComp& e) {
			char a;
			cout + e.what() << endl;
			cout + "are you want to add this company? (y\\n): ";
			cin >> a;
			if ((a == 'y') || (a == 'Y')) {
				companies::create(e.getName());
			}
			try {
				buy(e.getName());
			}
			catch (exception& e) {
				cout << e.what() << endl;
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
		break;
	case SELL:
		try {
			sell();
		} 
		catch (exception& e) {
			cout << e.what() << endl;
		}
		break;
	case PRINT:
		try {
			printSecurity();
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

void securities::buy(string nam) {
	int amo;
	if (nam == "") {
		cout + "enter company name to buy securities: ";
		cin >> nam;
	}

	if (companies::comps.find(nam) == companies::comps.end()) throw NotExistComp("buy security for ", nam);
	if (Secu.find(nam) == Secu.end()) {
		cout + "the Security need to be configured first" << endl;
		create(nam, 0);
	}	
	cout + "how many securities you want to buy of this company?  (" << companies::comps.find(nam)->second->getValue() << "$ per unit)" << endl;
	cout + "limited by " << companies::comps.find(nam)->second->getAmount() - Secu.find(nam)->second->getAmount() << ": ";
	cin >> amo;
	map<string, Security*>::iterator it = Secu.find(nam);
	it->second->buy(amo);
	cout + "thank you!" << endl << TAB << "* the " << securities::Secu.find(nam)->second->getType() << " bought successfully!*" << endl;
}

void securities::sell() {
	string nam;
	string Type;
	int to_sell;
	cout + "please enter security name to sell: ";
	cin >> nam;
	if (companies::comps.find(nam) == companies::comps.end()) throw NotExistComp("sell security", nam);
	if (Secu.find(nam) == Secu.end()) {  // the follow 2 liens could be an excpsion
		cout + "the Security need to be configured first" << endl;
		create(nam, 0);
		cout + "you have no " << Secu.find(nam)->second->getType() << " to sell"<< endl;
		return;
	}
	cout + "limited by " << companies::comps.find(nam)->second->getAmount() - Secu.find(nam)->second->getAmount() << ": ";
	cout + "how securities to sell: ";
	cin >> to_sell;
	Secu.find(nam)->second->sell(to_sell);
	if (Secu.find(nam)->second->getAmount() == 0) {
		Type = securities::Secu.find(nam)->second->getType();
		if (Secu.erase(nam) == 0)
			throw NotExistComp("erase", nam);
		cout + "the " << Type << " " << nam << " successfuly deleted!" << endl;
	}
	cout + "the " << Type << " selled successfully!" << endl;
}

void securities::printSecurity() {
	string nam;
	cout + "please enter security name to print: ";
	cin >> nam;
	map<string, Security*>::iterator it = Secu.find(nam);
	if (it == Secu.end()) throw NotExistComp("print a security", nam);
	else cout << (it->second);
	//if (Secu.find(nam) == Secu.end()) { create(nam, 0); }
}

void securities::printList() {
	if (Secu.empty()) {
		throw NoSecus();
	}
	cout + "all the exists securities: " << endl;
	int i = 1;
	for (map<string, Security*>::iterator it = Secu.begin(); it != Secu.end(); it++, i++)
		cout + "(" << i << ") " << it->second->getName() << " - " << it->second->getType() << endl;
}

void securities::create(string nam, int amo) {
	int inte;
	bool trade;
	int y, m, d;
	if (companies::comps.find(nam)==companies::comps.end()) throw NotExistComp("buy stock of",nam);
	if (amo > companies::comps.find(nam)->second->getAmount()) throw OutOfAmount();
	switch (companies::comps.find(nam)->second->getType()) {
	case company::PRIVATE: 
		Secu.insert(pair<string, Security*>(nam, new Share(nam, amo)));
		break;
	case company::GOVERMENTAL: 
		cout + "expiry date (format: DD MM YYYY): ";
		cin >> d >> m >> y;
		cout + "the interest in %: ";
		cin >> inte;
		Secu.insert(pair<string, Security*>(nam, new Bond(nam, Date(d, m, y), amo, inte)));
		break;
	case company::GOVERMENTAL_COMPANY: 
		cout + "expiry date (format: DD MM YYYY): ";
		cin >> d >> m >> y;
		cout + "the interest in %: ";
		cin >> inte;
		cout + "is tradable? (0/1)";
		cin >> trade;
		Secu.insert(pair<string, Security*>(nam, new shareBond(nam, trade, Date(d,m,y), amo, inte)));
		break;
	}
	cout + "*! the " << Secu.find(nam)->second->getType() << " was configured!*" << endl;
}
