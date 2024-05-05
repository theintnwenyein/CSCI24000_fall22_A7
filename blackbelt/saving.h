#ifndef SAVING_H_EXISTS
#define SAVING_H_EXISTS
#include "checking.h"

class Saving: public Checking{
	protected:
		double saving_balance;
	public:
		Saving();
		double getSavingBalance();
};
#endif
