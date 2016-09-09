#include "company.h"
#include "CompException.h"

company::company(string nam, string dep, Type typ, int val, int amo) :name(nam), department(dep),type(typ), value(val), total_amount(amo) { }
company::~company() {}

string company::getStringType() const {
	switch (type) {
	case PRIVATE:
		return "private company";
	case GOVERMENTAL:
		return "govermental body";
	case GOVERMENTAL_COMPANY:
		return "govermental company";
	default:
		return "";
	}
}

ostream& company::print(ostream& os) const {
	os << TAB2 << "company " << name << " informmation: " << endl;
	os + "price per unit" << TAB << ':' << TAB2 << value << "$" << endl;
	return os + "total amount" << TAB << ':' << TAB2 << total_amount << endl;
}

void company::printExtra() const {
	cout <</* "\t\t\t" << name << endl <<*/ "department\t:\t\t" << department << endl << "type\t\t:\t\t" << getStringType() << endl;
}

ostream& operator<<(ostream& os, const company& comp) { return comp.print(os); }