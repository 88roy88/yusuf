#include "Share.h"

Share::~Share() { }

ostream& Share::print(ostream& os) const {
	return Security::print(comp.print(os));
}

Security & Share::operator+(Security * other) {
	Share* otr = dynamic_cast<Share*>(other);
	string na = this->comp.getName() + otr->comp.getName();
	return Share(na, amount + otr->amount);
}
