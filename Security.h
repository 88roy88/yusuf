#pragma once
#include <iostream>
#include <string>
#include "company.h"
#include "copanies.h"
#include "CompException.h"
using namespace std;

class Security{
protected:
	company& comp;
	int amount;
public:
	//constrctors and destrctors
	Security(string nam, int amo = 1) :amount(0), comp (*companies::comps.find(nam)->second) { buy(amo); }
	virtual ~Security();

	//getters
	virtual const company* getCompany() const { return &comp; }
	virtual string getName() const { return comp.getName(); }
	virtual int getAmount() const { return amount; }
	virtual int getValue() const { return comp.getValue(); }
	virtual string getType() = 0;

	//functions
	virtual double getShare() const { return 100 * amount / comp.getAmount(); }
	virtual void buy(int to_buy);
	virtual void sell(int to_sell);
	virtual int totalValue() const { return amount*comp.getValue(); }
	virtual ostream& print(ostream& os) const =0;

	//opertors
	virtual Security& operator+(Security* other)=0;
	
};

ostream & operator<<(ostream & os, Security* sec);