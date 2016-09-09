#pragma once
#include "Bond.h"
#include "Share.h"

class shareBond : virtual public Bond,virtual public Share {
private:
	bool tradable;
public:
	shareBond(string nam, bool trade, Date D, int amo = 1, double inte = 1) :tradable(trade), Bond(nam, D, amo, inte), Share(nam, amo), Security(nam, amo) {};
	~shareBond();
	virtual string getType() { 
		if (tradable) return "tradeable govermental share";
		return "non-tradeable govermental share";
	}
	virtual ostream& print(ostream& os) const;
	void ChangeStatus() { tradable = !tradable; }
	virtual Security& operator+(Security* other);
};
