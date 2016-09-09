#pragma once
#include<exception>
#include<string>

using namespace std;

class differrntCompException :public exception {
public:
	const char* what()const {
		return "The companies aren't from the same type!";
	}
};

class MaxYearExcepsion : public exception {
public:
	const char* what()const {
		return "You've reached to the max permitted year";
	}
};

class badInterestExcepsion : public exception {
public:
	const char* what()const {
		return "Interest MUST be positive";
	}
};

class NoComps : public exception {
public:
	const char* what()const {
		return "there are no companies in the database";
	}
};

class NoSecus :public exception {
public:
	const char* what()const {
		return "there are no securities in the database";
	}
};

class NotExistComp : public exception {
	string name, act;
	string msg;
public:
	NotExistComp(string a, string b) :act(a), name(b) { msg = "you tried to " + act + " " + name + " but it isn't exist"; };
	const char* what()const {
		return msg.c_str();
	}
	string getName() { return name; }
};

class OutOfAmount : public exception {
public:
	const char* what()const {
		return "you cant buy more security then there is...";
	}
};

class alreadyExist : public exception {
public:
	const char* what()const {
		return "the company name is token";
	}
};