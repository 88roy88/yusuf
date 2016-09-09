#pragma once
#include <iostream>
#include <string>
#include "help.h"
using namespace std;
using namespace help;

class company{
public:
	enum Type{PRIVATE, GOVERMENTAL, GOVERMENTAL_COMPANY};
private:
	string name;
	string department;
	Type type;
	int value;
	int total_amount;
public:
	company(string nam, string dep, Type typ, int val, int amo);
	~company();
	//getters:
	string getName() const { return name; }
	string getDepartament() const { return department; }
	int getAmount() const { return total_amount; }
	int getValue() const { return value; }
	Type getType() const { return type; }
	string getStringType() const;

	//setters:
	void setValue(int new_val) { value = new_val; }
	void setName(string new_name) { name = new_name; }
	void setDepartament(string new_dep) { department = new_dep; }
	void setAmount(int new_am) { total_amount = new_am; }
	
	ostream& company::print(ostream& os) const;
	void printExtra() const;
};

ostream& operator<<(ostream& os, const company& comp);