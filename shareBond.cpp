#include "shareBond.h"

shareBond::~shareBond(){}

ostream& shareBond::print(ostream& os) const {
	Bond::print(os);
	return os << "tradable\t:\t\t" << boolalpha << tradable << endl;
}

Security & shareBond::operator+(Security * other) {
	const shareBond* otr = dynamic_cast<const shareBond*>(other);
	string na = this->comp.getName() + otr->comp.getName();
	return shareBond(na,tradable*otr->tradable, date.withDate(otr->date), amount + otr->amount, (interest + otr->interest) / 2);
}
