#include "Bond.h"
#include <iostream>
#include <string>
#include "CompException.h"
using namespace std;

Bond::~Bond() {}

void Bond::addTime()
{
	this->date.addYear();
}

void Bond::changeInterest(int new_interest)
{
	if (new_interest < 0) throw badInterestExcepsion();
	interest = new_interest;
}

ostream& Bond::print(ostream& os) const {
	comp.print(os);
	Security::print(os);
	os << "interest\t:\t\t" << interest << "%" << endl;
	return os << "return date\t:\t\t" << date << endl;
}

Security& Bond::operator+(Security* other)
{
	Bond* otr = dynamic_cast<Bond*>(other);
	string na = this->comp.getName() + otr->comp.getName();
	return Bond(na,date.withDate(otr->date),amount+otr->amount,(interest+ otr->interest)/2 );
}

ostream& operator<<(ostream& os, const Date& d) {
	return os << d.getDay() << "." << d.getMonth() << "." << d.getYear();
}

ostream& operator<<(ostream& out, const Bond& b) { return b.print(out); }

Date Date::withDate(const Date & other) const
{
	return Date((day+other.day)/2,(month+other.month)/2,(year+other.year)/2);
}
