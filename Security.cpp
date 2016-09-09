#include "Security.h"

Security::~Security(){}

void Security::buy(int to_buy) {
	if (to_buy + amount > comp.getAmount()) throw OutOfAmount();
	this->amount += to_buy; 
}

void Security::sell(int to_sell){
	if (to_sell < this->amount) this->amount -= to_sell;
	else this->amount = 0;
}

/*void Security::setValue(int new_val)
{
	this->value = new_val;
}*/

/*Security Security::operator+(Security other)
{
	return Security();
}*/

ostream& Security::print(ostream& os) const {
	os << TAB2 << "security" << comp.getName() << " information: " << endl;
	os + "your amount" << TAB << ":" << TAB2 << amount << endl;
	os + "your part" << TAB << ":" << TAB2 << getShare() << "%" << endl;
	return os + "total value" << TAB << ":" << TAB2 << totalValue() << "$" << endl;
}

ostream & operator<<(ostream & os, Security*  sec) { return sec->print(os); }
