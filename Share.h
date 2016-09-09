#pragma once
#include "Security.h"

class Share :public virtual Security {
public:
	Share(string nam, int amo = 1) :Security(nam, amo) {};
	~Share();
	virtual string getType() { return "share"; }
	virtual ostream& print(ostream& os) const;
	Security &operator+(Security * other);


};

