#include "saving.h"
#include <iostream>
#include <string>

Saving::Saving(){

	// default value
	Saving::saving_balance = 100.0;
}

double Saving::getSavingBalance(){
	Saving::saving_balance = getBalance() * (1 + (0.2/100) * 0.5); // rate = 0.2% , time period = 6 months
	return Saving::saving_balance;
}
