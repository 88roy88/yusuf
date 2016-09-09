#pragma once
#include "Security.h"
#include "CompException.h"

class Date {
private:
	int day, month, year;
public:
	Date(int D, int M, int Y) {
		if (Y > 2015 && Y < 2066) year = Y;
		else year = 2016;
		if (M > 0 && M < 13) month = M;
		else month = 9;
		if (D > 0 && D < 32) day = D;
		else day = 11;
	}
	Date withDate(const Date& other) const;
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }
	void addYear() { if (year >= 2066) throw MaxYearExcepsion(); year++; }
};

ostream& operator<<(ostream& os, const Date& d);

class Bond :public virtual Security{
protected:
	double interest;
	Date date;
public:
	Bond(string nam, Date D, int amo = 1, double inte = 1) : interest(inte>0?inte:1), Security(nam,amo), date(D) {}
	virtual ~Bond();
	virtual void addTime();
	virtual void changeInterest(int new_interest);
	virtual ostream& print(ostream& os) const; 	
	virtual string getType() { return "bond"; }
	virtual Security& operator+(Security* other);
};
